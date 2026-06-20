__int64 __fastcall cdp_enable_disable_vdev_tx_delay_stats(
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
  __int64 v9; // x8
  __int64 (*v10)(void); // x8

  if ( !*(_QWORD *)result )
    return qdf_trace_msg(
             0x89u,
             8u,
             "%s: Invalid Instance",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "cdp_enable_disable_vdev_tx_delay_stats");
  v9 = *(_QWORD *)(*(_QWORD *)result + 32LL);
  if ( v9 )
  {
    v10 = *(__int64 (**)(void))(v9 + 296);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != 1944199495 )
        __break(0x8228u);
      return v10();
    }
  }
  return result;
}
