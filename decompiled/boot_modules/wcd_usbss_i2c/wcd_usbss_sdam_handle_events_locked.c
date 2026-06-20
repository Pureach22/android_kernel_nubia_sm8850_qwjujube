__int64 __fastcall wcd_usbss_sdam_handle_events_locked(int a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x0
  __int64 v3; // x3
  _QWORD *v5; // x8

  v1 = (_QWORD *)wcd_usbss_ctxt_;
  if ( a1 > 2 )
  {
    if ( a1 != 3 )
    {
      if ( a1 != 5 && a1 != 7 )
        goto LABEL_29;
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 2, 32, 32, 0, 0, 0);
LABEL_12:
      regmap_update_bits_base(*v1, 37, 1, 0, 0, 0, 0);
      v2 = *v1;
      v3 = 0;
LABEL_13:
      regmap_update_bits_base(v2, 41, 1, v3, 0, 0, 0);
LABEL_14:
      regmap_update_bits_base(*v1, 1027, 24, 24, 0, 0, 0);
      if ( *(_BYTE *)(wcd_usbss_ctxt_ + 401) )
      {
        if ( (regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 16, 0, 0, 0, 0) & 0x80000000) == 0 )
        {
          usleep_range_state(10000, 10100, 2);
          *(_BYTE *)(wcd_usbss_ctxt_ + 401) = 0;
          return 0;
        }
        dev_err(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "%s: exit standby failed\n", "wcd_usbss_standby_control_locked");
        return 0;
      }
      return 0;
    }
LABEL_11:
    regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 2, 32, 32, 0, 0, 0);
    regmap_update_bits_base(*v1, 31, 1, 0, 0, 0, 0);
    regmap_update_bits_base(*v1, 34, 1, 0, 0, 0, 0);
    regmap_update_bits_base(*v1, 44, 32, 32, 0, 0, 0);
    if ( (*(_BYTE *)(wcd_usbss_ctxt_ + 536) & 1) != 0 )
      goto LABEL_14;
    goto LABEL_12;
  }
  switch ( a1 )
  {
    case 0:
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 2, 32, 0, 0, 0, 0);
      regmap_update_bits_base(*v1, 44, 32, 0, 0, 0, 0);
      regmap_update_bits_base(*v1, 31, 1, 1, 0, 0, 0);
      regmap_update_bits_base(*v1, 34, 1, 1, 0, 0, 0);
      v5 = (_QWORD *)wcd_usbss_ctxt_;
      if ( (*(_BYTE *)(wcd_usbss_ctxt_ + 536) & 1) == 0 )
      {
        regmap_update_bits_base(*v1, 37, 1, 1, 0, 0, 0);
        regmap_update_bits_base(*v1, 41, 1, 1, 0, 0, 0);
        v5 = (_QWORD *)wcd_usbss_ctxt_;
      }
      if ( (unsigned int)regmap_update_bits_base(*v5, 1027, 24, 0, 0, 0, 0) )
        printk(&unk_BA06);
      if ( (unsigned int)regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1045, 128, 0, 0, 0, 0) )
        printk(&unk_B55E);
      if ( (*(_BYTE *)(wcd_usbss_ctxt_ + 401) & 1) == 0 )
      {
        if ( (regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 16, 16, 0, 0, 0) & 0x80000000) == 0 )
        {
          *(_BYTE *)(wcd_usbss_ctxt_ + 401) = 1;
          return 0;
        }
        dev_err(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "%s: enter standby failed\n", "wcd_usbss_standby_control_locked");
        return 0;
      }
      return 0;
    case 1:
      goto LABEL_11;
    case 2:
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 2, 32, 0, 0, 0, 0);
      regmap_update_bits_base(*v1, 44, 32, 0, 0, 0, 0);
      regmap_update_bits_base(*v1, 31, 1, 1, 0, 0, 0);
      regmap_update_bits_base(*v1, 34, 1, 1, 0, 0, 0);
      if ( (*(_BYTE *)(wcd_usbss_ctxt_ + 536) & 1) != 0 )
        goto LABEL_14;
      regmap_update_bits_base(*v1, 37, 1, 1, 0, 0, 0);
      v2 = *v1;
      v3 = 1;
      goto LABEL_13;
  }
LABEL_29:
  dev_err(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "unexpected state:%d\n", a1);
  return 4294967274LL;
}
