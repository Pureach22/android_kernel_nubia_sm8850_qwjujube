__int64 __fastcall trace_event_raw_event_core_ctl_update_nr_need(
        __int64 a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  __int64 v16; // x8
  __int64 v21; // x9
  __int64 result; // x0
  _QWORD v24[7]; // [xsp+8h] [xbp-38h] BYREF

  v16 = a1;
  v24[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = *(_QWORD *)(a1 + 72);
  memset(v24, 0, 48);
  if ( (v21 & 0x2C0) == 0
    || (v21 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v16 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v24, v16, 56);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 36) = a9;
      *(_DWORD *)(result + 40) = a10;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = a5;
      *(_DWORD *)(result + 24) = a6;
      *(_DWORD *)(result + 28) = a7;
      *(_DWORD *)(result + 32) = a8;
      *(_DWORD *)(result + 44) = a11;
      *(_DWORD *)(result + 48) = a12;
      *(_DWORD *)(result + 52) = a13;
      result = trace_event_buffer_commit(v24);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
