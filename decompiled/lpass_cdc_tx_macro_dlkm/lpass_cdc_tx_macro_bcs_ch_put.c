__int64 __fastcall lpass_cdc_tx_macro_bcs_ch_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  int v3; // w19
  __int64 result; // x0
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v3 = *(_DWORD *)(a2 + 72);
  v6[0] = 0;
  if ( (lpass_cdc_tx_macro_get_data(v2, &v5, v6, (__int64)"lpass_cdc_tx_macro_bcs_ch_put") & 1) != 0 )
  {
    result = 0;
    *(int *)((char *)&dword_A78 + v6[0]) = v3;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
