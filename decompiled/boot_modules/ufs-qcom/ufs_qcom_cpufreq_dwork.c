__int64 __fastcall ufs_qcom_cpufreq_dwork(__int64 unlock)
{
  unsigned __int64 v1; // x8
  __int64 v2; // x19
  int v3; // w23
  __int64 v4; // x1
  int v5; // w8
  __int64 v6; // x24
  __int64 v7; // x25
  __int64 v8; // x9
  unsigned int *v9; // x8
  unsigned int v10; // w21
  unsigned __int64 v11; // x22
  __int64 lock; // x0
  __int64 v13; // x1
  __int64 updated; // x0
  int v15; // w22
  __int64 v16; // x20
  __int64 v17; // x0

  v1 = *(int *)(unlock - 8);
  *(_DWORD *)(unlock - 8) = 0;
  v2 = unlock;
  if ( v1 <= *(unsigned int *)(unlock + 2680) || (*(_BYTE *)(unlock - 4) & 1) != 0 )
  {
    if ( v1 >= *(unsigned int *)(unlock + 2676) || *(_BYTE *)(unlock - 4) != 1 )
      goto LABEL_24;
    v3 = 1;
    if ( *(_BYTE *)(unlock + 2609) != 1 )
      goto LABEL_10;
    v4 = 0;
  }
  else
  {
    v3 = 0;
    if ( (*(_BYTE *)(unlock + 2609) & 1) == 0 )
      goto LABEL_10;
    v4 = 1;
  }
  unlock = ((__int64 (__fastcall *)(_QWORD, __int64))ufs_qcom_toggle_pri_affinity)(*(_QWORD *)(unlock - 512), v4);
LABEL_10:
  v5 = *(_DWORD *)(v2 + 120);
  *(_BYTE *)(v2 - 4) = 1;
  if ( v5 < 1 )
  {
LABEL_24:
    v16 = *(_QWORD *)(*(_QWORD *)(v2 - 56) + 16LL);
    v17 = _msecs_to_jiffies(*(unsigned int *)(v2 + 2672));
    return queue_delayed_work_on(32, v16, v2, v17);
  }
  v6 = 0;
  v7 = 0;
  while ( 1 )
  {
    if ( v3 )
      v8 = 2;
    else
      v8 = 3;
    v9 = (unsigned int *)(*(_QWORD *)(v2 + 112) + v6);
    v10 = v9[v8];
    v11 = *v9;
    lock = cpus_read_lock(unlock);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v11 >> 3) & 0x1FFFFFF8)) >> v11) & 1) == 0 )
    {
      unlock = cpus_read_unlock(lock);
LABEL_22:
      if ( v10 != *(_DWORD *)(*(_QWORD *)(v2 + 112) + v6 + 8) )
        goto LABEL_13;
      goto LABEL_12;
    }
    if ( (unsigned int)v11 >= 0x20 )
      break;
    updated = freq_qos_update_request((char *)&qos_min_req + _per_cpu_offset[v11], v10);
    v15 = updated;
    unlock = cpus_read_unlock(updated);
    if ( (v15 & 0x80000000) == 0 )
      goto LABEL_22;
    unlock = dev_err(
               *(_QWORD *)(*(_QWORD *)(v2 - 512) + 64LL),
               "fail set cpufreq-fmin,freq_val=%u,cpu=%u,err=%d\n",
               v10,
               *(_DWORD *)(*(_QWORD *)(v2 + 112) + v6),
               v15);
LABEL_12:
    *(_BYTE *)(v2 - 4) = 0;
LABEL_13:
    ++v7;
    v6 += 32;
    if ( v7 >= *(int *)(v2 + 120) )
      goto LABEL_24;
  }
  __break(0x5512u);
  return ufs_qcom_cfg_timers(lock, v13);
}
