__int64 __usercall migrate_busy_time_addition@<X0>(
        unsigned __int64 a1@<X0>,
        unsigned int a2@<W1>,
        char *a3@<X2>,
        char *a4@<X8>)
{
  unsigned int *v5; // x23
  __int64 v6; // x9
  __int64 v9; // x25
  char *v10; // x21
  char *v11; // x24
  __int64 result; // x0
  __int64 v13; // x5
  __int64 v14; // x7
  const void *v15; // x5
  unsigned __int64 v16; // x28
  char *v17; // x8
  __int64 v18; // x9
  _QWORD *v19; // x8
  unsigned int *v20; // x9
  __int64 v21; // x10
  unsigned int *v22; // x10
  __int64 v23; // x8
  _QWORD *v24; // x8
  __int64 v25; // x11
  unsigned int v26; // w9
  __int64 v27; // x10
  unsigned int v28; // w9
  unsigned int v29; // w12
  __int64 v30; // x11
  unsigned int v31; // w12
  __int64 v32; // x14
  int v33; // w15
  unsigned __int64 v34; // x14
  unsigned __int8 v35; // w11
  unsigned int v36; // w9
  __int64 v37; // x12
  int v38; // w13
  unsigned __int64 v39; // x10
  unsigned __int64 StatusReg; // x8
  unsigned int v41; // w9
  __int64 v42; // x1
  __int64 v43; // x0

  if ( a2 >= 0x20 )
    goto LABEL_66;
  v5 = (_UNKNOWN *)a1 == &init_task ? (unsigned int *)&vendor_data_pad : (unsigned int *)(a1 + 5184);
  a4 = (char *)v5[88];
  if ( (unsigned int)a4 > 0x1F )
    goto LABEL_66;
  v6 = *((_QWORD *)&_per_cpu_offset + a2);
  v9 = *((_QWORD *)&_per_cpu_offset + (_QWORD)a4);
  v10 = (char *)&runqueues + v6;
  v11 = &walt_rq[v6];
  result = walt_update_task_ravg(a1, (char *)&runqueues + v6, 4u, a3, nullptr);
  v13 = *((_QWORD *)v5 + 2);
  v14 = *((_QWORD *)v11 + 8);
  if ( v13 != v14 && (unsigned int)sysctl_panic_on_walt_bug >> 8 == 4539614 )
  {
    if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
    {
      result = printk_deferred(
                 "WALT-BUG CPU%d: %s task %s(%d)'s ws=%llu not equal to dest_rq %d's ws=%llu",
                 *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                 "migrate_busy_time_addition",
                 (const char *)(a1 + 2320),
                 *(_DWORD *)(a1 + 1800),
                 v13,
                 *((_DWORD *)v10 + 908),
                 v14);
      if ( (sysctl_panic_on_walt_bug & 2) == 0 )
        goto LABEL_13;
    }
    else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
    {
      goto LABEL_13;
    }
    if ( a1 )
      result = walt_task_dump((unsigned __int64 *)a1);
    a4 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
    if ( !in_sched_bug )
      goto LABEL_67;
  }
LABEL_13:
  v15 = *((const void **)v5 + 30);
  v16 = *((_QWORD *)v5 + 21);
  if ( !v15 )
  {
    a4 = (char *)*((unsigned __int8 *)v5 + 360);
    if ( (_DWORD)a4 != 2 )
      goto LABEL_34;
    if ( a2 > 7 )
      goto LABEL_66;
    v22 = &v5[a2];
    v23 = *((_QWORD *)&_per_cpu_offset + a2);
    v22[17] = v5[33];
    v24 = &walt_rq[v23];
    v22[25] = v5[34];
    v25 = v24[19];
    v24[18] += v5[33];
    v24[19] = v25 + v5[34];
    if ( v16 > 0x5F5E0FF )
      goto LABEL_34;
    v24[20] += v5[33];
    v19 = v24 + 21;
    v26 = v5[34];
    goto LABEL_33;
  }
  if ( v15 != (const void *)qword_67BA0 && (unsigned int)sysctl_panic_on_walt_bug >> 8 == 4539614 )
  {
    if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
    {
      result = printk_deferred(
                 "WALT-BUG CPU%d: %s task %s(%d)'s grp=%p not equal to rtg[1]=%p'",
                 *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                 "migrate_busy_time_addition",
                 (const char *)(a1 + 2320),
                 *(_DWORD *)(a1 + 1800),
                 v15,
                 (const void *)qword_67BA0);
      if ( (sysctl_panic_on_walt_bug & 2) == 0 )
        goto LABEL_21;
    }
    else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
    {
      goto LABEL_21;
    }
    if ( a1 )
      result = walt_task_dump((unsigned __int64 *)a1);
    v17 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
    if ( !in_sched_bug )
      goto LABEL_68;
  }
LABEL_21:
  v18 = v5[33];
  v19 = v11 + 184;
  if ( !(_DWORD)v18 )
  {
    v20 = v5 + 34;
    v27 = v5[34];
    if ( !(_DWORD)v27 )
      goto LABEL_34;
    *v19 += v27;
    if ( v16 > 0x5F5E0FF )
      goto LABEL_34;
    goto LABEL_31;
  }
  *((_QWORD *)v11 + 22) += v18;
  if ( v16 >= 0x5F5E100 )
  {
    v26 = v5[34];
    if ( v26 )
      goto LABEL_33;
  }
  else
  {
    *((_QWORD *)v11 + 24) += v5[33];
    v20 = v5 + 34;
    v21 = v5[34];
    if ( (_DWORD)v21 )
    {
      *v19 += v21;
LABEL_31:
      v26 = *v20;
      v19 = v11 + 200;
LABEL_33:
      *v19 += v26;
    }
  }
LABEL_34:
  a4 = (char *)*((unsigned int *)v10 + 908);
  if ( (unsigned int)a4 >= 0x20 )
    goto LABEL_66;
  v29 = v5[33];
  v28 = v5[34];
  a4 = &walt_rq[*((_QWORD *)&_per_cpu_offset + (_QWORD)a4)];
  v30 = (unsigned __int8)a4[528];
  if ( !v29 )
    goto LABEL_43;
  if ( (unsigned int)v30 > 1 )
  {
LABEL_66:
    __break(0x5512u);
LABEL_67:
    *((_DWORD *)a4 + 815) = 1;
    walt_dump();
    __break(0x800u);
LABEL_68:
    *((_DWORD *)v17 + 815) = 1;
    v43 = walt_dump();
    __break(0x800u);
    return task_sched_boost(v43);
  }
  v31 = v29 / sched_load_granule;
  v32 = *(_QWORD *)&a4[8 * v30 + 512];
  if ( v31 >= 0x3E7 )
    v31 = 999;
  v33 = *(unsigned __int8 *)(v32 + v31);
  *(_BYTE *)(v32 + v31) = v33 + 1;
  if ( !v33 )
  {
    v34 = (unsigned __int64)&a4[128 * v30 + (((unsigned __int64)(999 - v31) >> 3) & 0x78)];
    *(_QWORD *)(v34 + 256) |= 1LL << (-25 - (unsigned __int8)v31);
  }
  if ( (signed int)v31 > *((_DWORD *)a4 + 134) )
    *((_DWORD *)a4 + 134) = v31;
LABEL_43:
  if ( v28 )
  {
    v35 = 1 - v30;
    if ( v35 <= 1u )
    {
      v36 = v28 / sched_load_granule;
      v37 = *(_QWORD *)&a4[8 * v35 + 512];
      if ( v36 >= 0x3E7 )
        v36 = 999;
      v38 = *(unsigned __int8 *)(v37 + v36);
      *(_BYTE *)(v37 + v36) = v38 + 1;
      if ( !v38 )
      {
        v39 = (unsigned __int64)&a4[128 * (unsigned __int64)v35 + (((unsigned __int64)(999 - v36) >> 3) & 0x78)];
        *(_QWORD *)(v39 + 256) |= 1LL << (-25 - (unsigned __int8)v36);
      }
      if ( (signed int)v36 > *((_DWORD *)a4 + 133) )
        *((_DWORD *)a4 + 133) = v36;
      goto LABEL_51;
    }
    goto LABEL_66;
  }
LABEL_51:
  if ( *((_BYTE *)v5 + 360) == 2 )
  {
    walt_rq[v9 + 540] = 1;
    StatusReg = _ReadStatusReg(SP_EL0);
    v11[540] = 1;
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      result = irq_work_queue(&walt_migration_irq_work);
    }
    else
    {
      v41 = __clz(__rbit64(_cpu_online_mask));
      if ( _cpu_online_mask )
        v42 = v41;
      else
        v42 = 32;
      result = irq_work_queue_on(&walt_migration_irq_work, v42);
    }
  }
  if ( boost_policy )
  {
    if ( (unsigned __int64)&a3[-*((_QWORD *)v5 + 28)] >= 0x90F560 )
      *((_QWORD *)v11 + 14) = a1;
  }
  v5[89] = -1;
  return result;
}
