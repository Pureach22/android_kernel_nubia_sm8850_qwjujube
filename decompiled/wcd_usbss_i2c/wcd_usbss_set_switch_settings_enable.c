__int64 __fastcall wcd_usbss_set_switch_settings_enable(unsigned int a1, unsigned int a2)
{
  __int64 result; // x0
  char v4; // w21
  int v6; // w0
  unsigned int v7; // w19

  if ( !wcd_usbss_ctxt_ )
    return 4294967277LL;
  result = 4294967274LL;
  if ( a2 <= 1 && a1 <= 7 && *(_QWORD *)wcd_usbss_ctxt_ )
  {
    v4 = a1;
    v6 = acquire_runtime_env(wcd_usbss_ctxt_);
    if ( v6 < 0 )
    {
      v7 = v6;
      dev_err(
        *(_QWORD *)(wcd_usbss_ctxt_ + 8),
        "%s: acquire_runtime_env failed: %i\n",
        "wcd_usbss_set_switch_settings_enable",
        v6);
      return v7;
    }
    else
    {
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1027, (unsigned int)(1 << v4), a2 << v4, 0, 0, 0);
      release_runtime_env(wcd_usbss_ctxt_);
      return 0;
    }
  }
  return result;
}
