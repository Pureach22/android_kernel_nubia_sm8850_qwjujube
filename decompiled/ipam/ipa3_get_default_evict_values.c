__int64 __fastcall ipa3_get_default_evict_values(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x0
  int v4; // w4
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  const char *v14; // x4
  int v15; // w4
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  int v22; // w4
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  int v29; // w4
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  _BOOL4 v36; // w4
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  _BOOL4 v43; // w4
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  _BOOL4 v50; // w4
  __int64 v51; // x8
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  int v55; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v56; // [xsp+8h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_101;
  v1 = result;
  v2 = *(_QWORD *)(ipa3_ctx + 34208);
  *(_QWORD *)result = 0;
  *(_DWORD *)(result + 8) = 0;
  v3 = *(_QWORD *)(v2 + 760);
  v55 = 0;
  if ( (of_property_read_variable_u32_array(v3, "qcom,coal-vp-lru-thrshld", &v55, 1, 0) & 0x80000000) != 0 )
  {
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d Error reading qcom,coal-vp-lru-thrshld...will use default\n",
          "ipa3_get_default_evict_values",
          608);
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
        ipc_log_string(
          v7,
          "ipa %s:%d Error reading qcom,coal-vp-lru-thrshld...will use default\n",
          "ipa3_get_default_evict_values",
          608);
    }
    v4 = 0;
  }
  else
  {
    v4 = v55;
  }
  *(_DWORD *)v1 = v4;
  v8 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d : coal_vp_lru_thrshld = %u", "ipa3_get_default_evict_values", 611, v4);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
      ipc_log_string(v10, "ipa %s:%d : coal_vp_lru_thrshld = %u", "ipa3_get_default_evict_values", 611, *(_DWORD *)v1);
  }
  of_find_property(*(_QWORD *)(v2 + 760), "qcom,coal-eviction-en", 0);
  *(_BYTE *)(v1 + 4) = 1;
  v11 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d : coal_eviction_en = %s", "ipa3_get_default_evict_values", 624, "true");
      v11 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v11 + 34160);
    if ( v13 )
    {
      if ( *(_BYTE *)(v1 + 4) )
        v14 = "true";
      else
        v14 = "false";
      ipc_log_string(v13, "ipa %s:%d : coal_eviction_en = %s", "ipa3_get_default_evict_values", 624, v14);
    }
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,coal_vp_lru_gran_sel", &v55, 1, 0) & 0x80000000) != 0 )
  {
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(
          v17,
          "ipa %s:%d Error reading qcom,coal_vp_lru_gran_sel...will use default\n",
          "ipa3_get_default_evict_values",
          638);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(
          v18,
          "ipa %s:%d Error reading qcom,coal_vp_lru_gran_sel...will use default\n",
          "ipa3_get_default_evict_values",
          638);
    }
    v15 = 0;
  }
  else
  {
    v15 = (unsigned __int8)v55;
  }
  *(_BYTE *)(v1 + 5) = v15;
  v19 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v20 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v20 )
    {
      ipc_log_string(v20, "ipa %s:%d : coal_vp_lru_gran_sel = %u\n", "ipa3_get_default_evict_values", 642, v15);
      v19 = ipa3_ctx;
    }
    v21 = *(_QWORD *)(v19 + 34160);
    if ( v21 )
      ipc_log_string(
        v21,
        "ipa %s:%d : coal_vp_lru_gran_sel = %u\n",
        "ipa3_get_default_evict_values",
        642,
        *(unsigned __int8 *)(v1 + 5));
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,coal-vp-lru-udp-thrshld", &v55, 1, 0)
      & 0x80000000) != 0 )
  {
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(
          v24,
          "ipa %s:%d Error reading qcom,coal-vp-lru-udp-thrshld...will use default\n",
          "ipa3_get_default_evict_values",
          656);
        v23 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v23 + 34160);
      if ( v25 )
        ipc_log_string(
          v25,
          "ipa %s:%d Error reading qcom,coal-vp-lru-udp-thrshld...will use default\n",
          "ipa3_get_default_evict_values",
          656);
    }
    v22 = 0;
  }
  else
  {
    v22 = (unsigned __int8)v55;
  }
  *(_BYTE *)(v1 + 6) = v22;
  v26 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v27 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v27 )
    {
      ipc_log_string(v27, "ipa %s:%d : coal_vp_lru_udp_thrshld = %u", "ipa3_get_default_evict_values", 659, v22);
      v26 = ipa3_ctx;
    }
    v28 = *(_QWORD *)(v26 + 34160);
    if ( v28 )
      ipc_log_string(
        v28,
        "ipa %s:%d : coal_vp_lru_udp_thrshld = %u",
        "ipa3_get_default_evict_values",
        659,
        *(unsigned __int8 *)(v1 + 6));
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,coal-vp-lru-tcp-thrshld", &v55, 1, 0)
      & 0x80000000) != 0 )
  {
    v30 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v31 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v31 )
      {
        ipc_log_string(
          v31,
          "ipa %s:%d Error reading qcom,coal-vp-lru-tcp-thrshld...will use default\n",
          "ipa3_get_default_evict_values",
          673);
        v30 = ipa3_ctx;
      }
      v32 = *(_QWORD *)(v30 + 34160);
      if ( v32 )
        ipc_log_string(
          v32,
          "ipa %s:%d Error reading qcom,coal-vp-lru-tcp-thrshld...will use default\n",
          "ipa3_get_default_evict_values",
          673);
    }
    v29 = 0;
  }
  else
  {
    v29 = (unsigned __int8)v55;
  }
  *(_BYTE *)(v1 + 7) = v29;
  v33 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v34 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v34 )
    {
      ipc_log_string(v34, "ipa %s:%d : coal_vp_lru_tcp_thrshld = %u", "ipa3_get_default_evict_values", 676, v29);
      v33 = ipa3_ctx;
    }
    v35 = *(_QWORD *)(v33 + 34160);
    if ( v35 )
      ipc_log_string(
        v35,
        "ipa %s:%d : coal_vp_lru_tcp_thrshld = %u",
        "ipa3_get_default_evict_values",
        676,
        *(unsigned __int8 *)(v1 + 7));
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,coal-vp-lru-udp-thrshld-en", &v55, 1, 0)
      & 0x80000000) != 0 )
  {
    v37 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v38 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v38 )
      {
        ipc_log_string(
          v38,
          "ipa %s:%d Error reading qcom,coal-vp-lru-udp-thrshld-en...will use default\n",
          "ipa3_get_default_evict_values",
          690);
        v37 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v37 + 34160);
      if ( v39 )
        ipc_log_string(
          v39,
          "ipa %s:%d Error reading qcom,coal-vp-lru-udp-thrshld-en...will use default\n",
          "ipa3_get_default_evict_values",
          690);
    }
    v36 = 1;
  }
  else
  {
    v36 = v55 != 0;
  }
  v40 = ipa3_ctx;
  *(_BYTE *)(v1 + 8) = v36;
  if ( v40 )
  {
    v41 = *(_QWORD *)(v40 + 34152);
    if ( v41 )
    {
      ipc_log_string(v41, "ipa %s:%d : coal_vp_lru_udp_thrshld_en = %u", "ipa3_get_default_evict_values", 694, v36);
      v40 = ipa3_ctx;
    }
    v42 = *(_QWORD *)(v40 + 34160);
    if ( v42 )
      ipc_log_string(
        v42,
        "ipa %s:%d : coal_vp_lru_udp_thrshld_en = %u",
        "ipa3_get_default_evict_values",
        694,
        *(unsigned __int8 *)(v1 + 8));
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,coal-vp-lru-tcp-thrshld-en", &v55, 1, 0)
      & 0x80000000) != 0 )
  {
    v44 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v45 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v45 )
      {
        ipc_log_string(
          v45,
          "ipa %s:%d Error reading qcom,coal-vp-lru-tcp-thrshld-en...will use default\n",
          "ipa3_get_default_evict_values",
          708);
        v44 = ipa3_ctx;
      }
      v46 = *(_QWORD *)(v44 + 34160);
      if ( v46 )
        ipc_log_string(
          v46,
          "ipa %s:%d Error reading qcom,coal-vp-lru-tcp-thrshld-en...will use default\n",
          "ipa3_get_default_evict_values",
          708);
    }
    v43 = 1;
  }
  else
  {
    v43 = v55 != 0;
  }
  v47 = ipa3_ctx;
  *(_BYTE *)(v1 + 9) = v43;
  if ( v47 )
  {
    v48 = *(_QWORD *)(v47 + 34152);
    if ( v48 )
    {
      ipc_log_string(v48, "ipa %s:%d : coal_vp_lru_tcp_thrshld_en = %u", "ipa3_get_default_evict_values", 712, v43);
      v47 = ipa3_ctx;
    }
    v49 = *(_QWORD *)(v47 + 34160);
    if ( v49 )
      ipc_log_string(
        v49,
        "ipa %s:%d : coal_vp_lru_tcp_thrshld_en = %u",
        "ipa3_get_default_evict_values",
        712,
        *(unsigned __int8 *)(v1 + 9));
  }
  result = of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,coal-vp-lru-tcp-num", &v55, 1, 0);
  if ( (result & 0x80000000) == 0 )
  {
    v50 = v55 != 0;
    *(_BYTE *)(v1 + 10) = v50;
    v51 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_101;
    goto LABEL_97;
  }
  v52 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v53 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v53 )
    {
      ipc_log_string(
        v53,
        "ipa %s:%d Error reading qcom,coal-vp-lru-tcp-num...will use default\n",
        "ipa3_get_default_evict_values",
        726);
      v52 = ipa3_ctx;
    }
    result = *(_QWORD *)(v52 + 34160);
    if ( result )
      result = ipc_log_string(
                 result,
                 "ipa %s:%d Error reading qcom,coal-vp-lru-tcp-num...will use default\n",
                 "ipa3_get_default_evict_values",
                 726);
  }
  v50 = 0;
  *(_BYTE *)(v1 + 10) = 0;
  v51 = ipa3_ctx;
  if ( ipa3_ctx )
  {
LABEL_97:
    v54 = *(_QWORD *)(v51 + 34152);
    if ( v54 )
    {
      ipc_log_string(v54, "ipa %s:%d : coal_vp_lru_tcp_num = %u", "ipa3_get_default_evict_values", 729, v50);
      v51 = ipa3_ctx;
    }
    result = *(_QWORD *)(v51 + 34160);
    if ( result )
      result = ipc_log_string(
                 result,
                 "ipa %s:%d : coal_vp_lru_tcp_num = %u",
                 "ipa3_get_default_evict_values",
                 729,
                 *(unsigned __int8 *)(v1 + 10));
  }
LABEL_101:
  _ReadStatusReg(SP_EL0);
  return result;
}
