__int64 __fastcall cam_cci_data_queue(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x8
  int *v5; // x28
  __int64 v6; // x7
  unsigned int v7; // w23
  __int64 v8; // x19
  unsigned int v9; // w22
  unsigned int v10; // w24
  __int64 v11; // x20
  int v12; // w8
  __int64 v13; // x0
  unsigned int v14; // w8
  __int64 v15; // x22
  __int64 v16; // x21
  __int64 v17; // x0
  _DWORD *v18; // x10
  __int64 v19; // x26
  char v20; // w27
  __int64 v21; // x25
  int v22; // w26
  unsigned int v23; // w8
  int v24; // w25
  unsigned int v25; // w6
  int v26; // w8
  unsigned int v27; // w7
  unsigned __int8 v28; // w9
  __int64 v29; // x10
  unsigned int v30; // w11
  unsigned int v31; // w8
  __int64 v32; // x0
  unsigned int v33; // w0
  __int64 v34; // x21
  __int64 v35; // x26
  __int64 v36; // x10
  unsigned int v37; // w9
  unsigned int v38; // w12
  unsigned int v39; // w8
  int v40; // w12
  int v41; // w10
  unsigned int v42; // w13
  char v43; // w14
  unsigned int v44; // w9
  int v45; // w12
  unsigned __int16 v46; // w13
  int v47; // w13
  unsigned int v48; // w13
  bool v49; // cf
  __int64 v50; // x19
  __int64 v51; // x0
  unsigned int v52; // w0
  int v53; // w0
  int v54; // w6
  char v55; // w8
  char v56; // w8
  int v57; // w7
  unsigned int v58; // w21
  unsigned int v59; // w26
  unsigned __int16 v60; // w27
  bool v61; // cc
  unsigned int v62; // w8
  unsigned int v63; // w9
  unsigned __int64 v64; // x9
  unsigned int v65; // w25
  int v66; // w10
  int v67; // w10
  char v68; // w8
  __int64 v69; // x0
  int v70; // w21
  int v71; // w20
  unsigned int v72; // w19
  __int64 result; // x0
  __int64 v74; // x6
  const char *v75; // x5
  unsigned int v76; // w19
  __int64 v77; // x4
  int v78; // w20
  __int64 v79; // x21
  unsigned int v80; // w26
  unsigned int v81; // [xsp+8h] [xbp-C8h]
  int v82; // [xsp+10h] [xbp-C0h]
  unsigned int v83; // [xsp+24h] [xbp-ACh]
  __int64 v84; // [xsp+28h] [xbp-A8h]
  unsigned int v85; // [xsp+30h] [xbp-A0h]
  unsigned int v86; // [xsp+34h] [xbp-9Ch]
  __int64 v87; // [xsp+38h] [xbp-98h]
  __int64 v88; // [xsp+40h] [xbp-90h]
  _DWORD *v89; // [xsp+48h] [xbp-88h]
  __int64 v90; // [xsp+58h] [xbp-78h]
  __int64 v91; // [xsp+60h] [xbp-70h]
  unsigned int v92; // [xsp+68h] [xbp-68h]
  char v94; // [xsp+70h] [xbp-60h]
  unsigned int v95; // [xsp+74h] [xbp-5Ch]
  unsigned int v96; // [xsp+78h] [xbp-58h]
  int v97; // [xsp+7Ch] [xbp-54h]
  __int64 v98; // [xsp+80h] [xbp-50h]
  __int64 v99; // [xsp+88h] [xbp-48h]
  __int64 v100; // [xsp+90h] [xbp-40h]
  int v101; // [xsp+A4h] [xbp-2Ch]
  __int64 v102; // [xsp+A8h] [xbp-28h]
  __int64 v103; // [xsp+B0h] [xbp-20h]
  int v104; // [xsp+B8h] [xbp-18h]
  __int64 v105; // [xsp+C0h] [xbp-10h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 8);
  v5 = *(int **)(a2 + 24);
  v104 = 0;
  v103 = 0;
  v6 = *(unsigned int *)(v4 + 16);
  if ( !v5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_data_queue",
      1233,
      "CCI%d_I2C_M%d_Q%d Failed: i2c cmd is NULL",
      *(unsigned int *)(a1 + 404),
      v6,
      a3);
    goto LABEL_181;
  }
  v7 = *(unsigned __int16 *)(a2 + 32);
  if ( !*(_WORD *)(a2 + 32) || v7 > 0x5000 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int, _DWORD))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_data_queue",
      1239,
      "CCI%d_I2C_M%d_Q%d failed: invalid cmd_size %d",
      *(unsigned int *)(a1 + 404),
      v6,
      a3,
      *(unsigned __int16 *)(a2 + 32));
    goto LABEL_181;
  }
  v8 = *(_QWORD *)(a1 + 672);
  v9 = *(_DWORD *)(a2 + 40);
  v91 = *(unsigned int *)(v4 + 16);
  v100 = a2;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    v78 = a4;
    v79 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_data_queue",
      1244,
      "CCI%d_I2C_M%d_Q%d addr type %d data type %d cmd_size %d",
      *(_DWORD *)(a1 + 404),
      v6,
      a3,
      *(_DWORD *)(a2 + 36),
      v9,
      v7);
    a2 = v100;
    a1 = v79;
    a4 = v78;
  }
  if ( *(_DWORD *)(a2 + 36) >= 5u )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int, _DWORD))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_data_queue",
      1248,
      "CCI%d_I2C_M%d_Q%d failed: invalid addr_type 0x%X",
      *(unsigned int *)(a1 + 404),
      v91,
      a3,
      *(_DWORD *)(a2 + 36));
    goto LABEL_181;
  }
  if ( *(_DWORD *)(a2 + 40) >= 5u )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int, _DWORD))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_data_queue",
      1253,
      "CCI%d_I2C_M%d_Q%d failed: invalid data_type 0x%X",
      *(unsigned int *)(a1 + 404),
      v91,
      a3,
      *(_DWORD *)(a2 + 40));
    goto LABEL_181;
  }
  v98 = a1;
  LODWORD(v102) = a4;
  if ( (unsigned int)v91 > 1 || a3 > 1 )
