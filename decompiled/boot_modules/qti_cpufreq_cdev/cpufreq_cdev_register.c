unsigned __int64 __fastcall cpufreq_cdev_register(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x20
  int v5; // w22
  int *v6; // x8
  int v7; // w9
  int v8; // t1
  unsigned int *v9; // x0
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x11
  int v13; // w8
  __int64 v14; // x22
  __int64 v15; // x8
  __int64 v16; // x3
  int v17; // w8
  unsigned __int64 result; // x0

  v2 = cpufreq_cpu_get(*(unsigned int *)(a1 - 128));
  if ( !v2 )
    return printk(&unk_685B, "qti_cpufreq_cdev", "cpufreq_cdev_register", *(unsigned int *)(a1 - 128));
  v3 = *(_QWORD *)(v2 + 384);
  v4 = v2;
  if ( !v3 )
    goto LABEL_22;
  v5 = 0;
  v6 = (int *)(v3 + 8);
  while ( 1 )
  {
    do
    {
      v8 = *v6;
      v6 += 3;
      v7 = v8;
    }
    while ( v8 == -1 );
    if ( v7 == -2 )
      break;
    ++v5;
  }
  if ( !v5 )
    goto LABEL_22;
  if ( v5 < 0 )
  {
    *(_QWORD *)(a1 - 104) = 0;
    goto LABEL_22;
  }
  v9 = (unsigned int *)_kmalloc_noprof(4LL * (unsigned int)v5, 3264);
  *(_QWORD *)(a1 - 104) = v9;
  if ( v9 )
  {
    if ( v5 <= 0 )
    {
      v17 = v5 - 1;
      v14 = a1 - 96;
      *(_QWORD *)(a1 - 8) = v4;
      *(_QWORD *)(a1 - 120) = 0;
      *(_QWORD *)(a1 - 112) = v17;
      v15 = v4 + 144;
    }
    else
    {
      v10 = 0;
      v11 = (unsigned int)v5 - 1LL;
      do
      {
        if ( *(_DWORD *)(v4 + 392) == 1 )
          v12 = v11;
        else
          v12 = v10;
        --v11;
        *(_DWORD *)(*(_QWORD *)(a1 - 104) + 4 * v10++) = *(_DWORD *)(*(_QWORD *)(v4 + 384) + 12 * v12 + 8);
      }
      while ( v11 != -1 );
      v13 = v5 - 1;
      v9 = *(unsigned int **)(a1 - 104);
      v14 = a1 - 96;
      *(_QWORD *)(a1 - 8) = v4;
      *(_QWORD *)(a1 - 120) = 0;
      *(_QWORD *)(a1 - 112) = v13;
      v15 = v4 + 144;
      if ( !v9 )
      {
        v16 = 0xFFFFFFFFLL;
LABEL_20:
        freq_qos_add_request(v15, v14, 2, v16);
        result = thermal_cooling_device_register(a1 - 32, a1 - 152, cpufreq_cdev_ops);
        *(_QWORD *)(a1 - 136) = result;
        if ( result < 0xFFFFFFFFFFFFF001LL )
          return result;
        printk(&unk_688A, "qti_cpufreq_cdev", "cpufreq_cdev_register", a1 - 32);
        freq_qos_remove_request(v14);
        goto LABEL_22;
      }
    }
    v16 = *v9;
    goto LABEL_20;
  }
LABEL_22:
  cpufreq_cpu_put(v4);
  if ( *(_QWORD *)(a1 - 136) )
    *(_QWORD *)(a1 - 136) = 0;
  return kfree(*(_QWORD *)(a1 - 104));
}
