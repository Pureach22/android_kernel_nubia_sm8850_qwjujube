__int64 __fastcall lpass_cdc_va_macro_event_handler(__int64 a1, unsigned __int16 a2)
{
  __int64 device_ptr; // x0
  _QWORD *v5; // x21
  _QWORD *v6; // x8
  __int64 v7; // x19
  int v8; // w20
  __int64 v10; // x0
  int v11; // w0
  _QWORD *v12; // x8
  __int64 v13; // x19
  __int64 v14; // x19
  int v15; // w19
  __int64 v16; // x0
  __int64 v17; // x19
  __int64 mono_fast_ns; // x0

  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
    {
      dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_va_macro_event_handler");
      goto LABEL_35;
    }
LABEL_18:
    LODWORD(v6) = -22;
    return (unsigned int)v6;
  }
  v5 = *(_QWORD **)(device_ptr + 152);
  if ( !v5 || !v5[21] )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
    {
      dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_event_handler");
LABEL_35:
      LODWORD(v6) = -22;
      return (unsigned int)v6;
    }
    goto LABEL_18;
  }
  LODWORD(v6) = 0;
  if ( a2 <= 5u )
  {
    if ( a2 == 4 )
    {
      v12 = (_QWORD *)v5[170];
      *((_WORD *)v5 + 789) = 0;
      if ( v12 )
      {
        v13 = device_ptr;
        swrm_wcd_notify(*v12, 6, 0);
        device_ptr = v13;
      }
      if ( (*(_WORD *)(device_ptr + 488) & 7) != 0 || *(_DWORD *)(device_ptr + 500) != 2 )
      {
        v14 = device_ptr;
        if ( !(unsigned int)lpass_cdc_runtime_suspend() )
        {
          _pm_runtime_disable(v14, 1);
          _pm_runtime_set_status(v14, 2);
          pm_runtime_enable(v14);
        }
      }
      goto LABEL_38;
    }
    if ( a2 != 5 )
      return (unsigned int)v6;
    v6 = (_QWORD *)v5[170];
    *((_BYTE *)v5 + 1344) = 1;
    *((_BYTE *)v5 + 1578) = 1;
    if ( !v6 )
      return (unsigned int)v6;
    swrm_wcd_notify(*v6, 7, 0);
LABEL_38:
    LODWORD(v6) = 0;
    return (unsigned int)v6;
  }
  switch ( a2 )
  {
    case 0xCu:
      v10 = *v5;
      *((_BYTE *)v5 + 1579) = 1;
      _pm_runtime_resume(v10, 4);
      if ( (lpass_cdc_check_core_votes(*v5) & 1) == 0 )
      {
        if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_event_handler__rs_230, "lpass_cdc_va_macro_event_handler") )
          dev_err(*v5, "%s: va request core vote failed\n", "lpass_cdc_va_macro_event_handler");
        goto LABEL_38;
      }
      v11 = lpass_cdc_clk_rsc_request_clock(*v5, *((unsigned __int16 *)v5 + 766), *((unsigned __int16 *)v5 + 767), 1);
      if ( v11 < 0 )
      {
        v15 = v11;
        if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_event_handler__rs_231, "lpass_cdc_va_macro_event_handler") )
          dev_err(*v5, "%s, failed to enable clk, ret:%d\n", "lpass_cdc_va_macro_event_handler", v15);
      }
      else
      {
        lpass_cdc_clk_rsc_request_clock(*v5, *((unsigned __int16 *)v5 + 766), *((unsigned __int16 *)v5 + 767), 0);
      }
      v16 = _pm_runtime_suspend(*v5, 13);
      v17 = *v5;
      mono_fast_ns = ktime_get_mono_fast_ns(v16);
      LODWORD(v6) = 0;
      *(_QWORD *)(v17 + 520) = mono_fast_ns;
      return (unsigned int)v6;
    case 7u:
      lpass_cdc_rsc_clk_reset();
      goto LABEL_38;
    case 6u:
      LODWORD(v6) = *((unsigned __int16 *)v5 + 668);
      if ( *((_WORD *)v5 + 668) )
      {
        v7 = device_ptr;
        v8 = 500;
        do
        {
          msleep(20);
          --v8;
        }
        while ( *((_WORD *)v5 + 668) && v8 );
        if ( !v8 && (unsigned int)__ratelimit(&lpass_cdc_va_macro_event_handler__rs, "lpass_cdc_va_macro_event_handler") )
          dev_err(v7, "%s: va_mclk_users non-zero, SSR fail!!\n", "lpass_cdc_va_macro_event_handler");
        goto LABEL_38;
      }
      break;
  }
  return (unsigned int)v6;
}
