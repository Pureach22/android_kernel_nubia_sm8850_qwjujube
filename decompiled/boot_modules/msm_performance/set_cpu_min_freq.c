__int64 __fastcall set_cpu_min_freq(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v6; // x0
  unsigned int v7; // w0
  int v8; // w25
  char *v9; // x0
  int v10; // w26
  unsigned int v11; // w21
  unsigned __int64 v18; // x10
  size_t v19; // x0
  __int64 v20; // x8
  __int64 lock; // x0
  char v22; // w8
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x25
  __int64 v26; // [xsp+0h] [xbp-10h] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v6 = mutex_lock(&freq_pmqos_lock);
  if ( (ready_for_freq_updates & 1) == 0 )
  {
    v7 = freq_qos_request_init(v6);
    if ( v7 )
    {
      v11 = v7;
      printk(&unk_BAD4, "set_cpu_min_freq", v7);
      mutex_unlock(&freq_pmqos_lock);
      a4 = (int)v11;
      goto LABEL_22;
    }
    ready_for_freq_updates = 1;
  }
  mutex_unlock(&freq_pmqos_lock);
  v8 = -1;
  v9 = (char *)a3;
  do
  {
    v9 = strpbrk(v9 + 1, " :");
    ++v8;
  }
  while ( v9 );
  if ( (v8 & 1) == 0 )
    goto LABEL_7;
  limit_mask_min[0] = 0;
  if ( v8 >= 1 )
  {
    v10 = 0;
    while ( sscanf(a3, "%u:%u", &v26, (char *)&v26 + 4) == 2 )
    {
      if ( (unsigned int)v26 < nr_cpu_ids )
      {
        if ( ((*(_QWORD *)((char *)&_cpu_possible_mask + (((unsigned __int64)(unsigned int)v26 >> 3) & 0x1FFFFFF8)) >> v26)
            & 1) != 0 )
        {
          if ( (unsigned int)v26 >= 0x20 )
            __break(0x5512u);
          *(_DWORD *)((char *)&msm_perf_cpu_stats + _per_cpu_offset[(unsigned int)v26]) = HIDWORD(v26);
          v20 = 1LL << v26;
          _X9 = (unsigned __int64 *)&limit_mask_min[(unsigned __int64)(unsigned int)v26 >> 6];
          __asm { PRFM            #0x11, [X9] }
          do
            v18 = __ldxr(_X9);
          while ( __stxr(v18 | v20, _X9) );
        }
        v19 = strlen(a3);
        v10 += 2;
        a3 = (const char *)(strnchr(a3, v19, 32) + 1);
        if ( v10 < v8 )
          continue;
      }
      goto LABEL_18;
    }
LABEL_7:
    a4 = -22;
    goto LABEL_22;
  }
LABEL_18:
  lock = cpus_read_lock();
  v22 = 0;
  do
  {
    v23 = (unsigned int)(-1LL << v22) & limit_mask_min[0];
    if ( !(_DWORD)v23 )
      break;
    v24 = __clz(__rbit64(v23));
    lock = freq_qos_update_request(
             (char *)&qos_req_min + _per_cpu_offset[v24],
             *(unsigned int *)((char *)&msm_perf_cpu_stats + _per_cpu_offset[v24]));
    v22 = v24 + 1;
  }
  while ( v24 < 0x1F );
  cpus_read_unlock(lock);
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return a4;
}
