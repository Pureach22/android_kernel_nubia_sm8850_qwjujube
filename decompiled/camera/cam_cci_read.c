__int64 __fastcall cam_cci_read(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 result; // x0
  unsigned int v6; // w0
  __int64 v7; // x27
  _DWORD *v8; // x26
  __int64 v9; // x21
  int v10; // w8
  unsigned int v11; // w0
  unsigned int v12; // w24
  unsigned int v13; // w19
  __int64 v14; // x8
  unsigned int v15; // w21
  int v16; // w0
  unsigned int v17; // w0
  unsigned int v18; // w9
  __int64 v19; // x0
  __int64 v20; // x24
  __int64 v22; // x6
  const char *v23; // x5
  __int64 v24; // x1
  __int64 v25; // x4
  int v26; // w8
  unsigned int v27; // w23
  __int64 v28; // x23
  __int64 v29; // x0
  __int64 v30; // x6
  int v31; // w8
  int v32; // w0
  unsigned int v33; // w9
  __int64 v34; // x11
  __int64 v35; // x8
  int v36; // w21
  int v37; // w0
  __int64 v38; // x8
  int v39; // w23
  int v40; // w23
  __int64 v41; // x12
  __int64 v42; // x13
  __int64 v43; // x12
  int v44; // w23
  int v45; // w23
  __int64 v46; // x23
  int v47; // w23
  __int64 v48; // x23
  __int64 v49; // x23
  __int64 v50; // x23
  int v51; // w23
  int v52; // [xsp+8h] [xbp-58h]
  int v53; // [xsp+10h] [xbp-50h]
  __int64 v54; // [xsp+28h] [xbp-38h]
  int v55; // [xsp+34h] [xbp-2Ch]
  int v56; // [xsp+34h] [xbp-2Ch]
  __int16 v57; // [xsp+36h] [xbp-2Ah]
  __int16 v58; // [xsp+36h] [xbp-2Ah]
  char v59; // [xsp+37h] [xbp-29h]
  char v60; // [xsp+37h] [xbp-29h]
  __int64 v61; // [xsp+38h] [xbp-28h]
  __int64 v62; // [xsp+40h] [xbp-20h]
  int v63; // [xsp+40h] [xbp-20h]
  int v64; // [xsp+40h] [xbp-20h]
  int v65; // [xsp+40h] [xbp-20h]
  int v66; // [xsp+40h] [xbp-20h]
  int v67; // [xsp+40h] [xbp-20h]
  unsigned int v68; // [xsp+40h] [xbp-20h]
  _BYTE v69[12]; // [xsp+4Ch] [xbp-14h]
  __int64 v70; // [xsp+58h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 240);
  *(_DWORD *)&v69[8] = 0;
  *(_QWORD *)&v69[1] = 0;
  if ( !v2 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_read",
      1795);
    result = 4294967274LL;
    goto LABEL_23;
  }
  v3 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 16LL);
  if ( (unsigned int)v3 >= 2 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_read",
      1804);
    result = 4294967274LL;
LABEL_23:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v6 = cam_cci_set_clk_param(v2);
  if ( (v6 & 0x80000000) != 0 )
  {
    v13 = v6;
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_read",
      1811);
    result = v13;
    goto LABEL_23;
  }
  v7 = v2 + 544LL * (unsigned int)v3;
  v8 = (_DWORD *)(v7 + 4040);
  mutex_lock(v7 + 4248);
  *(_BYTE *)(v2 + v3 + 5828) = 0;
  v9 = *(_QWORD *)(v2 + 672);
  v10 = *(_DWORD *)(v2 + 32 * v3 + 3988);
  *(_DWORD *)(v7 + 4328) = 0;
  v11 = cam_cci_validate_queue(v2, (unsigned int)(v10 - 1), (unsigned int)v3, 1);
  if ( (v11 & 0x80000000) != 0 )
  {
    v14 = v9 + (v3 << 9);
    v15 = v11;
    v16 = cam_io_r_mb(v14 + 1032);
    v12 = v15;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, unsigned int, int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_read",
      1835,
      "CCI%d_I2C_M%d_Q%d Initial validataion failed rc: %d, CUR_CMD:0x%x",
      *(unsigned int *)(v2 + 404),
      (unsigned int)v3,
      1,
      v15,
      v16);
    goto LABEL_19;
  }
  if ( *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 28LL) >= 4u )
  {
    v12 = v11;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, _DWORD, int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_read",
      1842,
      "CCI%d_I2C_M%d_Q%d Invalid read retries info retries from slave: %d, max retries: %d",
      *(unsigned int *)(v2 + 404),
      (unsigned int)v3,
      1,
      *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 28LL),
      3);
