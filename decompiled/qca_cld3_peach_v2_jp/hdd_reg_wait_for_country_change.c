__int64 __fastcall hdd_reg_wait_for_country_change(__int64 a1)
{
  int v2; // w22
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  qdf_mutex_acquire(a1 + 6968);
  v2 = *(unsigned __int8 *)(a1 + 6924);
  result = qdf_mutex_release(a1 + 6968);
  if ( v2 == 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: waiting for channel list to update",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_reg_wait_for_country_change");
    qdf_wait_for_event_completion(a1 + 6928, 0x1194u);
    qdf_mutex_acquire(a1 + 6968);
    *(_BYTE *)(a1 + 6924) = 0;
    return qdf_mutex_release(a1 + 6968);
  }
  return result;
}
