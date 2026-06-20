__int64 __fastcall hdd_convert_wlan_phy_to_reg_phy(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x1D )
    return 7;
  else
    return (unsigned int)dword_A07A38[a1 - 1];
}
