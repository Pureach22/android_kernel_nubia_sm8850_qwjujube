__int64 __fastcall cam_ois_driver_cmd(__int64 a1, __int64 a2)
{
  int v2; // w6
  __int64 v4; // x21
  int v6; // w6
  __int64 v7; // x1
  __int64 v8; // x25
  unsigned int v9; // w20
  __int64 result; // x0
  int v11; // w8
  __int64 v12; // x0
  const char *v13; // x5
  __int64 v14; // x4
  const char *v15; // x5
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x4
  int v19; // w8
  int v20; // w9
  const char *v21; // x5
  __int64 v22; // x4
  const char *v23; // x5
  __int64 v24; // x4
  unsigned int cpu_buf; // w0
  unsigned int v26; // w0
  __int64 v27; // x0
  unsigned int v28; // w20
  int v29; // w8
  _QWORD *v30; // x0
  _QWORD *v31; // x0
  unsigned int v32; // w0
  unsigned __int64 v33; // x24
  __int64 v34; // x25
  __int64 v35; // x8
  int *v36; // x8
  int *v37; // x8
  int v38; // t1
  __int64 v39; // x8
  int *v40; // x8
  int *v41; // x8
  int v42; // t1
  _QWORD *v43; // x0
  unsigned int v44; // w0
  int device_hdl; // w0
  int v46; // w9
  int v47; // w8
  unsigned __int64 StatusReg; // x9
  __int64 v49; // x8
  unsigned __int64 v50; // x10
  unsigned __int64 v51; // x10
  unsigned __int64 v57; // x9
  __int64 v58; // x0
  unsigned __int64 v59; // x8
  unsigned __int64 v61; // x9
  const char *v62; // x5
  __int64 v63; // x4
  _QWORD *v64; // x0
  _QWORD *v65; // x0
  unsigned int *v66; // x8
  unsigned int v67; // w6
  const char *v68; // x5
  __int64 v69; // x2
  __int64 v70; // x4
  unsigned int v71; // w22
  __int64 v72; // x27
  unsigned int *v73; // x8
  unsigned int v74; // w9
  unsigned int v75; // w0
  unsigned int v76; // w0
  const char *v77; // x5
  __int64 v78; // x4
  unsigned int *v79; // x8
  unsigned int v80; // w9
  unsigned int v81; // w0
  __int64 v82; // x1
  unsigned int *v83; // x8
  unsigned int *v84; // x9
  unsigned int *v85; // x21
  __int64 v86; // x8
  unsigned int v87; // w0
  unsigned int buf_to_list; // w0
  unsigned int current_qtimer_ns; // w0
  int v90; // w6
  unsigned int v91; // w0
  unsigned int v92; // w0
  unsigned int v93; // w0
  int *v94; // x21
  unsigned int v95; // w0
  __int64 v96; // x20
  unsigned int v97; // w0
  unsigned __int64 v98; // x24
  unsigned __int64 v99; // x28
  int *v100; // x23
  int v101; // w8
  unsigned __int64 v102; // x24
  unsigned int v103; // w0
  unsigned int updated; // w0
  __int64 v105; // x4
  const char *v106; // x5
  int v107; // w24
  unsigned int v108; // w0
  unsigned int v109; // w0
  unsigned int v110; // w0
  unsigned int v111; // w0
  const char *v112; // x5
  __int64 v113; // x4
  unsigned int v114; // w0
  unsigned int v115; // w0
  const char *v116; // x5
  __int64 v117; // x4
  int v118; // w0
  unsigned int v119; // w9
  const char *v120; // x5
  __int64 v121; // x1
  __int64 v122; // x2
  __int64 v123; // x4
  const char *v124; // x5
  __int64 v125; // x4
  const char *v126; // x5
  __int64 v127; // x1
  __int64 v128; // x2
  __int64 v129; // x4
  unsigned int v130; // w0
  unsigned int v131; // w0
  unsigned int v132; // w0
  int v133; // w0
  __int64 v134; // x24
  unsigned __int64 v135; // x25
  __int64 v136; // x8
  int v137; // w0
  __int64 v138; // x8
  int v139; // w0
  _QWORD *v140; // x0
  _QWORD *v141; // x0
  _QWORD *v142; // x0
  int v143; // w0
  const char *v144; // x5
  __int64 v145; // x4
  int v146; // w20
  int v147; // w20
  int v148; // [xsp+8h] [xbp-88h] BYREF
  __int16 v149; // [xsp+Ch] [xbp-84h]
  __int64 v150; // [xsp+10h] [xbp-80h] BYREF
  __int64 *v151; // [xsp+18h] [xbp-78h]
  __int64 v152; // [xsp+20h] [xbp-70h]
  __int64 v153; // [xsp+28h] [xbp-68h]
  __int64 v154; // [xsp+30h] [xbp-60h]
  __int64 v155; // [xsp+38h] [xbp-58h]
  __int64 v156; // [xsp+40h] [xbp-50h] BYREF
  unsigned __int64 v157; // [xsp+48h] [xbp-48h] BYREF
  unsigned int *v158; // [xsp+50h] [xbp-40h] BYREF
  unsigned __int64 v159; // [xsp+58h] [xbp-38h] BYREF
  __int64 v160; // [xsp+60h] [xbp-30h] BYREF
  __int64 v161; // [xsp+68h] [xbp-28h] BYREF
  unsigned __int64 v162; // [xsp+70h] [xbp-20h]
  __int64 v163; // [xsp+78h] [xbp-18h]
  _QWORD v164[2]; // [xsp+80h] [xbp-10h] BYREF

  v164[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v149 = 0;
  v148 = 0;
  if ( a1 && a2 )
  {
    v2 = *(_DWORD *)(a2 + 8);
    if ( v2 == 1 )
    {
      v4 = *(_QWORD *)(a1 + 3376);
      mutex_lock(a1 + 32);
      v6 = *(_DWORD *)a2;
      if ( *(int *)a2 > 259 )
      {
        if ( v6 <= 261 )
        {
          if ( v6 != 260 )
          {
            v7 = *(_QWORD *)(a2 + 16);
            v8 = *(_QWORD *)(a1 + 3376);
            v163 = 0;
            v164[0] = 0;
            v161 = 0;
            v162 = 0;
            v159 = 0;
            v160 = 0;
            v158 = nullptr;
            v157 = 0;
            if ( inline_copy_from_user_10(&v161, v7) )
            {
              v9 = -14;
              goto LABEL_108;
            }
            cpu_buf = cam_mem_get_cpu_buf(v163, &v160, &v159);
            if ( cpu_buf )
            {
              v9 = cpu_buf;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x100000,
                1,
                "cam_ois_pkt_parse",
                1319,
                "error in converting command Handle Error: %d",
                cpu_buf);
              goto LABEL_108;
            }
            if ( v159 < 0x40 || v162 >= v159 - 64 )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                3,
                0x100000,
                1,
                "cam_ois_pkt_parse",
                1329,
                "Inval cam_packet strut size: %zu, len_of_buff: %zu",
                64);
              v9 = -22;
              goto LABEL_107;
            }
            v44 = cam_packet_util_copy_pkt_to_kmd(v160 + (unsigned int)v162, &v158, v159 - v162);
            if ( v44 )
            {
              v9 = v44;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x100000,
                1,
                "cam_ois_pkt_parse",
                1339,
                "Copying packet to KMD failed");
LABEL_107:
              cam_mem_put_cpu_buf(v163);
              goto LABEL_108;
            }
            v66 = v158;
            v67 = *v158 & 0xFFFFFF;
            if ( v67 <= 1 )
            {
              if ( v67 )
              {
                if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    debug_mdl & 0x100000,
                    4,
                    "cam_ois_pkt_parse",
                    1637,
                    "CAM_OIS_PACKET_OPCODE_OIS_CONTROL");
                if ( *(_DWORD *)(a1 + 4512) <= 1u )
                {
                  v68 = "Not in right state to control OIS: %d";
                  v69 = 2;
                  v70 = 1642;
LABEL_138:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x100000,
                    v69,
                    "cam_ois_pkt_parse",
                    v70,
                    v68);
LABEL_139:
                  v9 = -22;
                  goto LABEL_140;
                }
                v73 = v158;
                v74 = v158[6];
                *(_DWORD *)(a1 + 4432) = 1;
                *(_QWORD *)(a1 + 4440) = 0;
                v75 = cam_sensor_i2c_command_parser(a1 + 3656, a1 + 4416, (char *)v73 + (v74 & 0xFFFFFFFC) + 56, 1, 0);
                if ( (v75 & 0x80000000) != 0 )
                {
                  v9 = v75;
                  v77 = "OIS pkt parsing failed: %d";
                  v78 = 1655;
                  goto LABEL_229;
                }
                v76 = cam_ois_apply_settings(a1, a1 + 4416);
                if ( (v76 & 0x80000000) != 0 )
                {
                  v9 = v76;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x100000,
                    1,
                    "cam_ois_pkt_parse",
                    1661,
                    "Cannot apply mode settings");
                  goto LABEL_140;
                }
                v9 = delete_request(a1 + 4416);
                if ( (v9 & 0x80000000) != 0 )
                {
                  v77 = "Fail deleting Mode data: rc: %d";
                  v78 = 1668;
LABEL_229:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                    3,
                    0x100000,
                    1,
                    "cam_ois_pkt_parse",
                    v78,
                    v77,
                    v9);
                  goto LABEL_140;
                }
                goto LABEL_323;
              }
              if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x100000,
                  4,
                  "cam_ois_pkt_parse",
                  1346,
                  "CAM_OIS_PACKET_OPCODE_INIT,num_cmd_buf %d",
                  v158[7]);
                v66 = v158;
                if ( v158[7] )
                  goto LABEL_132;
              }
              else if ( v158[7] )
              {
LABEL_132:
                v71 = 0;
                v72 = (__int64)v66 + (v66[6] & 0xFFFFFFFC) + 56;
                do
                {
                  v94 = (int *)(v72 + 24LL * (int)v71);
                  v95 = cam_packet_util_validate_cmd_desc(v94);
                  if ( v95 )
                  {
                    v9 = v95;
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      0x100000,
                      1,
                      "cam_ois_pkt_parse",
                      1356,
                      "Invalid cmd desc");
                    goto LABEL_140;
                  }
                  v96 = (unsigned int)v94[3];
                  if ( (_DWORD)v96 )
                  {
                    v97 = cam_mem_get_cpu_buf(*v94, v164, &v157);
                    if ( (v97 & 0x80000000) != 0 )
                    {
                      v9 = v97;
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        0x100000,
                        1,
                        "cam_ois_pkt_parse",
                        1368,
                        "Failed to get cpu buf : 0x%x",
                        *v94);
                      goto LABEL_140;
                    }
                    if ( !v164[0] )
                    {
                      v112 = "invalid cmd buf";
                      v113 = 1373;
                      goto LABEL_226;
                    }
                    v98 = v157;
                    if ( v157 < 8 || (v99 = (unsigned int)v94[1], v157 - 8 < v99) )
                    {
                      v112 = "Invalid length for sensor cmd";
                      v113 = 1383;
LABEL_226:
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                        3,
                        0x100000,
                        1,
                        "cam_ois_pkt_parse",
                        v113,
                        v112);
                      cam_mem_put_cpu_buf(*v94);
                      goto LABEL_139;
                    }
                    v100 = (int *)(v164[0] + ((unsigned int)v99 & 0xFFFFFFFC));
                    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        debug_mdl & 0x100000,
                        4,
                        "cam_ois_pkt_parse",
                        1393,
                        "cmm_hdr->cmd_type: %d",
                        *((unsigned __int8 *)v100 + 5));
                    v101 = *((unsigned __int8 *)v100 + 5);
                    v102 = v98 - v99;
                    if ( (unsigned int)(v101 - 2) < 2 )
                    {
                      if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                          3,
                          debug_mdl & 0x100000,
                          4,
                          "cam_ois_pkt_parse",
                          1407,
                          "Received power settings buffer");
                      updated = cam_sensor_update_power_settings(v100, (unsigned int)v96, v8 + 16);
                      if ( !updated )
                        goto LABEL_164;
                      v9 = updated;
                      v105 = 1414;
                      v106 = "Failed: parse power settings";
                    }
                    else
                    {
                      if ( v101 != 17 )
                      {
                        if ( v101 == 4 )
                        {
                          v93 = cam_ois_slaveInfo_pkt_parser(a1, v100, v102);
                          if ( (v93 & 0x80000000) != 0 )
                          {
                            v9 = v93;
                            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                              3,
                              0x100000,
                              1,
                              "cam_ois_pkt_parse",
                              1400,
                              "Failed in parsing slave info");
                            goto LABEL_248;
                          }
                        }
                        else if ( *(_DWORD *)(a1 + 4336) )
                        {
                          if ( *(_BYTE *)(a1 + 4549) && !*(_DWORD *)(a1 + 4384) )
                          {
                            if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                                3,
                                debug_mdl & 0x100000,
                                4,
                                "cam_ois_pkt_parse",
                                1463,
                                "Received calib settings");
                            *(_DWORD *)(a1 + 4384) = 1;
                            *(_QWORD *)(a1 + 4392) = 0;
                            v111 = cam_sensor_i2c_command_parser(a1 + 3656, a1 + 4368, v94, 1, 0);
                            if ( (v111 & 0x80000000) != 0 )
                            {
                              v9 = v111;
                              v126 = "Calib parsing failed: %d";
                              v127 = 0x100000;
                              v128 = 1;
                              v129 = 1473;
                              goto LABEL_247;
                            }
                          }
                          else if ( !*(_DWORD *)(a1 + 4288) )
                          {
                            if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                                3,
                                debug_mdl & 0x100000,
                                4,
                                "cam_ois_pkt_parse",
                                1477,
                                "received fwinit settings");
                            *(_DWORD *)(a1 + 4288) = 1;
                            *(_QWORD *)(a1 + 4296) = 0;
                            v103 = cam_sensor_i2c_command_parser(a1 + 3656, a1 + 4272, v94, 1, 0);
                            if ( (v103 & 0x80000000) != 0 )
                            {
                              v9 = v103;
                              if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                              {
                                v126 = "fw init parsing failed: %d";
                                v127 = debug_mdl & 0x100000;
                                v128 = 4;
                                v129 = 1488;
                                goto LABEL_247;
                              }
LABEL_248:
                              cam_mem_put_cpu_buf(*v94);
LABEL_140:
                              cam_common_mem_free((__int64)v158);
                              cam_mem_put_cpu_buf(v163);
                              if ( !v9 )
                              {
LABEL_110:
                                mutex_lock(a1 + 4680);
                                cam_sensor_util_release_read_buf(a1 + 4664);
                                mutex_unlock(a1 + 4680);
                                mutex_unlock(a1 + 32);
                                result = v9;
                                goto LABEL_111;
                              }
LABEL_108:
                              v62 = "Failed in ois pkt Parsing";
                              v63 = 2024;
LABEL_109:
                              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                                3,
                                0x100000,
                                1,
                                "cam_ois_driver_cmd",
                                v63,
                                v62);
                              goto LABEL_110;
                            }
                          }
                        }
                        else
                        {
                          if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                              3,
                              debug_mdl & 0x100000,
                              4,
                              "cam_ois_pkt_parse",
                              1445,
                              "Received init/config settings");
                          *(_DWORD *)(a1 + 4336) = 1;
                          *(_QWORD *)(a1 + 4344) = 0;
                          v110 = cam_sensor_i2c_command_parser(a1 + 3656, a1 + 4320, v94, 1, 0);
                          if ( (v110 & 0x80000000) != 0 )
                          {
                            v9 = v110;
                            v126 = "init parsing failed: %d";
                            v127 = 0x100000;
                            v128 = 1;
                            v129 = 1456;
LABEL_247:
                            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                              3,
                              v127,
                              v128,
                              "cam_ois_pkt_parse",
                              v129,
                              v126,
                              v9);
                            goto LABEL_248;
                          }
                        }
