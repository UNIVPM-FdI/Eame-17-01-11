#include <iostream>
using namespace std;
struct cella
{
int valore;
cella* succ;
};
typedef cella* lista;
void inserisci(lista&,int);
void sommaliste(lista, lista, lista& inizio3);
void stampa(lista);

int main(){
char s,c;
int n=0,l=0,h=0;
lista lista1=0;
lista lista2=0;
lista lista3=0;
do{
do{
cout << "\nMenu'";
cout << "\na: Scegli in quale lista inserire i dati";
cout << "\nb: Somma i corrispondenti elementi della prima e della seconda lista inserendoli nella terza lista";
cout << "\nc: Scegli quale lista stampare a video";
cout << "\nd: Esci dal programma";
cout << "\nScelta:";
cin>>s;
if(s!='a'&&s!='b'&&s!='c'&&s!='d'){
    cout<<"lettera non consentita"<<endl;
}
}while(s!='a'&&s!='b'&&s!='c'&&s!='d');
switch(s){
    case 'a':{
        do{
            cout << "1) Per inserire i valori nella prima lista\n";
            cout << "2) Per inserire i valori nella seconda lista\n";
            cout << "Scelta: ";
            cin>>l;
            if(l!=1&&l!=2){
                cout<<"numero non consentito"<<endl;
            }
        }while(l!=1&&l!=2);
        switch(l){
            case 1:{
                do{
                    cout<<"inserisci il numero"<<endl;
                    cin>>n;
                    inserisci(lista1,n);
                    cout<<"vuoi inserire un altro valore"<<endl;
                    cin>>c;
                    if(c!='s'&&c!='n'){
                        cout<<"inserisci solo s o n"<<endl;
                    }
                }while(c=='s');
            break;
            }
            case 2:{
                do{
                    cout<<"inserisci il numero"<<endl;
                    cin>>n;
                    inserisci(lista2,n);
                    cout<<"vuoi inserire un altro valore"<<endl;
                    cin>>c;
                    if(c!='s'&&c!='n'){
                        cout<<"inserisci solo s o n"<<endl;
                    }
                }while(c=='s');
            break;
            }
        }
    break;
    }
    case 'b':{
        sommaliste(lista1,lista2,lista3);
    break;
    }
    case 'c':{
        do{
            cout << "1) Per stampare la prima lista\n";
            cout << "2) Per stampare la seconda lista\n";
            cout << "3) Per stampare la terza lista\n";
            cout << "Scelta: ";
            cin>>h;
            if(h!=1&&h!=2&&h!=3){
                cout<<"lista inesistente"<<endl;
            }
        }while(h!=1&&h!=2&&h!=3);
        switch(h){
            case 1:{
                cout<<"sono presenti"<<endl;
                stampa(lista1);
            break;
            }
            case 2:{
                cout<<"sono presenti"<<endl;
                stampa(lista2);
            break;
            }
            case 3:{
                cout<<"sono presenti"<<endl;
                stampa(lista3);
            break;
            }
        }
    break;
    }
}
}while(s!='d');
return 0;
}

void stampa(lista inizio){
lista p=inizio;
if(p==0){
    cout<<"lista vuota"<<endl;
}
while(p!=0){
    cout<<p->valore<<endl;
    p=p->succ;
}
}

void inserisci(lista& inizio, int e){//inserimento in coda
lista p = 0, q,r;
for(q=inizio; q != 0; q = q->succ)
p = q;
r = new cella;
r -> valore = e;
r -> succ = 0;
if(inizio == 0)//se è il primo elemento
inizio = r;
else
p -> succ = r;
}
/*
void inserisci_testa(lista& inizio, int e)//funzione nel caso la si vuole inserire in testa
p->valore=e;
p->succ = inizio;
inizio = p;
}
*/
void sommaliste(lista inizio1, lista inizio2, lista& inizio3){
int p=0;
int q=0;
while(inizio1!=0||inizio2!=0){
    p=inizio1->valore;//prende il valore di inizio->valore e lo salva in p
    q=inizio2->valore;//prende il valore di inizio->valore e lo salva in q
    p+=q;//somma i due valori e li mette in p
    inserisci(inizio3,p);
    inizio1=inizio1->succ;//si passa al successivo elemento
    inizio2=inizio2->succ;//si passa al successivo elemento
}
cout<<"lista 1 e 2 sommate in lista 3"<<endl;
}

//Coded by DarkCerfa
