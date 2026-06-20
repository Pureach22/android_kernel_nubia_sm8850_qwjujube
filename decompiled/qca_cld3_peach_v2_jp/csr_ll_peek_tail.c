__int64 __fastcall csr_ll_peek_tail(
        __int64 *a1,
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
  __int64 *v10; // x20
  char v11; // w21
  __int64 v12; // x20

  if ( !a1 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a3, a4, a5, a6, a7, a8, a9, a10, "csr_ll_peek_tail");
    return 0;
  }
  if ( *((_DWORD *)a1 + 21) != -1582119721 )
    return 0;
  if ( (a2 & 1) != 0 )
  {
    v10 = a1;
    v11 = a2;
    qdf_mutex_acquire((__int64)(a1 + 2));
    a2 = v11;
    a1 = v10;
  }
  if ( (__int64 *)a1[1] != a1 )
  {
    v12 = *a1;
    if ( (a2 & 1) == 0 )
      return v12;
LABEL_11:
    if ( *((_DWORD *)a1 + 21) == -1582119721 )
      qdf_mutex_release((__int64)(a1 + 2));
    return v12;
  }
  v12 = 0;
  if ( (a2 & 1) != 0 )
    goto LABEL_11;
  return v12;
}
