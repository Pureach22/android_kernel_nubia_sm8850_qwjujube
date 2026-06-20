__int64 __fastcall csr_ll_next(
        __int64 a1,
        __int64 a2,
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
  __int64 v11; // x19
  char v12; // w21
  __int64 v13; // x22
  __int64 v14; // x8
  __int64 v15; // x19

  if ( !a1 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a4, a5, a6, a7, a8, a9, a10, a11, "csr_ll_next");
    return 0;
  }
  if ( *(_DWORD *)(a1 + 84) != -1582119721 )
    return 0;
  if ( (a3 & 1) != 0 )
  {
    v11 = a1;
    v12 = a3;
    v13 = a2;
    qdf_mutex_acquire(a1 + 16);
    a2 = v13;
    a3 = v12;
    a1 = v11;
  }
  v14 = *(_QWORD *)(a1 + 8);
  if ( v14 == a1 )
  {
    v15 = 0;
    goto LABEL_16;
  }
  v15 = 0;
  if ( *(_DWORD *)(a1 + 84) != -1582119721 || !v14 )
  {
LABEL_16:
    if ( (a3 & 1) == 0 )
      return v15;
    goto LABEL_17;
  }
  while ( v14 != a2 )
  {
    v14 = *(_QWORD *)(v14 + 8);
    v15 = 0;
    if ( !v14 || v14 == a1 )
      goto LABEL_16;
  }
  if ( *(_QWORD *)(a2 + 8) == a1 )
    v15 = 0;
  else
    v15 = *(_QWORD *)(a2 + 8);
  if ( (a3 & 1) != 0 )
  {
LABEL_17:
    if ( *(_DWORD *)(a1 + 84) == -1582119721 )
      qdf_mutex_release(a1 + 16);
  }
  return v15;
}
