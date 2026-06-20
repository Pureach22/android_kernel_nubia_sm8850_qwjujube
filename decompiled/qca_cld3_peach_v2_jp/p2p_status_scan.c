__int64 __fastcall p2p_status_scan(
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
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 comp_private_obj; // x0
  int v13; // w4
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  const char *v33; // x2
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  if ( !a1 )
  {
    v33 = "%s: vdev context passed is NULL";
    goto LABEL_11;
  }
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v33 = "%s: soc context is NULL";
LABEL_11:
    qdf_trace_msg(0x4Eu, 2u, v33, a2, a3, a4, a5, a6, a7, a8, a9, "get_p2p_soc_obj_by_vdev");
    qdf_trace_msg(0x4Eu, 2u, "%s: P2P soc context is NULL", v34, v35, v36, v37, v38, v39, v40, v41, "p2p_status_scan");
    return 16;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v10, 5u);
  if ( !comp_private_obj )
  {
    v33 = "%s: P2P soc context is NULL";
    goto LABEL_11;
  }
  v13 = *(_DWORD *)(a1 + 16);
  v14 = comp_private_obj;
  if ( v13 != 2 && v13 != 7 )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: this is not P2P CLIENT or DEVICE, mode:%d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_status_scan");
    return 0;
  }
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: connection status:%d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_status_scan",
    *(unsigned int *)(comp_private_obj + 276));
  v23 = *(_DWORD *)(v14 + 276);
  if ( (unsigned int)(v23 - 1) < 2 )
  {
    *(_DWORD *)(v14 + 276) = 3;
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: [P2P State] Changing state from Go nego completed to Connection is started",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "p2p_status_scan");
    v32 = "%s: P2P Scanning is started for 8way Handshake";
LABEL_15:
    qdf_trace_msg(0x4Eu, 8u, v32, v24, v25, v26, v27, v28, v29, v30, v31, "p2p_status_scan");
    return 0;
  }
  if ( v23 == 6 )
  {
    *(_DWORD *)(v14 + 276) = 7;
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: [P2P State] Changing state from Disconnected state to Connection is started",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "p2p_status_scan");
    v32 = "%s: P2P Scanning is started for 4way Handshake";
    goto LABEL_15;
  }
  return 0;
}
