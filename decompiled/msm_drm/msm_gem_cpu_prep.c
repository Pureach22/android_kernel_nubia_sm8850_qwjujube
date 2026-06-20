__int64 __fastcall msm_gem_cpu_prep(__int64 a1, unsigned int a2, _QWORD *a3)
{
  __int64 v5; // x21
  __int64 v6; // x0
  unsigned int v7; // w9

  if ( (a2 & 4) != 0 || *a3 < ktime_get(a1) )
    v5 = 0;
  else
    v5 = nsecs_to_jiffies();
  v6 = dma_resv_wait_timeout(*(_QWORD *)(a1 + 464), (a2 >> 1) & 1, 1, v5);
  if ( v5 )
    v7 = -110;
  else
    v7 = -16;
  if ( v6 )
    return (unsigned int)v6 & (unsigned int)(v6 >> 63);
  else
    return v7;
}
