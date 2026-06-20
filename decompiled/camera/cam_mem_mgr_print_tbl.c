__int64 cam_mem_mgr_print_tbl()
{
  const char *v0; // x28
  __int64 v1; // x21
  unsigned __int64 v2; // x8
  __int64 result; // x0
  bool v4; // cf
  unsigned __int64 v5; // [xsp+58h] [xbp-18h] BYREF
  __int64 v6; // [xsp+60h] [xbp-10h]
  __int64 v7; // [xsp+68h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  v6 = 0;
  ktime_get_real_ts64(&v5);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000,
    3,
    "cam_mem_mgr_print_tbl",
    136,
    "***%llu:%llu:%llu:%llu Mem mgr table dump***",
    (_QWORD)(v5 / 0xE10 - 24 * ((v5 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
    v5 / 0x3C - 60 * ((unsigned __int64)((v5 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
    v5 % 0x3C,
    v6 / 1000000);
  v0 = (const char *)&unk_2FDDE4;
  v1 = -2047;
  do
  {
    v2 = *(_QWORD *)(v0 - 156);
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               0x400000,
               3,
               "cam_mem_mgr_print_tbl",
               144,
               "%llu:%llu:%llu:%llu idx %d fd %d i_ino %lu size %llu active %d buf_handle %d krefCount %d urefCount %d buf_name %s",
               (_QWORD)(v2 / 0xE10 - 24 * ((v2 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
               v2 / 0x3C - 60 * ((unsigned __int64)((v2 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
               v2 % 0x3C,
               *(_QWORD *)(v0 - 148) / 1000000LL,
               (int)v1 + 2048,
               *((_DWORD *)v0 - 57),
               *(_QWORD *)(v0 - 220),
               *(_QWORD *)(v0 - 204),
               *((unsigned __int8 *)v0 - 164),
               *((_DWORD *)v0 - 53),
               *((_DWORD *)v0 - 35),
               *(_DWORD *)v0,
               v0 - 132);
    v4 = __CFADD__(v1++, 1);
    v0 += 296;
  }
  while ( !v4 );
  _ReadStatusReg(SP_EL0);
  return result;
}
