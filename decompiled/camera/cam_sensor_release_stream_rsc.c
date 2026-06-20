__int64 __fastcall cam_sensor_release_stream_rsc(__int64 result)
{
  __int64 v1; // x19

  v1 = result;
  if ( *(_DWORD *)(result + 7208) == 1 )
  {
    *(_DWORD *)(result + 7208) = -1;
    result = delete_request(result + 7192);
    if ( (result & 0x80000000) != 0 )
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                 3,
                 32,
                 1,
                 "cam_sensor_release_stream_rsc",
                 131,
                 "failed while deleting Streamoff settings");
  }
  if ( *(_DWORD *)(v1 + 7160) == 1 )
  {
    *(_DWORD *)(v1 + 7160) = -1;
    result = delete_request(v1 + 7144);
    if ( (result & 0x80000000) != 0 )
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               32,
               1,
               "cam_sensor_release_stream_rsc",
               140,
               "failed while deleting Streamon settings");
  }
  return result;
}
