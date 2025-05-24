#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

struct city{
    char name[50];
    int x;
    int y;
};

struct node{
    char name[50];
    long long int phone_number;
    char pickup_address[200];
    char drop_address[200];
    int citya;
    int cityb;
    float weight;
    long int order_number;
    float distance;
    float charge;
    struct node *next;
}*head=NULL,*tail=NULL;

float calculate_distance(struct city a ,struct city b){
    float distance;
    distance=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return distance;
}
long int random1(){
    long int lower=100000;
    long int upper=999999;
    long int randomNumber=(rand()%(upper-lower+1))+lower;
    return randomNumber;
}
float charge1(struct node newnode){int x;
    float charge;
    printf("Click 1 if the area is urban or Click 2 if the area is rural\n");
      scanf("%d",&x);
      if(x==1){
        charge =(1.5*newnode.distance)+(0.75*newnode.weight);
       
      }
      else if (x==2){
        charge =20+(1.5*newnode.distance)+(0.75*newnode.weight);
    }
    return charge;
};
void placeorder(){
    int a ,b;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter your name:");
    scanf("%s", newnode->name);
    struct city cities[10]={
        {"Mathura",0,0},
        {"Palwal",-30,-40},
        {"Noida",-70,50},
        {"Aligarh",-50,20},
        {"Agra",50,20},
        {"Delhi",-80,55},
        {"Bharatpur",30,40},
        {"Alwar",60,15},
        {"Faridabad",-50,-35},
        {"Jaipur",100,40}
    };
    printf("Select pickup city:\n");
    for(int i=0;i<10;i++){
        printf("%d.%s\n",i+1,cities[i].name);
    }
    printf("Enter the number of city:\n");
    scanf("%d",&newnode->citya);
    printf("Enter pickup address:");
    scanf("%s",newnode->pickup_address);
    printf("Select drop-off city:\n");
    for(int i=0;i<10;i++){
        printf("%d.%s\n",i+1,cities[i].name);
    }
    printf("Enter the number of city:\n");
    scanf("%d",&newnode->cityb);
      a=newnode->citya;
      b=newnode->cityb;
    printf("Enter drop-off address:");
    scanf("%s",newnode->drop_address);
      printf("Enter you phone number");
      scanf("%lld",&newnode->phone_number);
     newnode->distance= calculate_distance(cities[a-1],cities[b-1]);
     printf("Enter the weight of the courier in Kg:");
    scanf("%f",&newnode->weight);
     newnode->charge=charge1(*newnode);
    
    newnode->order_number=random1();
    printf("Your Order ID:%ld", newnode->order_number);
    //printf("%d", price);
    newnode->next=NULL;
    if (head==NULL){
        tail=head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
 
}
void delete_order(){
    struct node*temp,*ptr=NULL;
    temp=head;
    long int orderid;
    printf("Enter your order_id to cancel:\n");
    scanf("%ld",&orderid);
    if (temp==NULL){
        printf("There is no order yet:\n");
        return;
    }
    else if(head->order_number==orderid){
        head=head->next;
        tail=head;
        printf("Your order having Order Id %ld has been cancelled\n",orderid);
        free(temp);
        return;
    }
    else if (tail->order_number==orderid){
        while(temp->next!=tail){
            temp=temp->next;  
    }
        ptr=temp;
        temp=tail;
        ptr->next=NULL;
        tail=ptr;
        printf("Your order having Order Id %ld has been cancelled\n",orderid);
        free(temp);
        return;
      
    }
    else{
        while (temp != NULL && temp->next != NULL && temp->next->order_number != orderid) {
                     temp = temp->next;
                    }
                 if (temp == NULL || temp->next == NULL) {
                     printf("Order ID not found. Please enter a valid ID.\n");
                 } else {
                     ptr = temp->next;
                     temp->next = ptr->next;
                     printf("Order ID %ld has been deleted.\n", ptr->order_number);  
                     free(ptr);
    }
}
}

void display(){
    long long int x;
    struct node*temp,ptr;
    temp=head;
    if (head==NULL){
        printf("There is no oder yet:\n");
    }
    else{
        printf("Enter your oderid:\n");
        scanf("%lld",&x);
        while(temp->order_number!=x && temp!=NULL && temp->next!=NULL){
            temp=temp->next;
        }
        if (temp->order_number==x){
            printf("\nCustomer's Name: %s\n",temp->name);
            printf("\nPickup address: %s\n",temp->pickup_address);
            printf("\nDrop-off address: %s\n",temp->drop_address);
            printf("\nOrder ID: %ld\n",temp->order_number);
            printf("\nAmount charged: %f\n",temp->charge);
        }
        else{
            printf("Enter a valid order number");
        }
    }
}

int main()
{ 
    srand(time(NULL));
    
     int choice;
    
while(1){
    printf("\nEnter your choice:\n1.Place an order:\n2.Cancel an order:\n3.Display the bill:\n4.Exit:\n");
    scanf("%d",&choice);
    if (choice==1){
        placeorder();
    }
    else if (choice==2){
        delete_order();
    }
    else if (choice==3){
        display();
    }
    else if(choice==4){
        break;
    }
    else {
        printf("enter a valid choice:\n");
    }
}
    
     return 0;
}