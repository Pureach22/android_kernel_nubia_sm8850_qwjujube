__int64 __fastcall csr_ll_lock(
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
  if ( !result )
    return qdf_trace_msg(0x34u, 2u, "%s: Error!! pList is Null", a2, a3, a4, a5, a6, a7, a8, a9, "csr_ll_lock");
  if ( *(_DWORD *)(result + 84) == -1582119721 )
    return qdf_mutex_acquire(result + 16);
  return result;
}
