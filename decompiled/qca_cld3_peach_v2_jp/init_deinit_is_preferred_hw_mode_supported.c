__int64 __fastcall init_deinit_is_preferred_hw_mode_supported(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  int v12; // w8
  const char *v14; // x2
  int v15; // w9

  if ( !a2 )
  {
    v14 = "%s: psoc target_psoc_info is null in service ext msg";
LABEL_5:
    qdf_trace_msg(
      0x49u,
      2u,
      v14,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "init_deinit_is_preferred_hw_mode_supported",
      v10,
      v11);
    return 0;
  }
  v12 = *(_DWORD *)(a2 + 504);
  if ( v12 == 11 )
    return 1;
  if ( (*(_BYTE *)(a1 + 31) & 2) != 0 && (*(_BYTE *)(a1 + 22) & 8) == 0 )
  {
    v14 = "%s: WMI service bit for DYNAMIC HW mode is not set!";
    goto LABEL_5;
  }
  v15 = *(unsigned __int8 *)(a2 + 486);
  if ( !*(_BYTE *)(a2 + 486) )
    return 0;
  if ( *(_DWORD *)(a2 + 1072) == v12 )
    return 1;
  if ( v15 == 1 )
    return 0;
  if ( *(_DWORD *)(a2 + 1328) == v12 )
    return 1;
  if ( v15 == 2 )
    return 0;
  if ( *(_DWORD *)(a2 + 1584) == v12 )
    return 1;
  if ( v15 == 3 )
    return 0;
  if ( *(_DWORD *)(a2 + 1840) == v12 )
    return 1;
  if ( v15 == 4 )
    return 0;
  if ( *(_DWORD *)(a2 + 2096) == v12 )
    return 1;
  if ( v15 == 5 )
    return 0;
  if ( *(_DWORD *)(a2 + 2352) == v12 )
    return 1;
  if ( v15 == 6 )
    return 0;
  if ( *(_DWORD *)(a2 + 2608) == v12 )
    return 1;
  if ( v15 == 7 )
    return 0;
  if ( *(_DWORD *)(a2 + 2864) == v12 )
    return 1;
  if ( v15 == 8 )
    return 0;
  __break(0x5512u);
  return init_deinit_wakeup_host_wait(a1, a2);
}
