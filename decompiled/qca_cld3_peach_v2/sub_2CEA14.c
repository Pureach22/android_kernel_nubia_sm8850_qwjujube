__int64 __fastcall sub_2CEA14(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x2D59E8);
  return wlan_mlme_get_oem_eht_mlo_config(a1, a2);
}
