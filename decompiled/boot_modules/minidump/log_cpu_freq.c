void __fastcall log_cpu_freq(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned int v3; // w8
  int v4; // w20
  unsigned int v6; // w21
  __int64 v7; // x0
  unsigned int *v8; // x8
  unsigned int v9; // w11
  unsigned int *v10; // x9
  __int64 v11; // x10

  v3 = *(_DWORD *)(a2 + 28);
  if ( v3 >= 0x20 )
    goto LABEL_9;
  v4 = cpu_topology[12 * v3 + 2];
  if ( v4 > max_cluster )
    return;
  v6 = *(_DWORD *)(cpuclk_log + 168LL * v4);
  v7 = sched_clock();
  if ( v6 > 9 )
  {
LABEL_9:
    __break(0x5512u);
    md_module_process();
    return;
  }
  v8 = (unsigned int *)(cpuclk_log + 168LL * v4);
  if ( v6 == 9 )
    v9 = 0;
  else
    v9 = v6 + 1;
  v10 = &v8[4 * v6];
  *((_QWORD *)v10 + 1) = v7;
  v11 = *a3;
  *v8 = v9;
  *((_QWORD *)v10 + 2) = v11;
}
