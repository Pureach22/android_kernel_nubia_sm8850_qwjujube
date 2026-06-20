__int64 sub_6534B0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x65A484);
  return ucfg_twt_cfg_get_congestion_timeout();
}
