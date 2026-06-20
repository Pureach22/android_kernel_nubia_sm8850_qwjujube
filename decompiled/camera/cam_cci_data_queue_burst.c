__int64 __fastcall cam_cci_data_queue_burst(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x21
  int *v5; // x22
  __int64 v6; // x28
  __int64 v7; // x27
  const char *v8; // x23
  __int64 v9; // x19
  int v10; // w26
  unsigned int v11; // w8
  __int64 v12; // x6
  const char *v13; // x5
  __int64 v14; // x4
  unsigned int v16; // w8
  __int64 v17; // x8
  __int64 v18; // x25
  int v19; // w21
  __int64 v20; // x20
  int v21; // w6
  __int64 v22; // x26
  unsigned int v23; // w8
  __int16 v24; // w8
  __int64 v25; // x0
  __int64 v26; // x25
  __int64 v27; // x20
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x28
  int v31; // w26
  unsigned int v32; // w20
  unsigned int v33; // w12
  __int64 v34; // x27
  bool v35; // cf
  int v36; // w20
  unsigned int v37; // w24
  __int64 v38; // x4
  unsigned int v39; // w9
  unsigned __int64 v40; // x2
  _BYTE *v41; // x16
  _DWORD *v42; // x0
  int v43; // w25
  _DWORD *v44; // x8
  unsigned int v45; // w17
  unsigned int v46; // w21
  unsigned int v47; // w1
  char v48; // w9
  const char *v49; // x3
  char *v50; // x19
  int v51; // w11
  unsigned int v52; // w11
  int v53; // w12
  int v54; // w9
  int v55; // w20
  char v56; // w13
  int v57; // w11
  int v58; // w9
  __int64 v59; // x12
  __int64 v60; // x11
  __int64 v61; // x12
  char v62; // w9
  int v63; // w10
  unsigned int v64; // w5
  unsigned int v65; // w26
  __int64 v66; // x21
  int v67; // w22
  _DWORD *v68; // x8
  __int64 v69; // x25
  int v70; // w8
  __int16 v71; // w21
  int v72; // w25
  int v73; // w0
  int v74; // w6
  unsigned int v75; // w0
  unsigned int v76; // w20
  _QWORD *v77; // x0
  __int64 v78; // x20
  int v79; // w25
  __int64 v80; // x20
  int v81; // w25
  unsigned int v82; // w20
  unsigned __int64 v83; // x21
  int v84; // [xsp+8h] [xbp-98h]
  __int64 v85; // [xsp+28h] [xbp-78h]
  unsigned int v86; // [xsp+3Ch] [xbp-64h]
  unsigned int v87; // [xsp+40h] [xbp-60h]
  int v88; // [xsp+44h] [xbp-5Ch]
  unsigned __int8 v89; // [xsp+48h] [xbp-58h]
  unsigned __int64 v90; // [xsp+48h] [xbp-58h]
  unsigned __int64 v91; // [xsp+48h] [xbp-58h]
  unsigned int v92; // [xsp+54h] [xbp-4Ch]
  _BYTE *v93; // [xsp+58h] [xbp-48h]
  __int64 v94; // [xsp+60h] [xbp-40h]
  __int64 v95; // [xsp+68h] [xbp-38h]
  __int64 v96; // [xsp+70h] [xbp-30h]
  unsigned int v97; // [xsp+7Ch] [xbp-24h]
  __int64 v98; // [xsp+80h] [xbp-20h]
  __int64 v99; // [xsp+88h] [xbp-18h]
  __int64 v100; // [xsp+90h] [xbp-10h]
  __int64 v101; // [xsp+98h] [xbp-8h]

  v5 = *(int **)(a2 + 24);
  v6 = a3;
  v7 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 16LL);
  if ( !v5 )
  {
    v12 = *(unsigned int *)(a1 + 404);
    v13 = "CCI%d_I2C_M%d_Q%d Failed: i2c cmd is NULL";
    v14 = 898;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, unsigned int, int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_data_queue_burst",
      v14,
      v13,
      v12,
      (unsigned int)v7,
      a3,
      v84);
    return 4294967274LL;
  }
  LODWORD(v8) = *(_DWORD *)(a2 + 32);
  if ( !(_WORD)v8 || (unsigned __int16)v8 > 0x5000u )
  {
    v12 = *(unsigned int *)(a1 + 404);
    v13 = "CCI%d_I2C_M%d_Q%d failed: invalid cmd_size %d";
    v84 = (unsigned __int16)*(_DWORD *)(a2 + 32);
    v14 = 904;
    goto LABEL_11;
  }
  v9 = *(_QWORD *)(a1 + 672);
  v10 = *(_DWORD *)(a2 + 40);
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    v78 = a2;
    v4 = a1;
    v79 = a4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_data_queue_burst",
      909,
      "CCI%d_I2C_M%d_Q%d addr type %d data type %d cmd_size %d",
      *(_DWORD *)(a1 + 404),
      v7,
      a3,
      *(_DWORD *)(a2 + 36),
      v10,
      (unsigned __int16)v8);
    a4 = v79;
    a2 = v78;
    a1 = v4;
  }
  v11 = *(_DWORD *)(a2 + 36);
  if ( v11 >= 5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, unsigned int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_data_queue_burst",
      913,
      "CCI%d_I2C_M%d_Q%d failed: invalid addr_type 0x%X",
      *(unsigned int *)(a1 + 404),
      (unsigned int)v7,
      v6,
      v11);
    return 4294967274LL;
  }
  v16 = *(_DWORD *)(a2 + 40);
  if ( v16 >= 5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, unsigned int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_data_queue_burst",
      918,
      "CCI%d_I2C_M%d_Q%d failed: invalid data_type 0x%X",
      *(unsigned int *)(a1 + 404),
      (unsigned int)v7,
      v6,
      v16);
    return 4294967274LL;
  }
  v17 = *(_QWORD *)(a2 + 8);
  v89 = v10;
  v94 = v9;
  if ( (debug_mdl & 0x4000) != 0 && (LOWORD(v17) = debug_priority, !debug_priority) )
  {
    v80 = a2;
    v4 = a1;
    v81 = a4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_data_queue_burst",
      926,
      "CCI%d_I2C_M%d_Q%d : START for sid: 0x%x size: %d",
      *(_DWORD *)(a1 + 404),
      v7,
      v6,
      *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 20LL),
      *(_DWORD *)(a2 + 32));
    a4 = v81;
    a2 = v80;
    a1 = v4;
    if ( (unsigned int)v7 > 1 )
      goto LABEL_113;
  }
  else if ( (unsigned int)v7 > 1 )
  {
    goto LABEL_113;
  }
  if ( (unsigned int)v6 <= 1 )
  {
    v18 = a1;
    v99 = v7;
    v100 = (unsigned int)v6;
    v88 = a4;
    v95 = a1 + 544LL * (unsigned int)v7 + 4040;
    *(_BYTE *)(v95 + (unsigned int)v6 + 488) = 0;
    *(_DWORD *)(v95 + 4LL * (unsigned int)v6 + 492) = 0;
    v19 = *(_DWORD *)(a2 + 36);
    if ( (unsigned int)(v19 - 1) >= 4 )
    {
      v20 = a2;
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_convert_type_to_num_bytes",
        33);
      a2 = v20;
      v19 = 0;
    }
    v21 = *(_DWORD *)(a2 + 40);
    v22 = a2;
    if ( (unsigned int)(v21 - 1) >= 4 )
    {
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_convert_type_to_num_bytes",
        33);
      v21 = 0;
    }
    v23 = v19 + v21 * (_DWORD)v8 + (unsigned __int16)(v19 + v21 * (_WORD)v8) / 0xBu;
    v92 = (unsigned __int16)(v19 + v21 * (_WORD)v8) / 0xBu;
    if ( (unsigned __int16)(v19 + v21 * (_WORD)v8) % 0xBu )
      LOWORD(v23) = v23 + 1;
    if ( (v23 & 3) != 0 )
      v24 = ((unsigned __int16)v23 >> 2) + 1;
    else
      v24 = (unsigned __int16)v23 >> 2;
    LOWORD(v4) = v24 + 8;
    if ( mem_trace_en == 1 )
    {
      v25 = cam_mem_trace_alloc(4LL * (unsigned __int16)(v24 + 8), 0xCC0u, 0, "cam_cci_data_queue_burst", 0x3B9u);
      if ( v25 )
      {
LABEL_30:
        v97 = v6;
        v93 = (_BYTE *)v25;
        v98 = v18;
        v6 = (unsigned int)(((_DWORD)v7 << 9) | ((_DWORD)v6 << 8));
        cam_io_w_mb(*(unsigned __int16 *)(v18 + 5296), v9 + 4LL * *(__int16 *)(v18 + 5298) + 16);
        v96 = v22;
        *(_WORD *)(*(_QWORD *)(v22 + 8) + 28LL) = 0;
        LOWORD(v17) = debug_mdl;
        a1 = (16 * *(unsigned __int16 *)(*(_QWORD *)(v22 + 8) + 20LL))
           | (*(unsigned __int16 *)(*(_QWORD *)(v22 + 8) + 28LL) << 16)
           | (*(unsigned __int16 *)(*(_QWORD *)(v22 + 8) + 30LL) << 18)
           | 1u;
        if ( (debug_mdl & 0x4000) == 0 || debug_priority )
          goto LABEL_32;
        goto LABEL_114;
      }
    }
    else
    {
      v25 = _kvmalloc_node_noprof(4LL * (unsigned __int16)(v24 + 8), 0, 3520, 0xFFFFFFFFLL);
      if ( v25 )
        goto LABEL_30;
    }
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_data_queue_burst",
      955);
    return 4294967284LL;
  }
