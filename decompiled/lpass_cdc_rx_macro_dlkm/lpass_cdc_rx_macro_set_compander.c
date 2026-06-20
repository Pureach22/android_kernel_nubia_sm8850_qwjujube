__int64 __fastcall lpass_cdc_rx_macro_set_compander(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  int v6; // w20
  __int64 v7; // x19
  __int64 result; // x0
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 120);
  v4 = *(_QWORD *)(a1 + 128);
  v6 = *(_DWORD *)(a2 + 72);
  v14 = 0;
  v7 = *(unsigned int *)(v5 + 20);
  if ( (lpass_cdc_rx_macro_get_data(v4, v15, &v14, (__int64)"lpass_cdc_rx_macro_set_compander") & 1) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_5;
  }
  if ( (unsigned int)v7 <= 1 )
  {
    result = 0;
    *(_DWORD *)(v14 + 4 * v7 + 8) = v6;
LABEL_5:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return lpass_cdc_rx_macro_get_pcm_path();
}
