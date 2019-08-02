#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    startServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startServer()
{
    m_server = new QTcpServer(this);

    m_server->listen(QHostAddress::Any, 9999);

    connect(m_server, SIGNAL(newConnection()), this, SLOT(slot_newConnection()));
}

void MainWindow::slot_newConnection()
{
    QTcpSocket* socket = m_server->nextPendingConnection();

    m_sockets.push_back(socket);

    connect(socket, SIGNAL(readyRead()), this, SLOT(slot_readMessage()));
}

void MainWindow::slot_readMessage()
{
    QTcpSocket* socket = (QTcpSocket*)QObject::sender();

    QString str = socket->readAll().data();

    for(int i=0; i<m_sockets.size(); i++)
    {
        m_sockets[i]->write(str.toStdString().data());
    }
}
