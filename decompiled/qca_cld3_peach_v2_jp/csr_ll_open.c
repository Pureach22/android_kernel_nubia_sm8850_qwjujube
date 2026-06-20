__int64 __fastcall csr_ll_open(
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
  __int64 result; // x0

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 84) == -1582119721 )
    {
      return 0;
    }
    else
    {
      *(_DWORD *)(a1 + 80) = 0;
      result = qdf_mutex_create(a1 + 16);
      if ( (_DWORD)result )
      {
        return 16;
      }
      else
      {
        *(_QWORD *)a1 = a1;
        *(_QWORD *)(a1 + 8) = a1;
        *(_DWORD *)(a1 + 84) = -1582119721;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a2, a3, a4, a5, a6, a7, a8, a9, "csr_ll_open");
    return 16;
  }
  return result;
}
