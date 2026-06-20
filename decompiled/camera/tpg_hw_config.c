__int64 __fastcall tpg_hw_config(__int64 a1, int a2)
{
  __int64 v2; // x8
  int v4; // w8

  if ( !a1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 + 32);
  if ( !v2 )
    return 4294967274LL;
  if ( !*(_QWORD *)(v2 + 16) )
    return 4294967274LL;
  if ( a2 != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_config",
      1042,
      "TPG[%d] Unsupported hw config command",
      *(_DWORD *)a1);
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a1 + 168) || (v4 = *(_DWORD *)(a1 + 4), v4 == 3) )
  {
    tpg_hw_configure_init_settings_v3();
  }
  else if ( v4 == 1 )
  {
    tpg_hw_configure_init_settings();
  }
  return 0;
}
