__int64 __fastcall cam_sensor_update_power_settings(__int64 *a1, unsigned int a2, __int64 a3, unsigned __int64 a4)
{
  _QWORD *v8; // x26
  unsigned int v9; // w25
  __int64 v10; // x9
  __int64 v11; // x10
  int v12; // w8
  __int64 v13; // x0
  int v14; // w8
  __int64 v15; // x0
  unsigned int v16; // w23
  int v17; // w11
  __int64 v18; // x13
  int v19; // w14
  _QWORD *v20; // x19
  __int64 v21; // x0
  __int64 v22; // x0
  _QWORD *v23; // x0
  unsigned __int64 v24; // x8
  int v25; // w6
  int v26; // w8
  unsigned __int16 v27; // w8
  unsigned int v28; // w7
  __int64 v29; // x24
  unsigned int v30; // w27
  __int64 v31; // x22
  int v32; // w25
  __int64 v33; // x8
  __int64 v34; // x24
  int v35; // w22
  unsigned __int16 *v36; // x9
  __int64 v37; // x10
  __int64 v38; // x8
  int v39; // w8
  unsigned __int16 v40; // w8
  unsigned int v41; // w7
  __int64 v42; // x22
  int v43; // w25
  __int64 v44; // x8
  __int64 v45; // x22
  int v46; // w24
  unsigned __int16 *v47; // x9
  __int64 v48; // x8
  int v49; // w6
  __int64 v50; // x8
  __int64 v51; // x22
  int v52; // w24
  int v53; // w25
  __int64 v54; // x4
  const void *v55; // x6
  __int64 v56; // x19
  int v57; // w22
  int v58; // w23
  int v59; // w22
  __int64 v60; // x9
  int v61; // w22
  const char *v62; // x5
  __int64 v63; // x4
  _QWORD *v64; // x0
  _QWORD *v65; // x0
  const void *v67; // [xsp+0h] [xbp-20h]
  int v68; // [xsp+14h] [xbp-Ch]
  int v69; // [xsp+14h] [xbp-Ch]
  __int64 v70; // [xsp+18h] [xbp-8h]
  __int64 v71; // [xsp+18h] [xbp-8h]
  __int64 v72; // [xsp+18h] [xbp-8h]
  __int64 v73; // [xsp+18h] [xbp-8h]

  if ( mem_trace_en == 1 )
  {
    v8 = (_QWORD *)cam_mem_trace_alloc(a4, 0xCC0u, 0, "cam_sensor_update_power_settings", 0x5C7u);
    if ( v8 )
    {
LABEL_3:
      memcpy(v8, a1, a4);
      if ( a4 >= 8 && a2 && a2 <= a4 )
      {
        if ( (unsigned int)*((unsigned __int8 *)v8 + 5) - 2 >= 2 || a4 >= 0x14 )
        {
          v11 = *a1;
          v10 = a1[1];
          *((_DWORD *)v8 + 4) = *((_DWORD *)a1 + 4);
          *v8 = v11;
          v8[1] = v10;
          v12 = (unsigned __int8)mem_trace_en;
          *(_WORD *)(a3 + 16) = 0;
          if ( v12 == 1 )
          {
            v13 = cam_mem_trace_alloc(1344, 0xCC0u, 0, "cam_sensor_update_power_settings", 0x5DEu);
            *(_QWORD *)(a3 + 8) = v13;
            if ( v13 )
            {
LABEL_18:
              v14 = (unsigned __int8)mem_trace_en;
              *(_WORD *)(a3 + 32) = 0;
              if ( v14 == 1 )
              {
                v15 = cam_mem_trace_alloc(1344, 0xCC0u, 0, "cam_sensor_update_power_settings", 0x5E8u);
                *(_QWORD *)(a3 + 24) = v15;
                if ( v15 )
                {
LABEL_20:
                  v16 = 0;
                  v17 = 0;
                  v18 = 0;
                  v19 = 0;
                  v20 = v8;
                  while ( 1 )
                  {
                    v24 = a2 - v16;
                    if ( (unsigned int)v24 < 8 )
                    {
LABEL_103:
                      v64 = *(_QWORD **)(a3 + 24);
                      if ( mem_trace_en == 1 )
                        cam_mem_trace_free(v64, 0);
                      else
                        kvfree(v64);
                      v65 = *(_QWORD **)(a3 + 8);
                      if ( mem_trace_en == 1 )
                        cam_mem_trace_free(v65, 0);
                      else
                        kvfree(v65);
                      v9 = -22;
                      *(_QWORD *)(a3 + 24) = 0;
                      *(_QWORD *)(a3 + 8) = 0;
                      *(_WORD *)(a3 + 32) = 0;
                      goto LABEL_110;
                    }
                    v25 = *((unsigned __int8 *)v20 + 5);
                    if ( (unsigned int)(v25 - 2) >= 2 )
                    {
                      if ( v25 != 9 )
                      {
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          0x800000000LL,
                          1,
                          "cam_sensor_update_power_settings",
                          1710,
                          "Error: Un expected Header Type: %d",
                          v25);
                        goto LABEL_103;
                      }
                    }
                    else if ( v24 < 0x14 )
                    {
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                        3,
                        0x800000000LL,
                        1,
                        "cam_sensor_validate",
                        1463,
                        "Invalid cmd_buf len %zu min %zu",
                        a2 - v16);
                      goto LABEL_103;
                    }
                    if ( v25 == 9 )
                      break;
                    if ( v25 == 3 )
                    {
                      v39 = *(unsigned __int16 *)(a3 + 32);
                      v29 = (__int64)v20 + 20;
                      if ( *(_DWORD *)v20 > (v39 ^ 0xFFFFu) )
                      {
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                          3,
                          0x800000000LL,
                          1,
                          "cam_sensor_update_power_settings",
                          1653,
                          "ERR: Overflow");
                        goto LABEL_103;
                      }
                      v40 = v39 + *(_DWORD *)v20;
                      *(_WORD *)(a3 + 32) = v40;
                      v41 = *(_DWORD *)v20;
                      if ( v40 > 0xCu || v41 >= 0xE )
                      {
                        v62 = "pwr_down_setting_size %d, pwr_cmd->count: %d";
                        v63 = 1666;
                        goto LABEL_102;
                      }
                      v30 = v16 + 20;
                      if ( v41
                        || (v42 = v18,
                            v43 = v19,
                            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                              3,
                              0x800000000LL,
                              1,
                              "cam_sensor_update_power_settings",
                              1672,
                              "pwr_down size is zero"),
                            v19 = v43,
                            v18 = v42,
                            *(_DWORD *)v20) )
                      {
                        v44 = *(_QWORD *)(a3 + 24) + 112LL * v19;
                        *(_DWORD *)v44 = *((unsigned __int16 *)v20 + 4);
                        *(_QWORD *)(v44 + 8) = *((unsigned int *)v20 + 3);
                        *(_WORD *)(*(_QWORD *)(a3 + 24) + 112LL * v19 + 16) = 0;
                        if ( v30 > a2 )
                          goto LABEL_95;
                        if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
                        {
                          v72 = v18;
                          v59 = v19;
                          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                            3,
                            debug_mdl & 0x800000000LL,
                            4,
                            "cam_sensor_update_power_settings",
                            1702,
                            "Seq Type[%d]: %d Config_val: %ld",
                            v19,
                            *(_DWORD *)v44,
                            *(_QWORD *)(v44 + 8));
                          v18 = v72;
                          v19 = v59;
                        }
                        if ( *(_DWORD *)v20 >= 2u )
                        {
                          v45 = 0;
                          v46 = 1;
                          while ( 1 )
                          {
                            v47 = (unsigned __int16 *)v20 + 6 * v46 + 4;
                            v48 = *(_QWORD *)(a3 + 24) + 112LL * (v19 + v46);
                            *(_DWORD *)v48 = *v47;
                            *(_QWORD *)(v48 + 8) = *((unsigned int *)v47 + 1);
                            *(_WORD *)(*(_QWORD *)(a3 + 24) + 112LL * (v19 + v46) + 16) = 0;
                            if ( v16 + (unsigned int)v45 + 32 > a2 )
                              break;
                            if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
                            {
                              v71 = v18;
                              v69 = v19;
                              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                3,
                                debug_mdl & 0x800000000LL,
                                4,
                                "cam_sensor_update_power_settings",
                                1702,
                                "Seq Type[%d]: %d Config_val: %ld",
                                v19 + v46,
                                *(_DWORD *)v48,
                                *(_QWORD *)(v48 + 8));
                              v19 = v69;
                              v18 = v71;
                            }
                            ++v46;
                            v45 += 12;
                            if ( (unsigned int)v46 >= *(_DWORD *)v20 )
                            {
                              v19 += v46;
                              v30 = v16 + v45 + 20;
                              v29 = (__int64)v20 + v45 + 20;
                              goto LABEL_27;
                            }
                          }
LABEL_95:
                          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                            3,
                            0x800000000LL,
                            1,
                            "cam_sensor_update_power_settings",
                            1695,
                            "Command Buffer is wrong");
                          goto LABEL_103;
                        }
                        ++v19;
                      }
LABEL_27:
                      v17 = 3;
                    }
                    else
                    {
                      v26 = *(unsigned __int16 *)(a3 + 16);
                      if ( *(_DWORD *)v20 > (v26 ^ 0xFFFFu) )
                      {
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                          3,
                          0x800000000LL,
                          1,
                          "cam_sensor_update_power_settings",
                          1535,
                          "ERR: Overflow occurs");
                        goto LABEL_103;
                      }
                      v27 = v26 + *(_DWORD *)v20;
                      *(_WORD *)(a3 + 16) = v27;
                      v28 = *(_DWORD *)v20;
                      if ( v27 > 0xCu || v28 >= 0xE )
                      {
                        v62 = "pwr_up setting size %d, pwr_cmd->count: %d";
                        v63 = 1547;
LABEL_102:
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                          3,
                          0x800000000LL,
                          1,
                          "cam_sensor_update_power_settings",
                          v63,
                          v62);
                        goto LABEL_103;
                      }
                      v29 = (__int64)v20 + 20;
                      v30 = v16 + 20;
                      if ( v28
                        || (v31 = v18,
                            v32 = v19,
                            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                              3,
                              0x800000000LL,
                              2,
                              "cam_sensor_update_power_settings",
                              1556,
                              "pwr_up_size is zero"),
                            v19 = v32,
                            v18 = v31,
                            *(_DWORD *)v20) )
                      {
                        v33 = 112LL * (int)v18;
                        *(_DWORD *)(*(_QWORD *)(a3 + 8) + v33) = *((unsigned __int16 *)v20 + 4);
                        *(_QWORD *)(*(_QWORD *)(a3 + 8) + v33 + 8) = *((unsigned int *)v20 + 3);
                        *(_WORD *)(*(_QWORD *)(a3 + 8) + v33 + 16) = 0;
                        if ( v30 > a2 )
                          goto LABEL_94;
                        if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
                        {
                          v60 = *(_QWORD *)(a3 + 8) + 112LL * (int)v18;
                          v73 = v18;
                          v61 = v19;
                          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                            3,
                            debug_mdl & 0x800000000LL,
                            4,
                            "cam_sensor_update_power_settings",
                            1584,
                            "Seq Type[%d]: %d Config_val: %ld",
                            v18,
                            *(_DWORD *)v60,
                            *(_QWORD *)(v60 + 8));
                          v18 = v73;
                          v19 = v61;
                        }
                        if ( *(_DWORD *)v20 >= 2u )
                        {
                          v34 = 0;
                          v35 = 1;
                          while ( 1 )
                          {
                            v36 = (unsigned __int16 *)v20 + 6 * v35 + 4;
                            v37 = 112LL * ((int)v18 + v35);
                            *(_DWORD *)(*(_QWORD *)(a3 + 8) + v37) = *v36;
                            *(_QWORD *)(*(_QWORD *)(a3 + 8) + v37 + 8) = *((unsigned int *)v36 + 1);
                            *(_WORD *)(*(_QWORD *)(a3 + 8) + v37 + 16) = 0;
                            if ( v16 + (unsigned int)v34 + 32 > a2 )
                              break;
                            if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
                            {
                              v38 = *(_QWORD *)(a3 + 8) + 112LL * ((int)v18 + v35);
                              v70 = v18;
                              v68 = v19;
                              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                3,
                                debug_mdl & 0x800000000LL,
                                4,
                                "cam_sensor_update_power_settings",
                                1584,
                                "Seq Type[%d]: %d Config_val: %ld",
                                v18 + v35,
                                *(_DWORD *)v38,
                                *(_QWORD *)(v38 + 8));
                              v19 = v68;
                              v18 = v70;
                            }
                            ++v35;
                            v34 += 12;
                            if ( (unsigned int)v35 >= *(_DWORD *)v20 )
                            {
                              v18 = (unsigned int)(v18 + v35);
                              v30 = v16 + v34 + 20;
                              v29 = (__int64)v20 + v34 + 20;
                              goto LABEL_83;
                            }
                          }
LABEL_94:
                          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                            3,
                            0x800000000LL,
                            1,
                            "cam_sensor_update_power_settings",
                            1576,
                            "Error: Cmd Buffer is wrong");
                          goto LABEL_103;
                        }
                        v18 = (unsigned int)(v18 + 1);
                      }
