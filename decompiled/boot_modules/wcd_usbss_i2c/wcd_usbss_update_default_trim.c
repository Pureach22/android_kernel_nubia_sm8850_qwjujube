__int64 wcd_usbss_update_default_trim()
{
  int v0; // w0
  unsigned int v2; // w19

  if ( !wcd_usbss_ctxt_ )
    return 4294967277LL;
  if ( !*(_QWORD *)wcd_usbss_ctxt_ )
    return 4294967274LL;
  v0 = acquire_runtime_env(wcd_usbss_ctxt_);
  if ( v0 < 0 )
  {
    v2 = v0;
    dev_err(
      *(_QWORD *)(wcd_usbss_ctxt_ + 8),
      "%s: acquire_runtime_env failed: %i\n",
      "wcd_usbss_update_default_trim",
      v0);
    return v2;
  }
  else
  {
    regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 80, 1);
    regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 144, 0);
    regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 145, 0);
    regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 146, 0);
    release_runtime_env(wcd_usbss_ctxt_);
    return 0;
  }
}
