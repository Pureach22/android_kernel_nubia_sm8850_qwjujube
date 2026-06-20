__int64 __fastcall cam_get_dt_power_setting_data(__int64 a1, __int64 a2, __int64 a3)
{
  int string_helper; // w0
  unsigned int v6; // w27
  __int64 v7; // x0
  __int64 v8; // x24
  __int64 v9; // x23
  _DWORD *v10; // x27
  unsigned int v11; // w0
  const char *v12; // x19
  int v13; // w7
  __int64 result; // x0
  unsigned int v15; // w19
  __int64 v16; // x27
  _QWORD *v17; // x24
  unsigned int variable_u32_array; // w0
  __int64 v19; // x19
  _QWORD *v20; // x28
  unsigned int v21; // w0
  __int64 v22; // x19
  _WORD *v23; // x27
  __int64 v24; // x26
  int v25; // w8
  __int64 v26; // x0
  int v27; // w9
  __int64 v28; // x8
  unsigned int v29; // w11
  __int64 v30; // x11
  _QWORD *v31; // x12
  _QWORD *v32; // x13
  __int64 v33; // x14
  __int64 v34; // x14
  __int64 v35; // x16
  __int64 v36; // x17
  __int64 v37; // x14
  __int64 v38; // x16
  __int64 v39; // x17
  __int64 v40; // x14
  __int64 v41; // x15
  __int64 v42; // x12
  __int64 v43; // x16
  __int64 v44; // [xsp+8h] [xbp-28h]
  int v45; // [xsp+10h] [xbp-20h]
  _QWORD *v46; // [xsp+18h] [xbp-18h]
  const char *v47[2]; // [xsp+20h] [xbp-10h] BYREF

  v47[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v47[0] = nullptr;
  if ( !a3 )
  {
    result = 4294967274LL;
    goto LABEL_76;
  }
  string_helper = of_property_read_string_helper(a1, "qcom,cam-power-seq-type", 0, 0, 0);
  if ( string_helper < 1 )
  {
    result = 0;
    goto LABEL_76;
  }
  v6 = string_helper;
  if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x800000000LL,
      4,
      "cam_get_dt_power_setting_data",
      1748,
      "qcom,cam-power-seq-type count %d",
      string_helper);
  *(_WORD *)(a3 + 16) = v6;
  if ( mem_trace_en != 1 )
  {
    v7 = _kvmalloc_node_noprof(112LL * v6, 0, 3520, 0xFFFFFFFFLL);
    if ( v7 )
      goto LABEL_8;
LABEL_28:
    result = 4294967284LL;
    goto LABEL_76;
  }
  v7 = cam_mem_trace_alloc(112LL * v6, 0xCC0u, 0, "cam_get_dt_power_setting_data", 0x6D7u);
  if ( !v7 )
    goto LABEL_28;
LABEL_8:
  v8 = 0;
  v44 = a3;
  v45 = v6;
  *(_QWORD *)(a3 + 8) = v7;
  v9 = v6;
  v10 = (_DWORD *)v7;
  v46 = (_QWORD *)v7;
  do
  {
    v11 = of_property_read_string_helper(a1, "qcom,cam-power-seq-type", v47, 1, (unsigned int)v8);
    if ( (v11 & 0x80000000) != 0 )
    {
      v15 = v11;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_get_dt_power_setting_data",
        1760,
        "failed");
      goto LABEL_72;
    }
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_get_dt_power_setting_data",
        1763,
        "seq_name[%d] = %s",
        v8,
        v47[0]);
    v12 = v47[0];
    if ( !strcmp(v47[0], "cam_vio") )
    {
      v13 = 3;
    }
    else if ( !strcmp(v12, "cam_vana") )
    {
      v13 = 1;
    }
    else if ( !strcmp(v12, "cam_vana1") )
    {
      v13 = 12;
    }
    else
    {
      if ( strcmp(v12, "cam_clk") )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_get_dt_power_setting_data",
          1774,
          "unrecognized seq-type %s",
          v12);
        v15 = -84;
        goto LABEL_72;
      }
      v13 = 0;
    }
    *v10 = v13;
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_get_dt_power_setting_data",
        1778,
        "seq_type[%d] %d",
        (unsigned int)v8);
    ++v8;
    v10 += 28;
  }
  while ( v9 != v8 );
  if ( mem_trace_en == 1 )
  {
    LODWORD(v16) = v45;
    v17 = (_QWORD *)cam_mem_trace_alloc(4LL * (unsigned int)v45, 0xCC0u, 0, "cam_get_dt_power_setting_data", 0x6F5u);
    if ( !v17 )
    {
LABEL_71:
      v15 = -12;
      goto LABEL_72;
    }
  }
  else
  {
    LODWORD(v16) = v45;
    v17 = (_QWORD *)_kvmalloc_node_noprof(4LL * (unsigned int)v45, 0, 3520, 0xFFFFFFFFLL);
    if ( !v17 )
      goto LABEL_71;
  }
  variable_u32_array = of_property_read_variable_u32_array(a1, "qcom,cam-power-seq-cfg-val", v17, v9, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v15 = variable_u32_array;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_get_dt_power_setting_data",
      1790,
      "failed ");
    goto LABEL_56;
  }
  v19 = 0;
  if ( (int)v16 <= 1 )
    v16 = 1;
  else
    v16 = (unsigned int)v16;
  v20 = v46 + 1;
  do
  {
    *v20 = *((unsigned int *)v17 + v19);
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_get_dt_power_setting_data",
        1797,
        "power_setting[%d].config_val = %ld",
        (unsigned int)v19);
    ++v19;
    v20 += 14;
  }
  while ( v16 != v19 );
  v21 = of_property_read_variable_u32_array(a1, "qcom,cam-power-seq-delay", v17, v9, 0);
  if ( (v21 & 0x80000000) != 0 )
  {
    v15 = v21;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_get_dt_power_setting_data",
      1803,
      "failed");
