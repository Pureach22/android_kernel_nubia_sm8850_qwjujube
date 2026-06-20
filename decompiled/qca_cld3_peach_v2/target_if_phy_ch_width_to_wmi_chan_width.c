__int64 __fastcall target_if_phy_ch_width_to_wmi_chan_width(int a1)
{
  if ( (unsigned int)(a1 - 1) > 6 )
    return 0;
  else
    return dword_AD0790[a1 - 1];
}
