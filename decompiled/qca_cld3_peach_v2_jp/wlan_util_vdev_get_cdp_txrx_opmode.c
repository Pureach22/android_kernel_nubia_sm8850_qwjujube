__int64 __fastcall wlan_util_vdev_get_cdp_txrx_opmode(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(unsigned int *)(a1 + 16);
  if ( (unsigned int)v1 > 0xB )
    return 0;
  else
    return dword_9E05F8[v1];
}
