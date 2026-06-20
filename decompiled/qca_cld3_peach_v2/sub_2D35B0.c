__int64 sub_2D35B0()
{
  char v0; // w17

  if ( (v0 & 0x40) == 0 )
    JUMPOUT(0x2D98A0);
  return wlan_mlme_get_24_chan_bonding_mode();
}
