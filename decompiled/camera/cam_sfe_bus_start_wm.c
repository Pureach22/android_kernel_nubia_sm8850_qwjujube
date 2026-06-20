__int64 __fastcall cam_sfe_bus_start_wm(__int64 a1)
{
  _DWORD *v1; // x22
  __int64 v3; // x23
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x1
  char v7; // w8
  __int64 v8; // x8
  unsigned __int64 v9; // x19
  __int64 v10; // x25
  __int64 v11; // x26

  v1 = *(_DWORD **)(a1 + 24);
  v3 = *((_QWORD *)v1 + 1);
  cam_io_w((unsigned int)(v1[13] | (v1[14] << 16)), *(_QWORD *)(v3 + 8) + *(unsigned int *)(*((_QWORD *)v1 + 2) + 12LL));
  cam_io_w((unsigned int)v1[17], *(_QWORD *)(v3 + 8) + *(unsigned int *)(*((_QWORD *)v1 + 2) + 24LL));
  if ( *((_BYTE *)v1 + 124) == 1 )
  {
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_bus_start_wm",
        873,
        "configure line_done_cfg 0x%x for WM: %d",
        *(_DWORD *)(*((_QWORD *)v1 + 1) + 27436LL),
        *v1);
    cam_io_w_mb(
      *(unsigned int *)(*((_QWORD *)v1 + 1) + 27436LL),
      *(_QWORD *)(v3 + 8) + *(unsigned int *)(*((_QWORD *)v1 + 2) + 40LL));
  }
  if ( (*(_BYTE *)(v3 + 27472) & 0x10) == 0 )
  {
    cam_io_w_mb(1, *(_QWORD *)(v3 + 8) + *(unsigned int *)(*((_QWORD *)v1 + 2) + 96LL));
    cam_io_w_mb(0xFFFFFFFFLL, *(_QWORD *)(v3 + 8) + *(unsigned int *)(*((_QWORD *)v1 + 2) + 100LL));
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_bus_start_wm",
        886,
        "SFE: %u WM: %u MMU prefetch enabled",
        **((_DWORD **)v1 + 1),
        *v1);
  }
  cam_io_w_mb((unsigned int)v1[24], *(_QWORD *)(v3 + 8) + **((unsigned int **)v1 + 2));
  v4 = cam_io_w_mb(2816, *(_QWORD *)(v3 + 8) + *(unsigned int *)(*((_QWORD *)v1 + 2) + 84LL));
  v5 = debug_priority;
  v6 = debug_mdl & 0x40000000;
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    v4 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           v6,
           4,
           "cam_sfe_bus_start_wm",
           902,
           "Start SFE:%u WM:%d %s offset:0x%X en_cfg:0x%X width:%d height:%d",
           **((_DWORD **)v1 + 1),
           *v1,
           (const char *)(a1 + 128),
           **((_DWORD **)v1 + 2),
           v1[24],
           v1[13],
           v1[14]);
    v5 = debug_priority;
    v6 = debug_mdl & 0x40000000;
    if ( (debug_mdl & 0x40000000) == 0 )
      goto LABEL_15;
  }
  else if ( (debug_mdl & 0x40000000) == 0 )
  {
    goto LABEL_15;
  }
  if ( !v5 )
    v4 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           v6,
           4,
           "cam_sfe_bus_start_wm",
           905,
           "WM:%d pk_fmt:%d stride:%d",
           *v1,
           v1[17] & 0x11,
           v1[15]);
LABEL_15:
  *(_DWORD *)(a1 + 8) = 4;
  v7 = *(_BYTE *)(v3 + 27540);
  *(_DWORD *)(v3 + 27536) = 0;
  if ( (v7 & 1) != 0 )
    return 0;
  v8 = *(_QWORD *)(v3 + 48);
  if ( !*(_DWORD *)(v8 + 104) )
    return 0;
  v9 = 0;
  v10 = 112;
  v11 = v3 + 27476;
  while ( v10 != 176 )
  {
    v4 = *(unsigned int *)(v11 + 4 * v9);
    if ( (_DWORD)v4 )
    {
      cam_io_w_mb(v4, *(_QWORD *)(v3 + 8) + *(unsigned int *)(v8 + v10));
      *(_BYTE *)(v3 + 27540) = 1;
      v4 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             3,
             "cam_sfe_bus_start_wm",
             921,
             "SFE:%u perf_cnt_%d:0x%x",
             **((_DWORD **)v1 + 1),
             v9,
             *(_DWORD *)(v11 + 4 * v9));
      v8 = *(_QWORD *)(v3 + 48);
    }
    ++v9;
    v10 += 8;
    if ( v9 >= *(unsigned int *)(v8 + 104) )
      return 0;
  }
  __break(0x5512u);
  return cam_sfe_bus_stop_wm(v4);
}
