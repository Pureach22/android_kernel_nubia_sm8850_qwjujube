__int64 __fastcall tx_main_timer_func(__int64 result)
{
  __int64 (__fastcall *v1)(__int64, __int64); // x8
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 v5; // x1
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  if ( result )
  {
    v1 = *(__int64 (__fastcall **)(__int64, __int64))(result + 64);
    v2 = result;
    if ( v1 )
    {
      v3 = *(_QWORD *)(result + 256);
      v4 = *(unsigned int *)(v2 + 52);
      if ( *((_DWORD *)v1 - 1) != -1783303382 )
        __break(0x8228u);
      result = v1(v3, v4);
      v5 = *(_QWORD *)(v2 + 80);
      if ( v5 )
      {
        result = qdf_mc_timer_start(v2 + 88, v5);
        *(_QWORD *)(v2 + 80) = 0;
        if ( (_DWORD)result )
          return qdf_trace_msg(
                   0x37u,
                   3u,
                   "Unable to reschedule timer %s; status=%d",
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   v2,
                   (unsigned int)result);
      }
    }
  }
  return result;
}
