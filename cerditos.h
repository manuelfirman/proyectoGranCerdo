#ifndef CERDITOS_H_INCLUDED
#define CERDITOS_H_INCLUDED


#endif // CERDITOS_H_INCLUDED


/// MEJORES PUNTAJES
void fEstadisticas(){
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(50, 2);
    std::cout << "                         " << std::endl;
    rlutil::locate(48, 3);
    std::cout << "        ESTADISTICAS     " << std::endl;
    rlutil::locate(50, 4);
    std::cout << "                         " << std::endl;

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(50, 9);
    std::cout << "JOAQUI ..... 10000 pts" << std::endl;

    rlutil::locate(50, 11);
    std::cout << "MANOLE ..... 1500 pts" << std::endl;
    rlutil::anykey();
    rlutil::cls();
}

/// CREDITOS CREADORES
void fCerditos(){
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
    rlutil::locate(50, 2);
    std::cout << "                         " << std::endl;
    rlutil::locate(48, 3);
    std::cout << "    CERDITOS CODICIOSOS  " << std::endl;
    rlutil::locate(50, 4);
    std::cout << "                         " << std::endl;

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(32, 9);
    std::cout << "RAMIREZ MARIA JOAQUINA\t\t\t\tLEGAJO 26077" << std::endl;

    rlutil::locate(32, 11);
    std::cout << "FIRMAN TRONCOSO JUAN MANUEL\t\t\tLEGAJO 25908" << std::endl;
    rlutil::anykey();
    rlutil::cls();
}
