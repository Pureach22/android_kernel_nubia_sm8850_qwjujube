__int64 __fastcall cam_sfe_bus_stop_rm(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w8

  v1 = *(_QWORD *)(a1 + 24);
  cam_io_w_mb(0, *(_QWORD *)(*(_QWORD *)v1 + 8LL) + **(unsigned int **)(v1 + 8));
  v3 = debug_mdl;
  *(_DWORD *)(a1 + 8) = 2;
  *(_BYTE *)(v1 + 89) = 0;
  if ( (v3 & 0x40000000) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v3 & 0x40000000,
      4,
      "cam_sfe_bus_stop_rm",
      612,
      "SFE:%d RM:%d stopped",
      **(_DWORD **)v1,
      *(_DWORD *)(v1 + 24));
  return 0;
}
