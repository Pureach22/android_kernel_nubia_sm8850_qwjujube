__int64 __fastcall _read_register_with_poll_timeout(
        __int64 a1,
        unsigned int a2,
        int a3,
        int a4,
        unsigned int a5,
        unsigned int a6)
{
  unsigned int *v12; // x25
  __int64 v13; // x27
  int v14; // w8
  __int64 result; // x0
  __int64 v16; // x27
  unsigned int v17; // w21

  if ( (is_core_sub_state(a1, 1) & 1) != 0 )
  {
    v12 = (unsigned int *)(**(_QWORD **)(a1 + 3904) + a2);
    v13 = ktime_get();
    v14 = readl_relaxed_0(v12) & a3;
    if ( v14 != a4 )
    {
      v16 = v13 + 1000LL * a6;
      while ( !a6 || ktime_get() <= v16 )
      {
        if ( a5 )
          usleep_range_state(((unsigned __int64)a5 >> 2) + 1, a5, 2);
        __yield();
        if ( ((unsigned int)readl_relaxed_0(v12) & a3) == a4 )
        {
          v14 = a4;
          goto LABEL_15;
        }
      }
      v14 = readl_relaxed_0(v12) & a3;
    }
LABEL_15:
    __dsb(0xDu);
    if ( v14 == a4 )
      result = 0;
    else
      result = 4294967186LL;
    if ( (msm_vidc_debug & 4) != 0 )
    {
      v17 = result;
      printk(&unk_86267, "low ", 0xFFFFFFFFLL, "codec", **(_QWORD **)(a1 + 3904));
      return v17;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8C767, "err ", 0xFFFFFFFFLL, "codec", "__read_register_with_poll_timeout");
    return 4294967274LL;
  }
  return result;
}
