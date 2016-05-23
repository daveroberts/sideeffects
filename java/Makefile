# File containing main class, main class name must match filename
PACKAGE=foo

# Name of Main class.  Also used as name of jar
CLASS=SideEffects

build: clean
	javac -Xlint:unchecked -d obj -sourcepath src/ src/$(PACKAGE)/$(CLASS).java

jar: build
	cd obj; jar -cfm ../jar/$(CLASS).jar ../Manifest.mf *

run: build
	cd obj; java -cp . $(PACKAGE).$(CLASS)

runjar: jar
	java -jar jar/$(CLASS).jar

clean:
	rm -rf jar/*
	rm -rf obj/*
