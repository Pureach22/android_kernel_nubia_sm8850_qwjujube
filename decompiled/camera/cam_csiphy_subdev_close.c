__int64 __fastcall cam_csiphy_subdev_close(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x19

  if ( cam_req_mgr_is_open() )
  {
    result = 0;
    if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_csiphy_subdev_close",
        410,
        "CRM is ACTIVE, close should be from CRM");
      return 0;
    }
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 240);
    if ( v3 )
    {
      mutex_lock(v3 + 24);
      cam_csiphy_shutdown(v3);
      mutex_unlock(v3 + 24);
      return 0;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_subdev_close_internal",
      393,
      "csiphy_dev ptr is NULL");
    return 4294967274LL;
  }
  return result;
}
