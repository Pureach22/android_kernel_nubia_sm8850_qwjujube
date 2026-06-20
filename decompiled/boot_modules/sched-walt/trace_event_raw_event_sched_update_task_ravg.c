__int64 __fastcall trace_event_raw_event_sched_update_task_ravg(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        __int64 a6,
        _QWORD *a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v13; // x8
  __int64 v18; // x9
  int v19; // w27
  __int64 result; // x0
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x20
  size_t v26; // x2
  int v27; // w8
  _QWORD v29[7]; // [xsp+8h] [xbp-38h] BYREF

  v13 = a1;
  v29[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_QWORD *)(a1 + 72);
  memset(v29, 0, 48);
  if ( (v18 & 0x2C0) == 0
    || (v18 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v13 = a1, (result & 1) == 0) )
  {
    v19 = nr_cpu_ids;
    result = trace_event_buffer_reserve(v29, v13, 8 * nr_cpu_ids + 216LL);
    if ( result )
    {
      *(_QWORD *)(result + 40) = a5;
      *(_DWORD *)(result + 168) = ((unsigned __int16)v19 << 18) | 0xD8;
      *(_DWORD *)(result + 172) = (4 * v19 + 216) | (v19 << 18);
      v21 = *(_QWORD *)(a8 + 64);
      *(_DWORD *)(result + 88) = a4;
      *(_QWORD *)(result + 64) = v21;
      *(_QWORD *)(result + 72) = a5 - v21;
      *(_DWORD *)(result + 104) = *(_DWORD *)(a3 + 3632);
      *(_DWORD *)(result + 28) = *(_DWORD *)(*(_QWORD *)(a3 + 3344) + 1800LL);
      *(_DWORD *)(result + 32) = *(_QWORD *)(a8 + 120);
      v22 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v22;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 1800);
      v23 = *(_QWORD *)(a9 + 8);
      *(_QWORD *)(result + 48) = v23;
      *(_QWORD *)(result + 56) = a5 - v23;
      *(_DWORD *)(result + 92) = *(_DWORD *)(a9 + 28);
      *(_DWORD *)(result + 96) = *(_DWORD *)(a9 + 32);
      LODWORD(v23) = *(_DWORD *)(a9 + 24);
      *(_QWORD *)(result + 80) = a6;
      *(_DWORD *)(result + 100) = v23;
      *(_DWORD *)(result + 108) = *(unsigned __int16 *)(a9 + 160);
      *(_QWORD *)(result + 112) = *(_QWORD *)(a8 + 144);
      *(_QWORD *)(result + 120) = *(_QWORD *)(a8 + 152);
      if ( a7 )
      {
        *(_QWORD *)(result + 128) = *a7;
        *(_QWORD *)(result + 136) = a7[1];
        *(_QWORD *)(result + 144) = a7[2];
        v24 = a7[3];
      }
      else
      {
        v24 = 0;
        *(_QWORD *)(result + 136) = 0;
        *(_QWORD *)(result + 144) = 0;
        *(_QWORD *)(result + 128) = 0;
      }
      *(_QWORD *)(result + 152) = v24;
      v25 = result;
      *(_DWORD *)(result + 160) = *(_DWORD *)(a9 + 132);
      v26 = 4LL * nr_cpu_ids;
      *(_DWORD *)(result + 164) = *(_DWORD *)(a9 + 136);
      memcpy((void *)(result + 216), (const void *)(a9 + 68), v26);
      memcpy((void *)(v25 + *(unsigned __int16 *)(v25 + 172)), (const void *)(a9 + 100), 4LL * nr_cpu_ids);
      *(_QWORD *)(v25 + 176) = *(_QWORD *)(a8 + 160);
      *(_QWORD *)(v25 + 184) = *(_QWORD *)(a8 + 168);
      *(_QWORD *)(v25 + 192) = *(_QWORD *)(a9 + 168);
      *(_DWORD *)(v25 + 200) = *(_DWORD *)(a8 + 536);
      v27 = *(_DWORD *)(a8 + 532);
      *(_QWORD *)(v25 + 208) = a10;
      *(_DWORD *)(v25 + 204) = v27;
      result = trace_event_buffer_commit(v29);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
