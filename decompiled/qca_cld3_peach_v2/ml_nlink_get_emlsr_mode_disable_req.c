__int64 __fastcall ml_nlink_get_emlsr_mode_disable_req(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  unsigned int v3; // w19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v2 = *(_QWORD *)(a2 + 1360);
  if ( v2 && *(_QWORD *)(v2 + 2224) )
  {
    qdf_mutex_acquire(v2 + 1656);
    v3 = *(_DWORD *)(*(_QWORD *)(v2 + 2224) + 1448LL);
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: disable_req 0x%x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ml_nlink_get_emlsr_mode_disable_req",
      v3);
    qdf_mutex_release(v2 + 1656);
  }
  else
  {
    return 0;
  }
  return v3;
}