LABEL_164:
                        cam_mem_put_cpu_buf(*v94);
                        goto LABEL_165;
                      }
                      v107 = *v100;
                      if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          debug_mdl & 0x100000,
                          4,
                          "cam_ois_pkt_parse",
                          1422,
                          "Received fwInfo buffer,total_cmd_buf_in_bytes: %d, fwversion: %d",
                          v96,
                          v107);
                      if ( v107 == 2 )
                      {
                        v108 = cam_ois_fw_info_pkt_parser_v2(a1, v100, v96);
                        if ( !v108 )
                          goto LABEL_164;
                        v9 = v108;
                        v105 = 1428;
                        v106 = "Failed: parse fw info2 settings";
                      }
                      else
                      {
                        v109 = cam_ois_fw_info_pkt_parser(a1, v100, v96);
                        if ( !v109 )
                          goto LABEL_164;
                        v9 = v109;
                        v105 = 1437;
                        v106 = "Failed: parse fw info settings";
                      }
                    }
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      0x100000,
                      1,
                      "cam_ois_pkt_parse",
                      v105,
                      v106);
                    cam_mem_put_cpu_buf(*v94);
                    if ( (v9 & 0x80000000) != 0 )
                      goto LABEL_140;
                  }
LABEL_165:
                  ++v71;
                }
                while ( v71 < v158[7] );
              }
              if ( *(_DWORD *)(a1 + 4512) != 2 )
              {
                v130 = cam_ois_power_up(a1);
                if ( v130 )
                {
                  v9 = v130;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x100000,
                    1,
                    "cam_ois_pkt_parse",
                    1503,
                    " OIS Power up failed");
                  goto LABEL_140;
                }
              }
              if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x100000,
                  4,
                  "cam_ois_pkt_parse",
                  1508,
                  "ois_fw_flag: %d",
                  *(unsigned __int8 *)(a1 + 4548));
                if ( !*(_BYTE *)(a1 + 4548) )
                  goto LABEL_277;
              }
              else if ( !*(_BYTE *)(a1 + 4548) )
              {
                goto LABEL_277;
              }
              if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x100000,
                  4,
                  "cam_ois_pkt_parse",
                  1510,
                  "fw_count: %d",
                  *(unsigned __int8 *)(a1 + 4572));
                if ( *(_BYTE *)(a1 + 4572) )
                {
LABEL_259:
                  v131 = cam_ois_fw_download_v2(a1);
                  if ( v131 )
                  {
                    v9 = v131;
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      0x100000,
                      1,
                      "cam_ois_pkt_parse",
                      1514,
                      "Failed OIS FW Download v2");
                    goto LABEL_333;
                  }
