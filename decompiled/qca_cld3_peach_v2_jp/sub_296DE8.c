__int64 __fastcall sub_296DE8(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x29DDBC);
  return wlan_mlme_get_band_capability(a1, a2);
}
