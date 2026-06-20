__int64 __fastcall qcom_rng_read(__int64 a1, _DWORD *a2, unsigned int a3)
{
  unsigned int v6; // w19
  __int64 v7; // x23
  __int64 v8; // x23
  int v9; // w0
  size_t v10; // x2
  int src; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v6 = 0;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  while ( 1 )
  {
    v7 = ktime_get();
    if ( (readl(*(_QWORD *)(a1 + 48) + 4LL) & 1) == 0 )
    {
      v8 = v7 + 10000000;
      while ( ktime_get() <= v8 )
      {
        usleep_range_state(51, 200, 2);
        __yield();
        if ( (readl(*(_QWORD *)(a1 + 48) + 4LL) & 1) != 0 )
          goto LABEL_8;
      }
      if ( (readl(*(_QWORD *)(a1 + 48) + 4LL) & 1) == 0 )
        break;
    }
LABEL_8:
    v9 = readl_relaxed(*(_QWORD *)(a1 + 48));
    if ( !v9 )
    {
      v6 = -22;
      goto LABEL_15;
    }
    v10 = a3 - v6;
    if ( (unsigned int)v10 <= 3 )
    {
      src = v9;
      memcpy(a2, &src, v10);
      v6 = a3;
      goto LABEL_15;
    }
    v6 += 4;
    *a2++ = v9;
    if ( v6 >= a3 )
      goto LABEL_15;
  }
  v6 = -110;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v6;
}
