#ifndef DEBUG_CPP
#define DEBUG_CPP

#include "chara.hpp"
#include <vector>
#include <string>
/*
デバッグモードの切替はBreakout::DEBUG_MODEで行う
*/


struct debug_t {
	std::string name;
	std::string data;
};


class Debug{
	bool debugMode;
	std::vector<debug_t> debugData;
public:
	static Debug *me;				//自分自身のポインタ

	Debug(bool);
	void addData(std::string, std::string);
	void addData(std::string, int);
	void addData(std::string, double);
	void changeData(std::string, std::string);
	void changeData(std::string, int);
	void changeData(std::string, double);
	void deleteData(std::string);
	void draw();
};

#endif //!DEBUG_CPP