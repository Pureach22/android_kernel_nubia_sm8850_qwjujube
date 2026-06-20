__int64 sub_2A1928()
{
  char v0; // w17

  if ( (v0 & 0x40) == 0 )
    JUMPOUT(0x2A7C18);
  return wlan_mlme_get_24_chan_bonding_mode();
}
