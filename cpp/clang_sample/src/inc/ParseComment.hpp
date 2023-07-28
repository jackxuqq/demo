#pragma once

#include "Define.hpp"

class ParseComment
{
public:

    ParseComment(const std::string& file, int line)
    :m_file(file), m_line(line)
    {
    }

    int procParams();

    ParamAttribute getAttr(const std::string& param)
    {
        if (auto itr = m_attr.find(param); itr != m_attr.end())
        {
            return itr->second;
        }
        return ParamAttributrInit;
    }

    /*for debug*/
    void printf()
    {
        std::cout << "m_arr.size:" << m_attr.size() << std::endl;
        for (auto& val : m_attr)
        {
            std::cout << val.first  << ": " << val.second << std::endl;
        }
    }

private:

    /*header file name, include path*/
    std::string m_file;

    /*api line*/
    int m_line;

    /*param's attr, now is in or out*/
    std::unordered_map<std::string, ParamAttribute> m_attr;

private:
    /*fetch api's comment segment*/
    int _getComment(std::vector<std::string>* segment);

    /*for each comment line match @param[in/out]*/
    void _matchParams(const std::vector<std::string>& segment, std::vector<std::string>* params);

    /*fetch key[in/out] and after first word into m_attr*/
    void _makeAttr(const std::vector<std::string>& params);

};
