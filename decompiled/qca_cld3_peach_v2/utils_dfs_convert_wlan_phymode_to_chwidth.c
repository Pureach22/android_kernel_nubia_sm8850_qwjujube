__int64 __fastcall utils_dfs_convert_wlan_phymode_to_chwidth(int a1)
{
  if ( (unsigned int)(a1 - 5) > 0x23 )
    return 8;
  else
    return dword_B2F92C[a1 - 5];
}
