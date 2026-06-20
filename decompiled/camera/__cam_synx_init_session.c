__int64 _cam_synx_init_session()
{
  __int64 v0; // x0
  const void *v1; // x6
  __int64 result; // x0
  _QWORD v3[3]; // [xsp+0h] [xbp-50h] BYREF
  _QWORD v4[7]; // [xsp+18h] [xbp-38h] BYREF

  v4[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = cam_synx_session_name;
  v3[1] = v4;
  memset(v4, 0, 48);
  v3[2] = 0x100000000LL;
  v0 = synx_initialize(v3);
  *(_QWORD *)(g_cam_synx_obj_dev + 23552) = v0;
  if ( v0 )
  {
    v1 = (const void *)v0;
    result = 0;
    if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000000000LL,
        4,
        "__cam_synx_init_session",
        777,
        "Synx session initialized: %p",
        v1);
      result = 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "__cam_synx_init_session",
      772,
      "Synx session initialization failed");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
