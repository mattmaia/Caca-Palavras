#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
#include <ctype.h>

///Mateus Maia de Oliveira
///BSI - IFMG
/// Caça Palavras

const int tam=15;

using namespace std;

void ImprimirCacaPalavra(char Grid[15][15]) ///funçao para imprimir a matriz do caça palavra
{

    for(int i=0; i<15; i++)
    {
        cout<<"\n";
        for(int j=0; j<15; j++)
        {
            cout<<Grid[i][j]<<" ";
        }
    }

}

void EntradaPalavra(char Grid[15][15],char Grid2[15][15],char Palavra[tam])
///Grid(matriz principal),grid2(matriz a ser atualizada),Palavra de entrada
{
    int  i,j, t, n,cont=0; ///contadores
    int tam; ///armazena o tamanho da palavra
    int Encontrada; ///  Encontrada(sim =1 ou nao=0)
    cout<<"\n\nDigite quantas letras tem a palavra:  ";
    cin>>tam;
    cout<<"Digite a palavra a ser buscada:  ";
    for(n = 0; n < tam ; n++)
    {
        cin>>Palavra[n]; ///armazena a palavra no vetor
        Palavra[n]=toupper(Palavra[n]); ///transforma as letras minusculas para maiusculas
    }

    Encontrada=0; /// inicia como palavra nao encontrada;

    for(i=0; i<15; i++) ///linha
    {
        for(j=0; j<15; j++) ///coluna
        {
            if(Palavra[0] == Grid[i][j])///Se a primeira letra for encontrada
            {

                if (Palavra[1] == Grid[i - 1][j]) ///Se a segunda letra  for encontrada ACIMA
                {
                    Encontrada = 1; ///Encontrada assume o valor 1;

                    for (t = 0; t < tam; t++) ///verifica cada letra da palavra,
                    {
                        if (Palavra[t] != Grid[i - t][j])  ///verifica se as letras estao no grid
                        {
                            Encontrada = 0; ///palavra nao encontrada
                        }
                    }
                    if(Encontrada) ///se a palavra foi aceita
                    {
                        for (t = 0; t < tam; t++)
                        {
                            Grid2[i - t][j] = Palavra[t]; ///atualiza o grid2 para a vizualizaçao das palavras

                        }
                        cont++; ///contador qua armazena o n° de vezes que a palavra se repete no caça palavras
                    }
                }

                ///a mesma logica da condiçao 'if' acima se repete para os proximos if's, mas agora se a segunda letra for encotrada em outra direção

                if (Palavra[1] == Grid[i + 1][j]) ///Se a segunda letra for encontrada ABAIXO
                {
                    Encontrada = 1;

                    for (t = 0; t < tam; t++)
                    {

                        if (Palavra[t] != Grid[i + t][j])
                        {
                            Encontrada = 0;
                        }
                    }
                    if (Encontrada)
                    {
                        for (t = 0; t < tam; t++)
                        {
                            Grid2[i + t][j] = Palavra[t];
                        }
                        cont++;
                    }
                }


                if (Palavra[1] == Grid[i][j + 1]) ///Se a segunda letra for encontrada a DIREITA
                {
                    Encontrada = 1;

                    for (t = 0; t < tam; t++)
                    {

                        if (Palavra[t] != Grid[i][j + t])
                        {
                            Encontrada = 0;
                        }
                    }
                    if (Encontrada)
                    {
                        for (t = 0; t < tam; t++)
                        {
                            Grid2[i][j + t] = Palavra[t];
                        }
                        cont++;
                    }
                }


                if (Palavra[1] == Grid[i][j - 1]) ///Se a segunda letra for encontrada a ESQUERDA
                {
                    Encontrada = 1;

                    for (t = 0; t < tam; t++)
                    {

                        if (Palavra[t] != Grid[i][j - t])
                        {
                            Encontrada = 0;
                        }
                    }
                    if (Encontrada)
                    {
                        for (t = 0; t < tam; t++)
                        {
                            Grid2[i][j - t] = Palavra[t];
                        }

                        cont++;
                    }
                }


                if (Palavra[1] == Grid[i - 1][j + 1] ) ///Se a segunda letra for encontrada ACIMA-DIREITA
                {
                    Encontrada = 1;

                    for (t = 0; t < tam; t++)
                    {

                        if (Palavra[t] != Grid[i - t][j + t])
                        {
                            Encontrada = 0;
                        }
                    }
                    if (Encontrada)
                    {
                        for (t = 0; t < tam; t++)
                        {
                            Grid2[i - t][j + t] = Palavra[t];
                        }
                        cont++;
                    }
                }


                if (Palavra[1] == Grid[i - 1][j - 1] ) ///Se a segunda letra for encontrada ACIMA-ESQUERDA
                {
                    Encontrada = 1;

                    for (t = 0; t < tam; t++)
                    {

                        if (Palavra[t] != Grid[i - t][j - t])
                        {
                            Encontrada = 0;
                        }
                    }
                    if (Encontrada)
                    {
                        for (t = 0; t < tam; t++)
                        {
                            Grid2[i - t][j - t] = Palavra[t];
                        }
                        cont++;
                    }
                }


                if (Palavra[1] == Grid[i + 1][j + 1]) ///Se a segunda  letra for encontrada ABAIXO-DIREITA
                {
                    Encontrada = 1;

                    for (t = 0; t < tam; t++)
                    {

                        if (Palavra[t] != Grid[i + t][j + t])
                        {
                            Encontrada = 0;
                        }
                    }
                    if (Encontrada)
                    {
                        for (t = 0; t < tam; t++)
                        {
                            Grid2[i + t][j + t] = Palavra[t];
                        }
                        cont++;
                    }
                }


                if (Palavra[1] == Grid[i + 1][j - 1] ) ///Se a segunda letra for encontrada ABAIXO-ESQUERDA
                {
                    Encontrada = 1;

                    for (t = 0; t < tam; t++)
                    {

                        if (Palavra[t] != Grid[i + t][j - t])
                        {
                            Encontrada = 0;
                        }


                    }
                    if (Encontrada)
                    {
                        for (t = 0; t < tam; t++)
                        {
                            Grid2[i + t][j - t] = Palavra[t];
                        }
                        cont++;
                    }
                }

            }

        }

    }

    if(Encontrada=1) /// imprime se a palavra for encontrada e quantas vezes ela se repete
    {
        cout<<"\nPalavra encontrada "<<cont<<" vez(es): ";
        for(n = 0; n < tam; n++)
        {
            cout<<Palavra[n];
        }
    }
    else /// imprime a palavra que nao foi encontrada
    {
        cout<<"\nPalavra nao encontrada: ";
        for(n = 0; n < tam; n++)
        {
            cout<<Palavra[n];
        }
    }
    cout<<"\n";
}

