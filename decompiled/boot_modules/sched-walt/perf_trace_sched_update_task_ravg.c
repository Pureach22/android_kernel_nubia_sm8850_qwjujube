__int64 __fastcall perf_trace_sched_update_task_ravg(
        __int64 result,
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
  __int64 v10; // x30
  __int64 v11; // x28
  __int64 v14; // x19
  int v18; // w23
  __int64 v19; // x8
  unsigned int v21; // w21
  _QWORD *v22; // x9
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x22
  size_t v28; // x2
  __int64 v29; // x2
  __int64 v30; // x5
  int v31; // w8
  __int64 v32; // [xsp+0h] [xbp-30h] BYREF
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-28h]
  __int64 v34; // [xsp+10h] [xbp-20h]
  unsigned int v35; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v36[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v32 = a6;
  v11 = v10;
  v14 = result;
  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = nr_cpu_ids;
  v19 = *(_QWORD *)(result + 104);
  v36[0] = 0;
  v35 = 0;
  v34 = v19;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v34) )
  {
    v21 = ((8 * v18 + 227) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v21, v36, &v35);
    if ( result )
    {
      v22 = (_QWORD *)v36[0];
      *(_QWORD *)(v36[0] + 248LL) = &v32;
      v22[29] = &vars0;
      v22[32] = v11;
      v22[33] = 5;
      *(_QWORD *)(result + 40) = a5;
      *(_DWORD *)(result + 168) = ((unsigned __int16)v18 << 18) | 0xD8;
      *(_DWORD *)(result + 172) = (4 * v18 + 216) | (v18 << 18);
      v23 = *(_QWORD *)(a8 + 64);
      *(_DWORD *)(result + 88) = a4;
      *(_QWORD *)(result + 64) = v23;
      *(_QWORD *)(result + 72) = a5 - v23;
      *(_DWORD *)(result + 104) = *(_DWORD *)(a3 + 3632);
      *(_DWORD *)(result + 28) = *(_DWORD *)(*(_QWORD *)(a3 + 3344) + 1800LL);
      *(_DWORD *)(result + 32) = *(_QWORD *)(a8 + 120);
      v24 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v24;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 1800);
      v25 = *(_QWORD *)(a9 + 8);
      *(_QWORD *)(result + 48) = v25;
      *(_QWORD *)(result + 56) = a5 - v25;
      *(_DWORD *)(result + 92) = *(_DWORD *)(a9 + 28);
      *(_DWORD *)(result + 96) = *(_DWORD *)(a9 + 32);
      *(_DWORD *)(result + 100) = *(_DWORD *)(a9 + 24);
      *(_QWORD *)(result + 80) = v32;
      *(_DWORD *)(result + 108) = *(unsigned __int16 *)(a9 + 160);
      *(_QWORD *)(result + 112) = *(_QWORD *)(a8 + 144);
      *(_QWORD *)(result + 120) = *(_QWORD *)(a8 + 152);
      if ( a7 )
      {
        *(_QWORD *)(result + 128) = *a7;
        *(_QWORD *)(result + 136) = a7[1];
        *(_QWORD *)(result + 144) = a7[2];
        v26 = a7[3];
      }
      else
      {
        v26 = 0;
        *(_QWORD *)(result + 136) = 0;
        *(_QWORD *)(result + 144) = 0;
        *(_QWORD *)(result + 128) = 0;
      }
      *(_QWORD *)(result + 152) = v26;
      v27 = result;
      *(_DWORD *)(result + 160) = *(_DWORD *)(a9 + 132);
      v28 = 4LL * nr_cpu_ids;
      *(_DWORD *)(result + 164) = *(_DWORD *)(a9 + 136);
      memcpy((void *)(result + 216), (const void *)(a9 + 68), v28);
      memcpy((void *)(v27 + *(unsigned __int16 *)(v27 + 172)), (const void *)(a9 + 100), 4LL * nr_cpu_ids);
      v29 = v35;
      v30 = v36[0];
      *(_QWORD *)(v27 + 176) = *(_QWORD *)(a8 + 160);
      *(_QWORD *)(v27 + 184) = *(_QWORD *)(a8 + 168);
      *(_QWORD *)(v27 + 192) = *(_QWORD *)(a9 + 168);
      *(_DWORD *)(v27 + 200) = *(_DWORD *)(a8 + 536);
      v31 = *(_DWORD *)(a8 + 532);
      *(_QWORD *)(v27 + 208) = a10;
      *(_DWORD *)(v27 + 204) = v31;
      result = perf_trace_run_bpf_submit(v27, v21, v29, v14, 1, v30, StatusReg + v34, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
