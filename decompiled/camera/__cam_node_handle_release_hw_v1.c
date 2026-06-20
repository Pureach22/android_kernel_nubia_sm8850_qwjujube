__int64 __fastcall _cam_node_handle_release_hw_v1(const char *a1, __int64 a2)
{
  unsigned int v4; // w0
  const char *v5; // x5
  unsigned int v6; // w19
  __int64 v7; // x4
  unsigned int v8; // w0
  __int64 result; // x0
  const char *device_priv; // x0
  __int64 v11; // x20
  unsigned int v12; // w21
  int v13; // w7
  int v14; // w9
  unsigned int v15; // w20

  v4 = cam_handle_validate(*(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 8));
  if ( v4 )
  {
    v5 = "Invalid session handle for context";
    v6 = v4;
    v7 = 542;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_release_hw_v1",
      v7,
      v5);
    return v6;
  }
  v8 = cam_handle_validate(*(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 12));
  if ( v8 )
  {
    v5 = "Invalid device handle for context";
    v6 = v8;
    v7 = 548;
    goto LABEL_5;
  }
  device_priv = (const char *)cam_get_device_priv(*(_DWORD *)(a2 + 12));
  if ( device_priv )
  {
    v11 = (__int64)device_priv;
    if ( !strcmp(a1, device_priv) )
    {
      result = cam_context_handle_release_hw(v11, a2);
      if ( (_DWORD)result )
      {
        v12 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          2,
          1,
          "__cam_node_handle_release_hw_v1",
          567,
          "context release failed node %s",
          a1);
        result = v12;
      }
      if ( (debug_mdl & 2) != 0 && !debug_priority )
      {
        v13 = *(_DWORD *)(v11 + 32);
        v14 = *(_DWORD *)(v11 + 404);
        v15 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 2,
          4,
          "__cam_node_handle_release_hw_v1",
          571,
          "[%s] Release ctx_id=%d, refcount=%d",
          a1,
          v13,
          v14);
        return v15;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        2,
        1,
        "__cam_node_handle_release_hw_v1",
        561,
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
      "__cam_node_handle_release_hw_v1",
      555,
      "Can not get context for handle %d node %s",
      *(_DWORD *)(a2 + 12),
      a1);
    return 4294967274LL;
  }
  return result;
}
