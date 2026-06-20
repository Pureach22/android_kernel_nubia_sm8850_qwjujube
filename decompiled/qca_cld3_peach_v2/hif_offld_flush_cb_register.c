__int64 __fastcall hif_offld_flush_cb_register(__int64 a1, __int64 a2)
{
  if ( (unsigned int)hif_napi_enabled(a1, 0xFFFFFFFFLL) )
    return ((__int64 (__fastcall *)(__int64, __int64))hif_napi_rx_offld_flush_cb_register)(a1, a2);
  else
    return qdf_trace_msg(61, 2, "%s: NAPI not enabled", "hif_offld_flush_cb_register");
}
