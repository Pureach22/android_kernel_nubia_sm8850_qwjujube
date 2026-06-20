__int64 __fastcall wcd_usbss_linearizer_rdac_cal_code_select(unsigned int a1)
{
  bool v2; // cc
  __int64 result; // x0
  unsigned int v4; // w20
  int v5; // w0
  unsigned int v6; // w19

  if ( !wcd_usbss_ctxt_ )
    return 4294967277LL;
  v2 = a1 > 1;
  result = 4294967274LL;
  if ( !v2 && *(_QWORD *)wcd_usbss_ctxt_ )
  {
    v4 = a1;
    v5 = acquire_runtime_env(wcd_usbss_ctxt_);
    if ( v5 < 0 )
    {
      v6 = v5;
      dev_err(
        *(_QWORD *)(wcd_usbss_ctxt_ + 8),
        "%s: acquire_runtime_env failed: %i\n",
        "wcd_usbss_linearizer_rdac_cal_code_select",
        v5);
      return v6;
    }
    else
    {
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1043, 4, 4 * v4, 0, 0, 0);
      release_runtime_env(wcd_usbss_ctxt_);
      return 0;
    }
  }
  return result;
}
