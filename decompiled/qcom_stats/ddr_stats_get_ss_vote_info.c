__int64 __fastcall ddr_stats_get_ss_vote_info(int a1, __int64 a2)
{
  bool v2; // zf
  __int64 result; // x0
  unsigned int v5; // w0
  unsigned int v6; // w0
  __int64 v7; // x1
  unsigned int *v8; // x20
  __int64 i; // x22
  int v10; // w8
  __int64 v11; // x9
  unsigned int v12; // w0
  unsigned int v13; // w19

  v2 = a1 == 28;
  result = 4294967277LL;
  if ( v2 && a2 && drv )
  {
    if ( *(_QWORD *)(drv + 240) )
    {
      mutex_lock(drv + 192);
      v5 = qmp_send(*(_QWORD *)(drv + 240), "{class: ddr, res: drvs_ddr_votes}", 64);
      if ( v5 )
      {
        v13 = v5;
        printk(&unk_A305, v5);
      }
      else
      {
        v6 = readl_relaxed((unsigned int *)(*(_QWORD *)drv + *(_QWORD *)(*(_QWORD *)(drv + 8) + 8LL) + 4LL));
        if ( v6 >= 0x15 )
        {
          printk(&unk_A209, v7);
        }
        else
        {
          v8 = (unsigned int *)(*(_QWORD *)drv + *(_QWORD *)(*(_QWORD *)(drv + 8) + 8LL) + ((16 * v6) | 8));
          if ( v8 )
          {
            for ( i = 0; i != 224; i += 8 )
            {
              v12 = readl_relaxed(v8);
              if ( v12 == -8531 )
              {
                v10 = -8531;
                *(_DWORD *)(a2 + i) = -8531;
              }
              else if ( v12 == -559030611 )
              {
                *(_DWORD *)(a2 + i) = -559030611;
                v10 = -559030611;
              }
              else
              {
                *(_DWORD *)(a2 + i) = (v12 >> 14) & 0x3FFF;
                v10 = v12 & 0x3FFF;
              }
              v11 = a2 + i;
              ++v8;
              *(_DWORD *)(v11 + 4) = v10;
            }
            v13 = 0;
            goto LABEL_17;
          }
        }
        printk(&unk_A326, v7);
        v13 = -22;
      }
LABEL_17:
      mutex_unlock(drv + 192);
      return v13;
    }
    return 4294967201LL;
  }
  return result;
}
