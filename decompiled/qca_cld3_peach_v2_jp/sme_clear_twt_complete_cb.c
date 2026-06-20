__int64 __fastcall sme_clear_twt_complete_cb(_QWORD *a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  result = qdf_mutex_acquire((__int64)(a1 + 1597));
  if ( !(_DWORD)result )
  {
    a1[1810] = 0;
    a1[1809] = 0;
    a1[1808] = 0;
    a1[1807] = 0;
    a1[1806] = 0;
    a1[1805] = 0;
    a1[1804] = 0;
    qdf_mutex_release((__int64)(a1 + 1597));
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: TWT: callbacks Initialized",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "sme_clear_twt_complete_cb");
    return 0;
  }
  return result;
}
