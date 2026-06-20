__int64 __fastcall trace_event_raw_event_sched_update_history(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        int a6,
        __int64 a7,
        __int64 a8,
        __int16 a9)
{
  __int64 v12; // x8
  __int64 v17; // x9
  __int64 result; // x0
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x9
  __int64 v23; // x20
  _QWORD v25[7]; // [xsp+8h] [xbp-38h] BYREF

  v12 = a1;
  v25[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a1 + 72);
  memset(v25, 0, 48);
  if ( (v17 & 0x2C0) == 0
    || (v17 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v12 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v25, v12, 112);
    if ( result )
    {
      v19 = *(_QWORD *)(a3 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a3 + 2320);
      *(_QWORD *)(result + 16) = v19;
      LODWORD(v19) = *(_DWORD *)(a3 + 1800);
      *(_DWORD *)(result + 32) = a5;
      *(_DWORD *)(result + 36) = a6;
      *(_DWORD *)(result + 24) = v19;
      *(_DWORD *)(result + 28) = a4;
      *(_DWORD *)(result + 40) = *(_DWORD *)(a8 + 28);
      *(_DWORD *)(result + 44) = *(_DWORD *)(a8 + 32);
      *(_DWORD *)(result + 48) = *(unsigned __int16 *)(a8 + 160);
      v20 = *(_QWORD *)(a8 + 44);
      v21 = *(_QWORD *)(a8 + 36);
      *(_DWORD *)(result + 68) = *(_DWORD *)(a8 + 52);
      *(_QWORD *)(result + 60) = v20;
      *(_QWORD *)(result + 52) = v21;
      v22 = *(_QWORD *)(a8 + 56);
      *(_WORD *)(result + 80) = *(_WORD *)(a8 + 64);
      *(_QWORD *)(result + 72) = v22;
      *(_DWORD *)(result + 84) = *(_DWORD *)(a7 + 24);
      LODWORD(v19) = *(_DWORD *)(a2 + 3632);
      *(_WORD *)(result + 92) = a9;
      *(_DWORD *)(result + 88) = v19;
      LOBYTE(v19) = *(_BYTE *)(a8 + 384);
      v23 = result;
      *(_BYTE *)(result + 94) = v19;
      *(_QWORD *)(result + 96) = uclamp_eff_value(a3, 0);
      *(_QWORD *)(v23 + 104) = uclamp_eff_value(a3, 1);
      result = trace_event_buffer_commit(v25);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