LABEL_277:
                  if ( *(_DWORD *)(a1 + 4336) != 1 )
                    goto LABEL_284;
                  v9 = cam_ois_apply_settings(a1, a1 + 4320);
                  if ( v9 == -11 )
                  {
                    if ( *(_DWORD *)(a1 + 3656) != 1 )
                    {
                      v9 = -11;
LABEL_327:
                      v144 = "Cannot apply Init settings: rc = %d";
                      v145 = 1562;
LABEL_332:
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                        3,
                        0x100000,
                        1,
                        "cam_ois_pkt_parse",
                        v145,
                        v144,
                        v9);
                      goto LABEL_333;
                    }
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      0x100000,
                      2,
                      "cam_ois_pkt_parse",
                      1553,
                      "CCI HW is restting: Reapplying INIT settings");
                    usleep_range_state(1000, 1010, 2);
                    v9 = cam_ois_apply_settings(a1, a1 + 4320);
                  }
                  if ( (v9 & 0x80000000) == 0 )
                  {
                    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                    {
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                        3,
                        debug_mdl & 0x100000,
                        4,
                        "cam_ois_pkt_parse",
                        1565,
                        "apply Init settings success");
                      if ( !*(_BYTE *)(a1 + 4549) )
                        goto LABEL_292;
LABEL_285:
                      v9 = cam_ois_apply_settings(a1, a1 + 4368);
                      if ( v9 == -11 )
                      {
                        if ( *(_DWORD *)(a1 + 3656) != 1 )
                        {
                          v9 = -11;
                          goto LABEL_329;
                        }
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                          3,
                          0x100000,
                          2,
                          "cam_ois_pkt_parse",
                          1575,
                          "CCI HW is restting: Reapplying calib settings");
                        usleep_range_state(1000, 1010, 2);
                        v9 = cam_ois_apply_settings(a1, a1 + 4368);
                      }
                      if ( !v9 )
                      {
                        if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                            3,
                            debug_mdl & 0x100000,
                            4,
                            "cam_ois_pkt_parse",
                            1584,
                            "apply calib data settings success");
