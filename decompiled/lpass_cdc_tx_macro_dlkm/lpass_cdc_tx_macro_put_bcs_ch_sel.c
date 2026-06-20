__int64 __fastcall lpass_cdc_tx_macro_put_bcs_ch_sel(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  unsigned __int64 v4; // x3
  __int64 result; // x0
  __int64 v6; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v7[2]; // [xsp+10h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 128);
  if ( (lpass_cdc_tx_macro_get_data(v3, &v6, v7, (__int64)"lpass_cdc_tx_macro_put_bcs_ch_sel") & 1) != 0
    && (v4 = *(_QWORD *)(a2 + 72), v4 <= 0xC) )
  {
    snd_soc_component_update_bits(v3, 12508, 15, v4);
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
