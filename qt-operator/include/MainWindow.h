#pragma once
#include "Target.h"
#include <QMainWindow>

class QTableWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    public slots:
    void onTargetReceived(const Target& target);


private:
    QTableWidget* m_tableWidget;

};
