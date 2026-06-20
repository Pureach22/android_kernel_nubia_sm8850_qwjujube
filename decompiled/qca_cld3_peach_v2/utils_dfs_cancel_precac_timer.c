__int64 __fastcall utils_dfs_cancel_precac_timer(__int64 a1)
{
  return 16 * (unsigned int)(wlan_pdev_get_dfs_obj(a1) == 0);
}
