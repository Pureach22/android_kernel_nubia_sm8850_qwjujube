__int64 __fastcall cam_ife_hw_mgr_init_hw_res(__int64 a1)
{
  __int64 v1; // x9
  __int64 v3; // x22
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x8
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 result; // x0
  __int64 v8; // x9
  __int64 v9; // x21
  __int64 (__fastcall *v10)(__int64, __int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x1
  int v13; // w6
  int v14; // w7
  unsigned int v15; // w19

  v1 = *(_QWORD *)(a1 + 32);
  if ( v1 )
  {
    v3 = *(_QWORD *)(v1 + 16);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_init_hw_res",
        1677,
        "enabled vfe hardware %u",
        *(_DWORD *)(v3 + 4));
      v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v3 + 16);
      if ( !v4 )
        goto LABEL_8;
    }
    else
    {
      v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v3 + 16);
      if ( !v4 )
        goto LABEL_8;
    }
    v5 = *(_QWORD *)(v3 + 112);
    v6 = *(_QWORD *)(a1 + 32);
    if ( *((_DWORD *)v4 - 1) != 1989616049 )
      __break(0x8228u);
    LODWORD(result) = v4(v5, v6, 152);
    if ( (_DWORD)result )
      goto LABEL_15;
  }
LABEL_8:
  v8 = *(_QWORD *)(a1 + 40);
  if ( !v8 )
    return 0;
  v9 = *(_QWORD *)(v8 + 16);
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v9 + 16);
    if ( v10 )
      goto LABEL_12;
    return 0;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_hw_mgr_init_hw_res",
    1677,
    "enabled vfe hardware %u",
    *(_DWORD *)(v9 + 4));
  v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v9 + 16);
  if ( !v10 )
    return 0;
LABEL_12:
  v11 = *(_QWORD *)(v9 + 112);
  v12 = *(_QWORD *)(a1 + 40);
  if ( *((_DWORD *)v10 - 1) != 1989616049 )
    __break(0x8228u);
  result = v10(v11, v12, 152);
  if ( (_DWORD)result )
  {
LABEL_15:
    v13 = *(_DWORD *)(a1 + 16);
    v14 = *(_DWORD *)(a1 + 20);
    v15 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_init_hw_res",
      1690,
      "INIT HW res failed: (type:%d, id:%d)",
      v13,
      v14);
    return v15;
  }
  return result;
}
