__int64 sub_2D5754()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DC728);
  return ucfg_mlme_get_mws_coex_5g_nr_pwr_limit();
}
