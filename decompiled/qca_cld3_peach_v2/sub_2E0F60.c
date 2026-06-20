__int64 sub_2E0F60()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2E7F34);
  return cfg_p2p_get_go_keepalive_period();
}
