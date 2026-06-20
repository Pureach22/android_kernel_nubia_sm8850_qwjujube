__int64 __fastcall cam_isp_subdev_handle_message(__int64 result)
{
  __int64 v1; // x20
  unsigned int v2; // w24

  v1 = *(_QWORD *)(result + 240);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "cam_isp_subdev_handle_message",
               89,
               "node name %s",
               (const char *)v1);
    if ( !*(_DWORD *)(v1 + 104) )
      return result;
  }
  else if ( !*(_DWORD *)(v1 + 104) )
  {
    return result;
  }
  v2 = 0;
  do
  {
    result = cam_context_handle_message(*(_QWORD *)(v1 + 96) + 552LL * (int)v2);
    if ( (_DWORD)result )
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 8,
                 1,
                 "cam_isp_subdev_handle_message",
                 93,
                 "Failed to handle message for %s",
                 (const char *)v1);
    ++v2;
  }
  while ( v2 < *(_DWORD *)(v1 + 104) );
  return result;
}
