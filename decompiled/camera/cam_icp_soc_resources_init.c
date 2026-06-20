__int64 __fastcall cam_icp_soc_resources_init(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  __int64 v4; // x23
  int *v8; // x26
  unsigned int dt_properties; // w0
  __int64 v10; // x6
  const char *v11; // x5
  __int64 v12; // x4
  int v13; // w24
  unsigned int v14; // w0
  unsigned int v15; // w0
  __int64 v16; // x6
  __int64 v17; // x0
  __int64 v18; // x27
  __int64 v19; // x24
  unsigned int v20; // w0
  unsigned int v21; // w0
  int v22; // w8
  unsigned int v23; // w19
  const char *v25; // x5
  __int64 v26; // x4
  unsigned int v27; // w0
  unsigned int v28; // w0
  __int64 v29; // x0
  const char *v30; // x6
  const char *v31; // x5
  __int64 v32; // x4
  unsigned int v33; // w0
  unsigned int v34; // w0
  unsigned __int64 StatusReg; // x24
  __int64 v36; // x25
  __int64 v37; // x0
  _BYTE v38[4]; // [xsp+Ch] [xbp-24h] BYREF
  _BYTE v39[4]; // [xsp+10h] [xbp-20h] BYREF
  unsigned int v40; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v41; // [xsp+18h] [xbp-18h] BYREF
  __int64 v42; // [xsp+20h] [xbp-10h]
  __int64 v43; // [xsp+28h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(int **)(a1 + 3296);
  v41 = 0;
  v42 = 0;
  if ( v8 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)a1 + 760LL);
    dt_properties = cam_soc_util_get_dt_properties(a1);
    if ( dt_properties )
    {
      v10 = dt_properties;
      v11 = "failed to get DT properties rc=%d";
      v12 = 191;
LABEL_27:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_soc_dt_properties_get",
        v12,
        v11,
        v10);
      goto LABEL_28;
    }
    LOBYTE(v40) = 0;
    v4 = (__int64)(v8 + 4);
    v13 = *v8;
    v14 = _ubwc_config_get(v3, "ubwc-cfg", v8 + 4, &v40);
    if ( (unsigned __int8)v40 == 1 )
    {
      v10 = v14;
      if ( !v13 )
        *((_BYTE *)v8 + 68) = 1;
      if ( !v14 )
        goto LABEL_9;
LABEL_26:
      v11 = "failed to get UBWC config props rc=%d";
      v12 = 197;
      goto LABEL_27;
    }
    v39[0] = 0;
    v20 = _ubwc_config_get(v3, "ubwc-ipe-fetch-cfg", v8 + 4, v39);
    v10 = v20;
    if ( v20 )
      goto LABEL_26;
    v38[0] = 0;
    v21 = _ubwc_config_get(v3, "ubwc-ipe-write-cfg", v8 + 6, v38);
    v10 = v21;
    if ( v21 )
      goto LABEL_26;
    if ( v39[0] == 1 && (v38[0] & 1) != 0 )
    {
      v8[16] |= 4u;
    }
    else if ( v39[0] != v38[0] )
    {
      if ( v39[0] )
        v30 = "write";
      else
        v30 = "fetch";
      v31 = "Missing %s ipe ubwc config";
      v32 = 81;
      goto LABEL_52;
    }
    v27 = _ubwc_config_get(v3, "ubwc-bps-fetch-cfg", v8 + 8, v39);
    v10 = v27;
    if ( v27 )
      goto LABEL_26;
    v28 = _ubwc_config_get(v3, "ubwc-bps-write-cfg", v8 + 10, v38);
    v10 = v28;
    if ( v28 )
      goto LABEL_26;
    if ( v39[0] == 1 && (v38[0] & 1) != 0 )
    {
      v8[16] |= 8u;
      goto LABEL_54;
    }
    if ( v39[0] == v38[0] )
    {
LABEL_54:
      v33 = _ubwc_config_get(v3, "ubwc-ofe-fetch-cfg", v8 + 12, v39);
      v10 = v33;
      if ( v33 )
        goto LABEL_26;
      v34 = _ubwc_config_get(v3, "ubwc-ofe-write-cfg", v8 + 14, v38);
      v10 = v34;
      if ( v34 )
        goto LABEL_26;
      if ( v39[0] == 1 && (v38[0] & 1) != 0 )
      {
        v8[16] |= 0x10u;
        goto LABEL_9;
      }
      if ( v39[0] == v38[0] )
      {
LABEL_9:
        if ( (of_property_read_variable_u32_array(v3, "qos-val", v8 + 1, 1, 0) & 0x80000000) != 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            2,
            "cam_icp_soc_qos_get",
            134,
            "QoS not set for device: %d",
            *v8);
          v8[1] = 0;
        }
        if ( (of_property_read_variable_u32_array(v3, "fw-pas-id", v8 + 3, 1, 0) & 0x80000000) != 0 )
        {
          v4 = 33;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            2,
            "cam_icp_soc_get_fw_pas_id",
            169,
            "PAS_ID is not passed from DTSI and use default value: %d",
            33);
          v8[3] = 33;
        }
        v40 = 0;
        v15 = of_property_read_variable_u32_array(v3, "icp-version", &v40, 1, 0);
        if ( (v15 & 0x80000000) != 0 )
        {
          v16 = v15;
          v25 = "read icp-version failed rc=%d";
          v26 = 147;
        }
        else
        {
          v16 = v40;
          if ( v40 - 512 < 2 || v40 == 256 )
          {
            v8[2] = v40;
            v4 = (unsigned int)of_property_count_elems_of_size(v3, "cam_hw_pid", 4);
            if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x100,
                4,
                "cam_icp_soc_dt_properties_get",
                212,
                "ICP pid count: %d",
                v4);
              if ( (int)v4 < 1 )
                goto LABEL_28;
            }
            else if ( (int)v4 < 1 )
            {
              goto LABEL_28;
            }
            if ( mem_trace_en == 1 )
            {
              v17 = cam_mem_trace_alloc(4 * v4, 0xCC0u, 0, "cam_icp_soc_dt_properties_get", 0xD9u);
              *((_QWORD *)v8 + 10) = v17;
              if ( v17 )
                goto LABEL_21;
            }
            else
            {
              v29 = _kvmalloc_node_noprof(4 * v4, 0, 3520, 0xFFFFFFFFLL);
              *((_QWORD *)v8 + 10) = v29;
              if ( v29 )
                goto LABEL_21;
            }
