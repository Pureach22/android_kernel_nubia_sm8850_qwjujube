__int64 __fastcall _cam_node_handle_flush_dev(const char *a1, __int64 a2)
{
  unsigned int v4; // w0
  const char *v5; // x5
  unsigned int v6; // w19
  __int64 v7; // x4
  __int64 result; // x0
  unsigned int v9; // w0
  const char *device_priv; // x0
  __int64 v11; // x21
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w21
  __int64 v15; // x0

  if ( !a2 )
    return 4294967274LL;
  v4 = cam_handle_validate(*(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 8));
  if ( v4 )
  {
    v5 = "Invalid session handle for context";
    v6 = v4;
    v7 = 398;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_flush_dev",
      v7,
      v5);
    return v6;
  }
  v9 = cam_handle_validate(*(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 12));
  if ( v9 )
  {
    v5 = "Invalid device handle for context";
    v6 = v9;
    v7 = 404;
    goto LABEL_7;
  }
  device_priv = (const char *)cam_get_device_priv(*(_DWORD *)(a2 + 12));
  if ( device_priv )
  {
    v11 = (__int64)device_priv;
    if ( !strcmp(a1, device_priv) )
    {
      result = cam_context_handle_flush_dev(v11, a2);
      if ( (_DWORD)result )
      {
        v14 = result;
        if ( (unsigned int)__ratelimit(&_cam_node_handle_flush_dev__rs_61, "__cam_node_handle_flush_dev") )
          v15 = 3;
        else
          v15 = 2;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
          v15,
          2,
          1,
          "__cam_node_handle_flush_dev",
          426,
          "Flush failure for node %s",
          a1);
        return v14;
      }
    }
    else
    {
      if ( (unsigned int)__ratelimit(&_cam_node_handle_flush_dev__rs_60, "__cam_node_handle_flush_dev") )
        v12 = 3;
      else
        v12 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64))cam_print_log)(
        v12,
        2,
        1,
        "__cam_node_handle_flush_dev",
        419,
        "node name %s dev name:%s not matching",
        a1,
        v11);
      return 4294967274LL;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&_cam_node_handle_flush_dev__rs, "__cam_node_handle_flush_dev") )
      v13 = 3;
    else
      v13 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v13,
      2,
      1,
      "__cam_node_handle_flush_dev",
      412,
      "Can not get context for handle %d",
      *(_DWORD *)(a2 + 12));
    return 4294967274LL;
  }
  return result;
}
