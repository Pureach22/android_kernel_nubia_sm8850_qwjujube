__int64 sub_29B19C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A2170);
  return wlan_mlme_get_frag_threshold();
}
