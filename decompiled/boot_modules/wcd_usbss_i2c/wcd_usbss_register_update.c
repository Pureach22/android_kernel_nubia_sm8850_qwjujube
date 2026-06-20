__int64 __fastcall wcd_usbss_register_update(__int64 a1, char a2, __int64 a3)
{
  int v6; // w0
  unsigned __int8 *v7; // x21
  __int64 v8; // x1
  __int64 v9; // x0
  unsigned int v11; // w19

  if ( !wcd_usbss_ctxt_ )
    return 4294967277LL;
  if ( !*(_QWORD *)wcd_usbss_ctxt_ )
    return 4294967274LL;
  v6 = acquire_runtime_env(wcd_usbss_ctxt_);
  if ( v6 < 0 )
  {
    v11 = v6;
    dev_err(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "%s: acquire_runtime_env failed: %i\n", "wcd_usbss_register_update", v6);
    return v11;
  }
  if ( !a3 )
    goto LABEL_15;
  v7 = (unsigned __int8 *)(a1 + 4);
  while ( 1 )
  {
    v8 = *((unsigned int *)v7 - 1);
    v9 = *(_QWORD *)wcd_usbss_ctxt_;
    if ( (a2 & 1) == 0 )
      break;
    if ( (unsigned int)regmap_write(v9, v8, *v7) )
    {
      dev_err(
        *(_QWORD *)(wcd_usbss_ctxt_ + 8),
        "%s: USB-SS register 0x%x (value of 0x%x) write failed\n",
        "wcd_usbss_register_update",
        *((_DWORD *)v7 - 1),
        *(_DWORD *)v7);
      goto LABEL_15;
    }
LABEL_7:
    --a3;
    v7 += 8;
    if ( !a3 )
      goto LABEL_15;
  }
  if ( !(unsigned int)regmap_read(v9, v8, v7) )
    goto LABEL_7;
  dev_err(
    *(_QWORD *)(wcd_usbss_ctxt_ + 8),
    "%s: USB-SS register 0x%x read failed\n",
    "wcd_usbss_register_update",
    *((_DWORD *)v7 - 1));
LABEL_15:
  release_runtime_env(wcd_usbss_ctxt_);
  return 0;
}
