__int64 __fastcall sub_2C6F58(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x2CDF2C);
  return wlan_mlme_get_band_capability(a1, a2);
}
