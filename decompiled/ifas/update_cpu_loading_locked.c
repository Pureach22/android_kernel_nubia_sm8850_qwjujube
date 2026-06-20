__int64 update_cpu_loading_locked()
{
  __int64 v0; // x19
  __int64 v1; // x1
  __int64 v2; // x8
  __int64 v3; // x9
  int v4; // w21
  __int64 v5; // x26
  __int64 v6; // x9
  __int64 v7; // x25
  __int64 v8; // x20
  __int64 v9; // x28
  _QWORD *v10; // x8
  __int64 v11; // x10
  __int64 cpu_idle_time; // x0
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x12
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x10
  __int64 v18; // x10
  _DWORD *v19; // x10
  int v20; // t1
  __int64 v22; // [xsp+8h] [xbp-18h]
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  if ( cluster_num >= 1 )
  {
    v0 = 0;
    v22 = 0;
    do
    {
      v1 = 0;
      v2 = cpufreq_dev;
      v3 = cpufreq_dev + 344 * v0;
      v5 = *(unsigned int *)(v3 + 4);
      v4 = *(_DWORD *)(v3 + 8);
      *(_QWORD *)(v3 + 80) = *(unsigned int *)(v3 + 84);
      if ( (int)v5 <= v4 )
      {
        if ( (unsigned int)v5 <= 8 )
          v6 = 8;
        else
          v6 = (unsigned int)v5;
        v7 = 0;
        v8 = v22 + 8 * v5;
        v9 = v6 - v5;
        do
        {
          if ( v9 == v7 )
            __break(0x5512u);
          v10 = (_QWORD *)(v2 + v8 + 8 * v7);
          v11 = v10[19];
          v10[27] = v10[11];
          v10[35] = v11;
          cpu_idle_time = get_cpu_idle_time((unsigned int)(v5 + v7), v23, 1);
          v13 = v23[0];
          v2 = cpufreq_dev;
          v16 = cpufreq_dev + v8 + 8 * v7;
          *(_QWORD *)(v16 + 88) = v23[0];
          v14 = *(_QWORD *)(v16 + 216);
          v15 = *(_QWORD *)(v16 + 280);
          *(_QWORD *)(v16 + 152) = cpu_idle_time;
          LODWORD(v16) = 0;
          if ( ((_cpu_active_mask >> ((unsigned __int8)v5 + (unsigned __int8)v7)) & 1) != 0 && v13 != v14 )
          {
            v17 = v13 - v14;
            if ( v17 > cpu_idle_time - v15 )
              v16 = 100 * (v17 - (cpu_idle_time - v15)) / (unsigned int)v17;
          }
          v18 = v2 + 344 * v0;
          v20 = *(_DWORD *)(v18 + 84);
          v19 = (_DWORD *)(v18 + 84);
          v1 = (unsigned int)v20;
          if ( (int)v16 > v20 )
          {
            v1 = (unsigned int)v16;
            *v19 = v16;
          }
          ++v7;
        }
        while ( v4 > (int)v5 - 1 + (int)v7 );
      }
      ifas_systrace_c((unsigned int)saved_connected_pid, v1, "cpu:clus%d:loading", v0++);
      v22 += 344;
    }
    while ( v0 < cluster_num );
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
