#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <prglib.h>
#include <string>
#include "analisa.h"
#include "histograma.cpp"
#include <unistd.h>

using namespace std;
using prglib::lista;

//lista para capturar pacotes instante.

int main() {
    lista<long> horario;

    analisa obj;
    horario = obj.retira_lista_horarios();  
    lista<long> intervalos;
    intervalos = obj.diferecadetempo(horario);
    long i;
    i =obj.retorna_limiar(intervalos);
    //horario.escrevaSe(cout, "\n");
    int a=1;
    while(a==1){
        //menu
        int menu;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"--------------------------ANALISADOR------------------------"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"|  OPÇÕES  |              DESCRIÇÃO                        |"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"|     1    |Mostrar horários.                              |"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"|     2    |Apresenta a quantidade de grupos de pacotes    |"<<endl; 
        cout<<"|          |existente em uma amostra de tráfego.           |"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"|     3    |Apresenta a quantidade de pacotes mínima, média|"<<endl;
        cout<<"|          |e máxima existente em cada grupo de pacotes    |"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"|     4    |Apresenta, em ordem decrescente, as quantidades|"<<endl;
        cout<<"|          |de pacotes dos N grupos mais longos.           |"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"|     5    |apresenta, em ordem crescente, as quantidades  |"<<endl;
        cout<<"|          |de pacotes dos N grupos mais curtos            |"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"|     6    |Apresenta, em ordem decrescente, os N maiores  |"<<endl;
        cout<<"|          |intervalos de tempo entre grupos.              |"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"|     7    |Apresenta o valor médio dos intervalos de tempo|"<<endl;
        cout<<"|          |entre pacotes de um mesmo grupo                |"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"|     8    |Apresenta o valor médio dos intervalos de tempo|"<<endl;
        cout<<"|          |entre grupos de pacotes                        |"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"|     9    |Histograma                                     |"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"|     10   |SAIR                                           |"<<endl;
        cin>>menu;
     lista<long> nmenores;
     lista<long> nmaiores;
     lista<long> ninterval;
    
     histograma t;
     int choi;
     int control;
     long mediaIntG;           
        if(menu>=1 && menu <=12){
        
            switch(menu){
            
                case 1:
                    horario.escrevaSe(cout, "\n");
                    break;
                case 2:
                    long grupos;
                    grupos=obj.numeroDGrupos(intervalos,i);
                    cout<<"Nº de grupos:"<<grupos<<endl;
                    sleep(3);
                    break;
                case 3:
                    long media;
                    media=obj.media_pacotes_por_grupo(intervalos, i);
                    cout<<"Média de intervalos:"<<media<<endl;
                    long min;
                    min=obj.minimo_pacotes_por_grupo(intervalos, i);
                    cout<<"Minimo de intervalos:"<<min<<endl;
                    long max;
                    max=obj.maximo_pacotes_por_grupo(intervalos,i);
                    cout<<"Maximo de intervalo:"<<max<<endl;
                    sleep(4);
                    break;
                case 4:
                    control=0;
                    while(control==0){
                        cout<<"DIGITE A QUANTIDADE DE PACOTES:"<<endl;
                        cin >> choi;
                        if((choi>=1) && (choi <=1000)){
                            control=1;
                        }
                        else{
                            continue;
                        }
                    }
                    nmaiores=obj.osNmaiorespacotes(intervalos, choi);
                    nmaiores.escrevaSe(cout, "\n");
                    sleep(4);
                    break;
                case 5:
                    control=0;
                    while(control==0){
                        cout<<"DIGITE A QUANTIDADE DE PACOTES:"<<endl;
                        
                            cin >> choi;
                        if((choi>=1) && (choi <=1000)){
                            control=1;
                        }
                        else{
                            continue;
                        }
                    }
                    nmenores=obj.osNmenoresspacotes(intervalos, choi);
                    nmenores.escrevaSe(cout, "\n");
                    sleep(4);
                    break;
                case 6 :
                    control=0;
                    while(control==0){
                        cout<<"DIGITE A QUANTIDADE DE INTERVALOS:"<<endl;
                        
                            cin >> choi;
                        if((choi>=1) && (choi <=1000)){
                            control=1;
                        }
                        else{
                            continue;
                        }
                    }
                    ninterval= obj.N_intervalo_grupos(intervalos, i,choi);
                    ninterval.escrevaSe(cout, "\n");
                    sleep(4);
                    break;
                case 7:
                    mediaIntG = obj.mediaInterPacGrupo(intervalos, i);
                    cout<<"MÉDIA ENTRE GRUPOS É:"<<mediaIntG<<endl;
                    sleep(3);
                    break;
                case 8:
                    mediaIntG = obj.mediaInterGrupoPac(intervalos, i);
                    cout<<"MÉDIA ENTRE GRUPOS É:"<<mediaIntG<<endl;
                    sleep(4);
                    break;
                case 9:
                    t.montagem(obj.freq(intervalos), obj.desvio);
                    sleep(4);
                    break;
                case 10:
                    a=10;
                    break;
                default:
                    break;
            }
        }
        else{
            continue;
        }
    }
} 