#include "menu.h"

void iniciarMenu(){
    int option;
    cout << "Bem vindo!" << endl;
    list<Empresa> empresas;
    list<Funcionario> funcionarios;
    do{        
        option = escolherOpcao();       
        switch(option){
            case 1: {
                Empresa empresa = criarEmpresa();
                empresas.push_back(empresa);  
                cout << empresa;
                cout << "Empresa cadastrada com sucesso!" << endl;     
                break;
            }
                
            case 2: {
                Funcionario funcionario = criarFuncionario();
                adicionarFuncionario(empresas, funcionario);
                funcionarios.push_back(funcionario);               
                cout << "Funcionário adicionado com sucesso!" << endl;
                break;
            }                
            case 3:
                listarFuncionarios(empresas);
                break;
            case 4:
                aplicarAumento(empresas);
                cout << "Aumento aplicado com sucesso!" << endl;
                break;
            case 5:
                listarMediaFuncionarios(empresas);
                break;
            default: break;
        }       
    }while(option != 0);    
}

int escolherOpcao(){
    set<int> options = {0,1,2,3,4,5,6};
    int op;
    cout << "--- MENU PRINCIPAL ---" << endl;
    cout << "1 - criar empresa" << endl;
    cout << "2 - adicionar funcionaro" << endl;
    cout << "3 - listar funcionarios" << endl;
    cout << "4 - aplicar aumento" << endl;
    cout << "5 - listar média de funcionários" << endl;
    cout << "0 - sair"<<endl;
    cin >> op;
    const bool opValida = options.find(op) != options.end();
    if (opValida){
        return op;
    } else {
        cout << "Opção inválida!" << endl;
        return -1;
    }
}
