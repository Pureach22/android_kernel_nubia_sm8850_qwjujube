__int64 __fastcall csr_ll_is_list_empty(
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
  __int64 result; // x0
  _BOOL4 v12; // w19

  if ( !a1 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a3, a4, a5, a6, a7, a8, a9, a10, "csr_ll_is_list_empty");
    return 1;
  }
  if ( *(_DWORD *)(a1 + 84) != -1582119721 )
    return 1;
  if ( (a2 & 1) == 0 )
    return *(_QWORD *)(a1 + 8) == a1;
  qdf_mutex_acquire(a1 + 16);
  result = *(_QWORD *)(a1 + 8) == a1;
  if ( *(_DWORD *)(a1 + 84) == -1582119721 )
  {
    v12 = *(_QWORD *)(a1 + 8) == a1;
    qdf_mutex_release(a1 + 16);
    return v12;
  }
  return result;
}
