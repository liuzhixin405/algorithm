using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace NoPowerGraph
{
    /// <summary>
    /// 图的边
    /// </summary>
    class Border
    {
        #region 边的两个顶点
        public CruNode Fnode { get; set; }
        public CruNode Lnode { get; set; } 
        #endregion

        public Border(CruNode fnode, CruNode lnode)
        {
            this.Fnode = fnode;
            this.Lnode = lnode;
        }
    }
}
