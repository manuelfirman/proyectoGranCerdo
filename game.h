#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED



#endif // GAME_H_INCLUDED

char ffSoN(bool &relanzamiento);
bool ffCorteTurno(int vectNumDados[3], bool &corteAs, bool cerdoHundido, bool trufas50);
bool fCerdoHundido(int vectNumDados[3]);
int ffNumeroRandom(int vectNumDados[3]);
void ffCalculoDosDados(int &trufasRonda, int vectNumDados[3], bool &relanzamiento);
void ffCalculoTresDados(int &trufasRonda, int vectNumDados[3], bool &relanzamiento);
void ffContMaxLanz(int contLanzamiento, int &maxLanzamientos);
void ffCambioTurno(bool &turnoJugador);
void ffContadorOinks(bool turnoJugador, bool relanzamiento, int &contOink1, int &contOink2);
void ffHundirDosAses(int vectNumDados[3], bool &hundirDosAses, bool &cerdoHundido);
void ffHundirTresAses(int vectNumDados[3], bool &hundirTresAses, bool &hundirDosAses);
void funcionFinTurno(bool turnoJugador, int trufasRonda, char jugador1[15], char jugador2[15]);
void funcionLanzamiento(int contLanzamiento, int vectNumDados[3], int trufasRonda, bool cerdoHundido, int acuTrufas1, int acuTrufas2);
void ffTablaFilaUno(int matrizTablaResultados[5][4], int acuTrufas1, int acuTrufas2, int &masTrufas, char jugador1[15], char jugador2[15], char ganador[15]);
void ffTablaFilaDos(int matrizTablaResultados[5][4], int acuTrufas1, int acuTrufas2);
void ffTablaFilaTres(int matrizTablaResultados[5][4], int contOink1, int contOink2);
void ffTablaFilaCuatro(int matrizTablaResultados[5][4], int maxLanzamientos1, int maxLanzamientos2);
void ffTotal(int matrizTablaResultados[5][4], int &maxPDV, bool &tie, char jugador1[15], char jugador2[15], char ganador[15]);
void ffSinkTwo(bool turnoJugador, bool hundirDosAses, int &acuTrufas1, int &acuTrufas2);
void ffHundir(bool turnoJugador, bool &hundirDosAses, bool &hundirTresAses, int &acuTrufas1, int &acuTrufas2, char jugador1[15], char jugador2[15]);
void ffTrufas50(int acuTrufas1, int acuTrufas2, bool &trufas50);
void ffTest(char lanzar, int vectNumDados[]);

