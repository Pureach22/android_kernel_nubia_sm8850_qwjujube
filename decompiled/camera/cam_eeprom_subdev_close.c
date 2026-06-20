__int64 __fastcall cam_eeprom_subdev_close(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x19

  if ( cam_req_mgr_is_open() )
  {
    result = 0;
    if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x10000,
        4,
        "cam_eeprom_subdev_close",
        50,
        "CRM is ACTIVE, close should be from CRM");
      return 0;
    }
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 240);
    if ( v3 )
    {
      mutex_lock(v3 + 40);
      cam_eeprom_shutdown(v3);
      mutex_unlock(v3 + 40);
      return 0;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_subdev_close_internal",
      33,
      "e_ctrl ptr is NULL");
    return 4294967274LL;
  }
  return result;
}
