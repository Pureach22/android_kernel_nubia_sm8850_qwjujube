__int64 __fastcall wcd938x_codec_aux_dac_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x20
  int v6; // w8
  __int64 v7; // x4

  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  if ( a3 == 8 )
  {
    snd_soc_component_update_bits(v3 - 208, 13320, 4, 0);
  }
  else if ( a3 == 1 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
    wcd938x_rx_clk_enable(v4);
    snd_soc_component_update_bits(v4, 13320, 4, 4);
    snd_soc_component_update_bits(v4, 13321, 4, 4);
    snd_soc_component_update_bits(v4, 13391, 1, 1);
    v6 = *(_DWORD *)(v5 + 3184);
    if ( !v6 )
    {
      snd_soc_component_update_bits(v4, 12452, 4, 0);
      v6 = *(_DWORD *)(v5 + 3184);
    }
    v7 = *(unsigned int *)(v5 + 264);
    *(_DWORD *)(v5 + 3184) = v6 + 1;
    wcd_cls_h_fsm(v4, v5 + 224, 1, 8, v7);
  }
  return 0;
}
