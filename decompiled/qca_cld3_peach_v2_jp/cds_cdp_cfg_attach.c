__int64 __fastcall cds_cdp_cfg_attach(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 (__fastcall *v21)(__int64, __int64 *); // x9
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x20
  __int64 values; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  void (__fastcall *v35)(__int64, __int64); // x8
  __int64 v36; // x1
  const char *v37; // x2
  const char *v38; // x3
  unsigned int v39; // w0
  __int64 result; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x8
  void (__fastcall *v50)(__int64, __int64 *); // x8
  __int64 v51; // x0
  __int64 v52; // x20
  __int64 (__fastcall **v53)(__int64, __int64); // x8
  __int64 (__fastcall *v54)(__int64, __int64); // x8
  __int64 v55; // x1
  __int64 v56; // x8
  _DWORD *v57; // x8
  __int64 v58; // x0
  __int64 v59; // x8
  _DWORD *v60; // x8
  __int64 v61; // x0
  __int64 v62; // [xsp+8h] [xbp-88h] BYREF
  __int64 v63; // [xsp+10h] [xbp-80h]
  __int64 v64; // [xsp+18h] [xbp-78h]
  __int64 v65; // [xsp+20h] [xbp-70h]
  __int64 v66; // [xsp+28h] [xbp-68h]
  __int64 v67; // [xsp+30h] [xbp-60h]
  __int64 v68; // [xsp+38h] [xbp-58h]
  __int64 v69; // [xsp+40h] [xbp-50h]
  __int64 v70; // [xsp+48h] [xbp-48h]
  __int64 v71; // [xsp+50h] [xbp-40h]
  __int64 v72; // [xsp+58h] [xbp-38h]
  __int64 v73; // [xsp+60h] [xbp-30h]
  __int64 v74; // [xsp+68h] [xbp-28h]
  __int64 v75; // [xsp+70h] [xbp-20h]
  __int64 v76; // [xsp+78h] [xbp-18h]
  __int64 v77; // [xsp+80h] [xbp-10h]
  __int64 v78; // [xsp+88h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  if ( gp_cds_context )
  {
    v10 = *(_QWORD *)(gp_cds_context + 64);
    if ( !v10 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Module ID %d context is Null (via %s)",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "__cds_get_context",
        71,
        "cds_cdp_cfg_attach");
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "__cds_get_context",
      "cds_cdp_cfg_attach");
    v10 = 0;
  }
  LOBYTE(v62) = 1;
  BYTE1(v62) = ucfg_ipa_uc_is_enabled() & 1;
  HIDWORD(v62) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1060);
  LODWORD(v63) = *(_DWORD *)(cfg_psoc_get_values(a1) + 564);
  HIDWORD(v63) = *(_DWORD *)(cfg_psoc_get_values(a1) + 572);
  LODWORD(v64) = *(_DWORD *)(cfg_psoc_get_values(a1) + 568);
  LOBYTE(v65) = ucfg_dp_is_rx_common_thread_enabled(a1) & 1;
  WORD2(v64) = *(_WORD *)(cfg_psoc_get_values(a1) + 425);
  BYTE6(v64) = *(_BYTE *)(cfg_psoc_get_values(a1) + 427);
  HIBYTE(v64) = *(_BYTE *)(cfg_psoc_get_values(a1) + 636);
  BYTE1(v65) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4169);
  *(_WORD *)((char *)&v76 + 5) = *(_WORD *)(cfg_psoc_get_values(a1) + 406);
  HIBYTE(v76) = *(_BYTE *)(cfg_psoc_get_values(a1) + 408);
  LODWORD(v77) = *(_DWORD *)(cfg_psoc_get_values(a1) + 580);
  if ( (*(_BYTE *)(cfg_psoc_get_values(a1) + 412) & 1) != 0 )
    BYTE4(v76) = 1;
  BYTE4(v77) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4168);
  BYTE5(v77) = *(_BYTE *)(cfg_psoc_get_values(a1) + 576);
  BYTE6(v77) = *(_DWORD *)(cfg_psoc_get_values(a1) + 604);
  if ( !v10 || !*(_QWORD *)v10 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v11, v12, v13, v14, v15, v16, v17, v18, "cdp_cfg_attach");
    v20 = gp_cds_context;
