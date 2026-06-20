__int64 __fastcall cam_vfe_fe_resource_start(__int64 a1)
{
  int v1; // w6
  __int64 v3; // x21
  _DWORD *v4; // x8
  unsigned int v5; // w20
  unsigned int v6; // w9
  int v7; // w9
  int v8; // w8
  int v9; // w10
  int v10; // w9
  unsigned int v11; // w8
  unsigned int v12; // w9
  unsigned int v13; // w20
  int v14; // w8
  __int64 v15; // x1
  __int64 result; // x0

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_fe_resource_start",
      260,
      "Error! Invalid input arguments");
    return 4294967274LL;
  }
  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 != 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_fe_resource_start",
      266,
      "Error! Invalid fe res res_state:%d",
      v1);
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a1 + 24);
  v4 = *(_DWORD **)(v3 + 32);
  v5 = *(_DWORD *)(v3 + 56) << v4[12];
  if ( *(_DWORD *)(v3 + 48) == 2 )
    v5 |= 1 << v4[10];
  v6 = *(_DWORD *)(v3 + 52) - 1;
  if ( v6 <= 1 )
    v5 |= ((v4[15] & v6) << v4[14]) | (1 << v4[16]);
  if ( *(_DWORD *)(v3 + 92) )
    v5 |= v4[27] << v4[8];
  v7 = *(_DWORD *)(v3 + 96);
  if ( v7 )
    v5 |= v7 << v4[28];
  cam_io_w_mb(v5, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 68LL));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_fe_resource_start",
      303,
      "hw id:%d core_cfg (off:0x%x, val:0x%x)",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
      *(_DWORD *)(*(_QWORD *)(v3 + 24) + 68LL),
      v5);
  cam_io_w_mb(0xFFFFFFFFLL, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v3 + 24) + 40LL) + 4LL));
  v8 = *(_DWORD *)(v3 + 72);
  v9 = *(_DWORD *)(v3 + 64);
  v10 = *(_DWORD *)(v3 + 80) + v8;
  v11 = v8 - v9;
  v12 = (unsigned int)(v10 - v9) >> 1;
  if ( v12 < v11 )
    v11 = v12;
  v13 = *(unsigned __int16 *)(*(_QWORD *)(v3 + 32) + 76LL) | (v11 << 16);
  cam_io_w_mb(v13, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 24LL));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_fe_resource_start",
      323,
      "first_line:0x%x last_line:0x%x vbi:0x%x epoch_line_cfg: 0x%x",
      *(_DWORD *)(v3 + 64),
      *(_DWORD *)(v3 + 72),
      *(_DWORD *)(v3 + 80),
      v13);
  *(_DWORD *)(a1 + 8) = 4;
  cam_io_w_mb(*(unsigned int *)(v3 + 92), *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 48LL));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_fe_resource_start",
      333,
      "hw id:%d fe_cfg_data(off:0x%x val:0x%x)",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
      *(_DWORD *)(*(_QWORD *)(v3 + 16) + 48LL),
      *(_DWORD *)(v3 + 92));
  cam_io_w_mb(
    *(unsigned int *)(*(_QWORD *)(v3 + 32) + 72LL),
    *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 36LL));
  v14 = debug_priority;
  v15 = debug_mdl & 8;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v15,
      4,
      "cam_vfe_fe_resource_start",
      341,
      "hw id:%d RUP (off:0x%x, val:0x%x)",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
      *(_DWORD *)(*(_QWORD *)(v3 + 16) + 36LL),
      *(_DWORD *)(*(_QWORD *)(v3 + 32) + 72LL));
    v14 = debug_priority;
    v15 = debug_mdl & 8;
  }
  result = 0;
  *(_BYTE *)(v3 + 84) = 0;
  *(_DWORD *)(v3 + 88) = 0;
  if ( v15 )
  {
    if ( !v14 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v15,
        4,
        "cam_vfe_fe_resource_start",
        347,
        "Start Camif IFE %d Done",
        *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL));
      return 0;
    }
  }
  return result;
}
