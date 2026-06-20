__int64 __fastcall cam_tpg_subdev_close(__int64 a1)
{
  __int64 v1; // x19
  bool is_open; // w0
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 240);
  is_open = cam_req_mgr_is_open();
  if ( !v1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_subdev_close",
      26,
      "tpg_dev ptr is NULL");
    return 4294967274LL;
  }
  if ( !is_open )
  {
    mutex_lock(v1 + 24);
    if ( *(_DWORD *)(v1 + 4832) )
    {
      cam_tpg_shutdown(v1);
    }
    else if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x200000000LL,
        4,
        "cam_tpg_subdev_close",
        37,
        "TPG node %d is succesfully closed",
        *(_DWORD *)(v1 + 564));
    }
    mutex_unlock(v1 + 24);
    return 0;
  }
  result = 0;
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "cam_tpg_subdev_close",
      31,
      "CRM is ACTIVE, close should be from CRM");
    return 0;
  }
  return result;
}
