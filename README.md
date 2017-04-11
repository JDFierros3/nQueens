# nQueens

To build:
<code>make</code>
to run:
<code>./nqueens</code>

The program uses searching algorithm with a explored set, and a frontier. It generates board states by moving one queen randomly that is in conflict with another queen, then scores the states and moves to the best scored state. As the board size increases the order n squared scoring funcion slows the compuations down drastically.
