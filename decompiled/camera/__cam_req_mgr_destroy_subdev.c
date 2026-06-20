__int64 __fastcall _cam_req_mgr_destroy_subdev(const void **a1)
{
  __int64 result; // x0

  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_destroy_subdev",
      2839,
      "*l_device %pK",
      *a1);
    result = (__int64)*a1;
    if ( !*a1 )
      return result;
  }
  else
  {
    result = (__int64)*a1;
    if ( !*a1 )
      return result;
  }
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free(result, 0);
  else
    result = kvfree(result);
  *a1 = nullptr;
  return result;
}
