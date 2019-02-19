#include <iostream>
#include "Teatro.h"

using namespace std;

int main()
{
    Teatro Theater;
    bool exit = true;
    int line, column, line_1, column_1;

    cout<<"Theater Size"<<endl;
    cout<<"Lines: ";
    cin>>line;
    cout<<"Columns: ";
    cin>>column;
    cout<<"\n";


    Theater = Teatro(line,column);
    Theater.ZerarMatriz(Theater.Linhas,Theater.Colunas);

    while(exit)
    {
        cout<<"\n\n";

        cout<<"  ";
        for(int k = 0 ; k < Theater.Colunas; k++){
                if(k < 9)
                    cout<<"  "<<(k + 1)<<"  ";
                else
                    cout<<"  "<<(k + 1)<<" ";
            }

            cout<<"\n";

        for(int i = 0; i<Theater.Linhas; i++)
            {
                if(i<9){
                    cout<<(i + 1)<<" ";
                }
                else{
                    cout<<(i + 1);
                }
                for(int j = 0; j<Theater.Colunas ; j++)
                {
                    if(Theater.Assentos[i][j] == true){
                        cout<<" [X] ";
                    }
                    else
                        cout<<" [ ] ";
                }
                cout<<"\n";
            }

            cout<<"\nTickets sold: ";
            cout<<Theater.IngressosVendidos;
            cout<<"\n\n";

        cout<<"MENU\nSelect an option\n1 - Buy assent\n2 - Devolution\n3 - Exchange\n5 - EXIT"<<endl;
        int option;
        cin>>option;
        switch(option)
        {
            // OPTION 1 - BUY ASSENT
        case 1:
            cout<<"Enter the line and column: "<<endl;
            cout<<"Line: ";
            cin>>line;
            line -= 1;
            cout<<"Column: ";
            cin>>column;
            column -= 1;
            if(!Theater.isDisponivel(line,column)){
                cout<<"Assent unavailable. ";
            }
            else{
                Theater.MarcarLugar(line,column);
                cout<<"Assent available. Operation completed.";
            }
            break;
            // OPTION 2 - DEVOLUTION
        case 2:
            cout<<"Enter the line and column: "<<endl;
            cout<<"Line: ";
            cin>>line;
            line -= 1;
            cout<<"Column: ";
            cin>>column;
            column -= 1;
            if(Theater.isDisponivel(line ,column)){
                cout<<"Assent is empty. Returning to MENU.";
            }
            else{
                Theater.DesmarcarLugar(line,column);
                cout<<"Devolution completed.";
            }
            break;
            // OPTION 3 - EXCHANGE
        case 3:
            cout<<"Enter the line and column you bought: "<<endl;
            cout<<"Line: ";
            cin>>line;
            line -= 1;
            cout<<"Column: ";
            cin>>column;
            column -= 1;
            cout<<"Enter the line and column you want to exchange to: "<<endl;
            cout<<"Line: ";
            cin>>line_1;
            line_1 -= 1;
            cout<<"Column: ";
            cin>>column_1;
            column_1 -= 1;
            if(!Theater.isDisponivel(line,column) && (Theater.isDisponivel(line_1,column_1))){
                Theater.DesmarcarLugar(line,column);
                Theater.MarcarLugar(line_1,column_1);
                cout<<"Exchange successful. Returning to MENU.";
            }
            else{
                cout<<"Exchange not possible.";
            }
            break;
            // OPTION 5 - EXIT
        case 5:
            exit = false;
            cout<<"EXIT!"<<endl;
            break;
            // DEFAULT
        default:
            cout<<"Invalid option"<<endl;
            break;
        }
    }

    return 0;
}
