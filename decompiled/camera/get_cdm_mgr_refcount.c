__int64 get_cdm_mgr_refcount()
{
  unsigned int v0; // w19

  mutex_lock(&cam_cdm_mgr_lock);
  if ( (cdm_mgr[0] & 1) != 0 )
  {
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "get_cdm_mgr_refcount",
        40,
        "CDM intf mgr get refcount=%d",
        dword_39423C);
    v0 = 0;
    ++dword_39423C;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "get_cdm_mgr_refcount",
      36,
      "CDM intf mgr not probed yet");
    v0 = -1;
  }
  mutex_unlock(&cam_cdm_mgr_lock);
  return v0;
}
