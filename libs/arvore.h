/* 
 * File:   arvore.h
 * Author: msobral
 *
 * Created on 12 de Agosto de 2016, 13:12
 */

#ifndef ARVORE_H
#define	ARVORE_H

#include <libs/lista.h>

namespace prglib {
    
template <typename T> class Arvore {
 public:
     // um iterador in-order
    class Iterador {
     private:
        lista<Arvore<T>*> pilha;
        Arvore<T> * raiz;
     public:
        Iterador(Arvore<T> * root);
        ~Iterador() {}
        void inicia();
        T & proximo();
        bool fim();
    private:
        void desce(Arvore<T> * ptr);
    };
    
    friend class Iterador;
 public:
  Arvore();
  Arvore(const Arvore<T> & outra);
  Arvore(const T & dado);
  ~Arvore();

  void adiciona(const T& algo);
  T& obtem(const T & algo);
  void listeInOrder(Lista<T> & lista);
  void listePreOrder(Lista<T> & lista);
  void listePostOrder(Lista<T> & lista);
  unsigned int tamanho() const;  
  unsigned int altura();
  int fatorB();
  Arvore<T> * rotacionaL();
  Arvore<T> * rotacionaR();
  Arvore<T> * balanceia();
  Arvore<T> * balanceia(bool otimo);
  
  Iterador iniciaIteracao();
  
  T remove(const T & algo);
  T & obtemMenor() const;
  T & obtemMaior() const;
  
  void obtemMenoresQue(Lista<T> & lista, const T & algo);
  void obtemMaioresQue(Lista<T> & lista, const T & algo);
 private:
  Arvore<T> * esq, * dir, * atual;
  T dado;
  int h;
  
  Arvore<T> * obtem_nodo(const T & algo, Arvore<T>* &pai);
};

} // fim do namespace
#endif	/* ARVORE_H */

