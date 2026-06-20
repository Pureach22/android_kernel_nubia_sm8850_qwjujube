__int64 __fastcall wlan_global_lmac_if_open(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x21
  void (__fastcall *v7)(__int64); // x8
  unsigned int v8; // w19

  if ( !a1 )
  {
    qdf_trace_msg(56, 2, "%s: psoc is NULL", "wlan_global_lmac_if_open");
    return 4;
  }
  v2 = _qdf_mem_malloc(2176, "wlan_global_lmac_if_open", 200);
  if ( !v2 )
  {
    v8 = 2;
    qdf_trace_msg(56, 2, "%s: tx_ops is NULL", "wlan_global_lmac_if_open");
    return v8;
  }
  v3 = v2;
  v4 = _qdf_mem_malloc(1312, "wlan_global_lmac_if_open", 206);
  if ( !v4 )
  {
    v8 = 2;
    qdf_trace_msg(56, 2, "%s: rx_ops is NULL", "wlan_global_lmac_if_open");
    _qdf_mem_free(v3);
    return v8;
  }
  v5 = *(_DWORD *)(a1 + 12);
  v6 = v4;
  *(_QWORD *)(a1 + 2128) = v3;
  *(_QWORD *)(a1 + 2136) = v4;
  if ( v5 != 1 )
  {
    qdf_trace_msg(56, 2, "%s: Invalid device type", "wlan_global_lmac_if_open");
    _qdf_mem_free(v3);
    _qdf_mem_free(v6);
    return 4;
  }
  v7 = (void (__fastcall *)(__int64))off_6A40D0;
  if ( *((_DWORD *)off_6A40D0 - 1) != -1972930274 )
    __break(0x8228u);
  v7(v3);
  wlan_lmac_if_umac_rx_ops_register(v6);
  wlan_lmac_if_sptrl_register_rx_ops(v6);
  target_if_wake_lock_init(a1);
  return 0;
}
