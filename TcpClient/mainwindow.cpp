#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectToServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToServer()
{
    m_socket = new QTcpSocket(this);

    m_socket->connectToHost(QHostAddress::LocalHost, 9999);

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(slot_readMessage()));

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(slot_btnSendMsg()));
}

void MainWindow::slot_readMessage()
{
    QString str = m_socket->readAll().data();

    ui->textBrowser->setText(ui->textBrowser->toPlainText() + "\n" + str);
}

void MainWindow::slot_btnSendMsg()
{
    QString str = ui->lineEdit->text();

    m_socket->write(str.toStdString().data());

    ui->lineEdit->clear();
}
