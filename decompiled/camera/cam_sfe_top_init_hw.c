__int64 __fastcall cam_sfe_top_init_hw(__int64 a1)
{
  int v1; // w20
  unsigned int v2; // w8
  int v3; // w19
  int v4; // w0

  if ( a1 )
  {
    v1 = debug_mdl;
    v2 = 0;
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    {
      v3 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL);
      v4 = cam_io_r_mb(*(_QWORD *)(*(_QWORD *)a1 + 288LL) + ***(unsigned int ***)(a1 + 32296));
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v1 & 0x40000000,
        4,
        "cam_sfe_top_init_hw",
        2240,
        "SFE:%d hw-version:0x%x",
        v3,
        v4);
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_init_hw",
      2232,
      "Invalid args");
    return (unsigned int)-22;
  }
  return v2;
}
