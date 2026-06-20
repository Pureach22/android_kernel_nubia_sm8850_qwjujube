__int64 __fastcall lpass_cdc_rx_macro_int_dem_inp_mux_put(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x9
  unsigned int v6; // w8
  __int64 v7; // x1

  v4 = snd_soc_dapm_kcontrol_widget();
  v5 = *(_DWORD **)(a1 + 120);
  v6 = *(_DWORD *)(a2 + 72);
  if ( v6 >= v5[2] )
    return 4294967274LL;
  if ( *v5 == 5320 )
    v7 = 5316;
  else
    v7 = 5124;
  snd_soc_component_update_bits(*(_QWORD *)(v4 + 40) - 208LL, v7, 8, 8 * (unsigned int)(v6 != 0));
  return snd_soc_dapm_put_enum_double(a1, a2);
}
