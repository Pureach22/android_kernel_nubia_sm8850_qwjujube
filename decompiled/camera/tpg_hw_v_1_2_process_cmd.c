__int64 __fastcall tpg_hw_v_1_2_process_cmd(_DWORD *a1, int a2, __int64 a3)
{
  _DWORD *v3; // x23
  __int64 v4; // x24
  unsigned int *v5; // x22
  int v6; // w19
  unsigned int v7; // w19
  unsigned int v8; // w19
  __int64 result; // x0
  __int64 v10; // x6
  const char *v11; // x3
  const char *v12; // x5
  __int64 v13; // x1
  __int64 v14; // x4
  const char *v15; // x3
  const char *v16; // x5
  __int64 v17; // x4
  __int64 v18; // x24
  unsigned int *v19; // x22
  __int64 v20; // x23
  unsigned int v21; // w19
  int v22; // w19
  _DWORD *v23; // x22
  __int64 v24; // x23
  __int64 v25; // x23
  _DWORD *v26; // x22
  unsigned int v27; // w0
  unsigned int v28; // w19

  if ( !a1 )
  {
    v15 = "tpg_hw_v_1_2_process_cmd";
    v16 = "invalid argument";
    v17 = 190;
    goto LABEL_18;
  }
  if ( (debug_mdl & 0x200000000LL) == 0 || debug_priority )
  {
    if ( a2 != 0x4000 )
      goto LABEL_5;
LABEL_35:
    if ( *(int *)a3 > 0 )
    {
      v25 = *((_QWORD *)a1 + 5);
      v26 = a1;
      cam_io_w_mb(0xFFFFF, *(_QWORD *)(v25 + 288) + 116LL);
      if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x200000000LL,
          4,
          "configure_global_configs",
          64,
          "TPG[%d] cfg3=0x%x",
          *v26,
          0xFFFFF);
      v27 = cam_io_r_mb(*(_QWORD *)(v25 + 312) + 144LL);
      v28 = v27;
      if ( *v26 == 14 )
      {
        v28 = v27 | 0x100;
      }
      else if ( *v26 == 13 )
      {
        v28 = v27 | 1;
      }
      cam_io_w_mb(v28, *(_QWORD *)(v25 + 312) + 144LL);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        3,
        "configure_global_configs",
        77,
        "TPG[%d] Set CPAS top mux: 0x%x",
        *v26,
        v28);
      cam_io_w_mb(1, *(_QWORD *)(v25 + 288) + 96LL);
      result = 0;
      if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x200000000LL,
          4,
          "configure_global_configs",
          81,
          "TPG[%d] tpg_module_cfg=0x%x",
          *v26,
          1);
        return 0;
      }
      return result;
    }
    v15 = "configure_global_configs";
    v16 = "Invalid vc count";
    v17 = 56;
    goto LABEL_18;
  }
  v22 = a2;
  v23 = a1;
  v24 = a3;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x200000000LL,
    4,
    "tpg_hw_v_1_2_process_cmd",
    194,
    "TPG[%d] Cmd opcode:0x%x",
    *a1,
    a2);
  a2 = v22;
  a3 = v24;
  a1 = v23;
  if ( v22 == 0x4000 )
    goto LABEL_35;
LABEL_5:
  if ( a2 != 16386 )
  {
    if ( a2 != 16385 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_v_1_2_process_cmd",
        236,
        "invalid argument");
      return 0;
    }
    if ( a3 )
    {
      v3 = *(_DWORD **)(a3 + 8);
      v4 = *((_QWORD *)a1 + 5);
      v5 = a1;
      v6 = 16 * (v3[5] == 2);
      if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x200000000LL,
          4,
          "configure_vc",
          142,
          "TPG[%d] period: %d",
          *a1,
          *(_DWORD *)((char *)v3 + 73));
      v7 = v6 & 0xFFFFF81F | (32 * (*(_DWORD *)((char *)v3 + 73) & 0x3F));
      cam_io_w_mb(v7, *(_QWORD *)(v4 + 288) + 112LL);
      if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x200000000LL,
          4,
          "configure_vc",
          148,
          "TPG[%d] cfg2=0x%x",
          *v5,
          v7);
      v8 = *(_DWORD *)((char *)v3 + 61) | (*(_DWORD *)((char *)v3 + 57) << 20);
      cam_io_w_mb(v8, *(_QWORD *)(v4 + 288) + 108LL);
      result = 0;
      if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
      {
        v10 = *v5;
        v11 = "configure_vc";
        v12 = "TPG[%d] cfg1=0x%x";
        v13 = debug_mdl & 0x200000000LL;
        v14 = 154;
LABEL_29:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
          3,
          v13,
          4,
          v11,
          v14,
          v12,
          v10,
          v8);
        return 0;
      }
      return result;
    }
    v15 = "tpg_hw_v_1_2_process_cmd";
    v16 = "invalid argument";
    v17 = 202;
LABEL_18:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      v15,
      v17,
      v16);
    return 4294967274LL;
  }
  if ( !a3 )
  {
    v15 = "tpg_hw_v_1_2_process_cmd";
    v16 = "invalid argument";
    v17 = 217;
    goto LABEL_18;
  }
  v18 = *(_QWORD *)(a3 + 8);
  v19 = a1;
  v20 = *((_QWORD *)a1 + 5);
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "configure_dt",
      105,
      "TPG[%d] slot(%d,%d) <= dt:%d",
      *a1,
      *(_DWORD *)a3,
      *(_DWORD *)(a3 + 4),
      *(unsigned __int16 *)(v18 + 67));
  v21 = *(unsigned __int16 *)(v18 + 44) | (*(_DWORD *)(v18 + 40) << 16);
  cam_io_w_mb(v21, *(_QWORD *)(v20 + 288) + 104LL);
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "configure_dt",
      112,
      "TPG[%d] cfg0=0x%x",
      *v19,
      v21);
  v8 = *(unsigned __int16 *)(v18 + 67) << 11;
  cam_io_w_mb(v8, *(_QWORD *)(v20 + 288) + 112LL);
  result = 0;
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    v10 = *v19;
    v11 = "configure_dt";
    v12 = "TPG[%d] cfg2=0x%x";
    v13 = debug_mdl & 0x200000000LL;
    v14 = 119;
    goto LABEL_29;
  }
  return result;
}
