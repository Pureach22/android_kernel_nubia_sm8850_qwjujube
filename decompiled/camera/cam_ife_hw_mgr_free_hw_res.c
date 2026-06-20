__int64 __fastcall cam_ife_hw_mgr_free_hw_res(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v5; // x21
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x9
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x21
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  _QWORD *v12; // x8
  __int64 v13; // x9

  v2 = *(_QWORD *)(result + 32);
  v3 = result;
  if ( !v2 )
    goto LABEL_8;
  v5 = *(_QWORD *)(v2 + 16);
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v5 + 48);
  if ( v6 )
  {
    v7 = *(_QWORD *)(v5 + 112);
    if ( *((_DWORD *)v6 - 1) != 1989616049 )
      __break(0x8229u);
    result = v6(v7, v2, 152);
    if ( (_DWORD)result )
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 8,
                 1,
                 "cam_ife_hw_mgr_free_hw_res",
                 2106,
                 "Release HW:%d Res: %s resource id %d failed",
                 *(_DWORD *)(v5 + 4),
                 (const char *)(*(_QWORD *)(v3 + 32) + 128LL),
                 *(_DWORD *)(v3 + 20));
    *(_QWORD *)(v3 + 32) = 0;
LABEL_8:
    v8 = *(_QWORD *)(v3 + 40);
    if ( v8 )
      goto LABEL_9;
LABEL_17:
    if ( (a2 & 1) != 0 )
      goto LABEL_18;
    goto LABEL_23;
  }
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "cam_ife_hw_mgr_free_hw_res",
             2109,
             "Release null");
  v8 = *(_QWORD *)(v3 + 40);
  if ( !v8 )
    goto LABEL_17;
LABEL_9:
  v9 = *(_QWORD *)(v8 + 16);
  v10 = *(__int64 (__fastcall **)(_QWORD))(v9 + 48);
  if ( !v10 )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               8,
               1,
               "cam_ife_hw_mgr_free_hw_res",
               2109,
               "Release null");
    if ( (a2 & 1) != 0 )
      goto LABEL_18;
LABEL_23:
    *(_QWORD *)(v3 + 112) = 0;
    *(_QWORD *)(v3 + 120) = 0;
    *(_QWORD *)(v3 + 96) = 0;
    *(_QWORD *)(v3 + 104) = 0;
    *(_QWORD *)(v3 + 80) = 0;
    *(_QWORD *)(v3 + 88) = 0;
    *(_QWORD *)(v3 + 64) = 0;
    *(_QWORD *)(v3 + 72) = 0;
    *(_QWORD *)(v3 + 48) = 0;
    *(_QWORD *)(v3 + 56) = 0;
    *(_QWORD *)(v3 + 32) = 0;
    *(_QWORD *)(v3 + 40) = 0;
    *(_QWORD *)(v3 + 16) = 0;
    *(_QWORD *)(v3 + 24) = 0;
    *(_QWORD *)v3 = 0;
    *(_QWORD *)(v3 + 8) = 0;
    return result;
  }
  v11 = *(_QWORD *)(v9 + 112);
  if ( *((_DWORD *)v10 - 1) != 1989616049 )
    __break(0x8228u);
  result = v10(v11);
  if ( (_DWORD)result )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               1,
               "cam_ife_hw_mgr_free_hw_res",
               2106,
               "Release HW:%d Res: %s resource id %d failed",
               *(_DWORD *)(v9 + 4),
               (const char *)(*(_QWORD *)(v3 + 40) + 128LL),
               *(_DWORD *)(v3 + 20));
  *(_QWORD *)(v3 + 40) = 0;
  if ( (a2 & 1) == 0 )
    goto LABEL_23;
LABEL_18:
  v12 = *(_QWORD **)(v3 + 8);
  if ( *v12 == v3 && (v13 = *(_QWORD *)v3, *(_QWORD *)(*(_QWORD *)v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v13 + 8) = v12;
    *v12 = v13;
  }
  else
  {
    result = _list_del_entry_valid_or_report(v3);
  }
  *(_QWORD *)v3 = v3;
  *(_QWORD *)(v3 + 8) = v3;
  *(_QWORD *)(v3 + 16) = 0;
  *(_QWORD *)(v3 + 24) = 0;
  *(_QWORD *)(v3 + 32) = 0;
  *(_QWORD *)(v3 + 40) = 0;
  *(_QWORD *)(v3 + 48) = 0;
  *(_QWORD *)(v3 + 56) = 0;
  *(_QWORD *)(v3 + 64) = 0;
  *(_QWORD *)(v3 + 72) = 0;
  *(_QWORD *)(v3 + 80) = 0;
  *(_QWORD *)(v3 + 88) = 0;
  *(_QWORD *)(v3 + 96) = 0;
  *(_QWORD *)(v3 + 104) = 0;
  *(_QWORD *)(v3 + 112) = 0;
  *(_QWORD *)(v3 + 120) = 0;
  *(_QWORD *)v3 = v3;
  *(_QWORD *)(v3 + 8) = v3;
  return result;
}
