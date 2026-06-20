__int64 __fastcall utils_dfs_get_nol_chfreq_and_chwidth(__int64 a1, __int64 a2, _DWORD *a3, _DWORD *a4, int a5)
{
  if ( !wlan_pdev_get_dfs_obj(a1) )
    return 16;
  dfs_get_nol_chfreq_and_chwidth(a2, a3, a4, a5);
  return 0;
}
