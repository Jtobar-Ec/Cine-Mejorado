#include "ventanap.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>


int main(int argc, char *argv[])
{
    // Geovanny listo!
    // Hanner Participando
    // Justin Participando
    // Sebastián Participando
    QApplication a(argc, argv);
    QTranslator traduccion;
        // Solicitando al usuario que seleccione un idioma
        QStringList idiomas;
        idiomas << "English" << "Español";

    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                   "Idioma",
                                   "Seleccione un idioma",
                                   idiomas);
        // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
        if (idiomaSeleccionado == "English"){
            traduccion.load(":/Cine-Mejorado_en.qm");
        }
        // Si es diferente de español, se instala la traducción en TODA la aplicación
        if (idiomaSeleccionado != "Español"){
            a.installTranslator(&traduccion);}

    VentanaP w;
    w.show();
    return a.exec();
}
