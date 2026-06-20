__int64 sub_2A2BA4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A9B78);
  return ucfg_mlme_get_roam_disable_config();
}
