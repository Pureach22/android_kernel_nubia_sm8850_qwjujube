__int64 __fastcall utils_dfs_cac_valid_reset_for_freq(__int64 a1)
{
  return 16 * (unsigned int)(wlan_pdev_get_dfs_obj(a1) == 0);
}
