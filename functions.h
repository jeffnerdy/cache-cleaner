#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

bool SetUp(std::string search, std::string clean);
bool IsEmpty(std::ifstream& file);

int SearchDirectory(const std::string& path, std::ofstream& file);
int RemoveFromDirectory(const std::string& path);

bool Search(std::string& path, std::ifstream& ifile, std::ofstream& ofile);
bool Clean(std::string& path, std::ifstream& file);
