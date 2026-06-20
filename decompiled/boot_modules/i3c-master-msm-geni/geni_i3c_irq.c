__int64 __fastcall geni_i3c_irq(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned __int64 v4; // x20
  __int64 v5; // x21
  unsigned int v6; // w24
  int v7; // w26
  unsigned int v8; // w23
  unsigned int v9; // w22
  int v10; // w0
  int v11; // w25
  int v12; // w8
  int v13; // w26
  int v14; // w0
  int v15; // w9
  int v16; // w8
  __int64 v17; // x8
  int v18; // w9
  int v19; // w8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x21
  __int64 v25; // x0
  int v27; // w10
  int v28; // w8
  int v29; // w26
  __int64 v30; // x9
  __int64 v31; // x12
  unsigned int v32; // w0
  __int64 v33; // x11

  v2 = *(_QWORD *)(a2 + 2536);
  if ( v2 )
  {
    if ( *(_DWORD *)(a2 + 2544) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_irq", v4, v4 / 0x3E8);
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
  v5 = raw_spin_lock_irqsave(a2 + 21244);
  v6 = readl_relaxed((unsigned int *)(*(_QWORD *)a2 + 1552LL));
  readl_relaxed((unsigned int *)(*(_QWORD *)a2 + 1556LL));
  v7 = readl_relaxed((unsigned int *)(*(_QWORD *)a2 + 2052LL));
  v8 = readl_relaxed((unsigned int *)(*(_QWORD *)a2 + 3136LL));
  v9 = readl_relaxed((unsigned int *)(*(_QWORD *)a2 + 3392LL));
  v10 = readl_relaxed((unsigned int *)(*(_QWORD *)a2 + 600LL));
  v11 = v10;
  if ( (v6 & 0x3E2E) != 0 || (v9 & 0x7E0) != 0 )
  {
    geni_i3c_handle_err(a2, v6);
    if ( v11 )
      goto LABEL_31;
    goto LABEL_12;
  }
  if ( !v10 )
  {
    if ( (v6 & 0xC000000) != 0 && *(_DWORD *)(a2 + 21272) == 1 && *(_QWORD *)(a2 + 21264) )
    {
      if ( (v7 & 0x1FFFFFF) == 0 )
        goto LABEL_31;
      v12 = (v7 & 0x1FFFFFF) - 1;
      while ( 1 )
      {
        v13 = v12;
        v14 = readl_relaxed((unsigned int *)(*(_QWORD *)a2 + 1920LL));
        v15 = *(_DWORD *)(a2 + 21280);
        v16 = *(_DWORD *)(a2 + 21276);
        if ( v15 >= v16 )
          break;
        v17 = *(_QWORD *)(a2 + 21264);
        *(_DWORD *)(a2 + 21280) = v15 + 1;
        *(_BYTE *)(v17 + v15) = v14;
        v18 = *(_DWORD *)(a2 + 21280);
        v19 = *(_DWORD *)(a2 + 21276);
        if ( v18 >= v19 )
          goto LABEL_24;
        v20 = *(_QWORD *)(a2 + 21264);
        *(_DWORD *)(a2 + 21280) = v18 + 1;
        *(_BYTE *)(v20 + v18) = BYTE1(v14);
        v15 = *(_DWORD *)(a2 + 21280);
        v16 = *(_DWORD *)(a2 + 21276);
        if ( v15 >= v16 )
          break;
        v21 = *(_QWORD *)(a2 + 21264);
        *(_DWORD *)(a2 + 21280) = v15 + 1;
        *(_BYTE *)(v21 + v15) = BYTE2(v14);
        v18 = *(_DWORD *)(a2 + 21280);
        v19 = *(_DWORD *)(a2 + 21276);
        if ( v18 >= v19 )
        {
LABEL_24:
          if ( v18 == v19 )
            goto LABEL_31;
        }
        else
        {
          v22 = *(_QWORD *)(a2 + 21264);
          *(_DWORD *)(a2 + 21280) = v18 + 1;
          *(_BYTE *)(v22 + v18) = HIBYTE(v14);
          if ( *(_DWORD *)(a2 + 21280) == *(_DWORD *)(a2 + 21276) )
            goto LABEL_31;
        }
LABEL_27:
        v12 = v13 - 1;
        if ( !v13 )
          goto LABEL_31;
      }
      if ( v15 == v16 )
        goto LABEL_31;
      goto LABEL_27;
    }
    if ( (v6 & 0x40000000) == 0 || *(_DWORD *)(a2 + 21272) || !*(_QWORD *)(a2 + 21264) || !*(_DWORD *)(a2 + 96) )
      goto LABEL_31;
    v27 = *(_DWORD *)(a2 + 21276);
    v28 = *(_DWORD *)(a2 + 21280);
    v29 = 0;
    while ( 1 )
    {
      if ( v28 >= v27 )
      {
        v32 = 0;
      }
      else
      {
        v30 = *(_QWORD *)(a2 + 21264);
        v31 = v28 + 1LL;
        *(_DWORD *)(a2 + 21280) = v31;
        v32 = *(unsigned __int8 *)(v30 + v28);
        if ( v31 < v27 )
        {
          *(_DWORD *)(a2 + 21280) = v28 + 2;
          v32 |= *(unsigned __int8 *)(v30 + v31) << 8;
          if ( v28 + 2LL < v27 )
          {
            v33 = v28 + 3LL;
            *(_DWORD *)(a2 + 21280) = v33;
            v32 |= *(unsigned __int8 *)(v30 + v28 + 2LL) << 16;
            if ( v33 < v27 )
            {
              *(_DWORD *)(a2 + 21280) = v28 + 4;
              v32 |= *(unsigned __int8 *)(v30 + v33) << 24;
            }
          }
        }
      }
      writel_relaxed(v32, (unsigned int *)(*(_QWORD *)a2 + 1792LL));
      v28 = *(_DWORD *)(a2 + 21280);
      v27 = *(_DWORD *)(a2 + 21276);
      if ( v28 == v27 )
        break;
      if ( (unsigned int)++v29 >= *(_DWORD *)(a2 + 96) )
        goto LABEL_31;
    }
LABEL_12:
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)a2 + 2060LL));
    goto LABEL_31;
  }
  ipc_log_string(*(_QWORD *)(a2 + 2528), "i3c dma tx:0x%x, dma rx:0x%x\n", v8, v9);
  if ( *(_QWORD *)(a2 + 8) )
    i3c_trace_log();
