__int64 __fastcall lpass_cdc_rx_macro_get_compander(__int64 a1, __int64 a2)
{
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 result; // x0
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 120);
  v5 = *(_QWORD *)(a1 + 128);
  v14 = 0;
  v7 = *(unsigned int *)(v6 + 20);
  if ( (lpass_cdc_rx_macro_get_data(v5, v15, &v14, (__int64)"lpass_cdc_rx_macro_get_compander") & 1) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_5;
  }
  if ( (unsigned int)v7 < 2 )
  {
    result = 0;
    *(_QWORD *)(a2 + 72) = *(int *)(v14 + 4 * v7 + 8);
LABEL_5:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return lpass_cdc_rx_macro_set_compander();
}
