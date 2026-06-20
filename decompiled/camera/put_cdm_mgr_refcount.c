__int64 put_cdm_mgr_refcount()
{
  mutex_lock(&cam_cdm_mgr_lock);
  if ( (cdm_mgr[0] & 1) != 0 )
  {
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "put_cdm_mgr_refcount",
        54,
        "CDM intf mgr put refcount=%d",
        dword_39423C);
    if ( dword_39423C < 1 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "put_cdm_mgr_refcount",
        58,
        "Refcount put when zero");
      __break(0x800u);
    }
    else
    {
      --dword_39423C;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "put_cdm_mgr_refcount",
      51,
      "CDM intf mgr not probed yet");
  }
  return mutex_unlock(&cam_cdm_mgr_lock);
}
