#include <iostream>
using namespace std;
struct cella 
{
 int valore;
 cella* succ;
};
typedef cella* lista; 

// Questa procedura inserisce nella lista i valori forniti da tastiera
void inserisci(lista& inizio, int e)
{ 
lista p=new cella;
p->valore=e;
p->succ=inizio;
inizio=p;
}
void inserisici_in_fondo(lista& inizio,int d) 
{ // il prof non la richiedeva ma io l'ho inserita per comodità, in modo da inserire gli elementi che avanzano alla fine della lista come richiesto da lui
	lista p,q;
	for (q=inizio;q!=0;q=q->succ)
	p=q;
	q=new cella;
	q->valore=d;
    q->succ=0;
    p->succ=q;
}
// Questa procedura esegue la somma uno ad uno degli elementi corrispondenti
// delle due liste (primo con primo, ecc.) ogni somma finisce nella terza lista
void sommaliste(lista inizio1, lista inizio2, lista& inizio3)
{
	int d;
while (inizio1!=0 || inizio2!=0)
{
	d=inizio1->valore+inizio2->valore; 
	inserisci(inizio3,d); // dopo aver sommato i due elementi delle due lista, li inserisce nella terza
	//scorro le due lista
	inizio1=inizio1->succ; 
	inizio2=inizio2->succ;
   // controlllo quando le due liste sono finite, se lo è una delle due,aggiungerà gli elementi restanti nell'altra lista in fondo alla lista 3 
    if (inizio1==0)  
	{
	d=inizio2->valore;
	inserisici_in_fondo(inizio3,d);
	inizio2=inizio2->succ;
	}
	else if (inizio2==0)
	{
	d=inizio1->valore;
	inserisici_in_fondo(inizio3,d);
	inizio1=inizio1->succ;
	}
	}
}


// Questa procedura stampa a video il contenuto della lista
void stampa(lista inizio)
{
	while (inizio!=0)
	{
		cout << inizio->valore << endl;
		inizio=inizio->succ;
	}
}
int main()
{
	lista inizio1=0;
	lista inizio2=0;
	lista inizio3=0;
	char r,f;
	int q,u,y;
	do 
	{
		cout << "MENU'\na) SCEGLI IN QUALE LISTA INSERIRE I DATI\n" <<
"b) SOMMA I CORRISPONDENTI ELEMENTI DELLA PRIMA E DELLA SECONDA LISTA INSERENDOLI NELLA TERZA\n" <<
"c) SCEGLI QUALE LISTA STAMPARE A VIDEO\nd) ESCI DAL PROGRAMMA" << endl << "Scelta: ";
cin >> r;
switch (r)
{
	case 'a':{
		do {
			cout << "1) PER INSERIRE I VALORI NELLA PRIMA LISTA\n2) PER INSERIRE I VALORI NELLA SECONDA LISTA" << endl; 
			cout << "Scelta: ";
			cin >> q;
			if (q==1)
			{
				cout << "IMMETTI IL VALORE DA INSERIRE NELLA PRIMA LISTA: ";
				cin >> u;
				inserisci(inizio1,u);
			}
			else if (q==2)
			{
				cout << "IMMETTI IL VALORE DA INSERIRE NELLA SECONDA LISTA: " ;
				cin >> u;
				inserisci(inizio2,u);
			}
		 if (q>2||q==0) {
			cout << "puoi usare solo 1 o 2 come numeri" << endl;
	f='n'; // torna al menu principale 
		}
		else if(q==2||q==1){
			cout << "VUOI INSERIRE UN ALTRO VALORE? ";
			cin >> f;}
		}
		while (f=='s');
	}break;
case 'b':{ 
	sommaliste(inizio1,inizio2,inizio3);
	cout << "SOMMA EFFETTUATA" << endl;
}break;
case'c':
{
	cout << "1) PER STAMPARE LA PRIMA LISTA\n2) PER STAMPARE LA SECONDA LISTA\n3) PER STAMPARE LA TERZA LISTA" << endl;
	cout << "Scelta: ";
	cin>> y;
	if (y==1)stampa(inizio1);
	else if (y==2) stampa(inizio2);
	else if (y==3) stampa(inizio3);
	} break;
	case'd':{}break;
	default: cout << "HAI DIGITATO UNA LETTERA SBAGLIATA, USA SOLO LE LETTERE CONSENTITE NEL MENU'" << endl;break;
}

}
	while (r!='d');
}

