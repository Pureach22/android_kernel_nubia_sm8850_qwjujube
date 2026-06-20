__int64 __fastcall qfprom_reg_write(_QWORD *a1, unsigned int a2, __int64 a3, unsigned __int64 a4)
{
  __int64 v7; // x20
  unsigned int v9; // w22
  unsigned int v10; // w0
  unsigned int v11; // w0
  __int64 rate; // x20
  unsigned int v13; // w0
  unsigned int v14; // w0
  unsigned int v15; // w0
  __int64 v16; // x22
  unsigned int v17; // w0
  unsigned int v18; // w22
  unsigned int v19; // w23
  __int64 v20; // x0
  __int64 v21; // x26
  __int64 v22; // x0
  __int64 v23; // x26
  __int64 v24; // x24
  __int64 v25; // x26
  __int64 v26; // x21
  __int64 v27; // x0
  __int64 v28; // x21
  unsigned int v29; // w21
  __int64 v30; // x19
  unsigned int v32; // w8
  unsigned int v39; // w10

  if ( (a4 & 3) != 0 )
  {
    dev_err(a1[4], "%zu is not an integral number of words\n", a4);
    return 4294967274LL;
  }
  else
  {
    if ( (a2 & 3) == 0 )
    {
      v7 = a1[5];
      v9 = *(_DWORD *)(a1[7] + 12LL);
      v10 = clk_prepare(v7);
      if ( v10 )
      {
        v29 = v10;
      }
      else
      {
        v11 = clk_enable(v7);
        if ( !v11 )
        {
          rate = clk_get_rate(a1[5]);
          v13 = clk_set_rate(a1[5], *(unsigned int *)(a1[7] + 8LL));
          if ( v13 )
          {
            v29 = v13;
            dev_err(a1[4], "Failed to set clock rate for enable\n");
          }
          else
          {
            v14 = regulator_set_voltage(a1[6], v9, 0x7FFFFFFF);
            if ( v14 )
            {
              v29 = v14;
              dev_err(a1[4], "Failed to set %duV\n", v9);
            }
            else
            {
              v15 = regulator_enable(a1[6]);
              v16 = a1[4];
              if ( v15 )
              {
                v29 = v15;
                dev_err(a1[4], "Failed to enable regulator\n");
              }
              else
              {
                v17 = _pm_runtime_resume(a1[4], 4);
                if ( (v17 & 0x80000000) == 0 )
                {
                  dev_pm_genpd_set_performance_state(a1[4], 0x7FFFFFFF);
                  v18 = readl((unsigned int *)(a1[1] + 60LL));
                  v19 = readl((unsigned int *)(a1[1] + 68LL));
                  writel(*(unsigned int *)(a1[7] + 4LL), a1[1] + 60LL);
                  v20 = writel(*(unsigned int *)a1[7], a1[1] + 68LL);
                  v21 = ktime_get(v20);
                  v22 = readl_relaxed(a1[1] + 72LL);
                  if ( !(_DWORD)v22 )
                    goto LABEL_15;
                  v23 = v21 + 10000000;
                  while ( ktime_get(v22) <= v23 )
                  {
                    usleep_range_state(26, 100, 2);
                    __yield();
                    v22 = readl_relaxed(a1[1] + 72LL);
                    if ( !(_DWORD)v22 )
                      goto LABEL_15;
                  }
                  v22 = readl_relaxed(a1[1] + 72LL);
                  if ( (_DWORD)v22 )
                  {
                    dev_err(a1[4], "Timeout waiting for initial ready; aborting.\n");
                  }
                  else
                  {
LABEL_15:
                    if ( (int)(a4 >> 2) >= 1 )
                    {
                      v24 = (a4 >> 2) & 0x7FFFFFFF;
                      v25 = 0;
                      do
                      {
                        v22 = writel(*(unsigned int *)(a3 + v25), *a1 + a2 + (int)v25);
                        --v24;
                        v25 += 4;
                      }
                      while ( v24 );
                    }
                    v26 = ktime_get(v22);
                    v27 = readl_relaxed(a1[1] + 72LL);
                    if ( !(_DWORD)v27 )
                      goto LABEL_24;
                    v28 = v26 + 10000000;
                    while ( ktime_get(v27) <= v28 )
                    {
                      usleep_range_state(26, 100, 2);
                      __yield();
                      v27 = readl_relaxed(a1[1] + 72LL);
                      if ( !(_DWORD)v27 )
                        goto LABEL_24;
                    }
                    if ( !(unsigned int)readl_relaxed(a1[1] + 72LL) )
                    {
LABEL_24:
                      v29 = 0;
LABEL_25:
                      writel(v18, a1[1] + 60LL);
                      writel(v19, a1[1] + 68LL);
                      dev_pm_genpd_set_performance_state(a1[4], 0);
                      _pm_runtime_idle(a1[4], 5);
                      if ( (unsigned int)regulator_set_voltage(a1[6], 0, 0x7FFFFFFF) )
                        dev_warn(a1[4], "Failed to set 0 voltage (ignoring)\n");
                      if ( (unsigned int)regulator_disable(a1[6]) )
                        dev_warn(a1[4], "Failed to disable regulator (ignoring)\n");
                      if ( (unsigned int)clk_set_rate(a1[5], rate) )
                        dev_warn(a1[4], "Failed to set clock rate for disable (ignoring)\n");
                      goto LABEL_31;
                    }
                    dev_err(a1[4], "Timeout waiting for finish.\n");
                  }
                  v29 = -110;
                  goto LABEL_25;
                }
                v32 = *(_DWORD *)(v16 + 480);
                do
                {
                  if ( !v32 )
                    break;
                  _X12 = (unsigned int *)(v16 + 480);
                  __asm { PRFM            #0x11, [X12] }
                  while ( 1 )
                  {
                    v39 = __ldxr(_X12);
                    if ( v39 != v32 )
                      break;
                    if ( !__stlxr(v32 - 1, _X12) )
                    {
                      __dmb(0xBu);
                      break;
                    }
                  }
                  _ZF = v39 == v32;
                  v32 = v39;
                }
                while ( !_ZF );
                v29 = v17;
                dev_err(a1[4], "Failed to enable power-domain\n");
                regulator_disable(a1[6]);
              }
            }
            clk_set_rate(a1[5], rate);
          }
LABEL_31:
          v30 = a1[5];
          clk_disable(v30);
          clk_unprepare(v30);
          return v29;
        }
        v29 = v11;
        clk_unprepare(v7);
      }
      dev_err(a1[4], "Failed to enable clock\n");
      return v29;
    }
    dev_err(a1[4], "Invalid offset: %#x.  Must be word aligned\n", a2);
    return 4294967274LL;
  }
}
