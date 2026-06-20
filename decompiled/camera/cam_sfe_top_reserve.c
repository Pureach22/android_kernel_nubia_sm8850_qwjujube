__int64 __fastcall cam_sfe_top_reserve(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  int v4; // w8
  int v5; // w9
  int v6; // w7
  __int64 v7; // x19
  __int64 i; // x23
  __int64 v9; // x26
  __int64 v10; // x27
  __int64 v11; // x10
  __int64 v12; // x19
  __int64 v13; // x20

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_reserve",
      1511,
      "Error invalid input arguments");
    return (unsigned int)-22;
  }
  if ( !*(_WORD *)(a1 + 32260) || *(_QWORD *)(a1 + 32264) == *(_QWORD *)(a2 + 16) )
  {
    v4 = debug_mdl;
    v5 = debug_priority;
    v6 = *(_DWORD *)(a2 + 48);
    v7 = 0;
    for ( i = a1 + 22584; ; i += 152 )
    {
      if ( (v4 & 0x40000000) != 0 && !v5 )
      {
        v9 = a2;
        v10 = a1;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v4 & 0x40000000,
          4,
          "cam_sfe_top_reserve",
          1531,
          "i: %d res_id: %d state: %d",
          v7,
          v6,
          *(_DWORD *)(i + 8));
        v4 = debug_mdl;
        v5 = debug_priority;
        a2 = v9;
        v6 = *(_DWORD *)(v9 + 48);
        a1 = v10;
      }
      if ( *(_DWORD *)(i + 4) == v6 && *(_DWORD *)(i + 8) == 1 )
        break;
      if ( ++v7 == 6 )
        return (unsigned int)-22;
    }
    if ( (v4 & 0x40000000) != 0 && !v5 )
    {
      v12 = a2;
      v13 = a1;
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        v4 & 0x40000000,
        4,
        "cam_sfe_top_reserve",
        1539,
        "SFE [%u] for rsrc: %u acquired",
        *(unsigned int *)(*(_QWORD *)(i + 16) + 4LL));
      a2 = v12;
      a1 = v13;
    }
    v2 = 0;
    *(_QWORD *)(i + 48) = *(_QWORD *)(a2 + 56);
    v11 = *(_QWORD *)(a2 + 8);
    *(_DWORD *)(i + 8) = 2;
    *(_QWORD *)(i + 56) = v11;
    *(_QWORD *)(a2 + 40) = i;
    ++*(_WORD *)(a1 + 32260);
    *(_QWORD *)(a1 + 32264) = *(_QWORD *)(a2 + 16);
    *(_QWORD *)(a1 + 32280) = *(_QWORD *)(a2 + 24);
  }
  else
  {
    v2 = -22;
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_top_reserve",
        1523,
        "Acquiring same SFE[%u] HW res: %u for different streams",
        *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL),
        *(_DWORD *)(a2 + 48));
      return (unsigned int)-22;
    }
  }
  return v2;
}
