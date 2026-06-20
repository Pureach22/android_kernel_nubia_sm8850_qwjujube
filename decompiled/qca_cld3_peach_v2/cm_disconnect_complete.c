__int64 __fastcall cm_disconnect_complete(_QWORD *a1, unsigned int *a2)
{
  unsigned int v2; // w21
  unsigned int v5; // w8
  unsigned int v6; // w22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x1
  char v24; // w8
  double v25; // d0

  v2 = *a2;
  if ( !cm_get_req_by_cm_id_fl(a1, *a2, "cm_disconnect_complete", 595) )
    return 0;
  cm_notify_disconnect_complete(a1, a2);
  v5 = *((unsigned __int8 *)a1 + 184);
  if ( v5 > 1 || *((_BYTE *)a1 + 185) )
  {
    if ( (v2 & 0x10000000) != 0 )
      v6 = 10;
    else
      v6 = 0;
    if ( (v2 & 0x10000000) == 0 )
    {
LABEL_8:
      if ( *a2 == *((_DWORD *)a1 + 22) )
      {
        cm_flush_pending_request(a1, 218103808, 0);
        v5 = *((unsigned __int8 *)a1 + 184);
      }
    }
  }
  else
  {
    v6 = 0;
    if ( (v2 & 0x10000000) == 0 )
      goto LABEL_8;
  }
  if ( (v2 & 0x10000000) == 0 && v5 == 1 && (wlan_cm_check_mlo_roam_auth_status(*a1) & 1) == 0 )
    wlan_vdev_mlme_clear_mlo_vdev(*a1, v7, v8, v9, v10, v11, v12, v13, v14);
  cm_remove_cmd(a1, a2);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: disconnect count %d connect count %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "cm_disconnect_complete",
    *(unsigned __int8 *)(*a1 + 168LL),
    *a2,
    *((unsigned __int8 *)a1 + 184),
    *((unsigned __int8 *)a1 + 185));
  v24 = *((_BYTE *)a1 + 184);
  if ( v24 )
    goto LABEL_15;
  if ( (v2 & 0x10000000) == 0 && *((_BYTE *)a1 + 185) )
  {
    cm_flush_pending_request(a1, 201326592, 1);
    v24 = *((_BYTE *)a1 + 184) != 0;
  }
  if ( (v2 & 0x10000000) != 0 || (v24 & 1) != 0 )
  {
LABEL_15:
    if ( (v2 & 0x10000000) != 0 )
    {
      v25 = cm_reset_active_cm_id(*a1, *a2);
      mlo_mgr_link_switch_disconnect_done(*a1, v6, 1, v25);
    }
  }
  else
  {
    qdf_event_set((__int64)(a1 + 26), v23);
  }
  return 0;
}
