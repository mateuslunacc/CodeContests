# Exemplo de entrada: ./ordenar AlgoritmoX < input.txt > output.txt

if [ $1 == "heap" ]; then
	#chama o executável do heap passando o input.txt
	#echo "ordenar pelo heap"
	heap_sort < entrada.txt > saida.txt
else 
	#chama o executável do quick passando o input.txt
	#echo "ordenar pelo quick"
	quick_sort < entrada.txt > saida.txt
fi



