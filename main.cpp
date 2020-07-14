#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
struct Animais{
    char nome;
    int pos_atual=1;
};
void inicializa(Animais * Lebre, Animais * Tartaruga){ // usando apontadores posso fazer alterações nos "objetos"
    Lebre->nome = 'L';                                 // sem usar funções com retorno
    Tartaruga->nome = 'T';
}

void impressao(Animais * Lebre, Animais * Tartaruga){
    int i=1;
    for (;i <= 70; i++){
        if (i != Lebre->pos_atual && i != Tartaruga->pos_atual){
            cout << "-";
        }
        else if (i == Lebre->pos_atual && i == Tartaruga->pos_atual){
            cout << "Batida!!";
        }
        else if (i == Lebre->pos_atual){
            cout << Lebre->nome;
        }
        else{
            cout << Tartaruga->nome;
        }
    }
    cout << endl;
    if (Tartaruga->pos_atual == 70 || Lebre->pos_atual == 70){
        if (Tartaruga->pos_atual == 70 && Lebre->pos_atual != 70){
            cout << "A Tartaruga venceu !!!" << endl;
        }
        else if (Tartaruga->pos_atual != 70 && Lebre->pos_atual == 70){
            cout << "A Lebre venceu !!!" << endl;
        }
        else{
            cout << "A terminou empatada !!!" << endl;
        }
    }
}

int valor_teto(int pos_atual, int x){
    if (pos_atual + x > 70){
        return 70;
    }
    else{
        return (pos_atual + x);
    }
}

int valor_piso (int pos_atual, int x){
    if (pos_atual - x < 1){
        return 1;
    }
    else
        return (pos_atual -x);
}

int aleatorio(){
    return (rand() % 10) + 1;
}

void Tartaruga_pos_x(Animais * Tart){
    int pos_x =0;
    pos_x = aleatorio(); // ainda não está certo, tenho que chamar a biblioteca
    if (pos_x <= 5){
        Tart->pos_atual = valor_teto(Tart->pos_atual,3);
    }
    else if(pos_x <= 7){
        Tart->pos_atual = valor_piso(Tart->pos_atual, 6);
    }
    else{
        Tart->pos_atual = valor_teto(Tart->pos_atual,1);
    }
}

void Lebre_pos_x(Animais * Lebre){
    int pos_x =0;
    pos_x = aleatorio(); // ainda não está certo, tenho que chamar a biblioteca
    if ((3 <= pos_x) && (pos_x <= 4)){
        Lebre->pos_atual = valor_teto(Lebre->pos_atual,9);
    }
    else if(pos_x == 5){
        Lebre->pos_atual = valor_piso(Lebre->pos_atual, 12);
    }
    else if ((6 <= pos_x) && (pos_x <= 8)) {
        Lebre->pos_atual = valor_teto(Lebre->pos_atual,1);
    }
    else if ((9 <= pos_x) && (pos_x <= 10)){
        Lebre->pos_atual = valor_piso(Lebre->pos_atual,2);
    }
}

void Tique_do_relogio(){
    Animais Lebre, Tartaruga;
    inicializa(&Lebre, &Tartaruga);
    srand((unsigned)time(0));
    cout << "Clássica corrida Lebre vs Tartaruga" << endl;
    cout << "A Lebre serah represantada pela letra L" << endl;
    cout << "A Tartaruga serah represantada pela letra T" << endl;
    while(Lebre.pos_atual != 70 && Tartaruga.pos_atual != 70){
        Lebre_pos_x(&Lebre);
        Tartaruga_pos_x(&Tartaruga);
        impressao(&Lebre,&Tartaruga);
        Sleep(1000);
    }
}

int main(){
  Tique_do_relogio();
  return 0;
}


