#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;

struct node{
  struct node *prev;
  struct node *next;
  int serialno;
  char name[40];char des[40];
  char dept;
  long long int phone;
  float sal;
}*head=NULL;
struct node* newnode,*tail;


void create(int a){
for(int i=0;i<a;i++){
newnode=(struct node*)malloc(sizeof(struct node));
    int serialno;
    long long int phone;
    float sal;
    char dept;
    char name[40],des[40];
  newnode->next=NULL;
  newnode->prev=NULL;
    printf("\n enter serialno, name, department,designation,salary,phone no\n");
    scanf("%d %s %c %s %f %lld",&serialno, &name, &dept, &des, &sal, &phone);
    newnode->serialno =serialno ;
    strcpy(newnode->name, name);
    strcpy(newnode->des, des);
    newnode->dept=dept;
    newnode->sal = sal;
    newnode->phone = phone;
if(head==NULL)
head=newnode;
else{
tail->next=newnode;
newnode->prev=tail;

}tail=newnode;
count++;
}

}

void insertbegin(){
 struct node* newnode=(struct node*)malloc(sizeof(struct node));
    int serialno;
    long long int phone;
    float sal;
    char dept;
    char name[40],des[40];
    printf("\n enter serialno, name, department,designation,salary,phone no\n");
    scanf("%d %s %c %s %f %lld",&serialno, &name, &dept, &des, &sal, &phone);
    newnode->serialno =serialno ;
    strcpy(newnode->name, name);
    strcpy(newnode->des, des);
    newnode->dept=dept;
    newnode->sal = sal;
    newnode->phone = phone;

newnode->next=head;
newnode->prev=NULL;
head=newnode;
count++;
}

void insertend(){
    int serialno;
    long long int phone;
    float sal;
    char dept;
    char name[40],des[40];
 struct node* newnode=(struct node*)malloc(sizeof(struct node));
  printf("\n enter serialno, name, department,designation,salary,phone no\n");
    scanf("%d %s %c %s %f %lld",&serialno, &name, &dept, &des, &sal, &phone);
    newnode->serialno =serialno ;
    strcpy(newnode->name, name);
    strcpy(newnode->des, des);
    newnode->dept=dept;
    newnode->sal = sal;
    newnode->phone = phone;


newnode->next=NULL;
tail->next=newnode;
newnode->prev=tail;
tail=newnode;
count++;
}

void insertbw(){
    int serialno;
    long long int phone;
    float sal;
    char dept;
    char name[40],des[40];
int n,i=1;
struct node* newnode=(struct node*)malloc(sizeof(struct node));
struct node* temp=head;
printf("\nenter position at which you want to add\n");
scanf("%d",&n);
if(n<1 || n>=count+2)printf("can't add this position! enter correct position");
else if(n==1)insertbegin();
else if(n==count+1)insertend();

else{
   printf("\n enter serialno, name, department,designation,salary,phone no\n");
    scanf("%d %s %c %s %f %lld",&serialno, &name, &dept, &des, &sal, &phone);
    newnode->serialno =serialno ;
    strcpy(newnode->name, name);
    strcpy(newnode->des, des);
    newnode->dept=dept;
    newnode->sal = sal;
    newnode->phone = phone;

while(i<n-1){
    temp=temp->next;
    i++;
}
newnode->prev=temp;
newnode->next=temp->next;
temp->next=newnode;
newnode->next->prev=newnode;
count++;}
}


void deletefirst(){
    if(head==NULL) printf("\nlist is empty\n");
    else if(head==tail){
        printf("Now list is empty");
        head=NULL;
        count--;
    }
    else{
    struct node *temp=head;
    head=head->next;
    free(temp);
    printf("\ndeleted successfully");
    count--;
    }
   // printf("\nafter deleting first node\n");

}


void deletend(){
     if(head==NULL) printf("\nlist is empty\n");
     else if(head==tail){
        printf("Now list is empty");
        head=NULL;
        count--;
    }
     else{
    struct node* temp=tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    free(temp);
    printf("\ndeleted successfully\n");
    count--;
     }
}


void deletepos(){
    if(head==NULL)printf("list is empty");
    else{
    int n,i=1;
struct node *temp=head;
struct node *t;
printf("\nenter position which element you want to delete\n");
scanf("%d",&n);
if(n<1 || n>count )printf("\nEnter correct position\n");
else if(n==1)deletefirst();
else if(n==count)deletend();
else{
while(i<n-1){
    temp=temp->next;
    i++;
}
t=temp->next;
temp->next=t->next;
t->next->prev=temp;
free(t);
printf("\n deleted successfully");
count--;
}
    }

}

void display(){
struct node* temp=head;
if(head==NULL)printf("link is empty");
printf("\n information of %d emlpoyee\n",count);
while(temp!=NULL){
  printf("%d %s %c %s %f %lld\n",temp->serialno, temp->name,temp->dept, temp->des,temp->sal, temp->phone);
temp=temp->next;
}
}

int flag;
void search(){
    printf("\nenter employee name for finding employee details\n");
    char ename[40];
    scanf("%s",&ename);
    struct node *temp=head;
    if(temp==NULL)printf("\nlist is empty!\n");
    else{

    while(temp!=NULL){
        if(strcmp(temp->name,ename)==0){

          flag=0;
          break;
        }
        else flag=1;
        temp=temp->next;
    }

    if(flag==1)printf("\nsuch data doesn't exist!\n");
    else
      printf("%d %s %c %s %f %lld\n",temp->serialno, temp->name,temp->dept, temp->des,temp->sal, temp->phone);
    }
}

void employerDetails()
{
    int ch, n, i;
   // h = NULL;
   // temp = temp1 = NULL;

    while (1) {
    printf("\n--------Menu------------\n");
    printf("\n 1.create list of employee");
    printf("\n 2.display from beginning");
    printf("\n 3.insert at beginning");
    printf("\n 4.insert at end");
    printf("\n 5.insert at given position");
    printf("\n 6.delete at beginning");
    printf("\n 7.delete at end");
    printf("\n 8.delete at given position");
    printf("\n 9.search employee details");
    printf("\n 10.exit");
    printf("\n----------------------\n");
        printf("\n enter choice : ");
        scanf("%d", &ch);

        // Switch statements begins
        switch (ch) {
        case 1:
            printf("\n enter number of employees:");
            scanf("%d", &n);
            create(n);
            break;
        case 2:
            display();
            break;
        case 3:
            insertbegin();
            break;
        case 4:
            insertend();
            break;
        case 5:
            insertbw();
            break;
        case 6:
            deletefirst();
            break;
        case 7:
           deletend();
            break;
        case 8:
           deletepos();
            break;
        case 9:
            search();
            break;
        case 10:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }
}




int main(){
   employerDetails();
return 0;
}
