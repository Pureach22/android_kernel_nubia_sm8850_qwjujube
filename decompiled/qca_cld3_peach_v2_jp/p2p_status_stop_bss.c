__int64 __fastcall p2p_status_stop_bss(
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
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  if ( !a1 )
  {
    v22 = "%s: vdev context passed is NULL";
    goto LABEL_10;
  }
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v22 = "%s: soc context is NULL";
LABEL_10:
    qdf_trace_msg(0x4Eu, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "get_p2p_soc_obj_by_vdev");
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: P2P soc context is NULL",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "p2p_status_stop_bss");
    return 16;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v10, 5u);
  if ( !comp_private_obj )
  {
    v22 = "%s: P2P soc context is NULL";
    goto LABEL_10;
  }
  if ( *(_DWORD *)(a1 + 16) == 3 )
  {
    v13 = comp_private_obj;
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
      "p2p_status_stop_bss",
      *(unsigned int *)(comp_private_obj + 276));
    if ( *(_DWORD *)(v13 + 276) == 4 )
    {
      *(_DWORD *)(v13 + 276) = 0;
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: [P2P State] From GO completed to Inactive state GO got removed",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "p2p_status_stop_bss");
    }
  }
  else
  {
    qdf_trace_msg(0x4Eu, 8u, "%s: this is not P2P GO, mode:%d", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_status_stop_bss");
  }
  return 0;
}
