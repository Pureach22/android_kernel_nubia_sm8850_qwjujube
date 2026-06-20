__int64 __fastcall csr_ll_insert_head(
        __int64 result,
        __int64 *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  __int64 **v13; // x9
  int v14; // w10
  __int64 **v15; // x8

  if ( !result )
    return qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a4, a5, a6, a7, a8, a9, a10, a11, "csr_ll_insert_head");
  if ( *(_DWORD *)(result + 84) == -1582119721 )
  {
    if ( (a3 & 1) != 0 )
    {
      v11 = result;
      result = qdf_mutex_acquire(result + 16);
      v13 = *(__int64 ***)(v11 + 8);
      *a2 = v11;
      a2[1] = (__int64)v13;
      *v13 = a2;
      LODWORD(v13) = *(_DWORD *)(v11 + 80);
      v14 = *(_DWORD *)(v11 + 84);
      *(_QWORD *)(v11 + 8) = a2;
      *(_DWORD *)(v11 + 80) = (_DWORD)v13 + 1;
      if ( v14 == -1582119721 )
        return qdf_mutex_release(v11 + 16);
    }
    else
    {
      v15 = *(__int64 ***)(result + 8);
      *a2 = result;
      a2[1] = (__int64)v15;
      *v15 = a2;
      LODWORD(v15) = *(_DWORD *)(result + 80);
      *(_QWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 80) = (_DWORD)v15 + 1;
    }
  }
  return result;
}
