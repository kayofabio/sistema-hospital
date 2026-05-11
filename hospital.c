#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[20];
	int idade;
	int gravidade;
	int tipoAtendimento;
} Paciente;

int pacientesTotal = 0;
int pacientesAtendidos = 0;
int pacientesRestantes = 0;

void exibirPacienteRemovido(Paciente p) {
	printf("paciente Atendido:\nNome: %s\nIdade: %d\ngravidade: %d\nTipo de atendimento: %d\n\n", p.nome, p.idade, p.gravidade, p.tipoAtendimento);
}
 
#define MAX_SIZE_CONSULTA 5 
 
Paciente fila[MAX_SIZE_CONSULTA];  
int frente = 0; // Inicia em 0 na linear
int tras = -1; 
 
// Verifica se a filaConsulta esta vazia
int estaVaziaConsulta() {
    return frente > tras;
}
 
// Verifica se a filaConsulta esta cheia (limite do vetor)
int estaCheiaConsulta() {
    return tras == MAX_SIZE_CONSULTA - 1;
}
 
// Enfileirar (enqueue)
void enfileirarConsulta(Paciente p) {
    if (estaCheiaConsulta()) {
        printf("Erro: fila para Consulta linear cheia! (Limite do vetor atingido)\n");
        return;
    }
    tras++; 
    fila[tras] = p;
    printf("Enfileirado na consulta: %s\n", p.nome);
}
 
// Desenfileirar (dequeue)
int desenfileirarConsulta() {
    if (estaVaziaConsulta()) {
        printf("Erro: Fila para Consulta vazia!\n");
        return -1;
    }
    Paciente p = fila[frente]; 
    frente++; // Simplesmente avanca a frente
    return 0;
}
 
// Exibir a filaConsulta
void exibirfilaConsulta() {
    if (estaVaziaConsulta()) {
        printf("Fila para Consulta vazia!\n");
        return;
    }
    printf("Fila para Consulta: ");
    int i;
    for (i = frente; i <= tras; i++) {
        printf("%s ", fila[i].nome);
    }
    printf("\n");
}

#define MAX 5

Paciente pilha[MAX];// vetor que representa a pilha
int topo = -1; // controla o topo da pilha
 
