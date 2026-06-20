__int64 __fastcall lpass_cdc_rx_macro_mclk_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x8
  int *v5; // x19
  _QWORD *v6; // x8
  __int64 result; // x0
  int v8; // [xsp+4h] [xbp-1Ch] BYREF
  int *v9; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 40);
  v9 = nullptr;
  v8 = 9600000;
  if ( (lpass_cdc_rx_macro_get_data(v4 - 208, v10, &v9, (__int64)"lpass_cdc_rx_macro_mclk_event") & 1) == 0 )
  {
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( a3 == 8 )
  {
    if ( byte_48[(_QWORD)v9] == 1 )
      result = lpass_cdc_rx_macro_mclk_enable(v9, 0);
    else
      result = 0;
    goto LABEL_15;
  }
  if ( a3 != 1 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_mclk_event__rs, "lpass_cdc_rx_macro_mclk_event") )
      dev_err(*(_QWORD *)v9, "%s: invalid DAPM event %d\n", "lpass_cdc_rx_macro_mclk_event", a3);
    goto LABEL_14;
  }
  v5 = v9;
  if ( byte_56[(_QWORD)v9] == 1 )
    v8 = 11289600;
  v6 = *(_QWORD **)((char *)off_C8 + (_QWORD)v9);
  if ( v6 )
    swrm_wcd_notify(*v6, 5, &v8);
  result = lpass_cdc_rx_macro_mclk_enable(v5, 1);
  if ( (_DWORD)result )
    byte_48[(_QWORD)v5] = 0;
  else
    byte_48[(_QWORD)v5] = 1;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
