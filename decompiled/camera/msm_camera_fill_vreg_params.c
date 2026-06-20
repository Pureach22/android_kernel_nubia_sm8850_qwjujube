__int64 __fastcall msm_camera_fill_vreg_params(__int64 a1, char *a2, unsigned __int16 a3)
{
  int v5; // w20
  __int64 v8; // x21
  __int64 v9; // x26
  _BYTE *i; // x23
  int v11; // w6
  __int64 v12; // x25
  __int64 v14; // x1
  __int64 v15; // x4
  const char *v16; // x5
  __int64 v17; // x8

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "msm_camera_fill_vreg_params",
      1133,
      "failed: soc_info %pK power_setting %pK",
      (const void *)a1,
      a2);
    return 4294967274LL;
  }
  v5 = *(_DWORD *)(a1 + 488);
  if ( (unsigned int)(v5 - 11) <= 0xFFFFFFF5 )
  {
    if ( (debug_bypass_drivers & 1) == 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "msm_camera_fill_vreg_params",
        1144,
        "failed: num_vreg %d",
        v5);
      return 4294967274LL;
    }
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "msm_camera_fill_vreg_params",
        1142,
        "Bypass parameter check num_vreg %d",
        v5);
      if ( a3 )
        goto LABEL_11;
      return 0;
    }
  }
  if ( !a3 )
    return 0;
