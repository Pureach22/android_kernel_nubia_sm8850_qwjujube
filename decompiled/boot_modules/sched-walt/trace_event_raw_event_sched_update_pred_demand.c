__int64 __fastcall trace_event_raw_event_sched_update_pred_demand(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  __int64 v11; // x8
  __int64 v16; // x9
  __int64 result; // x0
  __int64 v18; // x8
  __int64 v19; // x9
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v11 = a1;
  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v16 & 0x2C0) == 0
    || (v16 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v11 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v21, v11, 68);
    if ( result )
    {
      v18 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v18;
      LODWORD(v18) = *(_DWORD *)(a2 + 1800);
      *(_DWORD *)(result + 28) = a3;
      *(_DWORD *)(result + 32) = a4;
      *(_DWORD *)(result + 24) = v18;
      v19 = *(_QWORD *)(a8 + 140);
      *(_QWORD *)(result + 44) = *(_QWORD *)(a8 + 148);
      *(_QWORD *)(result + 36) = v19;
      LODWORD(v18) = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 60) = a6;
      *(_DWORD *)(result + 64) = a7;
      *(_DWORD *)(result + 52) = v18;
      *(_DWORD *)(result + 56) = a5;
      result = trace_event_buffer_commit(v21);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