LABEL_113:
  __break(0x5512u);
LABEL_114:
  v82 = a1;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    v17 & 0x4000,
    4,
    "cam_cci_data_queue_burst",
    980,
    "CCI%d_I2C_M%d_Q%d_LOAD_DATA_ADDR:val 0x%x:0x%x",
    *(_DWORD *)(v98 + 404),
    v99,
    v97,
    v6 + 784,
    a1);
  a1 = v82;
LABEL_32:
  v26 = v9 + v6;
  v85 = v6;
  cam_io_w_mb(a1, v9 + v6 + 784);
  v27 = v95 + 4 * v100;
  v28 = raw_spin_lock_irqsave(v27 + 328);
  *(_DWORD *)(v27 + 4) = 0;
  v101 = v95 + 32 * v100;
  *(_DWORD *)(v101 + 416) = 0;
  raw_spin_unlock_irqrestore(v27 + 328, v28);
  v29 = v98;
  v30 = v95 + 480;
  *(_DWORD *)(v95 + 480 + 4 * v100) = 0;
  v31 = *v5;
  v32 = *(_DWORD *)(v98 + 32 * v99 + 16 * v100 + 3972);
  v33 = v32 >> ((unsigned int)(*(_DWORD *)(v96 + 16) - 9) < 0xFFFFFFFE);
  v86 = (unsigned __int16)v4;
  v87 = v33;
  if ( v33 > (unsigned __int16)v4 && (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_data_queue_burst",
      1012,
      "CCI%d_I2C_M%d_Q%d: len: %d < QueueSize: %d No need of threshold IRQ",
      *(_DWORD *)(v98 + 404),
      v99,
      v97,
      (unsigned __int16)v4,
      v33);
    v29 = v98;
  }
  v34 = v29 + 4096;
  if ( v88 == 1 )
  {
    v35 = (unsigned __int16)v8 >= v32;
    v36 = -2;
    if ( !v35 && *(_BYTE *)(v29 + 5304) )
    {
      cam_io_w_mb((16 * *(unsigned __int16 *)(v29 + 5300)) | 3u, v26 + 784);
      v29 = v98;
      v36 = -3;
    }
  }
  else
  {
    v36 = -2;
  }
  v37 = v89;
  cam_cci_lock_queue(v29, v99, v97, 1);
  v38 = v87;
  v39 = v87 + v36 - 1;
  v40 = v39 / 6uLL;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    v83 = v39 / 6uLL;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_data_queue_burst",
      1039,
      "CCI%d_I2C_M%d_Q%d queue_size: %d full_queue_mark: %d half_queue_mark: %d",
      *(_DWORD *)(v98 + 404),
      v99,
      v97,
      v87,
      v39 / 3,
      v40);
    v38 = v87;
    v40 = v83;
  }
  v41 = v93;
  v42 = (_DWORD *)v98;
  v43 = 0;
  v44 = (_DWORD *)v96;
  v45 = v92;
  v46 = 0;
  v47 = v86;
  v48 = 1;
  v49 = "cam_cci_data_queue_burst";
  v50 = v93;
  do
  {
    *v50 = 9;
    if ( (v48 & 1) != 0 && (v52 = v44[9]) != 0 )
    {
      v53 = 0;
      v54 = 0;
      v55 = 1;
      do
      {
        v56 = 8 * v53;
        v57 = v52 - v53;
        v53 = (unsigned __int16)++v54;
        ++v55;
        v50[v57] = (unsigned __int16)v31 >> v56;
        v52 = v44[9];
      }
      while ( v52 > (unsigned __int16)v54 );
    }
    else
    {
      v55 = 1;
    }
    v58 = v44[10];
    while ( 1 )
    {
      if ( v58 == 1 )
      {
        v50[(unsigned __int16)v55++] = v5[1];
        v58 = v44[10];
        if ( (unsigned int)(v44[4] - 7) < 2 )
          ++v31;
        goto LABEL_72;
      }
      if ( *(unsigned __int8 *)(v34 + 1696) < (unsigned int)(unsigned __int16)v55 )
        goto LABEL_72;
      if ( v37 >= 4 )
        break;
      if ( v37 == 3 )
        goto LABEL_68;
      if ( v37 >= 2 )
        goto LABEL_69;
LABEL_70:
      v50[(unsigned __int16)v55++] = v5[1];
      v58 = v44[10];
      v37 = (unsigned __int8)v58;
      if ( (unsigned int)(v44[4] - 7) <= 1 )
        v31 += v58;
LABEL_72:
      LOWORD(v8) = (_WORD)v8 - (v58 == v37);
      v5 += 4 * (v58 == v37);
      if ( !(_WORD)v8 )
      {
        v62 = *v50;
        ++v46;
        goto LABEL_87;
      }
      if ( *(unsigned __int8 *)(v34 + 1696) < (unsigned int)(unsigned __int16)v55 )
        goto LABEL_80;
    }
    v59 = (unsigned __int16)v55++;
    v50[v59] = *((_BYTE *)v5 + 7);
    if ( (unsigned __int16)v55 == 12 )
    {
      LOWORD(v55) = 12;
      v37 = 3;
      goto LABEL_80;
    }
LABEL_68:
    v60 = (unsigned __int16)v55++;
    v50[v60] = *((_WORD *)v5 + 3);
    if ( (unsigned __int16)v55 != 12 )
    {
LABEL_69:
      v61 = (unsigned __int16)v55++;
      v50[v61] = BYTE1(v5[1]);
      if ( (unsigned __int16)v55 == 12 )
      {
        LOWORD(v55) = 12;
        v37 = 1;
        goto LABEL_80;
      }
      goto LABEL_70;
    }
    LOWORD(v55) = 12;
    v37 = 2;
LABEL_80:
    v62 = *v50;
    ++v46;
    if ( (unsigned int)v38 > v47 )
    {
      if ( !(_WORD)v8 )
        goto LABEL_87;
      goto LABEL_48;
    }
    if ( (_WORD)v8 )
    {
      if ( v46 == v45 || !(v46 % (unsigned int)v40) )
      {
        *v50 = v62 | 0xE0;
        v63 = *(_DWORD *)(v30 + 4 * v100) + 1;
        *(_DWORD *)(v30 + 4 * v100) = v63;
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        {
          v90 = v40;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_data_queue_burst",
            1131,
            "CCI%d_I2C_M%d_Q%d Th IRQ enabled for index: %d num_payld: %d th_irq_ref_cnt: %d",
            v42[101],
            v99,
            v97,
            v43,
            v46,
            v63);
          v47 = v86;
          v38 = v87;
          v40 = v90;
          v45 = v92;
          v41 = v93;
          v44 = (_DWORD *)v96;
          v42 = (_DWORD *)v98;
          v49 = "cam_cci_data_queue_burst";
        }
        goto LABEL_49;
      }
LABEL_48:
      *v50 = v62 | 0xF0;
      goto LABEL_49;
    }