LABEL_11:
  v8 = 0;
  v9 = a3;
  for ( i = a2 + 104; ; i += 112 )
  {
    v11 = *((_DWORD *)i - 26);
    if ( (unsigned int)v11 >= 0xE )
      break;
    *i = 0;
    if ( v11 > 5 )
    {
      if ( v11 > 11 )
      {
        if ( v11 == 12 )
        {
          if ( v5 < 1 )
            goto LABEL_193;
          if ( !strcmp(*(const char **)(a1 + 496), "cam_vana1") )
          {
            v12 = 0;
          }
          else
          {
            LODWORD(v12) = v5;
            if ( v5 == 1 )
              goto LABEL_294;
            if ( !strcmp(*(const char **)(a1 + 504), "cam_vana1") )
            {
              v12 = 1;
            }
            else
            {
              LODWORD(v12) = v5;
              if ( v5 == 2 )
                goto LABEL_294;
              if ( !strcmp(*(const char **)(a1 + 512), "cam_vana1") )
              {
                v12 = 2;
              }
              else
              {
                LODWORD(v12) = v5;
                if ( v5 == 3 )
                  goto LABEL_294;
                if ( !strcmp(*(const char **)(a1 + 520), "cam_vana1") )
                {
                  v12 = 3;
                }
                else
                {
                  LODWORD(v12) = v5;
                  if ( v5 == 4 )
                    goto LABEL_294;
                  if ( !strcmp(*(const char **)(a1 + 528), "cam_vana1") )
                  {
                    v12 = 4;
                  }
                  else
                  {
                    LODWORD(v12) = v5;
                    if ( v5 == 5 )
                      goto LABEL_294;
                    if ( !strcmp(*(const char **)(a1 + 536), "cam_vana1") )
                    {
                      v12 = 5;
                    }
                    else
                    {
                      LODWORD(v12) = v5;
                      if ( v5 == 6 )
                        goto LABEL_294;
                      if ( !strcmp(*(const char **)(a1 + 544), "cam_vana1") )
                      {
                        v12 = 6;
                      }
                      else
                      {
                        LODWORD(v12) = v5;
                        if ( v5 == 7 )
                          goto LABEL_294;
                        if ( !strcmp(*(const char **)(a1 + 552), "cam_vana1") )
                        {
                          v12 = 7;
                        }
                        else
                        {
                          LODWORD(v12) = v5;
                          if ( v5 == 8 )
                            goto LABEL_294;
                          if ( !strcmp(*(const char **)(a1 + 560), "cam_vana1") )
                          {
                            v12 = 8;
                          }
                          else
                          {
                            LODWORD(v12) = v5;
                            if ( v5 == 9 )
                              goto LABEL_294;
                            if ( strcmp(*(const char **)(a1 + 568), "cam_vana1") )
                              goto LABEL_191;
                            v12 = 9;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if ( (debug_mdl & 0x800000000LL) == 0 || debug_priority )
            goto LABEL_290;
          v14 = debug_mdl & 0x800000000LL;
          v15 = 1234;
          v16 = "i: %d j: %d cam_vana1";
        }
        else
        {
          if ( v5 < 1 )
            goto LABEL_193;
          if ( !strcmp(*(const char **)(a1 + 496), "cam_v_custom3") )
          {
            v12 = 0;
          }
          else
          {
            LODWORD(v12) = v5;
            if ( v5 == 1 )
              goto LABEL_294;
            if ( !strcmp(*(const char **)(a1 + 504), "cam_v_custom3") )
            {
              v12 = 1;
            }
            else
            {
              LODWORD(v12) = v5;
              if ( v5 == 2 )
                goto LABEL_294;
              if ( !strcmp(*(const char **)(a1 + 512), "cam_v_custom3") )
              {
                v12 = 2;
              }
              else
              {
                LODWORD(v12) = v5;
                if ( v5 == 3 )
                  goto LABEL_294;
                if ( !strcmp(*(const char **)(a1 + 520), "cam_v_custom3") )
                {
                  v12 = 3;
                }
                else
                {
                  LODWORD(v12) = v5;
                  if ( v5 == 4 )
                    goto LABEL_294;
                  if ( !strcmp(*(const char **)(a1 + 528), "cam_v_custom3") )
                  {
                    v12 = 4;
                  }
                  else
                  {
                    LODWORD(v12) = v5;
                    if ( v5 == 5 )
                      goto LABEL_294;
                    if ( !strcmp(*(const char **)(a1 + 536), "cam_v_custom3") )
                    {
                      v12 = 5;
                    }
                    else
                    {
                      LODWORD(v12) = v5;
                      if ( v5 == 6 )
                        goto LABEL_294;
                      if ( !strcmp(*(const char **)(a1 + 544), "cam_v_custom3") )
                      {
                        v12 = 6;
                      }
                      else
                      {
                        LODWORD(v12) = v5;
                        if ( v5 == 7 )
                          goto LABEL_294;
                        if ( !strcmp(*(const char **)(a1 + 552), "cam_v_custom3") )
                        {
                          v12 = 7;
                        }
                        else
                        {
                          LODWORD(v12) = v5;
                          if ( v5 == 8 )
                            goto LABEL_294;
                          if ( !strcmp(*(const char **)(a1 + 560), "cam_v_custom3") )
                          {
                            v12 = 8;
                          }
                          else
                          {
                            LODWORD(v12) = v5;
                            if ( v5 == 9 )
                              goto LABEL_294;
                            if ( strcmp(*(const char **)(a1 + 568), "cam_v_custom3") )
                              goto LABEL_191;
                            v12 = 9;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if ( (debug_mdl & 0x800000000LL) == 0 || debug_priority )
            goto LABEL_290;
          v14 = debug_mdl & 0x800000000LL;
          v15 = 1322;
          v16 = "i:%d j:%d cam_vcustom3";
        }
LABEL_297:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
          3,
          v14,
          4,
          "msm_camera_fill_vreg_params",
          v15,
          v16,
          (unsigned int)v8,
          (unsigned int)v12);
        goto LABEL_290;
      }
      if ( v11 == 6 )
      {
        if ( v5 >= 1 )
        {
          if ( !strcmp(*(const char **)(a1 + 496), "cam_v_custom1") )
          {
            v12 = 0;
          }
          else
          {
            LODWORD(v12) = v5;
            if ( v5 == 1 )
              goto LABEL_294;
            if ( !strcmp(*(const char **)(a1 + 504), "cam_v_custom1") )
            {
              v12 = 1;
            }
            else
            {
              LODWORD(v12) = v5;
              if ( v5 == 2 )
                goto LABEL_294;
              if ( !strcmp(*(const char **)(a1 + 512), "cam_v_custom1") )
              {
                v12 = 2;
              }
              else
              {
                LODWORD(v12) = v5;
                if ( v5 == 3 )
                  goto LABEL_294;
                if ( !strcmp(*(const char **)(a1 + 520), "cam_v_custom1") )
                {
                  v12 = 3;
                }
                else
                {
                  LODWORD(v12) = v5;
                  if ( v5 == 4 )
                    goto LABEL_294;
                  if ( !strcmp(*(const char **)(a1 + 528), "cam_v_custom1") )
                  {
                    v12 = 4;
                  }
                  else
                  {
                    LODWORD(v12) = v5;
                    if ( v5 == 5 )
                      goto LABEL_294;
                    if ( !strcmp(*(const char **)(a1 + 536), "cam_v_custom1") )
                    {
                      v12 = 5;
                    }
                    else
                    {
                      LODWORD(v12) = v5;
                      if ( v5 == 6 )
                        goto LABEL_294;
                      if ( !strcmp(*(const char **)(a1 + 544), "cam_v_custom1") )
                      {
                        v12 = 6;
                      }
                      else
                      {
                        LODWORD(v12) = v5;
                        if ( v5 == 7 )
                          goto LABEL_294;
                        if ( !strcmp(*(const char **)(a1 + 552), "cam_v_custom1") )
                        {
                          v12 = 7;
                        }
                        else
                        {
                          LODWORD(v12) = v5;
                          if ( v5 == 8 )
                            goto LABEL_294;
                          if ( !strcmp(*(const char **)(a1 + 560), "cam_v_custom1") )
                          {
                            v12 = 8;
                          }
                          else
                          {
                            LODWORD(v12) = v5;
                            if ( v5 == 9 )
                              goto LABEL_294;
                            if ( strcmp(*(const char **)(a1 + 568), "cam_v_custom1") )
                              goto LABEL_191;
                            v12 = 9;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          {
            v14 = debug_mdl & 0x800000000LL;
            v15 = 1279;
            v16 = "i:%d j:%d cam_vcustom1";
            goto LABEL_297;
          }
          goto LABEL_290;
        }
        goto LABEL_193;
      }
      if ( v11 == 7 )
      {
        if ( v5 >= 1 )
        {
          if ( !strcmp(*(const char **)(a1 + 496), "cam_v_custom2") )
          {
            v12 = 0;
          }
          else
          {
            LODWORD(v12) = v5;
            if ( v5 == 1 )
              goto LABEL_294;
            if ( !strcmp(*(const char **)(a1 + 504), "cam_v_custom2") )
            {
              v12 = 1;
            }
            else
            {
              LODWORD(v12) = v5;
              if ( v5 == 2 )
                goto LABEL_294;
              if ( !strcmp(*(const char **)(a1 + 512), "cam_v_custom2") )
              {
                v12 = 2;
              }
              else
              {
                LODWORD(v12) = v5;
                if ( v5 == 3 )
                  goto LABEL_294;
                if ( !strcmp(*(const char **)(a1 + 520), "cam_v_custom2") )
                {
                  v12 = 3;
                }
                else
                {
                  LODWORD(v12) = v5;
                  if ( v5 == 4 )
                    goto LABEL_294;
                  if ( !strcmp(*(const char **)(a1 + 528), "cam_v_custom2") )
                  {
                    v12 = 4;
                  }
                  else
                  {
                    LODWORD(v12) = v5;
                    if ( v5 == 5 )
                      goto LABEL_294;
                    if ( !strcmp(*(const char **)(a1 + 536), "cam_v_custom2") )
                    {
                      v12 = 5;
                    }
                    else
                    {
                      LODWORD(v12) = v5;
                      if ( v5 == 6 )
                        goto LABEL_294;
                      if ( !strcmp(*(const char **)(a1 + 544), "cam_v_custom2") )
                      {
                        v12 = 6;
                      }
                      else
                      {
                        LODWORD(v12) = v5;
                        if ( v5 == 7 )
                          goto LABEL_294;
                        if ( !strcmp(*(const char **)(a1 + 552), "cam_v_custom2") )
                        {
                          v12 = 7;
                        }
                        else
                        {
                          LODWORD(v12) = v5;
                          if ( v5 == 8 )
                            goto LABEL_294;
                          if ( !strcmp(*(const char **)(a1 + 560), "cam_v_custom2") )
                          {
                            v12 = 8;
                          }
                          else
                          {
                            LODWORD(v12) = v5;
                            if ( v5 == 9 )
                              goto LABEL_294;
                            if ( strcmp(*(const char **)(a1 + 568), "cam_v_custom2") )
                              goto LABEL_191;
                            v12 = 9;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          {
            v14 = debug_mdl & 0x800000000LL;
            v15 = 1301;
            v16 = "i:%d j:%d cam_vcustom2";
            goto LABEL_297;
          }
          goto LABEL_290;
        }
        goto LABEL_193;
      }
    }
    else if ( v11 > 2 )
    {
      if ( v11 == 3 )
      {
        if ( v5 >= 1 )
        {
          if ( !strcmp(*(const char **)(a1 + 496), "cam_vio") )
          {
            v12 = 0;
          }
          else
          {
            LODWORD(v12) = v5;
            if ( v5 == 1 )
              goto LABEL_294;
            if ( !strcmp(*(const char **)(a1 + 504), "cam_vio") )
            {
              v12 = 1;
            }
            else
            {
              LODWORD(v12) = v5;
              if ( v5 == 2 )
                goto LABEL_294;
              if ( !strcmp(*(const char **)(a1 + 512), "cam_vio") )
              {
                v12 = 2;
              }
              else
              {
                LODWORD(v12) = v5;
                if ( v5 == 3 )
                  goto LABEL_294;
                if ( !strcmp(*(const char **)(a1 + 520), "cam_vio") )
                {
                  v12 = 3;
                }
                else
                {
                  LODWORD(v12) = v5;
                  if ( v5 == 4 )
                    goto LABEL_294;
                  if ( !strcmp(*(const char **)(a1 + 528), "cam_vio") )
                  {
                    v12 = 4;
                  }
                  else
                  {
                    LODWORD(v12) = v5;
                    if ( v5 == 5 )
                      goto LABEL_294;
                    if ( !strcmp(*(const char **)(a1 + 536), "cam_vio") )
                    {
                      v12 = 5;
                    }
                    else
                    {
                      LODWORD(v12) = v5;
                      if ( v5 == 6 )
                        goto LABEL_294;
                      if ( !strcmp(*(const char **)(a1 + 544), "cam_vio") )
                      {
                        v12 = 6;
                      }
                      else
                      {
                        LODWORD(v12) = v5;
                        if ( v5 == 7 )
                          goto LABEL_294;
                        if ( !strcmp(*(const char **)(a1 + 552), "cam_vio") )
                        {
                          v12 = 7;
                        }
                        else
                        {
                          LODWORD(v12) = v5;
                          if ( v5 == 8 )
                            goto LABEL_294;
                          if ( !strcmp(*(const char **)(a1 + 560), "cam_vio") )
                          {
                            v12 = 8;
                          }
                          else
                          {
                            LODWORD(v12) = v5;
                            if ( v5 == 9 )
                              goto LABEL_294;
                            if ( strcmp(*(const char **)(a1 + 568), "cam_vio") )
                              goto LABEL_191;
                            v12 = 9;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          {
            v14 = debug_mdl & 0x800000000LL;
            v15 = 1189;
            v16 = "i: %d j: %d cam_vio";
            goto LABEL_297;
          }
          goto LABEL_290;
        }
        goto LABEL_193;
      }
      if ( v11 == 4 )
      {
        if ( v5 >= 1 )
        {
          if ( !strcmp(*(const char **)(a1 + 496), "cam_vaf") )
          {
            v12 = 0;
            goto LABEL_280;
          }
          LODWORD(v12) = v5;
          if ( v5 == 1 )
            goto LABEL_294;
          if ( !strcmp(*(const char **)(a1 + 504), "cam_vaf") )
          {
            v12 = 1;
            goto LABEL_280;
          }
          LODWORD(v12) = v5;
          if ( v5 == 2 )
            goto LABEL_294;
          if ( !strcmp(*(const char **)(a1 + 512), "cam_vaf") )
          {
            v12 = 2;
            goto LABEL_280;
          }
          LODWORD(v12) = v5;
          if ( v5 == 3 )
            goto LABEL_294;
          if ( !strcmp(*(const char **)(a1 + 520), "cam_vaf") )
          {
            v12 = 3;
            goto LABEL_280;
          }
          LODWORD(v12) = v5;
          if ( v5 == 4 )
            goto LABEL_294;
          if ( !strcmp(*(const char **)(a1 + 528), "cam_vaf") )
          {
            v12 = 4;
            goto LABEL_280;
          }
          LODWORD(v12) = v5;
          if ( v5 == 5 )
            goto LABEL_294;
          if ( !strcmp(*(const char **)(a1 + 536), "cam_vaf") )
          {
            v12 = 5;
            goto LABEL_280;
          }
          LODWORD(v12) = v5;
          if ( v5 == 6 )
            goto LABEL_294;
          if ( !strcmp(*(const char **)(a1 + 544), "cam_vaf") )
          {
            v12 = 6;
            goto LABEL_280;
          }
          LODWORD(v12) = v5;
          if ( v5 == 7 )
            goto LABEL_294;
          if ( !strcmp(*(const char **)(a1 + 552), "cam_vaf") )
          {
            v12 = 7;
            goto LABEL_280;
          }
          LODWORD(v12) = v5;
          if ( v5 == 8 )
            goto LABEL_294;
          if ( !strcmp(*(const char **)(a1 + 560), "cam_vaf") )
          {
            v12 = 8;
            goto LABEL_280;
          }
          LODWORD(v12) = v5;
          if ( v5 == 9 )
            goto LABEL_294;
          if ( !strcmp(*(const char **)(a1 + 568), "cam_vaf") )
          {
            v12 = 9;
LABEL_280:
            if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
            {
              v14 = debug_mdl & 0x800000000LL;
              v15 = 1256;
              v16 = "i: %d j: %d cam_vaf";
              goto LABEL_297;
            }
LABEL_290:
            v17 = *((_QWORD *)i - 12);
            *((_WORD *)i - 50) = v12;
            if ( v17
              && v17 >= *(unsigned int *)(a1 + 580 + 4 * v12)
              && v17 <= (unsigned __int64)*(unsigned int *)(a1 + 620 + 4 * v12) )
            {
              *i = 1;
            }
LABEL_294:
            if ( (_DWORD)v12 == v5 )
              *((_WORD *)i - 50) = 100;
            goto LABEL_12;
          }
LABEL_191:
          LODWORD(v12) = v5;
          if ( v5 != 10 )
          {
            __break(0x5512u);
            __asm { PRFM            #0x19, [X14,#0x5C8] }
            return cam_sensor_util_request_gpio_table();
          }
          goto LABEL_294;
        }
LABEL_193:
        LODWORD(v12) = 0;
        goto LABEL_294;
      }
    }
    else
    {
      if ( v11 == 1 )
      {
        if ( v5 >= 1 )
        {
          if ( !strcmp(*(const char **)(a1 + 496), "cam_vana") )
          {
            v12 = 0;
          }
          else
          {
            LODWORD(v12) = v5;
            if ( v5 == 1 )
              goto LABEL_294;
            if ( !strcmp(*(const char **)(a1 + 504), "cam_vana") )
            {
              v12 = 1;
            }
            else
            {
              LODWORD(v12) = v5;
              if ( v5 == 2 )
                goto LABEL_294;
              if ( !strcmp(*(const char **)(a1 + 512), "cam_vana") )
              {
                v12 = 2;
              }
              else
              {
                LODWORD(v12) = v5;
                if ( v5 == 3 )
                  goto LABEL_294;
                if ( !strcmp(*(const char **)(a1 + 520), "cam_vana") )
                {
                  v12 = 3;
                }
                else
                {
                  LODWORD(v12) = v5;
                  if ( v5 == 4 )
                    goto LABEL_294;
                  if ( !strcmp(*(const char **)(a1 + 528), "cam_vana") )
                  {
                    v12 = 4;
                  }
                  else
                  {
                    LODWORD(v12) = v5;
                    if ( v5 == 5 )
                      goto LABEL_294;
                    if ( !strcmp(*(const char **)(a1 + 536), "cam_vana") )
                    {
                      v12 = 5;
                    }
                    else
                    {
                      LODWORD(v12) = v5;
                      if ( v5 == 6 )
                        goto LABEL_294;
                      if ( !strcmp(*(const char **)(a1 + 544), "cam_vana") )
                      {
                        v12 = 6;
                      }
                      else
                      {
                        LODWORD(v12) = v5;
                        if ( v5 == 7 )
                          goto LABEL_294;
                        if ( !strcmp(*(const char **)(a1 + 552), "cam_vana") )
                        {
                          v12 = 7;
                        }
                        else
                        {
                          LODWORD(v12) = v5;
                          if ( v5 == 8 )
                            goto LABEL_294;
                          if ( !strcmp(*(const char **)(a1 + 560), "cam_vana") )
                          {
                            v12 = 8;
                          }
                          else
                          {
                            LODWORD(v12) = v5;
                            if ( v5 == 9 )
                              goto LABEL_294;
                            if ( strcmp(*(const char **)(a1 + 568), "cam_vana") )
                              goto LABEL_191;
                            v12 = 9;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          {
            v14 = debug_mdl & 0x800000000LL;
            v15 = 1212;
            v16 = "i: %d j: %d cam_vana";
            goto LABEL_297;
          }
          goto LABEL_290;
        }
        goto LABEL_193;
      }
      if ( v11 == 2 )
      {
        if ( v5 >= 1 )
        {
          if ( !strcmp(*(const char **)(a1 + 496), "cam_vdig") )
          {
            v12 = 0;
          }
          else
          {
            LODWORD(v12) = v5;
            if ( v5 == 1 )
              goto LABEL_294;
            if ( !strcmp(*(const char **)(a1 + 504), "cam_vdig") )
            {
              v12 = 1;
            }
            else
            {
              LODWORD(v12) = v5;
              if ( v5 == 2 )
                goto LABEL_294;
              if ( !strcmp(*(const char **)(a1 + 512), "cam_vdig") )
              {
                v12 = 2;
              }
              else
              {
                LODWORD(v12) = v5;
                if ( v5 == 3 )
                  goto LABEL_294;
                if ( !strcmp(*(const char **)(a1 + 520), "cam_vdig") )
                {
                  v12 = 3;
                }
                else
                {
                  LODWORD(v12) = v5;
                  if ( v5 == 4 )
                    goto LABEL_294;
                  if ( !strcmp(*(const char **)(a1 + 528), "cam_vdig") )
                  {
                    v12 = 4;
                  }
                  else
                  {
                    LODWORD(v12) = v5;
                    if ( v5 == 5 )
                      goto LABEL_294;
                    if ( !strcmp(*(const char **)(a1 + 536), "cam_vdig") )
                    {
                      v12 = 5;
                    }
                    else
                    {
                      LODWORD(v12) = v5;
                      if ( v5 == 6 )
                        goto LABEL_294;
                      if ( !strcmp(*(const char **)(a1 + 544), "cam_vdig") )
                      {
                        v12 = 6;
                      }
                      else
                      {
                        LODWORD(v12) = v5;
                        if ( v5 == 7 )
                          goto LABEL_294;
                        if ( !strcmp(*(const char **)(a1 + 552), "cam_vdig") )
                        {
                          v12 = 7;
                        }
                        else
                        {
                          LODWORD(v12) = v5;
                          if ( v5 == 8 )
                            goto LABEL_294;
                          if ( !strcmp(*(const char **)(a1 + 560), "cam_vdig") )
                          {
                            v12 = 8;
                          }
                          else
                          {
                            LODWORD(v12) = v5;
                            if ( v5 == 9 )
                              goto LABEL_294;
                            if ( strcmp(*(const char **)(a1 + 568), "cam_vdig") )
                              goto LABEL_191;
                            v12 = 9;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          {
            v14 = debug_mdl & 0x800000000LL;
            v15 = 1167;
            v16 = "i: %d j: %d cam_vdig";
            goto LABEL_297;
          }
          goto LABEL_290;
        }
        goto LABEL_193;
      }
    }
LABEL_12:
    if ( v9 == ++v8 )
      return 0;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x800000000LL,
    1,
    "msm_camera_fill_vreg_params",
    1154,
    "failed: Invalid Seq type: %d",
    v11);
  return 4294967274LL;
}
