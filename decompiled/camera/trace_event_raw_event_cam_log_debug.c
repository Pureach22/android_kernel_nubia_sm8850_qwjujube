__int64 __fastcall trace_event_raw_event_cam_log_debug(__int64 a1, const char *a2, __int64 *a3)
{
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 result; // x0
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x11
  __int64 v11; // x12
  _QWORD arg[6]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v14; // [xsp+38h] [xbp-48h]
  __int64 v15; // [xsp+40h] [xbp-40h]
  _QWORD v16[7]; // [xsp+48h] [xbp-38h] BYREF

  v5 = a1;
  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v5 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v16, v5, 524);
    if ( result )
    {
      *(_DWORD *)(result + 8) = 33554444;
      v8 = a3[3];
      v10 = *a3;
      v9 = a3[1];
      v14 = a3[2];
      v15 = v8;
      arg[4] = v10;
      arg[5] = v9;
      v11 = *(unsigned __int16 *)(result + 8);
      arg[0] = v10;
      arg[1] = v9;
      arg[2] = v14;
      arg[3] = v8;
      vsnprintf((char *)(result + v11), 0x200u, a2, arg);
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
