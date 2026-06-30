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

  void MainWindow::onTargetReceived(
    const QString& id,
    double x,
    double y,
    double speed,
    const QString& type)
{
    int row = m_tableWidget->rowCount();

    m_tableWidget->insertRow(row);

    m_tableWidget->setItem(
        row,
        0,
        new QTableWidgetItem(id));

    m_tableWidget->setItem(
        row,
        1,
        new QTableWidgetItem(QString::number(x)));

    m_tableWidget->setItem(
        row,
        2,
        new QTableWidgetItem(QString::number(y)));

    m_tableWidget->setItem(
        row,
        3,
        new QTableWidgetItem(QString::number(speed)));

    m_tableWidget->setItem(
        row,
        4,
        new QTableWidgetItem(type));
}