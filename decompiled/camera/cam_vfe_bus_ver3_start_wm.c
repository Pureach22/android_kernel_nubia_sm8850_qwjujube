__int64 __fastcall cam_vfe_bus_ver3_start_wm(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v3; // x23
  __int64 v4; // x24
  __int64 v5; // x22
  __int64 v6; // x8
  unsigned int v7; // w21
  int v8; // w8
  __int64 v9; // x0
  int v10; // w8
  __int64 v11; // x1
  char v12; // w8
  __int64 v13; // x8
  unsigned __int64 v14; // x20
  __int64 v15; // x25
  _QWORD *v16; // x26

  v1 = *(_QWORD *)(a1 + 24);
  v3 = *(_QWORD **)v1;
  v4 = *(_QWORD *)v1 + 0x8000LL;
  v5 = *(_QWORD *)(*(_QWORD *)v1 + 16LL) + *(unsigned int *)(v1 + 156);
  if ( *(_BYTE *)(*(_QWORD *)v1 + 34668LL) == 1 )
    cam_io_w(15, v5 + *(unsigned int *)(*(_QWORD *)(v1 + 8) + 76LL));
  v6 = *(_QWORD *)(v1 + 56);
  if ( (*(_BYTE *)(v6 + 133) & 1) == 0 && *(_BYTE *)(v6 + 134) != 1 )
  {
    cam_vfe_bus_ver3_start_wm_util(v1);
    goto LABEL_14;
  }
  v7 = cam_io_r_mb(v3[2] + *v3 + *(unsigned int *)(v3[10] + 16LL));
  v8 = *(_DWORD *)(*(_QWORD *)(v1 + 56) + 120LL);
  if ( (v8 & 1) == 0 )
  {
    if ( (v8 & 2) == 0 )
      goto LABEL_7;
LABEL_11:
    cam_io_w_mb((unsigned int)(1 << *(_DWORD *)(v3[10] + 88LL)), v3[2] + *v3 + *(unsigned int *)(v3[10] + 16LL));
    cam_vfe_bus_ver3_start_wm_util(v1);
    if ( (*(_DWORD *)(*(_QWORD *)(v1 + 56) + 120LL) & 4) == 0 )
      goto LABEL_9;
    goto LABEL_8;
  }
  cam_io_w_mb(0, v3[2] + *v3 + *(unsigned int *)(v3[10] + 16LL));
  cam_vfe_bus_ver3_start_wm_util(v1);
  v8 = *(_DWORD *)(*(_QWORD *)(v1 + 56) + 120LL);
  if ( (v8 & 2) != 0 )
    goto LABEL_11;
LABEL_7:
  if ( (v8 & 4) != 0 )
  {
LABEL_8:
    cam_io_w_mb((unsigned int)(2 << *(_DWORD *)(v3[10] + 88LL)), v3[2] + *v3 + *(unsigned int *)(v3[10] + 16LL));
    cam_vfe_bus_ver3_start_wm_util(v1);
  }
LABEL_9:
  cam_io_w_mb(v7, v3[2] + *v3 + *(unsigned int *)(v3[10] + 16LL));
LABEL_14:
  v9 = cam_io_w_mb(2816, v5 + *(unsigned int *)(*(_QWORD *)(v1 + 8) + 112LL));
  v10 = debug_priority;
  v11 = debug_mdl & 8;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v9 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           v11,
           4,
           "cam_vfe_bus_ver3_start_wm",
           1498,
           "Start VFE:%u WM:%d %s offset:0x%X en_cfg:0x%X width:%d height:%d",
           *(_DWORD *)(*(_QWORD *)v1 + 8LL),
           *(_DWORD *)(v1 + 120),
           (const char *)(a1 + 128),
           **(_DWORD **)(v1 + 8) + *(_DWORD *)(v1 + 156),
           *(_DWORD *)(v1 + 44),
           *(_DWORD *)(v1 + 16),
           *(_DWORD *)(v1 + 20));
    v10 = debug_priority;
    v11 = debug_mdl & 8;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_19;
  }
  else if ( (debug_mdl & 8) == 0 )
  {
    goto LABEL_19;
  }
  if ( !v10 )
    v9 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           v11,
           4,
           "cam_vfe_bus_ver3_start_wm",
           1501,
           "VFE:%u WM:%d pk_fmt:%d stride:%d burst len:%d hw_ctxt_mask:0x%x",
           *(_DWORD *)(*(_QWORD *)v1 + 8LL),
           *(_DWORD *)(v1 + 120),
           *(_DWORD *)(v1 + 24),
           *(_DWORD *)(v1 + 32),
           15,
           *(_DWORD *)(*(_QWORD *)(v1 + 56) + 120LL));
LABEL_19:
  *(_DWORD *)(a1 + 8) = 4;
  v12 = *(_BYTE *)(v4 + 1904);
  *(_DWORD *)(v4 + 1956) = 0;
  if ( (v12 & 1) != 0 )
    return 0;
  v13 = v3[10];
  if ( !*(_DWORD *)(v13 + 160) )
    return 0;
  v14 = 0;
  v15 = 168;
  v16 = v3 + 4329;
  while ( v15 != 232 )
  {
    v9 = *((unsigned int *)v16 + v14);
    if ( (_DWORD)v9 )
    {
      cam_io_w_mb(v9, v3[2] + *v3 + *(unsigned int *)(v13 + v15));
      *(_BYTE *)(v4 + 1904) = 1;
      v9 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             3,
             "cam_vfe_bus_ver3_start_wm",
             1519,
             "VFE:%u perf_cnt_%d:0x%x offset: 0x%x",
             *(_DWORD *)(*(_QWORD *)v1 + 8LL),
             v14,
             *((_DWORD *)v16 + v14),
             *(_DWORD *)v3 + *(_DWORD *)(v3[10] + v15));
      v13 = v3[10];
    }
    ++v14;
    v15 += 8;
    if ( v14 >= *(unsigned int *)(v13 + 160) )
      return 0;
  }
  __break(0x5512u);
  return cam_vfe_bus_ver3_stop_wm(v9);
}
