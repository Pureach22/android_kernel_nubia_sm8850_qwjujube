__int64 __fastcall lpass_cdc_wsa2_macro_set_port_map(__int64 a1, int a2, int a3, __int64 a4)
{
  __int64 device_ptr; // x0
  __int64 v9; // x8
  _QWORD *v10; // x8
  __int64 result; // x0
  _DWORD v12[2]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 4);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_set_port_map");
    goto LABEL_9;
  }
  v9 = *(_QWORD *)(device_ptr + 152);
  if ( !v9 || !*(_QWORD *)(v9 + 248) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_set_port_map");
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  v10 = *(_QWORD **)(v9 + 144);
  v12[0] = a3;
  v12[1] = a2;
  v13 = a4;
  if ( v10 )
    result = swrm_wcd_notify(*v10, 9, v12);
  else
    result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
