__int64 __fastcall hdd_convert_wlan_phy_to_reg_phy(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x27 )
    return 8;
  else
    return (unsigned int)dword_AF9A98[a1 - 1];
}
