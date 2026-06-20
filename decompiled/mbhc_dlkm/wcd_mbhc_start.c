__int64 __fastcall wcd_mbhc_start(__int64 a1, __int64 a2)
{
  unsigned int v2; // w21
  __int64 v5; // x23
  _DWORD *v6; // x20
  __int64 v7; // x1
  int variable_u32_array; // w0
  __int64 v9; // x0
  int v10; // w0
  __int64 v11; // x8
  __int64 v12; // x22
  _DWORD *v13; // x23
  __int64 v14; // x1
  __int64 v16; // x3
  _QWORD v17[11]; // [xsp+8h] [xbp-58h] BYREF

  v2 = -22;
  v17[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
    goto LABEL_26;
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 216) + 32LL);
  *(_QWORD *)(a1 + 112) = a2;
  *(_DWORD *)(a2 + 88) = 0;
  v6 = (_DWORD *)(a2 + 88);
  if ( of_find_property(*(_QWORD *)(*(_QWORD *)(v5 + 72) + 744LL), "qcom,msm-mbhc-usbc-audio-supported", 0) )
  {
    variable_u32_array = of_property_read_variable_u32_array(
                           *(_QWORD *)(*(_QWORD *)(v5 + 72) + 744LL),
                           "qcom,msm-mbhc-usbc-audio-supported",
                           v6,
                           1,
                           0);
    v2 = variable_u32_array & (variable_u32_array >> 31);
    if ( !*v6 )
      goto LABEL_12;
  }
  else
  {
    v2 = 0;
    if ( !*v6 )
      goto LABEL_12;
  }
  *(_DWORD *)(a1 + 180) = 2;
  v9 = *(_QWORD *)(*(_QWORD *)(v5 + 72) + 744LL);
  memset(v17, 0, 80);
  v10 = _of_parse_phandle_with_args(v9, "wcd939x-i2c-handle", 0, 0, 0, v17);
  v11 = v17[0];
  if ( v10 )
    v11 = 0;
  *(_QWORD *)(a1 + 936) = v11;
  if ( !v11 )
  {
    dev_err(*(_QWORD *)(v5 + 72), "%s: wcd939x or fsa i2c node not found\n", "wcd_mbhc_start");
    v2 = -22;
    goto LABEL_26;
  }
  if ( *v6 )
  {
    *(_BYTE *)(a2 + 72) = 0;
    *(_BYTE *)(a2 + 92) = 0;
  }
LABEL_12:
  if ( (*(_BYTE *)(a1 + 212) & 1) == 0 )
  {
    v12 = 0;
    v13 = (_DWORD *)(*(_QWORD *)(a1 + 112) + 36LL);
    do
    {
      if ( v13[v12] )
      {
        if ( (unsigned int)v12 >= 6 )
        {
          if ( (wcd_mbhc_set_keycode___already_done & 1) == 0 )
          {
            wcd_mbhc_set_keycode___already_done = 1;
            _warn_printk("Wrong button number:%d\n", v12);
            __break(0x800u);
          }
          goto LABEL_36;
        }
        if ( (unsigned int)snd_jack_set_key(*(_QWORD *)(a1 + 616), dword_E6E8[v12]) )
        {
          printk(&unk_E11C, "wcd_mbhc_set_keycode");
LABEL_36:
          printk(&unk_E084, v7);
          goto LABEL_21;
        }
        input_set_capability(*(_QWORD *)(*(_QWORD *)(a1 + 616) + 32LL), 1, (unsigned int)v13[v12]);
      }
      ++v12;
    }
    while ( v12 != 8 );
    if ( *v13 )
      *(_BYTE *)(a1 + 212) = 1;
  }
LABEL_21:
  if ( **(_BYTE **)(a1 + 112) != 1 || *(_QWORD *)(a1 + 328) || *(_QWORD *)(a1 + 336) )
  {
    wcd_mbhc_initialise(a1);
    v2 = 0;
    if ( *v6 )
    {
LABEL_25:
      v14 = *(_QWORD *)(a1 + 936);
      *(_QWORD *)(a1 + 944) = wcd_mbhc_usbc_ana_event_handler;
      *(_DWORD *)(a1 + 960) = 0;
      v2 = wcd_usbss_reg_notifier(a1 + 944, v14);
    }
  }
  else
  {
    if ( (unsigned int)jiffies_to_usecs(0x3FFFFFFFFFFFFFFELL) >= 0x3D0900 )
      v16 = 1000;
    else
      v16 = 0x3FFFFFFFFFFFFFFELL;
    queue_delayed_work_on(32, system_wq, a1 + 224, v16);
    if ( *v6 )
      goto LABEL_25;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v2;
}
