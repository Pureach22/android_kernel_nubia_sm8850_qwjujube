__int64 __fastcall wcd_usbss_switch_update(int a1, int a2)
{
  int v5; // w0
  unsigned int v6; // w0
  __int64 v7; // x8
  unsigned int v8; // w9
  int v9; // w10
  __int64 *v10; // x8
  __int64 v11; // x0
  _QWORD *v12; // x8
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  unsigned int v16; // w19
  _QWORD *v17; // x8
  _QWORD *v18; // x8
  __int64 v19; // x2
  __int64 v20; // x3
  char v21; // w0
  int v22; // w9
  __int64 v23; // x0
  __int64 v24; // x8
  int v25; // w9
  _QWORD *v26; // x8

  if ( !wcd_usbss_ctxt_ )
    return 4294967277LL;
  if ( !*(_QWORD *)wcd_usbss_ctxt_ )
    return 4294967274LL;
  mutex_lock(wcd_usbss_ctxt_ + 408);
  printk(&unk_B6B7);
  v5 = acquire_runtime_env(wcd_usbss_ctxt_);
  if ( (v5 & 0x80000000) == 0 )
  {
    if ( a2 != 1 )
    {
      v6 = 0;
      if ( !a2 )
      {
        v7 = wcd_usbss_ctxt_;
        v8 = *(_DWORD *)(wcd_usbss_ctxt_ + 368) & ~(unsigned int)(1LL << a1);
        *(_DWORD *)(wcd_usbss_ctxt_ + 368) = v8;
        if ( a1 > 3 )
        {
          switch ( a1 )
          {
            case 4:
              v9 = -9;
              goto LABEL_46;
            case 5:
              v9 = -129;
              goto LABEL_46;
            case 7:
              v9 = -33;
              goto LABEL_46;
          }
        }
        else if ( (unsigned int)(a1 - 1) < 2 )
        {
          regmap_update_bits_base(*(_QWORD *)v7, 1028, 192, 0, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1027, 96, 0, 0, 0, 0);
          v6 = 0;
          *(_DWORD *)(wcd_usbss_ctxt_ + 368) &= 0xFFFFFFF9;
        }
        else
        {
          if ( !a1 )
          {
            v21 = *(_BYTE *)(v7 + 400) != 1 || *(_BYTE *)(v7 + 401) != 1;
            wcd_usbss_dpdm_switch_update(v21, 0);
            v6 = 0;
            goto LABEL_57;
          }
          if ( a1 == 3 )
          {
            v9 = -17;
LABEL_46:
            v22 = v8 & v9;
            *(_DWORD *)(v7 + 368) = v22;
            if ( v22 )
            {
              v6 = 0;
              goto LABEL_57;
            }
            wcd_usbss_switch_update_defaults(v7);
            v23 = *(_QWORD *)wcd_usbss_ctxt_;
            if ( *(_BYTE *)(wcd_usbss_ctxt_ + 400) == 1 )
            {
              regmap_update_bits_base(v23, 1027, 24, 0, 0, 0, 0);
              wcd_usbss_standby_control_locked(1);
              v6 = 0;
              *(_DWORD *)(wcd_usbss_ctxt_ + 508) = 0;
              goto LABEL_57;
            }
            regmap_update_bits_base(v23, 1027, 24, 24, 0, 0, 0);
            v24 = wcd_usbss_ctxt_;
            v6 = 0;
            v25 = 2;
LABEL_56:
            *(_DWORD *)(v24 + 508) = v25;
          }
        }
      }
LABEL_57:
      v16 = v6;
      release_runtime_env(wcd_usbss_ctxt_);
      goto LABEL_58;
    }
    *(_DWORD *)(wcd_usbss_ctxt_ + 368) |= 1LL << a1;
    wcd_usbss_pd_pu_enable();
    wcd_usbss_standby_control_locked(0);
    v6 = 0;
    if ( a1 <= 3 )
    {
      if ( (unsigned int)(a1 - 1) < 2 )
      {
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 129, 7, 1, 0, 0, 0);
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 128, 224, 224, 0, 0, 0);
        v6 = wcd_usbss_display_port_switch_update(wcd_usbss_ctxt_, (unsigned int)a1);
        if ( v6 )
          *(_DWORD *)(wcd_usbss_ctxt_ + 368) &= ~(unsigned int)(1LL << a1);
        goto LABEL_54;
      }
      if ( a1 )
      {
        if ( a1 == 3 )
        {
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 7, 1, 0, 0, 0);
          regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 1, 15);
          regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 67, 0);
          regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 61, 196);
          regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 80, 1);
          regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 145, 60);
          regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 146, 15);
          v10 = (__int64 *)wcd_usbss_ctxt_;
          if ( *(_DWORD *)(wcd_usbss_ctxt_ + 504) == 1 )
          {
            regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 2, 64, 64, 0, 0, 0);
            v10 = (__int64 *)wcd_usbss_ctxt_;
          }
          v11 = *v10;
          audio_fsm_mode = 1;
          regmap_update_bits_base(v11, 1027, 127, 0, 0, 0, 0);
          if ( audio_fsm_mode == 1 )
            regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1075, 1, 1, 0, 0, 1);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1028, 63, 2, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 41, 8, 0, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1027, 6, 6, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1029, 1, 1, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1027, 1, 1, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1027, 24, 24, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1041, 255, 2, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1037, 255, 2, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1038, 255, 1, 0, 0, 0);
          if ( audio_fsm_mode == 1 )
            regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1075, 1, 1, 0, 0, 1);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1152, 255, 57, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1165, 255, 57, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1172, 255, 232, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1176, 255, 115, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1185, 255, 232, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1189, 255, 115, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1121, 255, 0, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1123, 255, 0, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 8, 0, 0, 0, 0);
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 8, 8, 0, 0, 0);
          usleep_range_state(10000, 10100, 2);
          goto LABEL_53;
        }
