__int64 __fastcall cam_mem_put_kref(int a1)
{
  unsigned int v1; // w19
  char *v3; // x20
  char *v6; // x21
  int v7; // w22
  unsigned __int64 v8; // x8
  int v14; // w8

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x400000,
             1,
             "cam_mem_put_kref",
             2990,
             "Invalid buf_handle");
  v1 = a1 & 0x7FFF;
  if ( v1 - 2048 <= 0xFFFFF800 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x400000,
             1,
             "cam_mem_put_kref",
             2996,
             "idx: %d not valid",
             v1);
  v3 = (char *)&tbl + 296 * (a1 & 0x7FFF);
  _X0 = (unsigned int *)raw_spin_lock_bh(v3 + 352);
  if ( v1 > 0x7FF )
  {
    __break(1u);
LABEL_15:
    __asm { PRFM            #0x11, [X0] }
    do
      v14 = __ldxr(_X0);
    while ( __stlxr(v14 - 1, _X0) );
    if ( v14 == 1 )
    {
      __dmb(9u);
      if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x400000,
          4,
          "cam_mem_util_unmap_dummy",
          2779,
          "Cam mem util unmap dummy");
    }
    else if ( v14 <= 0 )
    {
      refcount_warn_saturate();
    }
    return raw_spin_unlock_bh(v3 + 352);
  }
  if ( v3[184] == 1 && *((_DWORD *)v3 + 34) == a1 )
  {
    _X0 = (unsigned int *)(v3 + 208);
    v7 = *((_DWORD *)v3 + 52);
    if ( !*((_DWORD *)v3 + 87) )
    {
      raw_spin_unlock_bh(v3 + 352);
      v8 = *((_QWORD *)v3 + 24);
      v6 = v3 + 64;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_put_kref",
        3019,
        "%llu:%llu:%llu:%llu idx %d fd %d i_ino %lu size %llu active %d buf_handle %d krefCount %d urefCount %d buf_name %s",
        (_QWORD)(v8 / 0xE10 - 24 * ((v8 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
        v8 / 0x3C - 60 * ((unsigned __int64)((v8 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
        v8 % 0x3C,
        *((_QWORD *)v6 + 17) / 1000000LL,
        v1,
        *((_DWORD *)v6 + 14),
        *((_QWORD *)v6 + 8),
        *((_QWORD *)v6 + 10),
        (unsigned __int8)v6[120],
        *((_DWORD *)v6 + 18),
        v7,
        0,
        v6 + 152);
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               0x400000,
               1,
               "cam_mem_put_kref",
               3020,
               "Buffer unmap called from UMD before KMD , not unmapping!");
    }
    goto LABEL_15;
  }
  return raw_spin_unlock_bh(v3 + 352);
}
