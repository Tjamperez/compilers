./etapa5 < ./e5_all/E5/ijk13.txt > ./tmp/saida.iloc
python3 ./ilocsim.py -x -t -s --data 500 --stack 1024 ./tmp/saida.iloc > ./tmp/saida.sim
cat ./tmp/saida.sim