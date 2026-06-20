__int64 __fastcall geni_i3c_ibi_irq(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  int v4; // w22
  __int64 v5; // x23
  unsigned __int64 v6; // x20
  __int64 v7; // x21
  int v8; // w22
  unsigned int v9; // w22
  int v10; // w24
  unsigned int v11; // w22
  char v12; // w24
  unsigned int v13; // w28
  __int64 v14; // x24
  __int64 v15; // x25
  bool v16; // cc
  __int64 v17; // x26
  __int64 free_slot; // x0
  __int64 v19; // x27
  int v20; // w0
  __int64 v21; // x8
  int v22; // w0
  __int64 v23; // x8
  unsigned int v24; // w8
  __int64 v25; // x1
  __int64 v26; // x2
  __int64 v27; // x3
  __int64 v28; // x0
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x3
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x21
  __int64 v35; // x0
  unsigned int v37; // [xsp+1Ch] [xbp-4h]

  v2 = *(_QWORD *)(a2 + 2536);
  v4 = a1;
  v5 = a2 + 20480;
  if ( v2 )
  {
    if ( *(_DWORD *)(a2 + 2544) )
    {
      v6 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_ibi_irq", v6, v6 / 0x3E8);
    }
    else
    {
      v6 = 0;
    }
  }
  else
  {
    v6 = -22;
  }
  v7 = raw_spin_lock_irqsave(a2 + 21352);
  if ( *(_DWORD *)(v5 + 876) != v4 )
  {
    if ( *(_DWORD *)(v5 + 912) != v4 )
      goto LABEL_56;
    v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 21328) + 4100LL));
    ipc_log_string(*(_QWORD *)(a2 + 2528), "IBI GPII IRQ, IBI_IRQ_STATUS:0x%x\n", v11);
    if ( *(_QWORD *)(a2 + 8) )
      i3c_trace_log();
    v12 = v11;
    if ( (v11 & 0x3F001ELL) != 0 )
      *(_DWORD *)(v5 + 960) = v11;
    if ( (v11 & 0x100) != 0 )
    {
      v37 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 21328) + 4112LL));
      if ( v37 )
      {
        v13 = v37;
        v14 = 0;
        v15 = 6148;
        do
        {
          if ( (v13 & 1) != 0 )
          {
            v17 = *(_QWORD *)(*(_QWORD *)(a2 + 21344) + 8 * v14);
            if ( v17 && *(_QWORD *)(v17 + 104) )
            {
              free_slot = i3c_generic_ibi_get_free_slot(*(_QWORD *)(*(_QWORD *)(v17 + 24) + 8LL));
              if ( free_slot )
              {
                v19 = free_slot;
                v20 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 21328) + v15));
                v21 = *(_QWORD *)(a2 + 21328);
                *(_DWORD *)(v5 + 968) = v20;
                v22 = readl_relaxed((unsigned int *)(v21 + v15 + 36));
                v23 = *(_QWORD *)(a2 + 21328);
                *(_DWORD *)(v5 + 972) = v22;
                *(_DWORD *)(v5 + 976) = readl_relaxed((unsigned int *)(v23 + v15 + 4));
                if ( *(_QWORD *)(v19 + 48) )
                  memcpy(
                    *(void **)(v19 + 48),
                    (const void *)(v5 + 976),
                    *(unsigned int *)(*(_QWORD *)(v17 + 104) + 36LL));
                v24 = (*(_DWORD *)(v5 + 968) >> 8) & 7;
                if ( v24 >= *(_DWORD *)(*(_QWORD *)(v17 + 104) + 36LL) )
                  v24 = *(_DWORD *)(*(_QWORD *)(v17 + 104) + 36LL);
                *(_DWORD *)(v19 + 40) = v24;
                ipc_log_string(
                  *(_QWORD *)(a2 + 2528),
                  "IBI: info: 0x%x, ts: 0x%x, Data: 0x%x slot_id: 0x%x\n",
                  *(unsigned int *)(v5 + 968),
                  *(unsigned int *)(v5 + 972),
                  *(unsigned int *)(v5 + 976),
                  (unsigned int)v14);
                if ( *(_QWORD *)(a2 + 8) )
                  i3c_trace_log();
                i3c_master_queue_ibi(v17, v19);
                goto LABEL_27;
              }
              ipc_log_string(*(_QWORD *)(a2 + 2528), "no free slot\n");
              v32 = *(_QWORD *)(a2 + 8);
              if ( v32 )
                dev_err(v32, "no free slot\n");
              else
                printk(&unk_1488E, v29, v30, v31);
              if ( *(_QWORD *)(a2 + 8) )
                goto LABEL_48;
            }
            else
            {
              ipc_log_string(*(_QWORD *)(a2 + 2528), "Invalid IBI device\n");
              v28 = *(_QWORD *)(a2 + 8);
              if ( !v28 )
              {
                printk(&unk_14878, v25, v26, v27);
                if ( !*(_QWORD *)(a2 + 8) )
                  goto LABEL_27;
LABEL_48:
                i3c_trace_log();
                goto LABEL_27;
              }
              dev_err(v28, "Invalid IBI device\n");
              if ( *(_QWORD *)(a2 + 8) )
                goto LABEL_48;
            }
          }
LABEL_27:
          v16 = v13 > 1;
          ++v14;
          v15 += 128;
          v13 >>= 1;
        }
        while ( v16 );
      }
      writel_relaxed(v37, (unsigned int *)(*(_QWORD *)(a2 + 21328) + 4116LL));
      v12 = v11;
    }
    if ( v11 )
    {
      writel_relaxed(v11, (unsigned int *)(*(_QWORD *)(a2 + 21328) + 4108LL));
      if ( (v12 & 1) == 0 )
        goto LABEL_56;
      goto LABEL_55;
    }
    v10 = v12 & 1;
    goto LABEL_54;
  }
  v8 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 21328) + 20LL));
  v9 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 21328) + 16LL)) & v8;
  ipc_log_string(*(_QWORD *)(a2 + 2528), "IBI MGR IRQ IBI_GEN_IRQ_STATUS:0x%x\n", v9);
  if ( *(_QWORD *)(a2 + 8) )
    i3c_trace_log();
  if ( (v9 & 0x12) != 0 )
    *(_DWORD *)(v5 + 960) = v9;
  v10 = (v9 & 9) != 0;
  if ( (v9 & 4) != 0 )
  {
    if ( *(_BYTE *)(v5 + 1161) == 1 )
      *(_BYTE *)(v5 + 1171) = 1;
    queue_work_on(32, *(_QWORD *)(a2 + 21488), a2 + 21496);
  }
  if ( v9 )
  {
    writel_relaxed(v9, (unsigned int *)(*(_QWORD *)(a2 + 21328) + 24LL));
    if ( (v9 & 9) == 0 )
      goto LABEL_56;
    goto LABEL_55;
  }
LABEL_54:
  if ( v10 )
LABEL_55:
    complete(a2 + 21360);
LABEL_56:
  v33 = raw_spin_unlock_irqrestore(a2 + 21352, v7);
  v34 = *(_QWORD *)(a2 + 2536);
  if ( v34 && v6 && *(_DWORD *)(a2 + 2544) )
  {
    v35 = sched_clock(v33);
    ipc_log_string(v34, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_ibi_irq", v35 - v6, (v35 - v6) / 0x3E8);
  }
  return 1;
}
