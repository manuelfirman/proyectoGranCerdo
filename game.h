#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED



#endif // GAME_H_INCLUDED

int matrizTablaResultados[5][4] = {};
bool ffCorteTurno(int vectNumDados[3], bool &corteAs, bool cerdoHundido);
bool fCerdoHundido(int vectNumDados[3]);
char ffSoN(bool &relanzamiento);
int ffNumeroRandom(int vectNumDados[3]);
int contOink1 = 0, contOink2 = 0;
void ffCalculoDosDados(int &trufasRonda, int vectNumDados[3], bool &relanzamiento);
void ffCalculoTresDados(int &trufasRonda, int vectNumDados[3]);
void ffContMaxLanz(int contLanzamiento, int &maxLanzamientos);
void ffCambioTurno(bool &turnoJugador);
void ffContadorOinks(bool turnoJugador, bool relanzamiento, int &contOink1, int &contOink2);
void ffHundirDosAses(int vectNumDados[3], bool &hundirDosAses, bool &cerdoHundido);
void ffHundirTresAses(int vectNumDados[3], bool &hundirTresAses);
void funcionFinTurno(bool turnoJugador, int trufasRonda, char jugador1[15], char jugador2[15]);
void funcionLanzamiento(int contLanzamiento, int vectNumDados[3], int trufasRonda, bool cerdoHundido, int acuTrufas1, int acuTrufas2);
void ffTablaFilaUno(int matrizTablaResultados[5][4], int acuTrufas1, int acuTrufas2, int &masTrufas, char jugador1[15], char jugador2[15], char ganador[15]);
void ffTablaFilaDos(int matrizTablaResultados[5][4], int acuTrufas1, int acuTrufas2);
void ffTablaFilaTres(int matrizTablaResultados[5][4], int contOink1, int contOink2);
void ffTablaFilaCuatro(int matrizTablaResultados[5][4], int maxLanzamientos1, int maxLanzamientos2);
//void fDelay(int segundos);
void ffSinkTwo(bool turnoJugador, bool hundirDosAses, int &acuTrufas1, int &acuTrufas2);
void ffHundir(bool turnoJugador, bool hundirDosAses, bool hundirTresAses, int &acuTrufas1, int &acuTrufas2, char jugador1[15], char jugador2[15]);

