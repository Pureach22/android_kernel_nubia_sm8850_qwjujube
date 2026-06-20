__int64 __fastcall cam_subdev_ioctl(__int64 a1, int a2, int *a3)
{
  __int64 v3; // x19
  __int64 v5; // x19
  __int64 (__fastcall *v9)(__int64, int *); // x8
  int *v10; // x1
  __int64 v11; // x0
  int v12; // w0
  __int64 v13; // x20

  v3 = *(_QWORD *)(a1 + 240);
  if ( !v3 || !*(_DWORD *)(v3 + 20) )
    return -22;
  if ( a2 != 263 )
  {
    if ( a2 == -1072146752 )
    {
      cam_req_mgr_rwsem_read_op(1);
      v5 = (int)cam_node_handle_ioctl(v3, a3);
      cam_req_mgr_rwsem_read_op(2);
      return v5;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "cam_subdev_ioctl",
      86,
      "Invalid command %d for %s",
      a2,
      (const char *)v3);
    return -22;
  }
  if ( (cam_req_mgr_is_shutdown() & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      2,
      "cam_subdev_ioctl",
      66,
      "SD shouldn't come from user space");
    return 0;
  }
  v9 = *(__int64 (__fastcall **)(__int64, int *))(v3 + 336);
  if ( !v9 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "cam_subdev_ioctl",
      72,
      "No shutdown routine for %s",
      (const char *)v3);
    return -22;
  }
  v10 = a3;
  v11 = a1;
  if ( (debug_mdl & 2) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 2,
      4,
      "cam_subdev_ioctl",
      77,
      "Shutdown for %s from media device",
      (const char *)v3);
    v9 = *(__int64 (__fastcall **)(__int64, int *))(v3 + 336);
    v11 = a1;
    v10 = a3;
  }
  if ( *((_DWORD *)v9 - 1) != 818855893 )
    __break(0x8228u);
  v12 = v9(v11, v10);
  if ( !v12 )
    return 0;
  v13 = v12;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    2,
    1,
    "cam_subdev_ioctl",
    82,
    "shutdown device failed(rc = %d) for %s",
    v12,
    (const char *)v3);
  return v13;
}
