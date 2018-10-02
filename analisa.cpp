/* 
 * File:   analisa.cpp
 * Author: andrey
 * 
 * Created on 24 de Setembro de 2016, 18:52
 */

#include "prglib.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "analisa.h"
#include "libs/lista.h"
#include <unistd.h>


using namespace std;
using namespace prglib;

analisa::analisa() {
}

analisa::analisa(const analisa& orig) {
}

analisa::~analisa() {
}

lista<long> analisa::retira_lista_horarios() {
    lista<long> L1;
    string linha;
    int h, m, s, us;
    long hour_us = 0;
    char c;

    ifstream f("redes2-entrada.txt");

    if (!f) {
        cout << "erro" << endl;
    }

    while (!f.eof()) {

        f >> h >> c >> m >> c >> s >> c >> us;
        f.ignore(10240, '\n');
        hour_us = us + s * 1000000 + m * 60 * 1000000 + h * 60 * 60 * 1000000;
        L1.insere(hour_us);
    }
    return L1;
}

lista<long> analisa::diferecadetempo(lista<long> L1) {
    
    lista<long> L2;
    
    long Tinicial, T;
    L1.inicia();
   // cout<<L1.proximo()<<endl;
    Tinicial = L1.proximo();
    
    while (!L1.fim()) {
        T = L1.proximo();
        L2.insere(Tinicial - T);
        Tinicial = T;
    }
    return L2;
}

long analisa::retorna_limiar(lista<long>  L2) {
    long aux, soma, media, xmenosmedia, somaquadrado, limiar;
    soma=0; 
    somaquadrado=0;
    
    L2.inicia();
    aux = L2.proximo();
    while (!L2.fim()) {
        soma = soma + L2.proximo();
    }
    media = soma / L2.comprimento();
    L2.inicia();
    while (!L2.fim()) {
        xmenosmedia = (L2.proximo() - media);
        somaquadrado = somaquadrado + (xmenosmedia * xmenosmedia);
    }
    desvio = sqrt(somaquadrado / L2.comprimento());
    limiar = media + (3 * desvio);
    return limiar;
}

int analisa::numeroDGrupos(lista<long> L2, long limiar) {
    int grupo=0;
    L2.inicia();
    while (!L2.fim()) {
        if (L2.proximo() >= limiar){
            grupo++;
        }
    }
    return grupo;
}
long analisa::mediaM(lista<long> L){
    long aux=0;
    long soma=0;
    long media=0;
    L.inicia();
    aux = L.proximo();
    while (!L.fim()) {
        soma = soma + L.proximo();
    }
    media = soma / L.comprimento();
    return media;
}
long analisa::media_pacotes_por_grupo(lista<long> L2, long limiar) { 
    int grupo = 0;
    long mediadosgrupos = 0;
    L2.inicia();
    grupo = numeroDGrupos(L2,limiar);
    mediadosgrupos = (L2.comprimento() / grupo);
    return mediadosgrupos;
}

long analisa::minimo_pacotes_por_grupo(lista<long> L2, long limiar){
    int init = 0, min = 0;
    L2.inicia();
    while (!L2.fim()) {
        init++;
        if (L2.proximo() >= limiar) {
            if (init < L2.comprimento()) {
                min = init;
            }
            init = 0;
        }
    }
    return min;
}
long analisa::mediaInterGrupoPac(lista<long> L2, long limiar) {
  
    long media = 0;
    int cont = 0;
    lista<long> aux;
    L2.inicia();
    while (not L2.fim()) {
        long valores = L2.proximo();
        aux.insere(valores);
        if (valores >= limiar) {
            
            media = media + mediaM(aux);
            aux.clear();
            cont++;
        }
    }
   // cout<<cont<<endl;
    //cout<<media<<endl;
    media = media / cont;
    return media;
}

long analisa::mediaInterPacGrupo(lista<long> L2, long limiar){
    lista<long> a;
    L2.inicia();
    while (not L2.fim()) {
        long valor = L2.proximo();
        if (valor >= limiar) {
            a.anexa(valor);
        }
    }
    return mediaM(a);
    
}



long analisa::maximo_pacotes_por_grupo(lista<long> L2, long limiar){
 int init = 0, max = 0;
    
    L2.inicia();
    while (!L2.fim()) {
        init++;
        if (L2.proximo() >= limiar) {
            if (init > max) {
                max = init;
            }
            init = 0;
        }
    }
    return max;
}
lista<long> analisa::osNmaiorespacotes (lista<long> L2, int N){
        lista <long> aux;
        int i=0;
        L2.ordena();
        L2.inverte();
        while(i<=N){
            aux.anexa(L2.obtem(i));
            i++;
        }
        return aux;  
}
lista<long> analisa::osNmenoresspacotes (lista<long> L2, int N){
        lista <long> aux;
        int i=0;
        L2.ordena();
      
        while(i<=N){
            aux.anexa(L2.obtem(i));
            i++;
         }
        return aux;  
}


lista <long> analisa::N_intervalo_grupos(lista<long> L2, long limiar, int N) { 
    lista<long> L3;
    lista <long> N_intervalos;
    long aux;
    int i=0;
    
    L2.inicia();
    while (!L2.fim()) {
        aux = L2.proximo();
        if ( aux > limiar) {
            L3.anexa(aux);
        }
    }
    L3.ordena();
    L3.inverte();
    while(i<=N){
            N_intervalos.anexa(L3.obtem(i));
            i++;
         }
        return N_intervalos; 
}
lista<long> analisa::freq (lista<long> L2){
    lista<long> teste;
    long aux=1;
    long c=0;
    long d=0;
    long max;
    long cont=0;
    L2.inicia();
    L2.ordena();
    L2.inverte();
    max=L2.obtem(0);//maior valor
    //cout<<max<<endl;
    while(c<max+desvio){
         c=c+aux*desvio;
         L2.inicia();
         L2.ordena();
        while(!L2.fim()){
            long algo=L2.proximo();
            if ((algo<=c) && (algo>=d)){
               cont++;
            }
        }
       // cout<<c<<endl;
       // cout<<cont<<endl;
        teste.insere(cont);
        cont=0;
        d=c;
        aux++;
    }
    teste.inverte();
    return teste;
}




