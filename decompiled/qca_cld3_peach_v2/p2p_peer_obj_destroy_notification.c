__int64 __fastcall p2p_peer_obj_destroy_notification(
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
  __int64 v9; // x20
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x19
  __int64 v22; // x5
  unsigned __int16 v23; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  if ( !a1 )
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: peer context passed is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_peer_obj_destroy_notification");
    return 4;
  }
  v9 = *(_QWORD *)(a1 + 96);
  if ( *(_DWORD *)(v9 + 16) != 3 )
    return 0;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(*(_QWORD *)(a1 + 96), 5u);
  v20 = *(_QWORD *)(v9 + 216);
  v21 = comp_private_obj;
  if ( !v20 )
  {
    v22 = 0;
LABEL_13:
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: p2p_vdev_obj:%pK psoc:%pK",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "p2p_peer_obj_destroy_notification",
      comp_private_obj,
      v22);
    return 4;
  }
  v22 = *(_QWORD *)(v20 + 80);
  if ( !comp_private_obj || !v22 )
    goto LABEL_13;
  if ( *(_DWORD *)(a1 + 68) == 4 && *(_DWORD *)(v9 + 16) == 3 )
  {
    v23 = *(_WORD *)(comp_private_obj + 18) - 1;
    *(_WORD *)(comp_private_obj + 18) = v23;
    if ( !v23 )
    {
      if ( (*(_BYTE *)(comp_private_obj + 16) & 1) != 0 )
      {
        v23 = 0;
      }
      else
      {
        *(_BYTE *)(comp_private_obj + 16) = (unsigned int)ucfg_p2p_set_noa(v22, *(unsigned __int8 *)(v9 + 168), 0) == 0;
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: Non p2p peer disconnected from GO,NOA status: %d.",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "p2p_peer_obj_destroy_notification");
        v23 = *(_WORD *)(v21 + 18);
      }
    }
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: Non P2P peer count: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "p2p_peer_obj_destroy_notification",
      v23);
  }
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: p2p peer object destroy successful",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "p2p_peer_obj_destroy_notification");
  return 0;
}