LABEL_83:
                      v17 = 2;
                    }
LABEL_28:
                    v9 = 0;
                    v16 = v30;
                    v20 = (_QWORD *)v29;
                    if ( v30 >= a2 )
                      goto LABEL_111;
                  }
                  v49 = *((unsigned __int8 *)v20 + 4);
                  if ( v49 == 3 && v17 == 2 )
                  {
                    if ( (int)v18 >= 1 )
                    {
                      v50 = *(_QWORD *)(a3 + 8) + 112LL * (unsigned int)v18;
LABEL_76:
                      *(_WORD *)(v50 - 96) += *(_WORD *)v20;
LABEL_88:
                      v30 = v16 + 8;
                      if ( v16 + 8 > a2 )
                      {
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                          3,
                          0x800000000LL,
                          1,
                          "cam_sensor_update_power_settings",
                          1630,
                          "Command Buffer is wrong");
                        return (unsigned int)-22;
                      }
                      v29 = (__int64)(v20 + 1);
                      if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
                      {
                        v55 = v20;
                        v67 = v20 + 1;
                        v56 = v18;
                        v57 = v19;
                        v58 = v17;
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          debug_mdl & 0x800000000LL,
                          4,
                          "cam_sensor_update_power_settings",
                          1640,
                          "ptr: %pK sizeof: %d Next: %pK",
                          v55,
                          8,
                          v67);
                        v17 = v58;
                        v19 = v57;
                        v18 = v56;
                      }
                      goto LABEL_28;
                    }
                    v54 = 1604;
                  }
                  else
                  {
                    if ( v49 != 3 || v17 != 3 )
                    {
                      if ( (debug_mdl & 0x800000000LL) == 0 || debug_priority )
                        goto LABEL_88;
                      v51 = v18;
                      v52 = v19;
                      v53 = v17;
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        debug_mdl & 0x800000000LL,
                        4,
                        "cam_sensor_update_power_settings",
                        1623,
                        "Invalid op code: %d",
                        v49);
                      goto LABEL_87;
                    }
                    if ( v19 >= 1 )
                    {
                      v50 = *(_QWORD *)(a3 + 24) + 112LL * (unsigned int)v19;
                      goto LABEL_76;
                    }
                    v54 = 1619;
                  }
                  v51 = v18;
                  v52 = v19;
                  v53 = v17;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x800000000LL,
                    1,
                    "cam_sensor_update_power_settings",
                    v54,
                    "Delay is expected only after valid power up setting");
