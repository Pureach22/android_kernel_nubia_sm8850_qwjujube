char *__fastcall walt_rt_energy_aware_wake_cpu(char *result, _DWORD *a2, int a3, unsigned int *a4)
{
  unsigned __int16 *v4; // x8
  bool v5; // zf
  unsigned int v7; // w25
  __int64 v8; // x19
  __int64 lock; // x0
  _DWORD *v11; // x15
  __int64 v12; // x2
  __int64 v13; // x27
  int v14; // w3
  unsigned __int64 v15; // x30
  char v16; // w8
  bool v17; // cf
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x11
  _BYTE *v22; // x10
  __int64 v23; // x12
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x13
  __int64 v26; // x12
  _QWORD *v27; // x11
  char *v28; // x12
  _BYTE *v29; // x12
  _BOOL4 v30; // w10
  __int64 v31; // x12
  unsigned __int64 v32; // x11
  char v33; // w8
  __int64 v34; // x24
  int v35; // w19
  unsigned __int64 v36; // [xsp+20h] [xbp-30h]
  unsigned int v37; // [xsp+2Ch] [xbp-24h]
  char *v38; // [xsp+30h] [xbp-20h]
  unsigned __int64 v40; // [xsp+40h] [xbp-10h]
  int v41; // [xsp+4Ch] [xbp-4h]

  v4 = (unsigned __int16 *)(result + 5184);
  if ( result == (char *)&init_task )
    v4 = (unsigned __int16 *)&vendor_data_pad;
  v5 = sched_boost_type == 1 && boost_policy == 1;
  v38 = result;
  v7 = v5 && num_sched_clusters > 1;
  if ( a3 && (walt_disabled & 1) == 0 )
  {
    v8 = v4[79];
    lock = _rcu_read_lock(result);
    v11 = a4;
    if ( num_sched_clusters >= 1 )
    {
      v12 = v8;
      v13 = 0;
      v5 = (soc_flags & 0x10) == 0;
      _ReadStatusReg(SP_EL0);
      if ( v5 )
        v14 = 1;
      else
        v14 = v7;
      v15 = -1;
      v36 = -1;
      v37 = -1;
      v41 = 1;
      while ( 1 )
      {
        v16 = 0;
        do
        {
          v18 = (unsigned int)(-1LL << v16) & *a2 & *(_QWORD *)(*(_QWORD *)(cpu_array + 8LL * v7) + 8 * v13);
          if ( !v18 )
            break;
          v19 = __clz(__rbit64(v18));
          v20 = 1LL << v19;
          if ( (_cpu_active_mask & (1LL << v19)) != 0 && (_cpu_halt_mask[0] & v20) == 0 )
          {
            v21 = *((_QWORD *)&_per_cpu_offset + v19);
            v22 = &walt_rq[v21];
            if ( (walt_rq[v21 + 541] & 1) == 0 && (walt_enforce_high_irq_cpu_mask & v20) == 0 )
            {
              v23 = *(unsigned int *)(*((_QWORD *)v22 + 1) + 32LL);
              if ( (unsigned int)v23 >= 4 )
              {
                __break(0x5512u);
                JUMPOUT(0x4DFDC);
              }
              v24 = *((_QWORD *)v22 + 5);
              v25 = *((_QWORD *)v22 + 79);
              v26 = (unsigned int)sched_capacity_margin_up[v23];
              if ( v24 >= v25 )
                v24 = *((_QWORD *)v22 + 79);
              if ( (v24 + v12) * v26 <= v25 << 10 )
              {
                v27 = (_QWORD *)((char *)&runqueues + v21);
                v28 = (char *)v27[418];
                if ( v28 == (char *)&init_task )
                  v29 = &vendor_data_pad;
                else
                  v29 = v28 + 5184;
                v30 = v29[191]
                   && ((v29[191] & 0xC) != 0
                    || sysctl_walt_low_latency_task_threshold > (unsigned int)*((unsigned __int16 *)v29 + 79))
                   || *((_DWORD *)v22 + 14) != 0;
                if ( v41 & 1 | !v30 )
                {
                  if ( (((v41 ^ v30) & 1) != 0 || v24 <= v15) && (v15 != v24 || *v11 != *((_DWORD *)v38 + 10)) )
                  {
                    v31 = v27[529];
                    if ( v31 )
                      LODWORD(v31) = *(_DWORD *)(v31 + 68);
                    v32 = v27[86];
                    if ( v15 != v24
                      || *((_DWORD *)v38 + 10) == (_DWORD)v19
                      || v37 >= (unsigned int)v31 && (v37 != (_DWORD)v31 || v36 >= v32) )
                    {
                      v15 = v24;
                      *v11 = v19;
                      v41 = v30;
                      v37 = v31;
                      v36 = v32;
                    }
                  }
                }
                else
                {
                  v41 = 0;
                }
              }
            }
          }
          v17 = v19 >= 0x1F;
          v16 = v19 + 1;
        }
        while ( !v17 );
        lock = (unsigned int)*v11;
        if ( v13 )
          v33 = 1;
        else
          v33 = v14;
        if ( (v33 & 1) != 0 )
          goto LABEL_19;
        if ( (_DWORD)lock != -1 )
        {
          v34 = v12;
          v35 = v14;
          v40 = v15;
          lock = available_idle_cpu(lock);
          v11 = a4;
          v15 = v40;
          v14 = v35;
          v12 = v34;
          if ( (_DWORD)lock )
            break;
        }
LABEL_20:
        if ( ++v13 >= num_sched_clusters )
          return (char *)_rcu_read_unlock(lock);
      }
      lock = *a4;
LABEL_19:
      if ( (_DWORD)lock != -1 )
        return (char *)_rcu_read_unlock(lock);
      goto LABEL_20;
    }
    return (char *)_rcu_read_unlock(lock);
  }
  return result;
}
