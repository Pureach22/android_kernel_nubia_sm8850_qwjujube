__int64 __fastcall target_cfr_callback(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x0
  __int64 result; // x0

  if ( a1 && a3 )
  {
    if ( a2 == 268 )
    {
      v13 = _qdf_nbuf_clone(a3);
      if ( v13 )
        wlan_cfr_rx_tlv_process(a1, v13);
    }
    else
    {
      qdf_trace_msg(0x6Au, 8u, "%s: event is %d", a4, a5, a6, a7, a8, a9, a10, a11, "target_cfr_callback", a2);
    }
    return _qdf_nbuf_free(a3);
  }
  result = qdf_trace_msg(
             0x6Au,
             2u,
             "%s: Invalid pdev %pK or data %pK for event %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "target_cfr_callback",
             a1,
             a3,
             a2);
  if ( a3 )
    return _qdf_nbuf_free(a3);
  return result;
}
