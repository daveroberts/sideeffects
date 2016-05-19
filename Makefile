# File containing main class, main class name must match filename
PACKAGE=foo

# Name of Main class.  Also used as name of jar
CLASS=HelloWorld

build: clean
	scalac -d obj -sourcepath src/ src/$(PACKAGE)/$(CLASS).scala

jar: build
	cd obj; jar -cfm ../jar/$(CLASS).jar ../Manifest.mf *

run: build
	cd obj; scala -cp . $(PACKAGE).$(CLASS)

runjar: jar
	java -jar jar/$(CLASS).jar

clean:
	rm -rf jar/*
	rm -rf obj/*
