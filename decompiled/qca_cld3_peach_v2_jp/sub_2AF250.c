__int64 sub_2AF250()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2B6224);
  return cfg_p2p_get_go_link_monitor_period();
}
