__int64 __fastcall lpass_cdc_wsa_macro_mute_stream(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v3; // x19
  __int64 device_ptr; // x0
  __int64 v6; // x20
  unsigned int v7; // w8
  __int64 v8; // x19

  if ( a2 )
    return 0;
  v3 = *(_QWORD *)(a1 + 96);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 + 24), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_mute_stream");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(device_ptr + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_mute_stream");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v7 = *(_DWORD *)(a1 + 8);
  if ( v7 - 1 <= 1 )
  {
    lpass_cdc_wsa_pa_on(device_ptr, 0);
    if ( (unsigned int)(*(_DWORD *)(a1 + 8) - 1) <= 1 )
    {
      v8 = *(_QWORD *)(a1 + 96);
      snd_soc_component_update_bits(v8, 9216, 16, 0);
      snd_soc_component_update_bits(v8, 9240, 16, 0);
      snd_soc_component_update_bits(v8, 9344, 16, 0);
      snd_soc_component_update_bits(v8, 9368, 16, 0);
    }
    device_ptr = queue_delayed_work_on(32, system_freezable_wq, v6 + 48, 2);
    v7 = *(_DWORD *)(a1 + 8);
  }
  if ( v7 >= 9 )
  {
    __break(0x5512u);
    return lpass_cdc_wsa_macro_hw_params(device_ptr);
  }
  else
  {
    if ( (*(_QWORD *)(v6 + 376 + 8LL * v7) & 0x10) == 0 && (*(_QWORD *)(v6 + 376 + 8LL * v7) & 0x20) == 0 )
      return 0;
    result = *(_QWORD *)(v6 + 784);
    if ( result )
    {
      result = readl();
      if ( (_DWORD)result )
      {
        writel(result, *(_QWORD *)(v6 + 784));
        return 0;
      }
    }
  }
  return result;
}
