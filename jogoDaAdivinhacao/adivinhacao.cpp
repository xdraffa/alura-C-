#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int numeroSecreto(){
    srand(time(NULL));
    int numeroAleatorio = rand();

    return numeroAleatorio % 100;
}

void renderizarIntroducao(){
    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao *" << endl;
    cout << "*************************************" << endl;
}

void renderizarJogoFinito(char dificuldade){
    int chute, tentativas, tentativasJogadas;
    const int NUMERO_SECRETO = numeroSecreto();

    if(dificuldade == 'F' || dificuldade == 'f'){
        tentativas = 15;
    } else if (dificuldade == 'M' || dificuldade == 'm') {
        tentativas = 10;
    } else {
        tentativas = 5;
    }
    
    while(tentativasJogadas < tentativas){
        cout << "Insira seu chute: ";
        cin >> chute;
        cout << "O valor do seu chute e " << chute << endl;

        if(chute == NUMERO_SECRETO){
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            break;
        } else if(chute > NUMERO_SECRETO){
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        } else {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
        }
        tentativasJogadas++;
    }

    cout << "Fim de jogo!" << endl;

    if(chute == NUMERO_SECRETO){
        cout << "Voce acertou o numero em: " << tentativasJogadas << " tentativas" << endl;
    } else {
        cout << "Voce chegou ao limite de tentativas, meus pesames!" << endl;
    }
}

void renderizarJogoInfinito(){
    int tentativas, chute;
    const int NUMERO_SECRETO = numeroSecreto();

    double pontos = 1000.0;
    double pontosPerdidos;

    bool acertouNumeroSecreto = chute == NUMERO_SECRETO;
    
    do{
    tentativas++;
    cout << "Tentativa: " << tentativas << endl;
        
    cout << "Insira seu chute: ";
    cin >> chute;
    cout << "O valor do seu chute e " << chute << endl;

    pontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
    pontos = pontos - pontosPerdidos;

    if(chute == NUMERO_SECRETO){
        cout << "Parabens! Voce acertou o numero secreto!" << endl;
    } else if(chute > NUMERO_SECRETO){
         cout << "Seu chute foi maior que o numero secreto!" << endl;
    } else {
        cout << "Seu chute foi menor que o numero secreto!" << endl;
    }
    } while (!acertouNumeroSecreto);

    cout << "Fim de jogo!" << endl;
    cout << "Voce acertou o numero em: " << tentativas << " tentativas" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuacao foi de: " << pontos << endl;

}

void escolha(){
    cout << "Escolha o modo de jogo: " << endl;
    cout << "Finito(F) | Infinito(I)" << endl;
    
    char escolha;
    cin >> escolha;

    if(escolha == 'F' || escolha == 'f'){
        cout << "Escolha a dificuldade: " << endl;
        cout << "FACIL(F), MEDIO(M) ou DIFICIL(D)" << endl;

        cin >> escolha;

        renderizarJogoFinito(escolha);
    } else if(escolha == 'I' || escolha == 'i'){
        renderizarJogoInfinito();
    }
}

int main(){
    renderizarIntroducao();
    escolha();
}