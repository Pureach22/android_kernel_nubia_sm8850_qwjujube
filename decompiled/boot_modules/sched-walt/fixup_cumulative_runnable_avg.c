__int64 __fastcall fixup_cumulative_runnable_avg(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x20
  __int64 v6; // x22
  char *v7; // x8
  unsigned __int16 *v8; // x19
  __int64 v9; // x23
  __int64 v10; // x25
  __int64 v11; // x24
  __int64 v12; // x26
  __int64 v13; // x8
  __int64 v14; // x22
  __int64 v15; // x24
  __int64 v16; // x23
  char *v17; // x8
  __int64 v18; // x9
  __int64 v19; // x19
  char *v20; // x8
  __int64 v21; // x24
  __int64 v22; // x25
  __int64 v23; // x26
  __int64 v24; // x27
  __int64 v25; // x23
  __int64 v26; // x24
  __int64 v27; // x25
  unsigned __int64 StatusReg; // x8
  int v29; // w9
  __int64 v30; // x19
  __int64 v31; // x21
  __int64 v32; // x0

  v6 = *(_QWORD *)(a3 + 16);
  v5 = *(_QWORD *)(a3 + 24);
  v7 = (char *)*(unsigned int *)(a2 + 40);
  if ( (_UNKNOWN *)a2 == &init_task )
    v8 = (unsigned __int16 *)&vendor_data_pad;
  else
    v8 = (unsigned __int16 *)(a2 + 5184);
  if ( (unsigned int)v7 >= 0x20 )
  {
    __break(0x5512u);
    goto LABEL_36;
  }
  if ( (_UNKNOWN *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + (_QWORD)v7)) != (_UNKNOWN *)result
    && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
  {
    if ( (sysctl_panic_on_walt_bug & 8) != 0 )
    {
      v21 = a3;
      v22 = a2;
      v23 = a4;
      v24 = a5;
      result = printk_deferred(
                 "WALT-BUG on CPU %d task %s(%d) not on rq %d",
                 *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                 (const char *)(a2 + 2320),
                 *(_DWORD *)(a2 + 1800),
                 *(_DWORD *)(result + 3632));
      a4 = v23;
      a5 = v24;
      a2 = v22;
      a3 = v21;
      if ( (sysctl_panic_on_walt_bug & 1) == 0 )
        goto LABEL_12;
    }
    else if ( (sysctl_panic_on_walt_bug & 1) == 0 )
    {
      goto LABEL_12;
    }
    if ( a2 )
    {
      v9 = a3;
      v10 = a2;
      v11 = a5;
      v12 = a4;
      result = walt_task_dump((unsigned __int64 *)a2);
      a4 = v12;
      a5 = v11;
      a2 = v10;
      a3 = v9;
    }
    v7 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
    if ( !in_sched_bug )
    {
LABEL_36:
      *((_DWORD *)v7 + 815) = 1;
      walt_dump();
      __break(0x800u);
      goto LABEL_37;
    }
  }
LABEL_12:
  v13 = v6 + a4;
  if ( ((v6 + a4) & 0x8000000000000000LL) == 0 )
    goto LABEL_20;
  if ( (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
  {
    if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
    {
      v25 = a2;
      v26 = a3;
      v27 = a5;
      result = printk_deferred(
                 "WALT-BUG on CPU %d task ds=%hu is higher than cra=%llu\n",
                 *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                 v8[79],
                 *(_QWORD *)(a3 + 16));
      a5 = v27;
      a2 = v25;
      a3 = v26;
      if ( (sysctl_panic_on_walt_bug & 2) != 0 )
      {
LABEL_16:
        if ( a2 )
        {
          v14 = a3;
          v15 = a2;
          v16 = a5;
          result = walt_task_dump((unsigned __int64 *)a2);
          a5 = v16;
          a2 = v15;
          a3 = v14;
        }
        v17 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
        if ( in_sched_bug )
          goto LABEL_19;
LABEL_37:
        *((_DWORD *)v17 + 815) = 1;
        walt_dump();
        __break(0x800u);
        goto LABEL_38;
      }
    }
    else if ( (sysctl_panic_on_walt_bug & 2) != 0 )
    {
      goto LABEL_16;
    }
  }
LABEL_19:
  v13 = 0;
LABEL_20:
  v18 = v5 + a5;
  *(_QWORD *)(a3 + 16) = v13;
  if ( ((v5 + a5) & 0x8000000000000000LL) == 0 )
  {
LABEL_28:
    *(_QWORD *)(a3 + 24) = v18;
    return result;
  }
  if ( (sysctl_panic_on_walt_bug & 0xFFFFFF00) != 0x4544DE00 )
    goto LABEL_27;
  if ( (sysctl_panic_on_walt_bug & 0x10) == 0 )
  {
    if ( (sysctl_panic_on_walt_bug & 2) != 0 )
      goto LABEL_24;
LABEL_27:
    v18 = 0;
    goto LABEL_28;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v29 = v8[80];
  v30 = a2;
  v31 = a3;
  result = printk_deferred(
             "WALT-BUG on CPU %d task pds=%hu is higher than pds_sum=%llu\n",
             *(_DWORD *)(StatusReg + 40),
             v29,
             *(_QWORD *)(a3 + 24));
  a2 = v30;
  a3 = v31;
  if ( (sysctl_panic_on_walt_bug & 2) == 0 )
    goto LABEL_27;
LABEL_24:
  if ( a2 )
  {
    v19 = a3;
    result = walt_task_dump((unsigned __int64 *)a2);
    a3 = v19;
  }
  v20 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
  if ( in_sched_bug )
    goto LABEL_27;
LABEL_38:
  *((_DWORD *)v20 + 815) = 1;
  v32 = walt_dump();
  __break(0x800u);
  return update_cluster_load_subtractions(v32);
}
