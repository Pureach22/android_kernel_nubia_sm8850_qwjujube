__int64 __fastcall trace_event_raw_event_rmnet_mod_template(
        __int64 a1,
        char a2,
        char a3,
        int a4,
        int a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v12; // x8
  __int64 v17; // x9
  __int64 result; // x0
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v12 = a1;
  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v17 & 0x2C0) == 0
    || (v17 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v12 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v20, v12, 56);
    if ( result )
    {
      *(_BYTE *)(result + 8) = a2;
      *(_BYTE *)(result + 9) = a3;
      *(_DWORD *)(result + 12) = a4;
      *(_DWORD *)(result + 16) = a5;
      *(_QWORD *)(result + 24) = a6;
      *(_QWORD *)(result + 32) = a7;
      *(_QWORD *)(result + 40) = a8;
      *(_QWORD *)(result + 48) = a9;
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
