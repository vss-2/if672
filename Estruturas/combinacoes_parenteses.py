# Source: https://leetcode.com/problems/generate-parentheses/
# Input: n = 3
# Output: ["((()))","(()())","(())()","()(())","()()()"]
def generateParenthesis(self, n: int) -> list:
    def backtracking(qtdEsq, qtdDir, comb, combs):
        
        # Completou todas as combinações ()
        if qtdEsq == 0 and qtdDir == 0:
            combs.append(comb)
            return
        
        if qtdEsq > 0:
            # Gasta uma (
            # Chama recursão para "diversificar" combinacao+"(" para gerar combinacoes
            backtracking(qtdEsq-1, qtdDir, comb + '(', combs)
        
        # Gasta )
        # Após aberto parênteses, começa a fechar
        if qtdDir > qtdEsq:
            backtracking(qtdEsq, qtdDir-1, comb + ')', combs)
        
        return combs

    # Salva as combinações
    combs = None
    # Inicia com mesma quantidade de parênteses abrindo e fechando
    combs = backtracking(n, n, '', [])
    return combs
