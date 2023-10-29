#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Listeye rastgele üretilmiþ 100 sayý eklensin, girilen tüm sayýlarý büyükten küçüðe sýralayan ve ekrana basan c kodunu yazýnýz.*/

struct node {
	int data; 
	struct node *next; 
};

// yeni bir düðüm oluþturan ve verisini atayan fonksiyon
struct node *create_node(int data) {
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->data = data; 
	temp->next = NULL; 
	return temp; 
}

// baðlý listenin baþýna yeni bir düðüm ekleyen fonksiyon
struct node *addFront(struct node *head, int data) {
	struct node *temp = create_node(data); 
	temp->next = head; 
	head = temp; 
	return head;
}

// baðlý listeyi büyükten küçüðe sýralayan fonksiyon
struct node *siralaList(struct node *head) {
	struct node *current = head; // geçerli düðümü baþtan baþlatma
	struct node *index = NULL; // indeks düðümünü NULL olarak baþlatma
  	int temp; // yer deðiþtirmek için geçici deðiþken

  	if (head == NULL) { // baðlý liste boþsa fonksiyondan çýk
    	return 0; 
    } 	
    else {
    	while (current != NULL) { // geçerli düðüm NULL olana kadar döngü
      		index = current->next; // indeks düðümünü geçerli düðümün sonrakine ayarlama

      		while (index != NULL) { // indeks düðümü NULL olana kadar döngü
        		if (current->data < index->data) { // geçerli düðümün verisi indeks düðümünün verisinden küçükse
          			temp = current->data; // geçici deðiþkene geçerli düðümün verisini atama
          			current->data = index->data; // geçerli düðümün verisini indeks düðümünün verisiyle deðiþtirme
          			index->data = temp; // indeks düðümünün verisini geçici deðiþkenle deðiþtirme
        		}
        		index = index->next; // indeks düðümünü bir sonraki düðüme ilerletme
      		}
      		current = current->next; // geçerli düðümü bir sonraki düðüme ilerletme
    	}
  	}
  	return head;
}

// baðlý listeyi ekrana basan fonksiyon
void printList(struct node *head) {
  	struct node *temp = head; // geçici pointer'ý baþa ayarlama

 	while (temp != NULL) { // geçici pointer NULL olana kadar döngü
   		printf("%d ", temp->data); // geçici pointer'ýn verisini ekrana basma
    	temp = temp->next; // geçici pointer'ý bir sonraki düðüme ilerletme
  	}
  	printf("\n");
}

int main() {
  	// rastgele sayý üretmek için tohum ayarlama
  	srand(time(NULL));

  	struct node *head = NULL; // baðlý listenin baþ pointer'ýný NULL olarak baþlatma

  	// baðlý listeye rastgele sayýlarla doldurma
  	for (int i = 0; i < 100; i++) {
    	head=addFront(head, rand() % 1000); // baðlý listenin baþýna rastgele bir tam sayý ekleme (0 ile 999 arasýnda)
  	}

  	// baðlý listeyi sýralama
  	head=siralaList(head);

  	// baðlý listeyi ekrana basma
  	printList(head);

  	return 0;
}

