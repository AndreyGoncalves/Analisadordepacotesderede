/* 
 * File:   analisa.h
 * Author: andrey
 *
 * Created on 24 de Setembro de 2016, 18:52
 */

#ifndef ANALISA_H
#define	ANALISA_H
#include "prglib.h"
#include <string>

using prglib::lista;
using namespace std;

class analisa {
public:
    long desvio;
    analisa();
    analisa(const analisa& orig);
    long mediaM(lista<long>);
    long mediaInterPacGrupos(lista<long> L2, long limiar);
    lista<long>retira_lista_horarios();
    lista<long> diferecadetempo(lista<long> L1);
    long media_pacotes_por_grupo(lista<long> L2, long limiar);
    long minimo_pacotes_por_grupo(lista<long> L2,long limiar);
    long maximo_pacotes_por_grupo(lista<long> L2,long limiar);
    lista<long> osNmaiorespacotes (lista<long> L2, int N);
    lista<long> osNmenoresspacotes (lista<long> L2, int N);
    lista <long> N_intervalo_grupos(lista<long> L2, long limiar,int N);
    long mediaInterGrupoPac(lista<long> L2, long limiar);
    long mediaInterPacGrupo(lista<long> L2, long limiar);
    long retorna_limiar(lista<long>  L2);
    int numeroDGrupos(lista<long> L2,long limiar);
    lista<long> freq (lista<long> L2);
    virtual ~analisa();
private:

};

#endif	/* ANALISA_H */

