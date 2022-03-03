/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:16:03
 * @FilePath: /Start_net/Array/ArrayWrapper.h
 * @Description:
 *********************************/

#ifndef _ARRAY_WRAPPER_H
#define _ARRAY_WRAPPER_H

#ifdef __cplusplus
extern "C"
{
#endif

    struct VLArray;

    extern struct VLArray* Init();
    extern void PushBack(struct VLArray* array, void* val);
    extern void PushFront(struct VLArray* array, void* val);
    extern void Insert(struct VLArray* array, int index, void* val);
    extern void PopBack(struct VLArray* array);
    extern void DeleteIndex(struct VLArray* array, int index);
    extern void* GetIndex(struct VLArray* array, int index);
    extern void Traverse(struct VLArray* array);
    extern int Size(struct VLArray* array);
    extern void Deinit(struct VLArray** array);

#ifdef __cplusplus
};
#endif

#endif