void fGame(int &record, char mejorPuntaje[15]){
    int matrizTablaResultados[5][4] = {};
    int contOink1 = 0, contOink2 = 0;
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
    bool trufas50 = false;

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
//                ffTest(lanzar, vectNumDados);
                fAnimacion(cerdoHundido, trufas50);

                if(cerdoHundido || trufas50){ /// CON CUANTOS DADOS JUEGO?
                    fTresDados(vectNumDados);
                    ffCalculoTresDados(trufasRonda, vectNumDados, relanzamiento);                // DOS DADOS
                    ffHundirTresAses(vectNumDados, hundirTresAses, hundirDosAses);
                } else {
                    fDosDados(vectNumDados);
                    ffCalculoDosDados(trufasRonda, vectNumDados, relanzamiento);  // TRES DADOS
                    ffHundirDosAses(vectNumDados, hundirDosAses, cerdoHundido);
                }

                ffContadorOinks(turnoJugador, relanzamiento, contOink1, contOink2);     /// CUENTA OINKS
                ffCorteTurno(vectNumDados, corteAs, cerdoHundido, trufas50);                      /// CORTA TURNO

                if(corteAs){        /// SALIO UN AS?
                    if(!turnoJugador){ /// PIERDE EL TURNO EL JUGADOR 1?
                        ffContMaxLanz(contLanzamiento, maxLanzamientos1); // CONTAR MAX LANZAMIENTOS 1
                        if(cerdoHundido || trufas50){ /// HAY CERDO HUNDIDO?
                            ffHundir(turnoJugador, hundirDosAses, hundirTresAses, acuTrufas1, acuTrufas2, jugador1, jugador2);
                        } else {
                            fPierdeTurno(turnoJugador, jugador1, jugador2);
                        }
                    } else {           /// PIERDE EL TURNO EL JUGADOR 2?
                        ffContMaxLanz(contLanzamiento, maxLanzamientos2); // CONTAR MAX LANZAMIENTOS 2
                        if(cerdoHundido || trufas50){ /// HAY CERDO HUNDIDO?
                            ffHundir(turnoJugador, hundirDosAses, hundirTresAses, acuTrufas1, acuTrufas2, jugador1, jugador2);
                        } else {
                            fPierdeTurno(turnoJugador, jugador1, jugador2);                     // PERDER TURNO (UN AS)
                        }
                        cambioRonda = true;
                    }
                    contLanzamiento = 0;
                    trufasRonda = 0;
                    ffCambioTurno(turnoJugador);
                } else { /// NO CORTA
                    posicionarXY(53,25);
                    std::cout << "SEGUIS JUGANDO";
                    posicionarXY(42,27);
                    std::cout << "PULSA CUALQUIER TECLA PARA CONTINUAR";
                }
                cualquierTecla();
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
            ffTrufas50(acuTrufas1, acuTrufas2, trufas50);
        }

        posicionarXY(55,4);
        std::cout << "RONDA #" << i+1 << " FINALIZADA";
        Sleep(1500);
    }
    limpiarConsola();
    posicionarXY(50, 30);
    std::cout << "GAME OVER";
    cualquierTecla();
    limpiarConsola();
    /// TABLA FIN JUEGO
    ffTablaFilaUno(matrizTablaResultados, acuTrufas1, acuTrufas2, masTrufas, jugador1, jugador2, ganador);  // FILA 1
    ffTablaFilaDos(matrizTablaResultados, acuTrufas1, acuTrufas2);                                          // FILA 2
    ffTablaFilaTres(matrizTablaResultados, contOink1, contOink2);                                           // FILA 3
    ffTablaFilaCuatro(matrizTablaResultados, maxLanzamientos1, maxLanzamientos2);                           // FILA 4
    ffTotal(matrizTablaResultados, maxPDV, tie, jugador1, jugador2, ganador);                               // TOTAL
    fFinJuego(matrizTablaResultados, jugador1, jugador2, ganador, tie, maxPDV);                             // TABLA

    if(maxPDV > record){
        record = maxPDV;
        for(int j=0; j<15; j++){
            mejorPuntaje[j] = ganador[j];
        }
    }
}


