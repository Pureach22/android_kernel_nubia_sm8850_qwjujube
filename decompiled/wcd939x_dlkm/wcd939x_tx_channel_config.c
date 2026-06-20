__int64 __fastcall wcd939x_tx_channel_config(__int64 a1, unsigned int a2, int a3)
{
  unsigned int v3; // w8
  __int64 v4; // x1
  __int64 v5; // x3

  if ( a2 >= 4 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_tx_channel_config__rs, "wcd939x_tx_channel_config") )
      printk(&unk_19A47, "wcd939x_tx_channel_config");
    return 4294967274LL;
  }
  else
  {
    v3 = dword_274C0[a2];
    v4 = dword_274D0[a2];
    if ( a3 )
      v5 = v3;
    else
      v5 = 0;
    snd_soc_component_update_bits(a1, v4, v3, v5);
    return 0;
  }
}
