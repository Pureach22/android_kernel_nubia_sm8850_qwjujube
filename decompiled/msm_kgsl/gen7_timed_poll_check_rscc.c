__int64 __fastcall gen7_timed_poll_check_rscc(__int64 a1, int a2, int a3, int a4, int a5)
{
  __int64 v9; // x24
  __int64 v10; // x23
  __int64 v11; // x0
  int v12; // w8
  __int64 v13; // x22

  v9 = (unsigned int)(4 * a2);
  v10 = ktime_get(a1);
  v11 = readl_1(*(_QWORD *)(a1 + 1104) + v9);
  v12 = v11 & a5;
  if ( ((unsigned int)v11 & a5) != a3 )
  {
    v13 = v10 + 1000LL * (unsigned int)(1000 * a4);
    while ( ktime_get(v11) <= v13 )
    {
      usleep_range_state(26, 100, 2);
      __yield();
      v11 = readl_1(*(_QWORD *)(a1 + 1104) + v9);
      if ( ((unsigned int)v11 & a5) == a3 )
      {
        v12 = a3;
        goto LABEL_7;
      }
    }
    v12 = readl_1(*(_QWORD *)(a1 + 1104) + v9) & a5;
  }
LABEL_7:
  if ( v12 == a3 )
    return 0;
  else
    return 4294967186LL;
}
