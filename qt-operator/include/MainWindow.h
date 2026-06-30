#pragma once

#include <QMainWindow>

class QTableWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    public slots:
    void onTargetReceived(const QString& id, double x, double y, 
                          double speed, const QString& type);


private:
    QTableWidget* m_tableWidget;

};
