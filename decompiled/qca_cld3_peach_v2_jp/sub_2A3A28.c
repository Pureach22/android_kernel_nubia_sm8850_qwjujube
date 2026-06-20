__int64 sub_2A3A28()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2AA9FC);
  return ucfg_mlme_get_mws_coex_5g_nr_pwr_limit();
}
