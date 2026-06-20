__int64 __fastcall cfr_allow_suspend(
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
  const char *v11; // x2

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 1721) & 1) != 0 )
    {
      qdf_wake_lock_release(a1 + 1728, 0x1Au);
      qdf_runtime_pm_allow_suspend((__int64 *)(a1 + 1928));
      *(_BYTE *)(a1 + 1721) = 0;
      return 0;
    }
    v11 = "%s: wake lock not acquired";
  }
  else
  {
    v11 = "%s: NULL pcfr";
  }
  qdf_trace_msg(0x6Au, 8u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "cfr_allow_suspend");
  return 4;
}
