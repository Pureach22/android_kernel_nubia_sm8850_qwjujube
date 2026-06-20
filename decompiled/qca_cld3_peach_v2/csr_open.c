__int64 __fastcall csr_open(__int64 a1)
{
  __int64 v2; // x21
  int v3; // w8
  const char *v4; // x20
  const char *v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v14; // x20
  const char *v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x20
  const char *v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x20
  const char *v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x20
  const char *v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x20
  const char *v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 result; // x0
  unsigned int v65; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w19
  __int64 v75; // x0
  __int64 psoc_ext_obj_fl; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x20

  v2 = a1 + 0x4000;
  qdf_mem_set(&csr_roam_roam_session, 0x240u, 0);
  v3 = *(_DWORD *)(v2 + 860);
  *(_QWORD *)(a1 + 17296) = &csr_roam_roam_session;
  if ( v3 )
  {
    v4 = mac_trace_getcsr_roam_state(0);
    v5 = mac_trace_getcsr_roam_state(*(_DWORD *)(v2 + 860));
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v6, v7, v8, v9, v10, v11, v12, v13, 0, v4, v5);
    if ( *(_DWORD *)(v2 + 860) == 2 )
      csr_roam_substate_change(a1, 0, 0);
    *(_DWORD *)(v2 + 860) = 0;
  }
  if ( *(_DWORD *)(v2 + 864) )
  {
    v14 = mac_trace_getcsr_roam_state(0);
    v15 = mac_trace_getcsr_roam_state(*(_DWORD *)(v2 + 864));
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v16, v17, v18, v19, v20, v21, v22, v23, 1, v14, v15);
    if ( *(_DWORD *)(v2 + 864) == 2 )
      csr_roam_substate_change(a1, 0, 1);
    *(_DWORD *)(v2 + 864) = 0;
  }
  if ( *(_DWORD *)(v2 + 868) )
  {
    v24 = mac_trace_getcsr_roam_state(0);
    v25 = mac_trace_getcsr_roam_state(*(_DWORD *)(v2 + 868));
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v26, v27, v28, v29, v30, v31, v32, v33, 2, v24, v25);
    if ( *(_DWORD *)(v2 + 868) == 2 )
      csr_roam_substate_change(a1, 0, 2);
    *(_DWORD *)(v2 + 868) = 0;
  }
  if ( *(_DWORD *)(v2 + 872) )
  {
    v34 = mac_trace_getcsr_roam_state(0);
    v35 = mac_trace_getcsr_roam_state(*(_DWORD *)(v2 + 872));
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v36, v37, v38, v39, v40, v41, v42, v43, 3, v34, v35);
    if ( *(_DWORD *)(v2 + 872) == 2 )
      csr_roam_substate_change(a1, 0, 3);
    *(_DWORD *)(v2 + 872) = 0;
  }
  if ( *(_DWORD *)(v2 + 876) )
  {
    v44 = mac_trace_getcsr_roam_state(0);
    v45 = mac_trace_getcsr_roam_state(*(_DWORD *)(v2 + 876));
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v46, v47, v48, v49, v50, v51, v52, v53, 4, v44, v45);
    if ( *(_DWORD *)(v2 + 876) == 2 )
      csr_roam_substate_change(a1, 0, 4);
    *(_DWORD *)(v2 + 876) = 0;
  }
  if ( *(_DWORD *)(v2 + 880) )
  {
    v54 = mac_trace_getcsr_roam_state(0);
    v55 = mac_trace_getcsr_roam_state(*(_DWORD *)(v2 + 880));
    qdf_trace_msg(0x34u, 8u, "CSR RoamState[%d]: [ %s <== %s ]", v56, v57, v58, v59, v60, v61, v62, v63, 5, v54, v55);
    if ( *(_DWORD *)(v2 + 880) == 2 )
      csr_roam_substate_change(a1, 0, 5);
    *(_DWORD *)(v2 + 880) = 0;
  }
  *(_QWORD *)(v2 + 808) = 0x100000000LL;
  *(_QWORD *)(v2 + 824) = 40;
  *(_WORD *)(v2 + 832) = 257;
  *(_QWORD *)(v2 + 816) = 0x900000400LL;
  *(_DWORD *)(v2 + 840) = 2;
  result = csr_scan_open(a1);
  if ( !(_DWORD)result )
  {
    if ( a1 )
    {
      v65 = qdf_mc_timer_init(a1 + 17304, 0, (__int64)csr_packetdump_timer_handler, a1);
      if ( v65 )
      {
        v74 = v65;
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: cannot allocate memory for packetdump timer",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "csr_packetdump_timer_init");
        return v74;
      }
      else
      {
        v75 = *(_QWORD *)(a1 + 21624);
        *(_DWORD *)(v2 + 1088) = 0;
        psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v75);
        if ( psoc_ext_obj_fl )
        {
          v85 = psoc_ext_obj_fl;
          qdf_mc_timer_init(psoc_ext_obj_fl + 7664, 0, (__int64)csr_disconnect_stats_timer_cb, a1);
          *(_DWORD *)(v85 + 7660) = 0;
        }
        else
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: NULL mlme psoc object",
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            "csr_init_disconnect_stats_timer");
        }
        return 0;
      }
    }
    else
    {
      return 4294967274LL;
    }
  }
  return result;
}
