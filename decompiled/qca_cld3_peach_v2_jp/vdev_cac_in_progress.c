void __fastcall vdev_cac_in_progress(__int64 a1, __int64 a2, _BYTE *a3)
{
  if ( (*a3 & 1) == 0 && !(unsigned int)wlan_vdev_is_dfs_cac_wait(a2) )
    *a3 = 1;
}
