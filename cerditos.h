#ifndef CERDITOS_H_INCLUDED
#define CERDITOS_H_INCLUDED


#endif // CERDITOS_H_INCLUDED


/// MEJORES PUNTAJES
void fEstadisticas(int record, char mejorPuntaje[15]){
    limpiarConsola();
    fondoRosado();
    posicionarXY(50, 2);
    std::cout << "                         " << std::endl;
    posicionarXY(48, 3);
    std::cout << "        ESTADISTICAS     " << std::endl;
    posicionarXY(50, 4);
    std::cout << "                         " << std::endl;
    fondoBlanco();
    posicionarXY(54, 8);
    std::cout << "  MEJOR PUNTAJE  " << std::endl;

    setConsolaOriginal();
    if(strlen(mejorPuntaje)>0){
        posicionarXY(54, 12);
        std::cout << mejorPuntaje << " ...... " << record << " PDV" << std::endl;
    } else {
        posicionarXY(52, 12);
        std::cout << "VACANTE ...... 0 PDV" << std::endl;
    }

    cualquierTecla();
    limpiarConsola();
}

/// CREDITOS CREADORES
void fCerditos(){
    limpiarConsola();
    fondoRosado();
    posicionarXY(50, 2);
    std::cout << "                         " << std::endl;
    posicionarXY(48, 3);
    std::cout << "    CERDITOS CODICIOSOS  " << std::endl;
    posicionarXY(50, 4);
    std::cout << "                         " << std::endl;

    setConsolaOriginal();
    posicionarXY(32, 9);
    std::cout << "RAMIREZ MARIA JOAQUINA\t\t\t\tLEGAJO 26077" << std::endl;

    posicionarXY(32, 11);
    std::cout << "FIRMAN TRONCOSO JUAN MANUEL\t\t\tLEGAJO 25908" << std::endl;
    cualquierTecla();
    limpiarConsola();
}
