__int64 __fastcall cam_sensor_update_req_mgr(__int64 a1, __int64 a2)
{
  int v3; // w9
  __int64 v4; // x6
  __int64 v5; // x8
  __int64 (__fastcall *v6)(_QWORD); // x8
  unsigned int v7; // w0
  unsigned int v8; // w20
  const char *v9; // x5
  __int64 v10; // x2
  __int64 v11; // x4
  __int64 v12; // x7
  __int64 v14; // x20
  _DWORD v15[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v16; // [xsp+10h] [xbp-20h]
  __int64 v17; // [xsp+18h] [xbp-18h]
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 7464);
  v4 = *(_QWORD *)(a2 + 8);
  v17 = 0;
  v18 = 0;
  v15[0] = v3;
  v16 = v4;
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
  {
    v14 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_update_req_mgr",
      96,
      " Rxed Req Id: %llu",
      v4);
    a1 = v14;
  }
  v5 = *(_QWORD *)(a1 + 7528);
  v15[1] = *(_DWORD *)(a1 + 7456);
  if ( !v5 )
    goto LABEL_11;
  v6 = *(__int64 (__fastcall **)(_QWORD))(v5 + 16);
  if ( !v6 )
    goto LABEL_11;
  if ( *((_DWORD *)v6 - 1) != -1947527126 )
    __break(0x8228u);
  v7 = v6(v15);
  if ( v7 )
  {
    v8 = v7;
    if ( v7 == -53 )
    {
      v9 = "Adding request: %llu failed with request manager rc: %d, it has been flushed";
      v10 = 3;
      v11 = 105;
      v12 = 4294967243LL;
    }
    else
    {
      v9 = "Adding request: %llu failed with request manager rc: %d";
      v10 = 1;
      v11 = 109;
      v12 = v7;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64))cam_print_log)(
      3,
      32,
      v10,
      "cam_sensor_update_req_mgr",
      v11,
      v9,
      *(_QWORD *)(a2 + 8),
      v12);
  }
  else
  {
LABEL_11:
    v8 = 0;
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_update_req_mgr",
        115,
        "Successfully add req: %llu to req mgr",
        v16);
      v8 = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
