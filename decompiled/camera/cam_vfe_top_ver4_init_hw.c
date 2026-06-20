__int64 __fastcall cam_vfe_top_ver4_init_hw(__int64 a1)
{
  unsigned int *v1; // x8
  __int64 v2; // x9
  int v4; // w0

  v1 = *(unsigned int **)(a1 + 8);
  v2 = *(_QWORD *)(a1 + 10432);
  *(_QWORD *)(a1 + 10440) = 0;
  v4 = cam_io_r_mb(*(_QWORD *)(v2 + 288) + *v1);
  *(_DWORD *)(a1 + 10400) = v4;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_ver4_init_hw",
      1246,
      "VFE:%u hw-version:0x%x",
      *(_DWORD *)(a1 + 1092),
      v4);
  return 0;
}
