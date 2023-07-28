#include "ParseComment.hpp"
#include "Utils.hpp"

int ParseComment::procParams()
{
    std::vector<std::string> segment;
    std::vector<std::string> params;

    /*step1:open header file, fetch comment segment*/
    if (auto ret = _getComment(&segment); ret != 0)
    {
        std::cout << "_getComment,fail:" << ret << std::endl;
        return ret;
    }

    /*step2:for each comment line match @param[in/out] lines*/
    _matchParams(segment, &params);

    /*step3:fetch key[in/out] and after first word into m_attr*/
    _makeAttr(params);
    return 0;
}

int ParseComment::_getComment(std::vector<std::string>* segment)
{
    std::ifstream header(m_file);
    std::vector<std::string> content;
    for (auto i = 0; i < m_line; i++)
    {
        std::string line;
        getline(header,line);
        content.push_back(line);
    }

    bool flag = false;
    for (auto i = m_line - 1; i >=0; --i)
    {
        auto tmp = StringUtils::trim(content[i]);

        if (tmp == "*/" || tmp == "**/")
        {
            /*last line*/
            flag = true;
            continue;
        }

        if  (tmp == "/**" || tmp == "/*")
        {
            /*first comment line*/
            break;
        }

        if (flag)
        {
            (*segment).push_back(tmp);
        }
     }

     if ((*segment).size() == 0 )
     {
        /*not found comment*/
        return -1;
     }
     return 0;
}

void ParseComment::_matchParams(const std::vector<std::string>& segment, std::vector<std::string>* params)
{
    for (auto& line : segment)
    {
        if (line.find("@param[") != std::string::npos)
        {
            (*params).push_back(line);
        }
    }
}

void ParseComment::_makeAttr(const std::vector<std::string>& params)
{
    for (auto& val : params)
    {
        std::cout << "In _makeAttr:" << val << std::endl;
    }

    auto innerFunc = [&](const std::string& key, ParamAttribute attr)->void
    {
        for (auto& param : params)
        {
            if (auto pos = param.find(key); pos != std::string::npos)
            {
                auto tmp = StringUtils::trim(param.substr(pos + key.size()));
                /* compatible case: @param[in/out]     :   paramName paramDesc*/
                if (tmp.size() > 0 && tmp[0] == ':')
                {
                    tmp = tmp.substr(1);
                    tmp = StringUtils::trim(tmp);
                }

                auto arr = StringUtils::split(tmp);

                if (arr.size() > 0)
                {
                    m_attr[arr[0]] = attr;
                }
            }
        }
    };

    innerFunc("@param[in]", ParamAttributeIn);
    innerFunc("@param[out]", ParamAttributeOut);
}