LABEL_188:
    __break(0x5512u);
  v10 = (_DWORD)v91 << 9;
  v11 = a1 + 544LL * (unsigned int)v91 + 4040;
  *(_BYTE *)(v11 + a3 + 488) = 0;
  *(_DWORD *)(v11 + 4LL * a3 + 492) = 0;
  v95 = a3 << 8;
  v90 = ((_DWORD)v91 << 9) + (a3 << 8);
  cam_io_w_mb(*(unsigned __int16 *)(a1 + 5296), v8 + 4LL * *(__int16 *)(a1 + 5298) + 16);
  cam_cci_lock_queue(v98, (unsigned int)v91, a3, 1);
  LOWORD(v12) = debug_mdl;
  v13 = (16 * *(unsigned __int16 *)(*(_QWORD *)(v100 + 8) + 20LL))
      | (*(unsigned __int16 *)(*(_QWORD *)(v100 + 8) + 28LL) << 16)
      | (*(unsigned __int16 *)(*(_QWORD *)(v100 + 8) + 30LL) << 18)
      | 1u;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    goto LABEL_187;
LABEL_17:
  v14 = (unsigned __int8)v9;
  v15 = v8 + 784;
  v96 = v14;
  cam_io_w_mb(v13, v8 + 784 + v90);
  v16 = v11 + 4LL * a3;
  v17 = raw_spin_lock_irqsave(v16 + 328);
  v87 = v11 + 4;
  v88 = v16;
  *(_DWORD *)(v11 + 4 + 4LL * a3) = 0;
  raw_spin_unlock_irqrestore(v16 + 328, v17);
  v18 = (_DWORD *)v100;
  v19 = v98 + 32 * v91 + 16LL * a3;
  v20 = (unsigned int)(*(_DWORD *)(v100 + 16) - 9) < 0xFFFFFFFE;
  v85 = *(_DWORD *)(v19 + 3972);
  v101 = *v5;
  if ( (_DWORD)v102 == 1 && *(_BYTE *)(v98 + 5304) && v7 < v85 )
  {
    cam_io_w_mb((16 * *(unsigned __int16 *)(v98 + 5300)) | 3u, v15 + v90);
    v18 = (_DWORD *)v100;
  }
  v97 = 0;
  v89 = (_DWORD *)(v19 + 3972);
  v92 = v85 >> v20;
  v99 = v8 + v90;
  v83 = 1 << (a3 | (2 * v91));
  v102 = v15 + v10 + v95;
  v84 = v11 + 320;
  while ( 2 )
  {
    if ( !v18 )
    {
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_calc_cmd_len",
        552);
      v24 = 0;
LABEL_48:
      v11 = 65514;
LABEL_51:
      LODWORD(v13) = cam_io_r_mb(v99 + 772);
      if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
      {
        v70 = v13;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_data_queue",
          1317,
          "CCI%d_I2C_M%d_Q%d CUR_WORD_CNT_ADDR %d len %d max %d",
          *(_DWORD *)(v98 + 404),
          v91,
          a3,
          v13,
          v11,
          v85);
        LODWORD(v13) = v70;
      }
      v31 = v11 + v13 + 2;
      if ( v31 > v92 )
      {
        if ( v31 > v85 )
        {
          v21 = v98;
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_process_full_q",
              502,
              "CCI%d_I2C_M%d_Q%d ENTER",
              *(_DWORD *)(v98 + 404),
              v91,
              a3);
          v32 = raw_spin_lock_irqsave(v88 + 328);
          if ( *(_DWORD *)(v87 + 4LL * a3) == 1 )
          {
            *(_DWORD *)(v84 + 4LL * a3) = 1;
            raw_spin_unlock_irqrestore(v88 + 328, v32);
            if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x4000,
                4,
                "cam_cci_process_full_q",
                511,
                "CCI%d_I2C_M%d_Q%d is set to 1",
                *(_DWORD *)(v98 + 404),
                v91,
                a3);
            v33 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))cam_cci_wait)(v98, v91, a3);
            if ( (v33 & 0x80000000) != 0 )
            {
              v74 = *(unsigned int *)(v98 + 404);
              v75 = "CCI%d_I2C_M%d_Q%d cci_wait failed for rc: %d";
              v76 = v33;
              v81 = v33;
              v77 = 516;
LABEL_184:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, unsigned int, unsigned int))cam_print_log)(
                3,
                0x4000,
                1,
                "cam_cci_process_full_q",
                v77,
                v75,
                v74,
                (unsigned int)v91,
                a3,
                v81);
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, unsigned int, int))cam_print_log)(
                3,
                0x4000,
                1,
                "cam_cci_data_queue",
                1326,
                "CCI%d_I2C_M%d_Q%d Failed to process full queue rc: %d",
                *(unsigned int *)(v98 + 404),
                (unsigned int)v91,
                a3,
                v76,
                v82);
              goto LABEL_185;
            }
          }
          else
          {
            raw_spin_unlock_irqrestore(v88 + 328, v32);
            if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x4000,
                4,
                "cam_cci_process_full_q",
                522,
                "CCI%d_I2C_M%d_Q%d is set to 0",
                *(_DWORD *)(v98 + 404),
                v91,
                a3);
            cam_cci_load_report_cmd(v98, (unsigned int)v91, a3);
            v50 = *(_QWORD *)(v98 + 672);
            v51 = raw_spin_lock_irqsave(v88 + 328);
            *(_DWORD *)(v87 + 4LL * a3) = 1;
            *(_DWORD *)(v84 + 4LL * a3) = 1;
            raw_spin_unlock_irqrestore(v88 + 328, v51);
            cam_io_w_mb(v83, v50 + 8);
            v52 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))cam_cci_wait)(v98, (unsigned int)v91, a3);
            if ( (v52 & 0x80000000) != 0 )
            {
              v74 = *(unsigned int *)(v98 + 404);
              v75 = "CCI%d_I2C_M%d_Q%d Failed in wait_report for rc: %d";
              v76 = v52;
              v81 = v52;
              v77 = 528;
              goto LABEL_184;
            }
          }
          if ( (debug_mdl & 0x4000) == 0 )
            goto LABEL_23;
          v18 = (_DWORD *)v100;
          if ( !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_process_full_q",
              533,
              "CCI%d_I2C_M%d_Q%d EXIT",
              *(_DWORD *)(v98 + 404),
              v91,
              a3);
            goto LABEL_23;
          }
          goto LABEL_24;
        }
        v11 = *(_QWORD *)(v98 + 672);
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_process_half_q",
            480,
            "CCI%d_I2C_M%d_Q%d ENTER",
            *(_DWORD *)(v98 + 404),
            v91,
            a3);
        v34 = v88;
        v35 = raw_spin_lock_irqsave(v88 + 328);
        if ( !*(_DWORD *)(v87 + 4LL * a3) )
        {
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_process_half_q",
              485,
              "CCI%d_I2C_M%d_Q%d is free",
              *(_DWORD *)(v98 + 404),
              v91,
              a3);
          cam_cci_load_report_cmd(v98, v91, a3);
          *(_DWORD *)(v87 + 4LL * a3) = 1;
          cam_io_w_mb(v83, v11 + 8);
          v34 = v88;
        }
        LODWORD(v13) = raw_spin_unlock_irqrestore(v34 + 328, v35);
      }
      v36 = v100;
      if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
      {
        LODWORD(v13) = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         debug_mdl & 0x4000,
                         4,
                         "cam_cci_data_queue",
                         1335,
                         "CCI%d_I2C_M%d_Q%d cmd_size %d addr 0x%x data 0x%x",
                         *(_DWORD *)(v98 + 404),
                         v91,
                         a3,
                         (unsigned __int16)v7,
                         *v5,
                         v5[1]);
        v36 = v100;
      }
      v37 = *(_DWORD *)(v36 + 16);
      v38 = v5[2];
      LOBYTE(v103) = 9;
      if ( v37 <= 0xC && ((1 << v37) & 0x1A40) != 0 )
        v101 = *v5;
      v95 = v38;
      if ( !v97 )
      {
        v39 = *(_DWORD *)(v36 + 36);
        if ( v39 )
        {
          v40 = 0;
          v41 = 0;
          LODWORD(v8) = 1;
          while ( 1 )
          {
            v42 = v39 - v40;
            if ( v39 - v40 > 0xB )
              goto LABEL_188;
            v43 = 8 * v40;
            ++v41;
            v8 = (unsigned int)(v8 + 1);
            v40 = (unsigned __int16)v41;
            *((_BYTE *)&v103 + v42) = (unsigned __int16)v101 >> v43;
            if ( v39 <= (unsigned __int16)v41 )
              goto LABEL_86;
          }
        }
      }
      v8 = 1;