LABEL_87:
    LOWORD(v8) = 0;
    *v50 = v62 | (16 * v55 - 16);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v91 = v40;
      v8 = v49;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        v49,
        1137,
        "End of register Write............ ",
        9,
        "CCI%d_I2C_M%d_Q%d Th IRQ enabled for index: %d num_payld: %d th_irq_ref_cnt: %d");
      v47 = v86;
      v38 = v87;
      v40 = v91;
      v45 = v92;
      v41 = v93;
      v44 = (_DWORD *)v96;
      v42 = (_DWORD *)v98;
      v49 = v8;
      LOWORD(v8) = 0;
    }
LABEL_49:
    v48 = 0;
    v51 = (unsigned __int16)v55 - 1;
    if ( !(_WORD)v55 )
      v51 = (unsigned __int16)v55 + 2;
    v50 += ((unsigned __int16)v55 + 3) & 0x1FFFC;
    v43 += (v51 >> 2) + 1;
  }
  while ( (_WORD)v8 );
  v64 = *(_DWORD *)(v30 + 4 * v100);
  if ( (debug_mdl & 0x4000) != 0 )
  {
    v65 = v99;
    v66 = 4 * v100;
    if ( !debug_priority )
    {
      v67 = v40;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_data_queue_burst",
        1148,
        "CCI%d_I2C_M%d_Q%d num words to Queue: %d th_irq_ref_cnt: %d cci_dev: %p",
        v42[101],
        v99,
        v97,
        v43,
        v64,
        v42);
      v41 = v93;
      LODWORD(v40) = v67;
      v42 = (_DWORD *)v98;
      v64 = *(_DWORD *)(v30 + 4 * v100);
    }
  }
  else
  {
    v65 = v99;
    v66 = 4 * v100;
  }
  v68 = (_DWORD *)(v95 + v66);
  *(_QWORD *)(v95 + 504 + 8 * v100) = v41;
  v68[130] = v43;
  v69 = v100;
  v68[132] = 0;
  v68[134] = 3 * v40;
  cam_cci_data_queue_burst_apply((__int64)v42, v65, v97, 0, v38, v64);
  if ( *(_DWORD *)(v30 + v66) )
  {
    while ( cam_common_wait_for_completion_timeout(v101 + 416) )
    {
      v70 = *(_DWORD *)(v30 + 4 * v69) - 1;
      *(_DWORD *)(v30 + 4 * v69) = v70;
      v71 = debug_mdl;
      if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
      {
        v72 = *(_DWORD *)(v98 + 404);
        v73 = cam_io_r_mb(v94 + v85 + 772);
        v74 = v72;
        v69 = v100;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v71 & 0x4000,
          4,
          "cam_cci_data_queue_burst",
          1185,
          "CCI%d_I2C_M%d_Q%d Threshold IRQ Raised, BufferLevel: %d",
          v74,
          v65,
          v97,
          v73);
        v70 = *(_DWORD *)(v30 + 4 * v100);
      }
      if ( !v70 )
        goto LABEL_101;
    }
    cam_cci_dump_registers(v98, v65, v97);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_data_queue_burst",
      1172);
    cam_cci_flush_queue(v98, v65);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_data_queue_burst",
      1177);
    cam_cci_dump_registers(v98, v65, v97);
    v76 = -110;
