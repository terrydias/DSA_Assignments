//Author: Terrence Dias   Branch: IT  Roll no.: 14
//Circular linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *getnode() {
    return ((struct node *)malloc(sizeof(struct node)));
}

void freenode(struct node *p) {
    free(p);
}

struct node *list = NULL;

void insert_atBeginning();  
void insert_atEnd();  
void insert_atLocation();  
void delete_atBeginning();  
void delete_atEnd();  
void delete_atLocation();  
void display();  
void search();
void concatenate();
void split();
void copy();
void reverse(); 

int main() {
    int choice;
	while(1) {
        printf("\nLinked list functions");
        printf("\n1.Insert at Beginning	\n2.Insert at End	\n3.Insert at Position		\n4.Delete at Beginning		\n5.Delete at End");
        printf("\n6.Delete at Position      \n7.Display     \n8.Search      \n9.Reverse     \n10.Copy       \n11.Concatenate");
        printf("\n12.Split     \n13.Exit");            
        
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        printf("\n");
                
        switch(choice)  
        {  
            case 1: insert_atBeginning();  
                    break;  
            
            case 2: insert_atEnd();  
                    break;  
            
            case 3: insert_atLocation();  
                    break;  
                
            case 4: delete_atBeginning();  
                    break;  
            
            case 5: delete_atEnd();  
                    break;  
                
            case 6: delete_atLocation();  
                    break;  
            
            case 7: display(); 
                    break;  

            case 8: search();  
                    break;  
            
            case 9: reverse();  
                    break;  
            
            case 10: copy(); 
                    break;  

            case 11: concatenate();  
                    break;  
            
            case 12: split();  
                    break;  
            
            case 13: return 0; 
            
            default: printf("Invalid choice!"); 
                    break;    
        }
    }    	
}

void insert_atBeg(){
    int n;
    printf("\nEnter element to be inserted : ");
    scanf("%d", &n);
    struct node *newnode;
    newnode = getnode();
    newnode->info = n;
    newnode->next = list;
    list=newnode;    

}

void insert_atEnd(){
    int n;
    printf("\nEnter element to be inserted : ");
    scanf("%d", &n);
    struct node *newnode, *temp;
    newnode = getnode();
    newnode->info = n;
    temp=list;
    newnode->next = list;
    if (list == NULL)
    {
        list = newnode;
    } else {
        while (temp->next!=list)
        {
            temp = temp->next;
        }
        temp->next = newnode;        
    }

}

void insert_atPosition(){
    int n, count, i;
    struct node *newnode, *temp;
    printf("\nEnter position : ");
    scanf("%d", &count);
    temp=list;
    if(temp==NULL){      
        insert_atBeg(n);
        printf("Since the list is empty, so inserted element at the beginning",count);   
    } else {
        printf("\nEnter element to be inserted : ");
        scanf("%d", &n);
		for(i=1;i<count-1;i++)
		{
		    if(temp-> next==list)
			{
				printf("There are less than %d elements in the List, so inserted element at the end",count);
				break;
			}
			temp=temp->next;
		}
		newnode = getnode();
        newnode->info=n;
		newnode->next=temp->next;
		temp->next=newnode;
		display();

	}
}

void delete_atBeg(){
    if (list == NULL)
    {
        printf("List is empty\n");
    } else {
        struct node *temp;
        temp= list;
        list = temp->next;
        freenode(temp);
    }    

}

void delete_atEnd(){
    if (list == NULL)
    {
        printf("List is empty\n");
    } else {
        struct node *temp, *del;
        temp = list;
        while (temp->next!=list)
        {
            del = temp;
            temp = temp->next;
        }
        del->next = list;
        freenode(temp);  

    }
}

void delete_atPosition(){
    if (list == NULL)
    {
        printf("List is empty\n");
    } else {   
        int i, count;
        struct node *temp, *ptr;        
        printf("\nEnter position : ");
        scanf("%d", &count);
        temp = list;
		if(count==1)
			list=list->next;
		else{
            for(i=1;i<count;i++)
            {
                if(temp-> next==list)
                {
                    printf("There are less than %d elements in the Less" ,count);
                    break;
                }
                ptr=temp;                                     
                temp=temp->next;    
            }
		}
	    if(temp->next!=list){
            printf("Element  %d successfully deleted",temp->info);
            ptr->next=temp->next;
            freenode(temp);
		}
		display();
	} 
}

void display(){
    if (list == NULL)
    {
        printf("List is empty\n");
    } else {
        struct node *temp;
        temp = list;
        printf("\nThe linked list is : ");
        while(temp != list){
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}

void search(){
    if (list == NULL)
    {
        printf("List is empty\n");
    } else {
        struct node *temp;
        int count=0, n;
        temp = list;
        printf("\nEnter element to be searched : ");
        scanf("%d", &n);
        while(temp != list){
            if(n == temp->info){
                count++;
                break;
            }
            temp = temp->next;
        }
        if (count>0)
        {
            printf("Element was found\n");
        } else {
            printf("Element is not in the linked list\n");
        } 
    }    

}

void reverse(){ //working on it
    struct node *t1, *t2, *temp;
    t1 = t2 = NULL;  
    if (list == NULL){
        printf("List is empty");
    } else {
        while (list != NULL) {
            t2 = list->next;
            list->next = t1;
            t1 = list;
            list = t2;
        }
        list = t1;
        temp = list;
        printf("Reversed linked list is : ");  
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");

    }
}

void copy(){
    //working on it
}

void copy(){
    //working on it
}

void concatenate(){
    //working on it
}

void split(){
    //working on it
}