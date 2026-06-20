__int64 __fastcall cam_vfe_bus_ver3_init_hw(__int64 a1)
{
  unsigned int v1; // w8
  char v2; // w20
  int v4; // w19
  int v5; // w0

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_init_hw",
      5235,
      "Invalid args");
    return (unsigned int)-22;
  }
  if ( (*(_BYTE *)(a1 + 34666) & 1) != 0 )
    return 0;
  if ( (*(_BYTE *)(a1 + 34628) & 0x10) != 0 )
    *(_QWORD *)(a1 + 48) = *(_QWORD *)(a1 + 32);
  *(_BYTE *)(a1 + 34666) = 1;
  v2 = debug_mdl;
  v1 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v4 = *(_DWORD *)(a1 + 8);
    v5 = cam_io_r_mb(*(_QWORD *)(a1 + 16) + *(_QWORD *)a1 + **(unsigned int **)(a1 + 80));
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v2 & 8,
      4,
      "cam_vfe_bus_ver3_init_hw",
      5255,
      "VFE:%u bus-wr hw-version:0x%x",
      v4,
      v5);
    return 0;
  }
  return v1;
}
