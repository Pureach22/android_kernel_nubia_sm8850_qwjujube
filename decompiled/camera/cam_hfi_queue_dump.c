__int64 __fastcall cam_hfi_queue_dump(unsigned int a1, char a2)
{
  __int64 v3; // x24
  _DWORD *v4; // x25
  int v6; // w8
  int v7; // w9
  int v8; // w19
  _DWORD *v9; // x26
  __int64 v10; // x6
  __int64 result; // x0
  int v12; // w8
  int v13; // w19
  int v14; // w9
  _DWORD *v15; // x24

  if ( a1 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      82,
      "Invalid HFI index: %u from hdl:%d",
      a1,
      a1);
    v10 = 4294967274LL;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
             3,
             0x40000,
             1,
             "cam_hfi_queue_dump",
             163,
             "Failed to get hfi info rc:%d for hdl:%d",
             v10,
             a1);
  }
  v3 = *(_QWORD *)&g_hfi[2 * a1 + 2];
  if ( !v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      89,
      "[%s] HFI interface not setup for client hdl: %d",
      byte_3EC,
      a1);
    v10 = 4294967277LL;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
             3,
             0x40000,
             1,
             "cam_hfi_queue_dump",
             163,
             "Failed to get hfi info rc:%d for hdl:%d",
             v10,
             a1);
  }
  v4 = *(_DWORD **)(v3 + 8);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x40000,
    3,
    "cam_hfi_queue_dump",
    179,
    "[%s] hfi hdl: %u qtbl header: version=0x%08x tbl_size=%u numq=%u qhdr_size=%u",
    (const char *)(v3 + 1004),
    a1,
    *v4,
    v4[1],
    v4[4],
    v4[3]);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x40000,
    3,
    "cam_hfi_queue_dump",
    187,
    "cmd_q: addr=0x%08x size=%u read_idx=%u write_idx=%u",
    *(_DWORD *)(v3 + 40),
    v4[69],
    v4[213],
    v4[229]);
  if ( (a2 & 1) == 0 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD))cam_print_log)(
             3,
             0x40000,
             3,
             "cam_hfi_queue_dump",
             201,
             "msg_q: addr=0x%08x size=%u read_idx=%u write_idx=%u",
             *(unsigned int *)(v3 + 64),
             (unsigned int)v4[308],
             v4[452],
             v4[468]);
  v6 = debug_mdl;
  v7 = debug_priority;
  v8 = 0;
  v9 = (_DWORD *)(*(_QWORD *)(v3 + 32) + 8LL);
  do
  {
    if ( (v6 & 0x40000) != 0 && !v7 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v6 & 0x40000LL,
        4,
        "hfi_queue_dump",
        108,
        "word[%04d]: 0x%08x 0x%08x 0x%08x 0x%08x",
        v8,
        *(v9 - 2),
        *(v9 - 1),
        *v9,
        v9[1]);
      v6 = debug_mdl;
      v7 = debug_priority;
    }
    v8 += 4;
    v9 += 4;
  }
  while ( v8 != 2048 );
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x40000,
             3,
             "cam_hfi_queue_dump",
             201,
             "msg_q: addr=0x%08x size=%u read_idx=%u write_idx=%u",
             *(_DWORD *)(v3 + 64),
             v4[308],
             v4[452],
             v4[468]);
  v12 = debug_mdl;
  v13 = 0;
  v14 = debug_priority;
  v15 = (_DWORD *)(*(_QWORD *)(v3 + 56) + 8LL);
  do
  {
    if ( (v12 & 0x40000) != 0 && !v14 )
    {
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 *(_QWORD *)&v12 & 0x40000LL,
                 4,
                 "hfi_queue_dump",
                 108,
                 "word[%04d]: 0x%08x 0x%08x 0x%08x 0x%08x",
                 v13,
                 *(v15 - 2),
                 *(v15 - 1),
                 *v15,
                 v15[1]);
      v12 = debug_mdl;
      v14 = debug_priority;
    }
    v13 += 4;
    v15 += 4;
  }
  while ( v13 != 2048 );
  return result;
}
