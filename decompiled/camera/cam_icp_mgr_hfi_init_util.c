__int64 __fastcall cam_icp_mgr_hfi_init_util(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w19
  __int64 v4; // x8
  void (__fastcall *v5)(__int64, __int64, int *, __int64); // x9
  __int64 v6; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = cam_icp_mgr_hfi_init(a1);
  if ( v2 )
  {
    v3 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_hfi_init_util",
      5951,
      "[%s] Failed in hfi init, rc %d",
      (const char *)(a1 + 112),
      v2);
    v4 = *(_QWORD *)(a1 + 80);
    v8 = 3;
    v5 = *(void (__fastcall **)(__int64, __int64, int *, __int64))(v4 + 88);
    v6 = *(_QWORD *)(v4 + 112);
    if ( *((_DWORD *)v5 - 1) != -1055839300 )
      __break(0x8229u);
    v5(v6, 15, &v8, 4);
  }
  else
  {
    v3 = cam_icp_mgr_send_memory_region_info(a1);
    if ( v3 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_hfi_init_util",
        5961,
        "[%s] Failed in sending mem region info, rc %d",
        (const char *)(a1 + 112),
        v3);
    else
      *(_BYTE *)(a1 + 44237) = 1;
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