LABEL_21:
    *(_QWORD *)(v20 + 72) = 0;
LABEL_22:
    v37 = "%s: failed to init cfg handle";
    v38 = "cds_cdp_cfg_attach";
    v39 = 56;
LABEL_23:
    result = qdf_trace_msg(v39, 8u, v37, v11, v12, v13, v14, v15, v16, v17, v18, v38);
    goto LABEL_24;
  }
  v19 = *(_QWORD *)(*(_QWORD *)v10 + 104LL);
  v20 = gp_cds_context;
  if ( !v19 )
    goto LABEL_21;
  v21 = *(__int64 (__fastcall **)(__int64, __int64 *))(v19 + 16);
  if ( !v21 )
    goto LABEL_21;
  v22 = *(_QWORD *)(gp_cds_context + 56);
  if ( *((_DWORD *)v21 - 1) != 2124239009 )
    __break(0x8229u);
  v23 = v21(v22, &v62);
  *(_QWORD *)(gp_cds_context + 72) = v23;
  if ( !v23 )
    goto LABEL_22;
  v24 = v23;
  values = cfg_psoc_get_values(a1);
  if ( *(_QWORD *)v10 )
  {
    v34 = *(_QWORD *)(*(_QWORD *)v10 + 104LL);
    if ( v34 )
    {
      v35 = *(void (__fastcall **)(__int64, __int64))(v34 + 64);
      if ( v35 )
      {
        v36 = *(unsigned __int8 *)(values + 4168);
        if ( *((_DWORD *)v35 - 1) != -1851553007 )
          __break(0x8228u);
        v35(v24, v36);
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: invalid instance",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "cdp_cfg_set_flow_steering");
  }
  HIDWORD(v65) = *(_DWORD *)(cfg_psoc_get_values(a1) + 560);
  LODWORD(v66) = *(_DWORD *)(cfg_psoc_get_values(a1) + 556);
  if ( *(_QWORD *)v10 )
  {
    v49 = *(_QWORD *)(*(_QWORD *)v10 + 104LL);
    if ( v49 )
    {
      v50 = *(void (__fastcall **)(__int64, __int64 *))(v49 + 56);
      if ( v50 )
      {
        v51 = *(_QWORD *)(gp_cds_context + 72);
        if ( *((_DWORD *)v50 - 1) != -2143514861 )
          __break(0x8228u);
        v50(v51, &v62);
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: invalid instance",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "cdp_cfg_set_flow_control_parameters");
  }
  v52 = *(_QWORD *)(gp_cds_context + 72);
  result = cfg_psoc_get_values(a1);
  if ( *(_QWORD *)v10 )
  {
    v53 = *(__int64 (__fastcall ***)(__int64, __int64))(*(_QWORD *)v10 + 104LL);
    if ( v53 )
    {
      v54 = *v53;
      if ( v54 )
      {
        v55 = *(unsigned __int8 *)(result + 576);
        if ( *((_DWORD *)v54 - 1) != -1851553007 )
          __break(0x8228u);
        result = v54(v52, v55);
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x89u,
               8u,
               "%s: invalid instance",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "cdp_cfg_set_rx_fwd_disabled");
  }
  if ( *(_QWORD *)v10 )
  {
    v56 = *(_QWORD *)(*(_QWORD *)v10 + 104LL);
    if ( v56 )
    {
      v57 = *(_DWORD **)(v56 + 8);
      if ( v57 )
      {
        v58 = *(_QWORD *)(gp_cds_context + 72);
        if ( *(v57 - 1) != -1851553007 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD))v57)(v58, 0);
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x89u,
               8u,
               "%s: invalid instance",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "cdp_cfg_set_packet_log_enabled");
  }
  if ( !*(_QWORD *)v10 )
  {
    v37 = "%s: invalid instance";
    v38 = "cdp_cfg_set_ptp_rx_opt_enabled";
    v39 = 137;
    goto LABEL_23;
  }
  v59 = *(_QWORD *)(*(_QWORD *)v10 + 104LL);
  if ( v59 )
  {
    v60 = *(_DWORD **)(v59 + 72);
    if ( v60 )
    {
      v61 = *(_QWORD *)(gp_cds_context + 72);
      if ( *(v60 - 1) != -1851553007 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD))v60)(v61, 0);
    }
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
