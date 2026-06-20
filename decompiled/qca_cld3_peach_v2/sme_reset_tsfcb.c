__int64 __fastcall sme_reset_tsfcb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  if ( a1 )
  {
    result = qdf_mutex_acquire(a1 + 12848);
    if ( !(_DWORD)result )
    {
      *(_QWORD *)(a1 + 13160) = 0;
      *(_QWORD *)(a1 + 13152) = 0;
      qdf_mutex_release(a1 + 12848);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: mac_handle is not valid", a2, a3, a4, a5, a6, a7, a8, a9, "sme_reset_tsfcb");
    return 4;
  }
  return result;
}
