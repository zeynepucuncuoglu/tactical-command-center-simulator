#include "MainWindow.h"

#include <QTableWidget>
#include <QStringList>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    m_tableWidget = new QTableWidget(this);

    m_tableWidget->setColumnCount(5);

    m_tableWidget->setHorizontalHeaderLabels(
        QStringList{
            "ID",
            "X",
            "Y",
            "Speed",
            "Type"
        }
    );

    setCentralWidget(m_tableWidget);

    setWindowTitle("Tactical Command Center");

    resize(800, 600);
}