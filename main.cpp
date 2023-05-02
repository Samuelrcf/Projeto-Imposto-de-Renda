#include <iostream>
#include <string>
#include <cctype>
#include <locale>
#include "CotacaoMoedas.cpp"

using namespace std;

struct rendimentosTributaveis {
    float salario;
    float pensao;
    float aposentadoria;
    float aluguel;
    float rendimento_anual;
};

void maiorOuIgualaZero(float valor);
void getDadosRT(rendimentosTributaveis* ptr);
float retornaLegal(float* ptr, float* ptr2);
float retornaSimples(float* ptr);
float getValor(string msg);
float despesasDedutiveis();
void chamarImposto(float* ptr);
void chamarRestituicao(float* ptr);

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    rendimentosTributaveis rT;
    float totalRendimentoAnual;
    float totalRendimentoAnual2;
    float imposto = 0;
    string nome;
    float deducaoDD;
    float fonte;
    float restituicao;
    float descontoGov = 0.2;
    cout << "Insira o seu nome completo: ";
    getline(cin, nome);
    
    cout << endl;

    getDadosRT(&rT);

    cout << endl;

    deducaoDD = despesasDedutiveis();

    cout << endl;

    cout << "Digite o valor retido na fonte: ";
    cin >> fonte;

    cout << endl;

    totalRendimentoAnual = retornaLegal(&rT.rendimento_anual, &deducaoDD);
    totalRendimentoAnual2 = retornaSimples(&rT.rendimento_anual);

    cout << "Declaração Legal: " << endl;

    if (totalRendimentoAnual > 22847.76) {
        if (totalRendimentoAnual >= 22847.77 && totalRendimentoAnual <= 33919.80) {
            imposto = (totalRendimentoAnual * 0.075f) - 1713.58;
            restituicao = imposto - fonte;
            if (restituicao > 0) {
                chamarImposto(&imposto);
            }
            else {
                chamarRestituicao(&restituicao);
            }
        }
        else if (totalRendimentoAnual >= 33919.81 && totalRendimentoAnual <= 45012.60) {
            imposto = (totalRendimentoAnual * 0.15f) - 4257.57;
            restituicao = imposto - fonte;
            if (restituicao > 0) {
                chamarImposto(&imposto);
            }
            else {
                chamarRestituicao(&restituicao);
            }
        }
        else if (totalRendimentoAnual >= 45012.61 && totalRendimentoAnual <= 55976.16) {
            imposto = (totalRendimentoAnual * 0.225f) - 7633.51;
            restituicao = imposto - fonte;
            if (restituicao > 0) {
                chamarImposto(&imposto);
            }
            else {
                chamarRestituicao(&restituicao);
            }
        }
        else {
            imposto = (totalRendimentoAnual * 0.275f) - 10432.32;
            restituicao = imposto - fonte;
            if (restituicao > 0) {
                chamarImposto(&imposto);
            }
            else {
                chamarRestituicao(&restituicao);
            }
        }
    }
    else {
        restituicao = totalRendimentoAnual - fonte;
        if (restituicao > 0) {
            chamarImposto(&imposto);
        }
        else {
            chamarRestituicao(&restituicao);
        }
    }

    cout << "Declaração Simplificada: " << endl;

    if (totalRendimentoAnual2 > 22847.76) {
        if (totalRendimentoAnual2 >= 22847.77 && totalRendimentoAnual2 <= 33919.80) {
            imposto = (totalRendimentoAnual2 * 0.075f) - 1713.58;
            restituicao = imposto - fonte;
            if (restituicao > 0) {
                chamarImposto(&imposto);
            }
            else {
                chamarRestituicao(&restituicao);
            }
        }
        else if (totalRendimentoAnual2 >= 33919.81 && totalRendimentoAnual2 <= 45012.60) {
            imposto = (totalRendimentoAnual2 * 0.15f) - 4257.57;
            restituicao = imposto - fonte;
            if (restituicao > 0) {
                chamarImposto(&imposto);
            }
            else {
                chamarRestituicao(&restituicao);
            }
        }
        else if (totalRendimentoAnual2 >= 45012.61 && totalRendimentoAnual2 <= 55976.16) {
            imposto = (totalRendimentoAnual2 * 0.225f) - 7633.51;
            restituicao = imposto - fonte;
            if (restituicao > 0) {
                chamarImposto(&imposto);
            }
            else {
                chamarRestituicao(&restituicao);
            }
        }
        else {
            imposto = (totalRendimentoAnual2 * 0.275f) - 10432.32;
            restituicao = imposto - fonte;
            if (restituicao > 0) {
                chamarImposto(&imposto);
            }
            else {
                chamarRestituicao(&restituicao);
            }
        }
    }
    else {
        restituicao = totalRendimentoAnual2 - fonte;
        if (restituicao > 0) {
            chamarImposto(&imposto);
        }
        else {
            chamarRestituicao(&restituicao);
        }
    }
}

