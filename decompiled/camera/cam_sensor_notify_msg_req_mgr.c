__int64 __fastcall cam_sensor_notify_msg_req_mgr(__int64 a1)
{
  int v1; // w9
  int v2; // w10
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 result; // x0
  unsigned int v6; // w19
  unsigned int v7; // w19
  _DWORD v8[2]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v9; // [xsp+8h] [xbp-38h]
  int v10; // [xsp+10h] [xbp-30h]
  int v11; // [xsp+14h] [xbp-2Ch]
  __int64 v12; // [xsp+18h] [xbp-28h]
  __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+28h] [xbp-18h]
  __int64 v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 7464);
  v2 = *(_DWORD *)(a1 + 7456);
  v3 = *(_QWORD *)(a1 + 7528);
  v14 = 0;
  v15 = 0;
  v8[0] = v1;
  v8[1] = v2;
  v12 = 0;
  v13 = 0;
  v9 = 0;
  v11 = 0;
  v10 = 2;
  if ( v3 && *(_QWORD *)(v3 + 16) )
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 40);
    if ( *((_DWORD *)v4 - 1) != 1498387893 )
      __break(0x8228u);
    result = v4(v8);
    if ( (_DWORD)result )
    {
      v6 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_notify_msg_req_mgr",
        75,
        "Notifying req mgr message: %u failed rc: %d",
        2,
        result);
      result = v6;
    }
  }
  else
  {
    result = 0;
  }
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
  {
    v7 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_notify_msg_req_mgr",
      80,
      "Successfully notified message : %u to req mgr",
      2);
    result = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