LABEL_292:
                        *(_DWORD *)(a1 + 4512) = 2;
                        v133 = delete_request(a1 + 4272);
                        if ( v133 < 0 )
                          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                            3,
                            0x100000,
                            2,
                            "cam_ois_pkt_parse",
                            1593,
                            "Fail deleting fwinit data: rc: %d",
                            v133);
                        if ( *(_BYTE *)(a1 + 4572) )
                        {
                          v134 = 0;
                          v135 = 0;
                          do
                          {
                            v136 = *(_QWORD *)(a1 + 4584);
                            if ( v136 )
                            {
                              if ( *(_DWORD *)(v136 + v134 + 16) == 1 )
                              {
                                v137 = delete_request(v136 + v134);
                                if ( v137 < 0 )
                                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                    3,
                                    0x100000,
                                    2,
                                    "cam_ois_pkt_parse",
                                    1601,
                                    "Fail deleting i2c_fw_init_data: rc: %d",
                                    v137);
                              }
                            }
                            v138 = *(_QWORD *)(a1 + 4592);
                            if ( v138 )
                            {
                              if ( *(_DWORD *)(v138 + v134 + 16) == 1 )
                              {
                                v139 = delete_request(v138 + v134);
                                if ( v139 < 0 )
                                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                    3,
                                    0x100000,
                                    2,
                                    "cam_ois_pkt_parse",
                                    1608,
                                    "Fail deleting i2c_fw_finalize_data: rc: %d",
                                    v139);
                              }
                            }
                            ++v135;
                            v134 += 48;
                          }
                          while ( v135 < *(unsigned __int8 *)(a1 + 4572) );
                        }
                        v140 = *(_QWORD **)(a1 + 4584);
                        if ( v140 )
                        {
                          if ( mem_trace_en == 1 )
                            cam_mem_trace_free(v140, 0);
                          else
                            kvfree(v140);
                          *(_QWORD *)(a1 + 4584) = 0;
                        }
                        v141 = *(_QWORD **)(a1 + 4592);
                        if ( v141 )
                        {
                          if ( mem_trace_en == 1 )
                            cam_mem_trace_free(v141, 0);
                          else
                            kvfree(v141);
                          *(_QWORD *)(a1 + 4592) = 0;
                        }
                        v142 = *(_QWORD **)(a1 + 4574);
                        if ( v142 )
                        {
                          if ( mem_trace_en == 1 )
                            cam_mem_trace_free(v142, 0);
                          else
                            kvfree(v142);
                          *(_QWORD *)(a1 + 4574) = 0;
                        }
                        v143 = delete_request(a1 + 4320);
                        if ( v143 < 0 )
                          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                            3,
                            0x100000,
                            2,
                            "cam_ois_pkt_parse",
                            1627,
                            "Fail deleting Init data: rc: %d",
                            v143);
                        v9 = delete_request(a1 + 4368);
                        if ( (v9 & 0x80000000) != 0 )
                        {
                          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                            3,
                            0x100000,
                            2,
                            "cam_ois_pkt_parse",
                            1632,
                            "Fail deleting Calibration data: rc: %d",
                            v9);
                          v9 = 0;
                          goto LABEL_140;
                        }