LABEL_86:
      v44 = v37 - 7;
      v9 = v96;
      v12 = *(_DWORD *)(v100 + 40);
      if ( v44 )
        v45 = 0;
      else
        v45 = *(_DWORD *)(v100 + 40);
      while ( 1 )
      {
        if ( v12 == 1 )
        {
          if ( (unsigned __int16)v8 > 0xBu )
            goto LABEL_188;
          v46 = v8;
          v8 = (unsigned int)(v8 + 1);
          *((_BYTE *)&v103 + v46) = v5[1];
          v101 += v44 == 0;
          goto LABEL_109;
        }
        if ( *(unsigned __int8 *)(v98 + 5792) < (unsigned int)(unsigned __int16)v8 )
          goto LABEL_109;
        if ( v9 >= 4 )
          break;
        if ( v9 == 3 )
        {
          if ( (unsigned __int16)v8 > 0xBu )
            goto LABEL_188;
          v47 = v8 + 1;
LABEL_102:
          if ( (unsigned __int16)v8 > 0xBu )
            goto LABEL_186;
          *((_BYTE *)&v103 + (unsigned __int16)v8) = *((_WORD *)v5 + 3);
          if ( (unsigned __int16)v47 == 12 )
          {
            v9 = 2;
            goto LABEL_132;
          }
          goto LABEL_104;
        }
        if ( v9 >= 2 )
        {
          v47 = v8;
          if ( (unsigned __int16)v8 > 0xBu )
            goto LABEL_188;
LABEL_104:
          if ( (unsigned __int16)v47 > 0xBu )
            goto LABEL_186;
          v8 = (unsigned int)(v47 + 1);
          *((_BYTE *)&v103 + (unsigned __int16)v47) = BYTE1(v5[1]);
          if ( (unsigned __int16)(v47 + 1) == 12 )
          {
            v9 = 1;
            goto LABEL_132;
          }
          v48 = v47 + 2;
          goto LABEL_107;
        }
        if ( (unsigned __int16)v8 > 0xBu )
          goto LABEL_188;
        v48 = v8 + 1;
LABEL_107:
        if ( (unsigned __int16)v8 > 0xBu )
        {
LABEL_186:
          __break(1u);
LABEL_187:
          v80 = v13;
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v12 & 0x4000,
            4,
            "cam_cci_data_queue",
            1273,
            "CCI%d_I2C_M%d_Q%d_LOAD_DATA_ADDR:val 0x%x:0x%x",
            *(_DWORD *)(v98 + 404),
            v91,
            a3,
            v90 + 784,
            v13);
          v13 = v80;
          goto LABEL_17;
        }
        v9 = (unsigned __int8)v12;
        *((_BYTE *)&v103 + (unsigned __int16)v8) = v5[1];
        v8 = v48;
        v101 += v45;
