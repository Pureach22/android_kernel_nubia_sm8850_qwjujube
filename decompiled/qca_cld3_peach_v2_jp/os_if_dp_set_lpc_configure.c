__int64 __fastcall os_if_dp_set_lpc_configure(__int64 a1, __int64 a2, unsigned int a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  const char *v13; // x3
  __int64 v14; // x8
  __int64 v15; // x20
  unsigned int v16; // w19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int connection_count_with_mlo; // w19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w19
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  _QWORD *context; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x4
  unsigned int v61; // w5
  __int64 result; // x0
  __int64 v63; // x4
  const char *v64; // x2
  _QWORD *v65; // x19
  const char *v66; // x4
  __int16 v67; // w20
  __int128 v68; // [xsp+8h] [xbp-68h] BYREF
  int v69; // [xsp+18h] [xbp-58h]
  __int64 v70; // [xsp+20h] [xbp-50h] BYREF
  __int64 v71; // [xsp+28h] [xbp-48h]
  __int64 v72; // [xsp+30h] [xbp-40h]
  __int64 v73; // [xsp+38h] [xbp-38h]
  __int64 v74; // [xsp+40h] [xbp-30h]
  __int64 v75; // [xsp+48h] [xbp-28h]
  __int64 v76; // [xsp+50h] [xbp-20h]
  __int64 v77; // [xsp+58h] [xbp-18h]
  __int64 v78; // [xsp+60h] [xbp-10h]
  __int64 v79; // [xsp+68h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v70 = 0;
  if ( (unsigned int)_nla_parse(&v70, 8, a2, a3, &set_monitor_mode_policy, 31, 0) )
  {
    v12 = "%s: Invalid monitor attr";
    v13 = "os_if_dp_set_lpc_configure";
LABEL_15:
    qdf_trace_msg(0x48u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, v13);
    goto LABEL_16;
  }
  v14 = *(_QWORD *)(a1 + 152);
  v69 = 0;
  v68 = 0u;
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 80)) == 0 )
  {
    v12 = "%s: NULL psoc";
    v13 = "os_if_start_capture_allowed";
    goto LABEL_15;
  }
  v16 = *(_DWORD *)(a1 + 16);
  if ( !ucfg_dp_is_local_pkt_capture_enabled() )
  {
    qdf_trace_msg(
      0x48u,
      3u,
      "%s: local pkt capture feature not enabled",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "os_if_start_capture_allowed");
    result = 11;
    goto LABEL_17;
  }
  if ( v16 != 6 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Operation not permitted in mode: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "os_if_start_capture_allowed",
      v16);
    result = 12;
    goto LABEL_17;
  }
  connection_count_with_mlo = policy_mgr_get_connection_count_with_mlo(v15);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Total connections %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "os_if_local_pkt_capture_concurrency_allowed",
    connection_count_with_mlo);
  if ( connection_count_with_mlo )
  {
    if ( connection_count_with_mlo != 1
      || (v42 = policy_mgr_mode_specific_connection_count(v15, 0, nullptr),
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: sta_count %d",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "os_if_local_pkt_capture_concurrency_allowed",
            v42),
          !v42) )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Concurrency check failed, start capture not allowed",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "os_if_start_capture_allowed");
      result = 12;
      goto LABEL_17;
    }
  }
  context = _cds_get_context(71, (__int64)"os_if_dp_local_pkt_capture_start", v34, v35, v36, v37, v38, v39, v40, v41);
  if ( context )
  {
    if ( v73 )
    {
      v60 = *(unsigned int *)(v73 + 4);
      if ( (_DWORD)v60 != 1 )
        goto LABEL_43;
      v61 = 1;
    }
    else
    {
      v61 = 0;
    }
    if ( v74 )
    {
      v60 = *(unsigned int *)(v74 + 4);
      if ( (_DWORD)v60 != 1 )
        goto LABEL_43;
      v61 = 1;
    }
    if ( v71 )
    {
      v60 = *(unsigned int *)(v71 + 4);
      if ( (_DWORD)v60 != 1 )
        goto LABEL_43;
      v61 |= 2u;
    }
    if ( v72 )
    {
      v60 = *(unsigned int *)(v72 + 4);
      if ( (_DWORD)v60 != 1 )
        goto LABEL_43;
      v61 |= 2u;
    }
    if ( v75 )
    {
      v60 = *(unsigned int *)(v75 + 4);
      if ( (_DWORD)v60 != 1 )
        goto LABEL_43;
      v61 |= 4u;
    }
    if ( !v76 )
    {
LABEL_37:
      if ( v78 && (v63 = *(unsigned int *)(v78 + 4), (_DWORD)v63) )
      {
        if ( (_DWORD)v63 != 1 )
        {
          v64 = "%s: Invalid operating type value: %d";
          goto LABEL_49;
        }
        if ( v61 != 7 )
        {
          if ( v61 )
          {
            v64 = "%s: Invalid config for coc mode, pkt_type: %d";
            v63 = v61;
LABEL_49:
            qdf_trace_msg(
              0x48u,
              2u,
              v64,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "os_if_dp_local_pkt_capture_start",
              v63);
            goto LABEL_16;
          }
LABEL_47:
          v64 = "%s: Invalid config, pkt_type: %d";
          v63 = 0;
          goto LABEL_49;
        }
        v65 = context;
        v66 = "coc";
        *(_QWORD *)((char *)&v68 + 2) = -1;
        v67 = 3;
        *(_DWORD *)((char *)&v68 + 10) = -1;
      }
      else
      {
        if ( !v61 )
          goto LABEL_47;
        v65 = context;
        v66 = "lpc";
        v67 = 1;
        WORD1(v68) = -(v61 & 1);
        WORD3(v68) = (__int64)((unsigned __int64)v61 << 62) >> 63;
        WORD2(v68) = (__int64)((unsigned __int64)v61 << 61) >> 63;
      }
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: start capture mode %s, config pkt_type:0x%x",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "os_if_dp_local_pkt_capture_start",
        v66);
      LOWORD(v68) = v67;
      result = cdp_start_local_pkt_capture(v65, &v68);
      goto LABEL_17;
    }
    v60 = *(unsigned int *)(v76 + 4);
    if ( (_DWORD)v60 == 1 )
    {
      v61 |= 4u;
      goto LABEL_37;
    }
LABEL_43:
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid value: %d Expected: %d",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "os_if_dp_local_pkt_capture_start",
      v60,
      1);
  }
LABEL_16:
  result = 4;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