LABEL_54:
        v24 = wcd_usbss_ctxt_;
        if ( (*(_BYTE *)(wcd_usbss_ctxt_ + 368) & 0xB8) == 0 )
          goto LABEL_57;
        v25 = 8;
        goto LABEL_56;
      }
      wcd_usbss_dpdm_switch_update(1, 1);
LABEL_53:
      v6 = 0;
      goto LABEL_54;
    }
    if ( a1 <= 5 )
    {
      if ( a1 != 5 )
      {
        dev_info(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "%s: GND MIC Swap register updates..\n", "wcd_usbss_switch_update");
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 7, 1, 0, 0, 0);
        regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 1, 15);
        v26 = (_QWORD *)wcd_usbss_ctxt_;
        if ( *(_DWORD *)(wcd_usbss_ctxt_ + 504) == 1 )
        {
          regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 2, 64, 64, 0, 0, 0);
          v26 = (_QWORD *)wcd_usbss_ctxt_;
        }
        regmap_update_bits_base(*v26, 1027, 2, 0, 0, 0, 0);
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 37, 8, 0, 0, 0, 0);
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1029, 1, 0, 0, 0, 0);
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1028, 63, 1, 0, 0, 0);
        v18 = (_QWORD *)wcd_usbss_ctxt_;
        v19 = 2;
        v20 = 2;
        goto LABEL_51;
      }
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 7, 1, 0, 0, 0);
      regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 1, 15);
      regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 67, 0);
      regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 61, 196);
      regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 80, 1);
      regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 145, 60);
      regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 146, 15);
      v17 = (_QWORD *)wcd_usbss_ctxt_;
      if ( *(_DWORD *)(wcd_usbss_ctxt_ + 504) == 1 )
      {
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 2, 64, 64, 0, 0, 0);
        v17 = (_QWORD *)wcd_usbss_ctxt_;
      }
      regmap_update_bits_base(*v17, 1028, 3, 1, 0, 0, 0);
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1029, 1, 0, 0, 0, 0);
      v12 = (_QWORD *)wcd_usbss_ctxt_;
      v13 = 37;
      v14 = 8;
      v15 = 0;
    }
    else
    {
      if ( a1 == 6 )
      {
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1027, 24, 0, 0, 0, 0);
        regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1028, 60, 40, 0, 0, 0);
        v18 = (_QWORD *)wcd_usbss_ctxt_;
        v19 = 24;
        v20 = 24;
        goto LABEL_51;
      }
      if ( a1 != 7 )
        goto LABEL_54;
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1027, 7, 0, 0, 0, 0);
      regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1028, 3, 2, 0, 0, 0);
      v12 = (_QWORD *)wcd_usbss_ctxt_;
      v13 = 1029;
      v14 = 1;
      v15 = 1;
    }
    regmap_update_bits_base(*v12, v13, v14, v15, 0, 0, 0);
    v18 = (_QWORD *)wcd_usbss_ctxt_;
    v19 = 7;
    v20 = 7;
LABEL_51:
    regmap_update_bits_base(*v18, 1027, v19, v20, 0, 0, 0);
    goto LABEL_53;
  }
  v16 = v5;
  dev_err(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "%s: acquire_runtime_env failed: %i\n", "wcd_usbss_switch_update", v5);
LABEL_58:
  mutex_unlock(wcd_usbss_ctxt_ + 408);
  return v16;
}
