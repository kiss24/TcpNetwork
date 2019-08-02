#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTcpServer* m_server;

    QList<QTcpSocket*> m_sockets;

    void startServer();

public slots:
    void slot_newConnection();
    void slot_readMessage();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
