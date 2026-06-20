__int64 __fastcall cam_cci_data_queue_burst_apply(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        __int64 a5,
        unsigned int a6)
{
  unsigned int v6; // w20
  unsigned int v7; // w21
  unsigned int v8; // w22
  __int64 v9; // x23
  unsigned int v10; // w25
  __int64 v11; // x26
  __int64 v12; // x27
  unsigned int v13; // w28
  __int64 v14; // x8
  __int64 v15; // x15
  __int64 v16; // x8
  __int16 v17; // w19
  int v18; // w24
  int v19; // w0
  __int64 result; // x0
  unsigned int v21; // w24
  __int64 v22; // x19
  __int64 v23; // x21
  int v24; // w8
  int v25; // w9
  unsigned int v26; // w28
  bool v27; // zf
  int v28; // w9
  unsigned __int64 StatusReg; // x19
  __int64 v30; // x0
  __int64 v31; // x8
  unsigned int v32; // [xsp+28h] [xbp-38h]
  __int64 v33; // [xsp+30h] [xbp-30h]
  unsigned int v34; // [xsp+38h] [xbp-28h]
  unsigned int v35; // [xsp+3Ch] [xbp-24h]
  __int64 v36; // [xsp+40h] [xbp-20h]
  __int64 v37; // [xsp+48h] [xbp-18h]
  unsigned int v38; // [xsp+50h] [xbp-10h]
  unsigned int v39; // [xsp+54h] [xbp-Ch]
  unsigned int v40; // [xsp+58h] [xbp-8h]

  if ( a2 >= 2 || (v10 = a3, a3 > 1) )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v30 = _traceiter_cam_cci_burst(0, a2, v13, v10, (__int64)"thirq raised Buflvl", a6);
      v31 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v31;
      if ( !v31 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v30);
    }
LABEL_6:
    v21 = 0;
    v17 = debug_mdl;
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v18 = *(_DWORD *)(v33 + 404);
      v19 = cam_io_r_mb(v36 + v35 + 772);
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v17 & 0x4000,
        4,
        "cam_cci_data_queue_burst_apply",
        786,
        "CCI%d_I2C_M%d_Q%d Threshold IRQ Raised, BufferLevel: %d",
        v18,
        v13,
        v10,
        v19);
      v21 = 0;
    }
    goto LABEL_10;
  }
  v11 = a3;
  v14 = a1 + 544LL * a2;
  v13 = a2;
  v15 = v14 + 4040;
  v12 = *(_QWORD *)(v14 + 4040 + 8LL * a3 + 504);
  if ( !v12 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_data_queue_burst_apply",
      770);
    return 4294967274LL;
  }
  v8 = a2 << 9;
  v9 = v14 + 4568;
  v16 = v15 + 4LL * a3;
  v7 = a3 << 8;
  v34 = 1 << (a3 + 2 * a2);
  v6 = *(_DWORD *)(v9 + 4LL * a3);
  v33 = a1;
  v39 = *(_DWORD *)(v16 + 536);
  v40 = *(_DWORD *)(v16 + 520);
  v38 = *(_DWORD *)(a1 + 32LL * a2 + 16LL * a3 + 3972);
  v36 = *(_QWORD *)(a1 + 672);
  v37 = v15;
  v35 = (a3 << 8) | (a2 << 9);
  if ( a4 == 1 )
    goto LABEL_6;
  v21 = cam_io_r_mb(*(_QWORD *)(a1 + 672) + ((a3 << 8) | (a2 << 9)) + 772LL);
LABEL_10:
  v32 = v13;
  if ( v6 < v40 )
  {
    v22 = v37 + 480;
    v23 = v36 + v8 + v7;
    do
    {
      v24 = *(_DWORD *)(v12 + 4LL * v6);
      v25 = (unsigned __int8)v24 >> 4;
      if ( (v24 & 0xE0) == 0xE0 )
        v26 = 3;
      else
        v26 = (unsigned int)(v25 + 4) >> 2;
      v27 = (v24 & 0xE0) == 0xE0 && v25 == 14;
      if ( v27 && (debug_mdl & 0x4000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_data_queue_burst_apply",
          805,
          "CCI%d_I2C_M%d_Q%d THRESHOLD IRQ Enabled; data_queue[%d]: 0x%x refcnt: %d",
          *(_DWORD *)(v33 + 404),
          v32,
          v10,
          v6,
          v24,
          *(_DWORD *)(v22 + 4 * v11));
        if ( !a4 )
        {
LABEL_29:
          if ( v21 + v26 + 1 <= v38 )
            goto LABEL_34;
          goto LABEL_30;
        }
      }
      else if ( !a4 )
      {
        goto LABEL_29;
      }
      if ( !*(_DWORD *)(v22 + 4 * v11) || v21 < v39 )
      {
        do
        {
LABEL_34:
          cam_io_w_mb(*(unsigned int *)(v12 + 4LL * v6), v23 + 784);
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          {
            v28 = *(_DWORD *)(v12 + 4LL * v6++);
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_data_queue_burst_apply",
              844,
              "CCI%d_I2C_M%d_Q%d LOAD_DATA_ADDR 0x%x, index: %d trig: %d numWordsInQueue: %d",
              *(_DWORD *)(v33 + 404),
              v32,
              v10,
              v28,
              v6,
              a4,
              ++v21);
          }
          else
          {
            ++v21;
            ++v6;
          }
          --v26;
          *(_DWORD *)(v9 + 4 * v11) = v6;
        }
        while ( v26 );
        continue;
      }
LABEL_30:
      if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_data_queue_burst_apply",
          816,
          "CCI%d_I2C_M%d_Q%d CUR_WORD_CNT_ADDR %d len %d max %d",
          *(_DWORD *)(v33 + 404),
          v32,
          v10,
          v21,
          v26,
          v38);
      if ( *(_DWORD *)(v22 + 4 * v11) )
      {
        cam_io_w_mb(v21, v36 + v35 + 768);
        cam_io_w_mb(v34, v36 + 8);
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
          "cam_cci_data_queue_burst_apply",
          827);
        return 0;
      }
    }
    while ( v6 < v40 );
  }
  if ( !v21 || !*(_DWORD *)(v37 + 480 + 4 * v11) )
    return 0;
  cam_io_w_mb(v21, v36 + v35 + 768);
  cam_io_w_mb(v34, v36 + 8);
  result = 0;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_data_queue_burst_apply",
      861,
      "CCI%d_I2C_M%d_Q%d Issued ****** FINAL QUEUE_START********, numWordsInQueue: %d, th_irq_ref_cnt[%d]:%d",
      *(_DWORD *)(v33 + 404),
      v32,
      v10,
      v10,
      v21,
      *(_DWORD *)(v37 + 480 + 4 * v11));
    return 0;
  }
  return result;
}
