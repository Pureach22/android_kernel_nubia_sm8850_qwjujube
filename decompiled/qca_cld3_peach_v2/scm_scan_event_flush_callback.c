__int64 __fastcall scm_scan_event_flush_callback(
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
  __int64 v9; // x19
  __int64 v10; // x20
  unsigned int *v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v21; // [xsp+0h] [xbp-10h]
  int v22; // [xsp+8h] [xbp-8h]

  if ( a1 && (v9 = *(_QWORD *)(a1 + 8)) != 0 )
  {
    v10 = *(_QWORD *)v9;
    v22 = *(_DWORD *)(v9 + 28);
    v21 = *(_DWORD *)(v9 + 24);
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: Flush scan event vdev %d type %d reason %d freq: %d req %d scanid %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "scm_scan_event_flush_callback",
      *(unsigned int *)(v9 + 8),
      *(unsigned int *)(v9 + 12),
      *(unsigned int *)(v9 + 16),
      *(unsigned int *)(v9 + 20),
      v21,
      v22);
    _qdf_mem_free(v9);
    wlan_objmgr_vdev_release_ref(v10, 0xCu, v11, v12, v13, v14, v15, v16, v17, v18, v19);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: msg or msg->bodyptr is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "scm_scan_event_flush_callback");
    return 29;
  }
}
