#include <stdio.h> 
#include <stdlib.h> 
 
/* klavyeden -1 girilinceye kadar girilen t�m tek say�lar� listenin ba��na, �ift say�lar� ise listenin sonuna ekleyen fonksiyon */ 

struct node { 
	int data; 
    struct node* next; 
}; 
  
struct node *fonk(struct node *head, int x){  //value=klavyeden girilen de�erler 
	//liste bo� 
    struct node *temp=(struct node*)malloc(sizeof(struct node));  //ilk d���m   
    temp->data = x; 
    temp->next = NULL; 
     
    if(head == NULL){ 
        head = temp; //ilk d���m=head olmal�
    } 
    else if(temp->data %2 !=0){  //e�er say� tek ise ba�a eklenmeli 
        struct node *current = temp;  
        current->data = x; 
        current->next =head;  
        head = current;  
    } 
    else{  //e�er �ift ise sona eklenmeli
        struct node *current = head ; //current bize listenin head ini g�steriyor 
        //listeyi ters �eviricez listenin sonunu g�rmeliyiz
        while(current->next!=NULL){ 
            current=current->next; 
        }//while d�ng�s�n�n sonunda current son d���m� g�steriyor olur . temp i son d���m�n yan�na eklemeliyiz 
        current->next = temp; 
    } 
    return head;
} 
 
int main(){ 
    int x; 
    struct node *head = NULL; 
 
    printf("listeye ekleyeceginiz verileri giriniz.  ( cikmak icin -1 i tuslayiniz.) :\n");  
 
    while(1){ //sonsuz d�ng�, true == 1 
        scanf("%d",&x); 
        if(x == -1) 
            break;  
        //veri -1 den farkl� ise onu temp e eklemeli
        //tek �ift ayr�m� ve dizili�i i�in fonksiyonu �a��rmal�
        head=fonk(head,x); 
    } 
 
    struct node *current = head; 
	 
    printf("liste :  "); //t�m listeyi yazd�rmal�
 
    while(current != NULL){ 
        printf("%d->",current->data); 
        current=current->next; 
    } 
 
    printf("liste sonu\n"); 
 
} 
