__int64 __fastcall policy_mgr_init_connection_update(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  result = qdf_event_create((_DWORD *)(a1 + 16));
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: init event failed",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "policy_mgr_init_connection_update");
    return 16;
  }
  return result;
}
