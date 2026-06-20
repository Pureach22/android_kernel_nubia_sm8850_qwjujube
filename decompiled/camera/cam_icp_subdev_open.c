__int64 __fastcall cam_icp_subdev_open(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x6
  __int64 v5; // x20
  unsigned int v6; // w22
  _DWORD *v7; // x8
  __int64 v8; // x0

  v1 = *(_QWORD *)(a1 + 240);
  if ( v1 )
  {
    cam_req_mgr_rwsem_read_op(1);
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_subdev_open",
        174,
        "Enter device open for %s[%u]",
        (const char *)(a1 + 184),
        *(_DWORD *)(v1 + 24));
    v3 = *(unsigned int *)(v1 + 24);
    if ( (unsigned int)v3 < 2 )
    {
      v5 = g_icp_dev[v3];
      mutex_lock(v5 + 343056);
      if ( *(int *)(v5 + 343104) < 1 )
      {
        v7 = *(_DWORD **)(v1 + 216);
        v8 = *(_QWORD *)(v1 + 112);
        if ( *(v7 - 1) != 1863972096 )
          __break(0x8228u);
        v6 = ((__int64 (__fastcall *)(__int64, _QWORD))v7)(v8, 0);
        if ( (v6 & 0x80000000) != 0 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_subdev_open",
            195,
            "FW download failed for device [%s]",
            (const char *)(a1 + 184));
        else
          ++*(_DWORD *)(v5 + 343104);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_subdev_open",
          187,
          "device[%s] is already opened, open count: %u",
          a1 + 184);
        v6 = -114;
      }
      mutex_unlock(v5 + 343056);
      cam_req_mgr_rwsem_read_op(2);
      return v6;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_subdev_open",
        178,
        "Invalid device idx: %u for device: %s",
        v3,
        (const char *)(a1 + 184));
      cam_req_mgr_rwsem_read_op(2);
      return 4294967277LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_subdev_open",
      168,
      "Invalid params: Node is NULL");
    return 4294967274LL;
  }
}
