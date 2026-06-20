__int64 __fastcall mlo_mgr_link_reject_set_mac_addr_resp(__int64 a1, unsigned __int8 a2)
{
  unsigned int v3; // w20
  __int64 mlo_ctx; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int8 *v22; // x21
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  __int64 v33; // x2
  __int64 v34; // x1
  __int64 v35; // x0
  __int64 (__fastcall *v36)(__int64, __int64, __int64); // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w20

  v3 = a2;
  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( v3 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: VDEV %d set MAC address response %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "mlo_mgr_link_reject_set_mac_addr_resp",
      *(unsigned __int8 *)(a1 + 168),
      v3);
    goto LABEL_3;
  }
  if ( !mlo_ctx )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: global mlo ctx NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "mlo_mgr_link_reject_set_mac_addr_resp");
    goto LABEL_3;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Dynamic vdev resp received",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "mlo_mgr_link_reject_set_mac_addr_resp");
  v22 = *(unsigned __int8 **)(*(_QWORD *)(a1 + 1360) + 3880LL);
  if ( v22[375] != 1 )
  {
LABEL_3:
    result = 4;
    goto LABEL_4;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Dynamic vdev update done for link reject",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "mlo_mgr_link_reject_set_mac_addr_resp");
  v23 = wlan_objmgr_get_mlo_ctx();
  if ( v23 )
  {
    v32 = *(_QWORD *)(v23 + 360);
    v33 = v22[360];
    v34 = v22[368];
    v35 = v22[361];
    v36 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v32 + 32);
    if ( *((_DWORD *)v36 - 1) != 612746675 )
      __break(0x8228u);
    result = v36(v35, v34, v33);
    if ( (_DWORD)result )
    {
      v45 = result;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: VDEV %d OSIF MAC addr update failed %d",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "mlo_mgr_update_link_rej_mac_addr_resp",
        v22[360],
        (unsigned int)result);
      result = v45;
    }
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: global mlo ctx NULL",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "mlo_mgr_update_link_rej_mac_addr_resp");
    result = 4;
  }
  v22[375] = 0;
LABEL_4:
  *(_DWORD *)(a1 + 64) &= ~0x4000000u;
  return result;
}
