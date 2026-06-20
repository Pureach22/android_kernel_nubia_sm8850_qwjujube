__int64 __fastcall lpass_cdc_wsa_macro_cooling_adjust_gain(__int64 result)
{
  __int64 v1; // x8
  _QWORD *v2; // x19
  __int64 v3; // x20

  if ( result == 696 )
    return printk(&unk_F838, "lpass_cdc_wsa_macro_cooling_adjust_gain");
  v1 = *(_QWORD *)(result - 696);
  if ( !v1 || !*(_QWORD *)(v1 + 744) )
    return dev_err(v1, "%s: DT node for wsa_priv does not exist\n", "lpass_cdc_wsa_macro_cooling_adjust_gain");
  if ( *(_BYTE *)(result - 542) == 1 )
  {
    v2 = (_QWORD *)(result - 336);
    v3 = result;
    snd_soc_component_update_bits(
      *(_QWORD *)(result - 336),
      9236,
      255,
      (unsigned __int8)(*(_BYTE *)(result - 20) - *(_BYTE *)(result - 8)));
    return snd_soc_component_update_bits(*v2, 9364, 255, (unsigned __int8)(*(_BYTE *)(v3 - 19) - *(_BYTE *)(v3 - 8)));
  }
  return result;
}
