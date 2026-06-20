__int64 __fastcall csr_ll_previous(
        __int64 a1,
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
  __int64 v11; // x19
  char v12; // w21
  _QWORD *v13; // x22
  _QWORD *v14; // x8
  __int64 v15; // x19

  if ( !a1 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a4, a5, a6, a7, a8, a9, a10, a11, "csr_ll_previous");
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
  v14 = *(_QWORD **)(a1 + 8);
  if ( v14 == (_QWORD *)a1 )
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
    v14 = (_QWORD *)v14[1];
    v15 = 0;
    if ( !v14 || v14 == (_QWORD *)a1 )
      goto LABEL_16;
  }
  if ( *a2 == a1 )
    v15 = 0;
  else
    v15 = *a2;
  if ( (a3 & 1) != 0 )
  {
LABEL_17:
    if ( *(_DWORD *)(a1 + 84) == -1582119721 )
      qdf_mutex_release(a1 + 16);
  }
  return v15;
}
