__int64 sub_2E0FCC()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2E7FA0);
  return cfg_p2p_get_go_link_monitor_period();
}
