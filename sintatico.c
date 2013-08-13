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
    
    char * tk = (char*) calloc(100, sizeof(char));
    char * saida = (char*) calloc(200, sizeof(char));
    int linha, coluna;
    
    linha = 1;
    coluna = 1;
    tk = token(entrada)[0];
    if(!strcmp(tk, "[PROGRAM]")){
        
        linha = getLinha(-1);
        coluna = getColuna(-1);
        tk = token(entrada)[0];
        if(!strcmp(tk, "[ID]")){
            
            linha = getLinha(-1);
            coluna = getColuna(-1);
            tk = token(entrada)[0];
            if(!strcmp(tk, "[PTVIR]")){
                
                linha = getLinha(-1);
                coluna = getColuna(-1);
                tk = token(entrada)[0];
                if(!strcmp(tk, "[VAR]")){
                    
                    if(LISTADEC(tk)){
                        
                        if(BLOCOM(tk)){
                            return "Analise completada com sucesso.";
                        }
                    }
                }
            }
        }
    } //[PROGRAM]
    if(!strcmp(tk, "!ERRO!")){
        sprintf(saida,"Erro lexico na linha %d, coluna %d.", getLinha(-1), getColuna(-1));
        return saida;
    }
    else{
        sprintf(saida,"Erro sintatico na linha %d, coluna %d.", linha, coluna);
        return saida;
    }
}

int LISTADEC(char * entrada){
    return 1;
}

int DEC(char * entrada){
    return 1;
}

int LISTAID(char * entrada){
    if(!strcmp(token(entrada)[0], "[ID]")){
        if(!strcmp(token(entrada)[0], "[VIRG]")){
            if(LISTAID(entrada)){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    return 0;
}

int TIPO(char * entrada){
    if(!strcmp(token(entrada)[0], "[REAL]"))
        return 1;
    if(!strcmp(token(entrada)[0], "[BOOLEAN]"))
        return 1;
    return 0;
}

int BLOCOM(char * entrada){
    return 1;
}

int LISTACOM(char * entrada){
    return 1;
}

int COM(char * entrada){
    return 1;
}

int BLIF(char * entrada){
    return 1;
}

int BLELSE(char * entrada){
    return 1;
}

int LISTAEXP(char * entrada){
    return 1;
}

int EXP(char * entrada){
    return 1;
}

int OP(char * entrada){
    return 1;
}

int OP1(char * entrada){
    return 1;
}

int OP2(char * entrada){
    return 1;
}

int OP3(char * entrada){
    return 1;
}

int UNI(char * entrada){
    return 1;
}
