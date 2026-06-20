__int64 __fastcall csr_ll_close(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x8
  __int64 *v11; // x9

  if ( !result )
    return qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a2, a3, a4, a5, a6, a7, a8, a9, "csr_ll_close");
  v9 = result;
  if ( *(_DWORD *)(result + 84) == -1582119721 )
  {
    qdf_mutex_acquire(result + 16);
    while ( *(_DWORD *)(v9 + 84) == -1582119721 )
    {
      v10 = *(_QWORD *)(v9 + 8);
      if ( v10 == v9 )
        goto LABEL_8;
      v11 = *(__int64 **)(v10 + 8);
      *(_QWORD *)(v9 + 8) = v11;
      *v11 = v9;
      --*(_DWORD *)(v9 + 80);
      if ( !v10 )
      {
        if ( *(_DWORD *)(v9 + 84) != -1582119721 )
          break;
LABEL_8:
        qdf_mutex_release(v9 + 16);
        break;
      }
    }
    result = qdf_mutex_destroy(v9 + 16);
    *(_DWORD *)(v9 + 84) = 0;
  }
  return result;
}
