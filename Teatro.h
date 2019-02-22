#ifndef TEATRO_H_INCLUDED
#define TEATRO_H_INCLUDED

struct Teatro{

    unsigned int Linhas;
    unsigned int Colunas;
    bool *Assentos;
    unsigned int IngressosVendidos;

    // Construtores

    Teatro(){
    }

    Teatro(int linhas, int colunas){
        Linhas = linhas;
        Colunas = colunas;
        Assentos = new bool[Linhas*Colunas];
        IngressosVendidos = 0;
        //zerar matriz
        for(int i = 0; i<Linhas;i++){
            for(int j = 0; j<Colunas;j++){
                Assentos[i*Colunas+j] = false;
            }
        }
    }

    //Verifica disponibilidade

    bool isDisponivel(int linha, int coluna){
        if(Assentos[linha*Colunas+coluna] == false && linha < Linhas && coluna < Colunas)
            return true;
    }


    // Venda de ingresso;

    void MarcarLugar(int linha, int coluna){
            Assentos[linha*Colunas+coluna] = true;
            IngressosVendidos += 1;

    }

    // Devolução de ingresso

    void DesmarcarLugar(int linha, int coluna){
            Assentos[linha*Colunas+coluna] = false;
            IngressosVendidos -= 1;
    }

};

#endif // TEATRO_H_INCLUDED
