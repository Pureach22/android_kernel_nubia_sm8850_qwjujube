__int64 sub_709D88()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x710D5C);
  return ucfg_twt_cfg_get_congestion_timeout();
}
