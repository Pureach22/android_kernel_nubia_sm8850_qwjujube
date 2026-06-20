__int64 __fastcall sbt_ctl_check(unsigned int a1)
{
  __int64 v1; // x8
  bool v2; // w9
  __int64 v3; // x10
  __int64 v4; // x11
  unsigned int v5; // w12
  __int64 v6; // x11
  int v7; // w12
  int v8; // w13
  __int64 *v9; // x14
  __int64 v10; // x15
  __int64 v11; // x16
  __int64 v12; // x17
  __int64 *v13; // x10
  __int64 v14; // x11
  __int64 v15; // t1
  char v16; // w14
  unsigned __int64 v17; // x14
  unsigned __int64 v18; // x14
  bool v19; // cc
  char v20; // w12
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x12
  unsigned __int64 v23; // x12
  _BYTE *v24; // x13
  unsigned __int64 v25; // x14
  unsigned __int64 v26; // x13
  __int64 result; // x0
  char v28; // w9
  int v29; // w9
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = (unsigned int)(num_sched_clusters - 1);
  if ( (unsigned int)v1 >= 5 )
  {
LABEL_47:
    __break(0x5512u);
    goto LABEL_48;
  }
  if ( !sysctl_sched_sbt_enable || last_nr_big != 1 )
  {
    if ( num_sched_clusters != 5 )
    {
      v2 = 0;
      goto LABEL_34;
    }
LABEL_48:
    __break(1u);
  }
  if ( num_sched_clusters == 5 )
    goto LABEL_48;
  v2 = 0;
  if ( a1 <= 0x2D && *((_DWORD *)&cluster_state + 76 * (unsigned int)v1 + 27) == 1 )
  {
    if ( num_sched_clusters == 1 )
    {
      v6 = 0;
LABEL_19:
      v16 = 0;
      do
      {
        v17 = (-1LL << v16) & v6;
        if ( !v17 )
          break;
        v18 = __clz(__rbit64(v17));
        if ( *(_DWORD *)((char *)&cpu_state + *((_QWORD *)&_per_cpu_offset + v18) + 4) > 0x14u )
        {
LABEL_31:
          v2 = 0;
          goto LABEL_34;
        }
        v19 = v18 > 0x1E;
        v16 = v18 + 1;
      }
      while ( !v19 );
      v20 = 0;
      v21 = *(unsigned int *)(*(_QWORD *)cpu_array + 8 * v1);
      while ( 1 )
      {
        v22 = (-1LL << v20) & v21;
        if ( !v22 )
          goto LABEL_31;
        v23 = __clz(__rbit64(v22));
        v24 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v23)];
        v25 = *((_QWORD *)v24 + 5);
        v26 = *((_QWORD *)v24 + 79);
        if ( v25 < v26 )
          v26 = v25;
        if ( v26 >= 0xC9 )
          break;
        v19 = v23 > 0x1E;
        v20 = v23 + 1;
        if ( v19 )
          goto LABEL_31;
      }
      if ( v21 )
      {
        v2 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + __clz(__rbit64(v21))) + 632] > 0x2BBu;
        goto LABEL_34;
      }
      goto LABEL_47;
    }
    v3 = *(_QWORD *)cpu_array;
    if ( num_sched_clusters == 2 )
    {
      v4 = 0;
      v5 = 0;
    }
    else
    {
      v4 = ((_BYTE)num_sched_clusters - 1) & 2;
      v7 = 0;
      v8 = 0;
      v9 = (__int64 *)(v3 + 8);
      v10 = ((_BYTE)num_sched_clusters - 1) & 6;
      do
      {
        v11 = *(v9 - 1);
        v12 = *v9;
        v10 -= 2;
        v9 += 2;
        v7 |= v11;
        v8 |= v12;
      }
      while ( v10 );
      v5 = v8 | v7;
      if ( v4 == v1 )
        goto LABEL_18;
    }
    v13 = (__int64 *)(v3 + 8 * v4);
    v14 = v1 - v4;
    do
    {
      v15 = *v13++;
      --v14;
      v5 |= v15;
    }
    while ( v14 );
LABEL_18:
    v6 = v5;
    goto LABEL_19;
  }
LABEL_34:
  now_is_sbt = v2;
  result = _sw_hweight64((unsigned int)cpus_for_sbt_pause);
  v28 = now_is_sbt;
  if ( !(_DWORD)result )
    goto LABEL_45;
  if ( prev_is_sbt != now_is_sbt )
  {
    if ( (now_is_sbt & 1) != 0 )
    {
      v29 = sbt_ctl_check_prev_is_sbt_windows--;
      if ( v29 > 0 )
        goto LABEL_46;
      v30[0] = cpus_for_sbt_pause;
      if ( (prev_is_sbt & 1) == 0 )
        result = walt_pause_cpus((__int64)v30, 8);
    }
    else
    {
      v30[0] = cpus_for_sbt_pause;
      if ( (prev_is_sbt & 1) != 0 )
        result = walt_resume_cpus((__int64)v30, 8);
    }
    v28 = now_is_sbt;
    sbt_ctl_check_prev_is_sbt_windows = sysctl_sched_sbt_delay_windows;
LABEL_45:
    prev_is_sbt = v28;
    goto LABEL_46;
  }
  if ( sbt_ctl_check_prev_is_sbt_windows < (unsigned int)sysctl_sched_sbt_delay_windows )
    sbt_ctl_check_prev_is_sbt_windows = sysctl_sched_sbt_delay_windows;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
