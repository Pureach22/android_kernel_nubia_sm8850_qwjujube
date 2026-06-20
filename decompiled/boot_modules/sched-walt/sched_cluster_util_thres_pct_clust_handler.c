__int64 __fastcall sched_cluster_util_thres_pct_clust_handler(
        __int64 *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x10
  unsigned int v16; // w19
  __int64 v18; // [xsp+8h] [xbp-88h] BYREF
  _QWORD *v19; // [xsp+10h] [xbp-80h]
  __int64 v20; // [xsp+18h] [xbp-78h]
  __int64 v21; // [xsp+20h] [xbp-70h]
  __int64 v22; // [xsp+28h] [xbp-68h]
  __int64 v23; // [xsp+30h] [xbp-60h]
  __int64 v24; // [xsp+38h] [xbp-58h]
  _QWORD v25[7]; // [xsp+40h] [xbp-50h] BYREF
  _QWORD v26[3]; // [xsp+78h] [xbp-18h] BYREF

  v26[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1[4];
  v6 = a1[5];
  v7 = a1[6];
  v20 = 0;
  v25[6] = v7;
  v25[4] = v5;
  v25[5] = v6;
  v8 = *a1;
  v9 = a1[1];
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v25[0] = v8;
  v25[1] = v9;
  v10 = a1[3];
  v25[2] = a1[2];
  v25[3] = v10;
  v18 = 0;
  v19 = v26;
  LODWORD(v20) = 16;
  WORD2(v20) = *((_WORD *)a1 + 10);
  if ( num_sched_clusters < 1 )
  {
    v16 = -22;
  }
  else
  {
    v26[0] = 0;
    v26[1] = 0;
    mutex_lock(&util_thres_mutex);
    if ( a2 )
    {
      v16 = proc_dointvec_minmax(v25, a2, a3, a4, a5);
      if ( !v16 )
        sysctl_sched_cluster_util_thres_pct = sysctl_sched_cluster_util_thres_pct_clust;
    }
    else
    {
      v19 = (_QWORD *)a1[1];
      LODWORD(v20) = 4 * num_sched_clusters;
      v16 = proc_dointvec(&v18, 0, a3, a4, a5);
    }
    mutex_unlock(&util_thres_mutex);
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
