#pragma once

#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

bool SetUp(const std::filesystem::path& search, const std::filesystem::path& clean);
bool IsEmpty(std::ifstream& file);

int SearchDirectory(const std::filesystem::path& path, std::ofstream& file);
int RemoveFromDirectory(const std::filesystem::path& path);

bool Search(std::string& path, std::ifstream& ifile, std::ofstream& ofile);
bool Clean(std::string& path, std::ifstream& file);
