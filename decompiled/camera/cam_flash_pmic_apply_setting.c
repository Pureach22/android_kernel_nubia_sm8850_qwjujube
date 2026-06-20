__int64 __fastcall cam_flash_pmic_apply_setting(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v3; // x20
  __int64 v4; // x1
  unsigned int v5; // w8
  unsigned int v6; // w0
  unsigned int v7; // w21
  const char *v8; // x5
  __int64 v9; // x4
  int v10; // w8
  int v11; // w8
  unsigned int v12; // w0
  unsigned int v13; // w8
  __int64 v14; // x0
  __int64 v15; // x21
  __int64 v16; // x0
  __int64 v17; // x21
  unsigned int v18; // w8
  __int64 v19; // x0
  __int64 v20; // x21
  unsigned int v21; // w0
  __int64 v22; // x1
  int v23; // w8
  const char *v24; // x5
  __int64 v25; // x4
  unsigned int v26; // w0
  int v27; // w24
  unsigned int v28; // w8
  unsigned int v29; // w0
  __int64 v30; // x21
  unsigned int v31; // w0
  __int64 v32; // x8
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x6
  unsigned __int64 v35; // x10
  unsigned __int64 v36; // x11
  bool v37; // cf
  __int64 v38; // x21
  __int64 v39; // x8

  if ( !a2 )
  {
    v10 = *(unsigned __int8 *)(a1 + 5508);
    switch ( v10 )
    {
      case 12:
        if ( *(_DWORD *)(a1 + 6200) == 3 || (v26 = ((__int64 (__fastcall *)(__int64))cam_flash_off)(a1)) == 0 )
        {
          if ( (debug_mdl & 0x1001000) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x1001000,
              4,
              "cam_flash_pmic_apply_setting",
              1148,
              "FLASH_RER req_id: %u",
              0);
            v27 = *(unsigned __int16 *)(a1 + 5512);
            if ( *(_WORD *)(a1 + 5512) )
            {
              while ( 1 )
              {
LABEL_74:
                if ( *(_DWORD *)(a1 + 6200) == 3 )
                {
                  v29 = ((__int64 (__fastcall *)(__int64, __int64))cam_flash_low)(a1, a1 + 5488);
                  if ( v29 )
                  {
                    v7 = v29;
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      4096,
                      1,
                      "cam_flash_pmic_apply_setting",
                      1158,
                      "Fire Torch Failed");
                    goto LABEL_130;
                  }
                  usleep_range_state(
                    1000LL * *(unsigned __int16 *)(a1 + 5514),
                    1000 * (unsigned int)*(unsigned __int16 *)(a1 + 5514) + 100,
                    2);
                }
                v7 = ((__int64 (__fastcall *)(__int64))cam_flash_off)(a1);
                if ( v7 )
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    4096,
                    1,
                    "cam_flash_pmic_apply_setting",
                    1171,
                    "Flash off failed: %d",
                    v7);
                  if ( !--v27 )
                    goto LABEL_130;
                }
                else
                {
                  v28 = *(unsigned __int16 *)(a1 + 5516);
                  *(_DWORD *)(a1 + 6200) = 3;
                  usleep_range_state(1000LL * v28, 1000 * v28 + 100, 2);
                  if ( !--v27 )
                    goto LABEL_130;
                }
              }
            }
          }
          else
          {
            v27 = *(unsigned __int16 *)(a1 + 5512);
            if ( *(_WORD *)(a1 + 5512) )
              goto LABEL_74;
          }
          goto LABEL_129;
        }
        v7 = v26;
        v24 = "Flash off failed: %d";
        v25 = 1144;
        break;
      case 14:
        v22 = debug_mdl & 0x1001000;
        if ( (debug_mdl & 0x1001000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v22,
            4,
            "cam_flash_pmic_apply_setting",
            1117,
            "FLASH_WIDGET req_id: %u flash_opcode: %d",
            0,
            *(char *)(a1 + 5518));
        v23 = *(unsigned __int8 *)(a1 + 5518);
        if ( v23 == 1 )
        {
          v7 = ((__int64 (__fastcall *)(__int64, __int64))cam_flash_off)(a1, v22);
          if ( !v7 )
            goto LABEL_130;
          v24 = "LED off failed: %d";
          v25 = 1134;
        }
        else
        {
          if ( v23 != 2 )
            goto LABEL_129;
          v7 = ((__int64 (__fastcall *)(__int64, __int64))cam_flash_low)(a1, a1 + 5488);
          if ( !v7 )
            goto LABEL_130;
          v24 = "Torch ON failed : %d";
          v25 = 1125;
        }
        break;
      case 16:
        if ( (debug_mdl & 0x1001000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1001000,
            4,
            "cam_flash_pmic_apply_setting",
            1072,
            "FLASH_INIT_FIRE req_id: %u flash_opcode: %d",
            0,
            *(char *)(a1 + 5518));
        v11 = *(unsigned __int8 *)(a1 + 5518);
        if ( v11 == 3 )
        {
          if ( *(_DWORD *)(a1 + 6200) == 3 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4096,
              2,
              "cam_flash_pmic_apply_setting",
              1080,
              "Wrong state :Prev state: %d",
              3);
          v7 = cam_flash_high(a1, a1 + 5488);
          if ( v7 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4096,
              1,
              "cam_flash_pmic_apply_setting",
              1086,
              "FLASH ON failed : %d",
              v7);
          if ( *(_BYTE *)(a1 + 5518) != 2 )
          {
LABEL_85:
            if ( *(_BYTE *)(a1 + 5518) == 1 )
            {
              v7 = ((__int64 (__fastcall *)(__int64))cam_flash_off)(a1);
              if ( v7 )
              {
                v8 = "LED OFF FAILED: %d";
                v9 = 1108;
                goto LABEL_106;
              }
            }
            goto LABEL_130;
          }
        }
        else
        {
          v7 = 0;
          if ( v11 != 2 )
            goto LABEL_85;
        }
        if ( *(_DWORD *)(a1 + 6200) == 3 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4096,
            2,
            "cam_flash_pmic_apply_setting",
            1094,
            "Wrong state :Prev state: %d",
            3);
        v7 = ((__int64 (__fastcall *)(__int64, __int64))cam_flash_low)(a1, a1 + 5488);
        if ( v7 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4096,
            1,
            "cam_flash_pmic_apply_setting",
            1100,
            "TORCH ON failed : %d",
            v7);
        goto LABEL_85;
      default:
LABEL_129:
        v7 = 0;
LABEL_130:
        LOBYTE(v3) = 0;
        goto LABEL_131;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_apply_setting",
      v25,
      v24,
      v7);
    goto LABEL_130;
  }
  v3 = a2;
  v4 = a1 + 56 * (a2 & 0x1F) + 3696;
  if ( (debug_mdl & 0x1001000) != 0 && !debug_priority )
  {
    v38 = v4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1001000,
      4,
      "cam_flash_pmic_apply_setting",
      1184,
      "FLASH_RT req_id: %u flash_opcode: %d",
      v3,
      *(char *)(v4 + 30));
    v4 = v38;
  }
  v5 = *(unsigned __int8 *)(v4 + 30);
  if ( v5 <= 2 )
  {
    if ( v5 != 1 )
    {
      if ( v5 == 2 && *(_BYTE *)v4 == 1 && *(_QWORD *)(v4 + 8) == v3 )
      {
        if ( *(_DWORD *)(a1 + 6200) == 3 )
        {
          v12 = ((__int64 (__fastcall *)(__int64))cam_flash_low)(a1);
          if ( v12 )
          {
            v7 = v12;
            v8 = "Torch ON failed: rc= %d";
            v9 = 1209;
            goto LABEL_106;
          }
        }
        goto LABEL_107;
      }
      goto LABEL_58;
    }
    if ( *(_BYTE *)v4 != 1 || *(_QWORD *)(v4 + 8) != v3 )
      goto LABEL_58;
    v21 = ((__int64 (__fastcall *)(__int64))cam_flash_off)(a1);
    if ( v21 )
    {
      v7 = v21;
      v8 = "Flash off failed %d";
      v9 = 1219;
      goto LABEL_106;
    }
    goto LABEL_107;
  }
  if ( v5 == 127 )
  {
    if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_pmic_apply_setting",
        1236,
        "NOP Packet");
    goto LABEL_107;
  }
  if ( v5 != 4 )
  {
    if ( v5 == 3 && *(_BYTE *)v4 == 1 && *(_QWORD *)(v4 + 8) == v3 )
    {
      if ( *(_DWORD *)(a1 + 6200) == 3 )
      {
        v6 = cam_flash_high(a1, v4);
        if ( v6 )
        {
          v7 = v6;
          v8 = "Flash ON failed: rc= %d";
          v9 = 1195;
LABEL_106:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            4096,
            1,
            "cam_flash_pmic_apply_setting",
            v9,
            v8,
            v7);
          return v7;
        }
      }
      goto LABEL_107;
    }
