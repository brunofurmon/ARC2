#ifndef SESSION_H
#define SESSION_H


#include "FileManager.h"


#include <QList>
#include <QString>


// Esta classe facilita salvar/carregar uma sessão de usuário
// em arquivos recentemente abertos
class Session
{
public:

    // Construtor Padrão
    Session();

    // Destrutor Padrão
    ~Session() {}

    // Adiciona entrada à lista de arquivos recentes
    void addToRecentList();

private:
    // Reorganiza a lista
    void sortList();

    // Lista de Arquivos abertos recentemente
    QList< QString > RecentFilesList;

    // Genrenciador de arquivos
    FileManager m_fileSession;
};

#endif // SESSION_H