LABEL_19:
    mutex_unlock(v7 + 4248);
    mutex_lock(v7 + 4400);
    if ( --*(_WORD *)(v7 + 4448) == 0 )
      up(v7 + 4376);
    mutex_unlock(v7 + 4400);
    result = v12;
    goto LABEL_23;
  }
  if ( !*(_QWORD *)(a2 + 32) )
  {
    v12 = v11;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_read",
      1848,
      "CCI%d_I2C_M%d_Q%d Data ptr is NULL",
      *(unsigned int *)(v2 + 404),
      (unsigned int)v3,
      1);
    goto LABEL_19;
  }
  v17 = cam_cci_write_i2c_queue(v2, 6, (unsigned int)v3);
  v18 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 14);
  if ( (v17 & 0x80000000) != 0 )
  {
    v12 = v17;
    if ( !v18 )
      goto LABEL_19;
    v22 = *(unsigned int *)(v2 + 404);
    v23 = "CCI%d_I2C_M%d_Q%d failed to write lock_cmd for rc: %d";
    v24 = debug_mdl & 0x4000;
    v25 = 1857;
    v52 = v17;
    goto LABEL_58;
  }
  if ( v18 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_read",
      1864,
      "CCI%d_I2C_M%d_Q%d set param sid 0x%x retries %d id_map %d",
      *(_DWORD *)(v2 + 404),
      v3,
      1,
      *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 20LL),
      *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 28LL),
      *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 30LL));
  LODWORD(v19) = cam_cci_write_i2c_queue(
                   v2,
                   (16 * *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 20LL))
                 | (*(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 28LL) << 16)
                 | (*(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 30LL) << 18)
                 | 1u,
                   (unsigned int)v3);
  if ( (v19 & 0x80000000) != 0 )
  {
    if ( (debug_mdl & 0x4000) == 0 )
      goto LABEL_62;
    v12 = v19;
    if ( debug_priority )
      goto LABEL_19;
    v22 = *(unsigned int *)(v2 + 404);
    v52 = v19;
    v23 = "CCI%d_I2C_M%d_Q%d Failed to write param_cmd for rc: %d";
    v24 = debug_mdl & 0x4000;
    v25 = 1872;
    goto LABEL_58;
  }
  v20 = *(unsigned __int16 *)(a2 + 28);
  if ( (unsigned int)v20 >= 5 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_read",
      1878);
    v12 = -22;
    goto LABEL_19;
  }
  v69[0] = (16 * v20) | 0xB;
  if ( (_DWORD)v20 )
  {
    v26 = *(_DWORD *)(a2 + 24);
    v69[v20] = v26;
    if ( (_DWORD)v20 != 1 )
    {
      v69[v20 - 1] = BYTE1(v26);
      if ( (_DWORD)v20 != 2 )
      {
        v69[v20 - 2] = BYTE2(v26);
        if ( (_DWORD)v20 != 3 )
          v69[v20 - 3] = HIBYTE(v26);
      }
    }
  }
  LODWORD(v19) = cam_cci_write_i2c_queue(v2, *(unsigned int *)v69, (unsigned int)v3);
  if ( (v19 & 0x80000000) != 0 )
    goto LABEL_55;
  v27 = (unsigned int)(v20 + 4) >> 2;
  if ( v27 == 1 )
  {
LABEL_40:
    LODWORD(v19) = cam_cci_write_i2c_queue(v2, (16 * *(unsigned __int16 *)(a2 + 40)) | 0xAu, (unsigned int)v3);
    if ( (v19 & 0x80000000) == 0 )
    {
      LODWORD(v19) = cam_cci_write_i2c_queue(v2, 7, (unsigned int)v3);
      if ( (v19 & 0x80000000) == 0 )
      {
        v12 = v19;
        v28 = v9 + (v3 << 9);
        v29 = cam_io_r_mb(v28 + 1028);
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        {
          v68 = v29;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_read",
            1923,
            "CCI%d_I2C_M%d_Q%d_CUR_WORD_CNT 0x%x",
            *(_DWORD *)(v2 + 404),
            v3,
            1,
            v29);
          v29 = v68;
        }
        cam_io_w_mb(v29, v28 + 1024);
        cam_io_w_mb((unsigned int)(2 << (2 * v3)), v9 + 8);
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_read",
            1930,
            "CCI%d_I2C_M%d_Q%d exp_words to be read: %d",
            *(_DWORD *)(v2 + 404),
            v3,
            1,
            (*(unsigned __int16 *)(a2 + 40) >> 2) + 1);
        if ( !cam_common_wait_for_completion_timeout(v7 + 4136) )
        {
          cam_cci_dump_registers(v2, v3, 1);
          cam_io_r_mb(v9 + (v3 << 8) + 284);
          v12 = -110;
          ((void (*)(__int64, const char *, ...))cam_print_log)(
            3,
            print_fmt_cam_context_state,
            (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
            "cam_cci_read",
            1941);
          cam_cci_flush_queue(v2, (unsigned int)v3);
          goto LABEL_19;
        }
        if ( *v8 )
        {
          v30 = *(unsigned int *)(v2 + 404);
          v31 = 2 * *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 20LL);
          if ( *(_BYTE *)(v2 + 5896) == 1 )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int, int))cam_print_log)(
              3,
              0x4000,
              3,
              "cam_cci_read",
              1950,
              "CCI%d_I2C_M%d_Q%d ERROR with Slave 0x%x",
              v30,
              (unsigned int)v3,
              1,
              v31);
          else
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int, int))cam_print_log)(
              3,
              0x4000,
              1,
              "cam_cci_read",
              1954,
              "CCI%d_I2C_M%d_Q%d ERROR with Slave 0x%x",
              v30,
              (unsigned int)v3,
              1,
              v31);
          *v8 = 0;
          v12 = -22;
          goto LABEL_19;
        }
        v32 = cam_io_r_mb(v9 + (v3 << 8) + 284);
        v33 = *(unsigned __int16 *)(a2 + 40);
        if ( v32 != (v33 >> 2) + 1 )
        {
          ((void (*)(__int64, const char *, ...))cam_print_log)(
            3,
            print_fmt_cam_context_state,
            (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
            "cam_cci_read",
            1965);
          memset(*(void **)(a2 + 32), 0, *(unsigned __int16 *)(a2 + 40));
          v12 = -22;
          goto LABEL_19;
        }
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        {
          v51 = v32;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_read",
            1972,
            "CCI%d_I2C_M%d_Q%d index: %d, num_bytes: %d",
            *(_DWORD *)(v2 + 404),
            v3,
            1,
            0,
            v33);
          v32 = v51;
        }
        v34 = 0;
        v55 = 0;
        v35 = v9 + (v3 << 8);
        v36 = v32 + 1;
        v61 = v35;
        while ( 1 )
        {
          v62 = v34;
          v37 = cam_io_r(v61 + 280);
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          {
            v39 = v37;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_read",
              1978,
              "CCI%d_I2C_M%d_Q%d read val: 0x%x",
              *(_DWORD *)(v2 + 404),
              v3,
              1,
              v37);
            v37 = v39;
          }
          v34 = v62;
          if ( (int)v62 >= *(unsigned __int16 *)(a2 + 40) )
            goto LABEL_71;
          v38 = a2;
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          {
            v40 = v37;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_read",
              1981,
              "CCI%d_I2C_M%d_Q%d i: %d, index: %d",
              *(_DWORD *)(v2 + 404),
              v3,
              1,
              0,
              v62);
            v34 = v62;
            v37 = v40;
            v38 = a2;
            if ( !v55 )
            {
LABEL_84:
              if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
              {
                v47 = v37;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x4000,
                  4,
                  "cam_cci_read",
                  1984,
                  "CCI%d_I2C_M%d_Q%d sid: 0x%x",
                  *(_DWORD *)(v2 + 404),
                  v3,
                  1,
                  (unsigned __int8)v37);
                v34 = v62;
                v37 = v47;
                v38 = a2;
              }
              goto LABEL_87;
            }
          }
          else if ( !v55 )
          {
            goto LABEL_84;
          }
          *(_BYTE *)(*(_QWORD *)(v38 + 32) + (int)v34) = v37;
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          {
            v44 = v37;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_read",
              1991,
              "CCI%d_I2C_M%d_Q%d data[%d] 0x%x",
              *(_DWORD *)(v2 + 404),
              v3,
              1,
              v34,
              *(unsigned __int8 *)(*(_QWORD *)(v38 + 32) + (int)v34));
            LODWORD(v34) = v62;
            v37 = v44;
            v38 = a2;
          }
          v34 = (unsigned int)(v34 + 1);
