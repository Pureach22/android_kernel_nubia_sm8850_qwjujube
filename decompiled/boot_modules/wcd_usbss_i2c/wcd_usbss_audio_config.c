__int64 __fastcall wcd_usbss_audio_config(__int64 a1, int a2, int a3)
{
  __int64 result; // x0
  int v6; // w0
  __int64 v7; // x0
  _QWORD *v8; // x8
  __int64 v9; // x1
  __int64 v10; // x2
  unsigned int v11; // w20
  unsigned int v12; // w19
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !wcd_usbss_ctxt_ )
  {
    result = 4294967277LL;
    goto LABEL_5;
  }
  if ( *(_QWORD *)wcd_usbss_ctxt_ )
  {
    v13 = 0;
    printk(&unk_B5D5);
    if ( (*(_BYTE *)(wcd_usbss_ctxt_ + 368) & 0xB8) == 0 )
    {
      result = 0;
      goto LABEL_5;
    }
    v6 = acquire_runtime_env(wcd_usbss_ctxt_);
    if ( v6 < 0 )
    {
      v12 = v6;
      dev_err(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "%s: acquire_runtime_env failed: %i\n", "wcd_usbss_audio_config", v6);
      result = v12;
      goto LABEL_5;
    }
    regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 1049, &v13);
    if ( (v13 & 7) != a3 )
    {
      if ( a2 )
      {
        printk(&unk_B8DC);
        v11 = -22;
        goto LABEL_16;
      }
      v7 = *(_QWORD *)wcd_usbss_ctxt_;
      if ( a3 == 1 )
      {
        regmap_write(v7, 1, 15);
        regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 61, 196);
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 7, 1, 0, 0, 0);
        v8 = (_QWORD *)wcd_usbss_ctxt_;
        v9 = 4;
        v10 = 16;
      }
      else
      {
        regmap_write(v7, 4, 16);
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 7, 4, 0, 0, 0);
        regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 1, 0);
        v8 = (_QWORD *)wcd_usbss_ctxt_;
        v9 = 61;
        v10 = 0;
      }
      regmap_write(*v8, v9, v10);
    }
    v11 = 0;
LABEL_16:
    release_runtime_env(wcd_usbss_ctxt_);
    result = v11;
    goto LABEL_5;
  }
  result = 4294967274LL;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
