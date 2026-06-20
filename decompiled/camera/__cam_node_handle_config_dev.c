__int64 __fastcall _cam_node_handle_config_dev(const char *a1, int *a2)
{
  unsigned int v4; // w0
  const char *v5; // x5
  unsigned int v6; // w19
  __int64 v7; // x4
  __int64 result; // x0
  unsigned int v9; // w0
  const char *device_priv; // x0
  __int64 v11; // x21
  unsigned int v12; // w20
  const char *v13; // x5
  __int64 v14; // x2
  __int64 v15; // x4

  if ( !a2 )
    return 4294967274LL;
  v4 = cam_handle_validate(*a2, *a2);
  if ( v4 )
  {
    v5 = "Invalid session handle for context";
    v6 = v4;
    v7 = 352;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_config_dev",
      v7,
      v5);
    return v6;
  }
  v9 = cam_handle_validate(*a2, a2[1]);
  if ( v9 )
  {
    v5 = "Invalid device handle for context";
    v6 = v9;
    v7 = 358;
    goto LABEL_7;
  }
  device_priv = (const char *)cam_get_device_priv(a2[1]);
  if ( !device_priv )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_config_dev",
      365,
      "Can not get context for handle %d",
      a2[1]);
    return 4294967274LL;
  }
  v11 = (__int64)device_priv;
  if ( strcmp(a1, device_priv) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_config_dev",
      371,
      "node name %s dev name:%s not matching",
      a1,
      (const char *)v11);
    return 4294967274LL;
  }
  result = cam_context_handle_config_dev(v11, (__int64)a2);
  if ( (_DWORD)result )
  {
    v12 = result;
    if ( *(_DWORD *)(v11 + 240) == 4 )
    {
      v13 = "Config failure for node %s, it has been flushed";
      v14 = 3;
      v15 = 380;
    }
    else
    {
      v13 = "Config failure for node %s";
      v14 = 1;
      v15 = 382;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
      3,
      2,
      v14,
      "__cam_node_handle_config_dev",
      v15,
      v13,
      a1);
    return v12;
  }
  return result;
}