LABEL_31:
  if ( v6 )
    writel_relaxed(v6, (unsigned int *)(*(_QWORD *)a2 + 1560LL));
  if ( v11 )
  {
    if ( v8 )
      writel_relaxed(v8, (unsigned int *)(*(_QWORD *)a2 + 3140LL));
    if ( v9 )
      writel_relaxed(v9, (unsigned int *)(*(_QWORD *)a2 + 3396LL));
  }
  if ( (v6 & 0x21) != 0 )
  {
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)a2 + 2060LL));
LABEL_45:
    complete(a2 + 2552);
    goto LABEL_46;
  }
  if ( (v8 & 1) != 0 || (v8 & 8) != 0 || (v9 & 9) != 0 )
  {
    ipc_log_string(*(_QWORD *)(a2 + 2528), "%s: DMA mode xfer completed\n", "geni_i3c_irq");
    if ( *(_QWORD *)(a2 + 8) )
      i3c_trace_log();
    goto LABEL_45;
  }
LABEL_46:
  v23 = raw_spin_unlock_irqrestore(a2 + 21244, v5);
  v24 = *(_QWORD *)(a2 + 2536);
  if ( v24 && v4 && *(_DWORD *)(a2 + 2544) )
  {
    v25 = sched_clock(v23);
    ipc_log_string(v24, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_irq", v25 - v4, (v25 - v4) / 0x3E8);
  }
  return 1;
}
