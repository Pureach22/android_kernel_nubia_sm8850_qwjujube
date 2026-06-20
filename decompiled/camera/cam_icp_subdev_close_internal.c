__int64 __fastcall cam_icp_subdev_close_internal(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x6
  unsigned int v3; // w19
  __int64 v4; // x20
  int v6; // w9

  v1 = *(_QWORD *)(a1 + 240);
  if ( !v1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_subdev_close_internal",
      217,
      "device[%s] Invalid params: node is NULL",
      (const char *)(a1 + 184));
    v4 = 0;
    v3 = -22;
LABEL_11:
    mutex_unlock(v4 + 343056);
    return v3;
  }
  v2 = *(unsigned int *)(v1 + 24);
  if ( (unsigned int)v2 < 2 )
  {
    v4 = g_icp_dev[v2];
    mutex_lock(v4 + 343056);
    v6 = *(_DWORD *)(v4 + 343104);
    if ( v6 <= 0 )
    {
      v3 = 0;
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_subdev_close_internal",
          232,
          "device[%s] is already closed",
          (const char *)(a1 + 184));
        v3 = 0;
      }
    }
    else
    {
      *(_DWORD *)(v4 + 343104) = v6 - 1;
      v3 = cam_node_shutdown(v1);
      if ( (v3 & 0x80000000) != 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_subdev_close_internal",
          249,
          "device[%s] HW close failed",
          (const char *)(a1 + 184));
    }
    goto LABEL_11;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_subdev_close_internal",
    224,
    "Invalid device idx: %u for device: %s",
    v2,
    (const char *)v1);
  return (unsigned int)-19;
}
