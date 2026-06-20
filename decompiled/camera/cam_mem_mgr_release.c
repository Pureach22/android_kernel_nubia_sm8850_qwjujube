__int64 __fastcall cam_mem_mgr_release(_DWORD *a1)
{
  char *v1; // x21
  _DWORD *v2; // x23
  _QWORD *v3; // x24
  unsigned int v4; // w19
  __int64 result; // x0
  const char *v6; // x5
  __int64 v7; // x4
  char *v8; // x20
  __int64 v11; // x1
  int v12; // w7
  __int64 v13; // x8
  unsigned int v14; // w21
  int v20; // w8
  int v21; // w25
  int v22; // w26
  __int64 v23; // x8
  unsigned __int64 v24; // x8
  _QWORD v25[3]; // [xsp+58h] [xbp-18h] BYREF

  v25[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  v25[1] = 0;
  if ( !cam_mem_mgr_state )
  {
    v6 = "failed. mem_mgr not initialized";
    v7 = 3035;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_release",
      v7,
      v6);
    result = 4294967274LL;
    goto LABEL_22;
  }
  if ( !a1 )
  {
    v6 = "Invalid argument";
    v7 = 3040;
    goto LABEL_7;
  }
  v4 = *a1 & 0x7FFF;
  if ( v4 - 2048 > 0xFFFFF800 )
  {
    v8 = (char *)&tbl + 296 * v4;
    _X0 = (unsigned int *)mutex_lock(v8 + 72);
    if ( v4 > 0x7FF )
    {
      __break(1u);
    }
    else
    {
      v1 = v8 + 64;
      if ( (v8[184] & 1) == 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_mgr_release",
          3052,
          "Released buffer state should be active");
        goto LABEL_20;
      }
      v12 = *((_DWORD *)v8 + 34);
      if ( v12 != *a1 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_mgr_release",
          3060,
          "Released buf handle %d not matching within table %d, idx=%d",
          *a1,
          v12,
          v4);
        goto LABEL_20;
      }
      v3 = &unk_393000;
      v2 = &unk_393000;
      if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x400000,
          4,
          "cam_mem_mgr_release",
          3065,
          "Releasing hdl = %x, idx = %d",
          v12,
          v4);
      _X0 = (unsigned int *)(v8 + 348);
    }
    __asm { PRFM            #0x11, [X0] }
    do
      v20 = __ldxr(_X0);
    while ( __stlxr(v20 - 1, _X0) );
    if ( v20 == 1 )
    {
      __dmb(9u);
      v13 = v3[458];
      if ( (v13 & 0x400000) != 0 && !v2[919] )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v13 & 0x400000,
          4,
          "cam_mem_util_unmap_dummy",
          2779,
          "Cam mem util unmap dummy");
    }
    else if ( v20 <= 0 )
    {
      refcount_warn_saturate();
    }
    v21 = *((_DWORD *)v1 + 71);
    if ( (v1[88] & 8) == 0 )
    {
      if ( v21 )
      {
        v14 = 0;
        goto LABEL_21;
      }
LABEL_34:
      cam_mem_util_unmap(v4, v11);
      v23 = v3[458];
      v14 = 0;
      if ( (v23 & 0x400000) != 0 && !v2[919] )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v23 & 0x400000,
          4,
          "cam_mem_mgr_release",
          3083,
          "Called unmap from here, buf_handle: %u, idx: %d",
          *a1,
          v4);
        v14 = 0;
      }
      goto LABEL_21;
    }
    v22 = *((_DWORD *)v1 + 36);
    if ( v22 == 1 && !v21 )
      goto LABEL_34;
    ktime_get_real_ts64(v25);
    v24 = *((_QWORD *)v1 + 16);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_release",
      3093,
      "%llu:%llu:%llu:%llu idx %d fd %d i_ino %lu size %llu active %d buf_handle %d krefCount %d urefCount %d buf_name %s",
      (_QWORD)(v24 / 0xE10 - 24 * ((v24 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
      v24 / 0x3C - 60 * ((unsigned __int64)((v24 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
      v24 % 0x3C,
      *((_QWORD *)v1 + 17) / 1000000LL,
      v4,
      *((_DWORD *)v1 + 14),
      *((_QWORD *)v1 + 8),
      *((_QWORD *)v1 + 10),
      (unsigned __int8)v1[120],
      *((_DWORD *)v1 + 18),
      v22,
      v21,
      v1 + 152);
    if ( v1[121] == 1 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_mgr_release",
        3096,
        "Unbalanced release Called buf_handle: %u, idx: %d",
        *((_DWORD *)v1 + 18),
        v4);
    v1[121] = 1;
LABEL_20:
    v14 = -22;
LABEL_21:
    mutex_unlock(v8 + 72);
    result = v14;
    goto LABEL_22;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000,
    1,
    "cam_mem_mgr_release",
    3047,
    "Incorrect index %d extracted from mem handle",
    v4);
  result = 4294967274LL;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
