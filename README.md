# Casamento de Padrões Musicais

**Desenvolvedores:** Hugo Alves Azevedo de Souza e Rafael Moisés de Sá Tavares

Projeto desenvolvido em **C** para reconhecimento de padrões em sequências de notas musicais utilizando diferentes algoritmos de casamento de padrões (*string matching*).

O sistema recebe uma sequência musical e um padrão e identifica se o padrão ocorre dentro da sequência. O principal diferencial do projeto é que o reconhecimento considera a **relação intervalar entre as notas**, permitindo encontrar um mesmo padrão mesmo quando ele é **transposto para outra tonalidade**.

Dessa forma, o sistema não realiza apenas uma comparação literal das notas. Por exemplo, o padrão:

```text
B C
```

pode ser reconhecido em:

```text
E F
```

pois ambas as sequências representam o mesmo intervalo entre as notas. Assim, um motivo musical pode ser encontrado independentemente da tonalidade em que foi executado.

## Representação das notas

As sequências são representadas utilizando a notação convencional das notas musicais:

```text
A B C D E F G
```

Também são aceitos acidentes musicais:

* `#` — sustenido
* `b` — bemol

Por exemplo:

```text
A# Db C B C#
```

representa uma sequência contendo **Lá sustenido, Ré bemol, Dó, Si e Dó sustenido**.

Os padrões e sequências podem possuir diferentes combinações de notas naturais, sustenidos e bemóis.

## Exemplo

Considere a sequência:

```text
A F Gb C Gb A Db Gb A# Db C B C# A G G D C E B C G# Bb Db C D Eb A E A# Gb E A
```

e o padrão:

```text
A# Db C B C# A G G D C E B C G# Bb Db C D Eb A E A# Gb E A D#
```

O programa busca a ocorrência do padrão considerando sua estrutura musical, permitindo reconhecer a sequência mesmo quando ela aparece transposta para outra tonalidade.

Essa característica permite utilizar os algoritmos de casamento de padrões para identificar **motivos, trechos ou sequências musicais equivalentes**, independentemente das notas absolutas utilizadas.

## Algoritmos Implementados

O projeto implementa quatro algoritmos clássicos de casamento de padrões:

1. **Força Bruta**
2. **KMP (Knuth-Morris-Pratt)**
3. **BMH (Boyer-Moore-Horspool)**
4. **Shift-And**

Cada algoritmo é utilizado para realizar a busca das sequências musicais, permitindo comparar seu desempenho em relação ao tempo de execução e à quantidade de comparações realizadas.

## Funcionalidades

* Busca de padrões em sequências de notas musicais.
* Reconhecimento de padrões transpostos para diferentes tonalidades.
* Suporte a notas naturais, sustenidos (`#`) e bemóis (`b`).
* Medição do tempo de execução.

## Formato de Entrada

Cada caso de teste possui três linhas:

```text
<tamanho_da_sequência> <tamanho_do_padrão>
<sequência de notas>
<padrão>
```

Exemplo:

```text
69 27
A F Gb C Gb A Db Gb A# Db C B C# A G G D C E B C G# Bb Db C D Eb A E A# Gb E A D# A# E G# Gb E G Bb F C B C Gb Gb E A A F G# B Ab E A Gb F C# E Eb E C# G# F Gb G C A
A# Db C B C# A G G D C E B C G# Bb Db C D Eb A E A# Gb E A D# A# 
```

O primeiro valor representa a quantidade de notas da sequência, enquanto o segundo representa a quantidade de notas do padrão.

A entrada pode conter múltiplos casos de teste. O processamento é encerrado quando é encontrado:

```text
0 0
```

## Saída

Para cada caso de teste, o programa informa se o padrão foi encontrado.

* `S <posição>` — padrão encontrado na posição indicada.
* `N` — padrão não encontrado.

Exemplo:

```text
Força Bruta
S 7
N
S 0
```

Além dos resultados, são apresentadas métricas de desempenho, incluindo o tempo de leitura, o número de comparações, o tempo de execução do algoritmo e o tempo de escrita.

## Execução

Para compilar o projeto:

```bash
make build
```

Para executar utilizando um algoritmo específico:

```bash
./tp3 entrada.txt 1
```

Os métodos disponíveis são:

```text
1 - Força Bruta
2 - KMP
3 - BMH
4 - Shift-And
```

Também é possível executar através do `Makefile`:

```bash
make run metodo=1
```

O método padrão é o **Shift-And** caso `metodo` não seja informado.

Para verificar vazamentos de memória utilizando Valgrind:

```bash
make leak
```

Para remover os arquivos gerados durante a compilação:

```bash
make clean
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
