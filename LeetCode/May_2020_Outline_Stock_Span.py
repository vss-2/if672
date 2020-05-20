# Pilha decrescente

class StockSpanner:
        def __init__(self):
                # Guarda o valor e a qtd de menores que ja apareceram
                self.p = []
                self.c = []
                return

        def next(self, price):
                # Comeca com um valor, pois ele inclui o valor dele mesmo na lista de menores
                v = 1
                i = len(self.c)-1
                while(len(self.p) != 0 and price >= self.p[len(self.p)-1]):
                        # Enquanto nao estiver vazio, 
                        # e o preco for maior que os que apareceram antes
                        # tire o preco da lista e some a quantidade ja aparecida
                        v += self.c[i]
                        self.p.pop()
                        self.c.pop()
                        i -= 1
                # Insira o valor e o preco na posicao ordenada
                self.c.append(v)
                self.p.append(price)
                return v
