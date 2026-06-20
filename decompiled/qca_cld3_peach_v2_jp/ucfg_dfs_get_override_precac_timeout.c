__int64 __fastcall ucfg_dfs_get_override_precac_timeout(__int64 a1)
{
  return 16 * (unsigned int)(wlan_pdev_get_dfs_obj(a1) == 0);
}