LABEL_109:
        v5 += 4 * (v12 == v9);
        v7 -= v12 == v9;
        if ( v44 < 2 )
        {
          if ( !(_WORD)v7 )
          {
            v7 = 0;
            goto LABEL_133;
          }
        }
        else
        {
          v49 = v24-- != 0;
          if ( !v49 || !(_WORD)v7 )
            goto LABEL_133;
        }
        if ( *(unsigned __int8 *)(v98 + 5792) < (unsigned int)(unsigned __int16)v8 )
          goto LABEL_133;
      }
      if ( (unsigned __int16)v8 > 0xBu )
        goto LABEL_188;
      *((_BYTE *)&v103 + (unsigned __int16)v8) = *((_BYTE *)v5 + 7);
      if ( (unsigned __int16)(v8 + 1) == 12 )
      {
        v9 = 3;
LABEL_132:
        v8 = 12;
LABEL_133:
        v53 = cam_io_r_mb(*(_QWORD *)(v98 + 672) + v90 + 772);
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        {
          v71 = v53;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_get_queue_free_size",
            465,
            "CCI%d_I2C_M%d_Q%d_CUR_WORD_CNT_ADDR %d max %d",
            *(_DWORD *)(v98 + 404),
            v91,
            a3,
            v53,
            *v89);
          v53 = v71;
        }
        v54 = *v89 - v53;
        if ( (unsigned int)(*(_DWORD *)(v100 + 16) - 7) <= 1 && (unsigned __int16)v8 == 12 )
        {
          v55 = v103;
          if ( *(_BYTE *)(v98 + 5273) && (_WORD)v7 && v54 >= 9 )
          {
            v56 = v103 | 0xF0;
            v57 = 1;
            v94 = 0;
            goto LABEL_144;
          }
        }
        else
        {
          v55 = v103;
        }
        v57 = 0;
        v56 = v55 | (16 * v8 - 16);
        v94 = 1;
