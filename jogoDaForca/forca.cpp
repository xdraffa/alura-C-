#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavraSecreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutesErrados;

bool letraExiste(char chute){
    for(char letra : palavraSecreta){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

bool ganhou(){
    for(char letra : palavraSecreta){
        if(!chutou[letra]){ 
            return false;
        } 
    }
    return true;
}

bool enforcou(){
    return chutesErrados.size() == 5;
}

void imprimeCabecalho(){
    cout << "****************************" << endl;
    cout << "*******JOGO DA FORCA********" << endl;
    cout << "****************************" << endl;
    cout << endl << endl;
}

void imprimeErros(){
    cout << "Chutes errados: ";
    for(char letra : chutesErrados){
        cout << letra << " - ";
    }
        cout << "\n" << endl;
}

void imprimePalavraSecreta(){
    for(char letra : palavraSecreta){
        if(chutou[letra]){
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }
        cout << endl;
}

void chuta(){
    cout << "\n" << endl;
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    cout << "O seu chute foi: " << chute << endl;
        
    if(letraExiste(chute)){
        cout << "Seu chute esta correto!" << endl;
    } else {
        cout << "Seu chute nao esta correto!" << endl;
        chutesErrados.push_back(chute);
    }
        cout << " \n" << endl;
}
    
vector<string> leArquivo(){
    ifstream arquivo;
    arquivo.open("palavras.txt");
    
    int quantidadeDePalavras;
    arquivo >> quantidadeDePalavras;
    
    if(arquivo.is_open()){
        vector<string> palavrasDoArquivo;

        for(int i = 0; i < quantidadeDePalavras; i++){
            string palavraLida;
            arquivo >> palavraLida;
            palavrasDoArquivo.push_back(palavraLida);
    }

        arquivo.close();
        return palavrasDoArquivo;

    } else {
        cout << "Nao foi possivel acessar o banco de dados" << endl;
        exit(0);
    }
}

void sorteiaPalavraSecreta(){
    vector<string> palavras = leArquivo();

    srand(time(NULL));
    int indiceSorteado = rand() % palavras.size();

    palavraSecreta = palavras[indiceSorteado];
}

void salvaArquivo(vector<string> novaLista) {
    ofstream arquivo;
    arquivo.open("palavras.txt");
    if(arquivo.is_open()){
        arquivo << novaLista.size() << endl;
        
        for(string palavra : novaLista){
            arquivo << palavra << endl;
        }
        arquivo.close();
    } else {
        cout << "Nao foi possivel acessar o banco de dados";
        exit(0);
    }
}

void adicionaPalavra(){
    cout << "Digite a nova palavra usando letras maiusculas" << endl;
    string novaPalavra;
    cin >> novaPalavra;

    vector<string> listaDePalavras = leArquivo();
    listaDePalavras.push_back(novaPalavra);

    salvaArquivo(listaDePalavras);
}

int main(){
    imprimeCabecalho();
    leArquivo();
    sorteiaPalavraSecreta();

    while(!ganhou() && !enforcou()){
        imprimeErros();
        imprimePalavraSecreta();
        chuta();

    if(ganhou()){
        cout << "Voce venceu!!!!!\n" << "A palavra secreta era: " << palavraSecreta << "\n" << endl;

        cout << "Voce deseja adicionar uma nova palavra ao banco de dados? (S/N)";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adicionaPalavra();
        }

    } else if(enforcou()){
        cout << "Voce perdeu, tente novamente!\n" << "A palavra secreta era: " << palavraSecreta;
    }
    
    }
}