__int64 __fastcall trace_event_raw_event_sched_update_task_ravg_mini(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        __int64 a6,
        _QWORD *a7,
        _QWORD *a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v13; // x8
  __int64 v17; // x9
  __int64 result; // x0
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x10
  int v23; // w8
  _QWORD v25[7]; // [xsp+8h] [xbp-38h] BYREF

  v13 = a1;
  v25[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a1 + 72);
  memset(v25, 0, 48);
  if ( (v17 & 0x2C0) == 0
    || (v17 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v13 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v25, v13, 136);
    if ( result )
    {
      *(_QWORD *)(result + 32) = a5;
      v19 = a8[8];
      *(_DWORD *)(result + 72) = a4;
      *(_QWORD *)(result + 56) = v19;
      *(_QWORD *)(result + 64) = a5 - v19;
      *(_DWORD *)(result + 80) = *(_DWORD *)(a3 + 3632);
      v20 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v20;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 1800);
      v21 = *(_QWORD *)(a9 + 8);
      *(_QWORD *)(result + 40) = v21;
      *(_QWORD *)(result + 48) = a5 - v21;
      *(_DWORD *)(result + 76) = *(_DWORD *)(a9 + 28);
      *(_QWORD *)(result + 88) = a8[18];
      *(_QWORD *)(result + 96) = a8[19];
      if ( a7 )
      {
        *(_QWORD *)(result + 104) = *a7;
        v22 = a7[1];
      }
      else
      {
        v22 = 0;
        *(_QWORD *)(result + 104) = 0;
      }
      *(_QWORD *)(result + 112) = v22;
      *(_DWORD *)(result + 120) = *(_DWORD *)(a9 + 132);
      v23 = *(_DWORD *)(a9 + 136);
      *(_QWORD *)(result + 128) = a10;
      *(_DWORD *)(result + 124) = v23;
      result = trace_event_buffer_commit(v25);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
