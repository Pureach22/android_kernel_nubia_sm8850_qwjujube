__int64 sub_5C58C0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x5CC894);
  return cfg_tdls_get_uapsd_inactivity_time();
}
