__int64 __fastcall cm_disconnect_complete(_QWORD *a1, unsigned int *a2)
{
  unsigned int v2; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x1
  char v14; // w8

  v2 = *a2;
  if ( cm_get_req_by_cm_id_fl(a1, *a2, "cm_disconnect_complete", 595) )
  {
    cm_notify_disconnect_complete(a1, a2);
    if ( (v2 & 0x10000000) == 0 && *a2 == *((_DWORD *)a1 + 22) )
      cm_flush_pending_request(a1, 218103808, 0);
    cm_remove_cmd(a1, a2);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: disconnect count %d connect count %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "cm_disconnect_complete",
      *(unsigned __int8 *)(*a1 + 104LL),
      *a2,
      *((unsigned __int8 *)a1 + 184),
      *((unsigned __int8 *)a1 + 185));
    v14 = *((_BYTE *)a1 + 184);
    if ( v14 )
      goto LABEL_6;
    if ( (v2 & 0x10000000) == 0 && *((_BYTE *)a1 + 185) )
    {
      cm_flush_pending_request(a1, 201326592, 1);
      v14 = *((_BYTE *)a1 + 184) != 0;
    }
    if ( (v2 & 0x10000000) != 0 || (v14 & 1) != 0 )
    {
LABEL_6:
      if ( (v2 & 0x10000000) != 0 )
        cm_reset_active_cm_id(*a1, *a2);
    }
    else
    {
      qdf_event_set((__int64)(a1 + 26), v13);
    }
  }
  return 0;
}
