__int64 __fastcall utils_dfs_get_rcsa_flags(__int64 a1, _BYTE *a2, _BYTE *a3)
{
  if ( !wlan_pdev_get_dfs_obj(a1) )
    return 16;
  *a2 = 0;
  *a3 = 0;
  return 0;
}
