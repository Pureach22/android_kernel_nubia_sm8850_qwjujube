__int64 __fastcall wlan_lmac_if_set_umac_txops_registration_cb(void *a1)
{
  wlan_lmac_if_umac_tx_ops_register = a1;
  return 0;
}
