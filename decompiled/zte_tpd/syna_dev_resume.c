__int64 __fastcall syna_dev_resume(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x19
  __int64 v4; // x21
  unsigned int v5; // w20
  __int64 result; // x0
  __int64 v7; // x2
  __int64 v8; // x2
  int v9; // w8
  _DWORD *v10; // x8
  void (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x2
  void *v13; // x0
  __int64 v14; // x2
  __int64 v15; // x2
  void (__fastcall *v16)(__int64, __int64); // x8
  __int64 v17; // x2
  __int64 v18; // x2
  __int64 v19; // x2
  unsigned int v20; // w0
  __int64 v21; // x2
  int v22; // w9
  __int64 v23; // x2
  unsigned int v24; // w20
  _BYTE v25[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD **)(a1 + 152);
  if ( !v3 )
  {
    result = 4294967274LL;
    goto LABEL_10;
  }
  v4 = v3[78];
  if ( v4 != -168 && *(_DWORD *)(v4 + 184) && (*(_BYTE *)(v4 + 188) & 1) != 0 )
    v5 = 0;
  else
    v5 = *(_DWORD *)(*v3 + 524LL);
  if ( *((_DWORD *)v3 + 351) == 1 )
  {
    result = 0;
    goto LABEL_10;
  }
  v25[0] = 0;
  if ( (unsigned __int8)word_314C0 == 1 )
  {
    if ( *((_DWORD *)v3 + 373) )
    {
      printk(&unk_32F51, "syna_dev_resume", a3);
    }
    else
    {
      printk(&unk_37652, "syna_dev_resume", a3);
      if ( !wait_for_completion_timeout(&dword_314A0, 625) )
        printk(&unk_3A355, "syna_dev_resume", v7);
      LOBYTE(word_314C0) = 0;
      ((void (__fastcall *)(_QWORD))report_ufp_uevent)(0);
    }
  }
  printk(&unk_31973, "syna_dev_resume", a3);
  v9 = *((unsigned __int8 *)v3 + 1409);
  *((_DWORD *)v3 + 351) = 1;
  large_area_uevent_count = 0;
  if ( v9 == 1 )
  {
    v10 = *(_DWORD **)(v4 + 64);
    if ( v10 )
    {
      if ( *(v10 - 1) != 875454897 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v10)(v4 + 8, 0);
    }
  }
  if ( *((_DWORD *)v3 + 373) && HIBYTE(word_314C0) | (unsigned __int8)word_314C0 )
  {
    printk(&unk_360CF, "syna_dev_resume", v8);
    if ( (syna_dev_enter_normal_sensing(v3) & 0x80000000) != 0 )
    {
      v13 = &unk_3BF10;
      goto LABEL_37;
    }
  }
  else
  {
    printk(&unk_33C55, "syna_dev_resume", v8);
    v11 = *(void (__fastcall **)(_QWORD))(v4 + 392);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != 725400091 )
        __break(0x8228u);
      v11(v4);
      if ( (*(_BYTE *)(v4 + 188) & 1) == 0 )
      {
        if ( (syna_tcm_get_event_data(*v3, v25, 0) & 0x80000000) != 0 )
          goto LABEL_31;
        if ( v25[0] == 16 )
          goto LABEL_35;
        msleep(50);
        if ( (syna_tcm_get_event_data(*v3, v25, 0) & 0x80000000) != 0 )
          goto LABEL_31;
        if ( v25[0] == 16 )
          goto LABEL_35;
        msleep(50);
        if ( (syna_tcm_get_event_data(*v3, v25, 0) & 0x80000000) != 0 )
          goto LABEL_31;
        if ( v25[0] == 16 )
          goto LABEL_35;
        msleep(50);
        if ( (syna_tcm_get_event_data(*v3, v25, 0) & 0x80000000) != 0 )
          goto LABEL_31;
        if ( v25[0] == 16 )
          goto LABEL_35;
        msleep(50);
        if ( (syna_tcm_get_event_data(*v3, v25, 0) & 0x80000000) != 0 )
          goto LABEL_31;
        if ( v25[0] == 16 )
          goto LABEL_35;
        msleep(50);
        if ( (syna_tcm_get_event_data(*v3, v25, 0) & 0x80000000) != 0 )
          goto LABEL_31;
        if ( v25[0] == 16 )
          goto LABEL_35;
        msleep(50);
        if ( (syna_tcm_get_event_data(*v3, v25, 0) & 0x80000000) != 0 )
          goto LABEL_31;
        if ( v25[0] == 16 )
          goto LABEL_35;
        msleep(50);
        if ( (syna_tcm_get_event_data(*v3, v25, 0) & 0x80000000) != 0 )
          goto LABEL_31;
        if ( v25[0] == 16 )
          goto LABEL_35;
        msleep(50);
        if ( (syna_tcm_get_event_data(*v3, v25, 0) & 0x80000000) != 0 )
          goto LABEL_31;
        if ( v25[0] == 16 )
          goto LABEL_35;
        msleep(50);
        if ( (syna_tcm_get_event_data(*v3, v25, 0) & 0x80000000) != 0 )
        {
LABEL_31:
          v13 = &unk_329B7;
          goto LABEL_37;
        }
        if ( v25[0] != 16 )
          msleep(50);
      }
    }
    else if ( (syna_tcm_reset(*v3, v5) & 0x80000000) != 0 )
    {
      v13 = &unk_3A94B;
      goto LABEL_37;
    }
  }