LABEL_56:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v17, 0);
    else
      kvfree(v17);
LABEL_72:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v46, 0);
    else
      kvfree(v46);
    result = v15;
    goto LABEL_76;
  }
  v22 = 0;
  v23 = v46 + 2;
  if ( v45 <= 1 )
    v24 = 1;
  else
    v24 = (unsigned int)v45;
  do
  {
    v25 = *((_DWORD *)v17 + v22);
    *v23 = v25;
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_get_dt_power_setting_data",
        1809,
        "power_setting[%d].delay = %d",
        v22,
        (unsigned __int16)v25);
    ++v22;
    v23 += 56;
  }
  while ( v24 != v22 );
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v17, 0);
  else
    kvfree(v17);
  if ( mem_trace_en == 1 )
    v26 = cam_mem_trace_alloc(112 * v9, 0xCC0u, 0, "cam_get_dt_power_setting_data", 0x716u);
  else
    v26 = _kvmalloc_node_noprof(112 * v9, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v44 + 24) = v26;
  if ( !v26 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_get_dt_power_setting_data",
      1817,
      "failed");
    goto LABEL_71;
  }
  v27 = v45 - 1;
  v28 = 0;
  if ( v45 <= 1 )
    v29 = 1;
  else
    v29 = v45;
  *(_WORD *)(v44 + 32) = v45;
  v30 = 112LL * v29;
  do
  {
    v31 = &v46[14 * v27];
    result = 0;
    --v27;
    v32 = (_QWORD *)(*(_QWORD *)(v44 + 24) + v28);
    v28 += 112;
    v33 = v31[1];
    *v32 = *v31;
    v32[1] = v33;
    v34 = v31[5];
    v35 = v31[2];
    v36 = v31[3];
    v32[4] = v31[4];
    v32[5] = v34;
    v32[2] = v35;
    v32[3] = v36;
    v37 = v31[9];
    v38 = v31[6];
    v39 = v31[7];
    v32[8] = v31[8];
    v32[9] = v37;
    v32[6] = v38;
    v32[7] = v39;
    v41 = v31[12];
    v40 = v31[13];
    v43 = v31[10];
    v42 = v31[11];
    v32[12] = v41;
    v32[13] = v40;
    v32[10] = v43;
    v32[11] = v42;
  }
  while ( v30 != v28 );
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