int main()
{
    int i=1;
    char Palavra[tam];
    char Grid[15][15] =  ///Matriz com as letras do caça palavars
    {
        {'Y', 'C', 'Y', 'G', 'W', 'R', 'P', 'K', 'H', 'O', 'A', 'B', 'U', 'V', 'H'},
        {'S', 'C', 'I', 'R', 'F', 'Z', 'B', 'M', 'C', 'P', 'M', 'Y', 'C', 'F', 'P'},
        {'U', 'A', 'F', 'R', 'X', 'T', 'W', 'L', 'O', 'T', 'A', 'S', 'M', 'X', 'C'},
        {'E', 'J', 'R', 'A', 'G', 'S', 'A', 'V', 'H', 'G', 'L', 'R', 'X', 'G', 'F'},
        {'K', 'X', 'Z', 'T', 'A', 'P', 'C', 'V', 'J', 'Q', 'M', 'J', 'Y', 'M', 'G'},
        {'G', 'C', 'X', 'Q', 'E', 'W', 'S', 'I', 'A', 'L', 'A', 'E', 'O', 'I', 'V'},
        {'I', 'F', 'Y', 'F', 'X', 'V', 'A', 'L', 'P', 'A', 'L', 'H', 'E', 'T', 'A'},
        {'L', 'E', 'K', 'O', 'U', 'U', 'T', 'I', 'G', 'U', 'A', 'N', 'C', 'O', 'I'},
        {'V', 'H', 'I', 'H', 'Z', 'U', 'A', 'I', 'F', 'R', 'D', 'B', 'A', 'L', 'U'},
        {'A', 'R', 'Z', 'H', 'X', 'C', 'L', 'C', 'O', 'G', 'E', 'E', 'X', 'V', 'R'},
        {'U', 'N', 'B', 'S', 'T', 'M', 'U', 'S', 'I', 'C', 'A', 'T', 'L', 'A', 'A'},
        {'W', 'R', 'A', 'U', 'J', 'A', 'B', 'I', 'S', 'S', 'N', 'O', 'R', 'I', 'S'},
        {'C', 'M', 'P', 'L', 'E', 'N', 'P', 'A', 'L', 'C', 'O', 'A', 'H', 'B', 'E'},
        {'T', 'M', 'F', 'O', 'T', 'Z', 'M', 'P', 'T', 'R', 'E', 'S', 'J', 'R', 'L'},
        {'F', 'S', 'I', 'K', 'U', 'F', 'P', 'E', 'Q', 'T', 'A', 'M', 'L', 'O', 'J'}
    };
    char Grid2[15][15]= ///Matriz que irá ser atualizadas para mostras as palavras que foram encontradas
    {
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    };

    while(i!=0) /// um While para manter a execuçao até quando o usuário quiser sair
    {
        cout<<"          Mateus Maia\n"<<endl;
        cout<<"         CACA-PALAVRAS"<<endl;

        /// chamando as funçoes:
        ImprimirCacaPalavra(Grid);
        EntradaPalavra(Grid,Grid2,Palavra);
        ImprimirCacaPalavra(Grid2);
        cout<<"\n\nDeseja sair? (SIM=0 ou NAO=1)";
        cin>>i;
        system("cls");
    }
    return 0;
}
