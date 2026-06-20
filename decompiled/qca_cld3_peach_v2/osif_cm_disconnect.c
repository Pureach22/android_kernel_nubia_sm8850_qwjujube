__int64 __fastcall osif_cm_disconnect(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  int v3; // w21
  const char *v7; // x0
  unsigned int v8; // w19

  v3 = *(unsigned __int8 *)(a2 + 168);
  v7 = (const char *)wlan_cm_reason_code_to_str(a3);
  qdf_trace_msg(
    72,
    4,
    "%s: %s(vdevid-%d): Received Disconnect reason:%d %s",
    "osif_cm_disconnect",
    (const char *)(a1 + 296),
    v3,
    a3,
    v7);
  v8 = mlo_disconnect(a2, 5, a3, 0);
  if ( v8 )
    qdf_trace_msg(72, 2, "%s: Disconnect failed with status %d", "osif_cm_disconnect", v8);
  return qdf_status_to_os_return(v8);
}
