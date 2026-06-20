__int64 __fastcall csr_start(
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
  _DWORD *v9; // x21
  const char *v11; // x20
  const char *v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x20
  const char *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x20
  const char *v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v41; // x20
  const char *v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  const char *v51; // x20
  const char *v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  const char *v61; // x20
  const char *v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x8
  __int64 result; // x0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w19

  v9 = (_DWORD *)(a1 + 0x4000);
  if ( *(_DWORD *)(a1 + 17172) != 1 )
  {
    v11 = mac_trace_getcsr_roam_state(1u);
    v12 = mac_trace_getcsr_roam_state(v9[197]);
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v13, v14, v15, v16, v17, v18, v19, v20, 0, v11, v12);
    if ( v9[197] == 2 )
      csr_roam_substate_change(a1, 0, 0);
    v9[197] = 1;
  }
  if ( v9[198] != 1 )
  {
    v21 = mac_trace_getcsr_roam_state(1u);
    v22 = mac_trace_getcsr_roam_state(v9[198]);
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v23, v24, v25, v26, v27, v28, v29, v30, 1, v21, v22);
    if ( v9[198] == 2 )
      csr_roam_substate_change(a1, 0, 1);
    v9[198] = 1;
  }
  if ( v9[199] != 1 )
  {
    v31 = mac_trace_getcsr_roam_state(1u);
    v32 = mac_trace_getcsr_roam_state(v9[199]);
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v33, v34, v35, v36, v37, v38, v39, v40, 2, v31, v32);
    if ( v9[199] == 2 )
      csr_roam_substate_change(a1, 0, 2);
    v9[199] = 1;
  }
  if ( v9[200] != 1 )
  {
    v41 = mac_trace_getcsr_roam_state(1u);
    v42 = mac_trace_getcsr_roam_state(v9[200]);
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v43, v44, v45, v46, v47, v48, v49, v50, 3, v41, v42);
    if ( v9[200] == 2 )
      csr_roam_substate_change(a1, 0, 3);
    v9[200] = 1;
  }
  if ( v9[201] != 1 )
  {
    v51 = mac_trace_getcsr_roam_state(1u);
    v52 = mac_trace_getcsr_roam_state(v9[201]);
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v53, v54, v55, v56, v57, v58, v59, v60, 4, v51, v52);
    if ( v9[201] == 2 )
      csr_roam_substate_change(a1, 0, 4);
    v9[201] = 1;
  }
  if ( v9[202] != 1 )
  {
    v61 = mac_trace_getcsr_roam_state(1u);
    v62 = mac_trace_getcsr_roam_state(v9[202]);
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v63, v64, v65, v66, v67, v68, v69, v70, 5, v61, v62);
    if ( v9[202] == 2 )
      csr_roam_substate_change(a1, 0, 5);
    v9[202] = 1;
  }
  v71 = *(_QWORD *)(a1 + 8);
  v9[209] = 0;
  result = 0;
  if ( *(_BYTE *)(v71 + 6384) == 1 )
  {
    result = ucfg_scan_register_event_handler(
               *(_QWORD *)(a1 + 21560),
               (__int64)csr_scan_event_handler,
               a1,
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9);
    if ( (_DWORD)result )
    {
      v81 = result;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: scan event registration failed ",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "csr_start");
      return v81;
    }
  }
  return result;
}
