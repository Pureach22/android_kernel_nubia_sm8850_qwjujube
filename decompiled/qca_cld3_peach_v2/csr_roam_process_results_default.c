__int64 __fastcall csr_roam_process_results_default(
        unsigned int *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 v11; // x8
  int opmode_from_vdev_id; // w22
  __int64 result; // x0
  __int64 v16; // x20
  unsigned int *v17; // x8
  __int64 v18; // x23
  __int64 v19; // x0
  int v20; // w0
  __int64 v21; // x9
  unsigned int *v22; // x25
  const char *v23; // x23
  const char *v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x22
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  char v50; // w9
  __int64 v51; // x9
  _DWORD *v52; // x8
  __int64 v53; // x0
  unsigned int *v54; // x23
  const char *v55; // x22
  const char *v56; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7

  v10 = *(unsigned int *)(a2 + 24);
  if ( !a1 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Invalid session id %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "csr_roam_process_results_default",
             (unsigned int)v10);
  if ( (unsigned int)v10 > 5 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Invalid session id %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "csr_roam_process_results_default",
             (unsigned int)v10);
  v11 = *((_QWORD *)a1 + 2162);
  if ( !v11 || (*(_BYTE *)(v11 + 96LL * (unsigned int)v10 + 1) & 1) == 0 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Invalid session id %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "csr_roam_process_results_default",
             (unsigned int)v10);
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*((_QWORD *)a1 + 2704), v10);
  result = _qdf_mem_malloc(0x180u, "csr_roam_process_results_default", 2807);
  if ( result )
  {
    v16 = result;
    v17 = a1;
    if ( a1[v10 + 4317] == 3 )
    {
      v18 = *((_QWORD *)a1 + 2162) + 96LL * (unsigned int)v10;
      v19 = *(_QWORD *)(v18 + 32);
      if ( v19 )
      {
        _qdf_mem_free(v19);
        v17 = a1;
        *(_QWORD *)(v18 + 32) = 0;
      }
      *(_DWORD *)(v18 + 24) = 0;
      *(_QWORD *)(v18 + 8) = 0;
      *(_QWORD *)(v18 + 16) = 0;
      v20 = csr_translate_to_wni_cfg_dot11_mode(a1, v17[4301]);
      v17 = a1;
      *(_DWORD *)(*((_QWORD *)a1 + 1) + 5964LL) = v20;
    }
    if ( (unsigned int)(*(_DWORD *)(a2 + 32) - 1) > 1 )
    {
      v54 = v17 + 4311;
      if ( v17[v10 + 4311] != 1 )
      {
        v55 = mac_trace_getcsr_roam_state(1u);
        v56 = mac_trace_getcsr_roam_state(v54[v10]);
        qdf_trace_msg(
          0x34u,
          8u,
          "CSR RoamState[%d]: [ %s <== %s ]",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          (unsigned int)v10,
          v55,
          v56);
        if ( v54[v10] == 2 )
          csr_roam_substate_change((__int64)a1, 0, v10, v65, v66, v67, v68, v69, v70, v71, v72);
        v54[v10] = 1;
      }
    }
    else
    {
      v21 = a2;
      *(_DWORD *)(v16 + 304) = v17[5418];
      *(_DWORD *)(v16 + 308) = v17[5419];
      *(_DWORD *)(v16 + 312) = v17[5420];
      *(_DWORD *)(v16 + 320) = v17[5422];
      v22 = v17 + 4311;
      *(_DWORD *)(v16 + 324) = v17[5421];
      if ( v17[v10 + 4311] != 3 )
      {
        v23 = mac_trace_getcsr_roam_state(3u);
        v24 = mac_trace_getcsr_roam_state(v22[v10]);
        qdf_trace_msg(
          0x34u,
          8u,
          "CSR RoamState[%d]: [ %s <== %s ]",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          (unsigned int)v10,
          v23,
          v24);
        if ( v22[v10] == 2 )
          csr_roam_substate_change((__int64)a1, 0, v10, v33, v34, v35, v36, v37, v38, v39, v40);
        v21 = a2;
        v22[v10] = 3;
      }
      if ( (opmode_from_vdev_id & 0xFFFFFFFD) == 1 )
      {
        v41 = v21;
        qdf_mem_copy((void *)(v16 + 23), (const void *)(v21 + 36), 6u);
        *(_DWORD *)(v16 + 36) = 2;
        v50 = *(_DWORD *)(v41 + 48);
        *(_DWORD *)(v16 + 32) = 0;
        *(_BYTE *)(v16 + 40) = v50;
        v51 = *((_QWORD *)a1 + 2162);
        if ( v51 && (*(_BYTE *)(v51 + 96LL * (unsigned int)v10 + 1) & 1) != 0 )
        {
          wlan_get_operation_chan_freq_vdev_id(*((_QWORD *)a1 + 2704), v10);
          v52 = *((_DWORD **)a1 + 2755);
          if ( v52 )
          {
            v53 = *((_QWORD *)a1 + 2703);
            if ( *(v52 - 1) != 1469140685 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64))v52)(v53, (unsigned int)v10, v16, 12, 2);
          }
        }
        else
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Session ID: %d is not valid",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "csr_roam_call_callback",
            (unsigned int)v10);
        }
      }
    }
    return _qdf_mem_free(v16);
  }
  return result;
}
