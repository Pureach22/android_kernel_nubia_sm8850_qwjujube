__int64 __fastcall lpass_cdc_rx_macro_mux_get(__int64 a1, __int64 a2)
{
  __int64 v5; // x20
  __int64 v6; // x0
  unsigned __int64 v7; // x8
  __int64 result; // x0
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = snd_soc_dapm_kcontrol_widget();
  v6 = *(_QWORD *)(v5 + 40) - 208LL;
  v14 = 0;
  if ( (lpass_cdc_rx_macro_get_data(v6, v15, &v14, (__int64)"lpass_cdc_rx_macro_mux_get") & 1) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_5;
  }
  v7 = *(unsigned __int8 *)(v5 + 76);
  if ( v7 < 6 )
  {
    result = 0;
    *(_QWORD *)(a2 + 72) = *(int *)(v14 + 4 * v7 + 32);
LABEL_5:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return lpass_cdc_rx_macro_mux_put();
}