LABEL_87:
          if ( (int)v34 < *(unsigned __int16 *)(v38 + 40) )
          {
            if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
            {
              v56 = v37;
              v45 = v34;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x4000,
                4,
                "cam_cci_read",
                1981,
                "CCI%d_I2C_M%d_Q%d i: %d, index: %d",
                *(_DWORD *)(v2 + 404),
                v3,
                1,
                1,
                v34);
              v37 = v56;
              LODWORD(v34) = v45;
              v38 = a2;
            }
            v41 = (int)v34;
            *(_BYTE *)(*(_QWORD *)(v38 + 32) + (int)v34) = BYTE1(v37);
            if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
            {
              v57 = HIWORD(v37);
              v46 = (int)v34;
              v64 = v34;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x4000,
                4,
                "cam_cci_read",
                1991,
                "CCI%d_I2C_M%d_Q%d data[%d] 0x%x",
                *(_DWORD *)(v2 + 404),
                v3,
                1,
                v34,
                *(unsigned __int8 *)(*(_QWORD *)(v38 + 32) + (int)v34));
              LODWORD(v34) = v64;
              HIWORD(v37) = v57;
              v41 = v46;
              v38 = a2;
            }
            v42 = v41 + 1;
            if ( (int)v41 + 1 >= *(unsigned __int16 *)(v38 + 40) )
            {
              v34 = (unsigned int)v42;
            }
            else
            {
              if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
              {
                v58 = HIWORD(v37);
                v48 = v41;
                v65 = v34;
                v54 = v41 + 1;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x4000,
                  4,
                  "cam_cci_read",
                  1981,
                  "CCI%d_I2C_M%d_Q%d i: %d, index: %d",
                  *(_DWORD *)(v2 + 404),
                  v3,
                  1,
                  2,
                  v41 + 1);
                v42 = v54;
                LODWORD(v34) = v65;
                v41 = v48;
                HIWORD(v37) = v58;
                v38 = a2;
              }
              *(_BYTE *)(*(_QWORD *)(v38 + 32) + v42) = BYTE2(v37);
              if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
              {
                v59 = HIBYTE(v37);
                v49 = v41;
                v66 = v34;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x4000,
                  4,
                  "cam_cci_read",
                  1991,
                  "CCI%d_I2C_M%d_Q%d data[%d] 0x%x",
                  *(_DWORD *)(v2 + 404),
                  v3,
                  1,
                  v42,
                  *(unsigned __int8 *)(*(_QWORD *)(v38 + 32) + v42));
                LODWORD(v34) = v66;
                HIBYTE(v37) = v59;
                v41 = v49;
                v38 = a2;
              }
              v43 = v41 + 2;
              if ( (int)v43 >= *(unsigned __int16 *)(v38 + 40) )
              {
                v34 = (unsigned int)v43;
              }
              else
              {
                if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
                {
                  v60 = HIBYTE(v37);
                  v50 = v43;
                  v67 = v34;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x4000,
                    4,
                    "cam_cci_read",
                    1981,
                    "CCI%d_I2C_M%d_Q%d i: %d, index: %d",
                    *(_DWORD *)(v2 + 404),
                    v3,
                    1,
                    3,
                    v43);
                  LODWORD(v34) = v67;
                  HIBYTE(v37) = v60;
                  v43 = v50;
                  v38 = a2;
                }
                *(_BYTE *)(*(_QWORD *)(v38 + 32) + v43) = HIBYTE(v37);
                if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
                {
                  v63 = v34;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x4000,
                    4,
                    "cam_cci_read",
                    1991,
                    "CCI%d_I2C_M%d_Q%d data[%d] 0x%x",
                    *(_DWORD *)(v2 + 404),
                    v3,
                    1,
                    v43,
                    *(unsigned __int8 *)(*(_QWORD *)(v38 + 32) + v43));
                  LODWORD(v34) = v63;
                }
                v34 = (unsigned int)(v34 + 3);
              }
            }
          }
          v55 = 1;
