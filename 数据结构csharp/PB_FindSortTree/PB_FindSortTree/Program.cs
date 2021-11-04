using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PB_FindSortTree
{
    /*
     * 节点类
     */
    public class Node
    {
        public int data;
        public Node left;
        public Node right;

        public Node(int data, Node left, Node right)
        {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    /*
     * 二叉查找树类
     */
    public class FindSortTree
    {
        private Node root;

        private void AddTree(Node rootNode, int data)
        {
            if (rootNode.data > data)
            {
                if (rootNode.left == null)
                    rootNode.left = new Node(data, null, null);
                else
                    AddTree(rootNode.left, data);
            }
            else
            {
                if (rootNode.right == null)
                    rootNode.right = new Node(data, null, null);
                else
                    AddTree(rootNode.right,data);
            }
        }

        public void Add(int data)
        {
            if (root == null)
                root = new Node(data, null, null);
            else
                AddTree(root,data);
        }


        public Node SearchNode(int data)
        {
            Node node = null;
            Node cur = root;
            while (true)
            {
                if (cur == null)
                    break;
                if (data == cur.data)
                {
                    node = cur;
                    break;
                }
                if (data > cur.data)
                    cur = cur.right;
                else
                    cur = cur.left;
            }
            return node;
        }


        public static void Main(string[] args)
        {
            FindSortTree tree = new FindSortTree();
            Node n;

            tree.Add(3);
            tree.Add(12);
            tree.Add(7);
            tree.Add(42);
            tree.Add(23);
            tree.Add(37);

            Console.WriteLine("查找节点为：16");
            n = tree.SearchNode(16);
            if (n == null)
                Console.WriteLine("查找失败。");
            else
                Console.WriteLine("查找成功，查到节点为："+n.data);


        }
    }


}