LABEL_323:
                        if ( !v9 )
                          goto LABEL_140;
LABEL_333:
                        cam_ois_power_down(a1);
                        goto LABEL_140;
                      }
LABEL_329:
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                        3,
                        0x100000,
                        1,
                        "cam_ois_pkt_parse",
                        1581,
                        "Cannot apply calib data");
                      goto LABEL_333;
                    }
LABEL_284:
                    if ( !*(_BYTE *)(a1 + 4549) )
                      goto LABEL_292;
                    goto LABEL_285;
                  }
                  goto LABEL_327;
                }
              }
              else if ( *(_BYTE *)(a1 + 4572) )
              {
                goto LABEL_259;
              }
              if ( *(_DWORD *)(a1 + 4288) != 1 )
                goto LABEL_277;
              v9 = cam_ois_apply_settings(a1, a1 + 4272);
              if ( v9 == -11 )
              {
                if ( *(_DWORD *)(a1 + 3656) != 1 )
                {
                  v9 = -11;
                  goto LABEL_331;
                }
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  0x100000,
                  2,
                  "cam_ois_pkt_parse",
                  1525,
                  "Reapplying fwinit settings");
                usleep_range_state(1000, 1010, 2);
                v9 = cam_ois_apply_settings(a1, a1 + 4272);
              }
              if ( !v9 )
              {
                if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    debug_mdl & 0x100000,
                    4,
                    "cam_ois_pkt_parse",
                    1536,
                    "OIS fwinit settings success");
                v132 = cam_ois_fw_download(a1);
                if ( v132 )
                {
                  v9 = v132;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x100000,
                    1,
                    "cam_ois_pkt_parse",
                    1541,
                    "Failed OIS FW Download");
                  goto LABEL_333;
                }
                goto LABEL_277;
              }
LABEL_331:
              v144 = "Cannot apply fwinit data %d";
              v145 = 1533;
              goto LABEL_332;
            }
            if ( v67 != 2 )
            {
              if ( v67 != 3 )
              {
                v68 = "Invalid Opcode: %d";
                v69 = 1;
                v70 = 1858;
                goto LABEL_138;
              }
              if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  debug_mdl & 0x100000,
                  4,
                  "cam_ois_pkt_parse",
                  1766,
                  "CAM_OIS_PACKET_OPCODE_WRITE_TIME");
              if ( *(_DWORD *)(a1 + 4512) <= 1u )
              {
                v68 = "Not in right state to write time to OIS: %d";
                v69 = 1;
                v70 = 1771;
                goto LABEL_138;
              }
              v79 = v158;
              v80 = v158[6];
              *(_DWORD *)(a1 + 4480) = 1;
              *(_QWORD *)(a1 + 4488) = 0;
              v81 = cam_sensor_i2c_command_parser(a1 + 3656, a1 + 4464, (char *)v79 + (v80 & 0xFFFFFFFC) + 56, 1, 0);
              if ( (v81 & 0x80000000) != 0 )
              {
                v9 = v81;
                v77 = "OIS pkt parsing failed: %d";
                v78 = 1784;
                goto LABEL_229;
              }
              if ( (*(_BYTE *)(a1 + 4728) & 1) != 0 || strncmp((const char *)(a1 + 4516), "ois_ov64b40_qwbarley", 0x14u) )
                goto LABEL_149;
              LODWORD(v150) = 0;
              v118 = camera_io_dev_read(a1 + 3656, 28944, &v150, 2, 2, 0);
              v119 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 20);
              if ( v118 < 0 )
              {
                if ( v119 )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x100000,
                    4,
                    "cam_ois_pkt_parse",
                    1799,
                    "%s read x gyro raw failed",
                    (const char *)(a1 + 4516));
