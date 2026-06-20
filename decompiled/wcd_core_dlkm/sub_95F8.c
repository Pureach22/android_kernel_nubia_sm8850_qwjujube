__int64 __usercall sub_95F8@<X0>(__int64 a1@<X4>, __int64 a2@<X8>)
{
  __int64 v2; // x9

  *(_QWORD *)(a2 + 312) = a1;
  *(_QWORD *)(a2 + 320) = v2;
  return wcd_irq_exit();
}
