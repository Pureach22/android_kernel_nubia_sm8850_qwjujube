__int64 __fastcall cam_ipe_deinit_soc_resources(__int64 a1)
{
  _QWORD *v1; // x20
  _QWORD *v3; // x0
  __int64 result; // x0

  v1 = *(_QWORD **)(a1 + 3296);
  if ( v1 )
  {
    v3 = (_QWORD *)v1[1];
    if ( v3 )
    {
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v3, 0);
      else
        kvfree(v3);
      v1[1] = 0;
    }
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v1, 0);
    else
      kvfree(v1);
  }
  result = cam_soc_util_release_platform_resource(a1);
  if ( (_DWORD)result )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             256,
             2,
             "cam_ipe_deinit_soc_resources",
             167,
             "release platform resources fail");
  return result;
}