LABEL_149:
                if ( *(_BYTE *)(a1 + 4572) )
                  v82 = *(unsigned __int8 *)(a1 + 4573) >> 4;
                else
                  v82 = 1;
                v114 = cam_ois_update_time(a1 + 4464, v82);
                if ( (v114 & 0x80000000) != 0 )
                {
                  v9 = v114;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x100000,
                    1,
                    "cam_ois_pkt_parse",
                    1838,
                    "Cannot update time");
                  goto LABEL_140;
                }
                v115 = cam_ois_apply_settings(a1, a1 + 4464);
                if ( (v115 & 0x80000000) != 0 )
                {
                  v9 = v115;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x100000,
                    1,
                    "cam_ois_pkt_parse",
                    1844,
                    "Cannot apply mode settings");
                  goto LABEL_140;
                }
                v9 = delete_request(a1 + 4464);
                if ( (v9 & 0x80000000) != 0 )
                {
                  v77 = "Fail deleting Mode data: rc: %d";
                  v78 = 1851;
                  goto LABEL_229;
                }
                goto LABEL_323;
              }
              if ( v119 )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x100000,
                  4,
                  "cam_ois_pkt_parse",
                  1801,
                  "%s read x gyro raw 0x%x",
                  (const char *)(a1 + 4516),
                  v150);
                if ( (_DWORD)v150 )
                {
LABEL_233:
                  *(_BYTE *)(a1 + 4728) = 1;
                  if ( (debug_mdl & 0x100000) == 0 || debug_priority )
                    goto LABEL_149;
                  v120 = "dw9784 gyro raw is valid!";
                  v121 = debug_mdl & 0x100000;
                  v122 = 4;
                  v123 = 1826;
                  goto LABEL_342;
                }
              }
              else if ( (_DWORD)v150 )
              {
                goto LABEL_233;
              }
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x100000,
                1,
                "cam_ois_pkt_parse",
                1803,
                "%s read x gyro raw is 0, config again",
                (const char *)(a1 + 4516));
              v146 = zte_cam_cci_i2c_write(a1 + 3656, 28704, 1, 2, 2);
              msleep(1);
              v147 = zte_cam_cci_i2c_write(a1 + 3656, 28704, 0, 2, 2) | v146;
              msleep(1);
              if ( v147 < 0 )
              {
                v120 = "dw9784 set 0x7020 failed";
                v121 = 0x100000;
                v122 = 1;
                v123 = 1819;
              }
              else
              {
                *(_BYTE *)(a1 + 4728) = 1;
                if ( (debug_mdl & 0x100000) == 0 || debug_priority )
                  goto LABEL_149;
                v120 = "dw9784 gyro raw config done!";
                v121 = debug_mdl & 0x100000;
                v122 = 4;
                v123 = 1822;
              }
LABEL_342:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                v121,
                v122,
                "cam_ois_pkt_parse",
                v123,
                v120);
              goto LABEL_149;
            }
            v155 = 0;
            v156 = 0;
            v153 = 0;
            v154 = 0;
            v152 = 0;
            if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                debug_mdl & 0x100000,
                4,
                "cam_ois_pkt_parse",
                1677,
                "CAM_OIS_PACKET_OPCODE_READ");
            if ( *(_DWORD *)(a1 + 4512) <= 1u )
            {
              v68 = "Not in right state to read OIS: %d";
              v69 = 2;
              v70 = 1683;
              goto LABEL_138;
            }
            v83 = v158;
            if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x100000,
                4,
                "cam_ois_pkt_parse",
                1687,
                "number of I/O configs: %d:",
                v158[9]);
              v83 = v158;
              if ( v158[9] )
                goto LABEL_154;
            }
            else if ( v158[9] )
            {
LABEL_154:
              v150 = (__int64)&v150;
              v151 = &v150;
              v84 = v83 + 14;
              v85 = (unsigned int *)((char *)v83 + v83[8] + 56);
              if ( v85 )
              {
                v86 = v83[6] & 0xFFFFFFFC;
                LODWORD(v152) = 1;
                v153 = 0;
                v87 = cam_sensor_i2c_command_parser(a1 + 3656, &v150, (char *)v84 + v86, 1, v85);
                if ( (v87 & 0x80000000) != 0 )
                {
                  v9 = v87;
                  v77 = "OIS read pkt parsing failed: %d";
                  v78 = 1716;
                  goto LABEL_229;
                }
                mutex_lock(a1 + 4680);
                buf_to_list = cam_sensor_util_add_read_buf_to_list(a1 + 4664, *v85);
                if ( (buf_to_list & 0x80000000) != 0 )
                {
                  v9 = buf_to_list;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x100000,
                    1,
                    "cam_ois_pkt_parse",
                    1724,
                    "Add read buf to list failed rc:%d",
                    buf_to_list);
                  mutex_unlock(a1 + 4680);
                  goto LABEL_140;
                }
                mutex_unlock(a1 + 4680);
                current_qtimer_ns = cam_sensor_util_get_current_qtimer_ns(&v156);
                if ( (current_qtimer_ns & 0x80000000) != 0 )
                {
                  v9 = current_qtimer_ns;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x100000,
                    1,
                    "cam_ois_pkt_parse",
                    1732,
                    "failed to get qtimer rc:%d",
                    v90);
                  goto LABEL_140;
                }
                v91 = cam_sensor_i2c_read_data(&v150, a1 + 3656);
                if ( (v91 & 0x80000000) != 0 )
                {
                  v9 = v91;
                  v124 = "cannot read data rc: %d";
                  v125 = 1740;
                }
                else
                {
                  if ( v158[9] < 2
                    || (v92 = cam_sensor_util_write_qtimer_to_io_buffer(v156, v85 + 64), (v92 & 0x80000000) == 0) )
                  {
                    v9 = delete_request(&v150);
                    if ( (v9 & 0x80000000) != 0 )
                    {
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                        3,
                        0x100000,
                        1,
                        "cam_ois_pkt_parse",
                        1759,
                        "Failed in deleting the read settings");
                      goto LABEL_140;
                    }
                    goto LABEL_323;
                  }
                  v9 = v92;
                  v124 = "write qtimer failed rc: %d";
                  v125 = 1750;
                }
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                  3,
                  0x100000,
                  1,
                  "cam_ois_pkt_parse",
                  v125,
                  v124,
                  v9);
                delete_request(&v150);
                goto LABEL_140;
              }
              v116 = "I/O config is invalid(NULL)";
              v117 = 1702;
