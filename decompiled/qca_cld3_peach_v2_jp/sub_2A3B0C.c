__int64 sub_2A3B0C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2AAAE0);
  return ucfg_mlme_get_mws_coex_scc_channel_avoid_delay();
}
