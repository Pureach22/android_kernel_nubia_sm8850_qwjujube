__int64 __fastcall lpass_cdc_rx_macro_enable_rx_path_clk(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x2
  __int64 v5; // x19
  unsigned __int16 v6; // w20
  __int16 v7; // w21

  v4 = *(unsigned __int8 *)(a1 + 76);
  v5 = *(_QWORD *)(a1 + 40) - 208LL;
  v6 = 192 * v4 + 5128;
  if ( a3 == 8 )
  {
    snd_soc_component_update_bits(*(_QWORD *)(a1 + 40) - 208LL, (unsigned __int16)(192 * v4 + 5128), 16, 0);
    lpass_cdc_rx_macro_enable_interp_clk(v5, 8, *(unsigned __int8 *)(a1 + 76));
  }
  else if ( a3 == 1 )
  {
    v7 = 192 * v4 + 5120;
    lpass_cdc_rx_macro_enable_interp_clk(*(_QWORD *)(a1 + 40) - 208LL, 1, v4);
    snd_soc_component_update_bits(v5, v6, 16, 16);
    snd_soc_component_update_bits(v5, v7 & 0xFFC0, 32, 32);
  }
  return 0;
}
