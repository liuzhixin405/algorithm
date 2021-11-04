using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StackDemo
{
    interface IStack
    {
        void Push(Object item);
        Object Pop();
        Object Peek();
        bool IsEmpty();
        int Size();
    }
}
