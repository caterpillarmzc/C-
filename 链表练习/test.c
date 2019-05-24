/**
* 基础链表练习
* 实现一个字符串链表，每插入一个字符串，链表会对其进行按字典进行排序（不区分大小写，如a在aa前，aa在b前等），
* 重复插入的字符串自动忽略，
* 通过索引号可以获取到对应位置上的字符串。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PRACTICE_LIST_H_
#define PRACTICE_LIST_H_
#if defined(__cplusplus) & __cplusplus
extern "C" {
#endif
#define ssize_t int	///<定义类型

	/**
	* 链表节点数据结构
	*/
	typedef struct tagLIST_NODE
	{

		char *str;
		struct tagLIST_NODE *next;

	}stLIST_NODE, *pstLIST_NODE;

	/**
	* 链表数据结构
	*/
	typedef struct tagLIST
	{
		/**
		* 向链表插入一条字符串数据。
		*
		* @return 成功插入返回0，重复插入返回0，失败返回-1。
		*/
		int
		(*insert)(struct tagLIST *const list, const char *str);

		/**
		* 从链表中移除一条指定的字符串数据。
		*
		* @return 移除成功返回0，否则返回-1。
		*/
		int
			(*remove)(struct tagLIST *const list, const char *str);

		/**
		* 返回链表的长度。
		*/
		ssize_t
			(*length)(struct tagLIST *const list);

		/**
		* 按序号查找到该序号上的字符串。
		*
		* @return 若对应需要上有字符串则把字符串拷贝到缓冲长度为stacklen的stack的缓冲中并返回字符串的长度，\n
		*          否则返回-1。
		*/
		ssize_t
			(*lookup)(struct tagLIST *const list, int id, char *stack, size_t stacklen);

		/**
		* 按顺序打印链表中的字符串数据。
		*
		* @return 无。
		*/
		void
			(*dump)(struct tagLIST *const list);

		struct tagLIST_NODE *next;	///<定义一个next指针,next指针存的是字符串链表的节点数据结构

	}stLIST, *pstLIST;

	/**
	* 创建链表。
	*
	* @retval 链表句柄 创建成功。
	* @retval NULL 创建失败。
	*/
	extern pstLIST
		LIST_create();

	/**
	* 释放链表。
	*
	* @param[in] list 链表句柄。
	*
	* @return 无。
	*/
	extern void
		LIST_release(pstLIST list);

#if defined(__cplusplus) & __cplusplus
}
#endif
#endif
