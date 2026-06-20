__int64 __fastcall lpass_cdc_tx_macro_tx_mixer_put(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x24
  __int64 v6; // x20
  __int64 v7; // x23
  unsigned int v8; // w21
  unsigned __int64 v9; // x22
  __int64 v10; // x8
  __int64 v11; // x9
  unsigned __int64 v12; // x10
  __int64 v13; // x11
  __int64 result; // x0
  __int64 v15; // x8
  unsigned __int64 v18; // x11
  unsigned __int64 v25; // x10
  __int64 v26; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = snd_soc_dapm_kcontrol_widget();
  v5 = *(_QWORD *)(v4 + 40);
  v6 = v4;
  v7 = *(unsigned __int8 *)(v4 + 76);
  v8 = *(_DWORD *)(a2 + 72);
  v9 = *(unsigned int *)(*(_QWORD *)(a1 + 120) + 20LL);
  v26 = 0;
  v27[0] = 0;
  if ( (lpass_cdc_tx_macro_get_data(v5 - 208, v27, &v26, "lpass_cdc_tx_macro_tx_mixer_put") & 1) != 0 )
  {
    if ( v8 )
    {
      if ( (unsigned int)v7 <= 4 )
      {
        if ( ((*(_QWORD *)(v26 + 8LL * (unsigned int)v7 + ((v9 >> 3) & 0x1FFFFFF8) + 2544) >> v9) & 1) != 0 )
        {
          dev_err(
            *(_QWORD *)(v5 - 184),
            "%s: channel is already enabled, dec_id = %d, dai_id = %d\n",
            "lpass_cdc_tx_macro_tx_mixer_put",
            (unsigned int)v9,
            (unsigned int)v7);
LABEL_10:
          snd_soc_dapm_mixer_update_power(*(_QWORD *)(v6 + 40), a1, v8, 0);
          result = 0;
          goto LABEL_11;
        }
        v10 = v26 + 8 * v7;
        v12 = v9 >> 6;
        v11 = 1LL << v9;
        v13 = v10 + 2544;
LABEL_16:
        _X10 = (unsigned __int64 *)(v13 + 8 * v12);
        __asm { PRFM            #0x11, [X10] }
        do
          v18 = __ldxr(_X10);
        while ( __stxr(v18 | v11, _X10) );
        ++*(_QWORD *)(v10 + 2576);
        goto LABEL_10;
      }
    }
    else if ( (unsigned int)v7 <= 4 )
    {
      v15 = v26 + 8 * v7;
      if ( ((*(_QWORD *)(v15 + ((v9 >> 3) & 0x1FFFFFF8) + 2544) >> v9) & 1) != 0 )
      {
        --*(_QWORD *)(v15 + 2576);
        _X8 = (unsigned __int64 *)(v15 + 2544 + 8LL * ((unsigned int)v9 >> 6));
        __asm { PRFM            #0x11, [X8] }
        do
          v25 = __ldxr(_X8);
        while ( __stxr(v25 & ~(1LL << v9), _X8) );
      }
      else
      {
        dev_err(
          *(_QWORD *)(v5 - 184),
          "%s: channel is already disabled, dec_id = %d, dai_id = %d\n",
          "lpass_cdc_tx_macro_tx_mixer_put",
          (unsigned int)v9,
          (unsigned int)v7);
      }
      goto LABEL_10;
    }
    __break(0x5512u);
    goto LABEL_16;
  }
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
