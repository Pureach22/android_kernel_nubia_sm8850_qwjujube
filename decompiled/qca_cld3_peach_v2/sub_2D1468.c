__int64 sub_2D1468()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D843C);
  return wlan_mlme_get_channel_bonding_5ghz();
}
