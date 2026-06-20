__int64 __fastcall cm_handle_rso_stop_rsp(__int64 a1, _DWORD *a2)
{
  __int64 cm_ctx_fl; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  cm_ctx_fl = cm_get_cm_ctx_fl(a1, "cm_handle_rso_stop_rsp", 506);
  if ( cm_ctx_fl )
  {
    if ( (*a2 & 0xF000000) == 0xD000000 && *(_DWORD *)(cm_ctx_fl + 88) == *a2 )
      return cm_sm_deliver_event(a1, 37, 24, a2);
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: active req is not disconnect req",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "cm_handle_rso_stop_rsp",
      *(unsigned __int8 *)(a1 + 168));
  }
  return 4;
}
