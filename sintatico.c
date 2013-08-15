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

char * tk;
char * temp_tk;
int linha, coluna;
int temp_linha;
int temp_coluna;

char * START(char * entrada){
    
    tk = (char*) calloc(100, sizeof(char));
    char * saida = (char*) calloc(200, sizeof(char));
    
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
                    
                    if(LISTADEC(entrada)){
                        
                        if(BLOCOM(entrada)){
                            return "Analise completada com sucesso.";
                        }
                    }
                }
            }
        }
    }
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

    tk = (char*) calloc(100, sizeof(char));
    
    linha = getLinha(-1);
    coluna = getColuna(-1);
    tk = token(entrada)[0];
    if(!strcmp(tk, "[ID]")){
        
        if(LISTAID(entrada)){
            
            //linha = getLinha(-1);
            //coluna = getColuna(-1);
            //tk = token(entrada)[0];
            if(!strcmp(tk, "[DOISPT]")){
                
                if(TIPO(entrada)){
                    
                    linha = getLinha(-1);
                    coluna = getColuna(-1);
                    tk = token(entrada)[0];
                    if(!strcmp(tk, "[PTVIR]")){
                        
                        if(DEC(entrada)){
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int DEC(char * entrada){
    
    tk = (char*) calloc(100, sizeof(char));
    
    linha = getLinha(-1);
    coluna = getColuna(-1);
    tk = token(entrada)[0];
    if(!strcmp(tk, "[ID]")){
        
        if(LISTAID(entrada)){
            
            linha = getLinha(-1);
            coluna = getColuna(-1);
            tk = token(entrada)[0];
            if(!strcmp(tk, "[DOISPT]")){
                
                if(TIPO(entrada)){
                    
                    linha = getLinha(-1);
                    coluna = getColuna(-1);
                    tk = token(entrada)[0];
                    if(!strcmp(tk, "[PTVIR]")){
                        
                        if(DEC(entrada)){
                            return 1;
                        }
                    }
                }
            }
        }
    }
    if(BLOCOM(entrada)) //SERIA O "VAZIO"
        return 1;
    
    return 0;
}

int LISTAID(char * entrada){
    
    tk = (char*) calloc(100, sizeof(char));
    temp_tk = (char*) calloc(100, sizeof(char));
    
    temp_linha = getLinha(-1);
    temp_coluna = getColuna(-1);
    temp_tk = token(entrada)[0];
    
    linha = temp_linha;
    coluna = temp_coluna;
    tk = temp_tk;
    if(!strcmp(tk, "[VIRG]")){
        
        linha = getLinha(-1);
        coluna = getColuna(-1);
        tk = token(entrada)[0];
        if(!strcmp(tk, "[ID]")){
        
            if(LISTAID(entrada)){
                return 1;
            }
            linha = temp_linha;
            coluna = temp_coluna;
            tk = temp_tk;
            return 1;
        }
    }
    if(!strcmp(tk, "[DOISPT]")){ //SERIA O "VAZIO"
        return 1;
    }
    if(!strcmp(tk, "[FPAR]")){ //SERIA O "VAZIO"
        return 1;
    }
    return 0;
}

int TIPO(char * entrada){
    
    tk = (char*) calloc(100, sizeof(char));
    
    linha = getLinha(-1);
    coluna = getColuna(-1);
    tk = token(entrada)[0];
    if(!strcmp(tk, "[REAL]"))
        return 1;

    if(!strcmp(tk, "[BOOLEAN]"))
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
