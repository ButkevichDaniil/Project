#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QCoreApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool isError;

public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void ClientDisconnected();
private:
    Ui::MainWindow *ui;
    QByteArray Data;
    bool skip_read;

    void SendToServer(QString str);
    void Connect();

public slots:
    void slotReadyRead();
private slots:
    //void on_textinfo_anchorClicked(const QUrl &arg1);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};
#endif // MAINWINDOW_H
