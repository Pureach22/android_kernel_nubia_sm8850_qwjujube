__int64 __fastcall cam_sensor_release_per_frame_resource(__int64 result)
{
  _QWORD *v1; // x19
  __int64 i; // x22
  __int64 v3; // x24
  __int64 j; // x22
  __int64 v5; // x24
  __int64 k; // x22
  __int64 v7; // x24
  __int64 m; // x22
  __int64 v9; // x24

  v1 = (_QWORD *)result;
  if ( *(_QWORD *)(result + 7296) )
  {
    for ( i = 0; i != 1536; i += 48 )
    {
      v3 = v1[912];
      result = v3 + i;
      if ( *(_DWORD *)(v3 + i + 16) == 1 )
      {
        *(_DWORD *)(result + 16) = -1;
        result = delete_request(result);
        if ( (result & 0x80000000) != 0 )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     32,
                     1,
                     "cam_sensor_release_per_frame_resource",
                     159,
                     "delete deferred frame_update setting for request: %lld rc: %d",
                     *(_QWORD *)(v3 + i + 24),
                     result);
      }
    }
  }
  if ( v1[911] )
  {
    for ( j = 0; j != 1536; j += 48 )
    {
      v5 = v1[911];
      result = v5 + j;
      if ( *(_DWORD *)(v5 + j + 16) == 1 )
      {
        *(_DWORD *)(result + 16) = -1;
        result = delete_request(result);
        if ( (result & 0x80000000) != 0 )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     32,
                     1,
                     "cam_sensor_release_per_frame_resource",
                     173,
                     "delete per frame setting for request: %lld rc: %d",
                     *(_QWORD *)(v5 + j + 24),
                     result);
      }
    }
  }
  if ( v1[913] )
  {
    for ( k = 0; k != 1536; k += 48 )
    {
      v7 = v1[913];
      result = v7 + k;
      if ( *(_DWORD *)(v7 + k + 16) == 1 )
      {
        *(_DWORD *)(result + 16) = -1;
        result = delete_request(result);
        if ( (result & 0x80000000) != 0 )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     32,
                     1,
                     "cam_sensor_release_per_frame_resource",
                     187,
                     "delete frame skip setting for request: %lld rc: %d",
                     *(_QWORD *)(v7 + k + 24),
                     result);
      }
    }
  }
  if ( v1[914] )
  {
    for ( m = 0; m != 1536; m += 48 )
    {
      v9 = v1[914];
      result = v9 + m;
      if ( *(_DWORD *)(v9 + m + 16) == 1 )
      {
        *(_DWORD *)(result + 16) = -1;
        result = delete_request(result);
        if ( (result & 0x80000000) != 0 )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     32,
                     1,
                     "cam_sensor_release_per_frame_resource",
                     201,
                     "delete bubble update setting for request: %lld rc: %d",
                     *(_QWORD *)(v9 + m + 24),
                     result);
      }
    }
  }
  return result;
}
