#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "rlutil.h"
#include "interfaz.h"
#include "game.h"
#include "cerditos.h"


int main()
{
    bool gameOver = false;
    int yCursor = 0; // posicion del cursor
    rlutil::hidecursor(); // ocultar cursor consola

    do{
        fondoRosado();
        fStartGranCerdo();
        fMenuGranCerdo();
        posicionarXY(45, 20 + yCursor);
        std::cout << (char)62 << std::endl;

        int key = rlutil::getkey(); // obtener tecla de ingreso

        switch(key){
            case 14: // Flecha arriba
                posicionarXY(45, 20 + yCursor);
                std::cout << " " << std::endl;
                yCursor--;
                if(yCursor<0){ // Limite superior
                    yCursor = 0;
                }
            break;
            case 15: // Flecha Abajo
                posicionarXY(45, 20 + yCursor);
                std::cout << " " << std::endl;
                yCursor++;
                if(yCursor>3){ // Limite inferior
                    yCursor = 3;
                }
            break;
            case 1: // Enter
                switch(yCursor){
                    case 0:
                        fGame();
                        limpiarConsola();
                    break;
                    case 1:
                        fEstadisticas();
                    break;
                    case 2:
                        fCerditos();
                    break;
                    case 3:
                        gameOver = true;
                    break;

                }
            break;
        }
    } while(!gameOver);

    return 0;
}

