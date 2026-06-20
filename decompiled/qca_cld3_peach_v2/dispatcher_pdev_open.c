__int64 __fastcall dispatcher_pdev_open(__int64 a1)
{
  int v2; // w0
  __int64 result; // x0

  if ( !(unsigned int)regulatory_pdev_open() )
  {
    v2 = wlan_cfr_pdev_open(a1);
    if ( v2 == 39 || !v2 )
    {
      if ( !(unsigned int)wlan_mgmt_txrx_pdev_open(a1) )
      {
        result = wlan_green_ap_pdev_open(a1);
        if ( !(_DWORD)result )
          return result;
        wlan_mgmt_txrx_pdev_close(a1);
      }
      wlan_cfr_pdev_close(a1);
    }
    regulatory_pdev_close(a1);
  }
  return 16;
}
