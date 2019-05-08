/*
Nama Program : Exer 1
Nama         : Sharashena Chairani
NPM          : 14081080022
Tanggal buat : 08 Mei 2019
Deskripsi    : Queue Circular Link List
********************************************/

#include <iostream>
using namespace std;

const int maxElement=5; // Batas Maksimal Antrian

struct Queue{
    char isi[maxElement];
    int head;
    int tail;
};

void createQueue(Queue &Q);
void push(Queue &Q);
void pop(Queue &Q);
void print(Queue Q);

int main(){
    Queue Q;
	int pil,n;
	char loop;
	createQueue(Q);
	do{
		cout<<"Banyak Data (max 5): ";
		cin>>n;
	}
		while(n>maxElement);
	
	cout<<"Masukkan Data : "<<endl;
	for(int i=0; i<n; i++){
		push(Q);
	}
	do{
		system("cls");
		cout<<"\t Pilihan Menu"<<endl;
		cout<<"\t1. Tambahkan Antrian"<<endl;
		cout<<"\t2. Kurangi Antrian"<<endl;
		cout<<"\t3. Print Antrian"<<endl;
		do{
			cin>>pil;
		}
		while(pil>3 || pil<1);
		
		switch(pil){
			case 1:
				if(Q.head!=0){
					cout<<"Masukkan Data : "<<endl;
				}
				push(Q);
				
				break;
			case 2:
				pop(Q);
				
				break;
			case 3:
				print(Q);
				
				break;
		}
		cout<<endl<<"Kembali ke menu? (Y/N) ";
		do{
			cin>>loop;
		}while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
	}while(loop=='Y' || loop=='y');
	if(loop=='N' || loop=='n'){
		cout<<endl<<"Terima Kasih!"<<endl;
	}
}

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}
void push(Queue &Q){
    if(Q.head==-1){
		Q.head++;
		Q.tail++;
		cin>>Q.isi[Q.head];
	}
	else{
		if(Q.tail < maxElement - 1){
			Q.tail++;
			cin>>Q.isi[Q.tail];
		}
		else{
			if(Q.head == 0){
				cout<<"Antrian penuh!"<<endl;
			}
			else{
				Q.tail = 0;
				cin>>Q.isi[Q.tail];
			}
		}
	}
}
void pop(Queue &Q){
	if(Q.tail == -1){
		cout<<"Antrian kosong, tidak ada yang didelete"<<endl;
	}
	else if(Q.head == Q.tail){
		Q.head = -1;
		Q.tail = -1;
	}
	else{
		if(Q.head < maxElement - 1){
			Q.head++;
		}
		else{
			Q.head = 0;
		}
	}
}
void print(Queue Q){
	if(Q.head == -1){
		cout<<"Antrian Kosong."<<endl;
	}else{
		int i= Q.head;
		cout<<endl<<"Antrian = [";
		if(Q.head > Q.tail){
			while(i < maxElement){
				cout<<Q.isi[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
			i=0;
			while(i<=Q.tail){
				cout<<Q.isi[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		else{
			while(i<=Q.tail){
				cout<<Q.isi[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		cout<<"]"<<endl;
	}
}
