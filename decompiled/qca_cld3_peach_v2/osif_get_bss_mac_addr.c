__int64 __fastcall osif_get_bss_mac_addr(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 184);
  if ( !v1 )
    return 0;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1) & 1) != 0 )
    return v1 + 792;
  return v1 + 48;
}
