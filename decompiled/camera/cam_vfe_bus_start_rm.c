__int64 __fastcall cam_vfe_bus_start_rm(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 v3; // x21
  char v4; // w9
  int v5; // w8
  __int64 v6; // x1

  v1 = *(_DWORD **)(a1 + 24);
  v3 = *((_QWORD *)v1 + 1);
  cam_io_w_mb(
    (unsigned int)*((unsigned __int16 *)v1 + 26) | (v1[14] << 16),
    *(_QWORD *)(v3 + 8) + *(unsigned int *)(*((_QWORD *)v1 + 2) + 8LL));
  cam_io_w_mb((unsigned int)v1[13], *(_QWORD *)(v3 + 8) + *(unsigned int *)(*((_QWORD *)v1 + 2) + 12LL));
  cam_io_w_mb((unsigned int)v1[18], *(_QWORD *)(v3 + 8) + *(unsigned int *)(*((_QWORD *)v1 + 2) + 16LL));
  cam_io_w_mb((unsigned int)v1[17], *(_QWORD *)(v3 + 8) + *(unsigned int *)(*((_QWORD *)v1 + 2) + 20LL));
  cam_io_w_mb(1, *(_QWORD *)(v3 + 8) + **((unsigned int **)v1 + 2));
  v4 = debug_mdl;
  v5 = debug_priority;
  *(_DWORD *)(a1 + 8) = 4;
  v6 = v4 & 8;
  if ( (v4 & 8) != 0 && !v5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6,
      4,
      "cam_vfe_bus_start_rm",
      471,
      "Start VFE:%d RM:%d offset:0x%X en_cfg:0x%X width:%d height:%d",
      **((_DWORD **)v1 + 1),
      *v1,
      **((_DWORD **)v1 + 2),
      v1[23],
      v1[13],
      v1[14]);
    v5 = debug_priority;
    v6 = debug_mdl & 8;
    if ( (debug_mdl & 8) == 0 )
      return 0;
  }
  else if ( (v4 & 8) == 0 )
  {
    return 0;
  }
  if ( !v5 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6,
      4,
      "cam_vfe_bus_start_rm",
      473,
      "RM:%d pk_fmt:%d stride:%d",
      *v1,
      v1[18],
      v1[15]);
  return 0;
}
