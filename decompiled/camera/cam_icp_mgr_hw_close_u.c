__int64 __fastcall cam_icp_mgr_hw_close_u(__int64 a1, int *a2)
{
  __int64 v4; // x21
  char v5; // w9
  unsigned int v6; // w20
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  if ( a1 )
  {
    v4 = a1 + 40960;
    mutex_lock(a1);
    if ( !a2 )
    {
      v5 = *(_BYTE *)(v4 + 3270);
      a2 = &v8;
      *(_WORD *)((char *)&v8 + 1) = *(unsigned __int8 *)(v4 + 3277);
      LOBYTE(v8) = v5;
    }
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_mgr_hw_close_u",
        4463,
        "[%s] UMD calls close",
        (const char *)(a1 + 112));
    v6 = cam_icp_mgr_hw_close(a1, a2);
    *(_DWORD *)(v4 + 3188) = 0;
    mutex_unlock(a1);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_hw_close_u",
      4451,
      "Null hw mgr");
    v6 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