LABEL_58:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_apply_setting",
      1240,
      "Invalid opcode: %d req_id: %llu",
      (char)v5,
      v3);
    return (unsigned int)-22;
  }
  if ( *(_BYTE *)v4 != 1 || *(_QWORD *)(v4 + 8) != v3 )
    goto LABEL_58;
  if ( *(_DWORD *)(a1 + 6200) != 3 )
  {
LABEL_107:
    v32 = 0;
    v33 = 0;
    v34 = 0;
    do
    {
      v35 = *(_QWORD *)(a1 + v32 + 3704);
      if ( v35 <= v3 && *(_BYTE *)(a1 + v32 + 3696) == 1 )
      {
        if ( v33 <= v35 )
          v36 = *(_QWORD *)(a1 + v32 + 3704);
        else
          v36 = v33;
        v37 = v34 >= v35;
        if ( v34 > v35 )
          v33 = v36;
        if ( v34 >= v35 )
          v35 = v34;
        if ( !v37 )
          v33 = v34;
        v34 = v35;
      }
      v32 += 56;
    }
    while ( v32 != 1792 );
    if ( v34 >= v3 )
      v3 = v33;
    if ( !v3 )
      return 0;
    v7 = 0;
    if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_pmic_delete_req",
        936,
        "top: %llu, del_req_id:%llu",
        v34,
        v3);
      v7 = 0;
    }
