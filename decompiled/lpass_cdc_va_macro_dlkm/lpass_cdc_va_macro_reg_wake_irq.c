__int64 __fastcall lpass_cdc_va_macro_reg_wake_irq(__int64 a1, int a2)
{
  __int64 v3; // x0
  __int64 device_ptr; // x0
  __int64 v5; // x8
  _QWORD *v6; // x8
  __int64 result; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 24);
  v8 = a2;
  device_ptr = lpass_cdc_get_device_ptr(v3, 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_va_macro_reg_wake_irq");
    goto LABEL_9;
  }
  v5 = *(_QWORD *)(device_ptr + 152);
  if ( !v5 || !*(_QWORD *)(v5 + 168) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_reg_wake_irq");
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  v6 = *(_QWORD **)(v5 + 1360);
  if ( v6 )
    result = swrm_wcd_notify(*v6, 8, &v8);
  else
    result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
