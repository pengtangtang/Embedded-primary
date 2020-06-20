/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：CMap.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月08日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _CMAP_H
#define _CMAP_H

#include "Node.h"
#include "Edge.h"
#include <vector>


/*数据结构之图：
 * 属性：最大顶点容纳量  当前顶点数  顶点数组  临界矩阵（顶点间是否有边）  边集合（边的具体信息）
 * 方法：
 * 	公有方法：
 * 	 构造函数  析构函数  顶点添加函数  顶点重置函数  边权值设置函数（有向图与无向图）  临界矩阵打印函数
 * 	 深度优先遍历函数  广度优先遍历函数 最小生成树之普利姆算法函数  最小生成树之克鲁斯卡尔算法函数  
 * 	 私有方法：
 * 	  临界矩阵权值获取函数  广度优先本层顶点相关的下层顶点获取函数  边集合中最小边获取函数  顶点是否在点集合判断函数  顶点合并函数
 *
 *图所需的辅助类：
 		顶点类：
			属性：顶点数值  访问标志
			方法：构造函数
		边类：
			属性：两个顶点  边的权值 访问标志
			方法：构造函数*/

class CMap{
	public:
		CMap(int capacity);
		~CMap();
		bool addNode(Node *pNode);
		void resetNode();
		bool setValueToMatrixForDirectedGraph(int row,int col,int val = 1);//为有向图设置边
		bool setValueToMatrixForUndirectedGraph(int row,int col,int val = 1);//为无向图设置边

		void printMatrix();//打印临界矩阵

		void depthFirstTraverse(int nodeIndex);//深度优先遍历
		void breadthFirstTraverse(int nodeIndex);//广度优先遍历

		/*指定第一个顶点，通过第一个点找到相关的边，再找出最小边*/
		void primTree(int nodeIndex);//普利姆算法生成树，求最小生成树
		void kruskalTree();//克鲁斯卡尔算法生成树
	private:
		bool getValueFromMatrix(int row,int col,int& val);//从矩阵中获取权值
		void breadthFirstTraverseImp(vector<int> preVec);

		int getMinEdge(vector<Edge> edgeVec);//获取最小边
		bool isInSet(vector<int> nodeSet,int target);//判断顶点是否在点集合中
		void mergeNodeSet(vector<int>& nodeSetA,vector<int> nodeSetB);//合并两个顶点集合
	private:

		/*图包含的属性：最大顶点容纳量  当前顶点数  顶点数组  临界矩阵（顶点间的边关系）  边集合（边的具体信息）*/
		int m_iCapacity;
		int m_iNodeCount;
		Node* m_pNodeArray;
		int *m_pMatrix;

		Edge* m_pEdge;//边指针，存最小生成树的边集合
};

#endif