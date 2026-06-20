__int64 sub_631F10()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x638EE4);
  return cfg_tdls_get_uapsd_inactivity_time();
}
