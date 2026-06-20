__int64 __fastcall trace_event_raw_event_adreno_cmdbatch_submitted(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7)
{
  __int64 v13; // x9
  __int64 result; // x0
  __int64 v15; // x8
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v13 & 0x2C0) == 0 || (v13 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v16);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL);
      *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(result + 16) = *a3;
      v15 = *(_QWORD *)(a2 + 24);
      *(_QWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 40) = a6;
      *(_DWORD *)(result + 20) = v15;
      *(_DWORD *)(result + 48) = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 8LL);
      *(_DWORD *)(result + 52) = a3[1];
      *(_DWORD *)(result + 56) = a3[2];
      *(_DWORD *)(result + 60) = a3[3];
      *(_DWORD *)(result + 64) = a7;
      *(_DWORD *)(result + 68) = a3[4];
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
