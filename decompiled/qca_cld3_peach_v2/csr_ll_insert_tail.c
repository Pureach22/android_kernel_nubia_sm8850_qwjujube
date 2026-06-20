__int64 __fastcall csr_ll_insert_tail(
        __int64 result,
        _QWORD *a2,
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
  __int64 v13; // x9
  int v14; // w10
  __int64 v15; // x8

  if ( !result )
    return qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a4, a5, a6, a7, a8, a9, a10, a11, "csr_ll_insert_tail");
  if ( *(_DWORD *)(result + 84) == -1582119721 )
  {
    if ( (a3 & 1) != 0 )
    {
      v11 = result;
      result = qdf_mutex_acquire(result + 16);
      v13 = *(_QWORD *)v11;
      *a2 = *(_QWORD *)v11;
      a2[1] = v11;
      *(_QWORD *)(v13 + 8) = a2;
      LODWORD(v13) = *(_DWORD *)(v11 + 80);
      v14 = *(_DWORD *)(v11 + 84);
      *(_QWORD *)v11 = a2;
      *(_DWORD *)(v11 + 80) = v13 + 1;
      if ( v14 == -1582119721 )
        return qdf_mutex_release(v11 + 16);
    }
    else
    {
      v15 = *(_QWORD *)result;
      *a2 = *(_QWORD *)result;
      a2[1] = result;
      *(_QWORD *)(v15 + 8) = a2;
      LODWORD(v15) = *(_DWORD *)(result + 80);
      *(_QWORD *)result = a2;
      *(_DWORD *)(result + 80) = v15 + 1;
    }
  }
  return result;
}
