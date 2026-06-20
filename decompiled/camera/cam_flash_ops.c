__int64 __fastcall cam_flash_ops(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x23
  __int64 v7; // x26
  __int64 v8; // x0
  int v9; // w22
  __int16 v10; // w8
  const char *v11; // x5
  __int64 v12; // x4
  __int64 v13; // x0
  unsigned __int64 v14; // x22
  __int64 v15; // x28
  __int64 v16; // x21
  __int64 v17; // x0
  unsigned int v18; // w27
  int max_avail_current; // w0
  unsigned int v20; // w7
  unsigned int v21; // w8
  unsigned int v22; // w1
  __int16 v23; // w9
  unsigned int v24; // kr00_4
  unsigned int v25; // w27
  unsigned __int64 v26; // x22
  unsigned int v27; // w25
  __int64 *v28; // x27
  __int64 v29; // x23
  __int64 v30; // x28
  __int64 v31; // x0
  unsigned int v32; // w25
  __int64 v33; // x0
  int v34; // w0
  unsigned int v35; // w8
  unsigned int v36; // kr04_4
  unsigned int v37; // w25
  unsigned int v38; // w25
  unsigned int v39; // w0
  unsigned int v40; // w0
  __int64 v41; // x0
  __int64 (*v42)(void); // x8
  unsigned int v43; // w0
  const char *v44; // x5
  __int64 v45; // x4
  __int64 v46; // x6
  __int16 v47; // w9
  __int64 v48; // x1
  __int64 v49; // x6
  int v50; // w8
  int *task; // x0
  int v52; // w0
  __int64 v53; // x0
  const char *v55; // x5
  __int64 v56; // x4
  unsigned int v57; // w26
  unsigned int v58; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v59; // [xsp+18h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v11 = "Fctrl or Data NULL";
    v12 = 569;
LABEL_105:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_ops",
      v12,
      v11);
    v57 = -22;
    goto LABEL_108;
  }
  v3 = *(_QWORD *)(a1 + 3320);
  if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "cam_flash_ops",
      576,
      "op: %d (1:OFF 2:LOW 3:HIGH 4:DURATION)",
      a3);
    if ( a3 == 2 )
    {
LABEL_5:
      v7 = *(_QWORD *)(a1 + 3320);
      if ( !*(_DWORD *)(a1 + 6148) )
        goto LABEL_25;
      v8 = *(_QWORD *)(a1 + 6256);
      if ( v8 )
      {
        if ( *(_DWORD *)(a2 + 32) >= *(_DWORD *)(v7 + 72) )
          v9 = *(_DWORD *)(v7 + 72);
        else
          v9 = *(_DWORD *)(a2 + 32);
        v10 = debug_mdl;
        if ( (debug_mdl & 0x1000) == 0 )
          goto LABEL_16;
      }
      else
      {
        v9 = 0;
        v10 = debug_mdl;
        if ( (debug_mdl & 0x1000) == 0 )
          goto LABEL_16;
      }
      if ( !debug_priority )
      {
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v10 & 0x1000,
          4,
          "cam_flash_set_brightness",
          533,
          "Led_Torch[%d]: Current: %d",
          0,
          v9);
        v8 = *(_QWORD *)(a1 + 6256);
      }
LABEL_16:
      cam_res_mgr_led_trigger_event(v8);
      if ( *(_DWORD *)(a1 + 6148) >= 2u )
      {
        v13 = *(_QWORD *)(a1 + 6264);
        if ( v13 )
        {
          if ( *(_DWORD *)(a2 + 36) >= *(_DWORD *)(v7 + 76) )
            v9 = *(_DWORD *)(v7 + 76);
          else
            v9 = *(_DWORD *)(a2 + 36);
        }
        if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000,
            4,
            "cam_flash_set_brightness",
            533,
            "Led_Torch[%d]: Current: %d",
            1,
            v9);
          v13 = *(_QWORD *)(a1 + 6264);
        }
        cam_res_mgr_led_trigger_event(v13);
        if ( *(_DWORD *)(a1 + 6148) > 2u )
LABEL_117:
          __break(0x5512u);
      }
