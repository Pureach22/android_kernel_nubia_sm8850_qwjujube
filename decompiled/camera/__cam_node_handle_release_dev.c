__int64 __fastcall _cam_node_handle_release_dev(const char *a1, int *a2)
{
  unsigned int v4; // w0
  const char *v5; // x5
  unsigned int v6; // w19
  __int64 v7; // x4
  unsigned int v9; // w0
  const char *device_priv; // x0
  __int64 v11; // x20
  unsigned int v12; // w21

  if ( !a2 )
    return 4294967274LL;
  v4 = cam_handle_validate(*a2, *a2);
  if ( v4 )
  {
    v5 = "Invalid session handle for context";
    v6 = v4;
    v7 = 442;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_release_dev",
      v7,
      v5);
    return v6;
  }
  v9 = cam_handle_validate(*a2, a2[1]);
  if ( v9 )
  {
    v5 = "Invalid device handle for context";
    v6 = v9;
    v7 = 448;
    goto LABEL_7;
  }
  device_priv = (const char *)cam_get_device_priv(a2[1]);
  if ( device_priv )
  {
    v11 = (__int64)device_priv;
    if ( !strcmp(a1, device_priv) )
    {
      if ( (unsigned int)(*(_DWORD *)(v11 + 240) - 1) > 4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          2,
          2,
          "__cam_node_handle_release_dev",
          473,
          "node %s context id %u state %d invalid to release hdl",
          a1,
          *(_DWORD *)(v11 + 32),
          *(_DWORD *)(v11 + 240));
      }
      else
      {
        if ( (unsigned int)cam_context_handle_release_dev(v11, (__int64)a2) )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            2,
            1,
            "__cam_node_handle_release_dev",
            469,
            "context release failed for node %s",
            a1);
        cam_context_putref(v11);
      }
      v12 = cam_destroy_device_hdl((unsigned int)a2[1]);
      if ( v12 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          2,
          1,
          "__cam_node_handle_release_dev",
          483,
          "destroy device hdl failed for node %s",
          a1);
      else
        *(_DWORD *)(v11 + 60) = -1;
      if ( (debug_mdl & 2) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 2,
          4,
          "__cam_node_handle_release_dev",
          489,
          "[%s] Release ctx_id=%d, refcount=%d",
          a1,
          *(_DWORD *)(v11 + 32),
          *(_DWORD *)(v11 + 404));
      return v12;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        2,
        1,
        "__cam_node_handle_release_dev",
        461,
        "node name %s dev name:%s not matching",
        a1,
        (const char *)v11);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_release_dev",
      455,
      "Can not get context for handle %d node %s",
      a2[1],
      a1);
    return 4294967274LL;
  }
}
