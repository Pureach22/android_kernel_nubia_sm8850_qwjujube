__int64 __fastcall lpass_cdc_tx_macro_dec_mode_get(__int64 a1, __int64 a2)
{
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v13; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 128);
  v15[0] = 0;
  v13 = 0;
  if ( (lpass_cdc_tx_macro_get_data(v6, &v14, v15, (__int64)"lpass_cdc_tx_macro_dec_mode_get") & 1) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_6;
  }
  result = lpass_cdc_tx_macro_path_get(a1 + 32, &v13);
  if ( (_DWORD)result )
  {
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v13 < 8 )
  {
    result = 0;
    *(_QWORD *)(a2 + 72) = *(int *)(v15[0] + 4LL * v13 + 2648);
    goto LABEL_6;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return lpass_cdc_tx_macro_dec_mode_put();
}
