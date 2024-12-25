all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/BagliListe.cpp -o ./lib/BagliListe.o	
	g++ -c -I "./include" ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
	g++ -c -I "./include" ./src/AgacDugum.cpp -o ./lib/AgacDugum.o

bagla:
	g++ ./lib/BagliListe.o	./lib/Dugum.o ./lib/IkiliAramaAgaci.o ./lib/AgacDugum.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program