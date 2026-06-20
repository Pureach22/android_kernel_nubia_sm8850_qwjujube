__int64 __fastcall mlme_get_rx_ops(
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
  __int64 ext_hdl; // x0
  const char *v11; // x2

  if ( a1 )
  {
    ext_hdl = wlan_psoc_mlme_get_ext_hdl(a1);
    if ( ext_hdl )
      return ext_hdl + 7624;
    v11 = "%s: psoc legacy private object is NULL";
  }
  else
  {
    v11 = "%s: psoc object is NULL";
  }
  qdf_trace_msg(0x68u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "mlme_get_rx_ops");
  return 0;
}
