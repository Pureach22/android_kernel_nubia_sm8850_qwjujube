__int64 __fastcall wlan_mlme_convert_phy_ch_width_to_eht_op_bw(unsigned int a1)
{
  if ( a1 >= 8 )
    return 0;
  else
    return (unsigned int)(0x400000003020100uLL >> (8 * (unsigned __int8)a1));
}
