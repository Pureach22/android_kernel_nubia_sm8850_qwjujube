__int64 __fastcall cam_cci_burst_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v6; // x25
  unsigned int v8; // w0
  __int64 v9; // x22
  _DWORD *v10; // x23
  __int64 v11; // x26
  int v12; // w8
  unsigned int v13; // w0
  unsigned int v14; // w19
  unsigned int v16; // w0
  unsigned int v17; // w9
  unsigned int v18; // w0
  int v19; // w9
  unsigned int v20; // w1
  unsigned int v21; // w8
  int v22; // w10
  int v23; // w11
  __int64 v24; // x6
  const char *v25; // x5
  __int64 v26; // x1
  __int64 v27; // x4
  int v28; // w12
  int v29; // w13
  int v30; // w14
  int v31; // w15
  unsigned int v32; // w17
  unsigned int v33; // w16
  int v34; // w17
  int v35; // w16
  int v36; // w12
  int v37; // w9
  int v38; // w10
  unsigned int v39; // w11
  int v40; // w11
  unsigned int v41; // w0
  unsigned int v42; // w0
  __int64 v43; // x19
  __int64 v44; // x0
  int v45; // w10
  int v46; // w19
  int v47; // w23
  int v48; // w27
  __int64 v49; // x22
  int v50; // w8
  int v51; // w0
  __int16 v52; // w8
  int v53; // w9
  int v54; // w27
  int v55; // w0
  int v56; // w24
  __int64 v57; // x28
  int v58; // w24
  int v59; // w24
  __int64 v60; // x24
  unsigned int v61; // w0
  unsigned int v62; // w22
  unsigned int v63; // [xsp+8h] [xbp-58h]
  int v64; // [xsp+10h] [xbp-50h]
  int v65; // [xsp+30h] [xbp-30h]
  int v66; // [xsp+34h] [xbp-2Ch]
  _DWORD *v67; // [xsp+38h] [xbp-28h]
  unsigned int v68; // [xsp+54h] [xbp-Ch]
  int v69; // [xsp+58h] [xbp-8h]
  int v70; // [xsp+5Ch] [xbp-4h]

  v4 = *(_QWORD *)(a1 + 240);
  if ( !v4 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_burst_read",
      1500);
    return 4294967274LL;
  }
  v6 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 16LL);
  if ( (unsigned int)v6 >= 2 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_burst_read",
      1509);
    return 4294967274LL;
  }
  v8 = cam_cci_set_clk_param(*(_QWORD *)(a1 + 240), a2, a3, a4);
  if ( (v8 & 0x80000000) != 0 )
  {
    v14 = v8;
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_burst_read",
      1517);
    return v14;
  }
  v9 = v4 + 544LL * (unsigned int)v6;
  v10 = (_DWORD *)(v9 + 4040);
  mutex_lock(v9 + 4248);
  *(_BYTE *)(v4 + v6 + 5828) = 1;
  v11 = *(_QWORD *)(v4 + 672);
  v12 = *(_DWORD *)(v4 + 32 * v6 + 3988);
  *(_DWORD *)(v9 + 4328) = 0;
  v13 = cam_cci_validate_queue(v4, v12 - 1, v6, 1u);
  if ( (v13 & 0x80000000) != 0 )
  {
    v68 = v13;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, unsigned int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_burst_read",
      1538,
      "CCI%d_I2C_M%d_Q%d Initial validataion failed rc:%d",
      *(unsigned int *)(v4 + 404),
      (unsigned int)v6,
      1,
      v13);
    goto LABEL_16;
  }
  if ( *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 28LL) >= 4u )
  {
    v68 = v13;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, _DWORD, int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_burst_read",
      1545,
      "CCI%d_I2C_M%d_Q%d Invalid read retries info retries from slave: %d, max retries: %d",
      *(unsigned int *)(v4 + 404),
      (unsigned int)v6,
      1,
      *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 28LL),
      3);
    goto LABEL_16;
  }
  if ( !*(_QWORD *)(a2 + 32) )
  {
    v68 = v13;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_burst_read",
      1551,
      "CCI%d_I2C_M%d_Q%d Data ptr is NULL",
      *(unsigned int *)(v4 + 404),
      (unsigned int)v6,
      1);
    goto LABEL_16;
  }
  if ( *(unsigned __int16 *)(a2 + 28) >= 5u )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_burst_read",
      1557);
    v68 = -22;
    goto LABEL_16;
  }
  v16 = cam_cci_write_i2c_queue(v4, 6u, v6);
  v17 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 14);
  if ( (v16 & 0x80000000) != 0 )
  {
    v68 = v16;
    if ( !v17 )
      goto LABEL_16;
    v24 = *(unsigned int *)(v4 + 404);
    v25 = "CCI%d_I2C_M%d_Q%d failed to write lock_cmd for rc: %d";
    v63 = v16;
    v26 = debug_mdl & 0x4000;
    v27 = 1567;
    goto LABEL_127;
  }
  if ( v17 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_burst_read",
      1574,
      "CCI%d_I2C_M%d_Q%d set param sid 0x%x retries %d id_map %d",
      *(_DWORD *)(v4 + 404),
      v6,
      1,
      *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 20LL),
      *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 28LL),
      *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 30LL));
  v18 = cam_cci_write_i2c_queue(
          v4,
          (16 * *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 20LL))
        | (*(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 28LL) << 16)
        | (*(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 30LL) << 18)
        | 1u,
          v6);
  if ( (v18 & 0x80000000) != 0 )
  {
    v68 = v18;
    if ( (debug_mdl & 0x4000) == 0 || debug_priority )
      goto LABEL_16;
    v24 = *(unsigned int *)(v4 + 404);
    v25 = "CCI%d_I2C_M%d_Q%d Failed to write param_cmd for rc: %d";
    v63 = v18;
    v26 = debug_mdl & 0x4000;
    v27 = 1582;
LABEL_127:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, unsigned int, int))cam_print_log)(
      3,
      v26,
      4,
      "cam_cci_burst_read",
      v27,
      v25,
      v24,
      v6,
      1,
      v63,
      v64);
    goto LABEL_16;
  }
  v19 = *(unsigned __int16 *)(a2 + 28);
  v20 = (16 * v19) | 0xB;
  if ( *(_WORD *)(a2 + 28) )
  {
    v21 = *(_DWORD *)(a2 + 24);
    v22 = 8 * v19;
    if ( v19 == 1 )
    {
      v23 = 0;
LABEL_35:
      v36 = 8 * v23;
      v37 = v19 - v23;
      v38 = v22 - 8 * v23;
      do
      {
        v39 = v21 >> v36;
        --v37;
        v36 += 8;
        v40 = (unsigned __int8)v39 << v38;
        v38 -= 8;
        v20 |= v40;
      }
      while ( v37 );
      goto LABEL_37;
    }
    v23 = v19 & 0xFFFE;
    v28 = 0;
    v29 = 8;
    v30 = v23;
    v31 = 8 * v19;
    do
    {
      v32 = v21 >> v29;
      v33 = v21 >> (v29 - 8);
      v30 -= 2;
      v29 += 16;
      v34 = (unsigned __int8)v32 << (v31 - 8);
      v35 = (unsigned __int8)v33 << v31;
      v31 -= 16;
      v28 |= v34;
      v20 |= v35;
    }
    while ( v30 );
    v20 |= v28;
    if ( v23 != v19 )
      goto LABEL_35;
  }
