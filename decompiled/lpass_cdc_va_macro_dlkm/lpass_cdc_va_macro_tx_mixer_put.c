__int64 __fastcall lpass_cdc_va_macro_tx_mixer_put(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x24
  __int64 v6; // x20
  __int64 v7; // x23
  unsigned int v8; // w21
  unsigned __int64 v9; // x22
  __int64 device_ptr; // x0
  __int64 v11; // x10
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v15; // x8
  __int64 v16; // x8
  unsigned __int64 v19; // x10
  unsigned __int64 v26; // x11

  v4 = snd_soc_dapm_kcontrol_widget();
  v5 = *(_QWORD *)(v4 + 40);
  v6 = v4;
  v7 = *(unsigned __int8 *)(v4 + 76);
  v8 = *(_DWORD *)(a2 + 72);
  v9 = *(unsigned int *)(*(_QWORD *)(a1 + 120) + 20LL);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v5 - 184), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v5 - 184), "%s: null device for macro!\n", "lpass_cdc_va_macro_tx_mixer_put");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v12 = *(_QWORD *)(device_ptr + 152);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 168)) == 0 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v5 - 184), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_tx_mixer_put");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( !v8 )
  {
    if ( (unsigned int)v7 <= 4 )
    {
      v15 = v12 + 8 * v7;
      if ( ((*(_QWORD *)(v15 + ((v9 >> 3) & 0x1FFFFFF8) + 1256) >> v9) & 1) == 0 )
      {
        if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_tx_mixer_put__rs_119, "lpass_cdc_va_macro_tx_mixer_put") )
          dev_err(
            *(_QWORD *)(v5 - 184),
            "%s: channel is already disabled, dec_id = %d, dai_id = %d\n",
            "lpass_cdc_va_macro_tx_mixer_put",
            (unsigned int)v9,
            (unsigned int)v7);
        goto LABEL_18;
      }
      v13 = 1LL << v9;
      v11 = (unsigned int)v9 >> 6;
      --*(_QWORD *)(v15 + 1288);
      v12 = v15 + 1256;
      goto LABEL_25;
    }
LABEL_24:
    __break(0x5512u);
LABEL_25:
    _X8 = (unsigned __int64 *)(v12 + 8 * v11);
    __asm { PRFM            #0x11, [X8] }
    do
      v19 = __ldxr(_X8);
    while ( __stxr(v19 & ~v13, _X8) );
    goto LABEL_18;
  }
  if ( (unsigned int)v7 > 4 )
    goto LABEL_24;
  if ( ((*(_QWORD *)(v12 + 8LL * (unsigned int)v7 + ((v9 >> 3) & 0x1FFFFFF8) + 1256) >> v9) & 1) != 0 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_tx_mixer_put__rs, "lpass_cdc_va_macro_tx_mixer_put") )
      dev_err(
        *(_QWORD *)(v5 - 184),
        "%s: channel is already enabled, dec_id = %d, dai_id = %d\n",
        "lpass_cdc_va_macro_tx_mixer_put",
        (unsigned int)v9,
        (unsigned int)v7);
  }
  else
  {
    v16 = v12 + 8 * v7;
    _X10 = (unsigned __int64 *)(v16 + 1256 + 8 * (v9 >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v26 = __ldxr(_X10);
    while ( __stxr(v26 | (1LL << v9), _X10) );
    ++*(_QWORD *)(v16 + 1288);
  }
LABEL_18:
  snd_soc_dapm_mixer_update_power(*(_QWORD *)(v6 + 40), a1, v8, 0);
  return 0;
}
