#include<stdio.h>
#include<string.h>

struct product
{
    char name[50];
    int qty;
    float price;
};
void printProduct(struct product p)
{
   printf("Product name: %s\n",p.name);
   printf("Product price: %.2f\n",p.price);
   printf("Product quantity: %d\n",p.qty);
}
void updatePrice(struct product *p, float newprice)
{
    p->price=newprice;
    printf("The updated price is: %.2f\n", newprice);
}
void addStock(struct product *p, int amount)
{
    p->qty+=amount;
    printf("Added stock: %d\n", amount);
}
void sellStock(struct product *p, int amount)
{
    if(p->qty>=amount)
    {
p->qty-=amount; 
printf("Ending stock is %d.\n",p->qty);
       printf("Sold %d items.\n", amount);
   }
   else{
       printf("Insufficient stock to sell %d items.\n", amount);
   }
}
int main()
{
struct product products[3];
    for(int i=0; i<3; i++)
    {
        printf("Enter the name of product #%d:\n",i+1);
        fgets(products[i].name,sizeof(products[i].name),stdin);
        printf("Enter the price of product #%d: ",i+1);
        scanf("%f",&products[i].price);
        printf("Enter the quantity on hand of product #%d: ",i+1);
        scanf("%d",&products[i].qty);
        while(getchar()!='\n');
    }
    printf("PRODUCTS DETAILS:\n");
    for(int i=0;i<3;i++)
    {
        printf("Product #%d:\n", i + 1);
        printProduct(products[i]);
    }
    printf("Select a product to modify (1-3): ");
    int choice;
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 3)
    {
        printf("Modifying product #%d:\n", choice);
        printf("Enter new price: ");
        float newPrice;
        scanf("%f", &newPrice);
        updatePrice(&products[choice - 1], newPrice);
        printf("Enter quantity to add: ");
        int addQty;
        scanf("%d", &addQty);
        addStock(&products[choice - 1], addQty);
        printf("Enter quantity to sell: ");
        int sellQty;
        scanf("%d", &sellQty);
        sellStock(&products[choice - 1], sellQty);
    }
    else
    {
        printf("Invalid choice.\n");
    }
    return 0;
}