void fGame(){
    char lanzar;
    char jugador1[15] = {}, jugador2[15] = {}, ganador[15] = {}; // VECTOR NOMBRES
    int masTrufas = 0;
    int i, contLanzamiento = 0, rondaActual = 0;         // CONTADORES
    int maxLanzamientos1 = 0, maxLanzamientos2 = 0;
    int vectNumDados[3] = {};                            // VECTOR NUMERO DE DADOS
    int trufasRonda = 0, acuTrufas1 = 0, acuTrufas2 = 0, maxPDV = 0; // ACUMULADORES
    bool hundirDosAses = false, hundirTresAses = false, cerdoHundido = false;
    bool corteAs = false, turnoJugador = false, cambioRonda = false;
    bool relanzamiento = false, tie = false;

    limpiarConsola();
    fPedirNombres(jugador1, jugador2);      // PEDIR NOMBRES
    fInstructivo();
    fBanner();                              // MOSTRAR INTERFAZ
    fMostrarNombres(jugador1, jugador2);    // MOSTRAR NOMBRES
    fMostrarTrufas(acuTrufas1, acuTrufas2); // MOSTRAR TRUFAS

    for(i=0; i<1; i++){
        limpiarConsola();
        cambioRonda = false;

        while(!cambioRonda){
            fBanner();
            fMostrarNombres(jugador1, jugador2);
            fMostrarTrufas(acuTrufas1, acuTrufas2);
            ftablaRonda(turnoJugador, trufasRonda, i, jugador1, jugador2, contLanzamiento);
            lanzar = ffSoN(relanzamiento);

            if(lanzar == 'S'){                 /// LANZAR
                contLanzamiento++;
                vectNumDados[3] = ffNumeroRandom(vectNumDados); /// ASIGNA NUMERO A LOS DADOS
                fAnimacion(cerdoHundido);

                if((cerdoHundido) || (acuTrufas1 > 50 && acuTrufas2 > 50)){ /// CON CUANTOS DADOS JUEGO?
                    fTresDados(vectNumDados);
                    ffCalculoTresDados(trufasRonda, vectNumDados);                // DOS DADOS
                    ffHundirTresAses(vectNumDados, hundirTresAses);
                } else {
                    fDosDados(vectNumDados);
                    ffCalculoDosDados(trufasRonda, vectNumDados, relanzamiento);  // TRES DADOS
                    ffHundirDosAses(vectNumDados, hundirDosAses, cerdoHundido);
                }

                ffContadorOinks(turnoJugador, relanzamiento, contOink1, contOink2);     /// CUENTA OINKS
                ffCorteTurno(vectNumDados, corteAs, cerdoHundido);                      /// CORTA TURNO

                if(corteAs){        /// SALIO UN AS?
                    if(!turnoJugador){ /// PIERDE EL TURNO EL JUGADOR 1?
                        ffContMaxLanz(contLanzamiento, maxLanzamientos1); // CONTAR MAX LANZAMIENTOS 1
                        if(cerdoHundido){ /// HAY CERDO HUNDIDO?
                            ffHundir(turnoJugador, hundirDosAses, hundirTresAses, acuTrufas1, acuTrufas2, jugador1, jugador2);
//                            ffSinkThree(turnoJugador, hundirTresAses, acuTrufas1, acuTrufas2);
//                            ffSinkTwo(turnoJugador, hundirDosAses, acuTrufas1, acuTrufas2);
                        } else {
                            fPierdeTurno(turnoJugador, jugador1, jugador2);
                        }
                    } else {           /// PIERDE EL TURNO EL JUGADOR 2?
                        ffContMaxLanz(contLanzamiento, maxLanzamientos2); // CONTAR MAX LANZAMIENTOS 2
                        if(cerdoHundido){ /// HAY CERDO HUNDIDO?
                            ffHundir(turnoJugador, hundirDosAses, hundirTresAses, acuTrufas1, acuTrufas2, jugador1, jugador2);
//                            ffSinkThree(turnoJugador, hundirTresAses, acuTrufas1, acuTrufas2);  // HUNDIR TRES DADOS
//                            ffSinkTwo(turnoJugador, hundirDosAses, acuTrufas1, acuTrufas2);     // HUNDIR DOS DADOS
                        } else {
                            fPierdeTurno(turnoJugador, jugador1, jugador2);                     // PERDER TURNO (UN AS)
                        }
                        cambioRonda = true;
                    }
                    contLanzamiento = 0;
                    trufasRonda = 0;
                    ffCambioTurno(turnoJugador);
                }
                posicionarXY(7,25);
                std::cout << "PULSE CUALQUIER TECLA PARA CONTINUAR";
                cualquierTecla();
                limpiarConsola();
                fBanner();
                fMostrarNombres(jugador1, jugador2);
                fMostrarTrufas(acuTrufas1, acuTrufas2);
                limpiarConsola();

            } else if(lanzar == 'N'){
                if(!turnoJugador){
                    funcionFinTurno(turnoJugador, trufasRonda, jugador1, jugador2);
                    cualquierTecla();
                    acuTrufas1 += trufasRonda;
                    ffContMaxLanz(contLanzamiento, maxLanzamientos1); // CONTAR MAX LANZAMIENTOS 2
                    limpiarConsola();
                } else {
                    funcionFinTurno(turnoJugador, trufasRonda, jugador1, jugador2);
                    cualquierTecla();
                    acuTrufas2 += trufasRonda;
                    ffContMaxLanz(contLanzamiento, maxLanzamientos2); // CONTAR MAX LANZAMIENTOS 2
                    cambioRonda = true;
                    limpiarConsola();
                }

                ffCambioTurno(turnoJugador);
                trufasRonda = 0;
                contLanzamiento = 0;
                setConsolaOriginal();
            }
        }
        posicionarXY(50,10);
        std::cout << "RONDA #" << i << " FINALIZADA";
    }
    limpiarConsola();
    posicionarXY(50, 20);
    std::cout << "GAME OVER";
    cualquierTecla();
    limpiarConsola();

    ffTablaFilaUno(matrizTablaResultados, acuTrufas1, acuTrufas2, masTrufas, jugador1, jugador2, ganador);
    ffTablaFilaDos(matrizTablaResultados, acuTrufas1, acuTrufas2);
    ffTablaFilaTres(matrizTablaResultados, contOink1, contOink2);
    ffTablaFilaCuatro(matrizTablaResultados, maxLanzamientos1, maxLanzamientos2);

    /// PDV TOTALES
    for(int j=0; j<4; j++){
        matrizTablaResultados[4][0] += matrizTablaResultados[j][0];
        matrizTablaResultados[4][2] += matrizTablaResultados[j][2];
    }
    if(matrizTablaResultados[4][0] > matrizTablaResultados[4][2]){
        for(int j=0; j<15; j++){
            ganador[j] = jugador1[j];
        }
        maxPDV = matrizTablaResultados[4][0];
    } else if(matrizTablaResultados[4][0] < matrizTablaResultados[4][2]) {
        for(int j=0; j<15; j++){
            ganador[j] = jugador2[j];
        }
        maxPDV = matrizTablaResultados[4][2];
    } else {
        tie = true;
        maxPDV = matrizTablaResultados[4][0];
    }

    ffTablaAlFinalizar(matrizTablaResultados, jugador1, jugador2, ganador, tie, maxPDV);
}