// Função para empilhar (push)
void empilhar(Paciente p) {
    if (topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    topo++;
    pilha[topo] = p;
    printf("Empilhado na emergencia: %s\n", p.nome);
}
 
// Função para desempilhar (pop)
int desempilhar() {
    if (topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return -1;   // valor de erro
    }
    Paciente p = pilha[topo];
    topo--;
    return 0;
}
 
// Função para consultar o topo (peek)
int consultar_topo() {
    if (topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return 0;
}
 
// Verifica se a pilha está vazia
int esta_vazia() {
    return topo == -1;
}
 
// Verifica se a pilha está cheia
int esta_cheia() {
    return topo == MAX - 1;
}
 
// Mostrar toda a pilha (do topo até a base)
void mostrar_pilha() {
    if (esta_vazia()) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Pilha (do topo para a base): ");
    int i;
    for (i = topo; i >= 0; i--) {
        printf("%s ", pilha[i].nome);
    }
    printf("\n");
}


//Fila circular (EXAME)********************************************
 
#define MAX_SIZE 8 // Tamanho máximo da fila (pode alterar)
 
//-1 indicar que a fila tá vazia
Paciente filaCircular[MAX_SIZE]; // Vetor que armazena os elementos
int frenteCircular = -1; // Índice do primeiro elemento
int trasCircular = -1; // Índice do último elemento
 
// Verifica se a fila está vazia
int estaVazia() {
    return frenteCircular == -1;
}
 
// Verifica se a fila está cheia (versão circular)
int estaCheia() {
    return (frenteCircular == (trasCircular + 1) % MAX_SIZE);
}
 
// Enfileirar (enqueue)
void enfileirar(Paciente p) { //fila[0] = 10 fila[1]=20 fila[2]=30 fila[3]=40 fila[4]=50
 
    if (estaCheia()) {
        printf("Erro: Fila cheia! Não é possível enfileirar %d.\n", p.nome);
        return;
    }
 
    if (estaVazia()) {
        frenteCircular = 0; // Primeira inserção
    }
 
    trasCircular = (trasCircular + 1) % MAX_SIZE;
    filaCircular[trasCircular] = p;
    printf("Enfileirado no exame: %s\n", p.nome);
}
 
// Desenfileirar (dequeue) - retorna o valor removido
int desenfileirar() {
    if (estaVazia()) {
        printf("Erro: filaCircular vazia! Nada para desenfileirar.\n");
        return -1; // Valor de erro
}
 
    Paciente p = filaCircular[frenteCircular]; // filaCircular[0] = 10 fila[1]=20
 
    if (frenteCircular == trasCircular) {
        // Era o último elemento
        frenteCircular = -1;
        trasCircular = -1;
    } else {
        frenteCircular = (frenteCircular + 1) % MAX_SIZE;
    }
 
    return 0;
}
 
// Consultar o elemento da frenteCircular (sem remover)
int consultarfrente() {
    if (estaVazia()) {
        printf("Fila vazia!\n");
        return -1;
    }
    printf("%s", filaCircular[frenteCircular].nome);
    return 0;
}
 
// Exibir a fila
void exibirFila() {
    if (estaVazia()) {
        printf("Fila vazia!\n");
        return;
    }
 
    printf("Fila: ");
    int i = frenteCircular; //pq eu havia tirado dois elementos -- frenteCircular=2 pos ou indice, valor do indice, valor da posicao, elemento 
    while (i != trasCircular) {
        printf("%s ", filaCircular[i].nome);
        i = (i + 1) % MAX_SIZE; //pois usa módulo (resto da divisão) fazer em qualque LP use lista ou vetor
    }
    printf("%s\n", filaCircular[trasCircular].nome); // imprime o último
}


int main() {
	printf("Hospital");
	int acao, sair = 1;
	while (sair) {
		printf("\n1- cadastrar paciente\n2- atender paciente\n3- mostrar pacientes\n4- transferir paciente\n5- relatorios\n6- sair");
		printf("\n>> ");
		scanf("%d", &acao);
		if (acao == 1) {
			char nome[20];
			int idade, gravidade, tipoAtendimento;
			Paciente p;
			printf("Preecha os dados do paciente:\n");
			printf("Nome: ");
			scanf("%s", &nome);
			printf("Idade: ");
			scanf("%d", &idade);
			printf("gravidade (1-5): ");
			scanf("%d", &gravidade);
			printf("tipo de atendimento (1: emergencia | 2: consulta | 3: exame): ");
			scanf("%d", &tipoAtendimento);
			strcpy(p.nome, nome);
			p.idade = idade;
			p.gravidade = gravidade;
			p.tipoAtendimento = tipoAtendimento;
			if (gravidade == 4 || gravidade == 5 || tipoAtendimento == 1) {
				empilhar(p);
			}
			else if (tipoAtendimento == 2) {
				enfileirarConsulta(p);
			}
			else if (tipoAtendimento == 3) {
				if (estaCheia()) {
					Paciente pRemovido = filaCircular[frenteCircular];
					desenfileirar();
					pacientesAtendidos++;
					pacientesRestantes--;
					exibirPacienteRemovido(pRemovido);
				}
				enfileirar(p);
			}
			pacientesTotal++;
			pacientesRestantes++;
		}
		if (acao == 2) {
			printf("Qual departamento atender?\n1- emergencia | 2- consulta | 3- exame");
			int atendimento;
			printf("\n>> ");
			scanf("%d", &atendimento);
			Paciente p;
			if (atendimento == 1) {
				p = pilha[topo];
				int sucesso = desempilhar();
				if (sucesso == 0) {
					pacientesAtendidos++;
					pacientesRestantes--;
					exibirPacienteRemovido(p);
				}
			} else if (atendimento == 2) {
				p = fila[frente];
				int sucesso = desenfileirarConsulta();
				if (sucesso == 0) {
					pacientesAtendidos++;
					pacientesRestantes--;
					exibirPacienteRemovido(p);
				}
			} else if (atendimento == 3) {
				p = filaCircular[frenteCircular];
				int sucesso = desenfileirar();
				if (sucesso == 0) {
					pacientesAtendidos++;
					pacientesRestantes--;
					exibirPacienteRemovido(p);
				}
			}
		}
		if (acao == 3) {
			printf("Exibir qual departamento?\n1- emergencia | 2- consulta | 3- exame");
			int departamento;
			printf("\n>> ");
			scanf("%d", &departamento);
			if (departamento == 1) {
				mostrar_pilha();
			} else if (departamento == 2) {
				exibirfilaConsulta();
			} else if (departamento == 3) {
				exibirFila();
			}
		}
		if (acao == 4) {
			printf("\nDe qual departamento trasferir?\n1- emergencia | 2- consulta | 3- exame");
			int departamento;
			Paciente p;
			printf("\n>> ");
			scanf("%d", &departamento);
			if (departamento == 1) {
				if (esta_vazia()) {
					printf("ninguem para transferir");
					continue;
				}
				p = pilha[topo];
				desempilhar();
			} else if (departamento == 2) {
				if (estaVaziaConsulta()) {
					printf("ninguem para transferir");
					continue;
				}
				
				p = fila[frente];
				desenfileirarConsulta();
			} else if (departamento == 3) {
				if (estaVazia()) {
					printf("ninguem para transferir");
					continue;
				}
				p = filaCircular[frenteCircular];
				desenfileirar();
			}
			
			
			
			printf("\nPara qual departamento trasferir?\n1- emergencia | 2- consulta | 3- exame");
			int transferir;
			printf("\n>> ");
			scanf("%d", &transferir);
			if (transferir == 1) {
				empilhar(p);
			} else if (transferir == 2) {
				enfileirarConsulta(p);
			} else if (transferir == 3) {
				enfileirar(p);
			}
		}
		if (acao == 5) {
			printf("\ntotal de pacientes do dia: %d\n", pacientesTotal);
			printf("total de pacientes atendidos: %d\n", pacientesAtendidos);
			printf("total de pacientes para serem atendidos: %d\n", pacientesRestantes);
		}
		if (acao == 6) {
			sair = 0;
		}
	}
	printf("\n\nFIM DO PROGRAMA\n");
	return 0;
}
