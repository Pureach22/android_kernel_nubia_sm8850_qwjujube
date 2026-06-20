__int64 __fastcall cm_handle_discon_req_in_non_connected_state(__int64 *a1, unsigned int *a2, int a3)
{
  int state; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x1
  unsigned int v16; // w6
  __int64 v17; // x4
  __int64 v18; // x5
  const char *v19; // x2
  __int64 *v21; // x0
  __int64 v22; // x1
  __int64 v23; // x8
  double v24; // d0
  double updated; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int cm_id; // w0
  __int64 v34; // x2

  state = cm_get_state(a1);
  v15 = *a1;
  v16 = a2[2];
  v17 = *(unsigned __int8 *)(*a1 + 168);
  if ( state == 1 )
  {
    if ( v16 > 0xD || ((1 << v16) & 0x3020) == 0 )
    {
      v18 = *a2;
      v19 = "%s: vdev %d cm_id 0x%x: ignore disconnect req from source %d in state %d";
LABEL_7:
      qdf_trace_msg(
        0x68u,
        4u,
        v19,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "cm_handle_discon_req_in_non_connected_state",
        v17,
        v18);
      return 4;
    }
  }
  else if ( v16 == 18 )
  {
    v18 = *a2;
    v19 = "%s: vdev %d cm_id 0x%x: Ignore disconnect req from source %d state %d";
    goto LABEL_7;
  }
  if ( a3 <= 6 )
  {
    switch ( a3 )
    {
      case 0:
        qdf_trace_msg(
          0x68u,
          4u,
          "%s: vdev %d cm_id 0x%x: dropping disconnect req from source %d in INIT state",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "cm_handle_discon_req_in_non_connected_state",
          v17,
          *a2);
        return 6;
      case 3:
        updated = mlme_cm_osif_update_id_and_src(*a1, 21, 0xFFFFFFFFLL);
        if ( (wlan_vdev_mlme_is_mlo_vdev(*a1, updated, v26, v27, v28, v29, v30, v31, v32) & 1) == 0
          || (*(_BYTE *)(*a1 + 60) & 2) == 0 )
        {
          cm_flush_pending_request(a1, 218103808, 0);
        }
        if ( *((_BYTE *)a1 + 185) )
          cm_flush_pending_request(a1, 201326592, 1);
        goto LABEL_33;
      case 4:
        v23 = *(_QWORD *)(v15 + 216);
        if ( v23 )
        {
          if ( (cm_roam_offload_enabled(*(_QWORD *)(v23 + 80)) & 1) == 0 )
            goto LABEL_33;
        }
        else if ( (cm_roam_offload_enabled(0) & 1) == 0 )
        {
          goto LABEL_33;
        }
        v21 = a1;
        v22 = 251658240;
        goto LABEL_13;
    }
LABEL_25:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: disconnect req in invalid state %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "cm_handle_discon_req_in_non_connected_state",
      v17,
      *a2,
      (unsigned int)a3);
    return 16;
  }
  if ( a3 > 8 )
  {
    if ( a3 == 9 )
      goto LABEL_33;
    if ( a3 == 14 )
    {
      if ( (*(_BYTE *)(v15 + 67) & 2) != 0 )
      {
        qdf_trace_msg(
          0x68u,
          4u,
          "%s: vdev %d cm_id 0x%x: Notfiy MLO MGR to abort link switch",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "cm_handle_discon_req_in_non_connected_state",
          v17,
          *a2);
        mlo_mgr_link_switch_disconnect_done(*a1, 10, 0, v24);
      }
      goto LABEL_33;
    }
    goto LABEL_25;
  }
  if ( a3 != 7 )
  {
    cm_vdev_scan_cancel(*(_QWORD *)(v15 + 216));
    v15 = *a1;
  }
  mlme_cm_osif_update_id_and_src(v15, 21, 0xFFFFFFFFLL);
  cm_flush_pending_request(a1, 201326592, 0);
  v21 = a1;
  v22 = 218103808;
LABEL_13:
  cm_flush_pending_request(v21, v22, 0);
LABEL_33:
  cm_id = cm_get_cm_id(a1, a2[2]);
  v34 = a2[2];
  *a2 = cm_id;
  *(a2 - 2) = cm_id;
  return cm_add_req_to_list_and_indicate_osif(a1, a2 - 6, v34);
}
