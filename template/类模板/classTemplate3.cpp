//类模板:实现快速排序

#include <iostream> 
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<typename T,typename Compare=std::less<T>>
class MyQsort
{
public:
    MyQsort(T* arr, size_t size, Compare com){
        for(int i = 0; i < size; ++i){
            _vec.push_back(arr[i]);
        }
        quick(0 , size-1, com);
    }

    void quick(int left, int right, Compare &com){
        if(left < right){
            int pivotIndex = partition(left, right, com);
            quick(left, pivotIndex - 1, com);
            quick(pivotIndex + 1, right, com);
        }   
    }

    int partition(int left, int right, Compare &com){
        T pivot = _vec[right];

        while(left < right){
            while(left < right && com(_vec[left],pivot)) left++;
            _vec[right] = _vec[left];
            while(left < right && !com(_vec[right],pivot)) right--;
            _vec[left] = _vec[right];
        }
        _vec[left] = pivot;
        return left;
    }

    void print(){
        for(auto &elem : _vec){
            cout << elem << " ";
        }
        cout << endl;
    }

private:
    vector<T> _vec;
};

void test(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    //函数参数里传的是对象,模板参数里传的是类型
    MyQsort<int> sort(arr, 10, std::less<int>()); //加小括号,表明是对象
    sort.print();
}

int main()
{
    test();    
    return 0;
}
