__int64 sub_2CEABC()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D5A90);
  return wlan_mlme_get_dtim_selection_diversity();
}
