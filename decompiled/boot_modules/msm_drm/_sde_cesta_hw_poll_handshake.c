__int64 __fastcall sde_cesta_hw_poll_handshake(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x19

  if ( a2 >= 9 )
  {
    __break(0x5512u);
    return ((__int64 (*)(void))readl_relaxed_11)();
  }
  else
  {
    v2 = *(_QWORD *)(a1 + 16LL * a2 + 552);
    v3 = ktime_get(a1);
    v4 = readl_relaxed_11(v2 + 16);
    if ( (v4 & 0x30) == 0x10 )
    {
      v5 = v3 + 1000000;
      while ( ktime_get(v4) <= v5 )
      {
        usleep_range_state(26, 100, 2);
        __yield();
        v4 = readl_relaxed_11(v2 + 16);
        if ( (v4 & 0x30) != 0x10 )
          return 0;
      }
      if ( (readl_relaxed_11(v2 + 16) & 0x30) == 0x10 )
        return 4294967186LL;
      else
        return 0;
    }
    else
    {
      return 0;
    }
  }
}
