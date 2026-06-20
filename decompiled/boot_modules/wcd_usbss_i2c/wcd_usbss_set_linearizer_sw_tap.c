__int64 __fastcall wcd_usbss_set_linearizer_sw_tap(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // w9
  __int64 result; // x0
  int v6; // w0
  unsigned int v7; // w19

  if ( !wcd_usbss_ctxt_ )
    return 4294967277LL;
  v2 = a2 | a1;
  result = 4294967274LL;
  if ( v2 <= 0x3FF && *(_QWORD *)wcd_usbss_ctxt_ )
  {
    v6 = acquire_runtime_env(wcd_usbss_ctxt_);
    if ( v6 < 0 )
    {
      v7 = v6;
      dev_err(
        *(_QWORD *)(wcd_usbss_ctxt_ + 8),
        "%s: acquire_runtime_env failed: %i\n",
        "wcd_usbss_set_linearizer_sw_tap",
        v6);
      return v7;
    }
    else
    {
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1125, 255, (unsigned __int8)a1, 0, 0, 0);
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1126, 3, a1 >> 8, 0, 0, 0);
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1127, 255, (unsigned __int8)a1, 0, 0, 0);
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1128, 3, a1 >> 8, 0, 0, 0);
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1129, 255, (unsigned __int8)a2, 0, 0, 0);
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1130, 3, a2 >> 8, 0, 0, 0);
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1131, 255, (unsigned __int8)a2, 0, 0, 0);
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1132, 3, a2 >> 8, 0, 0, 0);
      release_runtime_env(wcd_usbss_ctxt_);
      return 0;
    }
  }
  return result;
}
