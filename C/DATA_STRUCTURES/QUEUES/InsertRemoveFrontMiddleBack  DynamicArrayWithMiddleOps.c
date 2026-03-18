#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} MultiBuffer;

MultiBuffer* create() {
    MultiBuffer* obj = (MultiBuffer*)malloc(sizeof(MultiBuffer));
    obj->capacity = 10;
    obj->size = 0;
    obj->arr = (int*)malloc(obj->capacity * sizeof(int));
    return obj;
}

int isEmpty(MultiBuffer* obj) {
    return obj->size == 0;
}

void ensureCapacity(MultiBuffer* obj) {
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = (int*)realloc(obj->arr, obj->capacity * sizeof(int));
    }
}

void pushFront(MultiBuffer* obj, int val) {
    ensureCapacity(obj);

    for (int i = obj->size; i > 0; i--) {
        obj->arr[i] = obj->arr[i - 1];
    }

    obj->arr[0] = val;
    obj->size++;
}

void pushMiddle(MultiBuffer* obj, int val) {
    ensureCapacity(obj);

    int mid = obj->size / 2;

    for (int i = obj->size; i > mid; i--) {
        obj->arr[i] = obj->arr[i - 1];
    }

    obj->arr[mid] = val;
    obj->size++;
}

void pushBack(MultiBuffer* obj, int val) {
    ensureCapacity(obj);

    obj->arr[obj->size] = val;
    obj->size++;
}

int popFront(MultiBuffer* obj) {
    if (isEmpty(obj)) return -1;

    int temp = obj->arr[0];

    for (int i = 0; i < obj->size - 1; i++) {
        obj->arr[i] = obj->arr[i + 1];
    }

    obj->size--;
    return temp;
}

int popMiddle(MultiBuffer* obj) {
    if (isEmpty(obj)) return -1;

    int mid = (obj->size - 1) / 2;
    int temp = obj->arr[mid];

    for (int i = mid; i < obj->size - 1; i++) {
        obj->arr[i] = obj->arr[i + 1];
    }

    obj->size--;
    return temp;
}

int popBack(MultiBuffer* obj) {
    if (isEmpty(obj)) return -1;

    int temp = obj->arr[obj->size - 1];
    obj->size--;
    return temp;
}

int main() {
    int q;
    scanf("%d", &q);

    MultiBuffer *obj = create();

    while (q--) {
        int type, val;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &val);
            pushFront(obj, val);
        }
        else if (type == 2) {
            scanf("%d", &val);
            pushMiddle(obj, val);
        }
        else if (type == 3) {
            scanf("%d", &val);
            pushBack(obj, val);
        }
        else if (type == 4) {
            printf("%d\n", popFront(obj));
        }
        else if (type == 5) {
            printf("%d\n", popMiddle(obj));
        }
        else if (type == 6) {
            printf("%d\n", popBack(obj));
        }
    }

    return 0;
}