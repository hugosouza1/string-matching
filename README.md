# Reconhecimento de Padrões Musicais

**Desenvolvedores:** Hugo Alves Azevedo de Souza e Rafael Moisés de Sá Tavares

Projeto desenvolvido em **C** para reconhecimento e comparação de sequências de notas musicais utilizando algoritmos clássicos de casamento de padrões (*string matching*).

O sistema recebe uma sequência musical e um padrão de notas e busca ocorrências do padrão dentro da sequência. Como diferencial, o casamento não depende das notas absolutas, permitindo reconhecer **sequências equivalentes em diferentes tonalidades**.

Por exemplo, considerando o padrão:

```text
BC
```

uma sequência contendo:

```text
EF
```

também pode ser reconhecida, pois as duas sequências preservam a mesma relação entre as notas. Dessa forma, o sistema é capaz de identificar **motivos ou trechos musicais transpostos para diferentes tons**, em vez de comparar apenas as notas literalmente.

## Algoritmos Implementados

O projeto implementa quatro algoritmos clássicos de casamento de padrões:

1. **Força Bruta**
2. **KMP (Knuth-Morris-Pratt)**
3. **BMH (Boyer-Moore-Horspool)**
4. **Shift-And**

Os algoritmos são utilizados como base para o reconhecimento das sequências musicais, enquanto a lógica de comparação considera a relação entre as notas para permitir o reconhecimento de padrões transpostos.

### Exemplo

Considere o padrão:

```text
BC
```

A sequência:

```text
ABCDEF
```

contém o padrão literalmente:

```text
BC
```

Porém, uma sequência como:

```text
CDEFG
```

também pode conter uma ocorrência equivalente, dependendo da posição e da transposição considerada.

Por exemplo:

```text
BC
EF
```

representam o mesmo intervalo entre as notas, portanto o sistema pode considerar `EF` uma ocorrência do padrão `BC`.

Essa abordagem permite procurar **motivos musicais independentemente da tonalidade em que foram executados**, tornando os algoritmos tradicionais de casamento de padrões aplicáveis ao reconhecimento de sequências musicais.


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
