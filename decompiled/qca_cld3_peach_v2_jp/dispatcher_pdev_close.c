__int64 __fastcall dispatcher_pdev_close(__int64 a1)
{
  wlan_mgmt_txrx_pdev_close(a1);
  wlan_cfr_pdev_close(a1);
  regulatory_pdev_close(a1);
  return 0;
}
