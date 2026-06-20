__int64 __fastcall init_deinit_service_ready_event_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 psoc_from_scn_hdl; // x0
  __int64 v15; // x20
  __int64 v16; // x19
  __int64 v17; // x8
  void (__fastcall *v18)(__int64, __int64, __int64); // x8
  __int64 v19; // x1
  __int64 v20; // x21
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w8
  _QWORD *v40; // x8
  void (__fastcall *v41)(__int64, __int64, __int64); // x9
  void (__fastcall *v42)(__int64, __int64, __int64); // x9
  void (__fastcall *v43)(__int64, __int64, __int64); // x9
  void (__fastcall *v44)(__int64, __int64, __int64); // x9
  void (__fastcall *v45)(__int64, __int64, __int64); // x9
  void (__fastcall *v46)(__int64, __int64, __int64); // x8
  __int64 v47; // x8
  void (__fastcall *v48)(__int64, __int64, __int64); // x8
  unsigned int v49; // w8
  int v50; // w9
  _DWORD *psoc_legacy_service_ready_cb; // x0
  char v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w9
  const char *v62; // x2
  double inited; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 **v71; // x0
  __int64 v72; // x8
  void (*v73)(void); // x8
  __int64 **v74; // x0
  __int64 v75; // x8
  void (*v76)(void); // x8
  __int64 **v77; // x0
  __int64 v78; // x8
  void (*v79)(void); // x8
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  const char *v88; // x2
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x8
  void (*v98)(void); // x8

  if ( !a1 )
  {
    v88 = "%s: scn handle NULL in service ready handler";
LABEL_139:
    qdf_trace_msg(0x49u, 2u, v88, a4, a5, a6, a7, a8, a9, a10, a11, "init_deinit_service_ready_event_handler");
    return 4294967274LL;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v88 = "%s: psoc is null in service ready handler";
    goto LABEL_139;
  }
  v15 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  v16 = psoc_from_scn_hdl;
  if ( !v15 )
  {
    v88 = "%s: target_psoc_info is null in service ready ev";
    goto LABEL_139;
  }
  v17 = *(_QWORD *)(v15 + 4512);
  if ( v17 )
  {
    v18 = *(void (__fastcall **)(__int64, __int64, __int64))(v17 + 120);
    if ( v18 )
    {
      v19 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
      if ( *((_DWORD *)v18 - 1) != 1314010449 )
        __break(0x8228u);
      v18(psoc_from_scn_hdl, v19, a2);
    }
  }
  v20 = *(_QWORD *)(v15 + 16);
  result = init_deinit_populate_service_bitmap(v20, a2, v15 + 552);
  if ( (_DWORD)result )
    return result;
  result = init_deinit_populate_fw_version_cmd(v20, a2);
  if ( (_DWORD)result )
    return result;
  result = init_deinit_populate_target_cap(v20, a2, v15 + 680);
  if ( (_DWORD)result )
    return result;
  result = init_deinit_populate_phy_reg_cap(v16, v20, a2, v15 + 40, 1);
  if ( (_DWORD)result )
    return result;
  if ( (unsigned int)init_deinit_validate_160_80p80_fw_caps(v16, v15) )
    *(_DWORD *)(v16 + 32) |= 1u;
  if ( (wmi_service_enabled(v20, 35) & 1) != 0 || (wmi_service_enabled(v20, 62) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x400u;
  if ( (wmi_service_enabled(v20, 139) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x1000u;
  if ( (wmi_service_enabled(v20, 100) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x100u;
  if ( (wmi_service_enabled(v20, 154) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x2000u;
  if ( (wmi_service_enabled(v20, 155) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x4000u;
  if ( (wmi_service_enabled(v20, 149) & 1) != 0 )
    qdf_trace_msg(
      0x49u,
      8u,
      "%s:  BSS COLOR OFFLOAD supported",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "init_deinit_service_ready_event_handler");
  if ( (wmi_service_enabled(v20, 174) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x10000u;
  if ( (wmi_service_enabled(v20, 158) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x20000u;
  if ( (wmi_service_enabled(v20, 218) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x800000u;
  if ( (wmi_service_enabled(v20, 187) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x80000u;
  if ( (wmi_service_enabled(v20, 193) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x100000u;
  if ( (wmi_service_enabled(v20, 199) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x200000u;
  if ( (wmi_service_enabled(v20, 248) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x4000000u;
  v30 = wmi_service_enabled(v20, 249);
  v39 = *(_DWORD *)(v16 + 20);
  if ( (v30 & 1) != 0 )
  {
    v39 |= 0x8000000u;
    *(_DWORD *)(v16 + 20) = v39;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s:  TT support %d, Wide BW Scan %d, SW cal %d",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "init_deinit_service_ready_event_handler",
    (v39 >> 10) & 1,
    (v39 >> 12) & 1,
    (v39 >> 8) & 1);
  v40 = *(_QWORD **)(v15 + 4512);
  if ( v40 )
  {
    v41 = (void (__fastcall *)(__int64, __int64, __int64))v40[2];
    if ( !v41 )
      goto LABEL_49;
    if ( *((_DWORD *)v41 - 1) != -1559117844 )
      __break(0x8229u);
    v41(v16, v15, a2);
    v40 = *(_QWORD **)(v15 + 4512);
    if ( v40 )
    {
LABEL_49:
      v42 = (void (__fastcall *)(__int64, __int64, __int64))v40[16];
      if ( !v42 )
        goto LABEL_53;
      if ( *((_DWORD *)v42 - 1) != -1559117844 )
        __break(0x8229u);
      v42(v16, v15, a2);
      v40 = *(_QWORD **)(v15 + 4512);
      if ( v40 )
      {
LABEL_53:
        v43 = (void (__fastcall *)(__int64, __int64, __int64))v40[3];
        if ( !v43 )
          goto LABEL_57;
        if ( *((_DWORD *)v43 - 1) != -1559117844 )
          __break(0x8229u);
        v43(v16, v15, a2);
        v40 = *(_QWORD **)(v15 + 4512);
        if ( v40 )
        {
LABEL_57:
          v44 = (void (__fastcall *)(__int64, __int64, __int64))v40[17];
          if ( !v44 )
            goto LABEL_61;
          if ( *((_DWORD *)v44 - 1) != -1559117844 )
            __break(0x8229u);
          v44(v16, v15, a2);
          v40 = *(_QWORD **)(v15 + 4512);
          if ( v40 )
          {
LABEL_61:
            v45 = (void (__fastcall *)(__int64, __int64, __int64))v40[1];
            if ( !v45 )
              goto LABEL_65;
            if ( *((_DWORD *)v45 - 1) != -1559117844 )
              __break(0x8229u);
            v45(v16, v15, a2);
            v40 = *(_QWORD **)(v15 + 4512);
            if ( v40 )
            {
LABEL_65:
              v46 = (void (__fastcall *)(__int64, __int64, __int64))v40[4];
              if ( v46 )
              {
                if ( *((_DWORD *)v46 - 1) != -1559117844 )
                  __break(0x8228u);
                v46(v16, v15, a2);
              }
            }
          }
        }
      }
    }
  }
  wmi_service_enabled(v20, 256);
  v47 = *(_QWORD *)(v15 + 4512);
  if ( v47 )
  {
    v48 = *(void (__fastcall **)(__int64, __int64, __int64))(v47 + 48);
    if ( v48 )
    {
      if ( *((_DWORD *)v48 - 1) != -1559117844 )
        __break(0x8228u);
      v48(v16, v15, a2);
    }
  }
  if ( (wmi_service_enabled(v20, 186) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x40000u;
  if ( (wmi_service_enabled(v20, 221) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x1000000u;
  if ( (wmi_service_enabled(v20, 263) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x40000000u;
  if ( (wmi_service_enabled(v20, 222) & 1) != 0 )
    *(_DWORD *)(v16 + 20) |= 0x2000000u;
  if ( (wmi_service_enabled(v20, 273) & 1) != 0 )
    *(_DWORD *)(v16 + 24) |= 8u;
  init_deinit_update_wifi_pos_caps(v20, v16);
  if ( (wmi_service_enabled(v20, 278) & 1) != 0 )
    *(_DWORD *)(v16 + 24) |= 0x100u;
  v49 = *(unsigned __int16 *)(v16 + 60);
  if ( *(_DWORD *)(v15 + 72) < v49 )
  {
    v50 = *(_DWORD *)(v15 + 64);
    if ( *(_DWORD *)(v15 + 68) - v50 > v49 )
      *(_DWORD *)(v15 + 68) = v50 + v49;
  }
  psoc_legacy_service_ready_cb = (_DWORD *)target_if_get_psoc_legacy_service_ready_cb();
  if ( !psoc_legacy_service_ready_cb )
    return 4294967274LL;
  if ( *(psoc_legacy_service_ready_cb - 1) != 548044467 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD, __int64, __int64, _QWORD))psoc_legacy_service_ready_cb)(0, a1, a2, a3);
  init_deinit_chainmask_config(v16, v15);
  v52 = wmi_service_enabled(v20, 91);
  if ( (v52 & 1) != 0 )
    v61 = 2048;
  else
    v61 = 0;
  if ( (v52 & 1) != 0 )
    v62 = "%s: WMI mgmt service enabled";
  else
    v62 = "%s: WMI mgmt service disabled";
  *(_DWORD *)(v16 + 20) = *(_DWORD *)(v16 + 20) & 0xFFFFF7FF | v61;
  qdf_trace_msg(0x49u, 8u, v62, v53, v54, v55, v56, v57, v58, v59, v60, "init_deinit_service_ready_event_handler");
  inited = init_deinit_update_p2p_p2p_conc_support(v20, v16);
  result = init_deinit_handle_host_mem_req(v16, v15, a2, inited, v64, v65, v66, v67, v68, v69, v70);
  if ( !(_DWORD)result )
  {
    target_if_reg_set_offloaded_info(v16);
    target_if_reg_set_6ghz_info(v16);
    target_if_reg_set_5dot9_ghz_info(v16);
    target_if_twt_fill_tgt_caps(v16, v20);
    v71 = *(__int64 ***)(v16 + 2808);
    if ( v71 )
    {
      if ( *v71 )
      {
        v72 = **v71;
        if ( v72 )
        {
          v73 = *(void (**)(void))(v72 + 712);
          if ( v73 )
          {
            if ( *((_DWORD *)v73 - 1) != -1347190693 )
              __break(0x8228u);
            v73();
          }
        }
      }
    }
    if ( (wmi_service_enabled(v20, 265) & 1) != 0 )
    {
      v74 = *(__int64 ***)(v16 + 2808);
      if ( v74 )
      {
        if ( *v74 )
        {
          v75 = **v74;
          if ( v75 )
          {
            v76 = *(void (**)(void))(v75 + 712);
            if ( v76 )
            {
              if ( *((_DWORD *)v76 - 1) != -1347190693 )
                __break(0x8228u);
              v76();
            }
          }
        }
      }
    }
    if ( (wmi_service_enabled(v20, 259) & 1) != 0 )
    {
      v77 = *(__int64 ***)(v16 + 2808);
      if ( v77 )
      {
        if ( *v77 )
        {
          v78 = **v77;
          if ( v78 )
          {
            v79 = *(void (**)(void))(v78 + 712);
            if ( v79 )
            {
              if ( *((_DWORD *)v79 - 1) != -1347190693 )
                __break(0x8228u);
              v79();
            }
          }
        }
      }
    }
    if ( (wmi_service_enabled(v20, 183) & 1) != 0 )
      *(_DWORD *)(v16 + 24) |= 0x40u;
    if ( (wmi_service_enabled(v20, 274) & 1) != 0 )
      *(_DWORD *)(v16 + 24) |= 0x10u;
    if ( (wmi_service_enabled(v20, 275) & 1) != 0 )
      *(_DWORD *)(v16 + 24) |= 0x20u;
    if ( (wmi_service_enabled(v20, 290) & 1) != 0 )
      *(_DWORD *)(v16 + 24) |= 0x400u;
    if ( (wmi_service_enabled(v20, 291) & 1) != 0 )
      *(_DWORD *)(v16 + 24) |= 0x800u;
    if ( (wmi_service_enabled(v20, 318) & 1) != 0 )
      *(_DWORD *)(v16 + 24) |= 0x1000u;
    if ( (wmi_service_enabled(v20, 92) & 1) != 0 )
    {
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: Wait for EXT message",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "init_deinit_service_ready_event_handler");
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: No EXT message, send init command",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "init_deinit_service_ready_event_handler");
      *(_BYTE *)(v15 + 487) = 1;
      *(_BYTE *)(v15 + 484) = 1;
      init_deinit_prepare_send_init_cmd(v16, v15, v89, v90, v91, v92, v93, v94, v95, v96);
    }
    if ( (wmi_service_enabled(v20, 298) & 1) == 0 )
      return 0;
    result = *(_QWORD *)(v16 + 2808);
    if ( result )
    {
      if ( *(_QWORD *)result )
      {
        v97 = **(_QWORD **)result;
        if ( v97 )
        {
          v98 = *(void (**)(void))(v97 + 712);
          if ( v98 )
          {
            if ( *((_DWORD *)v98 - 1) != -1347190693 )
              __break(0x8228u);
            v98();
          }
        }
      }
      return 0;
    }
  }
  return result;
}
