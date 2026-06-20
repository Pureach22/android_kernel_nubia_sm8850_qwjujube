__int64 __fastcall lpass_cdc_va_macro_dec_mode_get(__int64 a1, __int64 a2)
{
  __int64 v6; // x21
  __int64 device_ptr; // x0
  __int64 v8; // x22
  __int64 result; // x0
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 128);
  v15 = 0;
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v6 + 24), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v6 + 24), "%s: null device for macro!\n", "lpass_cdc_va_macro_dec_mode_get");
    goto LABEL_10;
  }
  v8 = *(_QWORD *)(device_ptr + 152);
  if ( !v8 || !*(_QWORD *)(v8 + 168) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v6 + 24), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_dec_mode_get");
LABEL_10:
    result = 4294967274LL;
    goto LABEL_11;
  }
  result = lpass_cdc_va_macro_path_get(a1 + 32, &v15);
  if ( (_DWORD)result )
  {
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v15 < 4 )
  {
    result = 0;
    *(_QWORD *)(a2 + 72) = *(int *)(v8 + 4LL * v15 + 1540);
    goto LABEL_11;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return lpass_cdc_va_macro_dec_mode_put();
}
