#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
		int data;
		struct node* next;
	};

struct node *head=NULL,*tail=NULL,*temp=NULL,*temp2=NULL;

void insertll(int x){
	if(head==NULL){
	head=(struct node*)malloc(sizeof(struct node));
	head->data=x;
	head->next=NULL;
	tail=head;
	}
	else{
	tail->next=(struct node*)malloc(sizeof(struct node));
	tail=tail->next;
	tail->data=x;
	tail->next=NULL;
	}
}

void deletell(int del){
	temp=head;
	while(temp!=NULL){
		if((temp->data)==del){
			head=temp->next;
            temp->next=NULL;
            free(temp);
            break;
		}
        else if(temp->next->data==del && temp->next==tail){
            temp2=temp->next;
            temp->next=NULL;
            free(temp2);
            break;

        }
        else if(temp->next->data==del){
            temp2=temp->next;
            temp->next=temp->next->next;
            free(temp2);
            break;
        }
        else{
            temp=temp->next;
        }
	}
}

void largell(int del){
	int mx=__INT_MAX__;
	temp=head;
	while(temp!=NULL){
		if((temp->data)>del && (temp->data)<mx){
			mx=temp->data;
		}
		temp=temp->next;
	}
	(mx==__INT_MAX__)?printf("\n\n%d was the largest number in the list\n",del):printf("\n\nThe next largest number is:  %d\n",mx);
}

void printll(){
	temp=head;
	while(temp!=NULL){
	printf("%d  ",temp->data);
	temp=temp->next;
	}
}

void printarr(int a[],int n){
	for(int i=0;i<n-1;i++){printf("%d  ",a[i]);}
	printf("\n");
}

void removearr(int a[],int d,int n){
	for(int i=d;i<n-1;i++){
		a[i]=a[i+1];
	}
}

void nextel(int temp,int n,int a[]){
	int mx=__INT_MAX__;
	for(int i=0;i<n-1;i++){
	if(a[i]>temp && a[i]<mx){mx=a[i];}
	}
	(mx==__INT_MAX__)?printf("%d was the largest number in the array\n",temp):printf("\nThe next largest number is:  %d\n",mx);
}

int main(){
 	srand(time(0));
 	clock_t d1,d2,l1,l2;
 	clock_t dd1,dd2,ll1,ll2;
 	double tot1,tot2;
 	double tot3,tot4;
	long n;
	printf("\n\n-----LINK LIST + ARRAY-----");
	printf("\n\nEnter the number of elements:\t");
	scanf("%ld",&n);
	int a[n],x,pos,t;
	for(int i=0;i<n;i++){
		a[i]=rand()%(101);
		insertll(a[i]);
	}
	pos=n-1;
	int temp=a[pos];
	

	d1=clock();
	removearr(a,pos,n);
	d2=clock();
	tot1=((double)d2-d1)/CLOCKS_PER_SEC;
	l1=clock();
	nextel(temp,n,a);
	l2=clock();
	tot2=((double)l2-l1)/CLOCKS_PER_SEC;
	dd1=clock();
	deletell(temp);
	dd2=clock();
	tot3=((double)dd2-dd1)/CLOCKS_PER_SEC;
	ll1=clock();
	largell(temp);
	ll2=clock();
	tot4=((double)ll2-ll1)/CLOCKS_PER_SEC;
	printf("\nARRAY:\n");
	printf("\nTime taken for deletion:\t%.9lf\n",tot1);
	printf("\nTime taken for finding next element:\t%.9lf\n",tot2);
	printf("\nLINKED LIST:\n");
	printf("\nTime taken for deletion:\t%.9lf\n",tot3);
	printf("\nTime taken for finding next element:\t%.9lf\n\n",tot4);
	return 0;
}
