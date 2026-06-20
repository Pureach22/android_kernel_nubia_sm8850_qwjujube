__int64 __fastcall perf_trace_sched_cpu_util(__int64 result, unsigned int a2, int *a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v6; // x19
  __int64 v8; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v10; // x9
  __int64 v11; // x11
  _BYTE *v12; // x12
  unsigned __int64 v13; // x13
  unsigned __int64 v14; // x12
  __int64 v15; // x12
  _BYTE *v16; // x11
  _QWORD *v17; // x12
  __int64 v18; // x12
  _BOOL4 v19; // w13
  __int64 v20; // x12
  _BOOL4 v21; // w14
  int v22; // w11
  __int64 v23; // x2
  __int64 v24; // x5
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v26 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v8)
    || (result = perf_trace_buf_alloc(140, v27, &v26)) == 0 )
  {
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v10 = (_QWORD *)v27[0];
  *(_QWORD *)(v27[0] + 232LL) = &vars0;
  v10[33] = 5;
  v10[31] = &v25;
  v10[32] = v4;
  if ( a2 < 0x20 )
  {
    v11 = *((_QWORD *)&_per_cpu_offset + a2);
    *(_DWORD *)(result + 8) = a2;
    *(_DWORD *)(result + 12) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 4);
    v12 = &walt_rq[*((_QWORD *)&_per_cpu_offset + a2)];
    v13 = *((_QWORD *)v12 + 5);
    v14 = *((_QWORD *)v12 + 79);
    if ( v13 < v14 )
      v14 = v13;
    *(_QWORD *)(result + 16) = v14;
    *(_QWORD *)(result + 24) = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 688);
    *(_QWORD *)(result + 32) = (*(_QWORD *)((char *)&arch_freq_scale + *((_QWORD *)&_per_cpu_offset + a2))
                              * *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 632]) >> 10;
    *(_QWORD *)(result + 40) = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 3544);
    *(_QWORD *)(result + 48) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 632];
    v15 = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 4232);
    if ( v15 )
      LODWORD(v15) = *(_DWORD *)(v15 + 68);
    *(_DWORD *)(result + 56) = v15;
    v16 = &walt_rq[v11];
    v17 = &walt_rq[*((_QWORD *)&_per_cpu_offset + a2)];
    if ( (__int64)(v17[8] - v17[12]) > 2 )
      v18 = 0;
    else
      v18 = v17[11];
    *(_QWORD *)(result + 64) = v18;
    v19 = 1;
    v20 = 1LL << a2;
    v21 = (_cpu_active_mask & (1LL << a2)) == 0;
    *(_DWORD *)(result + 72) = (_cpu_online_mask & (1LL << a2)) != 0;
    *(_DWORD *)(result + 76) = v21;
    *(_DWORD *)(result + 80) = ((_cpu_partial_halt_mask[0] & (1LL << a2)) != 0)
                             | (2 * ((_cpu_halt_mask[0] & (1LL << a2)) != 0));
    *(_DWORD *)(result + 84) = ((unsigned int)*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 80] >> 1) & 1;
    if ( (walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 541] & 1) == 0 )
      v19 = (walt_enforce_high_irq_cpu_mask & v20) != 0;
    *(_DWORD *)(result + 88) = v19;
    *(_BYTE *)(result + 92) = (walt_enforce_high_irq_cpu_mask & v20) != 0;
    *(_DWORD *)(result + 96) = *(_DWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 56];
    *(_QWORD *)(result + 104) = *((_QWORD *)v16 + 23) + *((_QWORD *)v16 + 19);
    if ( a3 )
      v22 = *a3;
    else
      v22 = 0;
    *(_DWORD *)(result + 112) = v22;
    v23 = v26;
    v24 = v27[0];
    *(_QWORD *)(result + 120) = *(_QWORD *)((char *)&hw_pressure + *((_QWORD *)&_per_cpu_offset + a2));
    *(_DWORD *)(result + 128) = *(char *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 8] + 488LL);
    result = perf_trace_run_bpf_submit(result, 140, v23, v6, 1, v24, StatusReg + v8, 0);
    goto LABEL_18;
  }
  __break(0x5512u);
  return trace_event_raw_event_sched_compute_energy();
}