LABEL_35:
  printk(&unk_31EEA, "syna_dev_resume", v12);
  if ( (syna_dev_set_up_app_fw(v3) & 0x80000000) != 0 )
  {
    v13 = &unk_37007;
LABEL_37:
    printk(v13, "syna_dev_resume", v12);
    if ( (*(_BYTE *)(v4 + 188) & 1) != 0 )
      goto LABEL_44;
LABEL_40:
    v16 = *(void (__fastcall **)(__int64, __int64))(v4 + 64);
    if ( v16 )
    {
      if ( *((_DWORD *)v16 - 1) != 875454897 )
        __break(0x8228u);
      v16(v4 + 8, 1);
    }
    goto LABEL_44;
  }
  v15 = *((unsigned int *)v3 + 351);
  byte_314C2 = 0;
  word_314C0 = 0;
  printk(&unk_39D7B, "syna_dev_resume", v15);
  if ( (*(_BYTE *)(v4 + 188) & 1) == 0 )
    goto LABEL_40;
LABEL_44:
  *((_BYTE *)v3 + 1408) = 0;
  printk(&unk_36A84, "syna_dev_set_screen_on_fp_mode", v14);
  if ( (syna_tcm_set_dynamic_config(*v3, 212, 3, v5) & 0x80000000) != 0 )
  {
    printk(&unk_3B058, "syna_dev_set_screen_on_fp_mode", v17);
    printk(&unk_354E1, "syna_dev_resume", v18);
  }
  if ( syna_usb_detect_flag == 1 && (unsigned int)syna_dev_set_charger_mode(v3, 1u, v5) )
    printk(&unk_3D102, "syna_dev_resume", v19);
  syna_dev_set_display_rotation(v3, *((_DWORD *)v3 + 386), v5);
  if ( *((_DWORD *)v3 + 375) )
  {
    if ( (unsigned int)syna_dev_set_play_game(v3, 1u, v5) )
      printk(&unk_34708, "syna_dev_resume", v21);
    syna_dev_set_tp_report_rate(v3, *((_DWORD *)v3 + 382), v5);
    syna_dev_set_sensibility_level(v3, *((_DWORD *)v3 + 383), v5);
    syna_dev_set_follow_hand_level(v3, *((_DWORD *)v3 + 384), v5);
    v20 = syna_dev_set_stability_level(v3, *((_DWORD *)v3 + 385), v5);
  }
  else
  {
    v20 = syna_dev_set_tp_report_rate(v3, *((_DWORD *)v3 + 382), v5);
  }
  v22 = *((_DWORD *)v3 + 381);
  v23 = *((unsigned int *)v3 + 364);
  v24 = v20;
  *((_DWORD *)v3 + 378) = *((_DWORD *)v3 + 379);
  *((_DWORD *)v3 + 380) = v22;
  printk(&unk_3B149, "syna_dev_resume", v23);
  printk(&unk_3B7E6, "syna_dev_resume", *((unsigned int *)v3 + 369));
  printk(&unk_37D84, "syna_dev_resume", *((unsigned int *)v3 + 373));
  printk(&unk_335AE, "syna_dev_resume", *((unsigned int *)v3 + 378));
  printk(&unk_3937A, "syna_dev_resume", *((unsigned int *)v3 + 380));
  result = v24;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
