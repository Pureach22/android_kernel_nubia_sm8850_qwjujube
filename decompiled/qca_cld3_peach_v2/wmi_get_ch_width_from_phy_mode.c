__int64 __fastcall wmi_get_ch_width_from_phy_mode(__int64 a1, unsigned int a2)
{
  if ( a2 > 0x20 )
    return 0;
  else
    return mode_to_width[a2];
}
