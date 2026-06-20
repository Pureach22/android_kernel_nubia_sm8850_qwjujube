__int64 sub_2AF1E4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2B61B8);
  return cfg_p2p_get_go_keepalive_period();
}
