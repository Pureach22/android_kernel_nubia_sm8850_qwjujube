__int64 __fastcall policy_mgr_is_any_conn_in_transition(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned __int64 v11; // x20
  _BYTE *v12; // x28
  char v13; // w27
  bool v14; // cf
  unsigned int v15; // w23
  _QWORD *vdev_by_id_from_pdev; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x25
  bool is_vdev_connected; // w24
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  char is_link_switch_in_progress; // w26
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x2

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid pm context",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "policy_mgr_is_any_conn_in_transition");
    v13 = 0;
    return v13 & 1;
  }
  v10 = context;
  qdf_mutex_acquire(context + 56);
  v11 = 0;
  v12 = (char *)&qword_8D4F00 + 4;
  v13 = 1;
  while ( 1 )
  {
    if ( *v12 != 1 || (*((_DWORD *)v12 - 7) | 2) != 2 )
      goto LABEL_4;
    v15 = (unsigned __int8)*(v12 - 4);
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(v10 + 8), *(v12 - 4), 0x18u);
    if ( !vdev_by_id_from_pdev )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: vdev %d: not found",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "policy_mgr_is_any_conn_in_transition",
        v15);
      goto LABEL_4;
    }
    v25 = (__int64)vdev_by_id_from_pdev;
    is_vdev_connected = wlan_cm_is_vdev_connected((__int64)vdev_by_id_from_pdev, v17, v18, v19, v20, v21, v22, v23, v24);
    if ( (mlo_is_mld_sta(v25) & 1) != 0 )
      break;
    wlan_objmgr_vdev_release_ref(v25, 0x18u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
    if ( !is_vdev_connected )
    {
      v54 = "%s: vdev %d: is in transition state";
      goto LABEL_20;
    }
LABEL_4:
    v14 = v11++ >= 4;
    v12 += 36;
    v13 = !v14;
    if ( v11 == 5 )
      goto LABEL_21;
  }
  is_link_switch_in_progress = mlo_mgr_is_link_switch_in_progress(v25);
  wlan_objmgr_vdev_release_ref(v25, 0x18u, v37, v38, v39, v40, v41, v42, v43, v44, v45);
  if ( is_vdev_connected && (is_link_switch_in_progress & 1) == 0 )
    goto LABEL_4;
  v54 = "%s: vdev %d: is in transition state";
  if ( is_vdev_connected )
    v54 = "%s: vdev %d: sta mld is in link switch state";
LABEL_20:
  qdf_trace_msg(0x4Fu, 8u, v54, v46, v47, v48, v49, v50, v51, v52, v53, "policy_mgr_is_any_conn_in_transition", v15);
LABEL_21:
  qdf_mutex_release(v10 + 56);
  return v13 & 1;
}