/// PRIMER FILA DE LA TABLA
void ffTablaFilaUno(int matrizTablaResultados[5][4], int acuTrufas1, int acuTrufas2, int &masTrufas, char jugador1[15], char jugador2[15], char ganador[15]){
    matrizTablaResultados[0][1] = acuTrufas1; // TRUFAS ACUMULADAS A MATRIZ
    matrizTablaResultados[0][3] = acuTrufas2;
    if(acuTrufas1 > acuTrufas2){
        masTrufas = acuTrufas1;
        matrizTablaResultados[0][0] = 5; // PDV A MATRIZ
        matrizTablaResultados[0][2] = 0;
    } else if(acuTrufas1 < acuTrufas2) {
        masTrufas = acuTrufas2;
        matrizTablaResultados[0][2] = 5; // PDV A MATRIZ
        matrizTablaResultados[0][0] = 0;
    } else {
        masTrufas = acuTrufas1;
        matrizTablaResultados[0][0] = 5; // PDV A MATRIZ
        matrizTablaResultados[0][2] = 5;
    }
}

/// SEGUNDA FILA DE LA TABLA
void ffTablaFilaDos(int matrizTablaResultados[5][4], int acuTrufas1, int acuTrufas2){
    matrizTablaResultados[1][0] = acuTrufas1 / 50; // JUGADOR 1
    matrizTablaResultados[1][1] = matrizTablaResultados[1][0] * 50;

    matrizTablaResultados[1][2] = acuTrufas2 / 50; // JUGADOR 2
    matrizTablaResultados[1][3] = matrizTablaResultados[1][2] * 50;
}
/// TERCERA FILA DE LA TABLA
void ffTablaFilaTres(int matrizTablaResultados[5][4], int contOink1, int contOink2){
    matrizTablaResultados[2][0] = contOink1 * 2; // JUGADOR 1
    matrizTablaResultados[2][1] = contOink1;
    matrizTablaResultados[2][2] = contOink2 * 2; // JUGADOR 2
    matrizTablaResultados[2][3] = contOink2;
}
/// CUARTA FILA DE LA TABLA
void ffTablaFilaCuatro(int matrizTablaResultados[5][4], int maxLanzamientos1, int maxLanzamientos2){
    matrizTablaResultados[3][1] = maxLanzamientos1; // LANZAMIENTOS A MATRIZ
    matrizTablaResultados[3][3] = maxLanzamientos2;
    if(maxLanzamientos1 > maxLanzamientos2){
        matrizTablaResultados[3][0] = 3;
        matrizTablaResultados[3][2] = 0;
    } else if(maxLanzamientos1 < maxLanzamientos2){
        matrizTablaResultados[3][0] = 0;
        matrizTablaResultados[3][2] = 3;
    } else {
        matrizTablaResultados[3][0] = 3;
        matrizTablaResultados[3][2] = 3;
    }
}

