__int64 __fastcall trace_event_raw_event_ipc_update(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v11; // x8
  __int64 v16; // x9
  __int64 result; // x0
  _QWORD v19[7]; // [xsp+8h] [xbp-38h] BYREF

  v11 = a1;
  v19[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 72);
  memset(v19, 0, 48);
  if ( (v16 & 0x2C0) == 0
    || (v16 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v11 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v19, v11, 64);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 40) = a6;
      *(_QWORD *)(result + 48) = a7;
      *(_QWORD *)(result + 56) = a8;
      result = trace_event_buffer_commit(v19);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
