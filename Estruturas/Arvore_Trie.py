class NoTrie:
	def __init__(self):
		self.filho = [None]*26
		self.fim = False

class Trie:
	def __init__(self):
		self.raiz = self.getNo()

	def getNo(self):
		return NoTrie()

	def inserir(self, val):
		pAchar = self.raiz
		tam   = len(val)
		for t in range(0, tam):
			indc = ord(val[t]) - ord('a')

			if not pAchar.filho[indc]:
				pAchar.filho[indc] = self.getNo()
			pAchar = pAchar.filho[indc]

		pAchar.fim = True

	def buscar(self, val):
		pAcha = self.raiz
		tam   = len(val)
		for t in range(tam):
			indc = ord(val[t]) - ord('a')
			if not pAcha.filho[indc]:
				return False
			pAcha = pAcha.filho[indc]
		return pAcha != None and pAcha.fim


if __name__ == '__main__':
	t = Trie()

	palavras = ['isso','e','um','teste','para','demonstracao']

	for b in palavras:
		t.inserir(b)

	print('Digita o que voce quer buscar, pare com Enter.')

	set_busca = []
	i = None
	while True:
		i = input()
		if(i == ''):
			break
		set_busca.append(str(i))

	for p in set_busca:
		print('Procurando por', p, 'na Trie, obtive:', t.buscar(str(p)))
