using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace NoPowerGraph
{
    /// <summary>
    /// 图的顶点
    /// </summary>
    class CruNode
    {
        /// <summary>
        /// 顶点值
        /// </summary>
        public Object NodeValue { get; set; }

        public CruNode(Object nodeValue)
        {
            this.NodeValue = nodeValue;
        }

        public override string ToString()
        {
            return NodeValue == null ? "" : NodeValue.ToString();
        }
    }
}
