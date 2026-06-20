__int64 __fastcall perf_trace_sched_update_task_ravg_mini(
        __int64 result,
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
  __int64 v10; // x30
  __int64 v11; // x26
  __int64 v14; // x19
  __int64 v19; // x27
  unsigned __int64 StatusReg; // x28
  _QWORD *v21; // x9
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x2
  __int64 v27; // x5
  int v28; // w8
  __int64 v29; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v30; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v31[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v11 = v10;
  v14 = result;
  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31[0] = 0;
  v19 = *(_QWORD *)(result + 104);
  v30 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v19) )
  {
    result = perf_trace_buf_alloc(140, v31, &v30);
    if ( result )
    {
      v21 = (_QWORD *)v31[0];
      *(_QWORD *)(v31[0] + 232LL) = &vars0;
      v21[31] = &v29;
      v21[32] = v11;
      v21[33] = 5;
      *(_QWORD *)(result + 32) = a5;
      v22 = a8[8];
      *(_DWORD *)(result + 72) = a4;
      *(_QWORD *)(result + 56) = v22;
      *(_QWORD *)(result + 64) = a5 - v22;
      *(_DWORD *)(result + 80) = *(_DWORD *)(a3 + 3632);
      v23 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v23;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 1800);
      v24 = *(_QWORD *)(a9 + 8);
      *(_QWORD *)(result + 40) = v24;
      *(_QWORD *)(result + 48) = a5 - v24;
      *(_DWORD *)(result + 76) = *(_DWORD *)(a9 + 28);
      *(_QWORD *)(result + 88) = a8[18];
      *(_QWORD *)(result + 96) = a8[19];
      if ( a7 )
      {
        *(_QWORD *)(result + 104) = *a7;
        v25 = a7[1];
      }
      else
      {
        v25 = 0;
        *(_QWORD *)(result + 104) = 0;
      }
      *(_QWORD *)(result + 112) = v25;
      v26 = v30;
      v27 = v31[0];
      *(_DWORD *)(result + 120) = *(_DWORD *)(a9 + 132);
      v28 = *(_DWORD *)(a9 + 136);
      *(_QWORD *)(result + 128) = a10;
      *(_DWORD *)(result + 124) = v28;
      result = perf_trace_run_bpf_submit(result, 140, v26, v14, 1, v27, StatusReg + v19, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
