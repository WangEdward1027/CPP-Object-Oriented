//最少知识原则

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Building
{
public:
    virtual void sale() = 0;
    virtual string getQuality() = 0;
    virtual ~Building(){}
};

class WankeBuilding
: public Building
{
public:
    WankeBuilding()
    : _quality("高品质")
    {

    }

    void sale() override
    {
        cout << "万科楼盘" << _quality << "的房子被出售" << endl;
    }

    string getQuality() override
    {
        return _quality;
    }
private:
    string _quality;
};

class HengdaBuilding
: public Building
{
public:
    HengdaBuilding()
    : _quality("低品质")
    {
    
    }

    void sale() override
    {
        cout << "恒大楼盘" << _quality << "的房子被出售" << endl;
    }

    string getQuality() override
    {
        return _quality;
    }
private:
    string _quality;
};

void test()
{
    Building* pbuidingA = new WankeBuilding();
    Building* pbuidingB = new HengdaBuilding();

    /* string demand = "低品质"; */
    string demand = "高品质";

    //1.没有中介,购房者需要自己挨个查询所有的楼盘,以找到高品质的房子
    if(pbuidingA->getQuality() == demand){
        pbuidingA->sale();
    }

    if(pbuidingB->getQuality() == demand){
        pbuidingB->sale();
    }
}

//新增:中介类
class Mediator
{
public:
    Mediator()
    {
        Building *pbuildingA = new WankeBuilding();
        Building *pbuildingB = new HengdaBuilding();
        _buildings.push_back(pbuildingA);
        _buildings.push_back(pbuildingB);
    }

    Building* findBuilding(const string &quality)
    {
        for(auto &building : _buildings){
            if(building->getQuality() == quality){
                return building;
            }
        }
        return nullptr;
    }

    ~Mediator()
    {
        for(auto &building : _buildings){
            if(building){
                delete building;
            }
        }
    }
private:
    vector<Building *> _buildings;
};

void test2()
{
    string demand = "低品质";
    Mediator mediator;
    
    //由中介去遍历找房子,而不需要购房者自己去找房子
    Building* pbuilding = mediator.findBuilding(demand);
    if(pbuilding){
        pbuilding->sale();
    }else{
        cout << "没有符合要求的楼盘" << endl;
    }
}

int main()
{
    test();
    test2();
    return 0;
}
