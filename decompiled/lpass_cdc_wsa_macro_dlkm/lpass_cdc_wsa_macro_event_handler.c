__int64 __fastcall lpass_cdc_wsa_macro_event_handler(__int64 a1, __int16 a2)
{
  __int64 device_ptr; // x0
  __int64 v5; // x8
  _QWORD *v6; // x9
  __int64 v7; // x19
  __int64 v8; // x19
  _QWORD *v10; // x9
  __int64 v11; // x19

  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
    {
      dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_event_handler");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(device_ptr + 152);
  if ( !v5 || !*(_QWORD *)(v5 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
    {
      dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_event_handler");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  switch ( a2 )
  {
    case 7:
      v11 = device_ptr;
      ((void (*)(void))lpass_cdc_rsc_clk_reset)();
      lpass_cdc_rsc_clk_reset(v11, 6);
      break;
    case 5:
      v10 = *(_QWORD **)(v5 + 256);
      *(_BYTE *)(v5 + 776) = 1;
      *(_BYTE *)(v5 + 155) = 1;
      if ( v10 )
        swrm_wcd_notify(*v10, 7, 0);
      break;
    case 4:
      v6 = *(_QWORD **)(v5 + 256);
      *(_BYTE *)(v5 + 776) = 0;
      if ( v6 )
      {
        v7 = device_ptr;
        swrm_wcd_notify(*v6, 6, 0);
        device_ptr = v7;
      }
      if ( (*(_WORD *)(device_ptr + 488) & 7) != 0 || *(_DWORD *)(device_ptr + 500) != 2 )
      {
        v8 = device_ptr;
        if ( !(unsigned int)lpass_cdc_runtime_suspend() )
        {
          _pm_runtime_disable(v8, 1);
          _pm_runtime_set_status(v8, 2);
          pm_runtime_enable(v8);
        }
      }
      break;
  }
  return 0;
}
