#include "FileManager.h"

//#include <QtSql/QSqlDatabase>
#include <QFileDialog>


FileManager::FileManager():
    m_file() {}

void FileManager::openFile( const QString& fileName )
{
      QFile m_file( fileName );

      // Se arquivo não existe, retorna assertiva
      if ( !m_file.exists() ) {
          //todo implementar códigos de erro
          exit(-1);
      } else {
          // Se ocorrer algum erro na hora da leitura
          if ( !m_file.open( QIODevice::ReadOnly ) ) {
              //todo implementar códigos de erro
              exit(-1);
          }
      }
}
