__int64 __fastcall sched_updown_early_migrate_handler(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int *v5; // x23
  int v6; // w24
  unsigned __int16 v7; // w8
  unsigned int v13; // w19
  unsigned int v14; // w8
  int *v15; // x9
  __int64 *v16; // x9
  __int64 v18; // [xsp+0h] [xbp-50h] BYREF
  __int64 *v19; // [xsp+8h] [xbp-48h]
  int v20; // [xsp+10h] [xbp-40h]
  int v21; // [xsp+14h] [xbp-3Ch]
  __int64 v22; // [xsp+18h] [xbp-38h]
  __int64 v23; // [xsp+20h] [xbp-30h]
  __int64 v24; // [xsp+28h] [xbp-28h]
  __int64 v25; // [xsp+30h] [xbp-20h]
  __int64 v26; // [xsp+38h] [xbp-18h] BYREF
  unsigned int v27; // [xsp+40h] [xbp-10h]
  __int64 v28; // [xsp+48h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(int **)(a1 + 8);
  v18 = 0;
  v19 = &v26;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  if ( num_sched_clusters )
    v6 = num_sched_clusters - 1;
  else
    v6 = 0;
  v7 = *(_WORD *)(a1 + 20);
  v20 = 12;
  v21 = v7;
  if ( v6 >= 1 )
  {
    v27 = 0;
    v26 = 0;
    mutex_lock(&sysctl_cgroup_mutex);
    if ( use_cgroup_margin == 1 )
      goto LABEL_6;
    use_cgroup_margin = 2;
    if ( !a2 )
    {
      v16 = *(__int64 **)(a1 + 8);
      v20 = 4 * v6;
      v19 = v16;
      v13 = proc_dointvec(&v18, 0, a3, a4, a5);
      goto LABEL_20;
    }
    v13 = proc_dointvec(&v18, a2, a3, a4, a5);
    if ( v13 )
    {
LABEL_20:
      mutex_unlock(&sysctl_cgroup_mutex);
      goto LABEL_21;
    }
    v14 = v26;
    if ( (int)v26 < 1024 )
      goto LABEL_6;
    if ( v6 == 1 )
      goto LABEL_12;
    if ( SHIDWORD(v26) < 1024 )
      goto LABEL_6;
    if ( v6 == 2 )
      goto LABEL_12;
    v15 = (int *)v27;
    if ( (int)v27 < 1024 )
      goto LABEL_6;
    if ( v6 == 3 )
    {
LABEL_12:
      v15 = &sysctl_sched_early_up;
      if ( v5 != &sysctl_sched_early_up )
      {
        if ( sysctl_sched_early_up < (unsigned int)v26 )
        {
          if ( v6 == 1 )
          {
LABEL_29:
            *v5 = v14;
LABEL_30:
            ((void (__fastcall *)(bool))sched_update_updown_early_migrate_values)(v5 == v15);
            v13 = 0;
            goto LABEL_20;
          }
          if ( (unsigned int)qword_68520 < HIDWORD(v26) )
          {
            if ( v6 == 2 )
              goto LABEL_33;
            if ( HIDWORD(qword_68520) < v27 )
              goto LABEL_35;
          }
        }
LABEL_6:
        v13 = -22;
        goto LABEL_20;
      }
    }
    else
    {
      __break(0x5512u);
    }
    if ( v14 >= sysctl_sched_early_down )
      goto LABEL_6;
    if ( v6 == 1 )
      goto LABEL_29;
    if ( HIDWORD(v26) >= (unsigned int)qword_6852C )
      goto LABEL_6;
    if ( v6 == 2 )
    {
LABEL_33:
      *v5 = v14;
      v5[1] = HIDWORD(v26);
      goto LABEL_30;
    }
    if ( v27 < HIDWORD(qword_6852C) )
    {
LABEL_35:
      *v5 = v14;
      v5[1] = HIDWORD(v26);
      v5[2] = v27;
      goto LABEL_30;
    }
    goto LABEL_6;
  }
  v13 = -22;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v13;
}
