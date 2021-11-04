using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /// <summary>
    /// 树结点
    /// </summary>
    class TreeNode
    {
        //结点值
        public Object NodeValue { get; set; }
        //左孩子
        public TreeNode Left { get; set; }
        //右孩子
        public TreeNode Right { get; set; }

        public override string ToString()
        {
            string result = "(结点"+NodeValue.ToString();
            if (Left != null)
            {
                result += "左孩子:" + Left.ToString();
            }
            if(Right!=null)
            {
                result += "右孩子:"+Right.ToString();
            }
            result += ")";
            return result;
        }
    }
}
