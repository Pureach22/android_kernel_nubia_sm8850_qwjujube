__int64 __fastcall lpass_cdc_wsa_macro_cps_feed_mixer_put(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x23
  __int64 v6; // x20
  __int64 v7; // x22
  unsigned int v8; // w21
  int v9; // w24
  __int64 device_ptr; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v14; // x9
  unsigned __int64 v17; // x10
  unsigned __int64 v20; // x10
  unsigned __int64 v27; // x11
  unsigned __int64 v30; // x11

  v4 = snd_soc_dapm_kcontrol_widget();
  v5 = *(_QWORD *)(v4 + 40);
  v6 = v4;
  v7 = *(unsigned __int8 *)(v4 + 76);
  v8 = *(_DWORD *)(a2 + 72);
  v9 = *(_DWORD *)(*(_QWORD *)(a1 + 120) + 20LL);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v5 - 184), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v5 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_cps_feed_mixer_put");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v11 = *(_QWORD *)(device_ptr + 152);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 360)) == 0 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v5 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_cps_feed_mixer_put");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( !v8 )
  {
    if ( v9 == 1 )
    {
      if ( (unsigned int)v7 > 8 )
        goto LABEL_31;
      if ( (*(_QWORD *)(v11 + 376 + 8 * v7) & 2) == 0 )
        goto LABEL_27;
      _X9 = (unsigned __int64 *)(v11 + 376 + 8 * v7);
      __asm { PRFM            #0x11, [X9] }
      do
        v30 = __ldxr(_X9);
      while ( __stxr(v30 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
    }
    else
    {
      if ( v9 )
        goto LABEL_27;
      if ( (unsigned int)v7 > 8 )
        goto LABEL_31;
      if ( (*(_QWORD *)(v11 + 376 + 8 * v7) & 1) == 0 )
        goto LABEL_27;
      _X9 = (unsigned __int64 *)(v11 + 376 + 8 * v7);
      __asm { PRFM            #0x11, [X9] }
      do
        v27 = __ldxr(_X9);
      while ( __stxr(v27 & 0xFFFFFFFFFFFFFFFELL, _X9) );
    }
    v14 = -1;
LABEL_26:
    *(_QWORD *)(v11 + 8 * v7 + 440) += v14;
    goto LABEL_27;
  }
  if ( v9 == 1 )
  {
    if ( (unsigned int)v7 <= 8 )
    {
      if ( (*(_QWORD *)(v11 + 376 + 8 * v7) & 2) == 0 )
      {
        _X9 = (unsigned __int64 *)(v11 + 376 + 8 * v7);
        __asm { PRFM            #0x11, [X9] }
        do
          v20 = __ldxr(_X9);
        while ( __stxr(v20 | 2, _X9) );
        v14 = 1;
        goto LABEL_26;
      }
      goto LABEL_27;
    }
LABEL_31:
    __break(0x5512u);
    goto LABEL_32;
  }
  if ( v9 )
    goto LABEL_27;
  if ( (unsigned int)v7 > 8 )
    goto LABEL_31;
  v12 = v11 + 376;
  if ( (*(_QWORD *)(v11 + 376 + 8 * v7) & 1) == 0 )
  {
LABEL_32:
    _X9 = (unsigned __int64 *)(v12 + 8 * v7);
    __asm { PRFM            #0x11, [X9] }
    do
      v17 = __ldxr(_X9);
    while ( __stxr(v17 | 1, _X9) );
    v14 = 1;
    goto LABEL_26;
  }
LABEL_27:
  snd_soc_dapm_mixer_update_power(*(_QWORD *)(v6 + 40), a1, v8, 0);
  return 0;
}
