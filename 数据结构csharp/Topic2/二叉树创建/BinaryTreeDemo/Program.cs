using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BinaryTreeDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Create().ToString());
            Console.Read();

        }
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
    }
}
