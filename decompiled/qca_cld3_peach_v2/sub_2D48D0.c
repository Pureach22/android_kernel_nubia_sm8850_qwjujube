__int64 sub_2D48D0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DB8A4);
  return ucfg_mlme_get_roam_disable_config();
}
