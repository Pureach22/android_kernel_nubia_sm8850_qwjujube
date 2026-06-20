__int64 __fastcall cam_vfe_bus_stop_rm(__int64 a1)
{
  __int64 v1; // x20
  char v3; // w8

  v1 = *(_QWORD *)(a1 + 24);
  cam_io_w_mb(0, *(_QWORD *)(*(_QWORD *)(v1 + 8) + 8LL) + **(unsigned int **)(v1 + 16));
  v3 = debug_mdl;
  *(_DWORD *)(a1 + 8) = 2;
  *(_BYTE *)(v1 + 32) = 0;
  if ( (v3 & 8) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v3 & 8,
      4,
      "cam_vfe_bus_stop_rm",
      493,
      "VFE:%d RM:%d stopped",
      **(_DWORD **)(v1 + 8),
      *(_DWORD *)v1);
  return 0;
}