LABEL_25:
      if ( *(_DWORD *)(a1 + 6716) == 1 && *(_DWORD *)(a1 + 6144) )
      {
        v14 = 0;
        v15 = a1 + 6720;
        v16 = a2 + 32;
        while ( 1 )
        {
          if ( v14 == 2 )
            goto LABEL_117;
          v17 = *(_QWORD *)(v15 + 8 * v14);
          if ( !v17 )
            goto LABEL_102;
          v18 = *(_DWORD *)(v7 + 72 + 4 * v14);
          v58 = 0;
          max_avail_current = qcom_flash_led_get_max_avail_current(v17, &v58);
          if ( max_avail_current )
            break;
          v24 = v18;
          v25 = v58;
          v21 = v24 / 0x3E8;
          if ( v58 < v24 / 0x3E8 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4096,
              2,
              "cam_flash_get_max_current",
              506,
              "static_curr: %d mA > qcurr: %d mA",
              v58,
              v58);
            v21 = v25;
          }
          if ( *(_DWORD *)(v16 + 4 * v14) >= v21 )
            v20 = v21;
          else
            v20 = *(_DWORD *)(v16 + 4 * v14);
          if ( !v21 )
            goto LABEL_35;
          v22 = 255 * v20 / v21;
          v23 = debug_mdl;
          if ( (debug_mdl & 0x1000) != 0 )
          {
LABEL_28:
            if ( !debug_priority )
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v23 & 0x1000,
                4,
                "cam_flash_set_brightness",
                553,
                "Led_Torch[%d]: Current: %d max_curr: %d brightness: %d",
                v14,
                v20,
                v21,
                v22);
          }
LABEL_30:
          led_set_brightness(*(_QWORD *)(v15 + 8 * v14++));
          if ( v14 >= *(unsigned int *)(a1 + 6144) )
            goto LABEL_102;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4096,
          1,
          "cam_flash_get_max_current",
          494,
          "Query Current Failed rc: %d",
          max_avail_current);
        v20 = 0;
        v21 = 0;
LABEL_35:
        v22 = 0;
        v23 = debug_mdl;
        if ( (debug_mdl & 0x1000) != 0 )
          goto LABEL_28;
        goto LABEL_30;
      }
LABEL_102:
      v53 = *(_QWORD *)(a1 + 6136);
      if ( v53 )
      {
        if ( a3 == 4 )
        {
          v11 = "FIREDURATION op not supported";
          v12 = 726;
          goto LABEL_105;
        }
        cam_res_mgr_led_trigger_event(v53);
      }
LABEL_107:
      v57 = 0;
      goto LABEL_108;
    }
  }
  else if ( a3 == 2 )
  {
    goto LABEL_5;
  }
  if ( (unsigned int)(a3 - 3) > 1 )
  {
    v44 = "Wrong Operation: %d";
    v45 = 698;
    v46 = 4;
    goto LABEL_80;
  }
  if ( !*(_DWORD *)(a1 + 6144) )
  {
    LODWORD(v26) = 0;
LABEL_82:
    if ( a3 != 4 || *(_DWORD *)(a1 + 6716) != 1 )
      goto LABEL_102;
    if ( *(_BYTE *)(a1 + 6896) == 1 )
    {
      v57 = 0;
      if ( (debug_mdl & 0x1000) == 0 || debug_priority )
        goto LABEL_108;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_ops",
        643,
        "LED_Flash[%d] is already enabled",
        v26);
      goto LABEL_107;
    }
    if ( *(_DWORD *)(a1 + 6900) != 1 )
    {
      hrtimer_init(a1 + 6752, 1, 1);
      hrtimer_init(a1 + 6816, 1, 1);
      *(_QWORD *)(a1 + 6792) = on_timer_function;
      *(_QWORD *)(a1 + 6856) = &off_timer_function;
    }
    v47 = debug_mdl;
    *(_QWORD *)(a1 + 6888) = *(_QWORD *)(a2 + 40);
    v48 = v47 & 0x1000;
    v49 = *(_QWORD *)(a2 + 48);
    v50 = debug_priority;
    *(_QWORD *)(a1 + 6880) = v49;
    if ( (v47 & 0x1000) != 0 && !v50 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v48,
        4,
        "cam_flash_ops",
        665,
        "fctrl: %p on_timer: %p off_timer: %p",
        (const void *)a1,
        (const void *)(a1 + 6752),
        (const void *)(a1 + 6816));
      v49 = *(_QWORD *)(a1 + 6880);
      v50 = debug_priority;
      v48 = debug_mdl & 0x1000;
      if ( (debug_mdl & 0x1000) != 0 )
      {
LABEL_93:
        if ( !v50 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v48,
            4,
            "cam_flash_ops",
            669,
            "Precise flash_on time: %u, Precise flash_off time: %u",
            v49,
            *(_QWORD *)(a1 + 6888));
          v49 = *(_QWORD *)(a1 + 6880);
        }
      }
    }
    else if ( (v47 & 0x1000) != 0 )
    {
      goto LABEL_93;
    }
    if ( !v49 )
      goto LABEL_102;
    if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_ops",
        676,
        "on_time delay %llu ms ktime: %llu on_timer: %p func: %p",
        v49,
        1000000 * v49,
        (const void *)(a1 + 6752),
        *(const void **)(a1 + 6792));
    task = cam_req_mgr_workq_get_task(*(_QWORD *)(a1 + 6904));
    if ( task )
    {
      *((_QWORD *)task + 2) = cam_flash_task_handler;
      v52 = cam_req_mgr_workq_enqueue_task((unsigned int *)task, a1, 0);
      if ( v52 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4096,
          1,
          "cam_flash_ops",
          692,
          "cam_flash[%u] Failed to schedule task rc:%d",
          *(_DWORD *)(a1 + 44),
          v52);
      goto LABEL_102;
    }
    v46 = *(unsigned int *)(a1 + 44);
    v44 = "cam_flash[%u] No empty task";
    v45 = 682;
