__int64 __fastcall lpass_cdc_rx_macro_set_port_map(__int64 a1, int a2, int a3, __int64 a4)
{
  _QWORD *v7; // x8
  __int64 result; // x0
  _DWORD v9[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v10; // [xsp+10h] [xbp-20h]
  __int64 v11; // [xsp+18h] [xbp-18h] BYREF
  __int64 v12[2]; // [xsp+20h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  if ( (lpass_cdc_rx_macro_get_data(a1, v12, &v11, (__int64)"lpass_cdc_rx_macro_set_port_map") & 1) != 0 )
  {
    v9[0] = a3;
    v9[1] = a2;
    v10 = a4;
    v7 = *(_QWORD **)((char *)off_C8 + v11);
    if ( v7 )
      result = swrm_wcd_notify(*v7, 9, v9);
    else
      result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
