__int64 sub_2D60D4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DD0A8);
  return ucfg_mlme_get_channel_bonding_24ghz();
}
