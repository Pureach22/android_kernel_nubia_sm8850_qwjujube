__int64 __fastcall ucfg_wlan_mgmt_rx_srng_enabled(__int64 a1)
{
  return wlan_mgmt_rx_srng_cfg_enable(a1) & 1;
}
