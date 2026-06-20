__int64 __fastcall account_yields(__int64 result)
{
  unsigned __int64 v1; // x9
  unsigned __int64 v2; // x7
  unsigned __int64 v3; // x5
  char v4; // w3
  char v5; // w16
  unsigned __int64 v6; // x16
  unsigned __int64 v7; // x16
  _BYTE *v8; // x17
  unsigned __int64 v9; // x1
  unsigned __int64 v10; // x17
  bool v11; // cc

  v1 = result - account_yields_yield_counting_window_ts;
  if ( (unsigned __int64)(result - account_yields_yield_counting_window_ts) >= 0xD59F81 )
  {
    if ( v1 >= 0x112A881 )
    {
      v2 = 4 * v1 / 0xD59F80;
      v3 = 500 * v1 / 0xD59F80;
    }
    else
    {
      LODWORD(v2) = 4;
      LODWORD(v3) = 500;
    }
    if ( !sysctl_force_frequent_yielder )
    {
      v5 = 0;
      do
      {
        v6 = *(unsigned int *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1)) & (unsigned __int64)(-1LL << v5);
        if ( !v6 )
          break;
        v7 = __clz(__rbit64(v6));
        v8 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v7)];
        v9 = *((_QWORD *)v8 + 5);
        v10 = *((_QWORD *)v8 + 79);
        if ( v9 < v10 )
          v10 = v9;
        if ( v10 > 0xC8 )
          goto LABEL_17;
        v11 = v7 > 0x1E;
        v5 = v7 + 1;
      }
      while ( !v11 );
    }
    if ( total_yield_cnt < (unsigned int)v3 && total_sleep_cnt < (unsigned int)v2 >> 1 )
    {
LABEL_17:
      v4 = 0;
    }
    else
    {
      if ( (unsigned __int8)contiguous_yielding_windows > 1u )
      {
LABEL_19:
        account_yields_yield_counting_window_ts = result;
        total_yield_cnt = 0;
        total_sleep_cnt = 0;
        return result;
      }
      v4 = contiguous_yielding_windows + 1;
    }
    contiguous_yielding_windows = v4;
    goto LABEL_19;
  }
  return result;
}
