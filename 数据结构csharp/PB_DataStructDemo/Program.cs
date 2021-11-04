using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /**
     * 说明 使用region标识圈起来的是各个测试代码
     * */
    class Program
    {
        /// <summary>
        /// 判断符号对匹配
        /// </summary>
        /// <param name="args"></param>
        /// <returns></returns>
        public static bool IsSymmetry(string args)
        {
            StackDemo.IStack statck = new SequenceStack();
            int length = args.Length;
            for (int i = 0; i < length; i++)
            {
                char temp = args[i];
                #region switch
                switch (temp)
                {
                    case '{':

                    case '[':

                    case '(':
                        statck.Push(temp.ToString());
                        break;

                    case '}':
                        {
                            if (statck.Size() > 0)
                            {
                                Console.WriteLine(statck.Pop().Equals("{"));
                            }
                            break;
                        }
                    case ']':
                        {
                            if (statck.Size() > 0)
                            {
                                Console.WriteLine(statck.Pop().Equals("["));
                            }
                            break;
                        }
                    case ')':
                        {
                            if (statck.Size() > 0)
                            {
                                Console.WriteLine(statck.Pop().Equals("("));
                            }
                            break;
                        }
                } 
                #endregion
            }//end of for
            return statck.IsEmpty();
        }

        #region 判断符号匹配
        //static void Main(string[] args)
        //{
        //    //string symbolString = "{ss[aa(bb)]}";
        //    //Console.WriteLine(IsSymmetry(symbolString));
        //    //Console.Read();


        //    DoubleLinkedList dlist = new DoubleLinkedList();
        //    #region 添加元素
        //    dlist.add(100);
        //    dlist.add(200);
        //    dlist.add(300);
        //    dlist.add(400);
        //    dlist.add(500);
        //    #endregion

        //    #region 输出元素的总数，每一个元素
        //    Console.WriteLine(dlist.Size());
        //    Console.Write("输出元素");
        //    for (int i = 0; i < dlist.Size(); i++)
        //    {
        //        Console.Write(dlist.Get(i)+" ");
        //    }
        //    Console.WriteLine();
        //    #endregion


        //    #region 删除第0个元素之后
        //    dlist.remove(0);
        //    Console.Write("删除第0个元素之后：");
        //    for (int i = 0; i < dlist.Size(); i++)
        //    {
        //        Console.Write(dlist.Get(i) + " ");
        //    }
        //    Console.WriteLine(); 
        //    #endregion

        //    #region 删除最后一个元素之后
        //    dlist.remove(dlist.Size() - 1);
        //    Console.Write("删除最后一个元素之后：");
        //    for (int i = 0; i < dlist.Size(); i++)
        //    {
        //        Console.Write(dlist.Get(i) + " ");
        //    }
        //    Console.WriteLine(); 
        //    #endregion


        //    #region 设置最后一个元素
        //    Console.Write("设置最后一个元素为1000：");
        //    dlist.Set(dlist.Size() - 1, 1000);
        //    for (int i = 0; i < dlist.Size(); i++)
        //    {
        //        Console.Write(dlist.Get(i) + " ");
        //    }
        //    Console.WriteLine(); 
        //    #endregion 
        //    Console.Read();
        //}
        #endregion

        #region FiBonacci数列-递归算法
        //static void Main(string[] args)
        //{
        //    //输出FiBonacci数列前10项
        //    for(int i=0;i<10;i++)
        //    {
        //        Console.WriteLine(Fibonacci.F(i)); 
        //    }

        //}
        #endregion

        #region 二叉树的遍历
        //public static void Main(String[] args)
        //{
        //    //先序遍历：根---左---右
        //    //中序遍历:左--根--右
        //    //后续遍历：左--右 --根
        //    //ILinearList list =  RootFirst(Create().Root);
        //    // ILinearList list = RootMiddle(Create().Root);
        //    ILinearList list = RootLast(Create().Root);
        //    for (int i = 0; i < list.Size(); i++)
        //    {
        //        TreeNode node = (TreeNode)list.Get(i);
        //        Console.WriteLine(node.NodeValue);
        //    }

        //    Console.Read();
        //}

        ///// <summary>
        ///// 创建二叉树
        ///// </summary>
        ///// <returns></returns>
        //public static BinaryTree Create()
        //{
        //    TreeNode a, b, c, d, e, f, g;
        //    g = new TreeNode() { NodeValue = "G" };
        //    f = new TreeNode() { NodeValue = "F" };
        //    e = new TreeNode() { NodeValue = "E", Left = f, Right = g };
        //    d = new TreeNode() { NodeValue = "D" };
        //    b = new TreeNode() { NodeValue = "B", Left = d, Right = e };
        //    c = new TreeNode() { NodeValue = "C" };
        //    a = new TreeNode() { NodeValue = "A", Left = b, Right = c };
        //    return new BinaryTree() { Root = a };
        //}
        ///// <summary>
        ///// 先序遍历
        ///// </summary>
        ///// <param name="node"></param>
        ///// <returns></returns>
        //public static ILinearList RootFirst(TreeNode root)
        //{
        //    //根--左（先序）--右（先序）
        //    if (root == null)
        //    {
        //        return new SequenceList(10);
        //    }
        //    //list 用来存储所有访问到的结点
        //    ILinearList list = new SequenceList(20);
        //    //
        //    list.add(list.Size(), root);
        //    ILinearList lleft = RootFirst(root.Left);
        //    list.add(lleft);
        //    ILinearList lright = RootFirst(root.Right);
        //    list.add(lright);
        //    return list;
        //}

        //public static ILinearList RootMiddle(TreeNode root)
        //{
        //    //list 用来存储所有访问到的结点
        //    ILinearList list = new SequenceList(20);
        //    if (root == null)
        //    {
        //        return new SequenceList(10);
        //    }
        //    ILinearList lleft = RootMiddle(root.Left);
        //    list.add(lleft);//遍历左子树

        //    list.add(list.Size(), root);//根遍历
        //    ILinearList lright = RootMiddle(root.Right);
        //    list.add(lright);
        //    return list;
        //}
        ///// <summary>
        ///// 后续遍历
        ///// </summary>
        ///// <param name="root"></param>
        ///// <returns></returns>
        //public static ILinearList RootLast(TreeNode root)
        //{
        //    //list 用来存储所有访问到的结点
        //    ILinearList list = new SequenceList(20);
        //    if (root == null)
        //    {
        //        return new SequenceList(10);
        //    }
        //    ILinearList lleft = RootLast(root.Left);
        //    list.add(lleft);//遍历左子树
        //    ILinearList lright = RootLast(root.Right);
        //    list.add(lright);//遍历右子树
        //    list.add(list.Size(), root);//根遍历
        //    return list;
        //}
        #endregion


        #region 顺序表 
        //public static void Main(String[] args)
        //{
        //    SequenceList sequeceList = new SequenceList(100);
        //    ILinearList list = sequeceList;
        //    list.add(list.Size(), "C#");
        //    list.add(list.Size(), "C");
        //    list.add(list.Size(), "C++");
        //    list.add(list.Size(), "VB");


        //     Console.WriteLine(list.Get(4));

        //    //list.remove(2);
        //    Console.WriteLine(list.Size());
        //    Console.Read();
        //}
        #endregion


        #region 栈
        //public static void Main(String[] arg)
        //{
        //    StackDemo.IStack istack = new SequenceStack();
        //    //入栈
        //    istack.Push("C#");
        //    istack.Push("C");
        //    istack.Push("C++");
        //    istack.Push("VB");
        //    //出栈
        //    for (int i = 0; i < istack.Size();)
        //    {
        //        Console.WriteLine(istack.Pop()+" ");
        //    }
        //    Console.Read();
        //}
        #endregion

        //#region 线性表的链式实现
        //public static void Main(string[] args)
        //{
        //    ILinearList list = new SingleLinkedList();
        //    list.add(0, 1);
        //    list.add(1, 2);
        //    list.add(2, 3);
        //    list.add(3, 4);
        //    list.add(4, 5);

        //    Console.WriteLine("获取第0个值 ：{0}",list.Get(0)); ;
        //    object obj = list.remove(3);
        //    for (int i = 0; i < list.Size(); i++)
        //    {
        //        Console.WriteLine(list.Get(i));
        //    }

        //    //抛出一个异常  list.add(10000, 11);
        //    //抛出一个异常 list.remove(99999);
        //}
     //   #endregion

        //#region 线性表的选择排序
        //public static void Main(String[] args)
        //{
        //    SequenceList lists = new SequenceList(20);
        //    ILinearList lineList = lists;
        //    lineList.add(0, 23);
        //    lineList.add(1, 45);
        //    lineList.add(2, 16);
        //    lineList.add(3, 7);
        //    lineList.add(4, 42);
        //    lineList.add(5, 3);
        //    ILinearList list = null;//为体现迭代，使用了list，list可以不要，因为lineList是引用类型
        //    for (int i = 0; i < lineList.Size(); i++)
        //    {
        //        ArraySort.Sort(lineList, i);
        //        lineList = list;
        //    }

        //    for (int i = 0; i < lineList.Size(); i++)
        //    {
        //        Console.WriteLine(lineList.Get(i));
        //    }
        //    Console.Read();
        //}
        //#endregion


        #region Queue
        public static void Main(string[] args)
        {
            IQueue queue = new LinkedQueue();
            Console.WriteLine("请输入打饭人员的姓名，输入f终止");
            while (true)
            {
                string name = Console.ReadLine();
                if (name != "f")
                {
                    queue.Push(name);
                }
                else
                {
                    break;
                }

            }
            while (!queue.IsEmpty())
            {
                Console.WriteLine(queue.Pop() + " 打饭完成，走出队列");
            }

            Console.Read();


        }
        #endregion
    }
}
