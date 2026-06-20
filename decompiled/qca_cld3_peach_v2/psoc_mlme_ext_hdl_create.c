__int64 __fastcall psoc_mlme_ext_hdl_create(__int64 a1)
{
  __int64 v2; // x0

  v2 = _qdf_mem_malloc(0x1EA0u, "psoc_mlme_ext_hdl_create", 2033);
  *(_QWORD *)(a1 + 8) = v2;
  if ( !v2 )
    return 2;
  target_if_cm_roam_register_tx_ops(v2 + 7344);
  target_if_wfatestcmd_register_tx_ops(*(_QWORD *)(a1 + 8) + 7640LL);
  target_if_cm_roam_register_rx_ops(*(_QWORD *)(a1 + 8) + 7528LL);
  wlan_mlme_register_rx_ops((_QWORD *)(*(_QWORD *)(a1 + 8) + 7624LL));
  target_if_mlme_register_tx_ops(*(_QWORD *)(a1 + 8) + 7632LL);
  return 0;
}
