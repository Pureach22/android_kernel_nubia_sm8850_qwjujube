__int64 __fastcall wcd_usbss_dpdm_switch_update(char a1, char a2)
{
  int v4; // w0
  __int64 v5; // x3
  __int64 v6; // x3
  unsigned int updated; // w19

  if ( !wcd_usbss_ctxt_ )
    return 4294967277LL;
  if ( !*(_QWORD *)wcd_usbss_ctxt_ )
    return 4294967274LL;
  v4 = acquire_runtime_env(wcd_usbss_ctxt_);
  if ( v4 < 0 )
  {
    updated = v4;
    dev_err(
      *(_QWORD *)(wcd_usbss_ctxt_ + 8),
      "%s: acquire_runtime_env failed: %i\n",
      "wcd_usbss_dpdm_switch_update",
      v4);
  }
  else
  {
    if ( (a1 & 1) != 0 )
      v5 = 24;
    else
      v5 = 0;
    if ( (unsigned int)regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1027, 24, v5, 0, 0, 0) )
      printk(&unk_BA06);
    if ( (a2 & 1) != 0 )
      v6 = 128;
    else
      v6 = 0;
    updated = regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1045, 128, v6, 0, 0, 0);
    if ( updated )
      printk(&unk_B55E);
    release_runtime_env(wcd_usbss_ctxt_);
  }
  return updated;
}
