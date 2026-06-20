__int64 __fastcall cam_sensor_notify_v4l2_error_event(__int64 a1)
{
  unsigned int v2; // w8
  unsigned int v3; // w9
  int v4; // w10
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // [xsp+18h] [xbp-48h] BYREF
  __int64 v8; // [xsp+20h] [xbp-40h]
  unsigned __int64 v9; // [xsp+28h] [xbp-38h]
  __int64 v10; // [xsp+30h] [xbp-30h]
  __int64 v11; // [xsp+38h] [xbp-28h]
  __int64 v12; // [xsp+40h] [xbp-20h]
  __int64 v13; // [xsp+48h] [xbp-18h]
  __int64 v14; // [xsp+50h] [xbp-10h]
  __int64 v15; // [xsp+58h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 7456);
  v3 = *(_DWORD *)(a1 + 7464);
  v9 = 0;
  v10 = 0;
  v4 = *(_DWORD *)(a1 + 7460);
  v7 = 0;
  v8 = 0;
  v9 = __PAIR64__(v3, v2);
  HIDWORD(v10) = 0x4000;
  v5 = *(_QWORD *)(a1 + 7608);
  v13 = 0;
  v14 = 0;
  LODWORD(v7) = v4;
  v11 = 0;
  v12 = 0;
  LODWORD(v8) = 5;
  HIDWORD(v8) = v5;
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_notify_v4l2_error_event",
      45,
      "v4l2 error event [type: %u code: %u] for req: %llu on %s",
      5,
      0x4000,
      v5,
      (const char *)(a1 + 7560));
  result = cam_req_mgr_notify_message(&v7, 1, 0x8000000);
  if ( (_DWORD)result )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               32,
               1,
               "cam_sensor_notify_v4l2_error_event",
               54,
               "Notifying v4l2 error [type: %u code: %u] failed for req id:%llu on %s",
               5,
               0x4000,
               *(_QWORD *)(a1 + 7608),
               (const char *)(a1 + 7560));
  _ReadStatusReg(SP_EL0);
  return result;
}
