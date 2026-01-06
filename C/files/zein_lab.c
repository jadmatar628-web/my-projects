#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
    int id;
    char name[50];
    float avg;
} Student;

Student addstudent()
{
    Student new;
    printf("Enter student name: ");
    scanf("%49s",new.name);
    printf("Enter %s's ID: ",new.name);
    scanf("%d",&new.id);
    printf("Enter %s's average: ",new.name);
    scanf("%f",&new.avg);
    return new;
}

void addstudenttofile(Student *arr, int count)
{
    FILE *student=fopen("/home/jadmatar/MY_PROJECTS/C/files/students.txt","w");
    if(!student)
    {
        printf("File Openning failed.\n");
        return ;
    }
    for(int i=0;i<count;i++)
    {
        fprintf(student,"ID: %d\n",(arr+i)->id);
        fprintf(student,"Name: %s\n",(arr+i)->name);
        fprintf(student,"Average: %.2f\n",(arr+i)->avg);
        fprintf(student,"----------------------\n");
    }
    fclose(student);
}

void readfromtextfile(Student *arr, int *count)
{
    *count=0;
    FILE *open=fopen("/home/jadmatar/MY_PROJECTS/C/files/students.txt","r");
    if(!open)
    {
        printf("A problem occured when opening the file.");
        return ;
    }

    while(fscanf(open,"ID: %d",&arr[*count].id)==1)
    {
        fscanf(open,"Name: %s",arr[*count].name);
        fscanf(open,"Average: %f",&arr[*count].avg);
        fscanf(open, "----------------------");
        *count++;
    }
    fclose(open);

}

void writetobin(Student *arr, int count)
{
    FILE *bin1=fopen("students.dat","wb");
    if(!bin1)
    {
        printf("ERROR");
        return;
    }
    fwrite(arr,sizeof(Student),count,bin1);
    fclose(bin1);
}

void readfrombin(Student *arr,int *count)
{
    FILE *bin2=fopen("students.dat","rb");
    if(!bin2)
    {
        printf("ERROR");
        return;
    }
    fseek(bin2,0,SEEK_END);
    long pos=ftell(bin2);   
    *count=pos/sizeof(Student);
    rewind(bin2);
    fread(arr,sizeof(Student),*count,bin2);
    fclose(bin2);
}
void searchanddisplay(int id)
{
    int found=0;
    Student temp;
    FILE *j=fopen("students.dat","rb");
    if(!j)
    {
        return ;
    }
    while(fread(&temp,sizeof(Student),1,j)!=0)
    {
        if(temp.id==id)
        {
            printf("Student found:\n");
            printf("Name:%s\nID:%d\nAvergae:%.2f\n",temp.name,temp.id,temp.avg);
            found=1;
            break;
        }
    }
        if(found==0)
        {
            printf("Student not found");
        }
    fclose(j);
}

int main()
{
    int count=0;
    int capacity;
    capacity=2;
    Student *arr=malloc(sizeof(Student)*capacity);
    while(1)
    {
        printf("Entering data of student #%d: \n",count+1);
        arr[count]=addstudent();
        count++;
        printf("Do you want to add another student(Y/N)?\n");
        char answer[2];
        scanf(" %c",answer);
        if(answer[0]=='n')
        {
            break;
        }
        else 
        {
            if(capacity==count)
            {
                capacity*=2;
                arr=realloc(arr,capacity*sizeof(Student));
            }
        }

    }
    printf("Writing to file now...\n");
    //addstudenttofile(arr,count);
    //readfromtextfile(arr,&count);
    writetobin(arr,count);
    //readfrombin(arr,&count);
    searchanddisplay(3);


free(arr);
}