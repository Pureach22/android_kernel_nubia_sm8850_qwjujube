__int64 __fastcall cfr_prevent_suspend(
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
  if ( a1 )
  {
    if ( *(_BYTE *)(a1 + 1721) == 1 )
    {
      qdf_trace_msg(0x6Au, 8u, "%s: acquired wake lock", a2, a3, a4, a5, a6, a7, a8, a9, "cfr_prevent_suspend");
      return 3;
    }
    else
    {
      qdf_wake_lock_acquire(a1 + 1728, 0x1Au);
      qdf_runtime_pm_prevent_suspend((__int64 *)(a1 + 1928));
      *(_BYTE *)(a1 + 1721) = 1;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x6Au, 8u, "%s: NULL pcfr", a2, a3, a4, a5, a6, a7, a8, a9, "cfr_prevent_suspend");
    return 4;
  }
}
