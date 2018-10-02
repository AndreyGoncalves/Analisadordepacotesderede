/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   histograma.h
 * Author: destroy
 *
 * Created on 3 de Outubro de 2016, 18:35
 */

#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H
#include <cstdlib>
#include <iostream>
#include <prglib.h>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;
using prglib::lista;
class histograma {
public:
    histograma();
    histograma(const histograma& orig);
    virtual ~histograma();
    void montagem(lista<long> dados, long desvio);
private:

};

#endif /* HISTOGRAMA_H */

