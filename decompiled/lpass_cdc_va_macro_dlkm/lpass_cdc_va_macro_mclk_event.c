__int64 __fastcall lpass_cdc_va_macro_mclk_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x20
  __int64 device_ptr; // x0
  _QWORD *v6; // x19
  __int64 v7; // x20

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_va_macro_mclk_event");
    return 4294967274LL;
  }
  v6 = *(_QWORD **)(device_ptr + 152);
  if ( !v6 || !v6[21] )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_mclk_event");
    return 4294967274LL;
  }
  v7 = v3 - 208;
  if ( a3 == 8 )
  {
    if ( (*((_BYTE *)v6 + 1581) & 1) != 0 && *((_BYTE *)v6 + 1536) != 1 )
      lpass_cdc_tx_mclk_enable(v7, 0);
    else
      lpass_cdc_va_macro_mclk_enable(*(_QWORD **)(device_ptr + 152), 0);
    if ( *((int *)v6 + 393) >= 1 )
    {
      lpass_cdc_clk_rsc_request_clock(*v6, *((unsigned __int16 *)v6 + 766), 0, 0);
      --*((_DWORD *)v6 + 393);
    }
    return 0;
  }
  if ( a3 != 1 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_mclk_event__rs, "lpass_cdc_va_macro_mclk_event") )
      dev_err(*v6, "%s: invalid DAPM event %d\n", "lpass_cdc_va_macro_mclk_event", a3);
    return 4294967274LL;
  }
  if ( (unsigned int)lpass_cdc_clk_rsc_request_clock(*v6, *((unsigned __int16 *)v6 + 766), 0, 1) )
  {
    if ( (*((_BYTE *)v6 + 1581) & 1) == 0 )
      return lpass_cdc_va_macro_mclk_enable(v6, 1);
  }
  else
  {
    ++*((_DWORD *)v6 + 393);
    if ( (*((_BYTE *)v6 + 1581) & 1) == 0 )
      return lpass_cdc_va_macro_mclk_enable(v6, 1);
  }
  if ( *((_BYTE *)v6 + 1536) == 1 )
    return lpass_cdc_va_macro_mclk_enable(v6, 1);
  return lpass_cdc_tx_mclk_enable(v7, 1);
}
