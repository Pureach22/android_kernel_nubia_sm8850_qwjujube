__int64 sub_B25C()
{
  __int64 v0; // x29

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x57C8);
  return wcd939x_tx_channel_config();
}
