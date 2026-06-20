__int64 __fastcall cam_icp_subdev_close(__int64 a1)
{
  __int64 result; // x0

  if ( !cam_req_mgr_is_open() )
    return cam_icp_subdev_close_internal(a1);
  result = 0;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_subdev_close",
      266,
      "CRM is ACTIVE, close should be from CRM for device[%s]",
      (const char *)(a1 + 184));
    return 0;
  }
  return result;
}
