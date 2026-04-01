/*
 * @lc app=leetcode id=946 lang=c
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
typedef struct Stack
{
    int *arr;
    int top;
    int capacity;
}Stack;

Stack * createStack(int capacity)
{
    Stack *s;
    s=malloc(sizeof(Stack));
    s->top=-1;
    s->capacity=capacity;
    s->arr=malloc(sizeof(int)*capacity);
    return s;
}

int isEmpty(Stack *s)
{
    return(s->top==-1)?1:0;
}
int isFull(Stack *s)
{
    return(s->top==s->capacity-1)?1:0;
}
void push(Stack *s, int x)
{
    if(isFull(s))
    {
        s->capacity*=2;
        s->arr=realloc(s->arr,s->capacity*sizeof(int));
    }
      s->top++;
    s->arr[s->top]=x;
}

int pop(Stack *s)
{
    if(isEmpty(s)) return INT_MIN;
    int val=s->arr[s->top];
    s->top--;
    return val;
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) 
{
    int j=0;
    Stack *S=createStack(pushedSize);
    for(int i=0;i<pushedSize;i++)
    {
        push(S,pushed[i]);
        while(!isEmpty(S) && j<poppedSize && S->arr[S->top]==popped[j])
        {
            pop(S);
            j++;
        }
    }
    return(j==poppedSize);
}
// @lc code=end

