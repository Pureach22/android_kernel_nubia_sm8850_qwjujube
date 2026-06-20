__int64 sub_2D57C8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DC79C);
  return ucfg_mlme_get_mws_coex_pcc_channel_avoid_delay();
}
