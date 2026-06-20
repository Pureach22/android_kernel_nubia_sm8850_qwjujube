__int64 __fastcall wma_target_if_open(__int64 result)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(result + 24);
  if ( v1 )
  {
    ((void (__fastcall *)(__int64, __int64 (__fastcall *)(_QWORD *)))wlan_global_lmac_if_set_txops_registration_cb)(
      1,
      target_if_register_tx_ops);
    wlan_lmac_if_set_umac_txops_registration_cb(wma_register_tx_ops_handler);
    return wlan_global_lmac_if_open(v1);
  }
  return result;
}
