Tips for running and executing the program



#!/usr/bin/bash
##
## output2dot.sh
##
## Este script converte o formato de saída
## da E3 para o formato DOT. Ele lê da
## entrada padrão e escreve na saída padrão.
## Portanto, seu uso se dá da seguinte
## forma, assumindo o desejo de visualizar
## com a ferramenta xdot (não esqueça do "-"):
##
## ./etapa3 | ./output2dot.sh | xdot -
##
## Caso houver o desejo de salvar o DOT:
##
## ./etapa3 | ./output2dot.sh > saida.dot
##
## Caso a entrada esteja em entrada.txt e
## há o desejo de salvar a saída em arquivo
##
## ./output2dot.sh < entrada.txt > saida.dot
##
##


./etapa3 < entrada.txt  | grep 0x | ./output2dot.sh > saida.dot
 xdot saida.dot


 ./etapa3 < entrada.txt  | grep 0x | ./output2dot.sh | xdot -

 comandos para testar todo programa