LABEL_263:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x100000,
                1,
                "cam_ois_pkt_parse",
                v117,
                v116);
              goto LABEL_139;
            }
            v116 = "No I/O configs to process";
            v117 = 1689;
            goto LABEL_263;
          }
          if ( *(_DWORD *)(a1 + 4512) == 3 )
          {
            v11 = 2;
            goto LABEL_28;
          }
          v23 = "Not in right state for stop : %d";
          v24 = 2117;
          goto LABEL_37;
        }
        if ( v6 == 262 )
        {
          v19 = *(_DWORD *)(a1 + 4512);
          if ( v19 == 2 )
          {
            v26 = cam_ois_power_down(a1);
            if ( (v26 & 0x80000000) != 0 )
            {
              v9 = v26;
              v62 = "OIS Power down failed";
              v63 = 2039;
              goto LABEL_109;
            }
          }
          else if ( v19 == 3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x100000,
              2,
              "cam_ois_driver_cmd",
              2032,
              "Cant release ois: in start state");
            v9 = -22;
            goto LABEL_110;
          }
          v27 = *(unsigned int *)(a1 + 4192);
          if ( (_DWORD)v27 == -1 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x100000,
              1,
              "cam_ois_driver_cmd",
              2047,
              "link hdl: %d device hdl: %d",
              -1,
              *(_DWORD *)(a1 + 4200));
            v9 = -22;
          }
          else
          {
            v28 = cam_destroy_device_hdl(v27);
            if ( (v28 & 0x80000000) != 0 )
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x100000,
                1,
                "cam_ois_driver_cmd",
                2053,
                "destroying the device hdl");
            *(_QWORD *)(a1 + 4192) = -1;
            v29 = (unsigned __int8)mem_trace_en;
            *(_DWORD *)(a1 + 4200) = -1;
            *(_DWORD *)(a1 + 4512) = 0;
            v30 = *(_QWORD **)(v4 + 24);
            if ( v29 == 1 )
              cam_mem_trace_free(v30, 0);
            else
              kvfree(v30);
            v31 = *(_QWORD **)(v4 + 40);
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v31, 0);
            else
              kvfree(v31);
            *(_QWORD *)(v4 + 24) = 0;
            *(_QWORD *)(v4 + 40) = 0;
            *(_WORD *)(v4 + 48) = 0;
            *(_WORD *)(v4 + 32) = 0;
            if ( *(_DWORD *)(a1 + 4432) == 1 )
              delete_request(a1 + 4416);
            if ( *(_DWORD *)(a1 + 4384) == 1 )
              delete_request(a1 + 4368);
            if ( *(_DWORD *)(a1 + 4336) == 1 )
              delete_request(a1 + 4320);
            if ( *(_DWORD *)(a1 + 4288) == 1 )
              delete_request(a1 + 4272);
            v32 = v28;
            if ( *(_BYTE *)(a1 + 4572) )
            {
              v33 = 0;
              v34 = 16;
              do
              {
                v35 = *(_QWORD *)(a1 + 4584);
                if ( v35 )
                {
                  v36 = (int *)(v35 + v34);
                  v38 = *v36;
                  v37 = v36 - 4;
                  if ( v38 == 1 )
                  {
                    v32 = delete_request(v37);
                    if ( (v32 & 0x80000000) != 0 )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        0x100000,
                        2,
                        "cam_ois_driver_cmd",
                        2084,
                        "Fail deleting i2c_fw_init_data: rc: %d",
                        v32);
                      v32 = 0;
                    }
                  }
                }
                v39 = *(_QWORD *)(a1 + 4592);
                if ( v39 )
                {
                  v40 = (int *)(v39 + v34);
                  v42 = *v40;
                  v41 = v40 - 4;
                  if ( v42 == 1 )
                  {
                    v32 = delete_request(v41);
                    if ( (v32 & 0x80000000) != 0 )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        0x100000,
                        2,
                        "cam_ois_driver_cmd",
                        2093,
                        "Fail deleting i2c_fw_finalize_data: rc: %d",
                        v32);
                      v32 = 0;
                    }
                  }
                }
                ++v33;
                v34 += 48;
              }
              while ( v33 < *(unsigned __int8 *)(a1 + 4572) );
            }
            v9 = v32;
            if ( *(_QWORD *)(a1 + 4584) )
            {
              v43 = *(_QWORD **)(a1 + 4584);
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v43, 0);
              else
                kvfree(v43);
              *(_QWORD *)(a1 + 4584) = 0;
            }
            v64 = *(_QWORD **)(a1 + 4592);
            if ( v64 )
            {
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v64, 0);
              else
                kvfree(v64);
              *(_QWORD *)(a1 + 4592) = 0;
            }
            v65 = *(_QWORD **)(a1 + 4574);
            if ( v65 )
            {
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v65, 0);
              else
                kvfree(v65);
              *(_QWORD *)(a1 + 4574) = 0;
            }
          }
          goto LABEL_110;
        }
        if ( v6 == 264 )
        {
          v9 = 0;
          if ( (debug_mdl & 0x100000) == 0 || debug_priority )
            goto LABEL_110;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x100000,
            4,
            "cam_ois_driver_cmd",
            2123,
            "Flush recveived");
