#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BMToolPlugin.h"

void BMToolPlugin::input(std::string file) {
  inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void BMToolPlugin::run() {
   
}

void BMToolPlugin::output(std::string file) {
	//bmtool -d Mouse.fa -o Mouse.bitmask -w 12
	//kraken2 --use-names --db ${KRAKEN2_DB} --paired --output taxa.krak2 R1.fastq R2.fastq
	//trim_galore --no_report_file --paired -o $out $reads_1 $reads_2
	std::string command = "bmtool -d "+std::string(PluginManager::prefix())+"/"+parameters["fastafile"]+" -w "+parameters["wordsize"]+" -o "+file;
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<BMToolPlugin> BMToolPluginProxy = PluginProxy<BMToolPlugin>("BMTool", PluginManager::getInstance());
