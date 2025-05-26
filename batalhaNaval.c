#include <stdio.h// 
//
int main(){ 
     printf(¨Desafio Batalha naval!\n¨);      
      TAMANHO = 10  # tamanho do tabuleiro 10x10
NUM_NAVIOS = 4

def criar_tabuleiro():
    return [["~"] * TAMANHO for _ in range(TAMANHO)]

def imprimir_tabuleiro(tabuleiro, mostrar_navios=False):
    print("  " + " ".join(str(i) for i in range(TAMANHO)))
    for i, linha in enumerate(tabuleiro):
        print(str(i) + " " + " ".join(linha if mostrar_navios else ["~" if c == "N" else c for c in linha]))

def posicionar_navios(tabuleiro):
    navios = 0
    while navios < NUM_NAVIOS:
        x = random.randint(0, TAMANHO - 1)
        y = random.randint(0, TAMANHO - 1)
        if tabuleiro[x][y] != "N":
            tabuleiro[x][y] = "N"
            navios += 1

def atacar(tabuleiro, x, y):
    if tabuleiro[x][y] == "N":
        tabuleiro[x][y] = "X"
        return True
    elif tabuleiro[x][y] == "~":
        tabuleiro[x][y] = "O"
        return False
    return None  # já atacado

def contar_acertos(tabuleiro):
    return sum(linha.count("X") for linha in tabuleiro)

# Inicialização dos jogadores
tabuleiro1 = criar_tabuleiro()
tabuleiro2 = criar_tabuleiro()
posicionar_navios(tabuleiro1)
posicionar_navios(tabuleiro2)

vez = 1

print("=== BATALHA NAVAL ===")
while True:
    print(f"\n--- Jogador {vez} ---")
    if vez == 1:
        tabuleiro_alvo = tabuleiro2
    else:
        tabuleiro_alvo = tabuleiro1

    imprimir_tabuleiro(tabuleiro_alvo)

    try:
        x = int(input("Linha: "))
        y = int(input("Coluna: "))
    except ValueError:
        print("Digite números válidos.")
        continue

    if not (0 <= x < TAMANHO and 0 <= y < TAMANHO):
        print("Fora do tabuleiro!")
        continue

    resultado = atacar(tabuleiro_alvo, x, y)
    if resultado is True:
        print("💥 Acertou um navio!")
    elif resultado is False:
        print("🌊 Água!")
    else:
        print("⛔ Já atacou esse local.")
        continue  # não troca de vez

    if contar_acertos(tabuleiro_alvo) == NUM_NAVIOS:
        print(f"\n🎉 Jogador {vez} venceu!")
        break

    vez = 2 if vez == 1 else 1
 
 
 
 
 
 
     return 0;
}
