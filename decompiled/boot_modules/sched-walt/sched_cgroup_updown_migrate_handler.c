__int64 __fastcall sched_cgroup_updown_migrate_handler(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v10; // x24
  __int16 v11; // w8
  unsigned int v12; // w19
  unsigned int v13; // w8
  unsigned int v14; // w9
  unsigned int v15; // w2
  _QWORD *v16; // x9
  unsigned int v18; // w1
  __int64 v19; // x12
  __int64 v20; // [xsp+8h] [xbp-48h] BYREF
  _QWORD *v21; // [xsp+10h] [xbp-40h]
  __int64 v22; // [xsp+18h] [xbp-38h]
  __int64 v23; // [xsp+20h] [xbp-30h]
  __int64 v24; // [xsp+28h] [xbp-28h]
  __int64 v25; // [xsp+30h] [xbp-20h]
  __int64 v26; // [xsp+38h] [xbp-18h]
  _QWORD v27[2]; // [xsp+40h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = v27;
  v10 = *(_QWORD *)(a1 + 8);
  v22 = 8;
  v11 = *(_WORD *)(a1 + 20);
  v27[0] = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  WORD2(v22) = v11;
  mutex_lock(&sysctl_cgroup_mutex);
  if ( use_cgroup_margin == 2 )
    goto LABEL_2;
  use_cgroup_margin = 1;
  if ( !a2 )
  {
    v16 = *(_QWORD **)(a1 + 8);
    LODWORD(v22) = 8;
    v21 = v16;
    v12 = proc_dointvec(&v20, 0, a3, a4, a5);
    goto LABEL_21;
  }
  v12 = proc_dointvec(&v20, a2, a3, a4, a5);
  if ( !v12 )
  {
    v13 = v27[0];
    if ( (unsigned int)(LODWORD(v27[0]) - 101) < 0xFFFFFF9C )
      goto LABEL_2;
    v14 = HIDWORD(v27[0]);
    if ( (unsigned int)(HIDWORD(v27[0]) - 101) < 0xFFFFFF9C )
      goto LABEL_2;
    if ( (_UNKNOWN *)v10 == &sysctl_sched_topapp_updownmigrate_0 )
    {
      v18 = 0;
      v15 = 1;
      goto LABEL_34;
    }
    if ( (_UNKNOWN *)v10 != &sysctl_sched_topapp_updownmigrate_1 )
    {
      if ( (_UNKNOWN *)v10 == &sysctl_sched_topapp_updownmigrate_2 )
      {
        v18 = 2;
        v15 = 1;
        goto LABEL_34;
      }
      if ( (_UNKNOWN *)v10 == &sysctl_sched_foreground_updownmigrate_0 )
      {
        v18 = 0;
        v15 = 2;
        goto LABEL_34;
      }
      if ( (_UNKNOWN *)v10 == &sysctl_sched_foreground_updownmigrate_1 )
      {
        v18 = 1;
        v15 = 2;
        goto LABEL_34;
      }
      if ( (_UNKNOWN *)v10 == &sysctl_sched_foreground_updownmigrate_2 )
      {
        v15 = 2;
        goto LABEL_29;
      }
      if ( (_UNKNOWN *)v10 == &sysctl_sched_background_updownmigrate_0 )
      {
        v18 = 0;
        v15 = 3;
      }
      else if ( (_UNKNOWN *)v10 == &sysctl_sched_background_updownmigrate_1 )
      {
        v18 = 1;
        v15 = 3;
      }
      else if ( (_UNKNOWN *)v10 == &sysctl_sched_background_updownmigrate_2 )
      {
        v18 = 2;
        v15 = 3;
      }
      else
      {
        if ( (_UNKNOWN *)v10 != &sysctl_sched_other_cgroup_updownmigrate_0 )
        {
          if ( (_UNKNOWN *)v10 != &sysctl_sched_other_cgroup_updownmigrate_1 )
          {
            if ( (_UNKNOWN *)v10 == &sysctl_sched_other_cgroup_updownmigrate_2 )
            {
              v15 = 0;
LABEL_29:
              v18 = 2;
              goto LABEL_34;
            }
LABEL_2:
            v12 = -22;
            goto LABEL_21;
          }
          v15 = 0;
LABEL_24:
          v18 = 1;
          goto LABEL_34;
        }
        v15 = 0;
        v18 = 0;
      }
LABEL_34:
      if ( LODWORD(v27[0]) >= HIDWORD(v27[0]) )
      {
        v19 = 4LL * v15;
        *(_DWORD *)v10 = v27[0];
        *(_DWORD *)(v10 + 4) = v14;
        sched_capacity_margin_up[v19 + v18] = 0x19000 / v13;
        sched_capacity_margin_down[v19 + v18] = 0x19000 / v14;
        v12 = 0;
        goto LABEL_21;
      }
      goto LABEL_2;
    }
    v15 = 1;
    goto LABEL_24;
  }
LABEL_21:
  mutex_unlock(&sysctl_cgroup_mutex);
  _ReadStatusReg(SP_EL0);
  return v12;
}