void ffContMaxLanz(int contLanzamiento, int &maxLanzamientos){
    if(contLanzamiento > maxLanzamientos){
        maxLanzamientos = contLanzamiento;
    }
}

/// HUNDE CON DOS ASES
void ffSinkTwo(bool turnoJugador, bool hundirDosAses, int &acuTrufas1, int &acuTrufas2){
    if(hundirDosAses){
        if(!turnoJugador){
            acuTrufas1 = 0;
        } else {
            acuTrufas2 = 0;
        }
        fHundirEnElBarro(false);
        hundirDosAses = false;
    }
}

/// HUNDE CON TRES ASES
void ffHundir(bool turnoJugador, bool hundirDosAses, bool hundirTresAses, int &acuTrufas1, int &acuTrufas2, char jugador1[15], char jugador2[15]){
    if(hundirTresAses){ /// SALIERON 3 ASES?
        if(!turnoJugador){
            acuTrufas2 += acuTrufas1; // TRUFAS DEL 1 AL 2
            acuTrufas1 = 0;
        } else{
            acuTrufas1 += acuTrufas2; // TRUFAS DEL 2 AL 1
            acuTrufas2 = 0;
        }
        fHundirEnElBarro(true);
        hundirTresAses = false;
    } else if(hundirDosAses){ /// SALIERON 2 ASES?
        if(!turnoJugador){
            acuTrufas1 = 0;
        } else {
            acuTrufas2 = 0;
        }
        fHundirEnElBarro(false);
        hundirDosAses = false;
    } else {
        fPierdeTurno(turnoJugador, jugador1, jugador2);
    }
}

/// CONTADOR
void ffContadorOinks(bool turnoJugador, bool relanzamiento, int &contOink1, int &contOink2){
    if(relanzamiento){
        if(!turnoJugador){
            contOink1++;
        } else {
            contOink2++;
        }
    }
}

/// CALCULA LOS PUNTOS DE A DOS DADOS
void ffCalculoDosDados(int &trufasRonda, int vectNumDados[3], bool &relanzamiento){
    if(vectNumDados[0] != vectNumDados[1] && (vectNumDados[0] != 1 && vectNumDados[1] != 1)){ /// CARAS DISTINTAS SIN AS
        trufasRonda += vectNumDados[0] + vectNumDados[1];
    }
    else if(vectNumDados[0] == vectNumDados[1] && (vectNumDados[0] != 1 && vectNumDados[1] != 1)){ /// CARAS IGUALES SIN AS
        relanzamiento = true;
        fPrintOink();
        trufasRonda += (vectNumDados[0]+vectNumDados[1])*2;
    }
    else if(vectNumDados[0] != vectNumDados[1] && (vectNumDados[0] == 1 || vectNumDados[1] == 1)){ /// CARAS DISTINTAS CON AS
        trufasRonda = 0;
    }
}

