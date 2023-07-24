#pragma once

#include <iostream>

#include "ThreadExecutor.h"

struct Entity
{
    std::string m_entityID;
    int m_entityType{0};
    std::string m_entityContent;
    void print()
    {
        std::cout << "\tentityID:" << m_entityID << "\n"
                  << "\tentityType:" << m_entityType << "\n"
                  << "\tentityContent:" << m_entityContent << std::endl;
    }
};

struct Body
{
    std::string m_bodyID;
    std::vector<Entity> m_entitys;
    void print()
    {
        std::cout << "bodyID:" << m_bodyID << "\n"
                  << "entity.size:" << m_entitys.size() << std::endl;
        for (auto ent : m_entitys)
        {
            ent.print();
        }
    }
};

int getIndex(const std::string &blockIndex)
{
    auto pos = blockIndex.find("bindex");
    if (pos != std::string::npos)
    {
        return atoi(blockIndex.substr(pos + 6).c_str());
    }
    return -1;
}

std::string itos(int i)
{
    char sz[20] = {0};
    snprintf(sz, 19, "%d", i);
    return sz;
}
class ReadBlockTask : public ThreadTask
{
public:
    ReadBlockTask(const std::string &blockIndex)
        : m_blockIndex(blockIndex)
    {
    }

    int run()
    {
        std::cout << "begin task..." << std::endl;

        // mock logic
        std::this_thread::sleep_for(std::chrono::seconds(3));
        Body body;
        // std::cout << m_blockIndex << std::endl;
        auto idx = getIndex(m_blockIndex);
        if (idx % 2 == 1)
        {
            body.m_bodyID = "abc_" + itos(idx);
            {
                Entity ent;
                ent.m_entityID = itos(100 + idx);
                ent.m_entityContent = "{\"name\" : \"somebody_" + itos(1000 + idx) + "\"}";
                body.m_entitys.push_back(ent);
            }
            m_bodys.push_back(body);
        }
        else
        {
            body.m_bodyID = "abc_" + itos(idx);
            ;
            {
                Entity ent;
                ent.m_entityID = itos(100 + idx);
                ent.m_entityContent = "{\"name\" : \"somebody_" + itos(2000 + idx) + "\"}";
                body.m_entitys.push_back(ent);
            }
            {
                Entity ent;
                ent.m_entityID = "333";
                ent.m_entityContent = "{\"name\" : \"somebody_" + itos(2000 + idx + 1) + "\"}";
                body.m_entitys.push_back(ent);
            }
            m_bodys.push_back(body);
        }
        return 0;
    }

    const std::vector<Body> &getData() const
    {
        return m_bodys;
    }

private:
    // input
    std::string m_blockIndex;

    // output optional
    std::vector<Body> m_bodys;
};