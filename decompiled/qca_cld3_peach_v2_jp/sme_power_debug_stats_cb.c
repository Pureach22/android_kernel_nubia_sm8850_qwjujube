__int64 __fastcall sme_power_debug_stats_cb(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  void (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x1

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    v13 = *(void (__fastcall **)(__int64, __int64))(a1 + 12976);
    if ( v13 )
    {
      v14 = *(_QWORD *)(a1 + 12968);
      if ( *((_DWORD *)v13 - 1) != -1572389891 )
        __break(0x8228u);
      v13(a2, v14);
    }
    else
    {
      qdf_trace_msg(0x34u, 2u, "%s: Null hdd cb", v5, v6, v7, v8, v9, v10, v11, v12, "sme_power_debug_stats_cb");
    }
    *(_QWORD *)(a1 + 12976) = 0;
    *(_QWORD *)(a1 + 12968) = 0;
    return qdf_mutex_release(a1 + 12776);
  }
  return result;
}
