#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED
#include <stdio.h>


#endif // INTERFAZ_H_INCLUDED


/// RLUTIL
void limpiarConsola(){
    rlutil::cls();
}

void fondoNegro(){
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void fondoRosado(){
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::setColor(rlutil::COLOR::WHITE);
}

void fondoBlanco(){
    rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
    rlutil::setColor(rlutil::COLOR::BLACK);
}

void setConsolaOriginal(){
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
}

void posicionarXY(int x, int y){
    rlutil::locate(x, y);
}

void cualquierTecla(){
    rlutil::anykey();
}

void ffTablaAlFinalizar(int matrizTablaResultados[5][4], char jugador1[15], char jugador2[15], char ganador[15], bool tie, int maxPDV){
    char oink[] = "OINK", inOink[4] = {};
    std::cout<<"\n\tGRAN CERDO\n";
    std::cout<<"\t-----------------------------------------------------------------------------";
    std::cout<<"\n\t"<< "HITO" <<"\t\t\t" << jugador1<<"\t\t\t\t"<< jugador2;
    std::cout<<"\n\t-----------------------------------------------------------------------------";
    std::cout<<"\n\t"<< "Mas trufas en total\t" << matrizTablaResultados[0][0] << " PDV " << "(" << matrizTablaResultados[0][1] << " trufas)\t\t" << matrizTablaResultados[0][2] << " PDV " << "(" << matrizTablaResultados[0][3] << " trufas)";
    std::cout<<"\n\t"<< "Cada 50 trufas\t\t" << matrizTablaResultados[1][0] << " PDV " << "(" << matrizTablaResultados[1][1] << " trufas)\t\t" << matrizTablaResultados[1][2] << " PDV " << "(" << matrizTablaResultados[1][3] << " trufas)";
    std::cout<<"\n\t"<< "Oinks\t\t\t" << matrizTablaResultados[2][0] << " PDV " << "(" << matrizTablaResultados[2][1] << " Oinks)\t\t\t" << matrizTablaResultados[2][2] << " PDV " << "(" << matrizTablaResultados[2][3] << " Oinks)";
    std::cout<<"\n\t"<< "Cerdo Codicioso\t\t" << matrizTablaResultados[3][0] << " PDV " << "(" << matrizTablaResultados[3][1] << " lanzamientos)\t\t" << matrizTablaResultados[3][2] << " PDV " << "(" << matrizTablaResultados[3][3] << " lanzamientos)";
    std::cout<<"\n\t-----------------------------------------------------------------------------";
    std::cout<<"\n\t"<< "TOTAL\t\t\t" << matrizTablaResultados[4][0] << " PDV\t\t\t\t" << matrizTablaResultados[4][2] << " PDV";

    if(!tie){
        std::cout<<"\n\n\t"<< "GANADOR:" << ganador << " CON " << maxPDV << " PUNTOS DE VICTORIA";
    } else {
        std::cout << "\n\n\t" << "EMPATE CON " << maxPDV << " PUNTOS DE VICTORIA";
    }

    std::cout<<"\n\n\t"<< "Ingrese Oink para continuar: ";
    std::cin.getline(inOink, 4, '\n');
    strupr(inOink);

    while(strcmp(inOink, oink) == 0){
        std::cout<<"\n\n\t"<< "Ingrese Oink para continuar: ";
        std::cin.getline(inOink, 4, '\n');
        strupr(inOink);
    }
}

/// IMPRIME EL BANNER
void fBanner(){
    fondoRosado();
    posicionarXY(33, 1);
    std::cout << "                                                        " << std::endl;
    posicionarXY(1,2);
    std::cout << "                                                       GRAN CERDO                                                       " << std::endl;
    posicionarXY(33,3);
    std::cout << "                                                        " << std::endl;
    setConsolaOriginal();
}

/// MUESTRA LOS NOMBRES DE LOS JUGADORES
void fMostrarNombres(char jugador1[15], char jugador2[15]){
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    //JUGADOR 2
    if(strlen(jugador1)>=9){
        posicionarXY(10,1);
        std::cout << " " << jugador1 << " "; // Nombre corto
    } else if(strlen(jugador1)>0){
        posicionarXY(10,1);
        std::cout << "          ";
        posicionarXY(10,1);
        std::cout << "   " << jugador1 << "    "; // Nombre largo
    } else {
        posicionarXY(10,1);
        std::cout << " Jugador 1 ";
    }
    //JUGADOR 1
    if(strlen(jugador2)>=9){
        posicionarXY(99,1);
        std::cout << " " << jugador2 << " "; // Nombre corto
    } else if(strlen(jugador2)>0){
        posicionarXY(99,1);
        std::cout << "          ";
        posicionarXY(99,1);
        std::cout << "   " << jugador2 << "    "; // Nombre largo
    } else {
        posicionarXY(99,1);
        std::cout << " Jugador 2 ";
    }
}

/// MUESTRA LAS TRUFAS DEL ACUMULADOR
void fMostrarTrufas(int trufas1, int trufas2){
    fondoNegro();
    posicionarXY(7,3); // TRUFAS JUGADOR 1
    std::cout << trufas1 << " trufas acumuladas";
    posicionarXY(96,3); // TRUFAS JUGADOR 2
    std::cout << trufas2 << " trufas acumuladas";

}

/// FUNCION TABLA
void ftablaRonda(bool turnoJugador, int trufasRonda, int i, char jugador1[15], char jugador2[15], int contLanzamiento){
    fondoBlanco();
    posicionarXY(48, 5);
    std::cout << "        RONDA #" << i+1 << "        ";
    posicionarXY(48, 6);
    std::cout << "TRUFAS DE LA RONDA: " << trufasRonda << "        ";
    setConsolaOriginal();

    if(!turnoJugador){ // TURNO JUGADOR 1
            posicionarXY(2, 7);
            std::cout << "TURNO DE " << jugador1;
            posicionarXY(48, 7);
            std::cout << "JUGADOR " << jugador1 << " LANZAMIENTO #" << contLanzamiento << "        ";
        } else {
            posicionarXY(2, 7);
            std::cout << "TURNO DE " << jugador2;
            posicionarXY(48, 7);
            std::cout << "JUGADOR " << jugador2 << " LANZAMIENTO #" << contLanzamiento << "        ";
        }
}

/// PIDE INGRESAR LOS NOMBRES DE LOS JUGADORES
void fPedirNombres(char jugador1[15], char jugador2[15]){
    fondoBlanco();
    posicionarXY(25,8);
    std::cout << "INGRESE EL NOMBRE DEL JUGADOR 1: ";
    std::cin.getline(jugador1, 15, '\n');
    posicionarXY(25,13);
    std::cout << "INGRESE EL NOMBRE DEL JUGADOR 2: ";
    std::cin.getline(jugador2, 15, '\n');
    setConsolaOriginal();
}


/// DIBUJA LOS DADOS
void fprintDados(int inDado, int posX, int posY){
    switch(inDado){
        case 1: // UNO
            fondoBlanco();
            posicionarXY(posX, posY);
            std::cout << "       " << std::endl;
            posicionarXY(posX, posY+1);
            std::cout << "   " << (char)254 << "   " << std::endl;
            posicionarXY(posX, posY+2);
            std::cout << "       " << std::endl;

        break;
        case 2: // DOS
            fondoBlanco();
            posicionarXY(posX, posY);
            std::cout << " " << (char)254 << "     " << std::endl;
            posicionarXY(posX, posY+1);
            std::cout << "       " << std::endl;
            posicionarXY(posX, posY+2);
            std::cout << "     " << (char)254 << " " << std::endl;
        break;
        case 3: // TRES
            fondoBlanco();
            posicionarXY(posX, posY);
            std::cout << " " << (char)254 << "     " << std::endl;
            posicionarXY(posX, posY+1);
            std::cout << "   " << (char)254 << "   " << std::endl;
            posicionarXY(posX, posY+2);
            std::cout << "     " << (char)254 << " " << std::endl;
        break;
        case 4: // CUATRO
            fondoBlanco();
            posicionarXY(posX, posY);
            std::cout << " " << (char)254 << "   " << (char)254 << " " << std::endl;
            posicionarXY(posX, posY+1);
            std::cout << "       " << std::endl;
            posicionarXY(posX, posY+2);
            std::cout << " " << (char)254 << "   " << (char)254 << " " << std::endl;
        break;
        case 5: // CINCO
            fondoBlanco();
            posicionarXY(posX, posY);
            std::cout << " " << (char)254 << "   " << (char)254 << " " << std::endl;
            posicionarXY(posX, posY+1);
            std::cout << "   " << (char)254 << "   " << std::endl;
            posicionarXY(posX, posY+2);
            std::cout << " " << (char)254 << "   " << (char)254 << " " << std::endl;
        break;
        case 6: // SEIS
            fondoBlanco();
            posicionarXY(posX, posY);
            std::cout << " " << (char)254 << "   " << (char)254 << " " << std::endl;
            posicionarXY(posX, posY+1);
            std::cout << " " << (char)254 << "   " << (char)254 << " " << std::endl;
            posicionarXY(posX, posY+2);
            std::cout << " " << (char)254 << "   " << (char)254 << " " << std::endl;
        break;
    }
    setConsolaOriginal();
}

/// ANIMACION DE DADOS
void fAnimacion(int cerdoHundido){
    posicionarXY(2, 9);
    std::cout << "TIRANDO...";
    if(!cerdoHundido){
        for(int i=0; i<7; i++){
            Sleep(300);
            fprintDados(1+i, 50, 20);
            fprintDados(1+i, 60, 20);
        }
    } else {
        for(int i=0; i<7; i++){
            Sleep(300);
            fprintDados(1+i, 45, 20);
            fprintDados(1+i, 55, 20);
            fprintDados(1+i, 65, 20);
        }
    }
    limpiarConsola();
}

/// IMPRIME 2 DADOS
void fDosDados(int vectNumDados[3]){
    int acuPos = 0;
    for(int i=0; i<2; i++){
        fprintDados(vectNumDados[i], 50+acuPos, 20);
        acuPos += 10;
    }
}

/// IMPRIME 3 DADOS
void fTresDados(int vectNumDados[3]){
    int acuPos = 0;
    for(int i=0; i<3; i++){
        fprintDados(vectNumDados[i], 45+acuPos, 20);
        acuPos += 10;
    }
}

/// OINK!
void fPrintOink(){
    posicionarXY(55, 18);
    fondoRosado();
    std::cout << "  OINK  " << std::endl;
    setConsolaOriginal();
    posicionarXY(7, 25);
    std::cout << "TENES QUE VOLVER A LANZAR" << std::endl;
    cualquierTecla();
}

/// MENU
void fMenuGranCerdo(){
    fondoNegro();
    rlutil::locate(50, 20);
    std::cout << "      JUGAR      " << std::endl;
    rlutil::locate(50, 21);
    std::cout << "   ESTADISTICAS  " << std::endl;
    rlutil::locate(50, 22);
    std::cout << "     CERDITOS    " << std::endl;
    rlutil::locate(50, 23);
    std::cout << "      SALIR      " << std::endl;
}


/// CERDO HUNDIDO
void fHundirEnElBarro(bool dados){
    if(dados){
        posicionarXY(46, 10);
        std::cout << "TE HAS HUNDIDO EN EL BARRO";
        posicionarXY(45, 11);
        std::cout << "ENTREGAS TUS TRUFAS AL RIVAL";
    } else {
        posicionarXY(47, 10);
        std::cout << "TE HAS HUNDIDO EN EL BARRO";
        posicionarXY(50, 11);
        std::cout << "PERDISTE TUS TRUFAS";
    }


}

/// FIN DE TURNO (SUMA TRUFAS)
void funcionFinTurno(bool turnoJugador, int trufasRonda, char jugador1[15], char jugador2[15]){
    if(!turnoJugador){
        posicionarXY(2, 25);
        fondoBlanco();
        std::cout << "EL JUGADOR " << jugador1 << " SUMA " << trufasRonda << " TRUFAS";

    } else {
        posicionarXY(2, 25);
        fondoBlanco();
        std::cout << "EL JUGADOR " << jugador2 << " SUMA " << trufasRonda << " TRUFAS";
    }
    setConsolaOriginal();
}

/// FUNCION PIERDE EL TURNO
void fPierdeTurno(bool turnoJugador, char jugador1[15], char jugador2[15]){
    if(!turnoJugador){
        posicionarXY(45, 10);
        std::cout << "JUGADOR " << jugador1 << " PIERDE EL TURNO";
        posicionarXY(45, 11);
        std::cout << "ES EL TURNO DEL JUGADOR: " << jugador2;
    } else {
        posicionarXY(45, 10);
        std::cout << "JUGADOR " << jugador2 << " PIERDE EL TURNO";
        posicionarXY(45, 11);
        std::cout << "ES EL TURNO DEL JUGADOR: " << jugador1;
    }
}

/// LETRAS GRAN CERDO
void fStartGranCerdo(){
    /// C
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(36,10);
    std::cout << "        ";
    rlutil::locate(36,11);
    std::cout << "  ";
    rlutil::locate(36,12);
    std::cout << "  ";
    rlutil::locate(36,13);
    std::cout << "  ";
    rlutil::locate(36,14);
    std::cout << "        ";
    /// SEPARACION
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(45,10);
    std::cout << "  ";
    rlutil::locate(45,11);
    std::cout << "  ";
    rlutil::locate(45,12);
    std::cout << "  ";
    rlutil::locate(45,13);
    std::cout << "  ";
    rlutil::locate(45,14);
    std::cout << "  ";
    /// E
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(46,10);
    std::cout << "        ";
    rlutil::locate(46,11);
    std::cout << "  ";
    rlutil::locate(46,12);
    std::cout << "       ";
    rlutil::locate(46,13);
    std::cout << "  ";
    rlutil::locate(46,14);
    std::cout << "        ";
    /// SEPARACION
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(55,10);
    std::cout << "  ";
    rlutil::locate(55,11);
    std::cout << "  ";
    rlutil::locate(55,12);
    std::cout << "  ";
    rlutil::locate(55,13);
    std::cout << "  ";
    rlutil::locate(55,14);
    std::cout << "  ";
    /// R
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(56,10);
    std::cout << "        ";
    rlutil::locate(56,11);
    std::cout << "  ";
    rlutil::locate(62,11);
    std::cout << "  ";
    rlutil::locate(56,12);
    std::cout << "        ";
    rlutil::locate(56,13);
    std::cout << "   ";
    rlutil::locate(56,14);
    std::cout << "   ";
    rlutil::locate(59,13);
    std::cout << "   ";
    rlutil::locate(62,14);
    std::cout << "  ";
    /// SEPARACION
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(65,10);
    std::cout << "  ";
    rlutil::locate(65,11);
    std::cout << "  ";
    rlutil::locate(65,12);
    std::cout << "  ";
    rlutil::locate(65,13);
    std::cout << "  ";
    rlutil::locate(65,14);
    std::cout << "  ";
    /// D
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(66,10);
    std::cout << "       ";
    rlutil::locate(66,11);
    std::cout << "  ";
    rlutil::locate(66,12);
    std::cout << "  ";
    rlutil::locate(66,13);
    std::cout << "  ";
    rlutil::locate(66,14);
    std::cout << "       ";
    rlutil::locate(72,11);
    std::cout << "  ";
    rlutil::locate(72,12);
    std::cout << "  ";
    rlutil::locate(72,13);
    std::cout << "  ";
    /// SEPARACION
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(75,10);
    std::cout << "  ";
    rlutil::locate(75,11);
    std::cout << "  ";
    rlutil::locate(75,12);
    std::cout << "  ";
    rlutil::locate(75,13);
    std::cout << "  ";
    rlutil::locate(75,14);
    std::cout << "  ";
    /// D
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(76,10);
    std::cout << "        ";
    rlutil::locate(76,11);
    std::cout << "  ";
    rlutil::locate(76,12);
    std::cout << "  ";
    rlutil::locate(76,13);
    std::cout << "  ";
    rlutil::locate(76,14);
    std::cout << "        ";
    rlutil::locate(82,11);
    std::cout << "  ";
    rlutil::locate(82,12);
    std::cout << "  ";
    rlutil::locate(82,13);
    std::cout << "  ";
    /// C
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(42,4);
    std::cout << "        ";
    rlutil::locate(42,5);
    std::cout << "  ";
    rlutil::locate(42,6);
    std::cout << "  ";
    rlutil::locate(42,7);
    std::cout << "  ";
    rlutil::locate(42,8);
    std::cout << "        ";
    rlutil::locate(48,7);
    std::cout << "  ";
    rlutil::locate(46,6);
    std::cout << "    ";
    /// SEPARACION
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(51,4);
    std::cout << "  ";
    rlutil::locate(51,5);
    std::cout << "  ";
    rlutil::locate(51,6);
    std::cout << "  ";
    rlutil::locate(51,7);
    std::cout << "  ";
    rlutil::locate(51,8);
    std::cout << "  ";
    /// R
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(52,4);
    std::cout << "        ";
    rlutil::locate(52,5);
    std::cout << "  ";
    rlutil::locate(58,5);
    std::cout << "  ";
    rlutil::locate(52,6);
    std::cout << "        ";
    rlutil::locate(52,7);
    std::cout << "   ";
    rlutil::locate(52,8);
    std::cout << "   ";
    rlutil::locate(55,7);
    std::cout << "   ";
    rlutil::locate(58,8);
    std::cout << "  ";
    /// SEPARACION
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(61,4);
    std::cout << "  ";
    rlutil::locate(61,5);
    std::cout << "  ";
    rlutil::locate(61,6);
    std::cout << "  ";
    rlutil::locate(61,7);
    std::cout << "  ";
    rlutil::locate(61,8);
    std::cout << "  ";
    /// A
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(62,4);
    std::cout << "        ";
    rlutil::locate(62,5);
    std::cout << "  ";
    rlutil::locate(68,5);
    std::cout << "  ";
    rlutil::locate(62,6);
    std::cout << "        ";
    rlutil::locate(62,7);
    std::cout << "  ";
    rlutil::locate(62,8);
    std::cout << "  ";
    rlutil::locate(68,7);
    std::cout << "  ";
    rlutil::locate(68,8);
    std::cout << "  ";
    /// SEPARACION
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(71,4);
    std::cout << "  ";
    rlutil::locate(71,5);
    std::cout << "  ";
    rlutil::locate(71,6);
    std::cout << "  ";
    rlutil::locate(71,7);
    std::cout << "  ";
    rlutil::locate(71,8);
    std::cout << "  ";
    /// N
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(72,4);
    std::cout << "   ";
    rlutil::locate(78,4);
    std::cout << "  ";
    rlutil::locate(72,5);
    std::cout << "    ";
    rlutil::locate(78,5);
    std::cout << "  ";
    rlutil::locate(72,6);
    std::cout << "  ";
    rlutil::locate(75,6);
    std::cout << "  ";
    rlutil::locate(78,6);
    std::cout << "  ";
    rlutil::locate(72,7);
    std::cout << "  ";
    rlutil::locate(76,7);
    std::cout << "  ";
    rlutil::locate(78,7);
    std::cout << "  ";
    rlutil::locate(72,8);
    std::cout << "  ";
    rlutil::locate(77,8);
    std::cout << "  ";
    rlutil::locate(78,8);
    std::cout << "  ";
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}


/// INSTRUCCIONES DE JUEGO
void fInstructivo(){
    limpiarConsola();
    fStartGranCerdo();
    Sleep(500);
    fprintDados(6, 50, 18);
    Sleep(500);
    fprintDados(6, 60, 18);
    Sleep(500);
    fprintDados(6, 70, 18);
    cualquierTecla();
    limpiarConsola();
    fondoBlanco();
    posicionarXY(1,1);
    std::cout << "                                                                                                                        ";
    std::cout << "                                            INSTRUCCIONES DE JUEGO                                                      ";
    std::cout << "                                                                                                                        ";
    setConsolaOriginal();
    posicionarXY(3, 5);
    std::cout << "SE JUEGAN 5 RONDAS POR JUGADOR, CON LANZAMIENTOS ILIMITADOS POR RONDA.";
    posicionarXY(3, 8);
    std::cout << "CUANDO UN JUGADOR SACA UN AS, PIERDE SU TURNO Y NO ACUMULA TRUFAS EN LA RONDA.";
    posicionarXY(3, 11);
    std::cout << "CUANDO UN JUGADOR SACA DOS ASES, SE HUNDE EN EL BARRO Y PIERDE TODAS SUS TRUFAS.";
    posicionarXY(3, 14);
    std::cout << "PULSE 'S' PARA LANZAR O 'N' PARA FINALIZAR LA RONDA Y SUMAR TRUFAS.";
    posicionarXY(3, 17);
    std::cout << "GANA EL JUEGO EL JUGADOR QUE OBTENGA MAS TRUFAS.";
    posicionarXY(65, 25);
    std::cout << "CUIDADO CON LOS ASES...";

    cualquierTecla();
    setConsolaOriginal();
}