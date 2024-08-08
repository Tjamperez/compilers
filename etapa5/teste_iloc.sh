TIMEOUT_SEC=1
ILOCSIM="./ilocsim.py"  
STACK=1024
DATA=500
TEST_FILE="./e5_all/E5/ijk13" 


chmod +x ${ILOCSIM}


echo "Running etapa5 with timeout..."
timeout ${TIMEOUT_SEC} ./etapa5 < $TEST_FILE > /tmp/saida.iloc


echo "Running ILOC simulator..."
timeout ${TIMEOUT_SEC} ${ILOCSIM} \
--stack $STACK \
--data $DATA \
-s \
-x < /tmp/saida.iloc > /tmp/saida.sim


echo "Interpreting simulator output..."
cat /tmp/saida.sim | \
awk '/storeAI|loadI|jumpI|addI|loadAI|i2i|halt|nop/ {print NR ": " $0}' > /tmp/interpreted_output.txt
