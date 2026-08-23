
# Algoritmos de Casamento de Padrões

**Desenvolvedores:** Hugo Alves Azevedo de Souza e Rafael Moisés de Sá Tavares

Projeto desenvolvido em **C** para implementação e comparação de diferentes algoritmos de casamento de padrões (*string matching*). A aplicação recebe um texto e um padrão como entrada e identifica a primeira ocorrência do padrão no texto utilizando diferentes estratégias de busca.

O projeto tem como objetivo explorar e comparar algoritmos clássicos de processamento de strings, analisando aspectos como número de comparações e tempo de execução.

## Algoritmos Implementados

A aplicação disponibiliza quatro métodos de busca:

1. **Força Bruta** — realiza comparações sequenciais entre o padrão e as possíveis posições no texto.
2. **KMP (Knuth-Morris-Pratt)** — utiliza informações sobre o próprio padrão para evitar comparações desnecessárias.
3. **BMH (Boyer-Moore-Horspool)** — utiliza deslocamentos baseados nos caracteres do padrão para acelerar a busca.
4. **Shift-And** — utiliza operações sobre bits para realizar o casamento do padrão de forma eficiente.

## Execução

Para compilar o projeto, execute:

```bash
make build
```

O comando compila os arquivos-fonte e gera o executável `tp3`.

Para executar utilizando um método específico:

```bash
./tp3 entrada.txt 1
```

O segundo argumento define o algoritmo utilizado:

```text
1 - Força Bruta
2 - KMP
3 - BMH
4 - Shift-And
```

Também é possível executar diretamente através do `Makefile`:

```bash
make run metodo=1
```

Caso o parâmetro `metodo` não seja informado, o método padrão é o **Shift-And**.

### Verificação de memória

Para executar o programa utilizando o **Valgrind**:

```bash
make leak
```

Esse comando recompila o projeto e executa a aplicação com verificações de vazamentos e problemas de memória.

Para remover os arquivos gerados durante a compilação:

```bash
make clean
```

## Formato de Entrada

A entrada é composta por múltiplos casos de teste. Cada caso possui:

```text
<tamanho_do_texto> <tamanho_do_padrao>
<texto>
<padrao>
```

O último caso deve ser indicado por:

```text
0 0
```

Exemplo:

```text
10 3
abracadabra
cad
0 0
```

Os tamanhos informados devem corresponder aos respectivos textos e padrões. A entrada não deve possuir linhas vazias entre os casos de teste.

## Saída

Os resultados são armazenados no arquivo:

```text
tp3.out
```

Para cada caso de teste, o programa informa se o padrão foi encontrado e, quando encontrado, indica a posição da **primeira ocorrência**.

* `S <posição>` — padrão encontrado.
* `N` — padrão não encontrado.

Exemplo:

```text
KMP
S 4
N
S 0
```

Além dos resultados, o programa apresenta informações de desempenho no terminal, incluindo:

* tempo de leitura;
* quantidade de comparações realizadas;
* tempo de execução do algoritmo;
* tempo de escrita.

Essas métricas permitem analisar o comportamento dos diferentes algoritmos de casamento de padrões em relação ao tempo de execução e ao número de comparações realizadas.

O projeto é organizado em módulos, separando a implementação dos algoritmos de busca, entrada e saída de dados, medição de tempo e estruturas auxiliares.

## Tecnologias

* **Linguagem:** C
* **Build:** Make / Makefile
* **Compilação:** GCC
* **Análise de memória:** Valgrind
* **Algoritmos:** Força Bruta, KMP, Boyer-Moore-Horspool e Shift-And