LABEL_37:
  v41 = cam_cci_write_i2c_queue(v4, v20, v6);
  if ( (v41 & 0x80000000) != 0 )
  {
    v68 = v41;
    if ( (debug_mdl & 0x4000) == 0 || debug_priority )
      goto LABEL_16;
    v24 = *(unsigned int *)(v4 + 404);
    v25 = "CCI%d_I2C_M%d_Q%d Failed to write disable cmd for rc: %d";
    v63 = v41;
    v26 = debug_mdl & 0x4000;
    v27 = 1596;
    goto LABEL_127;
  }
  v42 = cam_cci_write_i2c_queue(v4, (16 * *(unsigned __int16 *)(a2 + 40)) | 0xAu, v6);
  if ( (v42 & 0x80000000) != 0 )
  {
    v68 = v42;
    if ( (debug_mdl & 0x4000) == 0 || debug_priority )
      goto LABEL_16;
    v24 = *(unsigned int *)(v4 + 404);
    v25 = "CCI%d_I2C_M%d_Q%d Failed to write read_cmd for rc: %d";
    v63 = v42;
    v26 = debug_mdl & 0x4000;
    v27 = 1605;
    goto LABEL_127;
  }
  v68 = cam_cci_write_i2c_queue(v4, 7u, v6);
  if ( (v68 & 0x80000000) != 0 )
  {
    if ( (debug_mdl & 0x4000) == 0 || debug_priority )
      goto LABEL_16;
    v24 = *(unsigned int *)(v4 + 404);
    v25 = "CCI%d_I2C_M%d_Q%d failed to write unlock_cmd for rc: %d";
    v63 = v68;
    v26 = debug_mdl & 0x4000;
    v27 = 1614;
    goto LABEL_127;
  }
  v43 = v11 + (v6 << 9);
  v44 = cam_io_r_mb(v43 + 1028);
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    v62 = v44;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_burst_read",
      1621,
      "CCI%d_I2C_M%d_Q%d cur word cnt 0x%x",
      *(_DWORD *)(v4 + 404),
      v6,
      1,
      v44);
    v44 = v62;
  }
  v67 = v10;
  cam_io_w_mb(v44, v43 + 1024);
  cam_io_w_mb((unsigned int)(2 << (2 * v6)), v11 + 8);
  v45 = (*(unsigned __int16 *)(a2 + 40) >> 2) + 1;
  v66 = v45;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_burst_read",
      1630,
      "CCI%d_I2C_M%d_Q%d waiting for threshold [exp_words %d]",
      *(_DWORD *)(v4 + 404),
      v6,
      1,
      v45);
    v45 = v66;
  }
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v70 = 0;
  v49 = v11 + (v6 << 8);
  if ( (v6 & 1) != 0 )
    v50 = 0x100000;
  else
    v50 = 0x10000;
  v65 = v50;
  do
  {
    if ( v48 == v45 )
      goto LABEL_124;
    if ( !cam_common_wait_for_completion_timeout((__int64)(v67 + 32)) )
    {
      cam_io_r_mb(v49 + 284);
      v68 = -110;
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_burst_read",
        1643);
      cam_cci_dump_registers(v4, v6, 1);
      cam_cci_flush_queue(v4, v6);
      v10 = v67;
LABEL_120:
      v9 = v4 + 544LL * (unsigned int)v6;
      goto LABEL_16;
    }
    if ( *v67 )
    {
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_burst_read",
        1653);
      v10 = v67;
      v68 = -22;
      *v67 = 0;
      goto LABEL_120;
    }
    v51 = cam_io_r_mb(v49 + 284);
    v52 = debug_mdl;
    if ( v51 < 1 )
    {
      if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_burst_read",
          1663,
          "CCI%d_I2C_M%d_Q%d FIFO Buffer lvl is 0",
          *(_DWORD *)(v4 + 404),
          v6,
          1);
      goto LABEL_107;
    }
    while ( 2 )
    {
      v53 = debug_priority;
LABEL_56:
      ++v70;
      if ( (v52 & 0x4000) != 0 && !v53 )
      {
        v58 = v51;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v52 & 0x4000,
          4,
          "cam_cci_burst_read",
          1670,
          "CCI%d_I2C_M%d_Q%d Iteration: %u read_words %d",
          *(_DWORD *)(v4 + 404),
          v6,
          1,
          v70,
          v51);
        v51 = v58;
      }
      v69 = v48 + v51;
      v54 = v51 + 1;
      do
      {
        v55 = cam_io_r(v49 + 280);
        if ( v46 >= *(unsigned __int16 *)(a2 + 40) )
          goto LABEL_62;
        v56 = v55;
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_burst_read",
            1679,
            "CCI%d_I2C_M%d_Q%d i:%d index:%d",
            *(_DWORD *)(v4 + 404),
            v6,
            1,
            0,
            v46);
          if ( !v47 )
          {
LABEL_72:
            if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x4000,
                4,
                "cam_cci_burst_read",
                1682,
                "CCI%d_I2C_M%d_Q%d sid 0x%x",
                *(_DWORD *)(v4 + 404),
                v6,
                1,
                (unsigned __int8)v56);
            goto LABEL_75;
          }
        }
        else if ( !v47 )
        {
          goto LABEL_72;
        }
        *(_BYTE *)(*(_QWORD *)(a2 + 32) + v46) = v56;
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_burst_read",
            1689,
            "CCI%d_I2C_M%d_Q%d data[%d] 0x%x",
            *(_DWORD *)(v4 + 404),
            v6,
            1,
            v46,
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 32) + v46));
        ++v46;
