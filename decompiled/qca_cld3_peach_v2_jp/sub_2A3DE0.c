__int64 sub_2A3DE0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2AADB4);
  return ucfg_mlme_get_restart_beaconing_on_ch_avoid();
}