LABEL_80:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_ops",
      v45,
      v44,
      v46);
    v57 = -22;
    goto LABEL_108;
  }
  v26 = 0;
  v27 = 0;
  v28 = (__int64 *)(a1 + 6240);
  v29 = v3 + 32;
  v30 = a2 + 32;
  while ( 1 )
  {
    if ( v26 == 2 )
      goto LABEL_117;
    v31 = *v28;
    if ( *v28 )
    {
      if ( *(_DWORD *)(v30 + 4 * v26) >= *(_DWORD *)(v29 + 4 * v26) )
        v27 = *(_DWORD *)(v29 + 4 * v26);
      else
        v27 = *(_DWORD *)(v30 + 4 * v26);
    }
    if ( *(_DWORD *)(a1 + 6716) != 1 || !v28[60] )
    {
      if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000,
          4,
          "cam_flash_ops",
          633,
          "LED_Flash[%d]: Current: %d",
          v26,
          v27);
        v31 = *v28;
      }
      cam_res_mgr_led_trigger_event(v31);
      goto LABEL_50;
    }
    v32 = *(_DWORD *)(v29 + 4 * v26);
    v33 = v28[60];
    v58 = 0;
    v34 = qcom_flash_led_get_max_avail_current(v33, &v58);
    if ( v34 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_get_max_current",
        494,
        "Query Current Failed rc: %d",
        v34);
      v35 = 0;
    }
    else
    {
      v36 = v32;
      v37 = v58;
      v35 = v36 / 0x3E8;
      if ( v58 < v36 / 0x3E8 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4096,
          2,
          "cam_flash_get_max_current",
          506,
          "static_curr: %d mA > qcurr: %d mA",
          v58,
          v58);
        v35 = v37;
      }
    }
    if ( *(_DWORD *)(v30 + 4 * v26) >= v35 )
      v38 = v35;
    else
      v38 = *(_DWORD *)(v30 + 4 * v26);
    if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_ops",
        603,
        "Led_Flash[%d]: Current: %d mA max_curr: %d mA",
        v26,
        v38,
        v35);
    v27 = 1000 * v38;
    v39 = led_set_flash_brightness(v28[62], v27);
    if ( v39 )
    {
      v57 = v39;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_ops",
        609,
        "LED_Flash[%d]:curr:%d uA set brightness failed, rc=%d",
        v26,
        v27,
        v39);
      goto LABEL_108;
    }
    v40 = led_set_flash_timeout(v28[62], 1000000);
    if ( v40 )
    {
      v57 = v40;
      v55 = "LED_Flash[%d]: set flash timeout failed, rc=%d";
      v56 = 616;
      goto LABEL_113;
    }
    if ( a3 != 4 )
      break;
LABEL_50:
    ++v26;
    ++v28;
    if ( v26 >= *(unsigned int *)(a1 + 6144) )
      goto LABEL_82;
  }
  v41 = v28[62];
  if ( v41 )
  {
    v42 = *(__int64 (**)(void))(*(_QWORD *)(v41 + 448) + 16LL);
    if ( *((_DWORD *)v42 - 1) != 1213401784 )
      __break(0x8228u);
    v43 = v42();
    if ( v43 )
    {
      v57 = v43;
      goto LABEL_112;
    }
    goto LABEL_50;
  }
  v57 = -22;
LABEL_112:
  v55 = "LED_Flash[%d]: set flash strobe failed, rc=%d";
  v56 = 625;
LABEL_113:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
    3,
    4096,
    1,
    "cam_flash_ops",
    v56,
    v55,
    (unsigned int)v26,
    v57);
LABEL_108:
  _ReadStatusReg(SP_EL0);
  return v57;
}
