__int64 __fastcall cam_icp_mgr_register_hfi_client(__int64 a1)
{
  __int64 v1; // x22
  const char *v2; // x21
  unsigned int v3; // w0
  unsigned int v4; // w20
  __int64 (__fastcall *v5)(__int64, __int64, int *, __int64); // x9
  __int64 v6; // x0
  int v8; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 80);
  if ( v1 )
  {
    *(_DWORD *)(a1 + 156) = 2;
    v2 = (const char *)(a1 + 156);
    v3 = cam_hfi_register(a1 + 156, a1 + 112);
    if ( v3 )
    {
      v4 = v3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_register_hfi_client",
        9964,
        "[%s] Fail to register hw mgr as hfi client rc=%d",
        v2 - 44,
        v3);
    }
    else
    {
      v5 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v1 + 88);
      v6 = *(_QWORD *)(v1 + 112);
      v8 = *(_DWORD *)v2;
      if ( *((_DWORD *)v5 - 1) != -1055839300 )
        __break(0x8229u);
      v4 = v5(v6, 16, &v8, 4);
      if ( v4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_register_hfi_client",
          9973,
          "[%s] Fail to share hfi handle to ICP core rc=%d hfi hdl: %d",
          v2 - 44,
          v4,
          v8);
        ((void (__fastcall *)(const char *))cam_hfi_unregister)(v2);
      }
      else if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_mgr_register_hfi_client",
          9979,
          "[%s] successfully registered as hfi client with handle: %d",
          v2 - 44,
          v8);
        v4 = 0;
      }
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_register_hfi_client",
      9956,
      "[%s] ICP device interface is NULL",
      (const char *)(a1 + 112));
    v4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
