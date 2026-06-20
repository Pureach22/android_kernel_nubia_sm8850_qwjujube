__int64 __fastcall lpass_cdc_wsa2_macro_vi_feed_mixer_put(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x23
  __int64 v6; // x20
  unsigned int v7; // w21
  int v8; // w24
  __int64 device_ptr; // x0
  __int64 v10; // x8
  __int64 v12; // x9
  unsigned __int64 v19; // x10
  unsigned __int64 v22; // x10
  unsigned __int64 v25; // x11
  unsigned __int64 v28; // x11

  v4 = snd_soc_dapm_kcontrol_widget();
  v5 = *(_QWORD *)(v4 + 40);
  v6 = v4;
  v7 = *(_DWORD *)(a2 + 72);
  v8 = *(_DWORD *)(*(_QWORD *)(a1 + 120) + 20LL);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v5 - 184), 4);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v5 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_vi_feed_mixer_put");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v10 = *(_QWORD *)(device_ptr + 152);
  if ( !v10 || !*(_QWORD *)(v10 + 248) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v5 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_vi_feed_mixer_put");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  *(_DWORD *)(v10 + 44) = *(_QWORD *)(a2 + 72);
  if ( !v7 )
  {
    if ( v8 == 1 )
    {
      if ( (*(_QWORD *)(v10 + 296) & 2) == 0 )
        goto LABEL_23;
      _X9 = (unsigned __int64 *)(v10 + 296);
      __asm { PRFM            #0x11, [X9] }
      do
        v28 = __ldxr(_X9);
      while ( __stxr(v28 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
    }
    else
    {
      if ( v8 || (*(_QWORD *)(v10 + 296) & 1) == 0 )
        goto LABEL_23;
      _X9 = (unsigned __int64 *)(v10 + 296);
      __asm { PRFM            #0x11, [X9] }
      do
        v25 = __ldxr(_X9);
      while ( __stxr(v25 & 0xFFFFFFFFFFFFFFFELL, _X9) );
    }
    v12 = -1;
LABEL_22:
    *(_QWORD *)(v10 + 352) += v12;
    goto LABEL_23;
  }
  if ( v8 != 1 )
  {
    if ( v8 || (*(_QWORD *)(v10 + 296) & 1) != 0 )
      goto LABEL_23;
    _X9 = (unsigned __int64 *)(v10 + 296);
    __asm { PRFM            #0x11, [X9] }
    do
      v19 = __ldxr(_X9);
    while ( __stxr(v19 | 1, _X9) );
    v12 = 1;
    goto LABEL_22;
  }
  if ( (*(_QWORD *)(v10 + 296) & 2) == 0 )
  {
    _X9 = (unsigned __int64 *)(v10 + 296);
    __asm { PRFM            #0x11, [X9] }
    do
      v22 = __ldxr(_X9);
    while ( __stxr(v22 | 2, _X9) );
    v12 = 1;
    goto LABEL_22;
  }
LABEL_23:
  snd_soc_dapm_mixer_update_power(*(_QWORD *)(v6 + 40), a1, v7, 0);
  return 0;
}
