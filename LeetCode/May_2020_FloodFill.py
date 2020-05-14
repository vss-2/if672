class Solution:
    def pintar(image, sr, sc, pixelAntes, newColor):
        if (sr < 0 or sc < 0 or len(image) <= sr or len(image[0]) <= sc):
                return
        elif (image[sr][sc] != pixelAntes):
                # pixel atual e diferente do pixel antes
                return
        else:
                # pinta pixel da nova cor
                if (image[sr][sc] != newColor):
                        image[sr][sc] = newColor
                Solution.pintar(image, sr-1, sc, pixelAntes, newColor)
                Solution.pintar(image, sr+1, sc, pixelAntes, newColor)
                Solution.pintar(image, sr, sc-1, pixelAntes, newColor)
                Solution.pintar(image, sr, sc+1, pixelAntes, newColor)
        return image
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        # sr e sc sao posicoes relativas
        # dfs
        if(image[sr][sc] == newColor):
                # Origem eh da mesma cor que nova
                return image
        Solution.pintar(image, sr, sc, image[sr][sc], newColor)
        return image