LABEL_87:
                  v17 = v53;
                  v19 = v52;
                  v18 = v51;
                  goto LABEL_88;
                }
              }
              else
              {
                v22 = _kvmalloc_node_noprof(1344, 0, 3520, 0xFFFFFFFFLL);
                *(_QWORD *)(a3 + 24) = v22;
                if ( v22 )
                  goto LABEL_20;
              }
              v23 = *(_QWORD **)(a3 + 8);
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v23, 0);
              else
                kvfree(v23);
              *(_QWORD *)(a3 + 8) = 0;
              v9 = -12;
LABEL_110:
              *(_WORD *)(a3 + 16) = 0;
              goto LABEL_111;
            }
          }
          else
          {
            v21 = _kvmalloc_node_noprof(1344, 0, 3520, 0xFFFFFFFFLL);
            *(_QWORD *)(a3 + 8) = v21;
            if ( v21 )
              goto LABEL_18;
          }
          v9 = -12;
LABEL_111:
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v8, 0);
          else
            kvfree(v8);
          return v9;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_validate",
          1463,
          "Invalid cmd_buf len %zu min %zu",
          a4);
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_update_power_settings",
        1492,
        "Invalid Args: pwr_cmd %pK, cmd_length: %d",
        v8,
        a2);
      v9 = -22;
      goto LABEL_111;
    }
  }
  else
  {
    v8 = (_QWORD *)_kvmalloc_node_noprof(a4, 0, 3520, 0xFFFFFFFFLL);
    if ( v8 )
      goto LABEL_3;
  }
  v9 = -12;
  if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x800000000LL,
      4,
      "cam_sensor_update_power_settings",
      1482,
      "pwr_cmd memory allocation failed!");
  return v9;
}
