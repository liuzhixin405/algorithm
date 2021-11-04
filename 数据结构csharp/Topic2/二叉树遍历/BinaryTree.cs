using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    class BinaryTree
    {
        public TreeNode Root { get; set; }

        public bool IsEmpty()
        {
            return Root == null;
        }
        public override string ToString()
        {
            return Root.ToString();
        }
    }
}
