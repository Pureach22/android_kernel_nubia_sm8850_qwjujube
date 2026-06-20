__int64 __fastcall lim_process_abort_scan_ind(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  __int64 v26; // x0
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  qdf_trace_msg(
    0x35u,
    8u,
    "%s: scan_id %d, scan_requestor_id 0x%x",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_process_abort_scan_ind",
    a3,
    a4);
  v16 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21624),
          a2,
          7);
  if ( !v16 )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: vdev is NULL",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "lim_process_abort_scan_ind");
  v25 = v16;
  v26 = _qdf_mem_malloc(0x20u, "lim_process_abort_scan_ind", 1667);
  if ( v26 )
  {
    *(_QWORD *)v26 = v25;
    *(_DWORD *)(v26 + 12) = a4;
    *(_DWORD *)(v26 + 16) = a3;
    *(_DWORD *)(v26 + 20) = 1;
    *(_DWORD *)(v26 + 24) = (unsigned __int8)a2;
    if ( (unsigned int)wlan_scan_cancel((__int64 *)v26, v28, v29, v30, v31, v32, v33, v34, v35) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Cancel scan request failed",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "lim_process_abort_scan_ind");
  }
  return wlan_objmgr_vdev_release_ref(v25, 7u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
}
