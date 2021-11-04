using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace NoPowerGraph
{
    /// <summary>
    /// 图
    /// </summary>
    class Graph
    {
        /// <summary>
        /// 顶点数组
        /// </summary>
        private CruNode[] nodes;
        /// <summary>
        /// 图的邻接矩阵
        /// </summary>
        private Border[,] adjmatrix;

    

        public Graph(CruNode[] nodes)
        {
            this.nodes = nodes;
            this.adjmatrix = new Border[nodes.Length, nodes.Length];
            
        }
        /// <summary>
        /// 连接各边，组成图，实质是设置顶点在邻接矩阵中的连通性
        /// </summary>
        /// <param name="borders"></param>
        public void Connect(Border[] borders)
        {
            foreach (Border border in borders)
            {
                CruNode fnode = border.Fnode;
                CruNode lnode = border.Lnode;
                int findex = FindIndex(fnode);
                int lindex = FindIndex(lnode);

                adjmatrix[findex, lindex] =border ;

                adjmatrix[lindex, findex] = border;
            }
        }
        /// <summary>
        /// 找出一个顶点在顶点集合中的位置
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        private int FindIndex(CruNode node)
        {
            for (int i = 0; i < nodes.Length; i++)
            {
                if (node.Equals(nodes[i]))
                {
                    return i;
                }
            }
            return -1;
        }

        /// <summary>
        /// 输出邻接矩阵：边、顶点
        /// </summary>
        public void printAdjMat()
        {
            Console.WriteLine("该有权图的邻接矩阵可以表示为：");
            Console.Write("  ");
            for (int k = 0; k < nodes.Length; k++)
            {
                Console.Write(nodes[k].ToString()+" ");
            }
            Console.WriteLine();
            for (int i = 0; i < nodes.Length; i++)
            {
                Console.Write( nodes[i].ToString()+" ");
                for (int j = 0; j < nodes.Length; j++)
                {
                    //Console.Write(adjmatrix[i,j]+" ");
                    Border border = adjmatrix[i, j];
                    if (border == null)
                    {
                        Console.Write("&" + " ");
                    }
                    else
                    {
                        Console.Write(adjmatrix[i,j].Power+" ");
                    }

                }
                Console.WriteLine();
            }//end of for
        }
    }
}