LABEL_75:
        if ( v46 >= *(unsigned __int16 *)(a2 + 40) )
          goto LABEL_61;
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_burst_read",
            1679,
            "CCI%d_I2C_M%d_Q%d i:%d index:%d",
            *(_DWORD *)(v4 + 404),
            v6,
            1,
            1,
            v46);
        *(_BYTE *)(*(_QWORD *)(a2 + 32) + v46) = BYTE1(v56);
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_burst_read",
            1689,
            "CCI%d_I2C_M%d_Q%d data[%d] 0x%x",
            *(_DWORD *)(v4 + 404),
            v6,
            1,
            v46,
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 32) + v46));
        v57 = v46 + 1LL;
        if ( v46 + 1 < *(unsigned __int16 *)(a2 + 40) )
        {
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_burst_read",
              1679,
              "CCI%d_I2C_M%d_Q%d i:%d index:%d",
              *(_DWORD *)(v4 + 404),
              v6,
              1,
              2,
              v57);
          *(_BYTE *)(*(_QWORD *)(a2 + 32) + v57) = BYTE2(v56);
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_burst_read",
              1689,
              "CCI%d_I2C_M%d_Q%d data[%d] 0x%x",
              *(_DWORD *)(v4 + 404),
              v6,
              1,
              v46 + 1,
              *(unsigned __int8 *)(*(_QWORD *)(a2 + 32) + v57));
          v57 = v46 + 2LL;
          if ( v46 + 2 < *(unsigned __int16 *)(a2 + 40) )
          {
            if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x4000,
                4,
                "cam_cci_burst_read",
                1679,
                "CCI%d_I2C_M%d_Q%d i:%d index:%d",
                *(_DWORD *)(v4 + 404),
                v6,
                1,
                3,
                v57);
            *(_BYTE *)(*(_QWORD *)(a2 + 32) + v57) = HIBYTE(v56);
            if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x4000,
                4,
                "cam_cci_burst_read",
                1689,
                "CCI%d_I2C_M%d_Q%d data[%d] 0x%x",
                *(_DWORD *)(v4 + 404),
                v6,
                1,
                v46 + 2,
                *(unsigned __int8 *)(*(_QWORD *)(a2 + 32) + v57));
            v46 += 3;
