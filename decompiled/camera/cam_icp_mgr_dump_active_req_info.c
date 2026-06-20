__int64 __fastcall cam_icp_mgr_dump_active_req_info(__int64 a1)
{
  __int64 v2; // x25
  int v3; // w24
  int v4; // w20
  const char *v5; // x7
  __int64 v6; // x21
  __int64 v7; // x20
  unsigned __int64 v8; // x22
  __int64 v9; // x3
  __int64 result; // x0
  int v11; // [xsp+Ch] [xbp-114h]
  _QWORD v12[34]; // [xsp+10h] [xbp-110h] BYREF

  v12[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v12, 0, 256);
  mutex_lock(a1);
  v2 = 0;
  v3 = 0;
  v4 = 0;
  do
  {
    mutex_lock(*(_QWORD *)(a1 + 88) + 48 * v2);
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v2);
    if ( v6 && *(_DWORD *)(v6 + 104) == 2 )
    {
      v11 = v4;
      v7 = 0;
      v8 = 0;
      do
      {
        v9 = *(_QWORD *)(v6 + 1784 + v7);
        if ( v9 )
        {
          if ( v8 > 0x100 )
            __break(0x5512u);
          v8 += (int)scnprintf((char *)v12 + v8, 256 - v8, " %llu", v9);
          ++v3;
        }
        v7 += 8;
      }
      while ( v7 != 320 );
      if ( v8 )
        v5 = (const char *)v12;
      else
        v5 = " None";
      v4 = v11 + 1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        3,
        "cam_icp_mgr_dump_active_req_info",
        2581,
        "%s: Active Requests IDs: %s",
        (const char *)(v6 + 29824),
        v5);
    }
    mutex_unlock(*(_QWORD *)(a1 + 88) + 48 * v2++);
  }
  while ( v2 != 54 );
  mutex_unlock(a1);
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             256,
             3,
             "cam_icp_mgr_dump_active_req_info",
             2587,
             "%s: Total Active streams: %u, Total active requests: %u",
             (const char *)(a1 + 112),
             v4,
             v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
