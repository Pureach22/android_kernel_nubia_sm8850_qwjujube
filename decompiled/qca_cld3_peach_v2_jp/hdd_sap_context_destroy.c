__int64 __fastcall hdd_sap_context_destroy(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  if ( *(_DWORD *)(a1 + 1120) )
  {
    qdf_wake_lock_release(a1 + 920, 2u);
    *(_DWORD *)(a1 + 1120) = 0;
    qdf_trace_msg(0x33u, 8u, "%s: DFS: Allowing suspend", v2, v3, v4, v5, v6, v7, v8, v9, "hdd_sap_context_destroy");
  }
  _qdf_wake_lock_destroy(a1 + 920);
  return _qdf_wake_lock_destroy(a1 + 288);
}
