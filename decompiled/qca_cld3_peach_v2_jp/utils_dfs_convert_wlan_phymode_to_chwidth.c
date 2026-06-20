__int64 __fastcall utils_dfs_convert_wlan_phymode_to_chwidth(int a1)
{
  if ( (unsigned int)(a1 - 5) > 0x19 )
    return 8;
  else
    return dword_A2D5C4[a1 - 5];
}
