__int64 __fastcall walt_lb_check_for_rotation(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w21
  int v4; // w8
  char v5; // w9
  unsigned __int64 v6; // x25
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x27
  __int64 v9; // x9
  char *v10; // x20
  char *v11; // x9
  char *v12; // x10
  bool v13; // zf
  _QWORD *v14; // x9
  unsigned __int64 v15; // x9
  unsigned int v16; // w28
  char v17; // w9
  unsigned __int64 v18; // x27
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x21
  __int64 v21; // x9
  char *v22; // x20
  char *v23; // x9
  char *v24; // x10
  _QWORD *v25; // x9
  unsigned __int64 v26; // x9
  char *v27; // x22
  __int64 v28; // x0
  char *v29; // x23
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // [xsp+8h] [xbp-18h]
  unsigned int v33; // [xsp+14h] [xbp-Ch]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v2 = *(unsigned int *)(result + 3632);
  if ( (unsigned int)v2 >= 0x20 )
    goto LABEL_46;
  if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v2) + 8] + 32LL) == min_possible_cluster_id )
  {
    v3 = nr_cpu_ids;
    v4 = _cpu_possible_mask;
    v5 = 0;
    v6 = 0;
    v32 = result;
    v34 = *(_QWORD *)(result + 3400);
    v33 = nr_cpu_ids;
    do
    {
      v7 = (unsigned int)(-1LL << v5) & v4;
      if ( !(_DWORD)v7 )
        break;
      v8 = __clz(__rbit64(v7));
      v9 = *((_QWORD *)&_per_cpu_offset + v8);
      if ( *(_DWORD *)(*(_QWORD *)&walt_rq[v9 + 8] + 32LL) != min_possible_cluster_id )
        break;
      if ( (*(_QWORD *)&walt_rq[v9 + 80] & 2) == 0 )
      {
        v10 = (char *)&runqueues + v9;
        if ( *(_QWORD *)((char *)&runqueues + v9 + 3568) )
        {
          result = *((_QWORD *)v10 + 418);
          if ( *(int *)(result + 148) >= 100 )
          {
            result = walt_is_idle_task((char *)result);
            v4 = _cpu_possible_mask;
            if ( (result & 1) == 0 )
            {
              v11 = *((char **)v10 + 418);
              v12 = v11 + 5184;
              v13 = v11 == (char *)&init_task;
              v14 = &vendor_data_pad;
              if ( !v13 )
                v14 = v12;
              v15 = v34 - v14[29];
              if ( v15 > v6 )
              {
                v3 = v8;
                v6 = v15;
              }
            }
          }
        }
      }
      v5 = v8 + 1;
    }
    while ( v8 < 0x1F );
    v16 = v33;
    if ( v3 == (_DWORD)v2 )
    {
      v17 = 0;
      v18 = 0;
      do
      {
        v19 = (unsigned int)(-1LL << v17) & v4;
        if ( !(_DWORD)v19 )
          break;
        v20 = __clz(__rbit64(v19));
        v21 = *((_QWORD *)&_per_cpu_offset + v20);
        if ( *(_DWORD *)(*(_QWORD *)&walt_rq[v21 + 8] + 32LL) != min_possible_cluster_id
          && (*(_QWORD *)&walt_rq[v21 + 80] & 2) == 0 )
        {
          v22 = (char *)&runqueues + v21;
          result = *(_QWORD *)((char *)&runqueues + v21 + 3344);
          if ( *(int *)(result + 148) >= 100 )
          {
            result = walt_is_idle_task((char *)result);
            v4 = _cpu_possible_mask;
            if ( (result & 1) == 0 && *((_DWORD *)v22 + 1) <= 1u )
            {
              v23 = *((char **)v22 + 418);
              v24 = v23 + 5184;
              v13 = v23 == (char *)&init_task;
              v25 = &vendor_data_pad;
              if ( !v13 )
                v25 = v24;
              v26 = v34 - v25[29];
              if ( v26 >= 0xF42400 && v26 > v18 )
              {
                v16 = v20;
                v18 = v26;
              }
            }
          }
        }
        v17 = v20 + 1;
      }
      while ( v20 < 0x1F );
      if ( v16 != nr_cpu_ids )
      {
        if ( v16 <= 0x1F )
        {
          v27 = (char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v16);
          double_rq_lock(v32, v27);
          v28 = *((_QWORD *)v27 + 418);
          if ( *(int *)(v28 + 148) < 100
            || (walt_is_idle_task((char *)v28) & 1) != 0
            || *(_DWORD *)(v32 + 3576)
            || *((_DWORD *)v27 + 894)
            || (v30 = *(_QWORD *)(v32 + 3344), ((**(_QWORD **)(v30 + 1376) >> v16) & 1) == 0)
            || ((**(_QWORD **)(*((_QWORD *)v27 + 418) + 1376LL) >> v2) & 1) == 0 )
          {
            v29 = nullptr;
            if ( v27 == (char *)v32 )
              goto LABEL_39;
          }
          else
          {
            get_task_struct(v30);
            get_task_struct(*((_QWORD *)v27 + 418));
            mark_reserved((unsigned int)v2);
            mark_reserved(v16);
            v29 = (char *)&walt_lb_rotate_works + *((_QWORD *)&_per_cpu_offset + v2);
            *((_QWORD *)v29 + 4) = *(_QWORD *)(v32 + 3344);
            v31 = *((_QWORD *)v27 + 418);
            *((_DWORD *)v29 + 12) = v2;
            *((_DWORD *)v29 + 13) = v16;
            *((_QWORD *)v29 + 5) = v31;
            *((_DWORD *)v27 + 894) = 1;
            *(_DWORD *)(v32 + 3576) = 1;
            if ( v27 == (char *)v32 )
            {
LABEL_39:
              result = raw_spin_rq_unlock(v32);
              if ( v29 )
                return queue_work_on((unsigned int)v2, system_highpri_wq, v29);
              return result;
            }
          }
          raw_spin_rq_unlock(v27);
          goto LABEL_39;
        }
LABEL_46:
        __break(0x5512u);
        return check_for_higher_capacity(result, a2);
      }
    }
  }
  return result;
}
