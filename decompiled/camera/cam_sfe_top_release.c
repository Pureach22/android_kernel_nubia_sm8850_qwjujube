__int64 __fastcall cam_sfe_top_release(__int64 a1, __int64 a2)
{
  __int16 v3; // w9
  __int64 v4; // [xsp+10h] [xbp-10h]
  __int64 v5; // [xsp+18h] [xbp-8h]

  if ( a1 && a2 )
  {
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    {
      v5 = a2;
      v4 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_top_release",
        1590,
        "Release for SFE [%u] resource id: %u in state: %d",
        *(_DWORD *)(*(_QWORD *)(a2 + 16) + 4LL),
        *(_DWORD *)(a2 + 4),
        *(_DWORD *)(a2 + 8));
      a2 = v5;
      a1 = v4;
    }
    if ( *(_DWORD *)(a2 + 8) > 1u )
    {
      *(_QWORD *)(a2 + 48) = 0;
      *(_QWORD *)(a2 + 56) = 0;
      *(_DWORD *)(a2 + 8) = 1;
      if ( !*(_WORD *)(a1 + 32260) || (v3 = *(_WORD *)(a1 + 32260) - 1, (*(_WORD *)(a1 + 32260) = v3) == 0) )
      {
        *(_QWORD *)(a1 + 32264) = 0;
        *(_QWORD *)(a1 + 32280) = 0;
      }
      return 0;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_top_release",
        1593,
        "SFE [%u] invalid res_state: %d",
        *(unsigned int *)(*(_QWORD *)(a2 + 16) + 4LL));
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_release",
      1580,
      "Invalid input arguments");
    return 4294967274LL;
  }
}
