__int64 __fastcall lpass_cdc_va_macro_get_channel_map(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  __int64 v3; // x22
  __int64 device_ptr; // x0
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 result; // x0
  __int64 v12; // x19

  v3 = *(_QWORD *)(a1 + 96);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 + 24), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v3 + 24), "%s: null device for macro!\n", "lpass_cdc_va_macro_get_channel_map");
    return 4294967274LL;
  }
  v8 = *(_QWORD *)(device_ptr + 152);
  if ( !v8 || !*(_QWORD *)(v8 + 168) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v3 + 24), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_get_channel_map");
    return 4294967274LL;
  }
  v9 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)(v9 - 1) >= 3 )
  {
    v12 = device_ptr;
    result = __ratelimit(&lpass_cdc_va_macro_get_channel_map__rs, "lpass_cdc_va_macro_get_channel_map");
    if ( (_DWORD)result )
    {
      dev_err(v12, "%s: Invalid AIF\n", "lpass_cdc_va_macro_get_channel_map");
      return 0;
    }
  }
  else
  {
    *a3 = *(_QWORD *)(v8 + 8 * v9 + 1256);
    v10 = *(unsigned int *)(a1 + 8);
    if ( (unsigned int)v10 > 3 )
    {
      __break(0x5512u);
      return lpass_cdc_va_mute_stream();
    }
    else
    {
      *a2 = *(_QWORD *)(v8 + 8 * v10 + 1288);
      return 0;
    }
  }
  return result;
}
