__int64 __fastcall perf_trace_walt_newidle_balance(
        __int64 result,
        unsigned int a2,
        int a3,
        int a4,
        char a5,
        char a6,
        __int64 a7)
{
  __int64 v7; // x30
  __int64 v8; // x26
  __int64 v11; // x19
  __int64 v16; // x27
  unsigned __int64 StatusReg; // x28
  _QWORD *v18; // x9
  int v19; // w9
  __int64 v20; // x9
  int v21; // w8
  __int64 v22; // x2
  __int64 v23; // x5
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v8 = v7;
  v11 = result;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  v16 = *(_QWORD *)(result + 104);
  v25 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v16) )
    goto LABEL_9;
  result = perf_trace_buf_alloc(68, v26, &v25);
  if ( !result )
    goto LABEL_9;
  v18 = (_QWORD *)v26[0];
  *(_QWORD *)(v26[0] + 232LL) = &vars0;
  v18[31] = &v24;
  v18[32] = v8;
  v18[33] = 5;
  *(_DWORD *)(result + 8) = a2;
  *(_DWORD *)(result + 12) = a3;
  *(_DWORD *)(result + 16) = a4;
  if ( a2 < 0x20 )
  {
    *(_DWORD *)(result + 20) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 4);
    *(_DWORD *)(result + 24) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 2640);
    v19 = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 3504);
    *(_BYTE *)(result + 32) = a5 & 1;
    *(_DWORD *)(result + 28) = v19;
    v20 = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 3976);
    *(_BYTE *)(result + 48) = a6 & 1;
    *(_QWORD *)(result + 40) = v20;
    *(_DWORD *)(result + 52) = *(unsigned __int8 *)(*(_QWORD *)((char *)&runqueues
                                                              + *((_QWORD *)&_per_cpu_offset + a2)
                                                              + 3528)
                                                  + 40LL);
    if ( a7 )
      v21 = *(_DWORD *)(a7 + 1800);
    else
      v21 = -1;
    v22 = v25;
    v23 = v26[0];
    *(_DWORD *)(result + 56) = v21;
    result = perf_trace_run_bpf_submit(result, 68, v22, v11, 1, v23, StatusReg + v16, 0);
LABEL_9:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return trace_event_raw_event_walt_lb_cpu_util();
}
