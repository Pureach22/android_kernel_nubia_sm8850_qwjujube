__int64 __fastcall dp_rx_ol_init(__int64 *a1, char a2)
{
  __int64 **context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 **v13; // x21
  __int64 v14; // x8
  __int64 (*v15)(void); // x8
  int v16; // w22
  __int64 *v17; // x8
  __int64 v18; // x8
  unsigned int (__fastcall *v19)(__int64 **, __int64); // x8
  __int64 v20; // x8
  unsigned int (__fastcall *v21)(__int64 **, __int64); // x8
  int v22; // w21
  int v23; // w22
  const char *v24; // x2
  __int64 v25; // x8
  unsigned int (__fastcall *v26)(__int64 **, __int64); // x8
  __int64 v27; // x8
  unsigned int (__fastcall *v28)(__int64 **, __int64); // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 (__fastcall *v37)(); // x8
  const char *v38; // x2
  unsigned int v39; // w1
  void (__fastcall *v40)(_QWORD); // x10
  __int64 v41; // x0
  unsigned int v42; // w20
  char v43; // w8
  __int64 (__fastcall *v44)(__int64, __int64 *); // x8
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v63; // [xsp+0h] [xbp-50h] BYREF
  _QWORD v64[9]; // [xsp+8h] [xbp-48h] BYREF

  v64[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = (__int64 **)_cds_get_context(71, "dp_resolve_rx_ol_mode");
  v13 = context;
  if ( !context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_cfg_get");
    v16 = 0;
    goto LABEL_25;
  }
  if ( !*context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_cfg_get");
    goto LABEL_11;
  }
  v14 = **context;
  if ( !v14 )
    goto LABEL_42;
  v15 = *(__int64 (**)(void))(v14 + 264);
  if ( !v15 )
  {
LABEL_11:
    v16 = 0;
    v17 = *v13;
    if ( *v13 )
      goto LABEL_12;
LABEL_25:
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_cfg_get");
    goto LABEL_26;
  }
  if ( *((_DWORD *)v15 - 1) != -1095293032 )
    __break(0x8228u);
  v16 = v15();
  v17 = *v13;
  if ( !*v13 )
    goto LABEL_25;
LABEL_12:
  v18 = *v17;
  if ( v18 )
  {
    v19 = *(unsigned int (__fastcall **)(__int64 **, __int64))(v18 + 264);
    if ( v19 )
    {
      if ( *((_DWORD *)v19 - 1) != -1095293032 )
        __break(0x8228u);
      if ( v16 == v19(v13, 7) )
        goto LABEL_27;
      goto LABEL_17;
    }
  }
LABEL_26:
  if ( !v16 )
  {
LABEL_27:
    if ( v13 && *v13 )
    {
      v25 = **v13;
      if ( !v25 )
        goto LABEL_42;
      v26 = *(unsigned int (__fastcall **)(__int64 **, __int64))(v25 + 264);
      if ( !v26 )
        goto LABEL_42;
      if ( *((_DWORD *)v26 - 1) != -1095293032 )
        __break(0x8228u);
      if ( !v26(v13, 6) )
        goto LABEL_42;
      if ( *v13 )
      {
        v27 = **v13;
        if ( v27 )
        {
          v28 = *(unsigned int (__fastcall **)(__int64 **, __int64))(v27 + 264);
          if ( v28 )
          {
            if ( *((_DWORD *)v28 - 1) != -1095293032 )
              __break(0x8228u);
            if ( v28(v13, 7) )
            {
              v22 = 0;
              v23 = 0;
              v24 = "%s: Can't enable both LRO and GRO, disabling Rx offload";
              goto LABEL_45;
            }
          }
        }
        goto LABEL_42;
      }
    }
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_cfg_get");
LABEL_42:
    v22 = 0;
    v23 = 0;
    v24 = "%s: LRO and GRO both are disabled";
    goto LABEL_45;
  }
LABEL_17:
  if ( v13 && *v13 )
  {
    v20 = **v13;
    if ( v20 )
    {
      v21 = *(unsigned int (__fastcall **)(__int64 **, __int64))(v20 + 264);
      if ( v21 )
      {
        if ( *((_DWORD *)v21 - 1) != -1095293032 )
          __break(0x8228u);
        if ( v21(v13, 6) )
        {
          v22 = 0;
          v23 = 1;
          v24 = "%s: Rx offload LRO is enabled";
          goto LABEL_45;
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_cfg_get");
  }
  v23 = 2;
  v22 = 1;
  v24 = "%s: Rx offload: GRO is enabled";
LABEL_45:
  qdf_trace_msg(0x45u, 5u, v24, v5, v6, v7, v8, v9, v10, v11, v12, "dp_resolve_rx_ol_mode");
  *((_DWORD *)a1 + 350) = v23;
  if ( a1 )
  {
    *((_BYTE *)a1 + 848) = 0;
    if ( v22 )
    {
      *((_DWORD *)a1 + 294) = 1;
      if ( (a2 & 1) != 0 )
      {
        v37 = dp_gro_rx;
      }
      else
      {
        v40 = (void (__fastcall *)(_QWORD))a1[60];
        if ( *((_BYTE *)a1 + 370) )
          v41 = 1;
        else
          v41 = 2;
        if ( *((_DWORD *)v40 - 1) != 679229441 )
          __break(0x822Au);
        v40(v41);
        v37 = dp_gro_rx_legacy;
      }
      a1[146] = (__int64)v37;
      v38 = "%s: GRO is enabled";
    }
    else
    {
      if ( !*((_DWORD *)a1 + 23) )
        goto LABEL_61;
      v38 = "%s: TCP Del ACK is enabled";
      *((_BYTE *)a1 + 848) = 1;
    }
    v39 = 5;
  }
  else
  {
    v38 = "%s: DP context is NULL";
    v39 = 2;
  }
  qdf_trace_msg(0x45u, v39, v38, v29, v30, v31, v32, v33, v34, v35, v36, "dp_register_rx_ol_cb");
LABEL_61:
  qdf_trace_msg(0x45u, 5u, "%s: ol init", v29, v30, v31, v32, v33, v34, v35, v36, "dp_rx_ol_init");
  if ( (a2 & 1) != 0 )
  {
    v42 = 0;
  }
  else
  {
    v43 = *((_BYTE *)a1 + 217);
    memset(v64, 0, 64);
    v63 = 0;
    if ( (v43 & 1) != 0 || *((_BYTE *)a1 + 216) == 1 )
      v63 = 0x1EE1000000001LL;
    get_random_bytes(v64, 20);
    get_random_bytes((char *)&v64[2] + 4, 44);
    v44 = (__int64 (__fastcall *)(__int64, __int64 *))a1[101];
    v45 = *a1;
    if ( *((_DWORD *)v44 - 1) != -1141409127 )
      __break(0x8228u);
    v42 = v44(v45, &v63);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: LRO Config: lro_enable: 0x%x tcp_flag 0x%x tcp_flag_mask 0x%x",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "dp_rx_ol_send_config",
      (unsigned int)v63,
      WORD2(v63) & 0x1FF,
      (HIDWORD(v63) >> 9) & 0x1FF);
    if ( v42 )
    {
      *((_DWORD *)a1 + 350) = 0;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Failed to send LRO/GRO configuration! %u",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "dp_rx_ol_init",
        v42);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v42;
}
