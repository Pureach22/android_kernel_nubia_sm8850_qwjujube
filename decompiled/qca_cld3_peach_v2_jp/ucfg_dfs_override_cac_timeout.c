__int64 __fastcall ucfg_dfs_override_cac_timeout(__int64 a1, __int64 a2, _DWORD *a3)
{
  if ( !wlan_pdev_get_dfs_obj(a1) )
    return 16;
  *a3 = 0;
  return 0;
}