LABEL_144:
        v10 = v8 - 1;
        LOBYTE(v103) = v56;
        v58 = (unsigned __int16)(v8 - 1) >> 2;
        v96 = v9;
        v97 = v57;
        v86 = v58 + 1;
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_data_queue",
            1434,
            "free_size %d, en_seq_write %d i: %d len: %d ",
            v54,
            v57,
            (unsigned __int16)v8,
            v86);
        LODWORD(v13) = cam_io_r_mb(v99 + 772);
        v59 = v13;
        LOWORD(v9) = 0;
        v60 = 0;
        v11 = (unsigned __int16)v8;
        do
        {
          if ( v60 >= (unsigned int)(unsigned __int16)v8 )
          {
            v65 = 0;
          }
          else
          {
            v62 = 12 - v60;
            v63 = (unsigned __int16)(v10 - v60);
            if ( v60 > 0xCu )
              v62 = 0;
            if ( v63 >= v62 )
              v63 = v62;
            if ( v63 >= 3 )
              v63 = 3;
            if ( v62 == v63 )
              goto LABEL_188;
            LOWORD(v12) = v60;
            if ( v60 > 0xBu )
              goto LABEL_186;
            LOWORD(v12) = v60;
            v64 = v60 + 1LL;
            v65 = *((unsigned __int8 *)&v103 + v60);
            if ( v64 < (unsigned __int16)v8 )
            {
              if ( v60 == 11 )
                goto LABEL_186;
              v66 = *((unsigned __int8 *)&v103 + v64);
              v64 = v60 + 2LL;
              v65 |= v66 << 8;
              if ( v64 < (unsigned __int16)v8 )
              {
                if ( v60 > 9u )
                  goto LABEL_186;
                v67 = *((unsigned __int8 *)&v103 + v64);
                v64 = v60 + 3LL;
                v65 |= v67 << 16;
                if ( v64 < (unsigned __int16)v8 )
                {
                  if ( v60 == 9 )
                    goto LABEL_186;
                  v65 |= *((unsigned __int8 *)&v103 + v64) << 24;
                  LOWORD(v64) = v60 + 4;
                }
              }
            }
            v60 = v64;
          }
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_data_queue",
              1443,
              "CCI%d_I2C_M%d_Q%d LOAD_DATA_ADDR 0x%x, len:%d, cnt: %d",
              *(_DWORD *)(v98 + 404),
              v91,
              a3,
              v65,
              v86,
              v59);
          LODWORD(v13) = cam_io_w_mb(v65, v102);
          v61 = v58 > (unsigned __int16)v9;
          LOWORD(v9) = v9 + 1;
          ++v59;
        }
        while ( v61 );
        cam_io_w_mb(v59, v99 + 768);
        v68 = v94 ^ 1;
        if ( v95 - 1 > 0xF423E )
          v68 = 1;
        if ( (v68 & 1) != 0 )
        {
          v21 = v98;
        }
        else
        {
          v21 = v98;
          v69 = ((*(_DWORD *)(v98 + 5784) * v95) >> 4) & 0xFFFFFF0 | 2;
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          {
            v72 = ((*(_DWORD *)(v98 + 5784) * v95) >> 4) & 0xFFFFFF0 | 2;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_data_queue",
              1463,
              "CCI%d_I2C_M%d_Q%d_LOAD_DATA_ADDR 0x%x",
              *(_DWORD *)(v98 + 404),
              v91,
              a3,
              v69);
            v69 = v72;
          }
          cam_io_w_mb(v69, v102);
          cam_io_w_mb(v59 + 1, v99 + 768);
        }
