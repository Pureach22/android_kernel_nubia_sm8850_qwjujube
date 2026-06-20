__int64 __fastcall wlan_util_vdev_get_cdp_txrx_subtype(__int64 a1)
{
  unsigned int v1; // w8

  v1 = *(_DWORD *)(a1 + 16) - 2;
  if ( v1 > 5 )
    return 0;
  else
    return dword_AD2268[v1];
}
