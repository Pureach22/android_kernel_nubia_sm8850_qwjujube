__int64 __fastcall wma_mgmt_unified_cmd_send(
        __int64 a1,
        __int64 a2,
        __int16 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 **context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 **v25; // x22
  __int64 *v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 *v35; // x21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w19
  const char *v45; // x2
  __int64 v46; // x8
  __int64 (__fastcall *v47)(__int64 **, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v48; // x1
  __int64 v49; // x3
  __int64 v50; // x4
  __int64 v51; // x5
  __int64 v52; // x0

  context = (__int64 **)_cds_get_context(71, (__int64)"wma_mgmt_unified_cmd_send", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !a4 )
  {
    v44 = 4;
    v45 = "%s: mgmt_params ptr passed is NULL";
LABEL_21:
    qdf_trace_msg(0x36u, 2u, v45, v17, v18, v19, v20, v21, v22, v23, v24, "wma_mgmt_unified_cmd_send");
    return v44;
  }
  *(_WORD *)(a4 + 14) = a3;
  if ( !a1 )
  {
    v44 = 4;
    v45 = "%s: vdev ptr passed is NULL";
    goto LABEL_21;
  }
  v25 = context;
  v26 = _cds_get_context(54, (__int64)"wma_mgmt_unified_cmd_send", v17, v18, v19, v20, v21, v22, v23, v24);
  if ( !v26 )
    return 4;
  v35 = v26;
  if ( (wmi_service_enabled(*v26, 0x5Bu, v27, v28, v29, v30, v31, v32, v33, v34) & 1) != 0 )
  {
    v44 = wmi_mgmt_unified_cmd_send(*v35);
    if ( !v44 )
      return v44;
    goto LABEL_20;
  }
  *(_WORD *)(a2 + 58) = *(_WORD *)(a4 + 14);
  if ( !v25 || !*v25 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v36, v37, v38, v39, v40, v41, v42, v43, "cdp_mgmt_send_ext");
LABEL_18:
    v52 = 0;
    goto LABEL_19;
  }
  v46 = **v25;
  if ( !v46 )
    goto LABEL_18;
  v47 = *(__int64 (__fastcall **)(__int64 **, __int64, __int64, __int64, __int64, __int64))(v46 + 288);
  if ( !v47 )
    goto LABEL_18;
  v48 = *(unsigned __int8 *)(a4 + 10);
  v49 = *(unsigned __int8 *)(a4 + 11);
  v50 = *(unsigned __int8 *)(a4 + 49);
  v51 = *(unsigned __int16 *)(a4 + 12);
  if ( *((_DWORD *)v47 - 1) != -72516355 )
    __break(0x8228u);
  v52 = v47(v25, v48, a2, v49, v50, v51);
LABEL_19:
  v44 = qdf_status_from_os_return(v52);
  if ( v44 )
  {
LABEL_20:
    v45 = "%s: mgmt tx failed";
    goto LABEL_21;
  }
  return v44;
}
