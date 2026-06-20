__int64 __fastcall sub_5F9C5C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, int a6)
{
  if ( (a6 & 0x20000000) != 0 )
    JUMPOUT(0x5FEA7C);
  return wifi_pos_register_get_fw_phy_mode_for_freq_cb(a1, a2);
}
