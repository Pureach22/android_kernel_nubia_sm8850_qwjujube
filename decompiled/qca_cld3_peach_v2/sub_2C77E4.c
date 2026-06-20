__int64 sub_2C77E4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2CE7B8);
  return wlan_mlme_get_auto_channel_weight();
}
