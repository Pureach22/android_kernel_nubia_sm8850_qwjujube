__int64 __fastcall csr_process_sap_response(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
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
  unsigned int v13; // w20
  __int64 active_cmd; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x24
  __int64 v27; // x0
  unsigned int v28; // w19
  __int64 v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v48; // x2
  __int64 v49; // x4

  if ( a2 >= 4 )
  {
    v48 = "%s: Invalid command to be dequeued %d";
    v49 = 34;
    return qdf_trace_msg(0x34u, 2u, v48, a5, a6, a7, a8, a9, a10, a11, a12, "csr_process_sap_response", v49);
  }
  v13 = dword_B35958[a2];
  active_cmd = wlan_serialization_get_active_cmd(*(_QWORD *)(a1 + 21624), a4, v13, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( active_cmd )
  {
    v26 = active_cmd;
    csr_process_sap_results(a1, a3, a2, a4);
    v27 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            *(_QWORD *)(a1 + 21624),
            a4,
            7);
    if ( v27 )
    {
      v28 = *(_DWORD *)(v26 + 4);
      v29 = v27;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Dequeue cmd id : %d type : %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "csr_process_sap_response",
        v28,
        v13);
      wlan_vdev_mlme_ser_remove_request(v29, v28, v13, v30, v31, v32, v33, v34, v35, v36, v37);
      return wlan_objmgr_vdev_release_ref(v29, 7u, v38, v39, v40, v41, v42, v43, v44, v45, v46);
    }
    v48 = "%s: vdev not found for vdev id: %d";
    v49 = (unsigned __int8)a4;
    return qdf_trace_msg(0x34u, 2u, v48, a5, a6, a7, a8, a9, a10, a11, a12, "csr_process_sap_response", v49);
  }
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: No active command for response from LIM for cmd: %d vdev: %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "csr_process_sap_response",
    v13,
    (unsigned __int8)a4);
  return csr_process_sap_results(a1, a3, a2, a4);
}
