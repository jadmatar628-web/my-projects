    document.getElementById("btn").addEventListener("click",signupval);
    document.getElementById("btne").addEventListener("click", loginval);

    function emailval(email)
    {
        if(email.length===0)
        {
            alert("Email cannot be empty");
            return false;
        }
        if(!email.includes("@") || !email.includes("."))
        {
            alert("Invalid E-mail Format");
            return false;
        }
        return true;
    }

    function passval(p,pp)
    {
        if(p.length===0)
        {
            alert("Password cannot be empty");
            return false;
        }
            if(pp.length===0)
        {
            alert("Password confirmation cannot be empty");
            return false;
        }
            if(p.length<8)
        {
            alert("Passwords must contains at least 8 characters.");
            return false;
        }
        if(p!=pp)
        {
            alert("Passwords do not match");
            return false;
        }
        return true;
    }
    function signupval(){
            let mail=document.getElementById("email").value;
            if(!emailval(mail)) return;
        let pass1=document.getElementById("pwd").value;
        let pass2=document.getElementById("pwd2").value;
                    if (!passval(pass1, pass2)) return;
        alert("Success!");
    }

    function loginval()
    {
                let mail=document.getElementById("emaile").value;
            emailval(mail);
            let pas=document.getElementById("pwde").value;
             if (!emailval(mail)) return;
            if (!passval(pass, pass)) return;
    }
