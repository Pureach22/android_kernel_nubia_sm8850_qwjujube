__int64 __fastcall target_if_wmi_chan_width_to_phy_ch_width(int a1)
{
  if ( (unsigned int)(a1 - 1) > 8 )
    return 0;
  else
    return dword_AD0730[a1 - 1];
}
