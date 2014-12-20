#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qapplication.h>
#include <QFileDialog>

#include <iostream>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    m_fileIsLoaded( false ),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connects do Qt
    connect( ui->actionSair, SIGNAL( triggered() ), qApp, SLOT( quit()));
    connect( this, SIGNAL( valueChanged( bool )), this, SLOT( updateWindow() ));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrirArquivo_triggered()
{
    QString auxString;
    auxString = QFileDialog::getOpenFileName( this ,
                                              tr( "Abrir Arquivo" ),
                                              "./",
                                              tr( "Valores Separado por Vírgulas (*.csv);;Microsoft Excel <=2003 (*.xls);;Microsoft Excel >=2007 (*.xlsx);;Todos os arquivos (*.*)" ) );
    // Se arquivo foi selecionado
    if ( auxString != "" ) {
        // Se arquivo selecionado é diferente do atual e deve er atualizado
        qDebug("Arquivo carregado:" );
    }
}

void MainWindow::on_actionFecharArquivo_triggered() {
    setFileLoaded( false );
}

void MainWindow::setFileLoaded( const bool value ) {
    if ( value != m_fileIsLoaded ) {
        m_fileIsLoaded = value;
        emit valueChanged( value );
    }
}

bool MainWindow::fileIsLoaded() const {
    return m_fileIsLoaded;
}


void MainWindow::updateWindow() {
    if ( m_fileIsLoaded ) {
//        ui->fileLabel->setText( QString("Arquivo: %0").arg(m_fileManager.fileName() ));
    } else {
        ui->fileLabel->setText( "Arquivo" );
    }
}
