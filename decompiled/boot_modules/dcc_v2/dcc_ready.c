__int64 __fastcall dcc_ready(_QWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  unsigned int v4; // w20

  v2 = ktime_get();
  if ( (readl(*a1 + 28LL) & 3) != 0 )
  {
    v3 = v2 + 100000;
    while ( ktime_get() <= v3 )
    {
      v4 = 1;
      usleep_range_state(1, 1, 2);
      __yield();
      if ( (readl(*a1 + 28LL) & 3) == 0 )
        return v4;
    }
    return (readl(*a1 + 28LL) & 3) == 0;
  }
  else
  {
    return 1;
  }
}
