__int64 __fastcall csr_ll_purge(
        __int64 result,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  char v11; // w21
  __int64 v12; // x8
  __int64 *v13; // x9

  if ( !result )
    return qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a3, a4, a5, a6, a7, a8, a9, a10, "csr_ll_purge");
  if ( *(_DWORD *)(result + 84) == -1582119721 )
  {
    if ( (a2 & 1) != 0 )
    {
      v10 = result;
      v11 = a2;
      qdf_mutex_acquire(result + 16);
      a2 = v11;
      result = v10;
    }
    do
    {
      if ( *(_DWORD *)(result + 84) != -1582119721 )
        break;
      v12 = *(_QWORD *)(result + 8);
      if ( v12 == result )
        break;
      v13 = *(__int64 **)(v12 + 8);
      *(_QWORD *)(result + 8) = v13;
      *v13 = result;
      --*(_DWORD *)(result + 80);
    }
    while ( v12 );
    if ( (a2 & 1) != 0 && *(_DWORD *)(result + 84) == -1582119721 )
      return qdf_mutex_release(result + 16);
  }
  return result;
}
