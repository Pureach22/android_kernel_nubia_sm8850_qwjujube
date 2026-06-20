__int64 __fastcall dp_soc_tx_desc_sw_pools_deinit(__int64 a1)
{
  __int64 result; // x0
  unsigned int num_tx_desc_pool; // w20
  unsigned int v4; // w21

  result = wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40));
  if ( !(_DWORD)result )
  {
    num_tx_desc_pool = wlan_cfg_get_num_tx_desc_pool(*(_QWORD *)(a1 + 40));
    v4 = wlan_cfg_get_num_tx_desc_pool(*(_QWORD *)(a1 + 40));
    dp_tx_flow_control_deinit(a1);
    dp_tx_tso_desc_pool_deinit(a1, num_tx_desc_pool);
    dp_tx_tso_num_seg_pool_deinit(a1, num_tx_desc_pool);
    return ((__int64 (__fastcall *)(__int64, _QWORD))dp_tx_ext_desc_pool_deinit)(a1, v4);
  }
  return result;
}
