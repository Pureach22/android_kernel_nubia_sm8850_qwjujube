__int64 __fastcall lpass_cdc_va_macro_enable_micbias(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x21
  __int64 device_ptr; // x0
  __int64 v6; // x20
  __int64 v7; // x8
  int v8; // w9
  __int64 v9; // x19
  unsigned int v10; // w0
  unsigned int v11; // w20
  const char *v12; // x1
  __int64 result; // x0
  __int64 v14; // x19
  int v15; // w9
  bool v16; // zf
  __int64 v17; // x19
  unsigned int v18; // w0
  unsigned int v19; // w0

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
    {
      v12 = "%s: null device for macro!\n";
      goto LABEL_21;
    }
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(device_ptr + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 168) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
    {
      v12 = "%s: priv is null for macro!\n";
LABEL_21:
      dev_err(*(_QWORD *)(v3 - 184), v12, "lpass_cdc_va_macro_enable_micbias");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(v6 + 1504);
  if ( !v7 )
  {
    v14 = device_ptr;
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_enable_micbias__rs, "lpass_cdc_va_macro_enable_micbias") )
      dev_err(v14, "%s:regulator not provided in dtsi\n", "lpass_cdc_va_macro_enable_micbias");
    return 4294967274LL;
  }
  if ( a3 == 8 )
  {
    v15 = *(_DWORD *)(v6 + 1528) - 1;
    v16 = *(_DWORD *)(v6 + 1528) == 1;
    *(_DWORD *)(v6 + 1528) = v15;
    if ( v15 < 0 || v16 )
    {
      if ( v15 < 0 )
      {
        *(_DWORD *)(v6 + 1528) = 0;
        return 0;
      }
      v17 = device_ptr;
      v18 = regulator_disable(v7);
      if ( v18 )
      {
        v11 = v18;
        if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_enable_micbias__rs_185, "lpass_cdc_va_macro_enable_micbias") )
        {
          dev_err(v17, "%s: regulator disable failed, err = %d\n", "lpass_cdc_va_macro_enable_micbias", v11);
          return v11;
        }
        return v11;
      }
      regulator_set_voltage(*(_QWORD *)(v6 + 1504), 0, *(unsigned int *)(v6 + 1512));
      regulator_set_load(*(_QWORD *)(v6 + 1504), 0);
    }
    return 0;
  }
  if ( a3 != 1 )
    return 0;
  v8 = *(_DWORD *)(v6 + 1528);
  *(_DWORD *)(v6 + 1528) = v8 + 1;
  if ( v8 > 0 )
    return 0;
  v9 = device_ptr;
  v10 = regulator_set_voltage(v7, *(unsigned int *)(v6 + 1512), *(unsigned int *)(v6 + 1512));
  if ( v10 )
  {
    v11 = v10;
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_enable_micbias__rs_179, "lpass_cdc_va_macro_enable_micbias") )
    {
      dev_err(v9, "%s: Setting voltage failed, err = %d\n", "lpass_cdc_va_macro_enable_micbias", v11);
      return v11;
    }
    return v11;
  }
  v19 = regulator_set_load(*(_QWORD *)(v6 + 1504), *(unsigned int *)(v6 + 1516));
  if ( v19 )
  {
    v11 = v19;
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_enable_micbias__rs_181, "lpass_cdc_va_macro_enable_micbias") )
    {
      dev_err(v9, "%s: Setting current failed, err = %d\n", "lpass_cdc_va_macro_enable_micbias", v11);
      return v11;
    }
    return v11;
  }
  result = regulator_enable(*(_QWORD *)(v6 + 1504));
  if ( (_DWORD)result )
  {
    v11 = result;
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_enable_micbias__rs_183, "lpass_cdc_va_macro_enable_micbias") )
    {
      dev_err(v9, "%s: regulator enable failed, err = %d\n", "lpass_cdc_va_macro_enable_micbias", v11);
      return v11;
    }
    return v11;
  }
  return result;
}
