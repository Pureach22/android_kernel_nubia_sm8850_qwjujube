__int64 __fastcall ucfg_dp_txrx_set_cpu_mask(
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
  __int64 (*v10)(void); // x8
  __int64 v12; // x0

  if ( !a1 )
    return 4;
  if ( *(_QWORD *)a1 )
  {
    v10 = *(__int64 (**)(void))(**(_QWORD **)a1 + 624LL);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != -1355198606 )
        __break(0x8228u);
      v12 = v10();
      if ( v12 )
        return dp_rx_tm_set_cpu_mask(v12 + 16, a2);
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a3, a4, a5, a6, a7, a8, a9, a10, "cdp_soc_get_dp_txrx_handle");
  }
  return 5;
}
