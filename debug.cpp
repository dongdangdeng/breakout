#include "debug.hpp"
#include <DxLib.h>
#include <string>
#include <vector>

Debug *Debug::me;

Debug::Debug(bool isAvailable) {
	debugMode = isAvailable;
	me = this;
}

void Debug::addData(std::string name, std::string data) {
	for (unsigned int i = 0; i < debugData.size(); ++i) {
		if (debugData[i].name == name) { return; }	//すでに同名のデータが有る場合何も行わない
	}
	debug_t tmp;
	tmp.name = name;
	tmp.data = data;
	debugData.push_back(tmp);
}

void Debug::addData(std::string name, int data) {
	addData(name, std::to_string(data));
}

void Debug::addData(std::string name, double data) {
	addData(name, std::to_string(data));
}

void Debug::changeData(std::string  name, std::string  data) {
	for (unsigned int i = 0; i < debugData.size(); ++i) {
		if (debugData[i].name == name) { debugData[i].data = data; }
	}
}

void Debug::changeData(std::string  name, int data) {
	changeData(name, std::to_string(data));
}

void Debug::changeData(std::string  name, double data) {
	changeData(name, std::to_string(data));
}

void Debug::deleteData(std::string name) {
	for (unsigned int i = 0; i < debugData.size(); ++i) {
		if (debugData[i].name == name) { debugData.erase(debugData.begin() + i); }
	}
}

void Debug::draw() {
	if (!debugMode) {
		return;
	}
	std::string str;
	for (unsigned int i = 0; i < debugData.size(); ++i) {
		str += debugData[i].name + " : " + debugData[i].data + "\n";
	}

	//charに変換
	char* cstr = new char[str.size() + 1];
	std::char_traits<char>::copy(cstr, str.c_str(), str.size() + 1);

	DrawFormatString(0, 0, GetColor(255, 255, 255), cstr);
}