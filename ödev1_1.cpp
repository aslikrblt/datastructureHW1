#include <stdio.h> 
#include <stdlib.h> 
 
/* klavyeden -1 girilinceye kadar girilen tüm tek sayýlarý listenin baþýna, çift sayýlarý ise listenin sonuna ekleyen fonksiyon */ 

struct node { 
	int data; 
    struct node* next; 
}; 
  
struct node *fonk(struct node *head, int x){  //value=klavyeden girilen deðerler 
	//liste boþ 
    struct node *temp=(struct node*)malloc(sizeof(struct node));  //ilk düðüm   
    temp->data = x; 
    temp->next = NULL; 
     
    if(head == NULL){ 
        head = temp; //ilk düðüm=head olmalý
    } 
    else if(temp->data %2 !=0){  //eðer sayý tek ise baþa eklenmeli 
        struct node *current = temp;  
        current->data = x; 
        current->next =head;  
        head = current;  
    } 
    else{  //eðer çift ise sona eklenmeli
        struct node *current = head ; //current bize listenin head ini gösteriyor 
        //listeyi ters çeviricez listenin sonunu görmeliyiz
        while(current->next!=NULL){ 
            current=current->next; 
        }//while döngüsünün sonunda current son düðümü gösteriyor olur . temp i son düðümün yanýna eklemeliyiz 
        current->next = temp; 
    } 
    return head;
} 
 
int main(){ 
    int x; 
    struct node *head = NULL; 
 
    printf("listeye ekleyeceginiz verileri giriniz.  ( cikmak icin -1 i tuslayiniz.) :\n");  
 
    while(1){ //sonsuz döngü, true == 1 
        scanf("%d",&x); 
        if(x == -1) 
            break;  
        //veri -1 den farklý ise onu temp e eklemeli
        //tek çift ayrýmý ve diziliþi için fonksiyonu çaðýrmalý
        head=fonk(head,x); 
    } 
 
    struct node *current = head; 
	 
    printf("liste :  "); //tüm listeyi yazdýrmalý
 
    while(current != NULL){ 
        printf("%d->",current->data); 
        current=current->next; 
    } 
 
    printf("liste sonu\n"); 
 
} 
