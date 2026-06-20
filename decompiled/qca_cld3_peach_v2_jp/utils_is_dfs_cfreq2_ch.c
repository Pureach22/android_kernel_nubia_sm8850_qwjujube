__int64 __fastcall utils_is_dfs_cfreq2_ch(__int64 a1)
{
  __int64 result; // x0

  result = wlan_pdev_get_dfs_obj(a1);
  if ( result )
    return (*(_WORD *)(*(_QWORD *)(result + 14888) + 16LL) & 0xC) == 4;
  return result;
}
