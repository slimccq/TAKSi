// This file is auto-generated by taxi v1.2.0, DO NOT EDIT!

#include "AutogenConfig.h"
#include <stddef.h>
#include <assert.h>
#include <memory>
#include <fstream>
#include "Utility/Conv.h"
#include "Utility/StringUtil.h"

using namespace std;

#ifndef ASSERT
#define ASSERT assert
#endif


// parse value from text
template <typename T>
inline T ParseValue(StringPiece text)
{
    text = trimWhitespace(text);
    if (text.empty())
    {
        return T();
    }
    return to<T>(text);
}


namespace config
{

std::function<std::string(const char*)> AutogenConfigManager::reader = AutogenConfigManager::ReadFileContent;

namespace 
{
    static std::vector<BoxProbabilityDefine>* _instance_boxprobabilitydefine = nullptr;
}

void AutogenConfigManager::LoadAll()
{
    ASSERT(reader);
    BoxProbabilityDefine::Load("box_probability_define.csv");
}

void AutogenConfigManager::ClearAll()
{
    delete _instance_boxprobabilitydefine;
    _instance_boxprobabilitydefine = nullptr;
}

//Load content of an asset file
std::string AutogenConfigManager::ReadFileContent(const char* filepath)
{
    ASSERT(filepath != nullptr);
    std::ifstream ifs(filepath);
    ASSERT(!ifs.fail());
    std::string content;
    content.assign(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
    return std::move(content);
}


const std::vector<BoxProbabilityDefine>* BoxProbabilityDefine::GetData()
{
    ASSERT(_instance_boxprobabilitydefine != nullptr);
    return _instance_boxprobabilitydefine;
}

const BoxProbabilityDefine* BoxProbabilityDefine::Get(const std::string& ID)
{
    const vector<BoxProbabilityDefine>* dataptr = GetData();
    ASSERT(dataptr != nullptr && dataptr->size() > 0);
    for (size_t i = 0; i < dataptr->size(); i++)
    {
        if (dataptr->at(i).ID == ID)
        {
            return &dataptr->at(i);
        }
    }
    return nullptr;
}

// load data from csv file
int BoxProbabilityDefine::Load(const char* filepath)
{
    vector<BoxProbabilityDefine>* dataptr = new vector<BoxProbabilityDefine>;
    string content = AutogenConfigManager::reader(filepath);
    MutableStringPiece sp((char*)content.data(), content.size());
    sp.replaceAll("\r\n", " \n");
    auto lines = Split(sp, "\n");
    ASSERT(!lines.empty());
    for (size_t i = 0; i < lines.size(); i++)
    {
        auto line = trimWhitespace(lines[i]);
        if (!line.empty())
        {
            const auto& row = Split(lines[i], ",");
            if (!row.empty())
            {
                BoxProbabilityDefine item;
                BoxProbabilityDefine::ParseFromRow(row, &item);
                dataptr->push_back(item);
            }
        }
    }
    delete _instance_boxprobabilitydefine;
    _instance_boxprobabilitydefine = dataptr;
    return 0;
}

// parse data object from an csv row
int BoxProbabilityDefine::ParseFromRow(const vector<StringPiece>& row, BoxProbabilityDefine* ptr)
{
    ASSERT(row.size() >= 13);
    ASSERT(ptr != nullptr);
    ptr->ID = ParseValue<std::string>(row[0]);
    ptr->Total = ParseValue<int>(row[1]);
    ptr->Time = ParseValue<int>(row[2]);
    ptr->Repeat = ParseValue<bool>(row[3]);
    for (int i = 4; i < 13; i += 3) 
    {
        ProbabilityGoodsDefine item;
        item.GoodsID = ParseValue<std::string>(row[i + 0]);
        item.Num = ParseValue<uint32_t>(row[i + 1]);
        item.Probability = ParseValue<uint32_t>(row[i + 2]);
        ptr->ProbabilityGoods.push_back(item);
    }
    return 0;
}


} // namespace config 
