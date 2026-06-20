__int64 __fastcall walt_newidle_balance(__int64 result, __int64 a2, _DWORD *a3, _DWORD *a4, int a5)
{
  __int64 v5; // x19
  __int64 v6; // x26
  unsigned __int64 v7; // x23
  unsigned int v8; // w8
  __int64 v9; // x8
  _BYTE *v10; // x9
  int v11; // w8
  unsigned __int64 v12; // x20
  char v13; // w11
  unsigned __int64 v14; // x11
  unsigned __int64 v15; // x11
  char *v16; // x21
  bool v17; // cc
  int v18; // w27
  _DWORD *v19; // x28
  __int64 v20; // x22
  __int64 v21; // x21
  __int64 v22; // x28
  __int64 v23; // x22
  __int64 v24; // x20
  __int64 v25; // x8
  int v26; // w26
  unsigned int busiest_cpu; // w21
  int v28; // w9
  int v29; // w8
  __int64 first_idle_if_others_are_busy; // x0
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x9
  __int64 v33; // x8
  _QWORD *v34; // x9
  unsigned __int64 v35; // x10
  unsigned __int64 v36; // x9
  bool v37; // cf
  unsigned __int64 v38; // x9
  __int64 v39; // x24
  __int64 v40; // x20
  _DWORD *v41; // x21
  __int64 v42; // x25
  int v43; // w22
  _DWORD *v44; // [xsp+8h] [xbp-38h]
  __int64 v45; // [xsp+10h] [xbp-30h]
  __int64 v46; // [xsp+18h] [xbp-28h]
  __int64 v47; // [xsp+18h] [xbp-28h]
  _BYTE *v48; // [xsp+20h] [xbp-20h]
  __int64 v49; // [xsp+28h] [xbp-18h] BYREF
  int v50; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+38h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned int *)(result + 3632);
  if ( (unsigned int)v5 >= 0x20 )
