__int64 __fastcall lpass_cdc_tx_macro_tx_mixer_get(__int64 a1, __int64 a2)
{
  __int64 v6; // x0
  __int64 v7; // x21
  unsigned __int64 v8; // x20
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v17[8]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = snd_soc_dapm_kcontrol_widget();
  v7 = *(unsigned __int8 *)(v6 + 76);
  v8 = *(unsigned int *)(*(_QWORD *)(a1 + 120) + 20LL);
  v9 = *(_QWORD *)(v6 + 40) - 208LL;
  v16 = 0;
  if ( (lpass_cdc_tx_macro_get_data(v9, v17, &v16, "lpass_cdc_tx_macro_tx_mixer_get") & 1) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_5;
  }
  if ( (unsigned int)v7 <= 4 )
  {
    result = 0;
    *(_QWORD *)(a2 + 72) = (*(_QWORD *)(v16 + 8 * v7 + ((v8 >> 3) & 0x1FFFFFF8) + 2544) >> v8) & 1LL;
LABEL_5:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return lpass_cdc_tx_macro_tx_mixer_put();
}
