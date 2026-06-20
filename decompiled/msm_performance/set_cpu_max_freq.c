__int64 __fastcall set_cpu_max_freq(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  unsigned int v6; // w0
  int v7; // w25
  char *v8; // x0
  __int64 result; // x0
  int v10; // w26
  unsigned int v11; // w21
  unsigned __int64 v18; // x9
  size_t v19; // x0
  int v20; // w9
  __int64 v21; // x8
  __int64 lock; // x0
  char v23; // w8
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x21
  unsigned int v26; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v27; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v26 = 0;
  mutex_lock(&freq_pmqos_lock);
  if ( (ready_for_freq_updates & 1) == 0 )
  {
    v6 = freq_qos_request_init();
    if ( v6 )
    {
      v11 = v6;
      printk(&unk_BAD4, "set_cpu_max_freq", v6);
      mutex_unlock(&freq_pmqos_lock);
      result = (int)v11;
      goto LABEL_24;
    }
    ready_for_freq_updates = 1;
  }
  mutex_unlock(&freq_pmqos_lock);
  v7 = -1;
  v8 = (char *)a3;
  do
  {
    v8 = strpbrk(v8 + 1, " :");
    ++v7;
  }
  while ( v8 );
  if ( (v7 & 1) == 0 )
    goto LABEL_7;
  limit_mask_max = 0;
  if ( v7 >= 1 )
  {
    v10 = 0;
    while ( sscanf(a3, "%u:%u", &v26, &v27) == 2 )
    {
      if ( v26 < nr_cpu_ids )
      {
        if ( ((*(_QWORD *)((char *)&_cpu_possible_mask + (((unsigned __int64)v26 >> 3) & 0x1FFFFFF8)) >> v26) & 1) != 0 )
        {
          if ( v26 >= 0x20 )
            __break(0x5512u);
          v20 = v27;
          v21 = 1LL << v26;
          if ( v27 >= 0x7FFFFFFF )
            v20 = 0x7FFFFFFF;
          *(_DWORD *)((char *)&msm_perf_cpu_stats + _per_cpu_offset[v26] + 4) = v20;
          _X11 = &limit_mask_max;
          __asm { PRFM            #0x11, [X11] }
          do
            v18 = __ldxr((unsigned __int64 *)&limit_mask_max);
          while ( __stxr(v18 | v21, (unsigned __int64 *)&limit_mask_max) );
        }
        v19 = strlen(a3);
        v10 += 2;
        a3 = (const char *)(strnchr(a3, v19, 32) + 1);
        if ( v10 < v7 )
          continue;
      }
      goto LABEL_20;
    }
LABEL_7:
    result = -22;
    goto LABEL_24;
  }
LABEL_20:
  lock = cpus_read_lock();
  v23 = 0;
  do
  {
    v24 = (unsigned int)(-1LL << v23) & (unsigned int)limit_mask_max;
    if ( !(_DWORD)v24 )
      break;
    v25 = __clz(__rbit64(v24));
    lock = freq_qos_update_request(
             (char *)&qos_req_max + _per_cpu_offset[v25],
             *(unsigned int *)((char *)&msm_perf_cpu_stats + _per_cpu_offset[v25] + 4));
    v23 = v25 + 1;
  }
  while ( v25 < 0x1F );
  cpus_read_unlock(lock);
  result = a4;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
