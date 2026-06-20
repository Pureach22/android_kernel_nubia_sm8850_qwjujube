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

  result = qdf_mutex_acquire((__int64)(a1 + 1606));
  if ( !(_DWORD)result )
  {
    a1[1819] = 0;
    a1[1818] = 0;
    a1[1817] = 0;
    a1[1816] = 0;
    a1[1815] = 0;
    a1[1814] = 0;
    a1[1813] = 0;
    qdf_mutex_release((__int64)(a1 + 1606));
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
