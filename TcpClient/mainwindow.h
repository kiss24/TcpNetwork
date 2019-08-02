#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTcpSocket* m_socket;

    void connectToServer();

private slots:
    void slot_readMessage();
    void slot_btnSendMsg();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
