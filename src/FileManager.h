#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <QFile>
#include <QString>


//! Classe handler de arquivos
class FileManager
{
public:
    //! Contrutor Padrão
    FileManager();

    //! Destrutor Padrão
    ~FileManager();

    //! Abre arquivo (esta classe poderia ser toda static??? como uma util???)
    void openFile( const QString& fileName );

    //! Retorna o nome do arquivo
    QString fileName() const { return m_file.fileName(); }

private:
    QFile m_file;
};

#endif // FILEMANAGER_H
