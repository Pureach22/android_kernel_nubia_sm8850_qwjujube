__int64 __fastcall cam_mem_put_cpu_buf(int a1)
{
  char *v1; // x21
  unsigned int v3; // w19
  __int64 result; // x0
  char *v5; // x22
  __int64 v7; // x0
  int v13; // w8
  int v14; // w24
  int v15; // w25
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // [xsp+58h] [xbp-18h] BYREF
  __int64 v18; // [xsp+60h] [xbp-10h]
  __int64 v19; // [xsp+68h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFF0100) != 0 )
  {
    v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           0x400000,
           1,
           "cam_mem_put_cpu_buf",
           2913,
           "Calling from softirq/atomic context");
    result = dump_stack(v7);
    goto LABEL_17;
  }
  if ( !a1 )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               0x400000,
               1,
               "cam_mem_put_cpu_buf",
               2919,
               "Invalid buf_handle");
    goto LABEL_17;
  }
  v3 = a1 & 0x7FFF;
  if ( v3 - 2048 > 0xFFFFF800 )
  {
    v5 = (char *)&tbl + 296 * (a1 & 0x7FFF);
    mutex_lock(v5 + 72);
    _X0 = (unsigned int *)raw_spin_lock_bh(v5 + 352);
    if ( v3 <= 0x7FF )
    {
      v1 = v5 + 64;
      if ( (v5[184] & 1) != 0 )
      {
        if ( *((_DWORD *)v5 + 34) == a1 )
        {
          _X0 = (unsigned int *)(v5 + 208);
          goto LABEL_20;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_put_cpu_buf",
          2939,
          "idx: %d Invalid buf handle %d",
          v3,
          a1);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_put_cpu_buf",
          2932,
          "idx: %d not active",
          v3);
      }
      raw_spin_unlock_bh(v5 + 352);
LABEL_16:
      result = mutex_unlock(v5 + 72);
      goto LABEL_17;
    }
    __break(1u);
LABEL_20:
    __asm { PRFM            #0x11, [X0] }
    do
      v13 = __ldxr(_X0);
    while ( __stlxr(v13 - 1, _X0) );
    if ( v13 == 1 )
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
    else if ( v13 <= 0 )
    {
      refcount_warn_saturate();
    }
    v14 = *((_DWORD *)v1 + 36);
    v15 = *((_DWORD *)v1 + 71);
    raw_spin_unlock_bh(v5 + 352);
    if ( v14 != 1 || v15 )
    {
      if ( v1[121] == 1 )
      {
        v16 = *((_QWORD *)v1 + 16);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_put_cpu_buf",
          2966,
          "%llu:%llu:%llu:%llu idx %d fd %d i_ino %lu size %llu active %d buf_handle %d krefCount %d urefCount %d buf_name %s",
          (_QWORD)(v16 / 0xE10 - 24 * ((v16 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
          v16 / 0x3C - 60 * ((unsigned __int64)((v16 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
          v16 % 0x3C,
          *((_QWORD *)v1 + 17) / 1000000LL,
          v3,
          *((_DWORD *)v1 + 14),
          *((_QWORD *)v1 + 8),
          *((_QWORD *)v1 + 10),
          (unsigned __int8)v1[120],
          *((_DWORD *)v1 + 18),
          v14,
          v15,
          v1 + 152);
        ktime_get_real_ts64(&v17);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_put_cpu_buf",
          2971,
          "%llu:%llu:%llu:%llu  Not unmapping even after defer, buf_handle: %u, idx: %d",
          (_QWORD)(v17 / 0xE10 - 24 * ((v17 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
          v17 / 0x3C - 60 * ((unsigned __int64)((v17 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
          v17 % 0x3C,
          v18 / 1000000,
          a1,
          v3);
      }
      else if ( !v14 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_put_cpu_buf",
          2975,
          "Unbalanced release Called buf_handle: %u, idx: %d kref: %d",
          *((_DWORD *)v1 + 18),
          v3,
          0);
      }
    }
    else
    {
      cam_mem_util_unmap(v3);
      ktime_get_real_ts64(&v17);
      if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x400000,
          4,
          "cam_mem_put_cpu_buf",
          2959,
          "%llu:%llu:%llu:%llu  Called unmap from here, buf_handle: %u, idx: %d",
          (_QWORD)(v17 / 0xE10 - 24 * ((v17 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
          v17 / 0x3C - 60 * ((unsigned __int64)((v17 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
          v17 % 0x3C,
          v18 / 1000000,
          a1,
          v3);
    }
    goto LABEL_16;
  }
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x400000,
             1,
             "cam_mem_put_cpu_buf",
             2925,
             "idx: %d not valid",
             v3);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