LABEL_71:
          if ( --v36 <= 1 )
            goto LABEL_19;
        }
      }
      if ( (debug_mdl & 0x4000) != 0 )
      {
        v12 = v19;
        if ( debug_priority )
          goto LABEL_19;
        v22 = *(unsigned int *)(v2 + 404);
        v52 = v19;
        v23 = "CCI%d_I2C_M%d_Q%d failed to write unlock_cmd for rc: %d";
        v24 = debug_mdl & 0x4000;
        v25 = 1916;
        goto LABEL_58;
      }
LABEL_62:
      v12 = v19;
      goto LABEL_19;
    }
    if ( (debug_mdl & 0x4000) == 0 )
      goto LABEL_62;
    v12 = v19;
    if ( debug_priority )
      goto LABEL_19;
    v22 = *(unsigned int *)(v2 + 404);
    v52 = v19;
    v23 = "CCI%d_I2C_M%d_Q%d Failed to write read_cmd for rc: %d";
    v24 = debug_mdl & 0x4000;
    v25 = 1907;
LABEL_58:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int, int, int))cam_print_log)(
      3,
      v24,
      4,
      "cam_cci_read",
      v25,
      v23,
      v22,
      (unsigned int)v3,
      1,
      v52,
      v53);
    goto LABEL_19;
  }
  LODWORD(v19) = cam_cci_write_i2c_queue(v2, *(unsigned int *)&v69[4], (unsigned int)v3);
  if ( (v19 & 0x80000000) != 0 )
  {
LABEL_55:
    if ( (debug_mdl & 0x4000) == 0 )
      goto LABEL_62;
    v12 = v19;
    if ( debug_priority )
      goto LABEL_19;
    v22 = *(unsigned int *)(v2 + 404);
    v52 = v19;
    v23 = "CCI%d_I2C_M%d_Q%d Failed to write disable_cmd for rc: %d";
    v24 = debug_mdl & 0x4000;
    v25 = 1896;
    goto LABEL_58;
  }
  if ( v27 == 2 )
    goto LABEL_40;
  v19 = cam_cci_write_i2c_queue(v2, *(unsigned int *)&v69[8], (unsigned int)v3);
  if ( (v19 & 0x80000000) != 0 )
    goto LABEL_55;
  if ( v27 == 3 )
    goto LABEL_40;
  __break(1u);
  return cam_cci_set_clk_param(v19);
}
