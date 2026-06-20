__int64 sub_2D5B0C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DCAE0);
  return ucfg_mlme_get_restart_beaconing_on_ch_avoid();
}
