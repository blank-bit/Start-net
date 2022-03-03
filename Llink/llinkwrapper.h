/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:03:02
 * @FilePath: /Start_net/Llink/LlinkWrapper.h
 * @Description:
 *********************************/

#ifndef _LLINK_WRAPPER_H
#define _LLINK_WRAPPER_H

#ifdef __cplusplus
extern "C"
{
#endif

    struct tagLlink;

    extern struct tagLlink* Init(void);
    extern void* getIndex(struct tagLlink* llink, int index);
    extern void* getHead(struct tagLlink* llink);
    extern void* getTail(struct tagLlink* llink);
    extern void addAtHead(struct tagLlink* llink, void* val);
    extern void addAtTail(struct tagLlink* llink, void* val);
    extern void addAtIndex(struct tagLlink* llink, int index, void* val);
    extern void deleteAtIndex(struct tagLlink* llink, int index);
    extern void deinit(struct tagLlink** llink);
    extern int getSize(struct tagLlink* llink);
    extern int isEmpty(struct tagLlink* llink);
    extern void traverse(struct tagLlink* llink);

#ifdef __cplusplus
};
#endif

#endif
