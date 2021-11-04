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
        #region 边的两个顶点和权值
        public CruNode Fnode { get; set; }
        public CruNode Lnode { get; set; }

        public double Power { get; set; }
        #endregion

        public Border(CruNode fnode, CruNode lnode)
        {
            this.Fnode = fnode;
            this.Lnode = lnode;
        }
        public Border(double power,CruNode fnode, CruNode lnode):this(fnode,lnode)
        {
            this.Power = power;
        }
    }
}
