__int64 __fastcall cam_ife_csid_ver2_send_secure_info(__int64 a1, __int64 a2)
{
  int v2; // w7
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x10
  int v6; // w6
  int v7; // w6
  __int64 result; // x0
  __int64 v9; // x22
  _DWORD v10[2]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v11; // [xsp+28h] [xbp-18h]
  int v12; // [xsp+30h] [xbp-10h]
  int v13; // [xsp+34h] [xbp-Ch]
  __int64 v14; // [xsp+38h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a2 + 2080);
  v3 = 1LL << *(_DWORD *)(a1 + 12);
  v4 = **(_QWORD **)(a2 + 31136);
  v5 = *(_QWORD *)(a2 + 31120);
  v10[1] = v2;
  v13 = v3;
  v11 = 0;
  v6 = *(_DWORD *)(v5 + 4);
  v12 = 1LL << v6;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v9 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_send_secure_info",
      7144,
      "PHY secure info for CSID[%u], lane_cfg: 0x%x, ife: 0x%x, cdm: 0x%x, vc_mask: 0x%llx",
      v6,
      v2,
      1LL << v6,
      v3,
      0);
    a2 = v9;
  }
  v7 = *(_DWORD *)(a2 + 2068) - *(_DWORD *)(*(_QWORD *)(v4 + 120) + 588LL);
  if ( v7 < 0 )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               2,
               "cam_ife_csid_ver2_send_secure_info",
               7150,
               "Can't notify csiphy, incorrect phy selected=%d",
               v7);
  }
  else
  {
    v10[0] = *(_DWORD *)(a2 + 2068) - *(_DWORD *)(*(_QWORD *)(v4 + 120) + 588LL);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_send_secure_info",
        7153,
        "Notify CSIPHY: %d",
        v7);
    result = cam_subdev_notify_message(65544, 3u, (__int64)v10);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
