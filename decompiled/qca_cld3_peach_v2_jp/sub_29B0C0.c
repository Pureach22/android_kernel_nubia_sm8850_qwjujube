__int64 sub_29B0C0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A2094);
  return wlan_mlme_get_rts_threshold();
}
