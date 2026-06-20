__int64 __fastcall cam_actuator_update_req_mgr(__int64 a1, __int64 a2)
{
  __int64 v2; // x6
  int v3; // w9
  int v4; // w10
  __int64 v5; // x8
  __int64 (__fastcall *v6)(_QWORD); // x8
  __int64 result; // x0
  __int64 v9; // x6
  unsigned int v10; // w19
  _DWORD v11[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v12; // [xsp+10h] [xbp-20h]
  __int64 v13; // [xsp+18h] [xbp-18h]
  __int64 v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 8);
  v3 = *(_DWORD *)(a1 + 4592);
  v4 = *(_DWORD *)(a1 + 4584);
  v5 = *(_QWORD *)(a1 + 4656);
  v13 = 0;
  v14 = 0;
  v12 = v2;
  v11[0] = v3;
  v11[1] = v4;
  if ( v5 && (v6 = *(__int64 (__fastcall **)(_QWORD))(v5 + 16)) != nullptr )
  {
    if ( *((_DWORD *)v6 - 1) != -1947527126 )
      __break(0x8228u);
    result = v6(v11);
    if ( (_DWORD)result )
    {
      if ( (_DWORD)result == -53 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000,
          3,
          "cam_actuator_update_req_mgr",
          395,
          "Adding request: %llu failed: rc: %d, it has been flushed",
          *(_QWORD *)(a2 + 8),
          -53);
        result = 4294967243LL;
      }
      else
      {
        v9 = *(_QWORD *)(a2 + 8);
        v10 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_update_req_mgr",
          399,
          "Adding request: %llu failed: rc: %d",
          v9,
          result);
        result = v10;
      }
    }
    else if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000,
        4,
        "cam_actuator_update_req_mgr",
        403,
        "Request Id: %lld added to CRM",
        v12);
      result = 0;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_update_req_mgr",
      406,
      "Can't add Request ID: %lld to CRM",
      v2);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
