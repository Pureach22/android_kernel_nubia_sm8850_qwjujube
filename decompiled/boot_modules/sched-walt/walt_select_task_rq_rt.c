__int64 __fastcall walt_select_task_rq_rt(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        int a4,
        char a5,
        unsigned int *a6)
{
  __int64 v8; // x8
  _QWORD *v9; // x25
  __int64 v10; // x10
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x9
  _DWORD *v13; // x21
  unsigned int fitness; // w22
  __int64 v15; // x0
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x12
  __int64 v18; // x13
  unsigned int v19; // w8
  char *v20; // x9
  int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = -1;
  v22[0] = 0;
  if ( (walt_disabled & 1) == 0 && (a4 == 8 || a4 == 4) )
  {
    v8 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
    if ( (unsigned int)v8 < 0x20 )
    {
      if ( (_UNKNOWN *)a2 == &init_task )
        v9 = &vendor_data_pad;
      else
        v9 = (_QWORD *)(a2 + 5184);
      if ( sysctl_sched_sync_hint_enable )
      {
        v10 = 1LL << v8;
        if ( (_cpu_active_mask & (1LL << v8)) != 0
          && (_cpu_halt_mask[0] & v10) == 0
          && (**(_QWORD **)(a2 + 1376) & v10) != 0
          && (a5 & 0x10) != 0
          && (v9[46] & v10) != 0 )
        {
          v20 = (char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v8);
          if ( *(_DWORD *)(a2 + 148) <= *((_DWORD *)v20 + 663) && *((_DWORD *)v20 + 660) <= 2u )
          {
            *a6 = v8;
            goto LABEL_35;
          }
        }
      }
      *a6 = a3;
      if ( a3 <= 0x1F )
      {
        _rcu_read_lock(result);
        StatusReg = _ReadStatusReg(TPIDR_EL1);
        v12 = *(unsigned int *)(a2 + 40);
        if ( (unsigned int)v12 <= 0x1F )
        {
          v13 = (_DWORD *)((char *)&walt_local_cpu_mask + StatusReg);
          fitness = cpupri_find_fitness(
                      *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v12) + 3528) + 184LL,
                      a2,
                      a2,
                      (char *)&walt_local_cpu_mask + StatusReg,
                      walt_rt_task_fits_capacity);
          v15 = walt_find_and_choose_cluster_packing_cpu(a2);
          if ( (unsigned int)v15 <= 7 )
          {
            v16 = (unsigned int)v15;
            while ( 1 )
            {
              v17 = v16 >> 6;
              v18 = 1LL << v16;
              if ( (v9[(v16 >> 6) + 46] & (1LL << v16)) != 0
                && (*(_QWORD *)(*(_QWORD *)(a2 + 1376) + 8 * v17) & v18) != 0
                && (*((_QWORD *)&_cpu_active_mask + v17) & v18) != 0
                && (_cpu_halt_mask[v17] & v18) == 0
                && *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v16) + 2640) < 2u )
              {
                break;
              }
              if ( ++v16 == 8 )
                goto LABEL_22;
            }
LABEL_32:
            *a6 = v16;
LABEL_34:
            result = _rcu_read_unlock(v15);
            goto LABEL_35;
          }
LABEL_22:
          v22[0] = (unsigned int)(*v13 & v9[46]);
          if ( !LODWORD(v22[0]) || (v15 = walt_rt_energy_aware_wake_cpu(a2, v22, fitness, &v21), v19 = v21, v21 == -1) )
          {
            v15 = walt_rt_energy_aware_wake_cpu(a2, v13, fitness, &v21);
            v19 = v21;
            if ( v21 == -1 )
            {
LABEL_28:
              if ( ((*(unsigned __int64 *)((char *)_cpu_halt_mask + (((unsigned __int64)*a6 >> 3) & 0x1FFFFFF8)) >> *a6)
                  & 1) == 0 )
                goto LABEL_34;
              LODWORD(v16) = __clz(__rbit64(**(_DWORD **)(a2 + 1376) & (unsigned int)~LODWORD(_cpu_halt_mask[0])));
              if ( (**(_DWORD **)(a2 + 1376) & ~LODWORD(_cpu_halt_mask[0])) == 0 )
                LODWORD(v16) = 32;
              v21 = v16;
              if ( (unsigned int)v16 >= nr_cpu_ids )
                goto LABEL_34;
              goto LABEL_32;
            }
          }
          if ( v19 <= 0x1F )
          {
            if ( *(_DWORD *)(a2 + 148) < *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v19) + 2648) )
              *a6 = v19;
            goto LABEL_28;
          }
        }
      }
    }
    __break(0x5512u);
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
