__int64 sub_29E11C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A50F0);
  return wlan_mlme_get_idle_data_packet_count();
}
