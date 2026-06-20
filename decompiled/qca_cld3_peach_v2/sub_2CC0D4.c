__int64 sub_2CC0D4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D30A8);
  return wlan_mlme_get_frag_threshold();
}
