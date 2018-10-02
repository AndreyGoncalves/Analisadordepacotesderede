/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   histograma.cpp
 * Author: destroy
 * 
 * Created on 3 de Outubro de 2016, 18:35
 */
#include <cstdlib>
#include <iostream>
#include <prglib.h>
#include <string>
#include <fstream>
#include <math.h>
#include "histograma.h"
using prglib::lista;
histograma::histograma() {
}

histograma::histograma(const histograma& orig) {
}

histograma::~histograma() {
}
void histograma::montagem(lista<long> dados, long desvio){
    long aux=1;
    dados.inicia();
    cout<<"|     desvio         |     nº de pacotes       |"<<endl;
    while(!dados.fim()){
        cout<<"|      "<<desvio*aux<<"         |     "<<dados.proximo()<<"        |"<<endl;
        aux++;
    }
}

