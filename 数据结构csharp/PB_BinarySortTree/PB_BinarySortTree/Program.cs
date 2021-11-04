using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PB_BinarySortTree
{
    /*
     * 当前节点类
     */
    class Node
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
    class BinarySortTree
    {
        private Node root;
        private static BinarySortTree tree = new BinarySortTree();

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
                    AddTree(rootNode.right, data);
            }
        }

        public void Add(int data)
        {
            if (root == null)
                root = new Node(data, null, null);
            else
                AddTree(root, data);
        }

        private void ShowTree(Node node)
        {
            if (node.left != null)
                ShowTree(node.left);
            
            Console.WriteLine(node.data + " ");

            if (node.right != null)
                ShowTree(node .right);
        }

        private void Show()
        {
            Console.WriteLine("中序遍历结果为：");
            ShowTree(root);
        }

        /*
         * 创建二叉树
         */
        private static void CreateTree()
        {
            tree.Add(15);
            tree.Add(12);
            tree.Add(9);
            tree.Add(14);
            tree.Add(13);
            tree.Add(19);
            tree.Add(18);
            tree.Add(22);
            tree.Add(23);
        }


        public static void Main(string[] args)
        {
            CreateTree();
            Console.WriteLine("插入节点：17");
            tree.Add(17);
            tree.Show();

        }
    }

}
