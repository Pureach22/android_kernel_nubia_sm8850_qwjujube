__int64 __fastcall cam_vfe_bus_ver3_start_wm_util(__int64 *a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x8

  v1 = *a1;
  v3 = *(_QWORD *)(*a1 + 16) + *((unsigned int *)a1 + 39);
  cam_io_w(*((unsigned int *)a1 + 6), v3 + *(unsigned int *)(a1[1] + 24));
  if ( (*(_BYTE *)(v1 + 34671) & 1) == 0 )
  {
    v4 = *(unsigned int *)(a1[1] + 60);
    if ( (_DWORD)v4 )
    {
      cam_io_w_mb(1, v3 + v4);
      cam_io_w_mb(0xFFFFFFFFLL, v3 + *(unsigned int *)(a1[1] + 64));
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_start_wm_util",
          1432,
          "VFE: %u WM: %d MMU prefetch enabled",
          *(_DWORD *)(*a1 + 8),
          *((_DWORD *)a1 + 30));
    }
  }
  v5 = a1[7];
  if ( (*(_BYTE *)(v5 + 133) & 1) != 0 || *(_BYTE *)(v5 + 134) == 1 )
    cam_io_w_mb(*(unsigned int *)(v5 + 120), v3 + *(unsigned int *)(a1[1] + 72));
  return cam_io_w_mb(*((unsigned int *)a1 + 11), v3 + *(unsigned int *)a1[1]);
}
