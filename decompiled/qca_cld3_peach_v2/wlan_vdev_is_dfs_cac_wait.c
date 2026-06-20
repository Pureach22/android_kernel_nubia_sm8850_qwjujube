__int64 __fastcall wlan_vdev_is_dfs_cac_wait(__int64 a1)
{
  return 16 * (unsigned int)(*(_DWORD *)(a1 + 20) != 2);
}
