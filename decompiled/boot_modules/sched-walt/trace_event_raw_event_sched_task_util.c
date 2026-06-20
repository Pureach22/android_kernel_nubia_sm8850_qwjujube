__int64 __fastcall trace_event_raw_event_sched_task_util(
        __int64 a1,
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
  __int64 v19; // x8
  __int64 result; // x0
  __int64 v21; // x1
  __int64 v22; // x19
  __int64 v23; // x12
  _QWORD *v24; // x27
  int v25; // w9
  int v26; // w9
  int v27; // w8
  __int64 unlock; // x0
  __int64 v29; // x1
  char v30; // w8
  char v31; // w23
  __int64 lock; // x0
  __int64 v33; // x8
  int v35; // w8
  char v36; // w8
  __int64 v37; // x0
  bool v38; // w8
  _QWORD v39[7]; // [xsp+8h] [xbp-38h] BYREF

  v39[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = *(_QWORD *)(a1 + 72);
  memset(v39, 0, 48);
  if ( (v19 & 0x2C0) == 0 || (v19 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v39, a1, 136);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 1800);
      v22 = result;
      v23 = *(_QWORD *)(a2 + 2320);
      if ( (_UNKNOWN *)a2 == &init_task )
        v24 = &vendor_data_pad;
      else
        v24 = (_QWORD *)(a2 + 5184);
      *(_QWORD *)(result + 20) = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 12) = v23;
      *(_QWORD *)(result + 32) = *((unsigned __int16 *)v24 + 79);
      v25 = *(_DWORD *)(a2 + 40);
      *(_QWORD *)(result + 40) = a3;
      *(_BYTE *)(result + 56) = a5 & 1;
      *(_DWORD *)(result + 48) = v25;
      v26 = boost_policy;
      *(_DWORD *)(result + 60) = a6;
      *(_DWORD *)(result + 64) = a7;
      *(_DWORD *)(result + 52) = a4;
      if ( v26 )
      {
        result = ((__int64 (__fastcall *)(__int64))task_sched_boost_0)(a2);
        v27 = boost_policy;
        if ( (result & 1) == 0 )
          v27 = 0;
        if ( v27 == 1 )
          v27 = sched_boost_type != 5 && sched_boost_type != 2
             || sysctl_sched_min_task_util_for_boost < (unsigned int)*((unsigned __int16 *)v24 + 79);
      }
      else
      {
        v27 = 0;
      }
      *(_DWORD *)(v22 + 68) = v27;
      unlock = sched_clock(result, v21);
      *(_BYTE *)(v22 + 88) = a9 & 1;
      *(_QWORD *)(v22 + 80) = unlock - a8;
      v30 = soc_flags;
      *(_BYTE *)(v22 + 89) = v24[30] != 0;
      if ( v30 < 0 )
      {
        lock = _rcu_read_lock(unlock);
        v33 = v24[30];
        if ( v33 )
          v31 = *(_BYTE *)(v33 + 40);
        else
          v31 = 0;
        unlock = _rcu_read_unlock(lock);
      }
      else
      {
        v31 = 0;
      }
      *(_DWORD *)(v22 + 92) = a10;
      *(_BYTE *)(v22 + 90) = v31 & 1;
      *(_DWORD *)(v22 + 96) = *((_DWORD *)v24 + 55);
      *(_QWORD *)(v22 + 104) = **(_QWORD **)(a2 + 1376);
      if ( v24[24] && (unsigned __int64)walt_sched_clock(unlock, v29) > v24[25] )
      {
        *((_DWORD *)v24 + 46) = 0;
        v24[24] = 0;
        v24[25] = 0;
      }
      if ( *((_DWORD *)v24 + 46) == 1 && (soc_flags & 8) == 0 )
        v35 = 0;
      else
        v35 = *((_DWORD *)v24 + 46);
      *(_DWORD *)(v22 + 112) = v35;
      v36 = *((_BYTE *)v24 + 191);
      if ( v36 )
        v36 = (*((_BYTE *)v24 + 191) & 0xC) != 0
           || sysctl_walt_low_latency_task_threshold > (unsigned int)*((unsigned __int16 *)v24 + 79);
      *(_BYTE *)(v22 + 116) = v36;
      v37 = (unsigned int)part_haltable_cpus;
      *(_BYTE *)(v22 + 117) = *((_BYTE *)v24 + 272);
      *(_DWORD *)(v22 + 120) = *((_DWORD *)v24 + 84);
      if ( (unsigned int)_sw_hweight64(v37) )
        v38 = (~(LODWORD(_cpu_halt_mask[0]) | LODWORD(_cpu_partial_halt_mask[0])) & (unsigned int)part_haltable_cpus) != 0;
      else
        v38 = 1;
      *(_BYTE *)(v22 + 124) = v38;
      *(_DWORD *)(v22 + 128) = *((_DWORD *)v24 + 91);
      *(_DWORD *)(v22 + 132) = a11;
      result = trace_event_buffer_commit(v39);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