/// CALCULA LOS PUNTOS DE A TRES DADOS
void ffCalculoTresDados(int &trufasRonda, int vectNumDados[3]){
    if((vectNumDados[0]!=vectNumDados[1] && vectNumDados[1]!=vectNumDados[2] && vectNumDados[0]!=vectNumDados[2]) && (vectNumDados[0]!=1 && vectNumDados[1]!=1 && vectNumDados[2]!=1)){ /// CARAS DISTINTAS SIN AS
        trufasRonda += vectNumDados[0] + vectNumDados[1] + vectNumDados[2];
    } else if((vectNumDados[0]==vectNumDados[1] && vectNumDados[1]==vectNumDados[2]) && (vectNumDados[0]!=1 && vectNumDados[1]!=1 && vectNumDados[2]!=1)){ /// 3 CARAS IGUALES SIN ASES
        trufasRonda += (vectNumDados[0]+vectNumDados[1]+vectNumDados[2]) * 2;
    } else if((vectNumDados[0]==vectNumDados[1] || vectNumDados[1]==vectNumDados[2] || vectNumDados[2]==vectNumDados[1]) && (vectNumDados[0]!=1 && vectNumDados[1]!=1 && vectNumDados[2]!=1)){ /// 2 CARAS IGUALES SIN ASES
        trufasRonda += vectNumDados[0] + vectNumDados[1] + vectNumDados[2];
    } else if(vectNumDados[0]==1 && vectNumDados[1]==1 && vectNumDados[2]==1){ /// TRES ASES
//        std::cout << "HUNDE EN EL BARRO" << std::endl;
//        std::cout << "PUNTO PAL OTRO" << std::endl;
    } else if((vectNumDados[0]==vectNumDados[1] && vectNumDados[0]==1)|| (vectNumDados[1]==vectNumDados[2] && vectNumDados[2]==1) || (vectNumDados[0]==vectNumDados[2] && vectNumDados[0]==1)){ /// DOS ASES
        trufasRonda = 0;
    } else if((vectNumDados[0]!=vectNumDados[1] && vectNumDados[1]!=vectNumDados[2] && vectNumDados[0]!=vectNumDados[2]) && (vectNumDados[0]==1 || vectNumDados[1]==1 || vectNumDados[2]==1)){ /// UN AS CARAS DISTINTAS
        trufasRonda = 0;
    }
}

/// HUNDE CON DOS ASES
void ffHundirDosAses(int vectNumDados[3], bool &hundirDosAses, bool &cerdoHundido){
    if(vectNumDados[0] == 1 && vectNumDados[1] == 1){
        cerdoHundido = true;
        hundirDosAses = true;
    } else {
        hundirDosAses = false;
    }
}

/// HUNDE CON TRES ASES
void ffHundirTresAses(int vectNumDados[3], bool &hundirTresAses){
    if(vectNumDados[0] == 1 && vectNumDados[1] == 1 && vectNumDados[2]){
        hundirTresAses = true;
    } else {
        hundirTresAses = false;
    }
}

/// CORTA TURNO
bool ffCorteTurno(int vectNumDados[3], bool &corteAs, bool cerdoHundido){
    if(!cerdoHundido){
        if(vectNumDados[0] == 1 || vectNumDados[1] == 1){
            corteAs = true;
        } else {
            corteAs = false;
        }
    } else {
        if(vectNumDados[0] == 1 || vectNumDados[1] == 1 || vectNumDados[2] == 1){
            corteAs = true;
        } else {
            corteAs = false;
        }
    }
    return corteAs;
}

/// LANZAMIENTO
char ffSoN(bool &relanzamiento){
    char lanzar;
    if(!relanzamiento){
        fondoBlanco();
        posicionarXY(2, 29);
        std::cout << "LANZAR? (S/N)";
        // LANZAR
        lanzar = rlutil::getkey();
        if(lanzar == 's' || lanzar == 'n'){
            lanzar -= 32;
        }

    } else {
        // PEDIR LANZAMIENTO
        fondoBlanco();
        posicionarXY(2, 29);
        std::cout << "TENES QUE VOLVER A LANZAR (S)";
        rlutil::anykey();
        // LANZAR
        lanzar = 'S';
        relanzamiento = false;
    }
    setConsolaOriginal();
    return lanzar;
}

/// CAMBIO DE TURNO
void ffCambioTurno(bool &turnoJugador){
    if(!turnoJugador){ // INVIERTE EL BOOLEANO
        turnoJugador = true;
    } else {
        turnoJugador = false;
    }
}

/// DA UN NUMERO RANDOM
int ffNumeroRandom(int vectNumDados[3]){
    srand(time(NULL));
    for(int i=0; i<3; i++){
        vectNumDados[i] = rand() % 6 + 1;
    }
    return vectNumDados[3];
    system("PAUSE");
}


