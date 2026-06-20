__int64 sub_2A43A8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2AB37C);
  return ucfg_mlme_get_channel_bonding_24ghz();
}
