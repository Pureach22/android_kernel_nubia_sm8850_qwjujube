__int64 __fastcall cam_common_read_poll_timeout(
        const void *a1,
        unsigned __int64 a2,
        __int64 a3,
        unsigned int a4,
        int a5,
        _DWORD *a6)
{
  unsigned int v10; // w8
  unsigned __int64 v12; // x25
  __int64 v14; // x24
  int v15; // w0
  int v16; // w8
  __int64 v17; // x24
  int v18; // w0
  int v19; // w0

  if ( a1 && a6 )
  {
    v10 = timeout_multiplier;
    if ( !timeout_multiplier )
    {
      v10 = 1;
      timeout_multiplier = 1;
    }
    v12 = v10 * a3;
    if ( (cam_presil_mode_enabled(a1) & 1) != 0 )
    {
      return cam_presil_readl_poll_timeout(a1, a4, v12 / 0xEA60, 100);
    }
    else
    {
      v14 = ktime_get();
      v15 = readl(a1);
      v16 = v15 & a4;
      *a6 = v15;
      if ( (v15 & a4) != a5 )
      {
        v17 = v14 + 1000 * v12;
        while ( !v12 || ktime_get() <= v17 )
        {
          if ( a2 )
            usleep_range_state((a2 >> 2) + 1, a2, 2);
          __yield();
          v18 = readl(a1);
          *a6 = v18;
          if ( (v18 & a4) == a5 )
          {
            v16 = a5;
            goto LABEL_17;
          }
        }
        v19 = readl(a1);
        *a6 = v19;
        v16 = v19 & a4;
      }
LABEL_17:
      if ( v16 == a5 )
        return 0;
      else
        return 4294967186LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_read_poll_timeout",
      108,
      "Invalid param addr: %pK status: %pK",
      a1,
      a6);
    return 4294967274LL;
  }
}
