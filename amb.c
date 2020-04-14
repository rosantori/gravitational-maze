/* @file: 160047269.c
	@matricula: 16/0047269
	@author: Rosana Santos Ribeiro
	 @disciplina: Algoritmos e Programação de Computadores
	  @atividade: Trabalho 2 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void procurarcolunaelinhadeahm(char v[22][22], int F, char jogador, int *linha, int *coluna) {
	int i=0, j=0;

	while (v[i][j] != jogador && i < F) {
		
		while (v[i][j] != jogador && j < F) {
			++j;
		}
		if(j==F) j=0;
		if(v[i][j] != jogador) ++i;
	}
	
	*linha = i;
	*coluna = j;
	
	return ;
}

int jogo( char objetivo, char parede, char referencial, char jogador,
           char horario, char antihorario, int F) {
	char v[22][22], vaux[22], vaux2[22][22], jogada, horario2, antihorario2;
	int i, j, linhajogador=0, colunajogador=0, numeromapa;
	srand(time(NULL));
	numeromapa =  rand () % 12;

	if(antihorario <= 'z' && antihorario >= 'a') antihorario2 = antihorario - ('a' - 'A');
	else if(antihorario <= 'Z' && antihorario >= 'A') antihorario2 = antihorario + ('a' - 'A');
	else antihorario2 = antihorario;


	if(horario <= 'z' && horario >= 'a') horario2 = horario - ('a' - 'A');
	else if(horario <= 'Z' && horario >= 'A') horario2 = horario + ('a' - 'A');
	else horario2 = horario;
	
	printf("\e[1;1H\e[2J");

		/* preenche o labirinto com espaços vazios */
	for(i=0; i<F; i++) {
		for(j=0; j<F; j++) {
			v[i][j] = ' ';
			
		}
	}

	/* Coloca as paredes do labirinto */

	for (j=0; j < F; j++) {
		v[0][j] = parede;
		v[F-1][j] = parede; 
		v[j][0] = parede;    
		v[j][F-1] = parede;  
	}

	v[0][0]= referencial;
	
	
	if(F==12) {
		if(numeromapa%3 == 0) {
			v[10][2] = jogador;
			v[10][4] = objetivo;
			v[3][1] = parede;
			v[1][5] = parede;
			v[4][7] = parede;
			v[4][4] = parede;
			v[5][2] = parede;
			v[6][10] = parede;
			v[7][1] = parede;
			v[8][3] = parede;
			v[8][9] = parede;
			v[9][2] = parede;
			v[10][3] = parede;
		} else if (numeromapa%3 == 1) {
			v[1][2] = parede;
			v[1][7] = parede;
			v[2][2] = parede;
			v[2][4] = parede;
			v[3][6] = parede;
			v[4][1] = parede;
			v[6][6] = objetivo;
			v[7][3] = parede;
			v[7][8] = parede;
			v[9][5] = parede;
			v[3][1] = jogador; 
		} else if (numeromapa%3 == 2) {
			v[10][8] = parede;
			v[5][7] = parede;
			v[6][8] = parede;
			v[6][2] = parede;
			v[2][3] = parede;
			v[3][10] = parede;
			v[4][8] = parede;
			v[1][9] = parede;
			v[1][10] = objetivo;
			v[10][1] = jogador;
		}
	}
	if (F==17) {
		if(numeromapa%4 == 0 ) {
			v[3][2] = jogador;
			v[13][14] = objetivo;
			v[1][5] = parede;
			v[1][10] = parede;
			v[3][14] = parede;
			v[5][1] = parede;
			v[5][8] = parede;
			v[6][4] = parede;
			v[8][2] = parede;
			v[8][12] = parede;
			v[9][6] = parede;
			v[13][1] = parede;
			v[14][7] = parede;
		} else if (numeromapa%4 == 1) {
			v[1][2] = parede;
			v[1][7] = parede;
			v[2][11] = parede;
			v[2][4] = parede;
			v[3][6] = parede;
			v[4][1] = parede;
			v[7][13] = parede;
			v[7][3] = parede;
			v[7][8] = parede;
			v[9][5] = parede;
			v[9][1] = jogador;
			v[2][15] = parede;
			v[4][8] = parede;
			v[5][3] = parede;
			v[5][7] = parede;
			v[5][11] = parede;
			v[9][12] = parede;
			v[10][5] = parede;
			v[11][5] = parede;
			v[12][5] = parede;
			v[13][5] = parede;
			v[14][5] = parede;
			v[15][9] = parede;
			v[11][9] = parede;
			v[9][11] = parede;
			v[10][12] = parede;
			v[15][10] = objetivo;
		} else if (numeromapa%4 == 2) {
				v[3][8] = jogador;
				v[4][8] = objetivo;
				v[1][6] = parede;
				v[2][8] = parede;
				v[3][1] = parede;
				v[3][12] = parede;
				v[4][6] = parede;
				v[4][14] = parede;
				v[5][8] = parede;
				v[6][8] = parede;
				v[7][8] = parede;
				v[8][10] = parede;
				v[9][2] = parede;
				v[10][15] = parede;
				v[11][11] = parede;
				v[14][3] = parede;
				v[14][7] = parede;
		} else if (numeromapa%4 == 3) {
			v[3][3] = jogador;
			v[13][13] = objetivo;
			v[1][3] = parede;
			v[1][7] = parede;
			v[1][13] = parede;
			v[2][8] = parede;
			v[3][2] = parede;
			v[6][7] = parede;
			v[7][3] = parede;
			v[9][14] = parede;
			v[10][1] = parede;
			v[12][6] = parede;v[6][8] = parede;
			v[12][13] = parede;
			v[12][15] = parede;
			v[13][12] = parede;
			v[15][4] = parede;
		}

		}
		
	


		 if ( F == 22) {
		 	
		v[8][10] = jogador;
		v[2][19] = objetivo;
		v[1][1] = parede;
		v[1][11] = parede;
		v[1][14] = parede;
		v[2][12] = parede;
		v[3][15] = parede;
		v[3][20] = parede;
		v[4][3] = parede;
		v[4][13] = parede;
		v[5][4] = parede;
		v[6][15] = parede;
		v[7][12] = parede;
		v[8][6] = parede;
		v[8][14] = parede;
		v[8][17] = parede;
		v[9][2] = parede;
		v[10][5] = parede;
		v[11][13] = parede;
		v[12][14] = parede;
		v[14][18] = parede;
		v[15][16] = parede;
		v[16][8] = parede;
		v[19][3] = parede;
		v[19][10] = parede;
		v[19][19] = parede;
		v[19][20] = parede;
		v[20][11] = parede;
		v[20][15] = parede;
		} 
		
	


	for(i=0; i<F; i++) {
		for(j=0; j<F; j++) {
			printf("%c ", v[i][j]);
		}
		printf("\n");
		
	}
	printf("  PARA DESISTIR, TECLE '=' !\n\n");

	while (v[linhajogador+1][colunajogador] != objetivo) {
		do {
			printf("Girar sentido anti-horário [%c] ou horario [%c]??\n ", antihorario, horario);
			do {  scanf("%c", &jogada);}	while (jogada == ' ' || jogada == '\n');
				if (jogada == '=') return 1;
		} while (jogada != horario && jogada != antihorario && jogada != horario2 && jogada != antihorario2);

	
			sleep(1/2);
			printf("\e[1;1H\e[2J");

		if ( jogada == horario || jogada == horario2) {
			for(i=0; i<F; i++) {
				for(j=0; j<F; j++) {
					vaux2[i][j] = v[i][j];
				}
			}

			for(i=0; i < F; i++) {
				for (j=0; j<F; j++) {		
					vaux[j] = vaux2[i][j];
					v[j][(F-1)-i] = vaux[j];

				}	
			}

			for(i=0; i<F; i++) {
				for(j=0; j<F; j++) {
					printf("%c ", v[i][j]);
				}
				printf("\n");
			}

			
		


		} else if (jogada == antihorario || jogada == antihorario2) {
			for(i=0; i<F; i++) {
				for(j=0; j<F; j++) {
					vaux2[i][j] = v[i][j];
				}
			}

			for(i=0; i < F; i++) {
				for (j=0; j<F; j++) {
			
					vaux[(F-1)-j] = vaux2[i][(F-1)-j];
					v[j][i] = vaux[(F-1)-j];

				}	
			}


			for(i=0; i<F; i++) {
				for(j=0; j<F; j++) {
					printf("%c ", v[i][j]);
				}
			printf("\n");
			}

		}


		sleep(1);
		printf("\e[1;1H\e[2J");

		procurarcolunaelinhadeahm (v, F, jogador, &linhajogador, &colunajogador);
		if(v[linhajogador + 1 ][colunajogador] == parede) {
			for(i=0; i < F; i++) {
				for (j=0; j < F; j++){
					printf("%c ", v[i][j]);
				}
				printf("\n");
			}
		}

		while(v[linhajogador + 1][colunajogador] == ' ' ) {
			v[linhajogador][colunajogador] = ' ';
			v[linhajogador+1][colunajogador] = jogador;
			linhajogador++;
		

			for(i=0; i<F; i++) {
				for(j=0; j<F; j++) {
					printf("%c ", v[i][j]);
				}
				printf("\n");
			}
			sleep(0.5);
			if(v[linhajogador + 1][colunajogador] == ' ') printf("\e[1;1H\e[2J");
		}
	}

	v[linhajogador][colunajogador] = ' ';
	v[linhajogador + 1][colunajogador] = 'x';
	
	printf("\e[1;1H\e[2J");
	for(i=0; i<F; i++) {
		for(j=0; j<F; j++) {
			printf("%c ", v[i][j]);
			}
		printf("\n");
	}
	

	return 0;
}

		
	

