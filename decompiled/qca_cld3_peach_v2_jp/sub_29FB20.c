__int64 sub_29FB20()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A6AF4);
  return wlan_mlme_get_channel_bonding_5ghz();
}