LABEL_61:
            v47 = 1;
            goto LABEL_62;
          }
        }
        v47 = 1;
        v46 = v57;
LABEL_62:
        --v54;
      }
      while ( v54 > 1 );
      v48 = v69;
      if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_burst_read",
          1697,
          "CCI%d_I2C_M%d_Q%d Iteration:%u total_read_words %d",
          *(_DWORD *)(v4 + 404),
          v6,
          1,
          v70,
          v69);
      v51 = cam_io_r_mb(v49 + 284);
      if ( v51 >= 1 )
      {
        v52 = debug_mdl;
        v53 = debug_priority;
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        {
          v59 = v51;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_burst_read",
            1702,
            "FIFO Buffer lvl is %d",
            v51);
          v52 = debug_mdl;
          v51 = v59;
          continue;
        }
        goto LABEL_56;
      }
      break;
    }
LABEL_107:
    v60 = raw_spin_lock_irqsave(v4 + 5824);
    if ( *(_DWORD *)(v4 + 5832) )
    {
      v61 = cam_io_r_mb(v11 + 3088);
      cam_io_w_mb(*(_DWORD *)(v4 + 5832) & v65 | v61, v11 + 3088);
    }
    raw_spin_unlock_irqrestore(v4 + 5824, v60);
    v45 = v66;
  }
  while ( v48 != v66 );
  v10 = v67;
  if ( cam_common_wait_for_completion_timeout((__int64)(v67 + 24)) )
  {
    v45 = v66;
    if ( *v67 )
    {
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_burst_read",
        1754);
      v10 = v67;
      v9 = v4 + 544LL * (unsigned int)v6;
      v68 = -22;
      *v67 = 0;
      goto LABEL_16;
    }
LABEL_124:
    if ( (debug_mdl & 0x4000) != 0 )
    {
      v10 = v67;
      v9 = v4 + 544LL * (unsigned int)v6;
      if ( !debug_priority )
      {
        v24 = *(unsigned int *)(v4 + 404);
        v25 = "CCI%d_I2C_M%d_Q%d Burst read successful words_read %d";
        v26 = debug_mdl & 0x4000;
        v27 = 1764;
        v63 = v45;
        goto LABEL_127;
      }
    }
    else
    {
      v10 = v67;
      v9 = v4 + 544LL * (unsigned int)v6;
    }
  }
  else
  {
    cam_io_r_mb(v49 + 284);
    v68 = -110;
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_burst_read",
      1744);
    cam_cci_dump_registers(v4, v6, 1);
    cam_cci_flush_queue(v4, v6);
    v9 = v4 + 544LL * (unsigned int)v6;
  }
LABEL_16:
  mutex_unlock(v9 + 4248);
  mutex_lock(v10 + 90);
  if ( --*((_WORD *)v10 + 204) == 0 )
    up(v10 + 84);
  mutex_unlock(v10 + 90);
  return v68;
}
