__int64 __fastcall cam_vfe_init_config_update(__int64 *a1, int a2)
{
  __int64 v2; // x10
  __int64 result; // x0
  int *v5; // x8
  char v6; // w9
  int v7; // w8

  v2 = *a1;
  if ( a2 == 16 )
  {
    result = 0;
    v5 = (int *)a1[1];
    v6 = debug_mdl;
    v7 = *v5;
    *(_DWORD *)(*(_QWORD *)(v2 + 24) + 22728LL) = v7;
    if ( (v6 & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v6 & 8,
        4,
        "cam_vfe_init_config_update",
        1177,
        "VFE:%u Init Update for res_name: %s epoch_factor: %u%%",
        *(_DWORD *)(*(_QWORD *)(v2 + 16) + 4LL),
        (const char *)(v2 + 128),
        v7);
      return 0;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_init_config_update",
      1168,
      "VFE:%u Invalid args size expected: %zu actual: %zu",
      *(_DWORD *)(*(_QWORD *)(v2 + 16) + 4LL),
      0x10u,
      a2);
    return 4294967274LL;
  }
  return result;
}
