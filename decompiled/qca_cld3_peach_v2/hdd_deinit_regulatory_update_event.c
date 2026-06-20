__int64 __fastcall hdd_deinit_regulatory_update_event(__int64 a1, __int64 a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( (unsigned int)qdf_event_destroy(a1 + 6952, a2) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to destroy regulatory update event",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hdd_deinit_regulatory_update_event");
  result = qdf_mutex_destroy(a1 + 6992);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Failed to destroy regulatory status mutex",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "hdd_deinit_regulatory_update_event");
  return result;
}