LABEL_131:
    v39 = a1 + 56 * (v3 & 0x1F);
    *(_QWORD *)(v39 + 3704) = 0;
    *(_BYTE *)(v39 + 3696) = 0;
    *(_DWORD *)(v39 + 3712) = 0;
    *(_QWORD *)(v39 + 3728) = 0;
    return v7;
  }
  if ( !v4 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_duration",
      830,
      "Flash Data NULL");
    v7 = -22;
LABEL_105:
    v8 = "PreciaseFlash op failed:%d";
    v9 = 1231;
    goto LABEL_106;
  }
  v13 = *(_DWORD *)(a1 + 6148);
  if ( !v13 )
    goto LABEL_102;
  v14 = *(_QWORD *)(a1 + 6256);
  if ( v14 )
  {
    v15 = v4;
    cam_res_mgr_led_trigger_event(v14);
    v13 = *(_DWORD *)(a1 + 6148);
    v4 = v15;
  }
  if ( v13 < 2 )
    goto LABEL_102;
  v16 = *(_QWORD *)(a1 + 6264);
  if ( v16 )
  {
    v17 = v4;
    v16 = cam_res_mgr_led_trigger_event(v16);
    v13 = *(_DWORD *)(a1 + 6148);
    v4 = v17;
  }
  if ( v13 <= 2 )
  {
LABEL_102:
    if ( *(_DWORD *)(a1 + 6716) != 1 )
      goto LABEL_103;
    v18 = *(_DWORD *)(a1 + 6144);
    if ( !v18 )
      goto LABEL_103;
    v19 = *(_QWORD *)(a1 + 6720);
    if ( v19 )
    {
      if ( (debug_mdl & 0x1000) != 0 )
      {
        v20 = v4;
        if ( !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000,
            4,
            "cam_flash_duration",
            844,
            "Led_Torch[%d]: brightness: 0 (LED_OFF)",
            0);
          v19 = *(_QWORD *)(a1 + 6720);
        }
      }
      else
      {
        v20 = v4;
      }
      led_set_brightness_sync(v19, 0);
      v18 = *(_DWORD *)(a1 + 6144);
      v4 = v20;
    }
    if ( v18 < 2 )
      goto LABEL_103;
    v16 = *(_QWORD *)(a1 + 6728);
    if ( v16 )
    {
      if ( (debug_mdl & 0x1000) != 0 )
      {
        v30 = v4;
        if ( !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000,
            4,
            "cam_flash_duration",
            844,
            "Led_Torch[%d]: brightness: 0 (LED_OFF)",
            1);
          v16 = *(_QWORD *)(a1 + 6728);
        }
      }
      else
      {
        v30 = v4;
      }
      v16 = led_set_brightness_sync(v16, 0);
      v18 = *(_DWORD *)(a1 + 6144);
      v4 = v30;
    }
    if ( v18 <= 2 )
    {
LABEL_103:
      v31 = cam_flash_ops(a1);
      if ( v31 )
      {
        v7 = v31;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4096,
          1,
          "cam_flash_duration",
          853,
          "Fire PreciseFlash Failed: %d",
          v31);
        goto LABEL_105;
      }
      goto LABEL_107;
    }
  }
  __break(0x5512u);
  return cam_flash_high(v16, v4);
}
