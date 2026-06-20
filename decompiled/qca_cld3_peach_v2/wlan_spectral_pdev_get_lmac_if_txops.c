__int64 __fastcall wlan_spectral_pdev_get_lmac_if_txops(
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
  __int64 v9; // x8
  __int64 v10; // x8
  const char *v12; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 80);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 2128);
      if ( v10 )
        return v10 + 488;
      v12 = "%s: tx_ops is NULL";
    }
    else
    {
      v12 = "%s: psoc is NULL!";
    }
  }
  else
  {
    v12 = "%s: pdev is NULL!";
  }
  qdf_trace_msg(0x56u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_spectral_pdev_get_lmac_if_txops");
  return 0;
}