void configuracaovisual(char *objetivo, char *parede, char *referencial, char *jogador) {
	char escolha;
	
		printf("        ______________________________________               \n");
		printf("*******|                                      |*******\n");
		printf("*******|          CONFIGURAÇÃO VISUAL         |*******\n");
		printf("*******|                                      |*******\n");
		printf("*******|   1) OBJETIVO : %c                    |*******\n", *objetivo);
		printf("*******|   2) PAREDE : %c                      |*******\n", *parede);
		printf("*******|   3) REFERENCIAL : %c                 |*******\n", *referencial);
		printf("*******|   4) JOGADOR : %c                     |*******\n", *jogador);
		printf("*******|                                      |*******\n");
		printf("*******|                                      |*******\n");
		printf("*******|   0) VOLTAR                          |*******\n");
		printf("*******|                                      |*******\n");
		printf("*******|______________________________________|*******\n");

		printf("\n O que você deseja mudar?? ");
	  do {  scanf("%c", &escolha);}	while (escolha == ' ' || escolha == '\n');
	   switch(escolha) {
	   	case '1': 
	   		printf("Digite o novo caracter para 'objetivo' : ");
	   		do {  scanf("%c", objetivo);}	while (*objetivo == ' ' || *objetivo == '\n');
	   		printf("\e[1;1H\e[2J");
	   		configuracaovisual(objetivo, parede, referencial, jogador);
	   		break;
	   	case '2':
	   		printf("Digite o novo caracter para 'parede' : ");
	   		do {  scanf("%c", parede);}	while (*parede == ' ' || *parede == '\n');
	   		printf("\e[1;1H\e[2J");
	   		configuracaovisual(objetivo, parede, referencial, jogador);
	   		break;
	   	case '3':
	   		printf("Digite o novo caracter para 'referencial' : ");
	   		do {  scanf("%c", referencial);}	while (*referencial == ' ' || *referencial == '\n');
	   		printf("\e[1;1H\e[2J");
	   		configuracaovisual(objetivo, parede, referencial, jogador);
	   		break;
	   	case '4':
	   		printf("Digite o novo caracter para 'jogador' : ");
	   		do {  scanf("%c", jogador);}	while (*jogador == ' ' || *jogador == '\n');
	   		printf("\e[1;1H\e[2J");

	   		configuracaovisual(objetivo, parede, referencial, jogador);
	   		break;
	   	case '0':
	   		printf("\e[1;1H\e[2J");
	   		break;
	   	default:
	   		printf("\e[1;1H\e[2J");
	   		printf("Opção inválida.\n");
	   		sleep (1);
	   		configuracaovisual(objetivo, parede, referencial, jogador);
	   		break;
	   


	} while (objetivo == jogador || objetivo == referencial || objetivo == parede || jogador == parede);
	return;
}
void configuracaocontroles(char* horario, char* antihorario) {
	char escolha;

	do       {
		printf("        ______________________________________               \n");
		printf("*******|                                      |*******\n");
		printf("*******|              CONTROLES               |*******\n");
		printf("*******|                                      |*******\n");
		printf("*******|                                      |*******\n");           
		printf("*******|   1) GIRAR HORÁRIO : %c               |*******\n", *horario);
		printf("*******|   2) GIRAR ANTI-HORÁRIO : %c          |*******\n", *antihorario);
		printf("*******|                                      |*******\n");               
		printf("*******|                                      |*******\n");
		printf("*******|                                      |*******\n");
		printf("*******|   0) VOLTAR                          |*******\n");
		printf("*******|                                      |*******\n");
		printf("*******|______________________________________|*******\n");
		printf("\n O que você deseja mudar?? ");

		do {  scanf("%c", &escolha);}	while (escolha == ' ' || escolha == '\n');
   
	   	switch(escolha) {
	   	case '1': 
	   		printf("Digite o novo comando para 'girar no sentido horário' : ");
	   		do {  scanf("%c", horario);}	while (*horario == ' ' ||  *horario == '\n');
	   		printf("\e[1;1H\e[2J");
	   		
	   		break;
	   	case '2':
	   		printf("Digite o novo comando para 'girar no sentido anti-horário' : ");
	   		do {  scanf("%c", antihorario);}	while (*antihorario == ' ' || *antihorario == '\n');
	   		printf("\e[1;1H\e[2J");
	   		
	   		break;
	   	case '0':
	   	printf("\e[1;1H\e[2J");
	   		break;
	   	default:
	   	printf("\e[1;1H\e[2J");
	   		printf("Opção inválida.\n");
	   		escolha = '6';
	   		sleep (1);
	      		

	   	}
	   	if(*horario == *antihorario) {
	   		printf("OPA! O mesmo comando não pode!! Tá querendo me complicar, né... -.-'' \n");
	   		sleep (1.5);
	   		
	   	}
	   	

   } while((*horario == *antihorario && escolha ==  '0') || escolha == '6' || escolha != '0');
   


	return;
}


