__int64 __usercall sub_4CA07C@<X0>(__int64 a1@<X3>, __int64 a2@<X8>)
{
  __int64 v2; // x19

  *(_QWORD *)(v2 + 488) = a2;
  *(_QWORD *)(v2 + 496) = a1;
  return wma_add_bss_lfr3();
}
