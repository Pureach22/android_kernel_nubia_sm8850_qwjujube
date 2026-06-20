__int64 __fastcall cam_ife_hw_mgr_start_hw_res(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v5; // x22
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x9
  __int64 v7; // x0
  unsigned int v8; // w21
  __int64 v9; // x1
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0

  v2 = *(_QWORD *)(a1 + 40);
  if ( !v2 )
  {
    v8 = -1;
    v9 = *(_QWORD *)(a1 + 32);
    if ( v9 )
      goto LABEL_7;
    return 0;
  }
  v5 = *(_QWORD *)(v2 + 16);
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v5 + 56);
  if ( !v6 )
  {
    v8 = -1;
    goto LABEL_15;
  }
  v7 = *(_QWORD *)(v5 + 112);
  if ( *((_DWORD *)v6 - 1) != 1989616049 )
    __break(0x8229u);
  v8 = v6(v7, v2, 152);
  if ( v8 )
    goto LABEL_11;
  v9 = *(_QWORD *)(a1 + 32);
  if ( !v9 )
    return 0;
LABEL_7:
  v5 = *(_QWORD *)(v9 + 16);
  v10 = *(__int64 (__fastcall **)(_QWORD))(v5 + 56);
  if ( !v10 )
  {
LABEL_15:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_start_hw_res",
      1806,
      "function null, ctx_idx: %u",
      *(_DWORD *)(a2 + 56));
    goto LABEL_16;
  }
  v11 = *(_QWORD *)(v5 + 112);
  if ( *((_DWORD *)v10 - 1) != 1989616049 )
    __break(0x8228u);
  v8 = v10(v11);
  if ( v8 )
  {
LABEL_11:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_start_hw_res",
      1802,
      "Can not start HW:%d resources, ctx_idx: %u",
      *(_DWORD *)(v5 + 4),
      *(_DWORD *)(a2 + 56));
LABEL_16:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_start_hw_res",
      1814,
      "Start hw res failed (ctx_idx: %u type:%d, id:%d)",
      *(_DWORD *)(a2 + 56),
      *(_DWORD *)(a1 + 16),
      *(_DWORD *)(a1 + 20));
  }
  return v8;
}
