bool __fastcall csr_ll_find_entry(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x9
  _BOOL4 v11; // w8
  __int64 v12; // x10

  if ( !a1 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a3, a4, a5, a6, a7, a8, a9, a10, "csr_ll_find_entry");
    return 0;
  }
  if ( *(_DWORD *)(a1 + 84) != -1582119721 )
    return 0;
  v10 = *(_QWORD *)(a1 + 8);
  v11 = 0;
  if ( v10 == a1 )
    v12 = 0;
  else
    v12 = *(_QWORD *)(a1 + 8);
  if ( v12 && v12 != a1 )
  {
    do
    {
      v11 = v10 == a2;
      if ( v10 == a2 )
        break;
      v10 = *(_QWORD *)(v10 + 8);
      if ( !v10 )
        break;
    }
    while ( v10 != a1 );
  }
  return v11;
}
