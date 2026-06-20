__int64 __fastcall spi_geni_runtime_resume(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x19
  __int64 v3; // x21
  unsigned __int64 v4; // x20
  int v5; // w0
  int v6; // w0
  unsigned int v7; // w21
  __int64 v8; // x0
  __int64 (*v9)(void); // x8
  int v10; // w0
  int v11; // w0
  __int64 v12; // x20
  __int64 v13; // x22
  __int64 v14; // x23
  int v15; // w21
  int v16; // w0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x22
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x22
  __int64 v23; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  int v27; // w21
  __int64 v28; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 152);
  v3 = *(_QWORD *)(v2 + 488);
  if ( v3 )
  {
    if ( *(_DWORD *)(v2 + 496) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "spi_geni_runtime_resume", v4, v4 / 0x3E8);
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  if ( *(_BYTE *)(v2 + 503) != 1 )
  {
    ipc_log_string(*(_QWORD *)(v2 + 472), "%s: %d\n", "spi_geni_runtime_resume", 0);
    if ( *(_QWORD *)(v2 + 200) )
      spi_trace_log();
    if ( *(_BYTE *)(v2 + 502) != 1 || (v8 = *(_QWORD *)(v2 + 320)) == 0 )
    {
LABEL_23:
      if ( (*(_BYTE *)(v2 + 501) & 1) != 0 || (*(_BYTE *)(v2 + 504) & 1) != 0 || *(_BYTE *)(v2 + 500) != 1 )
      {
        v11 = geni_icc_enable(v2);
        if ( !v11 )
        {
          v7 = geni_se_resources_on(v2);
          writel_relaxed(0x7Fu, (unsigned int *)(*(_QWORD *)(v2 + 184) + 36LL));
          _const_udelay(42950);
          v21 = enable_irq(*(unsigned int *)(v2 + 192));
          if ( *(_BYTE *)(v2 + 500) == 1 )
          {
            v21 = spi_geni_gpi_pause_resume(v2, 0);
            v7 = v21;
          }
          v22 = *(_QWORD *)(v2 + 488);
          if ( v22 && v4 && *(_DWORD *)(v2 + 496) )
          {
            v23 = sched_clock(v21);
            ipc_log_string(
              v22,
              "%s:took %llu nsec(%llu usec)\n",
              "spi_geni_runtime_resume",
              v23 - v4,
              (v23 - v4) / 0x3E8);
          }
          return v7;
        }
      }
      else
      {
        v11 = geni_icc_enable(v2);
        if ( !v11 )
        {
          v12 = *(_QWORD *)(v2 + 120);
          v13 = *(_QWORD *)(v2 + 128);
          v14 = *(_QWORD *)(v2 + 24);
          v15 = clk_prepare(v12);
          if ( !v15 )
          {
            v15 = clk_enable(v12);
            if ( !v15 )
            {
              v15 = clk_prepare(v13);
              if ( !v15 )
              {
                v15 = clk_enable(v13);
                if ( !v15 )
                {
                  v15 = clk_prepare(v14);
                  if ( !v15 )
                  {
                    v16 = clk_enable(v14);
                    if ( !v16 )
                      return (unsigned int)spi_geni_gpi_pause_resume(v2, 0);
                    v15 = v16;
                    clk_unprepare(v14);
                  }
                  clk_disable(v13);
                }
                clk_unprepare(v13);
              }
              clk_disable(v12);
            }
            clk_unprepare(v12);
          }
          ipc_log_string(*(_QWORD *)(v2 + 472), "%s: Error %d turning on clocks\n", "spi_geni_runtime_resume", v15);
          if ( *(_QWORD *)(v2 + 200) )
            spi_trace_log();
          return (unsigned int)spi_geni_gpi_pause_resume(v2, 0);
        }
      }
      v7 = v11;
      ipc_log_string(*(_QWORD *)(v2 + 472), "%s failing at geni icc enable ret=%d\n", "spi_geni_runtime_resume", v11);
      if ( *(_QWORD *)(v2 + 200) )
      {
LABEL_43:
        spi_trace_log();
        return v7;
      }
      return v7;
    }
    v9 = *(__int64 (**)(void))(*(_QWORD *)v8 + 328LL);
    if ( v9 )
    {
      if ( *((_DWORD *)v9 - 1) != -403578064 )
        __break(0x8228u);
      v10 = v9();
      if ( !v10 )
        goto LABEL_21;
      v27 = v10;
    }
    else
    {
      v27 = -38;
    }
    ipc_log_string(*(_QWORD *)(v2 + 472), "%s dmaengine_resume failed: %d\n", "spi_geni_runtime_resume", v27);
    v28 = *(_QWORD *)(v2 + 200);
    if ( v28 )
      dev_err(v28, "%s dmaengine_resume failed: %d\n", "spi_geni_runtime_resume", v27);
    else
      printk(&unk_F7B1);
    if ( *(_QWORD *)(v2 + 200) )
      spi_trace_log();
LABEL_21:
    ipc_log_string(*(_QWORD *)(v2 + 472), "%s: Shared_SE dma_resume call\n", "spi_geni_runtime_resume");
    if ( *(_QWORD *)(v2 + 200) )
      spi_trace_log();
    goto LABEL_23;
  }
  if ( (*(_BYTE *)(v2 + 224) & 1) == 0 && (v5 = spi_geni_mas_setup(v1)) != 0 )
  {
    v7 = v5;
    ipc_log_string(*(_QWORD *)(v2 + 472), "%s mas_setup failed: %d\n", "spi_geni_levm_resume_proc", v5);
    v26 = *(_QWORD *)(v2 + 200);
    if ( v26 )
      dev_err(v26, "%s mas_setup failed: %d\n", "spi_geni_levm_resume_proc", v7);
    else
      printk(&unk_DF01);
    if ( *(_QWORD *)(v2 + 200) )
      goto LABEL_43;
  }
  else if ( *(_BYTE *)(v2 + 500) == 1 && (v6 = spi_geni_gpi_pause_resume(v2, 0)) != 0 )
  {
    v7 = v6;
    ipc_log_string(*(_QWORD *)(v2 + 472), "%s: ret:%d\n", "spi_geni_levm_resume_proc", v6);
    if ( *(_QWORD *)(v2 + 200) )
      goto LABEL_43;
  }
  else
  {
    v7 = spi_geni_lock_bus(v1);
    v17 = *(_QWORD *)(v2 + 472);
    if ( !v7 )
    {
      ipc_log_string(v17, "%s: ret:%d\n", "spi_geni_levm_resume_proc", 0);
      v18 = *(_QWORD *)(v2 + 200);
      if ( v18 )
        spi_trace_log();
      v19 = *(_QWORD *)(v2 + 488);
      if ( v19 )
      {
        v7 = 0;
        if ( !v4 || !*(_DWORD *)(v2 + 496) )
          return v7;
        v20 = sched_clock(v18);
        ipc_log_string(v19, "%s:took %llu nsec(%llu usec)\n", "spi_geni_levm_resume_proc", v20 - v4, (v20 - v4) / 0x3E8);
      }
      return 0;
    }
    ipc_log_string(v17, "%s lock_bus failed: %d\n", "spi_geni_levm_resume_proc", v7);
    v25 = *(_QWORD *)(v2 + 200);
    if ( v25 )
      dev_err(v25, "%s lock_bus failed: %d\n", "spi_geni_levm_resume_proc", v7);
    else
      printk(&unk_DBCB);
    if ( *(_QWORD *)(v2 + 200) )
      goto LABEL_43;
  }
  return v7;
}
