__int64 __fastcall lpass_cdc_rx_macro_set_iir_gain(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x19
  __int64 v4; // x0
  unsigned int v5; // w20
  unsigned int v6; // w21
  unsigned int v7; // w22
  unsigned int v8; // w23
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w0

  if ( a3 == 4 || a3 == 2 )
  {
    v3 = *(_QWORD *)(a1 + 40) - 208LL;
    v4 = strnstr(*(_QWORD *)(a1 + 8), "IIR0", 5);
    if ( v4 )
      v5 = 6660;
    else
      v5 = 6788;
    if ( v4 )
      v6 = 6664;
    else
      v6 = 6792;
    if ( v4 )
      v7 = 6668;
    else
      v7 = 6796;
    if ( v4 )
      v8 = 6672;
    else
      v8 = 6800;
    v9 = snd_soc_component_read(v3, v5);
    snd_soc_component_write(v3, v5, v9);
    v10 = snd_soc_component_read(v3, v6);
    snd_soc_component_write(v3, v6, v10);
    v11 = snd_soc_component_read(v3, v7);
    snd_soc_component_write(v3, v7, v11);
    v12 = snd_soc_component_read(v3, v8);
    snd_soc_component_write(v3, v8, v12);
  }
  return 0;
}
