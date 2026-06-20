__int64 __fastcall osif_cm_disconnect_sync(__int64 a1, unsigned __int16 a2)
{
  int v3; // w20
  const char *v5; // x0
  __int64 v6; // x0

  v3 = *(unsigned __int8 *)(a1 + 168);
  v5 = (const char *)wlan_cm_reason_code_to_str(a2);
  qdf_trace_msg(72, 4, "%s: vdevid-%d: Received Disconnect reason:%d %s", "osif_cm_disconnect_sync", v3, a2, v5);
  v6 = mlo_sync_disconnect(a1, 5, a2, 0);
  return qdf_status_to_os_return(v6);
}
