/* 
 * File:   sintatico.c
 * Authors: Rodrigo Acosta, Rodrigo Oliveira
 *
 * Created on 14 de Julho de 2013
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexico.h"

char * START(char * entrada){

    char
        * fim;
    
    fim    = (char*) calloc(   1, sizeof(char));
    
    *fim = 'f';
    
    if(!strcmp(token(entrada)[0], "[PROGRAM]")){
        if(!strcmp(token(entrada)[0], "[ID]")){
            if(!strcmp(token(entrada)[0], "[PTVIR]")){
                if(!strcmp(token(entrada)[0], "[VAR]")){
                    if(LISTADEC(entrada)){
                        if(BLOCOM(entrada)){
                            return "OK.";
                        }
                    }
                }
            }
        }
    }
    return "not ok";
}

int LISTADEC(char * entrada){
    return 1;
}

int BLOCOM(char * entrada){
    return 1;
}

int DEC(char * entrada){
    return 1;
}

int LISTAID(char * entrada){
    return 1;
}

int TIPO(char * entrada){
    return 1;
}

int LISTACOM(char * entrada){
    return 1;
}

int COM(char * entrada){
    return 1;
}

int LISTAEXP(char * entrada){
    return 1;
}

int EXP(char * entrada){
    return 1;
}

int IF(char * entrada){
    return 1;
}

int ELSE(char * entrada){
    return 1;
}

int E1(char * entrada){
    return 1;
}

int E2(char * entrada){
    return 1;
}

int E3(char * entrada){
    return 1;
}

int E4(char * entrada){
    return 1;
}

int UNIT(char * entrada){
    return 1;
}
