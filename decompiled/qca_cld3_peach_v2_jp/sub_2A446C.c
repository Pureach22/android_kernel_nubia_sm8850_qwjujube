__int64 sub_2A446C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2AB440);
  return ucfg_mlme_get_channel_bonding_5ghz();
}
