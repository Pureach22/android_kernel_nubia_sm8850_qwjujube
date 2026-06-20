__int64 __fastcall sub_64EFDC(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x655FB0);
  return wlan_twt_cfg_get_congestion_timeout(a1, a2);
}