LABEL_25:
          v9 = 0;
          goto LABEL_110;
        }
        goto LABEL_23;
      }
      if ( v6 == 257 )
      {
        v12 = *(_QWORD *)(a2 + 16);
        v148 = *(_DWORD *)(a1 + 100);
        if ( !inline_copy_to_user_8(v12, &v148, 6) )
        {
          v9 = 0;
          if ( (debug_mdl & 0x100000) == 0 || debug_priority )
            goto LABEL_110;
          v15 = "ois_cap: ID: %d";
          v16 = debug_mdl & 0x100000;
          v17 = 4;
          v18 = 2000;
          goto LABEL_24;
        }
        v13 = "Failed Copy to User";
        v14 = 1996;
LABEL_45:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_driver_cmd",
          v14,
          v13);
        v9 = -14;
        goto LABEL_110;
      }
      if ( v6 != 258 )
      {
        if ( v6 == 259 )
        {
          if ( *(_DWORD *)(a1 + 4512) == 2 )
          {
            v11 = 3;
LABEL_28:
            v9 = 0;
            *(_DWORD *)(a1 + 4512) = v11;
            goto LABEL_110;
          }
          v23 = "Not in right state for start : %d";
          v24 = 2016;
LABEL_37:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x100000,
            2,
            "cam_ois_driver_cmd",
            v24,
            v23);
          v9 = -22;
          goto LABEL_110;
        }
LABEL_23:
        v15 = "invalid opcode: %d";
        v16 = 0x100000;
        v17 = 1;
        v18 = 2126;
LABEL_24:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v16,
          v17,
          "cam_ois_driver_cmd",
          v18,
          v15);
        goto LABEL_25;
      }
      v20 = *(_DWORD *)(a1 + 4192);
      v162 = 0;
      v163 = 0;
      v161 = 0;
      v151 = nullptr;
      if ( v20 == -1 )
      {
        if ( inline_copy_from_user_10(&v161, *(_QWORD *)(a2 + 16)) )
          goto LABEL_44;
        v150 = (unsigned int)v161;
        v153 = a1 + 4208;
        v154 = a1;
        v152 = 0x100000;
        device_hdl = cam_create_device_hdl((__int64)&v150);
        HIDWORD(v161) = device_hdl;
        if ( device_hdl )
        {
          v46 = v161;
          v47 = debug_mdl;
          *(_DWORD *)(a1 + 4192) = device_hdl;
          *(_DWORD *)(a1 + 4196) = v46;
          if ( (v47 & 0x100000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              *(_QWORD *)&v47 & 0x100000LL,
              4,
              "cam_ois_get_dev_handle",
              126,
              "Device Handle: %d",
              device_hdl);
          StatusReg = _ReadStatusReg(SP_EL0);
          v49 = *(_QWORD *)(a2 + 16);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0
            || (v50 = *(_QWORD *)(a2 + 16), (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          {
            v50 = v49 & (v49 << 8 >> 8);
          }
          if ( v50 <= 0x7FFFFFFFE8LL )
          {
            v51 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v57 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v57 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v57);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v51);
            v58 = _arch_copy_to_user(v49 & 0xFF7FFFFFFFFFFFFFLL);
            v59 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v61 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v61 - 4096);
            _WriteStatusReg(TTBR1_EL1, v61);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v59);
            if ( !v58 )
            {
              v11 = 1;
              goto LABEL_28;
            }
          }
          v21 = "ACQUIRE_DEV: copy to user failed";
          v22 = 129;
        }
        else
        {
          v21 = "Can not create device handle";
          v22 = 120;
        }
      }
      else
      {
        v21 = "Device is already acquired";
        v22 = 103;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_get_dev_handle",
        v22,
        v21);
LABEL_44:
      v13 = "Failed to acquire dev";
      v14 = 2005;
      goto LABEL_45;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_driver_cmd",
      1980,
      "Invalid handle type: %d",
      v2);
    result = 4294967274LL;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_driver_cmd",
      1974,
      "Invalid arguments");
    result = 4294967274LL;
  }
LABEL_111:
  _ReadStatusReg(SP_EL0);
  return result;
}
