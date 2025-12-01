#include<stdio.h>
#include<string.h>

typedef struct 
{
    int id, std_count, credit_count;
    float credit_price;
    char degname[50], dep_name[50], responsible[50]; 
} degree;

void readdegree(degree ldeg[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter the id of degree #%d: ", i+1);
        scanf("%d", &ldeg[i].id);
        while (getchar() != '\n');  // clear leftover newline

        printf("Enter the name of degree #%d: ", i+1);
        fgets(ldeg[i].degname, 50, stdin);
        ldeg[i].degname[strcspn(ldeg[i].degname, "\n")] = '\0';

        printf("Enter the name of department of degree #%d: ", i+1);
        fgets(ldeg[i].dep_name, 50, stdin);
        ldeg[i].dep_name[strcspn(ldeg[i].dep_name, "\n")] = '\0';

        printf("Enter student count of degree #%d: ", i+1);
        scanf("%d", &ldeg[i].std_count);
        while (getchar() != '\n');

        printf("Enter credit count of degree #%d: ", i+1);
        scanf("%d", &ldeg[i].credit_count);
        while (getchar() != '\n');

        printf("Enter credit price of degree #%d: ", i+1);
        scanf("%f", &ldeg[i].credit_price);
        while (getchar() != '\n');

        printf("Enter the name of the responsible person of degree #%d: ", i+1);
        fgets(ldeg[i].responsible, 50, stdin);
        ldeg[i].responsible[strcspn(ldeg[i].responsible, "\n")] = '\0';
    }
}


void search(degree ldeg[], char *name, int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(ldeg[i].degname,name)==0)
        {
            flag=1;
            printf("MAJOR FOUND!\nHERE ARE THE DETAILS:\n");
            printf("Major ID: %d.\n",ldeg[i].id);
            printf("Major Name: %s.\n",ldeg[i].degname);
            printf("Major Departement: %s.\n",ldeg[i].dep_name);
            printf("Major Credits: %d.\n",ldeg[i].credit_count);
            printf("Major Cost: %.2f$.\n",ldeg[i].credit_price*ldeg[i].credit_count);
        }              
    }
    if(flag==0)
    {
        printf("Major not found!\n");
    }
}

void cost_update(degree ldeg[],int id, int n,float new_cost)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(ldeg[i].id==id)
        {
            flag=1;
            ldeg[i].credit_price=new_cost;
            break;
        }
    }
    if(flag==0)
    {
        printf("ERROR\n");
    }
}

void showdegs(degree ldeg[], int n)
{
    for(int i=0;i<n;i++)
    {
            printf("Major #%d:\n",i+1);
            printf("Major ID: %d.\n",ldeg[i].id);
            printf("Major Name: %s.\n",ldeg[i].degname);
            printf("Major Departement: %s.\n",ldeg[i].dep_name);
            printf("Major Credits: %d.\n",ldeg[i].credit_count);
            printf("Major Cost: %.2f$.\n",ldeg[i].credit_price*ldeg[i].credit_count);
            printf("Major Student Count: %d.\n",ldeg[i].std_count);
            printf("Major Responsible in charge: %s.\n",ldeg[i].responsible);
    }
}

int main()
{
    degree arr[2];
    readdegree(arr,2);
    printf("Enter the major you wish to check availability: ");
    char major[50];
    scanf(" %49[^\n]",major);
    search(arr,major,2);
    printf("Enter the ID you want to change its cost: ");
    int id;
    float cost;
    scanf("%d",&id);
    printf("Enter the new cost: ");
    scanf("%f",&cost);
    cost_update(arr,id,2,cost);
    showdegs(arr,2);
}
