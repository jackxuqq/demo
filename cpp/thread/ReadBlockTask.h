/***************************************************************************************
* @file       ReadBlockTask.h
* @brief      replaceme
* @details
* @author     xuzewei
* @date       2023-07-20
* @version    V1.0
* @copyright  Copyright (c) 2022-2025  Shen Zhen Poisson Software Technology CO.,LTD
**************************************************************************************/

#include "ThreadExecutor.h"

namespace pscloud
{

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

class ReadBlockTask :public ThreadTask
{
public:
    ReadBlockTask(const std::string& blockIndex)
        :m_blockIndex(blockIndex)
    {
    }

    void run()
    {
        std::cout << "begin task..." << std::endl;

        // mock logic
        std::this_thread::sleep_for(std::chrono::seconds(3));
        Body body;
        if (m_blockIndex == "bindex1")
        {
            body.m_bodyID = "abc111";
            {
                Entity ent;
                ent.m_entityID = "111";
                ent.m_entityContent = "{\"name\" : \"jack\"}";
                body.m_entitys.push_back(ent);
            }
            m_bodys.push_back(body);
        }
        else if (m_blockIndex == "bindex2")
        {
            body.m_bodyID = "abc222";
            {
                Entity ent;
                ent.m_entityID = "222";
                ent.m_entityContent = "{\"name\" : \"tom\"}";
                body.m_entitys.push_back(ent);
            }
            {
                Entity ent;
                ent.m_entityID = "333";
                ent.m_entityContent = "{\"name\" : \"lucy\"}";
                body.m_entitys.push_back(ent);
            }
            m_bodys.push_back(body);
        }
        m_ret = 0;
    }

    int getResult()
    {
        return m_ret;
    }

    const std::vector<Body>& getData() const
    {
        return m_bodys;
    }

private:
    // ret
    int m_ret;

    // input
    std::string m_blockIndex;

    // output optional
    std::vector<Body> m_bodys;
};
}
