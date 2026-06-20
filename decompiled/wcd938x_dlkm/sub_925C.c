__int64 sub_925C()
{
  __int64 v0; // x29

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x37C8);
  return wcd938x_tx_channel_config();
}