LABEL_76:
    __break(0x5512u);
  v6 = *((_QWORD *)&_per_cpu_offset + v5);
  v7 = *(_QWORD *)(result + 3976);
  v50 = 0;
  v49 = 0;
  if ( (walt_disabled & 1) == 0 )
  {
    *a4 = 1;
    *a3 = 0;
    v8 = *(_DWORD *)(result + 3392);
    *(_QWORD *)(result + 3568) = 0;
    if ( v8 <= 1 && (assert_clock_updated___already_done_0 & 1) == 0 )
    {
      v40 = result;
      v41 = a3;
      assert_clock_updated___already_done_0 = 1;
      v42 = a2;
      v43 = a5;
      _warn_printk("rq->clock_update_flags < RQCF_ACT_SKIP");
      a5 = v43;
      a2 = v42;
      result = v40;
      a3 = v41;
      __break(0x800u);
    }
    *(_QWORD *)(result + 3968) = *(_QWORD *)(result + 3400);
    v9 = 1LL << v5;
    if ( (_cpu_active_mask & (1LL << v5)) != 0 && (_cpu_halt_mask[0] & v9) == 0 )
    {
      v10 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v5)];
      if ( (*((_QWORD *)v10 + 10) & 2) == 0 && (v10[541] & 1) == 0 && (walt_enforce_high_irq_cpu_mask & v9) == 0 )
      {
        if ( *(_DWORD *)(result + 3392) >= 3u )
          *(_DWORD *)(a2 + 8) = 4;
        if ( *(int *)(result + 2680) <= 0 )
        {
          v12 = *(unsigned int *)(result + 3632);
          v13 = 0;
          do
          {
            v14 = _cpu_possible_mask & (unsigned __int64)(-1LL << v13);
            if ( !v14 )
              break;
            v15 = __clz(__rbit64(v14));
            v16 = (char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v15);
            if ( *((char **)v16 + 333) != v16 + 2664 )
            {
              if ( (_DWORD)v12 != (_DWORD)v15 )
              {
                v18 = a5;
                v46 = a2;
                v19 = a3;
                v20 = result;
                raw_spin_rq_unlock(result);
                double_rq_lock(v20, v16);
                result = v20;
                if ( *(int *)(v20 + 2680) <= 0 )
                {
                  v33 = pick_highest_pushable_task(v16, (unsigned int)v12);
                  result = v20;
                  if ( v33 )
                  {
                    if ( ((*(_QWORD *)(*(_QWORD *)(v33 + 1376) + ((v12 >> 3) & 0x1FFFFFF8)) >> v12) & 1) != 0 )
                    {
                      v34 = (_QWORD *)(v33 + 5184);
                      v35 = *(_QWORD *)(v20 + 3400);
                      if ( (_UNKNOWN *)v33 == &init_task )
                        v34 = &vendor_data_pad;
                      v36 = v34[28];
                      if ( v35 <= *((_QWORD *)v16 + 425) )
                        v35 = *((_QWORD *)v16 + 425);
                      v37 = v35 >= v36;
                      v38 = v35 - v36;
                      if ( v38 == 0 || !v37 || v38 > 0x3D08F )
                      {
                        v39 = v33;
                        deactivate_task(v16, v33, 0);
                        set_task_cpu(v39, (unsigned int)v12);
                        activate_task(v20, v39, 0);
                        if ( v16 != (char *)v20 )
                          raw_spin_rq_unlock(v16);
                        a2 = v46;
                        a3 = v19;
                        result = v20;
                        goto LABEL_15;
                      }
                    }
                  }
                }
                a2 = v46;
                a3 = v19;
                a5 = v18;
                if ( v16 != (char *)result )
                {
                  raw_spin_rq_unlock(v16);
                  a2 = v46;
                  a5 = v18;
                  result = v20;
                  a3 = v19;
                }
              }
              break;
            }
            v17 = v15 > 0x1E;
            v13 = v15 + 1;
          }
          while ( !v17 );
        }
        if ( *(_DWORD *)(result + 4) )
          goto LABEL_15;
        if ( (a5 || *(_BYTE *)(*(_QWORD *)(result + 3528) + 40LL) == 1)
          && (!*(_DWORD *)(result + 3504) || v7 >= 0x7A121) )
        {
          v21 = result;
          v47 = a2;
          v44 = a3;
          should_help_min_cap((unsigned int)v5);
          v45 = v21;
          raw_spin_unlock(v21);
          if ( num_sched_clusters < 1 )
            goto LABEL_63;
          v22 = 0;
          v23 = 0;
          v48 = &walt_rq[v6];
          v24 = *(int *)(*(_QWORD *)&walt_rq[v6 + 8] + 32LL);
          while ( 1 )
          {
            v25 = *(_QWORD *)(cpu_array + 8 * v24);
            if ( !*(_DWORD *)(v25 + v22) )
              goto LABEL_76;
            v26 = *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset
                                                  + __clz(__rbit64(*(unsigned int *)(v25 + v22))))
                                                + 8]
                            + 32LL);
            busiest_cpu = walt_lb_find_busiest_cpu((unsigned int)v5, v25 + v22, &v50, 1);
            if ( busiest_cpu != -1 )
            {
              if ( v7 > 0x7A120
                || (v31 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v5) + 632],
                    v32 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + busiest_cpu) + 632],
                    v31 >= v32)
                && (v31 <= v32 || v50) )
              {
                if ( num_sched_clusters < 3
                  || ((v28 = num_sched_clusters - 1, (v29 = *(_DWORD *)(*((_QWORD *)v48 + 1) + 32LL)) != 0) || v26 != v28)
                  && (v29 != v28 || v26) )
                {
LABEL_60:
                  if ( busiest_cpu != (_DWORD)v5 && !*(_DWORD *)(v45 + 4) )
                    *v44 = walt_lb_pull_tasks((unsigned int)v5, busiest_cpu, &v49);
LABEL_63:
                  raw_spin_lock(v45);
                  a3 = v44;
                  result = v45;
                  a2 = v47;
LABEL_15:
                  v11 = *(_DWORD *)(result + 532);
                  if ( v11 && !*a3 )
                  {
                    *a3 = 1;
                    v11 = *(_DWORD *)(result + 532);
                  }
                  if ( *(_DWORD *)(result + 4) == v11 )
                  {
                    if ( !*a3 )
                      break;
                  }
                  else
                  {
                    *a3 = -1;
                  }
                  *(_QWORD *)(result + 3968) = 0;
                  break;
                }
                first_idle_if_others_are_busy = find_first_idle_if_others_are_busy();
                if ( (_DWORD)first_idle_if_others_are_busy == -1 )
                {
                  if ( walt_rotation_enabled == 1
                    && *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v5) + 632] > *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + busiest_cpu) + 632] )
                  {
                    goto LABEL_60;
                  }
                }
                else
                {
                  walt_kick_cpu(first_idle_if_others_are_busy);
                }
              }
            }
            ++v23;
            v22 += 8;
            if ( v23 >= num_sched_clusters )
              goto LABEL_63;
          }
        }
        *(_DWORD *)(result + 3392) |= *(_DWORD *)(a2 + 8);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
