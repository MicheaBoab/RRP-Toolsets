#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "asc.h"
#include "st.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QVariant>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// open
void MainWindow::on_actionOpen_triggered()
{
    QString filter = "All File (*.*) ;; Text File (*.txt)";
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", "", filter);
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox:: warning(this, "title", "File not open");
    }

    QTextStream in(&file);
    QString text = in.readAll();
    //ui->pcpuTextEdit->setPlainText(text);

    file.close();
}



// save as
void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Open a file", "");
    QFile file(fileName);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox:: warning(this, "title", "File not open");
    }

    QTextStream out(&file);
    //QString text = ui->pcpuTextEdit->toPlainText();
    //out << text;

    file.flush();
    file.close();
}

void MainWindow::on_pcgButton_clicked()
{
    PCG pcg;
    pcg.setModal(true);
    pcg.exec();
}

void MainWindow::on_ascButton_clicked()
{
    ASC asc;
    asc.setModal(true);
    asc.exec();
}

void MainWindow::on_schedulabilityButton_clicked()
{
    ST st;
    st.setModal(true);
    st.exec();
}


void MainWindow::on_actionASG_triggered()
{
    QMessageBox *mBox = new QMessageBox(QMessageBox::Information,
                                        "Automated Schedule Configurator",
                                        "ASC generates one cyclic schedule for each CPU with the configurations of the partitions taken as inputs.",
                                        QMessageBox::Ok | QMessageBox::Default);
    mBox->show();
}

void MainWindow::on_actionST_triggered()
{
    QMessageBox *mBox = new QMessageBox(QMessageBox::Information,
                                        "Schedulability Test",
                                        "ST can judge whether the current configuration of a partition can offer real-time performance guarantees to the task set being deployed.",
                                        QMessageBox::Ok | QMessageBox::Default);
    mBox->show();
}

void MainWindow::on_actionRRP_model_triggered()
{
    QMessageBox *mBox = new QMessageBox(QMessageBox::Information,
                                        "RRP Model",
                                        "The Regularity-based Resource Partitioning (RRP) model is a resource-level model that helps divide physical resources into multiple partitions.",
                                        QMessageBox::Ok | QMessageBox::Default);
    mBox->show();
}

void MainWindow::on_actionPCG_triggered()
{
    QMessageBox *mBox = new QMessageBox(QMessageBox::Information,
                                        "Partition Configuration Generator",
                                        "PCG takes in the information of a task set that will be deployed on a partition. It generates an availability factor so that the task set given is schedulable on the partition equipped with the availability factor. ",
                                        QMessageBox::Ok | QMessageBox::Default);
    mBox->show();
}
