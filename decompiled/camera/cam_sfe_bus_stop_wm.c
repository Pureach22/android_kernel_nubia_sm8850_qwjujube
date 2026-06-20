__int64 __fastcall cam_sfe_bus_stop_wm(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20

  v1 = *(_QWORD *)(a1 + 24);
  v3 = *(_QWORD *)(v1 + 8);
  cam_io_w_mb(0, *(_QWORD *)(v3 + 8) + **(unsigned int **)(v1 + 16));
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_stop_wm",
      938,
      "Stop SFE:%d WM:%d %s",
      **(_DWORD **)(v1 + 8),
      *(_DWORD *)v1,
      (const char *)(a1 + 128));
  *(_DWORD *)(a1 + 8) = 2;
  *(_WORD *)(v1 + 121) = 0;
  *(_BYTE *)(v3 + 27540) = 0;
  return 0;
}
