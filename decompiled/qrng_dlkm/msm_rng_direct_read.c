__int64 __fastcall msm_rng_direct_read(__int64 a1, _DWORD *a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // x20
  unsigned int *v5; // x23
  __int64 v8; // x0
  __int64 v9; // x20
  int v10; // w24
  __int64 v11; // x21
  __int64 v12; // x0

  if ( a3 >= 4 )
  {
    v5 = *(unsigned int **)(a1 + 8);
    mutex_lock(a1 + 24);
    v8 = *(_QWORD *)(a1 + 72);
    if ( v8 && (unsigned int)icc_set_bw(v8, 0, 300000) )
    {
      LODWORD(v3) = 0;
      goto LABEL_25;
    }
    v9 = *(_QWORD *)(a1 + 16);
    if ( v9 && (*(_BYTE *)(a1 + 80) & 1) == 0 )
    {
      if ( !(unsigned int)clk_prepare(*(_QWORD *)(a1 + 16)) )
      {
        if ( !(unsigned int)clk_enable(v9) )
          goto LABEL_9;
        clk_unprepare(v9);
      }
      printk(&unk_6F63);
      LODWORD(v3) = 0;
      goto LABEL_20;
    }
LABEL_9:
    v10 = 0;
    v3 = 0;
    while ( 1 )
    {
      if ( (readl_relaxed(v5 + 1) & 1) != 0 )
      {
        v3 += 4LL;
        *a2++ = readl_relaxed(v5);
        if ( a3 - v3 < 4 )
          goto LABEL_18;
      }
      else
      {
        if ( v10 == 5 )
        {
          if ( v3 )
          {
LABEL_18:
            v11 = *(_QWORD *)(a1 + 16);
            if ( !v11 )
              goto LABEL_20;
            goto LABEL_19;
          }
          printk(&unk_6EBD);
          v11 = *(_QWORD *)(a1 + 16);
          if ( v11 )
          {
LABEL_19:
            clk_disable(v11);
            clk_unprepare(v11);
          }
LABEL_20:
          v12 = *(_QWORD *)(a1 + 72);
          if ( !v12 || !(unsigned int)icc_set_bw(v12, 0, 0) )
          {
LABEL_22:
            mutex_unlock(a1 + 24);
            return (unsigned int)v3;
          }
LABEL_25:
          printk(&unk_6F82);
          goto LABEL_22;
        }
        ++v10;
        _const_udelay(1889800);
      }
      if ( v3 >= a3 || *(_BYTE *)(a1 + 80) == 1 )
        goto LABEL_18;
    }
  }
  LODWORD(v3) = 0;
  return (unsigned int)v3;
}
