__int64 __fastcall lpass_cdc_va_mute_stream(__int64 a1, int a2)
{
  __int64 v2; // x19
  __int64 device_ptr; // x0
  __int64 v6; // x22
  __int64 v7; // x8
  char v8; // w28
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x26

  v2 = *(_QWORD *)(a1 + 96);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v2 + 24), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v2 + 24), "%s: null device for macro!\n", "lpass_cdc_va_mute_stream");
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(device_ptr + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 168) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v2 + 24), "%s: priv is null for macro!\n", "lpass_cdc_va_mute_stream");
    return 4294967274LL;
  }
  v7 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)v7 > 4 )
  {
LABEL_25:
    __break(0x5512u);
    return lpass_cdc_va_macro_hw_params();
  }
  else
  {
    v8 = 0;
    v9 = 0;
    while ( v9 <= 3 )
    {
      v10 = (unsigned __int8)(-1LL << v9) & (unsigned __int8)*(_QWORD *)(v6 + 1256 + 8 * v7) & 0xF;
      if ( !v10 )
        break;
      v11 = __clz(__rbit64(v10));
      if ( (snd_soc_component_read(v2, (unsigned int)(8 * v11 + 12548)) & 3) == 0 || *(_BYTE *)(v6 + 1580) == 1 )
      {
        if ( a2 )
        {
          snd_soc_component_update_bits(v2, (unsigned int)(((_DWORD)v11 << 7) + 13312), 16, 16);
        }
        else
        {
          *(_DWORD *)(v6 + 184) = *(_DWORD *)(a1 + 8);
          if ( (v8 & 1) == 0 )
            queue_delayed_work_on(32, system_freezable_wq, v6 + 192, 3);
          v8 = 1;
        }
      }
      v7 = *(unsigned int *)(a1 + 8);
      v9 = v11 + 1;
      if ( (unsigned int)v7 >= 5 )
        goto LABEL_25;
    }
    return 0;
  }
}
