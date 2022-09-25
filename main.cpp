/**
 * This started with the Hello World example from develop.kde.org/docs/use/kxmlgui/hello_world
 */

#include <QApplication>
#include <KMessageBox>
#include <marble/MarbleWidget.h>

#include <iostream>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    KGuiItem yesButton("Hello", QString(),
                       "This is a tooltip",
                       "This is a WhatsThis help text.");

    auto retVal = KMessageBox::questionYesNo(0, "Hello World!", "Hello", yesButton) ==
                  KMessageBox::Yes ? EXIT_SUCCESS : EXIT_FAILURE;

    Marble::MarbleWidget *mapWidget = new Marble::MarbleWidget;
    mapWidget->setProjection(Marble::Mercator);
    mapWidget->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");

    mapWidget->setWindowTitle("Hello Marble");
    mapWidget->show();

    return app.exec();
}
