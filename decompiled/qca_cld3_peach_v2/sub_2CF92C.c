__int64 sub_2CF92C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D6900);
  return wlan_mlme_get_idle_data_packet_count();
}
