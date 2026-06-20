__int64 sub_2D6198()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DD16C);
  return ucfg_mlme_get_channel_bonding_5ghz();
}
