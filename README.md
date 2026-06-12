O funcionamento do programa é baseado em um menu que permite ao usuário 
cadastrar produtos, visualizar informações do estoque e pesquisar produtos pelo 
código. Inicialmente, o usuário informa a quantidade de produtos que deseja 
cadastrar, e o programa utiliza alocação dinâmica de memória por meio da função 
realloc() para reservar espaço suficiente para armazenar os dados. Em seguida, são 
solicitados o código, nome, preço e quantidade de cada produto, que são 
armazenados em uma estrutura do tipo Produto. Para gerar o resumo do estoque, o 
programa percorre todos os produtos cadastrados, calculando o valor em estoque 
de cada item por meio da multiplicação do preço pela quantidade disponível, além 
de somar esses valores para obter o valor total do estoque. O produto mais caro é 
identificado comparando os preços de todos os produtos cadastrados e 
armazenando a posição daquele que possui o maior valor. Ao encerrar o programa, 
a memória utilizada é liberada com a função free(), evitando desperdício de recursos 
do sistema.
