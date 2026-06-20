__int64 __fastcall cam_packet_util_process_generic_blob(unsigned int a1, _DWORD *a2, _DWORD *a3, __int64 a4)
{
  int v8; // w27
  unsigned __int64 v9; // x28
  unsigned __int64 v10; // x26
  unsigned __int64 v11; // x20
  __int64 v12; // x25
  __int64 v13; // x24
  unsigned int v14; // w0
  unsigned int v16; // w19

  if ( a1 < 5 )
    return 0;
  v8 = 0;
  v9 = a1;
  while ( 1 )
  {
    v10 = (unsigned int)*a2;
    if ( (unsigned int)v10 < 0x100 )
      return 0;
    v11 = v10 >> 8;
    v12 = (((*a2 >> 8) + 3) & 0x1FFFFFC) + 4LL;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_packet_util_process_generic_blob",
        685,
        "Blob type=%d size=%d block_size=%d len_read=%d total=%d",
        (unsigned __int8)*a2,
        v11,
        v12,
        v8,
        a1);
    v13 = (unsigned int)(v12 + v8);
    if ( (unsigned int)v13 > a1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_packet_util_process_generic_blob",
        690,
        "Invalid Blob %d %d %d %d",
        (unsigned __int8)v10,
        v11,
        v8,
        a1);
      return 4294967274LL;
    }
    if ( *(a3 - 1) != -872724753 )
      __break(0x8236u);
    v14 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _DWORD *))a3)(
            a4,
            (unsigned __int8)v10,
            (unsigned int)v11,
            a2 + 1);
    if ( v14 )
      break;
    a2 = (_DWORD *)((char *)a2 + v12);
    v8 += v12;
    if ( v13 + 4 >= v9 )
      return 0;
  }
  v16 = v14;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_packet_util_process_generic_blob",
    701,
    "Error in handling blob type %d %d",
    (unsigned __int8)v10,
    v11);
  return v16;
}
