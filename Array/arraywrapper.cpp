/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:15:47
 * @FilePath: /Start_net/Array/ArrayWrapper.cpp
 * @Description:
 *********************************/

#include "ArrayWrapper.h"
#include "array.h"

#ifdef __cplusplus
extern "C"
{
#endif

    struct VLArray
    {
        MyArray myArray;
        VLArray()
        {
            MyArray myArray;
        }
    };

    struct VLArray* Init()
    {
        return new struct VLArray;
    }

    void PushBack(struct VLArray* array, void* val)
    {
        array->myArray.PushBack(val);
    }

    void PushFront(struct VLArray* array, void* val)
    {

        array->myArray.PushFront(val);
    }

    void Insert(struct VLArray* array, int index, void* val)
    {
        array->myArray.Insert(index, val);
    }

    void PopBack(struct VLArray* array)
    {

        array->myArray.PopBack();
    }

    void DeleteIndex(struct VLArray* array, int index)
    {

        array->myArray.DeleteIndex(index);
    }

    void* GetIndex(struct VLArray* array, int index)
    {
        return array->myArray.GetIndex(index);
    }

    void Traverse(struct VLArray* array)
    {
        int i = 0;
        while (i < array->myArray.Size())
        {
            // auto ot = (*(array->myArray.Begin() + i));
            std::cout << "Array[" << i << "]:" << *(int*)(*(array->myArray.Begin() + i)) << std::endl;
            // std::cout << "Array[" << i << "]:" << *ot << std::endl;
            i++;
        }
    }

    int Size(struct VLArray* array)
    {
        return array->myArray.Size();
    }

    void Deinit(struct VLArray** array)
    {
        delete* array;
    }

    // int *Begin(struct VLArray *array)
    // {
    //     return array->myArray.Begin();
    // }

    // int *End(struct VLArray *array)
    // {
    //     return array->myArray.End();
    // }

    // int Capacity(struct VLArray *array)
    // {
    //     return array->myArray.Capacity();
    // }

    // void ExpCapacity(struct VLArray *array)
    // {
    //     array->myArray.ExpCapacity();
    // }

    // void CutCapacity(struct VLArray *array)
    // {

    //     array->myArray.CutCapacity();
    // }
#ifdef __cplusplus
};
#endif