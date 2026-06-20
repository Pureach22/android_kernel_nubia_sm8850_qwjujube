__int64 __fastcall csr_ll_remove_head(
        __int64 a1,
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
  __int64 v10; // x19
  char v11; // w21
  __int64 v12; // x19
  _QWORD *v13; // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a3, a4, a5, a6, a7, a8, a9, a10, "csr_ll_remove_head");
    return 0;
  }
  if ( *(_DWORD *)(a1 + 84) != -1582119721 )
    return 0;
  if ( (a2 & 1) != 0 )
  {
    v10 = a1;
    v11 = a2;
    qdf_mutex_acquire(a1 + 16);
    a2 = v11;
    a1 = v10;
  }
  v12 = *(_QWORD *)(a1 + 8);
  if ( v12 == a1 )
  {
    v12 = 0;
    if ( (a2 & 1) == 0 )
      return v12;
  }
  else
  {
    v13 = *(_QWORD **)(v12 + 8);
    *(_QWORD *)(a1 + 8) = v13;
    *v13 = a1;
    --*(_DWORD *)(a1 + 80);
    if ( (a2 & 1) == 0 )
      return v12;
  }
  if ( *(_DWORD *)(a1 + 84) == -1582119721 )
    qdf_mutex_release(a1 + 16);
  return v12;
}
