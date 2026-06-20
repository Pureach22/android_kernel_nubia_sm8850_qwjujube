__int64 __fastcall cam_icp_mgr_hw_open_u(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0
  unsigned int v4; // w20
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 256;
  if ( a1 )
  {
    LOBYTE(v5) = *(_BYTE *)(a1 + 44230);
    if ( a2 )
      LOBYTE(v5) = *a2 ^ 1;
    if ( (cam_presil_mode_enabled(a1) & 1) != 0 )
    {
      result = 0;
      if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x8000000,
          4,
          "cam_icp_mgr_hw_open_u",
          5722,
          "[%s] hw_open from umd skipped for presil",
          (const char *)(a1 + 112));
        result = 0;
      }
    }
    else
    {
      mutex_lock(a1);
      v4 = cam_icp_mgr_hw_open(a1, &v5);
      mutex_unlock(a1);
      result = v4;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_hw_open_u",
      5708,
      "Null hw mgr");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
