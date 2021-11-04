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
     


        #region 二叉树的遍历
        public static void Main(String[] args)
        {
            //先序遍历：根---左---右
            //中序遍历:左--根--右
            //后续遍历：左--右 --根
            //ILinearList list =  RootFirst(Create().Root);
            // ILinearList list = RootMiddle(Create().Root);

            ILinearList list = RootLast(Create().Root);
            for (int i = 0; i < list.Size(); i++)
            {
                TreeNode node = (TreeNode)list.Get(i);
                Console.WriteLine(node.NodeValue);
            }

            Console.Read();
        }

        /// <summary>
        /// 创建二叉树
        /// </summary>
        /// <returns></returns>
        public static BinaryTree Create()
        {
            TreeNode a, b, c, d, e, f, g;
            g = new TreeNode() { NodeValue = "G" };
            f = new TreeNode() { NodeValue = "F" };
            e = new TreeNode() { NodeValue = "E", Left = f, Right = g };
            d = new TreeNode() { NodeValue = "D" };
            b = new TreeNode() { NodeValue = "B", Left = d, Right = e };
            c = new TreeNode() { NodeValue = "C" };
            a = new TreeNode() { NodeValue = "A", Left = b, Right = c };
            return new BinaryTree() { Root = a };
        }
        /// <summary>
        /// 先序遍历
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        public static ILinearList RootFirst(TreeNode root)
        {
            //根--左（先序）--右（先序）
            if (root == null)
            {
                return new SequenceList(10);
            }
            //list 用来存储所有访问到的结点
            ILinearList list = new SequenceList(20);
            //
            list.add(list.Size(), root);
            ILinearList lleft = RootFirst(root.Left);
            list.add(lleft);
            ILinearList lright = RootFirst(root.Right);
            list.add(lright);
            return list;
        }

        public static ILinearList RootMiddle(TreeNode root)
        {
            //list 用来存储所有访问到的结点
            ILinearList list = new SequenceList(20);
            if (root == null)
            {
                return new SequenceList(10);
            }
            ILinearList lleft = RootMiddle(root.Left);
            list.add(lleft);//遍历左子树

            list.add(list.Size(), root);//根遍历
            ILinearList lright = RootMiddle(root.Right);
            list.add(lright);
            return list;
        }
        /// <summary>
        /// 后续遍历
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public static ILinearList RootLast(TreeNode root)
        {
            //list 用来存储所有访问到的结点
            ILinearList list = new SequenceList(20);
            if (root == null)
            {
                return new SequenceList(10);
            }
            ILinearList lleft = RootLast(root.Left);
            list.add(lleft);//遍历左子树
            ILinearList lright = RootLast(root.Right);
            list.add(lright);//遍历右子树
            list.add(list.Size(), root);//根遍历
            return list;
        }
        #endregion


       
    }
}
