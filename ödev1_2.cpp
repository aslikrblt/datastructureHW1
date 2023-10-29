#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Listeye rastgele �retilmi� 100 say� eklensin, girilen t�m say�lar� b�y�kten k����e s�ralayan ve ekrana basan c kodunu yaz�n�z.*/

struct node {
	int data; 
	struct node *next; 
};

// yeni bir d���m olu�turan ve verisini atayan fonksiyon
struct node *create_node(int data) {
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->data = data; 
	temp->next = NULL; 
	return temp; 
}

// ba�l� listenin ba��na yeni bir d���m ekleyen fonksiyon
struct node *addFront(struct node *head, int data) {
	struct node *temp = create_node(data); 
	temp->next = head; 
	head = temp; 
	return head;
}

// ba�l� listeyi b�y�kten k����e s�ralayan fonksiyon
struct node *siralaList(struct node *head) {
	struct node *current = head; // ge�erli d���m� ba�tan ba�latma
	struct node *index = NULL; // indeks d���m�n� NULL olarak ba�latma
  	int temp; // yer de�i�tirmek i�in ge�ici de�i�ken

  	if (head == NULL) { // ba�l� liste bo�sa fonksiyondan ��k
    	return 0; 
    } 	
    else {
    	while (current != NULL) { // ge�erli d���m NULL olana kadar d�ng�
      		index = current->next; // indeks d���m�n� ge�erli d���m�n sonrakine ayarlama

      		while (index != NULL) { // indeks d���m� NULL olana kadar d�ng�
        		if (current->data < index->data) { // ge�erli d���m�n verisi indeks d���m�n�n verisinden k���kse
          			temp = current->data; // ge�ici de�i�kene ge�erli d���m�n verisini atama
          			current->data = index->data; // ge�erli d���m�n verisini indeks d���m�n�n verisiyle de�i�tirme
          			index->data = temp; // indeks d���m�n�n verisini ge�ici de�i�kenle de�i�tirme
        		}
        		index = index->next; // indeks d���m�n� bir sonraki d���me ilerletme
      		}
      		current = current->next; // ge�erli d���m� bir sonraki d���me ilerletme
    	}
  	}
  	return head;
}

// ba�l� listeyi ekrana basan fonksiyon
void printList(struct node *head) {
  	struct node *temp = head; // ge�ici pointer'� ba�a ayarlama

 	while (temp != NULL) { // ge�ici pointer NULL olana kadar d�ng�
   		printf("%d ", temp->data); // ge�ici pointer'�n verisini ekrana basma
    	temp = temp->next; // ge�ici pointer'� bir sonraki d���me ilerletme
  	}
  	printf("\n");
}

int main() {
  	// rastgele say� �retmek i�in tohum ayarlama
  	srand(time(NULL));

  	struct node *head = NULL; // ba�l� listenin ba� pointer'�n� NULL olarak ba�latma

  	// ba�l� listeye rastgele say�larla doldurma
  	for (int i = 0; i < 100; i++) {
    	head=addFront(head, rand() % 1000); // ba�l� listenin ba��na rastgele bir tam say� ekleme (0 ile 999 aras�nda)
  	}

  	// ba�l� listeyi s�ralama
  	head=siralaList(head);

  	// ba�l� listeyi ekrana basma
  	printList(head);

  	return 0;
}

