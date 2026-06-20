__int64 __fastcall cm_ser_connect_after_mode_change_resp(__int64 *a1, unsigned int *a2, int a3)
{
  __int64 req_by_cm_id_fl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 result; // x0
  int v16; // w2

  if ( !a2 )
    return 16;
  req_by_cm_id_fl = cm_get_req_by_cm_id_fl(a1, *a2, "cm_ser_connect_after_mode_change_resp", 395);
  if ( !req_by_cm_id_fl )
    return 4;
  v14 = req_by_cm_id_fl;
  if ( *(_QWORD *)(*a1 + 216) )
  {
    switch ( a3 )
    {
      case 38:
LABEL_7:
        result = cm_ser_connect_req(a1, req_by_cm_id_fl + 24);
        if ( !(_DWORD)result )
          return result;
        v16 = 12;
        return cm_send_connect_start_fail(a1, (unsigned int *)(v14 + 24), v16);
      case 5:
        v16 = 11;
        return cm_send_connect_start_fail(a1, (unsigned int *)(v14 + 24), v16);
      case 4:
        goto LABEL_7;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: Failed to find pdev",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "cm_ser_connect_after_mode_change_resp",
      *(unsigned __int8 *)(*a1 + 168),
      *(unsigned int *)(req_by_cm_id_fl + 16));
  }
  v16 = 14;
  return cm_send_connect_start_fail(a1, (unsigned int *)(v14 + 24), v16);
}
