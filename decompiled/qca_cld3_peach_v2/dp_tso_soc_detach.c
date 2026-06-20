__int64 __fastcall dp_tso_soc_detach(__int64 a1)
{
  unsigned int num_tx_desc_pool; // w20

  num_tx_desc_pool = wlan_cfg_get_num_tx_desc_pool(*(_QWORD *)(a1 + 40));
  dp_tx_tso_desc_pool_deinit(a1, num_tx_desc_pool);
  dp_tx_tso_num_seg_pool_deinit(a1, num_tx_desc_pool);
  ((void (__fastcall *)(__int64, _QWORD))dp_tx_tso_desc_pool_free)(a1, num_tx_desc_pool);
  ((void (__fastcall *)(__int64, _QWORD))dp_tx_tso_num_seg_pool_free)(a1, num_tx_desc_pool);
  return 0;
}
