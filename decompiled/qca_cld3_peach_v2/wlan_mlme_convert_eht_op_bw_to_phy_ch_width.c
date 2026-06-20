__int64 __fastcall wlan_mlme_convert_eht_op_bw_to_phy_ch_width(char a1)
{
  if ( (unsigned __int8)(a1 - 1) > 3u )
    return 0;
  else
    return dword_B35A08[(unsigned __int8)(a1 - 1)];
}
