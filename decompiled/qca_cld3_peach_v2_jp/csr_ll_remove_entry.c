__int64 __fastcall csr_ll_remove_entry(
        __int64 a1,
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
  __int64 v11; // x19
  char v12; // w21
  __int64 *v13; // x22
  __int64 *v14; // x8
  unsigned int v15; // w19
  __int64 v16; // x9
  _QWORD *v18; // x8
  __int64 v19; // x9

  if ( !a1 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a4, a5, a6, a7, a8, a9, a10, a11, "csr_ll_remove_entry");
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
    if ( *(_DWORD *)(v11 + 84) != -1582119721 )
      return 0;
  }
  v14 = *(__int64 **)(a1 + 8);
  v15 = 0;
  if ( v14 == (__int64 *)a1 )
    v16 = 0;
  else
    v16 = *(_QWORD *)(a1 + 8);
  if ( v16 && v16 != a1 )
  {
    while ( v14 != a2 )
    {
      v14 = (__int64 *)v14[1];
      v15 = 0;
      if ( !v14 || v14 == (__int64 *)a1 )
        goto LABEL_18;
    }
    v19 = *v14;
    v18 = (_QWORD *)v14[1];
    v15 = 1;
    *(_QWORD *)(v19 + 8) = v18;
    *v18 = v19;
    --*(_DWORD *)(a1 + 80);
  }
LABEL_18:
  if ( (a3 & 1) != 0 && *(_DWORD *)(a1 + 84) == -1582119721 )
    qdf_mutex_release(a1 + 16);
  return v15;
}
