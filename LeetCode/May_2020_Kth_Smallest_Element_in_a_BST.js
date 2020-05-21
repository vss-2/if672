/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    arv  = []
    raiz = root
    while(k--){
        // Percorre em ordem, ou seja, esquerda->direita->raiz
        while(root != undefined){
            // Percorre todos os nós pela esquerda
            arv.push(root)
            root = root.left
        }
        // Percore todos os nós pela direita
        raiz = arv.pop()
        root = raiz.right
        // Visitou o nó, pode subir um nível
    }
    // Retorna o k-ésima nó (ou raiz) da visita em em ordem
    return raiz.val
};