/// TEST
void ffTest(char lanzar, int vectNumDados[]){
lanzar = rlutil::getkey();
    if (lanzar == 'T'){
        vectNumDados[0] = 1;
        vectNumDados[1] = 1;
        vectNumDados[2] = 1;
    } else if(lanzar == 'D'){
        vectNumDados[0] = 1;
        vectNumDados[1] = 2;
        vectNumDados[2] = 1;
    } else if(lanzar == 'F'){
        vectNumDados[0] = 1;
        vectNumDados[1] = 1;
        vectNumDados[2] = 2;
    } else if(lanzar == 'G'){
        vectNumDados[0] = 2;
        vectNumDados[1] = 1;
        vectNumDados[2] = 1;
    } else if(lanzar == 'Z'){
        vectNumDados[0] = 2;
        vectNumDados[1] = 3;
        vectNumDados[2] = 2;
    }
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

/// TOTAL TABLA
void ffTotal(int matrizTablaResultados[5][4], int &maxPDV, bool &tie, char jugador1[15], char jugador2[15], char ganador[15]){
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
}

void ffContMaxLanz(int contLanzamiento, int &maxLanzamientos){
    if(contLanzamiento > maxLanzamientos){
        maxLanzamientos = contLanzamiento;
    }
}

void ffTrufas50(int acuTrufas1, int acuTrufas2, bool &trufas50){
    if(acuTrufas1 > 49 && acuTrufas2 > 49){
        trufas50 = true;
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
void ffCalculoTresDados(int &trufasRonda, int vectNumDados[3], bool &relanzamiento){
    if((vectNumDados[0]!=vectNumDados[1] && vectNumDados[1]!=vectNumDados[2] && vectNumDados[0]!=vectNumDados[2]) && (vectNumDados[0]!=1 && vectNumDados[1]!=1 && vectNumDados[2]!=1)){ /// CARAS DISTINTAS SIN AS
        trufasRonda += vectNumDados[0] + vectNumDados[1] + vectNumDados[2];
    } else if((vectNumDados[0]==vectNumDados[1] && vectNumDados[1]==vectNumDados[2]) && (vectNumDados[0]!=1 && vectNumDados[1]!=1 && vectNumDados[2]!=1)){ /// 3 CARAS IGUALES SIN ASES
        relanzamiento = true;
        fPrintOink();
        trufasRonda += (vectNumDados[0]+vectNumDados[1]+vectNumDados[2]) * 2;
    } else if((vectNumDados[0]==vectNumDados[1] || vectNumDados[1]==vectNumDados[2] || vectNumDados[0]==vectNumDados[2]) && (vectNumDados[0]!=1 && vectNumDados[1]!=1 && vectNumDados[2]!=1)){ /// 2 CARAS IGUALES SIN ASES
        trufasRonda += vectNumDados[0] + vectNumDados[1] + vectNumDados[2];
    } else if(vectNumDados[0]==1 && vectNumDados[1]==1 && vectNumDados[2]==1){ /// TRES ASES
        trufasRonda = 0;
    } else if((vectNumDados[0]==vectNumDados[1] && vectNumDados[0]==1)|| (vectNumDados[1]==vectNumDados[2] && vectNumDados[2]==1) || (vectNumDados[0]==vectNumDados[2] && vectNumDados[0]==1)){ /// DOS ASES
        trufasRonda = 0;
    } else if((vectNumDados[0]!=vectNumDados[1] && vectNumDados[1]!=vectNumDados[2] && vectNumDados[0]!=vectNumDados[2]) && (vectNumDados[0]==1 || vectNumDados[1]==1 || vectNumDados[2]==1)){ /// UN AS CARAS DISTINTAS
        trufasRonda = 0;
    }
}

/// HUNDIR EN EL BARRO
void ffHundir(bool turnoJugador, bool &hundirDosAses, bool &hundirTresAses, int &acuTrufas1, int &acuTrufas2, char jugador1[15], char jugador2[15]){
    if(hundirTresAses){ /// SALIERON 3 ASES?
        if(!turnoJugador){
            acuTrufas2 += acuTrufas1; // TRUFAS DEL 1 AL 2
            acuTrufas1 = 0;
        } else{
            acuTrufas1 += acuTrufas2; // TRUFAS DEL 2 AL 1
            acuTrufas2 = 0;
        }
        fCartelHundido(true); // true = tres ases
        hundirTresAses = false;
    } else if(hundirDosAses){ /// SALIERON 2 ASES?
        if(!turnoJugador){
            acuTrufas1 = 0;
        } else {
            acuTrufas2 = 0;
        }
        fCartelHundido(false); // false = dos ases
        hundirDosAses = false;
    } else {
        fPierdeTurno(turnoJugador, jugador1, jugador2);
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
void ffHundirTresAses(int vectNumDados[3], bool &hundirTresAses, bool &hundirDosAses){
    if(vectNumDados[0] == 1 && vectNumDados[1] == 1 && vectNumDados[2] == 1){
        hundirTresAses = true;
    } else {
        hundirTresAses = false;
    }

    if(((vectNumDados[0] == 1) && (vectNumDados[1] == 1)) || ((vectNumDados[1] == 1) && (vectNumDados[2] == 1)) || ((vectNumDados[0] == 1) && (vectNumDados[2] == 1))){
        hundirDosAses = true;
    } else {
        hundirDosAses = false;
    }
}

/// CORTA TURNO
bool ffCorteTurno(int vectNumDados[3], bool &corteAs, bool cerdoHundido, bool trufas50){
    if(cerdoHundido || trufas50){
        if(vectNumDados[0] == 1 || vectNumDados[1] == 1 || vectNumDados[2] == 1){
            corteAs = true;
        } else {
            corteAs = false;
        }
    } else {
        if(vectNumDados[0] == 1 || vectNumDados[1] == 1){
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
        posicionarXY(7, 21);
        std::cout << "LANZAR? (S/N)";
        // LANZAR
        lanzar = rlutil::getkey();
        if(lanzar == 's' || lanzar == 'n'){
            lanzar -= 32;
        }
        setConsolaOriginal();
        posicionarXY(7, 21);
        std::cout << "             ";

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


