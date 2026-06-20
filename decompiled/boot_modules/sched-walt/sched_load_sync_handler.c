__int64 __fastcall sched_load_sync_handler(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 *v5; // x24
  unsigned int v11; // w19
  int *v12; // x8
  __int64 *v13; // x9
  __int64 *v14; // x10
  __int64 *v15; // x11
  int v16; // w12
  int v17; // w13
  int v18; // w8

  if ( num_sched_clusters >= 1 )
  {
    v5 = *(__int64 **)(a1 + 8);
    mutex_lock(&load_sync_mutex);
    v11 = proc_dointvec(a1, a2, a3, a4, a5);
    if ( !v11 )
    {
      v12 = (int *)&sysctl_cluster01_load_sync;
      if ( v5 == &sysctl_cluster01_load_sync )
      {
        v13 = (__int64 *)&dword_685EC;
        v14 = (__int64 *)&dword_685AC;
        v15 = (__int64 *)&dword_6856C;
        goto LABEL_32;
      }
      v12 = (int *)&sysctl_cluster01_load_sync_60fps;
      if ( v5 == &sysctl_cluster01_load_sync_60fps )
      {
        v13 = (__int64 *)&dword_686B8;
        v14 = (__int64 *)&dword_68678;
        v15 = (__int64 *)&dword_68638;
        goto LABEL_32;
      }
      v12 = &sysctl_cluster02_load_sync;
      if ( v5 == (__int64 *)&sysctl_cluster02_load_sync )
      {
        v13 = &qword_685F0;
        v14 = &qword_685B0;
        v15 = &qword_68570;
        goto LABEL_32;
      }
      v12 = &sysctl_cluster03_load_sync;
      if ( v5 == (__int64 *)&sysctl_cluster03_load_sync )
      {
        v13 = (__int64 *)((char *)&qword_685F0 + 4);
        v14 = (__int64 *)((char *)&qword_685B0 + 4);
        v15 = (__int64 *)((char *)&qword_68570 + 4);
        goto LABEL_32;
      }
      v12 = (int *)&sysctl_cluster10_load_sync;
      if ( v5 == &sysctl_cluster10_load_sync )
      {
        v13 = &qword_685F8;
        v14 = &qword_685B8;
        v15 = &qword_68578;
        goto LABEL_32;
      }
      v12 = (int *)&sysctl_cluster10_load_sync_60fps;
      if ( v5 == &sysctl_cluster10_load_sync_60fps )
      {
        v13 = (__int64 *)&dword_686C4;
        v14 = (__int64 *)&dword_68684;
        v15 = (__int64 *)&dword_68644;
        goto LABEL_32;
      }
      v12 = &sysctl_cluster12_load_sync;
      if ( v5 == (__int64 *)&sysctl_cluster12_load_sync )
      {
        v13 = &qword_68600;
        v14 = &qword_685C0;
        v15 = &qword_68580;
        goto LABEL_32;
      }
      v12 = &sysctl_cluster13_load_sync;
      if ( v5 == (__int64 *)&sysctl_cluster13_load_sync )
      {
        v13 = (__int64 *)((char *)&qword_68600 + 4);
        v14 = (__int64 *)((char *)&qword_685C0 + 4);
        v15 = (__int64 *)((char *)&qword_68580 + 4);
        goto LABEL_32;
      }
      v12 = &sysctl_cluster20_load_sync;
      if ( v5 == (__int64 *)&sysctl_cluster20_load_sync )
      {
        v13 = &qword_68608;
        v14 = &qword_685C8;
        v15 = &qword_68588;
        goto LABEL_32;
      }
      v12 = &sysctl_cluster21_load_sync;
      if ( v5 == (__int64 *)&sysctl_cluster21_load_sync )
      {
        v13 = (__int64 *)((char *)&qword_68608 + 4);
        v14 = (__int64 *)((char *)&qword_685C8 + 4);
        v15 = (__int64 *)((char *)&qword_68588 + 4);
        goto LABEL_32;
      }
      v12 = &sysctl_cluster23_load_sync;
      if ( v5 == (__int64 *)&sysctl_cluster23_load_sync )
      {
        v13 = (__int64 *)&dword_68614;
        v14 = (__int64 *)&dword_685D4;
        v15 = (__int64 *)&dword_68594;
        goto LABEL_32;
      }
      v12 = &sysctl_cluster30_load_sync;
      if ( v5 == (__int64 *)&sysctl_cluster30_load_sync )
      {
        v13 = &qword_68618;
        v14 = &qword_685D8;
        v15 = &qword_68598;
        goto LABEL_32;
      }
      v12 = &sysctl_cluster31_load_sync;
      if ( v5 == (__int64 *)&sysctl_cluster31_load_sync )
      {
        v13 = (__int64 *)((char *)&qword_68618 + 4);
        v14 = (__int64 *)((char *)&qword_685D8 + 4);
        v15 = (__int64 *)((char *)&qword_68598 + 4);
        goto LABEL_32;
      }
      v12 = &sysctl_cluster32_load_sync;
      if ( v5 == (__int64 *)&sysctl_cluster32_load_sync )
      {
        v13 = &qword_68620;
        v14 = &qword_685E0;
        v15 = &qword_685A0;
LABEL_32:
        v16 = *v12;
        v17 = v12[1];
        v18 = v12[2];
        *(_DWORD *)v15 = v16;
        *(_DWORD *)v14 = v17;
        *(_DWORD *)v13 = v18;
      }
    }
    mutex_unlock(&load_sync_mutex);
    return v11;
  }
  return (unsigned int)-22;
}
