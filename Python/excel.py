import itertools
import string
import hashlib
import base64
from multiprocessing import Process, Manager, Value
import time

# ---------- Configure your Excel hash ----------
hashValue = "WzO/5RmdKOUM8s"
saltValue = "anVUkU"
spinCount = 1000
# -----------------------------------------------

def verify_password(password, hash_b64, salt_b64, spin_count):
    """Compute PBKDF2-HMAC-SHA512 hash and compare to target."""
    expected_hash = base64.b64decode(hash_b64)
    salt = base64.b64decode(salt_b64)
    pwd_bytes = password.encode("utf-16le")
    h = hashlib.sha512(salt + pwd_bytes).digest()
    for _ in range(spin_count - 1):
        h = hashlib.sha512(h).digest()
    return h == expected_hash

def worker(start_chars, chars, hash_b64, salt_b64, spin_count, max_length, progress, total, found_flag):
    """Worker process to try passwords starting with a subset of characters."""
    for first in start_chars:
        if found_flag.value:
            return
        for pwd_tuple in itertools.product(chars, repeat=max_length-1):
            if found_flag.value:
                return
            pwd = first + ''.join(pwd_tuple)
            progress.value += 1
            if verify_password(pwd, hash_b64, salt_b64, spin_count):
                print(f"\n✅ Password found: {pwd}")
                found_flag.value = 1
                return
            if progress.value % 100 == 0:
                percent = (progress.value / total.value) * 100
                print(f"\rProgress: {percent:.6f}%  ", end="")

def calculate_total_guesses(chars, length):
    return len(chars) ** length

def run_parallel(hash_b64, salt_b64, spin_count, max_length=1, num_cores=5):
    chars = string.ascii_letters  # letters only
    total_guesses = calculate_total_guesses(chars, max_length)
    
    manager = Manager()
    progress = manager.Value('i', 0)
    total = manager.Value('i', total_guesses)
    found_flag = manager.Value('i', 0)

    # split starting characters for each core
    chunk_size = len(chars) // num_cores
    procs = []
    for i in range(num_cores):
        start = chars[i*chunk_size:(i+1)*chunk_size]
        p = Process(target=worker, args=(start, chars, hash_b64, salt_b64, spin_count, max_length, progress, total, found_flag))
        procs.append(p)
        p.start()

    for p in procs:
        p.join()

    if not found_flag.value:
        print("\n❌ Password not found.")

if __name__ == "__main__":
    start_time = time.time()
    run_parallel(hashValue, saltValue, spinCount, max_length=4, num_cores=16)
    elapsed = time.time() - start_time
    print(f"\nElapsed time: {elapsed:.2f} seconds")
