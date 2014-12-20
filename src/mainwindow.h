#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QObject>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setFileLoaded ( const bool value );
    bool fileIsLoaded() const;

public slots:
    void on_actionAbrirArquivo_triggered();
    void on_actionFecharArquivo_triggered();
    void updateWindow();
    
signals:
    void valueChanged( bool value );

private:
    bool m_fileIsLoaded;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