float retornaLegal(float* ptr, float* ptr2) {
    float total;
    cout << "Rendimento tributável anual: " << *ptr << endl;
    cout << "Despesas dedutíveis: " << *ptr2 << endl;
    total = *ptr - *ptr2;
    cout << "DEDUÇÃO: " << total << endl << endl;
    return total;
}

float retornaSimples(float* ptr) {
    float total;
    cout << "Rendimento tributável anual: " << *ptr << endl;
    total = *ptr - (*ptr * 0.2);
    cout << "DEDUÇÃO: " << total << endl << endl;
    return total;
}

void getDadosRT(rendimentosTributaveis* ptr) {

    ptr->salario = getValor("do salário");
    ptr->aposentadoria = getValor("da aposentadoria");
    ptr->aluguel = getValor("do aluguel");
    ptr->pensao = getValor("da pensão");
    ptr->rendimento_anual = ptr->salario + ptr->aposentadoria + ptr->aluguel + ptr->pensao;
}

float getValor(string msg)
{
    float valor;
    do {
        cout << "Caso haja, digite o valor " << msg << ": ";
        cin >> valor;
        if (valor < 0) {
            cout << "Valor inválido (deve ser um número maior ou igual a zero)." << endl;
        }
    } while (valor < 0);
    return valor;
}

void maiorOuIgualaZero(float valor) {
    while (valor < 0) {
        cout << "Valor inválido (deve ser um número maior ou igual a zero)." << endl;
        cin >> valor;
    }
}

float despesasDedutiveis() {

    char sn;
    int qnt_dependente;
    float pensao_alimenticia;
    float educacao;
    float saude;
    float inss;
    float desconto = 0;

    cout << "Digite o valor da contribuição previdenciária oficial: ";
    cin >> inss;
    maiorOuIgualaZero(inss);
    desconto += inss;

    cout << "Possui dependente(s)? [S/N] ";
    cin >> sn;
    sn = toupper(sn);
    if (sn == 'S') {
        cout << "Insira o número de dependentes: ";
        cin >> qnt_dependente;
        maiorOuIgualaZero(qnt_dependente);
        desconto += (qnt_dependente * 2275.08f);
    }

    cout << "Realiza pagamento de pensão alimentícia? [S/N] ";
    cin >> sn;
    sn = toupper(sn);
    if (sn == 'S') {
        cout << "Digite o valor do pagamento: ";
        cin >> pensao_alimenticia;
        maiorOuIgualaZero(pensao_alimenticia);
        desconto += pensao_alimenticia;
    }

    cout << "Possui gastos com educação? [S/N] ";
    cin >> sn;
    sn = toupper(sn);
    if (sn == 'S') {
        cout << "Digite o valor dos gastos: ";
        cin >> educacao;
        maiorOuIgualaZero(educacao);
        desconto += educacao;
    }

    cout << "Possui gastos com saúde? [S/N] ";
    cin >> sn;
    sn = toupper(sn);
    if (sn == 'S') {
        cout << "Digite o valor dos gastos: ";
        cin >> saude;
        maiorOuIgualaZero(saude);
        if (saude >= 3561.50) {
            desconto += 3561.50;
        }
        else {
            desconto += saude;
        }
    }
    return desconto;
}

void chamarImposto(float *ptr) {
    cout << "Imposto a pagar incidente nos rendimentos tributáveis: " << *ptr;
    cout << "Sem nenhum valor a restituir." << endl << endl;
}

void chamarRestituicao(float* ptr) {
    cout << "Valor a restituir: " << *ptr * (-1);
    cout << "Sem imposto a pagar." << endl << endl;
}
