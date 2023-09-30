all: main testIns testDel testSea resIns resDel resSea clean

main: main.o
	g++ main.o UnrolledList.o Node.o -o main

testIns: tests.o modules.o
	g++ InsertTest.o UnrolledList.o Node.o -o testIns
testDel: tests.o modules.o
	g++ DeleteTest.o UnrolledList.o Node.o -o testDel
testSea: tests.o modules.o
	g++ SearchTest.o UnrolledList.o Node.o -o testSea
	
resIns: research.o modules.o
	g++ InsertResearch.o UnrolledList.o Node.o -o resIns
resDel: research.o modules.o
	g++ DeleteResearch.o UnrolledList.o Node.o -o resDel
resIns: research.o modules.o
	g++ SearchResearch.o UnrolledList.o Node.o -o resSea


main.o: modules.o
	g++ -c *.cpp -Imodules
tests.o: modules.o
	g++ -c tests/*.cpp -Imodules
research.o: modules.o
	g++ -c research/*.cpp -Imodules
modules.o:
	g++ -c modules/*.cpp -Imodules

clean:
	rm -f *.o