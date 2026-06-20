__int64 __fastcall perf_trace_sched_task_util(
        __int64 result,
        __int64 a2,
        __int64 a3,
        int a4,
        char a5,
        int a6,
        int a7,
        __int64 a8,
        char a9,
        int a10,
        int a11)
{
  __int64 v11; // x30
  __int64 v12; // x28
  __int64 v15; // x19
  __int64 v21; // x8
  __int64 v22; // x1
  _QWORD *v23; // x9
  __int64 v24; // x20
  __int64 v25; // x12
  _QWORD *v26; // x28
  int v27; // w9
  int v28; // w9
  int v29; // w8
  __int64 unlock; // x0
  __int64 v31; // x1
  char v32; // w8
  char v33; // w24
  __int64 lock; // x0
  __int64 v35; // x8
  int v37; // w8
  char v38; // w8
  __int64 v39; // x0
  bool v40; // w8
  __int64 v41; // x2
  __int64 v42; // x5
  __int64 v43; // [xsp+0h] [xbp-30h] BYREF
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-28h]
  __int64 v45; // [xsp+10h] [xbp-20h]
  unsigned int v46; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v47[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v12 = v11;
  v15 = result;
  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = *(_QWORD *)(result + 104);
  v47[0] = 0;
  v46 = 0;
  v45 = v21;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v45) )
  {
    result = perf_trace_buf_alloc(140, v47, &v46);
    if ( result )
    {
      v23 = (_QWORD *)v47[0];
      *(_QWORD *)(v47[0] + 232LL) = &vars0;
      v24 = result;
      v23[31] = &v43;
      v23[32] = v12;
      v23[33] = 5;
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 1800);
      v25 = *(_QWORD *)(a2 + 2320);
      if ( (_UNKNOWN *)a2 == &init_task )
        v26 = &vendor_data_pad;
      else
        v26 = (_QWORD *)(a2 + 5184);
      *(_QWORD *)(result + 20) = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 12) = v25;
      *(_QWORD *)(result + 32) = *((unsigned __int16 *)v26 + 79);
      v27 = *(_DWORD *)(a2 + 40);
      *(_QWORD *)(result + 40) = a3;
      *(_BYTE *)(result + 56) = a5 & 1;
      *(_DWORD *)(result + 48) = v27;
      v28 = boost_policy;
      *(_DWORD *)(result + 60) = a6;
      *(_DWORD *)(result + 64) = a7;
      *(_DWORD *)(result + 52) = a4;
      if ( v28 )
      {
        result = ((__int64 (__fastcall *)(__int64))task_sched_boost_0)(a2);
        v29 = boost_policy;
        if ( (result & 1) == 0 )
          v29 = 0;
        if ( v29 == 1 )
          v29 = sched_boost_type != 5 && sched_boost_type != 2
             || sysctl_sched_min_task_util_for_boost < (unsigned int)*((unsigned __int16 *)v26 + 79);
      }
      else
      {
        v29 = 0;
      }
      *(_DWORD *)(v24 + 68) = v29;
      unlock = sched_clock(result, v22);
      *(_BYTE *)(v24 + 88) = a9 & 1;
      *(_QWORD *)(v24 + 80) = unlock - a8;
      v32 = soc_flags;
      *(_BYTE *)(v24 + 89) = v26[30] != 0;
      if ( v32 < 0 )
      {
        lock = _rcu_read_lock(unlock);
        v35 = v26[30];
        if ( v35 )
          v33 = *(_BYTE *)(v35 + 40);
        else
          v33 = 0;
        unlock = _rcu_read_unlock(lock);
      }
      else
      {
        v33 = 0;
      }
      *(_DWORD *)(v24 + 92) = a10;
      *(_BYTE *)(v24 + 90) = v33 & 1;
      *(_DWORD *)(v24 + 96) = *((_DWORD *)v26 + 55);
      *(_QWORD *)(v24 + 104) = **(_QWORD **)(a2 + 1376);
      if ( v26[24] && (unsigned __int64)walt_sched_clock(unlock, v31) > v26[25] )
      {
        *((_DWORD *)v26 + 46) = 0;
        v26[24] = 0;
        v26[25] = 0;
      }
      if ( *((_DWORD *)v26 + 46) == 1 && (soc_flags & 8) == 0 )
        v37 = 0;
      else
        v37 = *((_DWORD *)v26 + 46);
      *(_DWORD *)(v24 + 112) = v37;
      v38 = *((_BYTE *)v26 + 191);
      if ( v38 )
        v38 = (*((_BYTE *)v26 + 191) & 0xC) != 0
           || sysctl_walt_low_latency_task_threshold > (unsigned int)*((unsigned __int16 *)v26 + 79);
      *(_BYTE *)(v24 + 116) = v38;
      v39 = (unsigned int)part_haltable_cpus;
      *(_BYTE *)(v24 + 117) = *((_BYTE *)v26 + 272);
      *(_DWORD *)(v24 + 120) = *((_DWORD *)v26 + 84);
      if ( (unsigned int)_sw_hweight64(v39) )
        v40 = (~(LODWORD(_cpu_halt_mask[0]) | LODWORD(_cpu_partial_halt_mask[0])) & (unsigned int)part_haltable_cpus) != 0;
      else
        v40 = 1;
      *(_BYTE *)(v24 + 124) = v40;
      v41 = v46;
      v42 = v47[0];
      *(_DWORD *)(v24 + 128) = *((_DWORD *)v26 + 91);
      *(_DWORD *)(v24 + 132) = a11;
      result = perf_trace_run_bpf_submit(v24, 140, v41, v15, 1, v42, StatusReg + v45, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
