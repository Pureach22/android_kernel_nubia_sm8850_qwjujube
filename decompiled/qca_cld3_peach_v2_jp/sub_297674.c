__int64 sub_297674()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x29E648);
  return wlan_mlme_get_auto_channel_weight();
}
