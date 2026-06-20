__int64 __fastcall _cam_node_handle_acquire_hw_v2(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  const char *v5; // x5
  unsigned int v6; // w19
  __int64 v7; // x4
  unsigned int v8; // w0
  __int64 result; // x0
  const char *device_priv; // x0
  __int64 v11; // x20
  unsigned int v12; // w20
  unsigned int v13; // w21

  v4 = cam_handle_validate(*(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 8));
  if ( v4 )
  {
    v5 = "Invalid session handle for context";
    v6 = v4;
    v7 = 222;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_acquire_hw_v2",
      v7,
      v5);
    return v6;
  }
  v8 = cam_handle_validate(*(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 12));
  if ( v8 )
  {
    v5 = "Invalid device handle for context";
    v6 = v8;
    v7 = 228;
    goto LABEL_5;
  }
  device_priv = (const char *)cam_get_device_priv(*(_DWORD *)(a2 + 12));
  if ( device_priv )
  {
    v11 = (__int64)device_priv;
    if ( !strcmp((const char *)a1, device_priv) )
    {
      result = cam_context_handle_acquire_hw(v11, a2);
      if ( (_DWORD)result )
      {
        v12 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          2,
          1,
          "__cam_node_handle_acquire_hw_v2",
          248,
          "Acquire device failed for node %s",
          (const char *)a1);
        if ( *(_DWORD *)(a1 + 104) )
        {
          v13 = 0;
          do
            cam_context_handle_info_dump(*(_QWORD *)(a1 + 96) + 552LL * (int)v13++, 1u);
          while ( v13 < *(_DWORD *)(a1 + 104) );
        }
        return v12;
      }
      else if ( (debug_mdl & 2) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 2,
          4,
          "__cam_node_handle_acquire_hw_v2",
          254,
          "[%s] Acquire ctx_id %d",
          (const char *)a1,
          *(_DWORD *)(v11 + 32));
        return 0;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        2,
        1,
        "__cam_node_handle_acquire_hw_v2",
        241,
        "node name %s dev name:%s not matching",
        (const char *)a1,
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
      "__cam_node_handle_acquire_hw_v2",
      235,
      "Can not get context for handle %d",
      *(_DWORD *)(a2 + 12));
    return 4294967274LL;
  }
  return result;
}
