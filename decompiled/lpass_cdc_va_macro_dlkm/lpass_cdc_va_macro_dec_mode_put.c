__int64 __fastcall lpass_cdc_va_macro_dec_mode_put(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  int v4; // w21
  __int64 device_ptr; // x0
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v8; // x1
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 128);
  v4 = *(_DWORD *)(a2 + 72);
  v9 = 0;
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 + 24), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v3 + 24), "%s: null device for macro!\n", "lpass_cdc_va_macro_dec_mode_put");
    goto LABEL_10;
  }
  v6 = *(_QWORD *)(device_ptr + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 168) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v3 + 24), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_dec_mode_put");
LABEL_10:
    result = 4294967274LL;
    goto LABEL_11;
  }
  result = lpass_cdc_va_macro_path_get(a1 + 32, &v9);
  if ( (_DWORD)result )
  {
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v9 <= 3 )
  {
    result = 0;
    *(_DWORD *)(v6 + 4LL * v9 + 1540) = v4;
    goto LABEL_11;
  }
  __break(0x5512u);
  return lpass_cdc_va_macro_path_get(result, v8);
}