int main () {
	char escolha, escolhaconf;
	char  objetivo = '0', parede = '#', referencial = 'R',
	 jogador = 'o', horario = 'd', antihorario = 'a', escolhadif = '1', fimjogo, t, antihorario2, horario2;
	 int brilho;
	
	printf("\e[1;1H\e[2J");

	do {
		printf("        ______________________________________        \n");
		printf("*******|                                      |*******       \n");
		printf("*******|             AmbAmbirinto             |*******       \n");
		printf("*******|                                      |*******       \n");
		printf("*******|                                      |*******       \n");
		printf("*******|    1) JOGAR                          |*******       \n");
		printf("*******|                                      |*******       \n");
		printf("*******|    2) CONFIGURAÇÕES                  |*******       \n");
		printf("*******|                                      |*******       \n");
		printf("*******|    3) SAIR                           |*******       \n");
		printf("*******|                                      |*******       \n");
		printf("*******|______________________________________|*******       \n");
		printf("                                                      \n");

		do {  scanf("%c", &escolha);}	while (escolha == ' ' || escolha == '\n');

		
		printf("\e[1;1H\e[2J");

		switch (escolha) {
			case '1': 
				if (escolhadif == '1' )
					fimjogo = jogo (objetivo, parede, referencial, jogador, horario, antihorario, 12);
				if (escolhadif == '2')
					fimjogo = jogo (objetivo, parede, referencial, jogador, horario, antihorario, 17);
				if (escolhadif == '3')
					fimjogo = jogo (objetivo, parede, referencial, jogador, horario, antihorario, 22);

				if (fimjogo == 0){
					getchar();
					sleep (1);
					printf("\e[1;1H\e[2J");
					for(brilho=0; brilho < 5; brilho++){
						printf("                                         _o_o_                                 \n");
						printf("            oooo         oooo   °        | P |       °                         \n");
						printf("     °    *0****0*     *0****0*         o| A |o                                \n");
						printf("  °      0********0   0********0     °   | R |            °                    \n");
						printf("       *0**********0 0**********0*      o| A |o    °                           \n");
						printf("       0************0************0       | B |                                 \n");
						printf("  °    *0***********************0*   °  o| É |o                                \n");
						printf("         *0*******************0*         | N |   °         °                   \n");
						printf("           *0***************0*          o| S |o                                \n");
						printf("   °    °    *0***********0*             |___|                                 \n");
						printf("               *0*******0*       °         I        °                          \n");
						printf("      %c     °    *0***0*              °    I                                  \n",jogador);
						printf("   /O/             *0*         °           I             °                     \n");
						printf("   ||      °        0                °     I      °                            \n");
						printf("__//\\\\_____________________________________I______________                   \n");
						printf("\n\n\t      VOCÊ RECUPEROU AMB AMB!!!!!!!!                                           \n");
						sleep(0.1);
						printf("\e[1;1H\e[2J");


						printf("                                      .  o_o_o   .                             \n");
						printf("   .   .    ****         ****           o| P |o     .      .                   \n");
						printf("          ********     ********         .| A |                                 \n");
						printf("  .      **********   **********     .  o| R |o .        .                     \n");
						printf("       ************* *************      .| A |     .   .                       \n");
						printf("       ***************************      o| B |o                                \n");
						printf("    .  ***************************      .| É | .   .   .    .                  \n");
						printf("         ***********************      . o| N |o                                \n");
						printf(" .   .     *******************     .     | S |    .     .                      \n");
						printf("             ***************            o|___|o      .                         \n");
						printf("  .        .   ***********  .        .     I              .                    \n");
						printf("  %c              *******                   I    .    .                        \n",jogador);
						printf("  \\O\\     .  .     ***        .    .    .  I   .    .                        \n");
						printf("   ||      .        *     .                I    .   .                          \n");
						printf("__//\\\\_____________________________________I______________                   \n");
						printf("\n\n\t      VOCÊ RECUPEROU AMB AMB!!!!!!!!                                     \n");
						if(brilho < 9) {
							sleep(0.1);
							printf("\e[1;1H\e[2J");
						}
					} 
	printf("\n\n\nPressione 'Enter' para voltar ao menu. \n");
	do {
		t = getchar();
	}while (t != '\n');
	printf("\e[1;1H\e[2J"); 
				} else if (fimjogo == 1) {
					printf("\e[1;1H\e[2J");
						printf ("                                                                \n");
						printf ("     AMB morreu de solidão....                                  \n");
						printf ("                                     e de desgosto...           \n");
						printf ("             ____________________________                       \n");
						printf ("            |                            |                      \n");
						printf ("            | POR QUE ME ABANDONASTE???? |                      \n");
						printf ("            |__     _____________________|                      \n");
						printf ("               |   /                                            \n");
						printf ("               |  /                                             \n");
						printf ("               | /                                              \n");
						printf ("               |/                                               \n");
						printf ("               %c                                                \n", jogador);
						printf ("                                                                \n\n");

						printf("\n\n\nPressione 'Enter' para voltar ao menu. \n");
						getchar();
	do {
		t = getchar();
	}while (t != '\n');
	printf("\e[1;1H\e[2J");
					}
				break;
			case '2':
					do {
						printf("        ______________________________________               \n");
						printf("*******|                                      |*******\n");
						printf("*******|             CONFIGURAÇÕES            |*******\n");
						printf("*******|                                      |*******\n");
						printf("*******|                                      |*******\n");           
						printf("*******|   1) CONFIGURAÇÃO VISUAL             |*******\n");             
						printf("*******|   2) CONTROLES                       |*******\n");                 
						printf("*******|   3) DIFICULDADE                     |*******\n");               
						printf("*******|                                      |*******\n");
						printf("*******|                                      |*******\n");
						printf("*******|   0) VOLTAR                          |*******\n");
						printf("*******|                                      |*******\n");
						printf("*******|______________________________________|*******\n");
						printf("\n O que você deseja? ");
						do {  scanf("%c", &escolhaconf);}	while (escolhaconf == ' ' || escolhaconf == '\n');

						
						printf("\e[1;1H\e[2J");

						switch(escolhaconf) {
							case '1': 
								do {
									configuracaovisual(&objetivo, &parede, &referencial, &jogador);
									if(objetivo == ' ') printf("Você é realmente DO MAL! Assim, o AMB vai ficar preso eternamente u.u!!! objetivo tem que ser diferente de 'espaço'\n");
									 if(objetivo == jogador || objetivo == referencial || objetivo == parede || jogador == parede ) printf("Háháhá, muito engraçado!! Nem o objetivo nem o jogador podem \nser iguais aos outros componentes!!!\n");
								} while(objetivo == jogador || objetivo == referencial || objetivo == parede || jogador == parede || objetivo == ' ');
								break;
							case '2':
								do {
									configuracaocontroles(&horario, &antihorario);
									if(antihorario <= 'z' && antihorario >= 'a') antihorario2 = antihorario - ('a' - 'A');
									else if(antihorario <= 'Z' && antihorario >= 'A') antihorario2 = antihorario + ('a' - 'A');
									else antihorario2 = antihorario;


									if(horario <= 'z' && horario >= 'a') horario2 = horario - ('a' - 'A');
									else if(horario <= 'Z' && horario >= 'A') horario2 = horario + ('a' - 'A');
									else horario2 = horario;
	
									if (horario == '=' || antihorario == '=') printf("O Comando '=' é usado para desistência, use outra tecla.\n");


									if(antihorario == horario2 || horario == antihorario2) printf("Lembre-se que 'a' e 'A' são o mesmo comando...\n");
								} while (antihorario == '=' || horario == '=' || antihorario == horario2 || horario == antihorario2 );
								break;
							case '3':
								printf("\e[1;1H\e[2J");

								do {
									
									if (escolhadif == '1'){
										printf("        ______________________________________               \n");
										printf("*******|                                      |*******\n");
										printf("*******|             DIFICULDADE              |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");           
										printf("*******|   1) FÁCIL      (10x10)    <-        |*******\n");             
										printf("*******|   2) MÉDIO      (15x15)              |*******\n");                 
										printf("*******|   3) DIFÍCIL    (20x20)              |*******\n");               
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|______________________________________|*******\n");
									} else if (escolhadif == '2') {
										printf("        ______________________________________               \n");
										printf("*******|                                      |*******\n");
										printf("*******|             DIFICULDADE              |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|   1) FÁCIL      (10x10)              |*******\n");
										printf("*******|   2) MÉDIO      (15x15)    <-        |*******\n");                 
										printf("*******|   3) DIFÍCIL    (20x20)              |*******\n");               
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|______________________________________|*******\n");
									} else if (escolhadif == '3' ) {
										printf("        ______________________________________               \n");
										printf("*******|                                      |*******\n");
										printf("*******|             DIFICULDADE              |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");           
										printf("*******|   1) FÁCIL      (10x10)              |*******\n");             
										printf("*******|   2) MÉDIO      (15x15)              |*******\n");                 
										printf("*******|   3) DIFÍCIL    (20x20)    <-        |*******\n");               
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|______________________________________|*******\n");
									} else {
										printf("        ______________________________________               \n");
										printf("*******|                                      |*******\n");
										printf("*******|             DIFICULDADE              |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");           
										printf("*******|   1) FÁCIL      (10x10)              |*******\n");             
										printf("*******|   2) MÉDIO      (15x15)              |*******\n");                 
										printf("*******|   3) DIFÍCIL    (20x20)              |*******\n");               
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|                                      |*******\n");
										printf("*******|______________________________________|*******\n");
									}
									printf("\n Qual dificuldade você deseja? ");
									do {  scanf("%c", &escolhadif);}	while (escolhadif == ' ' || escolhadif == '\n');
									printf("\e[1;1H\e[2J");



								} while (escolhadif != '1' && escolhadif != '2' && escolhadif  != '3');
								break;
							case '0':
								break;
							default : 
								printf("Opção inválida!!!!\n");
								break;

						}
					} while (escolhaconf != '0');

					break;
			case '3': printf("Vlw flws!! Tchaus! Beijo! Obrigada ^^  \n");
					break;
			default: printf("Amigo... As opções são 1, 2 e 3... Nada além, nada aquém... '%c' não é válido!\n", escolha);
					
					
					break;		
		}
	} while(escolha != '3');
	return 0;
}  
