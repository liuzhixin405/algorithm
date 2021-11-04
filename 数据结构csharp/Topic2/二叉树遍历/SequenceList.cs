using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /// <summary>
    /// 顺序表
    /// </summary>
    class SequenceList : ILinearList
    {
        private Object[] sList;//对象数组
        private int size; //顺序表的长度
        /// <summary>
        /// 默认容量10
        /// </summary>
        private const int defaultCapcity = 10;

        public SequenceList(int capacity)
        {
            if (capacity <= 0)
            {
                sList = new object[10];
            }
            else
            {
                sList = new object[capacity];
            }
            this.size = 0;

        }
        bool ILinearList.IsEmpty()
        {
            return size == 0;
        }

        int ILinearList.Size()
        {
            return size;
        }

        object ILinearList.Get(int index)
        {
            rangeCheck(index);
            return sList[index];
        }

        private void rangeCheck(int index)
        {
            if (index >= size || index < 0)
            {
                throw new IndexOutOfRangeException("索引越界");
            }
        }

        object ILinearList.Set(int index, object elem)
        {
            rangeCheck(index);
            Object temp = sList[index];
            sList[index] = elem;
            return temp;

        }

        bool ILinearList.add(int index, object elem)
        {
            //1,2,5,3,4
            //size 10, 11,12 
            //size == Slist.Length 内存分配
            //元素要后移动，插入

            if (index > size || index < 0)
            {
                throw new IndexOutOfRangeException("索引越界");
            }
            if (size == sList.Length)
            {
                Object[] temp = sList;
                this.sList = new Object[sList.Length * 2];
                for (int i = 0; i < temp.Length; i++)
                {

                    sList[i] = temp[i];
                }

            }
            for (int j = size - 1; j >= index; j--)
            {
                sList[j + 1] = sList[j];
            }
            sList[index] = elem;
            size++;
            return true;
        }

        object ILinearList.remove(int index)
        {
            //1,3,4,
            //删除数据，后边的数据前移
            //index
            rangeCheck(index);
            Object old = sList[index];
            for (int i = index; i < size - 1; i++)
            {
                sList[i] = sList[i + 1];
            }
            sList[size - 1] = null;
            size--;
            return old;
        }

        void ILinearList.clear()
        {

            for (int i = 0; i < size; i++)
            {
                this.sList[i] = null;
            }
            size = 0;

        }


        bool ILinearList.add(ILinearList subList)
        {
            int count = subList.Size();
            ILinearList list = this;
            for (int i = 0; i < count; i++)
            {
                list.add(list.Size(), subList.Get(i));
            }
            return true;
        }

      
    }
}
