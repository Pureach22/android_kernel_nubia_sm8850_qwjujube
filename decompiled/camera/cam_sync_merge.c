__int64 __fastcall cam_sync_merge(__int64 a1, unsigned int a2, _DWORD *a3)
{
  const char *v4; // x5
  __int64 v5; // x4
  int v9; // w8
  __int64 v10; // x21
  unsigned int v11; // w0
  __int64 first_zero_bit; // x0
  __int64 v13; // x25
  __int64 v14; // x26
  __int64 v21; // x8
  __int64 v22; // x22
  int v23; // w7
  unsigned int v24; // w19
  unsigned __int64 v27; // x9

  if ( !a1 || !a3 )
  {
    v4 = "Invalid pointer(s)";
    v5 = 498;
    goto LABEL_6;
  }
  if ( a2 <= 1 )
  {
    v4 = "Single object merge is not allowed";
    v5 = 503;
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_merge",
      v5,
      v4);
    return 4294967274LL;
  }
  if ( (unsigned int)cam_common_util_remove_duplicate_arr(a1, a2) != a2 )
  {
    v4 = "The obj list has duplicate fence";
    v5 = 509;
    goto LABEL_6;
  }
  v9 = 0;
  do
  {
    v10 = v9;
    v11 = cam_sync_check_valid(*(unsigned int *)(a1 + 4LL * v9));
    if ( v11 )
    {
      v23 = *(_DWORD *)(a1 + 4 * v10);
      v24 = v11;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_sync_merge",
        517,
        "Sync_obj[%d] %d valid check fail",
        v10,
        v23);
      return v24;
    }
    v9 = v10 + 1;
  }
  while ( a2 != (_DWORD)v10 + 1 );
  do
  {
    first_zero_bit = find_first_zero_bit(sync_dev + 8416, 2048);
    if ( first_zero_bit > 2047 )
      return 4294967284LL;
    v13 = 1LL << first_zero_bit;
    v14 = (unsigned int)first_zero_bit >> 6;
    _X9 = (unsigned __int64 *)(sync_dev + 8416 + 8 * v14);
    __asm { PRFM            #0x11, [X9] }
    do
      v21 = __ldxr(_X9);
    while ( __stlxr(v21 | v13, _X9) );
    __dmb(0xBu);
  }
  while ( (v21 & v13) != 0 );
  if ( (unsigned __int64)first_zero_bit >= 0x801 )
  {
    __break(0x5512u);
LABEL_27:
    _X8 = (unsigned __int64 *)(v21 + 8 * v14);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 & ~v13, _X8) );
    return 4294967274LL;
  }
  v22 = first_zero_bit;
  raw_spin_lock_bh(sync_dev + 4 * first_zero_bit + 136);
  if ( (((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, _QWORD))cam_sync_init_group_object)(
          *(_QWORD *)(sync_dev + 128),
          (unsigned int)v22,
          a1,
          a2)
      & 0x80000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_merge",
      533,
      "Error: Unable to init row at idx = %ld",
      v22);
    v21 = sync_dev + 8416;
    goto LABEL_27;
  }
  if ( (debug_mdl & 0x80) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      (unsigned __int8)debug_mdl & 0x80,
      4,
      "cam_sync_merge",
      537,
      "Init row at idx:%ld to merge objects",
      v22);
  *a3 = v22;
  raw_spin_unlock_bh(sync_dev + 4 * v22 + 136);
  return 0;
}
