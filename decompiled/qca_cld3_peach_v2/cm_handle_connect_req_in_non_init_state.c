__int64 __fastcall cm_handle_connect_req_in_non_init_state(_BYTE *a1, unsigned int *a2, int a3)
{
  unsigned int v6; // w22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x5
  unsigned int v16; // w6
  unsigned int v17; // w19
  __int64 v18; // x8
  _BYTE *v19; // x0
  __int64 v20; // x2
  unsigned int cm_id; // w0
  __int64 v22; // x2

  v6 = *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL);
  if ( (cm_is_connect_req_reassoc(a2 + 2) & 1) != 0 )
  {
    v15 = *a2;
    *((_BYTE *)a2 + 192) |= 8u;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: Reassoc received in %d state",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "cm_handle_connect_req_in_non_init_state",
      v6,
      v15,
      (unsigned int)a3);
  }
  v16 = a2[3];
  if ( v16 != 17 && v16 != 15 )
  {
    if ( a3 > 6 )
    {
      if ( a3 != 7 )
      {
        if ( a3 != 8 )
        {
          if ( a3 == 9 )
            goto LABEL_24;
          goto LABEL_16;
        }
        cm_vdev_scan_cancel(*(_QWORD *)(*(_QWORD *)a1 + 216LL));
      }
      v19 = a1;
      v20 = 0;
    }
    else
    {
      if ( a3 == 2 )
        goto LABEL_24;
      if ( a3 != 3 )
      {
        if ( a3 == 4 )
        {
          v18 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
          if ( v18 )
          {
            if ( (cm_roam_offload_enabled(*(_QWORD *)(v18 + 80)) & 1) == 0 )
              goto LABEL_24;
            goto LABEL_23;
          }
          if ( (cm_roam_offload_enabled(0) & 1) != 0 )
LABEL_23:
            cm_flush_pending_request(a1, 251658240, 0);
LABEL_24:
          cm_initiate_internal_disconnect(a1);
          goto LABEL_25;
        }
LABEL_16:
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: Connect req in invalid state %d",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "cm_handle_connect_req_in_non_init_state",
          v6,
          *a2,
          (unsigned int)a3);
        return 16;
      }
      if ( !a1[185] )
      {
LABEL_25:
        cm_id = cm_get_cm_id(a1, a2[3]);
        v22 = a2[3];
        *a2 = cm_id;
        *(a2 - 2) = cm_id;
        return (unsigned int)cm_add_req_to_list_and_indicate_osif(a1, a2 - 6, v22);
      }
      v19 = a1;
      v20 = 1;
    }
    cm_flush_pending_request(v19, 201326592, v20);
    goto LABEL_25;
  }
  v17 = 4;
  qdf_trace_msg(
    0x68u,
    4u,
    "%s: vdev %d cm_id 0x%x: Ignore connect req from source %d state %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "cm_handle_connect_req_in_non_init_state",
    v6,
    *a2);
  return v17;
}
