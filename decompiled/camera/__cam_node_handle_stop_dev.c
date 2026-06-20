__int64 __fastcall _cam_node_handle_stop_dev(const char *a1, int *a2)
{
  unsigned int v4; // w0
  const char *v5; // x5
  unsigned int v6; // w19
  __int64 v7; // x4
  __int64 result; // x0
  unsigned int v9; // w0
  const char *device_priv; // x0
  const char *v11; // x21
  unsigned int v12; // w20

  if ( !a2 )
    return 4294967274LL;
  v4 = cam_handle_validate(*a2, *a2);
  if ( v4 )
  {
    v5 = "Invalid session handle for context";
    v6 = v4;
    v7 = 311;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_stop_dev",
      v7,
      v5);
    return v6;
  }
  v9 = cam_handle_validate(*a2, a2[1]);
  if ( v9 )
  {
    v5 = "Invalid device handle for context";
    v6 = v9;
    v7 = 317;
    goto LABEL_7;
  }
  device_priv = (const char *)cam_get_device_priv(a2[1]);
  if ( device_priv )
  {
    v11 = device_priv;
    if ( !strcmp(a1, device_priv) )
    {
      result = cam_context_handle_stop_dev((__int64)v11, (__int64)a2);
      if ( (_DWORD)result )
      {
        v12 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          2,
          1,
          "__cam_node_handle_stop_dev",
          336,
          "Stop failure for node %s",
          a1);
        return v12;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        2,
        1,
        "__cam_node_handle_stop_dev",
        330,
        "node name %s dev name:%s not matching",
        a1,
        v11);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_stop_dev",
      324,
      "Can not get context for handle %d",
      a2[1]);
    return 4294967274LL;
  }
  return result;
}
