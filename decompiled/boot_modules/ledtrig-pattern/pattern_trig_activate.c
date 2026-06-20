__int64 __fastcall pattern_trig_activate(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x21
  char v4; // w8
  __int64 result; // x0
  __int64 default_pattern; // x0
  __int64 v7; // x20
  int v8; // w2
  __int64 v9; // x21
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = _kmalloc_large_noprof(8392, 3520);
  if ( v2 )
  {
    if ( (*(_QWORD *)(a1 + 64) != 0) != (*(_QWORD *)(a1 + 72) != 0) )
    {
      v9 = v2;
      dev_warn(*(_QWORD *)(a1 + 80), "Hardware pattern ops validation failed\n");
      v2 = v9;
      *(_QWORD *)(a1 + 64) = 0;
      *(_QWORD *)(a1 + 72) = 0;
    }
    *(_BYTE *)(v2 + 8280) = 1;
    *(_DWORD *)(v2 + 8284) = 0;
    *(_DWORD *)(v2 + 8272) = -1;
    v3 = (_QWORD *)v2;
    _mutex_init(v2 + 8216, "&data->lock", &pattern_trig_activate___key);
    *v3 = a1;
    *(_QWORD *)(a1 + 336) = v3;
    init_timer_key(v3 + 1036, pattern_trig_timer_function, 0, 0, 0);
    hrtimer_init(v3 + 1041, 1, 1);
    v4 = *(_BYTE *)(a1 + 22);
    result = 0;
    *(_BYTE *)(a1 + 344) = 1;
    v3[1046] = pattern_trig_hrtimer_function;
    if ( v4 < 0 )
    {
      v10 = 0;
      default_pattern = led_get_default_pattern(a1, &v10);
      if ( default_pattern )
      {
        v7 = default_pattern;
        if ( (v10 & 1) != 0 )
        {
          dev_warn(*(_QWORD *)(a1 + 80), "Expected pattern of tuples\n");
        }
        else
        {
          v8 = pattern_trig_store_patterns(a1, 0, default_pattern);
          if ( v8 < 0 )
            dev_warn(*(_QWORD *)(a1 + 80), "Pattern initialization failed with error %d\n", v8);
        }
        kfree(v7);
      }
      result = 0;
      *(_DWORD *)(a1 + 20) &= ~0x800000u;
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
