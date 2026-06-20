__int64 __fastcall synx_test_create_sync_fd(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 result; // x0
  unsigned int v8; // w20
  _QWORD *v9; // x0
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x0

  if ( a1 && a1 < 0xFFFFFFFFFFFFF001LL )
  {
    result = get_unused_fd_flags(0x80000);
    if ( (result & 0x80000000) != 0 )
      return result;
    v8 = result;
    v9 = (_QWORD *)sync_file_create(a1);
    if ( v9 && (unsigned __int64)v9 < 0xFFFFFFFFFFFFF001LL )
    {
      fd_install(v8, *v9);
      return v8;
    }
    v12 = v8;
    if ( (synx_debug & 1) != 0 )
    {
      printk(&unk_2AA0B, &unk_29207, "synx_test_create_sync_fd", 305, v10, v11);
      v12 = v8;
    }
    put_unused_fd(v12);
  }
  else if ( (synx_debug & 1) != 0 )
  {
    printk(&unk_289DC, &unk_29207, "synx_test_create_sync_fd", 295, a5, a6);
  }
  return 4294967274LL;
}
