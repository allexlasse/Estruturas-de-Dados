#ifndef TEATRO_H_INCLUDED
#define TEATRO_H_INCLUDED
#define LINHA 99
#define COLUNA 99

struct Teatro{

    int Linhas = (int)LINHA;
    int Colunas = (int) COLUNA;
    bool Assentos[LINHA][COLUNA];
    //bool *P = &Assentos[][];
    unsigned int IngressosVendidos = 0;

    // Construtores

    Teatro(){
    }

    Teatro(int linhas, int colunas){
        Linhas = linhas;
        Colunas = colunas;
        Assentos[Linhas][Colunas];
    }

    // Zerar Matriz

    void ZerarMatriz(int linha,int coluna){
        for(int i = 0; i<linha;i++){
            for(int j = 0; j<coluna;j++){
                Assentos[i][j] = false;
            }
        }
    }

    //Verifica disponibilidade

    bool isDisponivel(int linha, int coluna){
        return !Assentos[linha][coluna];
    }


    // Venda de ingresso;

    void MarcarLugar(int linha, int coluna){
            IngressosVendidos += 1;
            Assentos[linha][coluna] = true;

    }

    // Devolução de ingresso

    void DesmarcarLugar(int linha, int coluna){
            Assentos[linha][coluna] = false;
            IngressosVendidos -= 1;
    }

    // Troca de assento

    void TrocarLugar(int linha, int coluna, int linha2, int coluna2){
        if(isDisponivel(linha,coluna) && (!isDisponivel(linha2,coluna2))){
            DesmarcarLugar(linha,coluna);
            MarcarLugar(linha2,coluna2);
        }
    }

};

#endif // TEATRO_H_INCLUDED
