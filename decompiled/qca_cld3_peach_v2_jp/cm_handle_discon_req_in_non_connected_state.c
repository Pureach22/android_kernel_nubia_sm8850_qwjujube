__int64 __fastcall cm_handle_discon_req_in_non_connected_state(_BYTE *a1, unsigned int *a2, int a3)
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
  _BYTE *v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x8
  unsigned int cm_id; // w0
  __int64 v26; // x2

  state = cm_get_state(a1);
  v15 = *(_QWORD *)a1;
  v16 = a2[2];
  v17 = *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL);
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
  if ( a3 > 6 )
  {
    if ( a3 <= 8 )
    {
      if ( a3 != 7 )
      {
        cm_vdev_scan_cancel(*(_QWORD *)(v15 + 152));
        v15 = *(_QWORD *)a1;
      }
      mlme_cm_osif_update_id_and_src(v15, 21, 0xFFFFFFFFLL);
      cm_flush_pending_request(a1, 201326592, 0);
      v21 = a1;
      v22 = 218103808;
LABEL_13:
      v23 = 0;
      goto LABEL_14;
    }
    if ( a3 == 9 || a3 == 14 )
      goto LABEL_29;
    goto LABEL_23;
  }
  if ( !a3 )
  {
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
  }
  if ( a3 != 3 )
  {
    if ( a3 == 4 )
    {
      v24 = *(_QWORD *)(v15 + 152);
      if ( v24 )
      {
        if ( (cm_roam_offload_enabled(*(_QWORD *)(v24 + 80)) & 1) == 0 )
          goto LABEL_29;
      }
      else if ( (cm_roam_offload_enabled(0) & 1) == 0 )
      {
        goto LABEL_29;
      }
      v21 = a1;
      v22 = 251658240;
      goto LABEL_13;
    }
LABEL_23:
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
  mlme_cm_osif_update_id_and_src(*(_QWORD *)a1, 21, 0xFFFFFFFFLL);
  cm_flush_pending_request(a1, 218103808, 0);
  if ( !a1[185] )
    goto LABEL_29;
  v21 = a1;
  v22 = 201326592;
  v23 = 1;
LABEL_14:
  cm_flush_pending_request(v21, v22, v23);
LABEL_29:
  cm_id = cm_get_cm_id(a1, a2[2]);
  v26 = a2[2];
  *a2 = cm_id;
  *(a2 - 2) = cm_id;
  return cm_add_req_to_list_and_indicate_osif(a1, a2 - 6, v26);
}
