__int64 __fastcall utils_dfs_fetch_nol_ie_info(__int64 a1, _BYTE *a2, _WORD *a3, _BYTE *a4)
{
  if ( !wlan_pdev_get_dfs_obj(a1) )
    return 16;
  *a2 = 0;
  *a3 = 0;
  *a4 = 0;
  return 0;
}
