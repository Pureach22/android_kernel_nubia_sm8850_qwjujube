__int64 __fastcall cam_mem_mgr_release_mem(_DWORD *a1)
{
  char *v1; // x21
  _QWORD *v2; // x23
  unsigned int v3; // w19
  const char *v4; // x5
  __int64 v5; // x4
  char *v7; // x20
  _DWORD *v8; // x22
  __int64 v10; // x1
  int v11; // w6
  const char *v12; // x5
  __int64 v13; // x4
  unsigned int v14; // w23
  __int64 v15; // x8
  int v21; // w8

  if ( !cam_mem_mgr_state )
  {
    v4 = "failed. mem_mgr not initialized";
    v5 = 3249;
    goto LABEL_7;
  }
  if ( !a1 )
  {
    v4 = "Invalid argument";
    v5 = 3254;
    goto LABEL_7;
  }
  v3 = a1[4] & 0x7FFF;
  if ( v3 - 2048 <= 0xFFFFF800 )
  {
    v4 = "Incorrect index extracted from mem handle";
    v5 = 3260;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_release_mem",
      v5,
      v4);
    return 4294967274LL;
  }
  v7 = (char *)&tbl + 296 * v3;
  v8 = a1;
  _X0 = (unsigned int *)mutex_lock(v7 + 72);
  if ( v3 <= 0x7FF )
  {
    v1 = v7 + 64;
    if ( (v7[184] & 1) != 0 )
    {
      v11 = *((_DWORD *)v7 + 34);
      if ( v11 == v8[4] )
      {
        v2 = &unk_393000;
        v8 = &unk_393000;
        if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x400000,
            4,
            "cam_mem_mgr_release_mem",
            3277,
            "Releasing hdl = %X",
            v11);
        _X0 = (unsigned int *)(v7 + 208);
        goto LABEL_27;
      }
      v12 = "Released buf handle not matching within table";
      v13 = 3272;
    }
    else
    {
      v12 = "Released buffer state should be active";
      v13 = 3265;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_release_mem",
      v13,
      v12);
    goto LABEL_20;
  }
  __break(1u);
LABEL_27:
  __asm { PRFM            #0x11, [X0] }
  do
    v21 = __ldxr(_X0);
  while ( __stlxr(v21 - 1, _X0) );
  if ( v21 == 1 )
  {
    __dmb(9u);
    if ( (*((_DWORD *)v1 + 18) & 0x7FFFu) - 2048 > 0xFFFFF800 )
      cam_mem_util_unmap(*((_DWORD *)v1 + 18) & 0x7FFF, v10);
    else
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_util_unmap_wrapper",
        2896,
        "idx: %d not valid",
        *((_DWORD *)v1 + 18) & 0x7FFF);
    v15 = v2[458];
    v14 = 0;
    if ( (v15 & 0x400000) != 0 && !v8[919] )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v15 & 0x400000,
        4,
        "cam_mem_mgr_release_mem",
        3281,
        "Called unmap from here, buf_handle: %u, idx: %d",
        *((_DWORD *)v1 + 18),
        v3);
      v14 = 0;
    }
    goto LABEL_21;
  }
  if ( v21 <= 0 )
    refcount_warn_saturate();
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000,
    1,
    "cam_mem_mgr_release_mem",
    3285,
    "Unbalanced release Called buf_handle: %u, idx: %d",
    *((_DWORD *)v1 + 18),
    v3);
LABEL_20:
  v14 = -22;
LABEL_21:
  mutex_unlock(v7 + 72);
  return v14;
}
