__int64 __fastcall ucfg_dfs_is_ap_cac_timer_running(__int64 a1, _DWORD *a2)
{
  if ( !wlan_pdev_get_dfs_obj(a1) )
    return 16;
  *a2 = 0;
  return 0;
}