LABEL_23:
        v18 = (_DWORD *)v100;
LABEL_24:
        if ( !(_WORD)v7 )
        {
          result = cam_cci_transfer_end(v21, (unsigned int)v91, a3);
          if ( (result & 0x80000000) == 0 )
            goto LABEL_182;
          v76 = result;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, int, _DWORD))cam_print_log)(
            3,
            0x4000,
            1,
            "cam_cci_data_queue",
            1476,
            "CCI%d_I2C_M%d_Q%d Slave: 0x%x failed rc %d",
            *(unsigned int *)(v21 + 404),
            (unsigned int)v91,
            a3,
            2 * *(unsigned __int16 *)(*(_QWORD *)(v100 + 8) + 20LL),
            result);
LABEL_185:
          result = v76;
          goto LABEL_182;
        }
        continue;
      }
      v47 = v8 + 2;
      v8 = (unsigned int)(v8 + 1);
      goto LABEL_102;
    }
    break;
  }
  v22 = v18[9];
  v23 = v22 - 1;
  if ( (unsigned int)(v18[4] - 7) > 1 )
  {
    if ( v23 >= 4 )
    {
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_convert_type_to_num_bytes",
        33);
      v18 = (_DWORD *)v100;
      v22 = 0;
    }
    v26 = v18[10];
    if ( (unsigned int)(v26 - 1) >= 4 )
    {
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_convert_type_to_num_bytes",
        33);
      v26 = 0;
    }
    v25 = v26 + v22;
    v27 = *(unsigned __int8 *)(v98 + 5792);
    v28 = v27 - (v26 + v22);
    if ( v27 - (v26 + v22) >= (unsigned __int16)v7 )
      v28 = v7;
    if ( v28 )
    {
      v29 = 0;
      v24 = 0;
      LOBYTE(v30) = 0;
      while ( 1 )
      {
        if ( v5[v29 + 2] || (unsigned int)(unsigned __int16)v7 - 1 <= (v29 * 4) >> 4 || v5[v29] + 1 != v5[v29 + 4] )
        {
LABEL_46:
          if ( v25 <= v27 )
            goto LABEL_50;
          goto LABEL_47;
        }
        if ( 2 * v26 + v22 > v27 )
          break;
        v25 += v26;
        ++v24;
        v30 = (unsigned __int8)(v30 + v26);
        v29 += 4;
        v22 += v26;
        if ( v30 >= v28 )
          goto LABEL_46;
      }
      v25 = v26 + v22;
      if ( v26 + v22 <= v27 )
        goto LABEL_50;
    }
    else
    {
      v24 = 0;
      if ( v25 <= v27 )
        goto LABEL_50;
    }
LABEL_47:
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_calc_cmd_len",
      591);
    goto LABEL_48;
  }
  if ( v23 >= 4 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_convert_type_to_num_bytes",
      33);
    v22 = 0;
  }
  v24 = 0;
  if ( v22 + (unsigned int)(unsigned __int16)v7 >= *(unsigned __int8 *)(v98 + 5792) )
    v25 = *(unsigned __int8 *)(v98 + 5792);
  else
    v25 = v22 + (unsigned __int16)v7;
LABEL_50:
  v11 = (unsigned __int16)(((v25 + 1) >> 2) + 1);
  if ( (unsigned __int16)((v25 + 1) >> 2) != 0xFFFF )
    goto LABEL_51;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int, _DWORD))cam_print_log)(
    3,
    0x4000,
    1,
    "cam_cci_data_queue",
    1310,
    "CCI%d_I2C_M%d_Q%d Calculate command len failed, len: %d",
    *(unsigned int *)(v98 + 404),
    v91,
    a3,
    0);
LABEL_181:
  result = 4294967274LL;
LABEL_182:
  _ReadStatusReg(SP_EL0);
  return result;
}