LABEL_107:
    v77 = v93;
  }
  else
  {
LABEL_101:
    v75 = cam_cci_transfer_end(v98, v65, v97);
    if ( (v75 & 0x80000000) != 0 )
    {
      v76 = v75;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, int, unsigned int))cam_print_log)(
        3,
        0x4000,
        1,
        "cam_cci_data_queue_burst",
        1196,
        "CCI%d_I2C_M%d_Q%d Slave: 0x%x failed rc %d",
        *(unsigned int *)(v98 + 404),
        v65,
        v97,
        2 * *(unsigned __int16 *)(*(_QWORD *)(v96 + 8) + 20LL),
        v75);
      goto LABEL_107;
    }
    v76 = v75;
    trace_cam_cci_burst();
    if ( (debug_mdl & 0x4000) == 0 )
      goto LABEL_107;
    v77 = v93;
    if ( !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, _DWORD, _DWORD))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_data_queue_burst",
        1203,
        "CCI%d_I2C_M%d_Q%d : completed ....for sid: 0x%x size: %d",
        *(unsigned int *)(v98 + 404),
        v65,
        v97,
        *(unsigned __int16 *)(*(_QWORD *)(v96 + 8) + 20LL),
        *(_DWORD *)(v96 + 32));
      goto LABEL_107;
    }
  }
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v77, 0);
  else
    kvfree(v77);
  *(_QWORD *)(v95 + 504 + 8 * v69) = 0;
  return v76;
}
