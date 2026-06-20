__int64 __fastcall lpass_cdc_wsa2_macro_vi_feed_mixer_get(__int64 a1, __int64 a2)
{
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 v9; // x22
  unsigned __int64 v10; // x21
  __int64 device_ptr; // x0
  __int64 v12; // x8
  __int64 result; // x0

  v6 = snd_soc_dapm_kcontrol_widget();
  v7 = *(_QWORD *)(a1 + 120);
  v8 = *(_QWORD *)(v6 + 40);
  v9 = *(unsigned __int8 *)(v6 + 76);
  v10 = *(unsigned int *)(v7 + 20);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v8 - 184), 4);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v8 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_vi_feed_mixer_get");
    return 4294967274LL;
  }
  v12 = *(_QWORD *)(device_ptr + 152);
  if ( !v12 || !*(_QWORD *)(v12 + 248) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v8 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_vi_feed_mixer_get");
    return 4294967274LL;
  }
  if ( (unsigned int)v9 > 7 )
  {
    __break(0x5512u);
    __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
    return lpass_cdc_wsa2_macro_vi_feed_mixer_put();
  }
  else
  {
    result = 0;
    *(_QWORD *)(a2 + 72) = ((*(_QWORD *)(v12 + 8 * v9 + ((v10 >> 3) & 0x1FFFFFF8) + 264) >> v10) & 1) != 0;
  }
  return result;
}
