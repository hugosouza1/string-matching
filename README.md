# PROJETO E ANÁLISE DE ALGORITMOS - TRABALHO PRÁTICO 3
**Alunos:** Hugo Alves Azevedo de Souza e Rafael Moisés de Sá Tavares

Esse arquivo conta com instruções para execução do tp 3 e de informações sobre a entrada e saída do programa.

## Execução:
  Para compilar o programa é necessário usar o comando no terminal:
  ```
  make build
  ``` 
  Tal comando irá compilar todos os arquivos necessários em arquivo objeto e salvar na pasta "objeto".
  É possível executar o programa utilizar o comando:
  ```
  ./tp3 entrada.txt 1
  ```
  Sendo entrada.txt o arquivo que contém as entradas e o "1" um valor que vai de 1 a 4 para selecionar o método. 
  1 - Força Bruta
  2 - KMP
  3  - BMH
  4 - Shift-And
  Outra forma de executar o programa é com o comando:
  ```
   make run metodo=1
  ```
  O "metodo" é usado para pegar o algoritmo requisitado.
## Entrada:
  O formato da entrada é o mesmo especificado no pdf do tp: 
  1° linha - tamanho do texto e tamanho do padrão, separados por espaço
  2° linha - texto
  3° linha - padrão
  A última linha da entrada deve ser "0 0" para indicar o fim. O arquivo não pode ter linhas vazias nos meio.
## Saída: 
  A saída será impressa no arquivo "tp3.out"
  É impresso no terminal o tempo gasto com:
  - Leitura
  - Quantidadde de comparações
  - Resolução do método
  - Escrita

  A saída no terá o nome do processo escolhido no topo e em cada linha o resultado. Caso tenha achado, será impresso "S", seguido da primeira ocorrência. Caso não, será impresso "N"
  Exemplo de saída:
```
Força Bruta
S 7
N
N
S 0
N
N
S 0
S 2
S 0
S 0
S 1
S 0
S 2
S 4
S 0
S 2
S 1
S 0
S 7
S 5
S 3
S 10
N
```
