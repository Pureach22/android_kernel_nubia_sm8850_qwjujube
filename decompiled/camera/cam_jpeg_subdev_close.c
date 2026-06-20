__int64 __fastcall cam_jpeg_subdev_close(__int64 a1)
{
  __int64 result; // x0

  if ( !cam_req_mgr_is_open() )
    return cam_jpeg_subdev_close_internal(a1);
  result = 0;
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_subdev_close",
      148,
      "CRM is ACTIVE, close should be from CRM");
    return 0;
  }
  return result;
}
