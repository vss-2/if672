import java.util.Scanner;

class dadosPaciente{
	int Urg, Idade, Ordem;
	dadosPaciente(int X, int Y, int Z){
		Urg = X;
		Idade = Y;
		Ordem = Z;
	}
}

class Heaps{
	int tamanho, tamanhoHeap;
	// Tem que ter um desses para
	// saber se dobro o tamanho
	dadosPaciente[] modelo;
	
	Heaps(int tam){
		modelo = new dadosPaciente[tam];
		tamanho = tam;
		tamanhoHeap = 0;
	}
	
	void dobrarTamanho() {
		dadosPaciente[] temporario;
		temporario = this.modelo;
		this.modelo = new dadosPaciente[2*tamanho];
		
		for(int i = 0; i < this.tamanho; i++) {
			this.modelo[i] = temporario[i];
		}
		
		this.tamanho = 2*this.tamanho;
	}
	
	void organizarCima(int val) {
		int meioU = this.modelo[(val-1)/2].Urg;
		int meioI = this.modelo[(val-1)/2].Idade;
		int meioO = this.modelo[(val-1)/2].Ordem;
		
		dadosPaciente swap = new dadosPaciente(0, 0, 0);
				
		while(val > 0 && this.modelo[val].Urg >= meioU){
			if(this.modelo[val].Urg == meioU) {
				break;
			} else if (this.modelo[val].Urg == meioU && this.modelo[val].Idade == meioI && this.modelo[val].Ordem == meioO){
				break;
			}
			
			// Faço a troca padrão
			int noPai = (val-1)/2;
			swap = this.modelo[val];
			this.modelo[val] = modelo[noPai];
			this.modelo[noPai] = swap;
			val = noPai;
		}
	}
	
	void inserirPaciente(dadosPaciente inserido){
		if(this.tamanhoHeap == this.tamanho) {
			this.dobrarTamanho();
		}
		modelo[this.tamanhoHeap] = inserido;
		this.tamanhoHeap++;
		this.organizarCima(this.tamanhoHeap - 1);
	}
	
	void heapify(int input){
		int meio = input;
		int esq = 2*input + 1;
		int dir = 2*input + 2;
		
		dadosPaciente swap = new dadosPaciente(0, 0, 0);
		
		if(esq < this.tamanhoHeap && this.modelo[esq].Urg >= this.modelo[meio].Urg){
			if(this.modelo[esq].Urg == this.modelo[meio].Urg) {
				if(this.modelo[esq].Idade > this.modelo[meio].Ordem) {
					meio = esq;
				}
			} else if(this.modelo[esq].Idade == this.modelo[meio].Idade) {
				if(this.modelo[esq].Ordem < this.modelo[meio].Ordem) {
					meio = esq;
				}
			}
		} else {
			meio = esq;
		}
		
		if(dir < this.tamanhoHeap && this.modelo[dir].Urg >= this.modelo[meio].Urg){
			if(this.modelo[dir].Urg == this.modelo[meio].Urg) {
				if(this.modelo[dir].Idade > this.modelo[meio].Ordem) {
					meio = dir;
				}
			} else if(this.modelo[dir].Idade == this.modelo[meio].Idade) {
				if(this.modelo[dir].Ordem < this.modelo[meio].Ordem) {
					meio = dir;
				}
			}
		} else {
			meio = dir;
		}
		
		if(meio != input) {
			swap = this.modelo[input];
			this.modelo[input] = modelo[meio];
			this.modelo[meio] = swap;
			input = meio;
		}
	}
	
	dadosPaciente atenderPaciente(){
		dadosPaciente removido = this.modelo[0];
		
		this.modelo[0] = this.modelo[this.tamanhoHeap - 1];
		this.modelo[this.tamanhoHeap - 1] = null;
		
		this.tamanhoHeap--;
		
		this.heapify(0);
		
		return removido;
	}
}

public class Main{
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int S, I, U, A, OC;
		String entrada;
		S = in.nextInt();
		
		Heaps hospital[] = new Heaps[S];
		
		for(int contador = 0; contador < S; contador++) {
			hospital[contador] = new Heaps(3);
			// Criando as tres heaps para Idade, Urgencia 
			// e Ordem de Chegada
		}
		
		OC = 0;
		
		while(in.hasNext()) {
			entrada = in.next();
			if(entrada.equals("CIN")) {
				// Cadastro de paciente
				I = in.nextInt();
				U = in.nextInt();
				A = in.nextInt();
				
				dadosPaciente entrando = new dadosPaciente(I, U, OC);
				OC++;
				
				hospital[A].inserirPaciente(entrando);
			} else if(entrada.equals("NXT")) {
				// Atendimento padrão
				A = in.nextInt();
				
				if(hospital[A].modelo[0] != null){
					dadosPaciente temp2 = hospital[A].atenderPaciente();
					System.out.printf("%d %d %d\n", A, temp2.Idade, temp2.Urg);
				} else {
					System.out.println("-1 -1 -1");
				}
			} else if(entrada.equals("STD")) {
				// Atendimento por estudante
				int contador2 = 0, posicao = 0;
				
				dadosPaciente menorRisco = new dadosPaciente(99999, 99999, 99999);
				
				while(contador2 < S) {
					if(hospital[contador2].modelo[0] == null) {
						if(hospital[contador2].modelo[0] != null) {
							menorRisco = hospital[contador2].modelo[0];
							posicao = contador2;
						} else if((hospital[contador2].modelo[0].Urg == menorRisco.Urg) && (hospital[contador2].modelo[0].Idade == menorRisco.Idade))  {
							menorRisco = hospital[contador2].modelo[0];
							posicao = contador2;
						} else if((hospital[contador2].modelo[0].Urg == menorRisco.Urg) && (hospital[contador2].modelo[0].Idade == menorRisco.Idade) && (hospital[contador2].modelo[0].Ordem == menorRisco.Ordem)) {
							menorRisco = hospital[contador2].modelo[0];
							posicao = contador2;
						}
						contador2++;
					}
				}
				
				if(hospital[posicao].modelo[0] != null) {
					dadosPaciente temp3 = hospital[posicao].atenderPaciente();
					System.out.printf("%d %d %d\n", posicao, temp3.Urg, temp3.Idade);
				} else {
					System.out.println("-1 -1 -1");
				}
			}
		}
	}
}
