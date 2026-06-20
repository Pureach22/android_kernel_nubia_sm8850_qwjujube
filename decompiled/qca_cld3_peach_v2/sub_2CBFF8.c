__int64 sub_2CBFF8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D2FCC);
  return wlan_mlme_get_rts_threshold();
}
