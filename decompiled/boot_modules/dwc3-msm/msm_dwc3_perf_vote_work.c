__int64 __fastcall msm_dwc3_perf_vote_work(unsigned __int8 *a1)
{
  __int64 result; // x0
  int v3; // w9
  unsigned int v4; // w11
  __int64 v5; // x10
  int v6; // w10
  unsigned int v7; // w12
  int v8; // w20
  int v9; // w11
  unsigned int v10; // w8
  __int64 v11; // x1
  __int64 v12; // x0
  __int64 v13; // x0

  result = irq_to_desc(*((unsigned int *)a1 - 93));
  if ( result )
  {
    v3 = *(_DWORD *)(result + 144);
    v4 = v3 - *((_DWORD *)a1 - 92);
    if ( a1[1665] == 1 )
    {
      v5 = a1[1666];
      if ( (unsigned int)v5 <= 0x31 )
      {
        a1[1666] = v5 + 1;
        *(_DWORD *)&a1[4 * v5 + 1668] = v4;
      }
    }
    v6 = a1[1664];
    v8 = true;
    if ( v6 != 1 )
    {
      if ( a1[1664] || (!*(a1 - 184) ? (v7 = 200) : (v7 = 400), v4 < v7) )
        v8 = false;
    }
    v9 = *(a1 - 184);
    *((_DWORD *)a1 - 92) = v3;
    if ( v9 != v8 )
    {
      v10 = *((_DWORD *)a1 - 14);
      if ( v10 )
      {
        if ( v8 )
          v11 = v10;
        else
          v11 = 0xFFFFFFFFLL;
        cpu_latency_qos_update_request(a1 - 48, v11);
        v6 = a1[1664];
        *(a1 - 184) = v8;
      }
    }
    if ( ((unsigned __int8)v8 & (v6 == 0)) != 0 )
      v12 = 2000;
    else
      v12 = 100;
    v13 = _msecs_to_jiffies(v12);
    return queue_delayed_work_on(32, system_wq, a1, v13);
  }
  return result;
}
