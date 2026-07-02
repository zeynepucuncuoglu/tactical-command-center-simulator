#include "MainWindow.h"
#include "Target.h"
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

std::string targetTypeToString(TargetType type) {
    switch (type) {
        case TargetType::AIRCRAFT:
            return "AIRCRAFT";
        case TargetType::DRONE:
            return "DRONE";
        case TargetType::SHIP:
            return "SHIP";
        default:
            return "UNKNOWN";
    }
}


  void MainWindow::onTargetReceived(
    const Target& target)
{
    int row = m_tableWidget->rowCount();

    m_tableWidget->insertRow(row);

    m_tableWidget->setItem(
        row,
        0,
        new QTableWidgetItem(QString::fromStdString(target.getId())));

    m_tableWidget->setItem(
        row,
        1,
        new QTableWidgetItem(QString::number(target.getX())));

    m_tableWidget->setItem(
        row,
        2,
        new QTableWidgetItem(QString::number(target.getY())));

    m_tableWidget->setItem(
        row,
        3,
        new QTableWidgetItem(QString::number(target.getSpeed())));

    m_tableWidget->setItem(
        row,
        4,
        new QTableWidgetItem(QString::fromStdString(targetTypeToString(target.getType()))));
}