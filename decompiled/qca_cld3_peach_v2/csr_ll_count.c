__int64 __fastcall csr_ll_count(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 84) == -1582119721 )
      return *(unsigned int *)(a1 + 80);
    else
      return 0;
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a2, a3, a4, a5, a6, a7, a8, a9, "csr_ll_count", v9, v10);
    return 0;
  }
}
