__int64 __fastcall cam_irq_controller_register_dependent(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w9
  __int64 result; // x0
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x9
  int v8; // w11
  unsigned int v9; // w10
  int v10; // w13
  __int64 v11; // x12

  if ( a1 && a2 )
  {
    v4 = *(_DWORD *)(a2 + 68);
    if ( v4 == -1 )
    {
      v6 = *(_DWORD *)(a1 + 64) | 0xFFFFFFFFFFFFE000LL;
      if ( v6 == -1 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x800000,
          1,
          "cam_irq_controller_register_dependent",
          286,
          "reached maximum dependents (%s - %s)",
          (const char *)a1,
          (const char *)a2);
        return 4294967284LL;
      }
      else
      {
        v7 = __clz(__rbit64(~v6));
        *(_DWORD *)(a2 + 68) = v7;
        v8 = *(_DWORD *)(a1 + 24);
        *(_QWORD *)(a1 + 8 * v7 + 216) = a2;
        if ( v8 )
        {
          v9 = 0;
          do
          {
            v10 = *(_DWORD *)(a3 + 4LL * (int)v9);
            v11 = *(_QWORD *)(a1 + 32) + 112LL * (int)v9++;
            *(_DWORD *)(v11 + 4 * v7 + 56) = v10;
          }
          while ( v9 < *(_DWORD *)(a1 + 24) );
        }
        *(_BYTE *)(a2 + 324) = 1;
        *(_DWORD *)(a1 + 64) |= 1LL << v7;
        if ( !*(_DWORD *)(a2 + 48) )
          *(_BYTE *)(a1 + 325) = 1;
        result = 0;
        if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x800000,
            4,
            "cam_irq_controller_register_dependent",
            306,
            "successfully registered %s as dependent of %s",
            (const char *)a2,
            (const char *)a1);
          return 0;
        }
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000,
        1,
        "cam_irq_controller_register_dependent",
        279,
        "Duplicate dependent register for pri_ctrl:%s sec_ctrl:%s parent_bitmap_idx:%d",
        (const char *)a1,
        (const char *)a2,
        v4);
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000,
      1,
      "cam_irq_controller_register_dependent",
      267,
      "invalid args: %pK, %pK",
      (const void *)a1,
      (const void *)a2);
    return 4294967274LL;
  }
  return result;
}
