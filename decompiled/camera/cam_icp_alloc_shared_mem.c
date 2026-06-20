__int64 __fastcall cam_icp_alloc_shared_mem(__int64 a1, __int64 a2, _QWORD *a3)
{
  int v5; // w9
  unsigned int v6; // w19
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x8
  __int64 v11; // [xsp+18h] [xbp-48h] BYREF
  __int64 v12; // [xsp+20h] [xbp-40h]
  __int64 v13; // [xsp+28h] [xbp-38h]
  __int64 v14; // [xsp+30h] [xbp-30h]
  __int64 v15; // [xsp+38h] [xbp-28h]
  __int64 v16[2]; // [xsp+40h] [xbp-20h] BYREF
  int v17; // [xsp+50h] [xbp-10h]
  int v18; // [xsp+54h] [xbp-Ch]
  __int64 v19; // [xsp+58h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 148);
  v16[0] = a2;
  v16[1] = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v11 = 0;
  v17 = v5;
  v18 = 2049;
  v6 = cam_mem_mgr_request_mem(v16, (__int64)&v11);
  if ( v6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_alloc_shared_mem",
      3783,
      "[%s] Failed in alloc shared mem rc %d",
      (const char *)(a1 + 112),
      v6);
  }
  else
  {
    v7 = v15;
    v8 = v13;
    a3[3] = v14;
    a3[4] = v7;
    v9 = v11;
    a3[1] = v12;
    a3[2] = v8;
    *a3 = v9;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_alloc_shared_mem",
        3790,
        "[%s] kva: %llX, iova: %x, hdl: %x, len: %lld",
        (const char *)(a1 + 112),
        v11,
        v12,
        v13,
        v14);
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
