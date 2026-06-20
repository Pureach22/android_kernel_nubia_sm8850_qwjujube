__int64 __fastcall cluster_power_down(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x21
  __int64 v3; // x9
  __int64 cpus_qos; // x0
  int v6; // w8
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 result; // x0
  int v10; // w20
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  int v14; // w8

  v1 = *(_QWORD *)(a1 + 160);
  v2 = *(unsigned int *)(v1 + 1460);
  if ( (v2 & 0x80000000) != 0 )
    return 0;
  v3 = *(_QWORD *)(a1 + 360);
  *(_DWORD *)(a1 + 16) = v2;
  *(_QWORD *)(a1 + 328) = v3;
  cpus_qos = get_cpus_qos(*(_QWORD *)(a1 + 160) + 1328LL);
  v6 = *(_DWORD *)(v1 + 1456);
  if ( !v6 )
  {
LABEL_8:
    if ( *(_BYTE *)(a1 + 409) != 1 )
      goto LABEL_11;
    v10 = _sw_hweight64(_cpu_possible_mask);
    if ( v10 == (unsigned int)_sw_hweight64(*(unsigned int *)(*(_QWORD *)(a1 + 160) + 1328LL)) )
    {
      v6 = *(_DWORD *)(v1 + 1456);
LABEL_11:
      if ( ((_DWORD)v2 != v6 - 1 || *(_DWORD *)(a1 + 20) != -1) && *(_BYTE *)(a1 + 404) == 1 )
      {
        v11 = *(_QWORD *)(a1 + 352);
        if ( v11 == 0x7FFFFFFFFFFFFFFFLL || *(_QWORD *)(a1 + 336) >= v11 )
        {
          if ( (*(_BYTE *)(a1 + 406) & 1) == 0 && _hrtimer_get_remaining(a1 + 264, 0) >= 1000 )
            hrtimer_try_to_cancel(a1 + 264);
          if ( (_DWORD)v2 == *(_DWORD *)(v1 + 1456) - 1 )
            v12 = v2;
          else
            v12 = (int)v2 + 1;
          v13 = *(unsigned int *)(*(_QWORD *)(v1 + 1440) + (v12 << 6) + 16);
          *(_QWORD *)(a1 + 304) = clusttimer_fn;
          hrtimer_start_range_ns(a1 + 264, v13 + 100000, 0, 3);
          *(_BYTE *)(a1 + 406) = 0;
          return 0;
        }
      }
      return 0;
    }
    if ( *(_BYTE *)(a1 + 406) == 1 )
    {
      if ( (*(_BYTE *)(a1 + 407) & 1) != 0 )
      {
LABEL_20:
        *(_BYTE *)(a1 + 408) = 1;
        return 0xFFFFFFFFLL;
      }
      v14 = *(unsigned __int8 *)(a1 + 408);
      result = 0;
      *(_BYTE *)(a1 + 13) = 0;
      *(_BYTE *)(a1 + 406) = 0;
      if ( v14 != 1 )
        return result;
      *(_BYTE *)(a1 + 408) = 0;
      clusttimer_cancel(a1);
    }
    else
    {
      if ( (*(_BYTE *)(a1 + 407) & 1) != 0 )
        goto LABEL_20;
      *(_BYTE *)(a1 + 408) = 0;
      if ( _hrtimer_get_remaining(a1 + 264, 0) >= 1000 )
        hrtimer_try_to_cancel(a1 + 264);
    }
    *(_QWORD *)(a1 + 304) = clusttimer_fn;
    hrtimer_start_range_ns(a1 + 264, 10000000, 0, 3);
    *(_BYTE *)(a1 + 407) = 1;
    return 0xFFFFFFFFLL;
  }
  v7 = *(unsigned int *)(v1 + 1456);
  v8 = v2;
  while ( v8 || cpus_qos >= *(_QWORD *)(*(_QWORD *)(v1 + 1440) + (v2 << 6) + 8) )
  {
    --v7;
    --v8;
    if ( !v7 )
      goto LABEL_8;
  }
  return 0xFFFFFFFFLL;
}