LABEL_47:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_soc_dt_properties_get",
              219,
              "Failed at allocating memory for OFE hw pids");
            v23 = -12;
            goto LABEL_33;
          }
          v25 = "Invalid ICP version: %u";
          v26 = 158;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_soc_get_hw_version",
          v26,
          v25,
          v16);
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_soc_dt_properties_get",
          207,
          "Get ICP HW version failed");
        goto LABEL_28;
      }
      if ( v39[0] )
        v30 = "write";
      else
        v30 = "fetch";
      v31 = "Missing %s ofe ubwc config";
      v32 = 121;
      goto LABEL_52;
    }
    if ( v39[0] )
      v30 = "write";
    else
      v30 = "fetch";
    v31 = "Missing %s bps ubwc config";
    v32 = 101;
LABEL_52:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_soc_ubwc_config_get",
      v32,
      v31,
      v30);
    v10 = 4294967274LL;
    goto LABEL_26;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_soc_dt_properties_get",
    181,
    "soc private is NULL");
LABEL_28:
  while ( 1 )
  {
    v22 = *(_DWORD *)(a1 + 104);
    if ( !v22 )
      break;
    v41 = a3;
    if ( v22 == 1 )
      break;
    v42 = a3;
    if ( v22 == 2 )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v36 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_icp_soc_dt_properties_get__alloc_tag_18;
    v37 = _kvmalloc_node_noprof(4 * v4, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v36;
    *((_QWORD *)v8 + 10) = v37;
    if ( !v37 )
      goto LABEL_47;
LABEL_21:
    v18 = 0;
    v19 = 0;
    do
    {
      of_property_read_u32_index(v3, "cam_hw_pid", (unsigned int)v19++, *((_QWORD *)v8 + 10) + v18);
      v18 += 4;
    }
    while ( v4 != v19 );
    v8[18] = v4;
  }
  v23 = cam_soc_util_request_platform_resource(a1, a2, &v41);
  if ( v23 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_soc_resources_init",
      248,
      "request for soc platform resource failed rc=%d",
      v23);
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return v23;
}
