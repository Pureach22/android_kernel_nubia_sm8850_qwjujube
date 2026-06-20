__int64 __fastcall tmc_enable_etf_sink(__int64 a1, int a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v5; // x21
  unsigned int v6; // w23
  __int64 v8; // x20
  __int64 aux; // x0
  __int64 v10; // x23
  int v11; // w0
  unsigned int v12; // w19
  __int64 result; // x0
  __int64 v14; // x24
  int v15; // w8
  int v16; // w23
  unsigned int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x8
  unsigned __int64 v20; // x9

  if ( a2 == 2 )
  {
    v8 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
    aux = perf_get_aux(a3);
    if ( !aux )
      return 4294967274LL;
    v10 = *(_QWORD *)(aux + 48);
    if ( !v10 )
      return 4294967274LL;
    raw_spin_lock_irqsave(v8 + 104);
    if ( *(_BYTE *)(v8 + 408) == 1 && (*(_BYTE *)(v8 + 112) & 1) == 0 )
    {
      if ( (unsigned int)*(_QWORD *)(a1 + 968) == 1
        || (v15 = *(_DWORD *)(v8 + 108), v16 = *(_DWORD *)(v10 + 8), v15 != -1) && v15 != v16 )
      {
        v11 = -16;
        goto LABEL_11;
      }
      v18 = perf_get_aux(a3);
      if ( v18 )
      {
        v19 = *(_QWORD *)(v18 + 48);
        if ( v19 )
        {
          v20 = (((unsigned __int64)*(unsigned int *)(v19 + 4) << 12) - 1) & *(_QWORD *)(a3 + 40);
          *(_QWORD *)(v19 + 16) = *(_QWORD *)(a3 + 40) & 0xFFFLL;
          *(_DWORD *)v19 = v20 >> 12;
          *(_QWORD *)(v19 + 24) = 0;
          if ( *(_DWORD *)(v8 + 108) != v16 )
          {
            v11 = tmc_etb_enable_hw(v8);
            if ( v11 )
              goto LABEL_11;
            *(_DWORD *)(v8 + 108) = v16;
            if ( ((unsigned int)*(_QWORD *)(a1 + 968) | 2) != 2 )
            {
              _warn_printk("Device already in use\n");
              __break(0x800u);
            }
            *(_QWORD *)(a1 + 968) = 2;
          }
          v11 = 0;
          ++*(_DWORD *)(a1 + 976);
          goto LABEL_11;
        }
      }
    }
    v11 = -22;
LABEL_11:
    v12 = v11;
    raw_spin_unlock_irqrestore(v8 + 104);
    return v12;
  }
  if ( a2 != 1 )
    return 4294967274LL;
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v4 + 104);
  if ( *(_QWORD *)(v4 + 120) )
  {
    v5 = 0;
    if ( (*(_BYTE *)(v4 + 112) & 1) != 0 )
    {
LABEL_5:
      v6 = -16;
LABEL_29:
      raw_spin_unlock_irqrestore(v4 + 104);
LABEL_30:
      kfree(v5);
      return v6;
    }
  }
  else
  {
    raw_spin_unlock_irqrestore(v4 + 104);
    v5 = _kmalloc_noprof(*(unsigned int *)(v4 + 132), 3520);
    if ( !v5 )
      return 4294967284LL;
    raw_spin_lock_irqsave(v4 + 104);
    if ( (*(_BYTE *)(v4 + 112) & 1) != 0 )
      goto LABEL_5;
  }
  if ( *(_BYTE *)(v4 + 408) != 1 )
  {
    v6 = -22;
    goto LABEL_29;
  }
  if ( (unsigned int)*(_QWORD *)(a1 + 968) == 1 )
  {
    v6 = 0;
    ++*(_DWORD *)(a1 + 976);
    goto LABEL_29;
  }
  v14 = *(_QWORD *)(v4 + 120);
  if ( v14 )
    memset(*(void **)(v4 + 120), 0, *(unsigned int *)(v4 + 132));
  else
    *(_QWORD *)(v4 + 120) = v5;
  v6 = coresight_claim_device(*(_QWORD *)(v4 + 16));
  if ( v6 )
    goto LABEL_29;
  v17 = _tmc_etb_enable_hw(v4);
  if ( v17 )
  {
    v6 = v17;
    coresight_disclaim_device(*(_QWORD *)(v4 + 16));
    goto LABEL_29;
  }
  if ( (*(_QWORD *)(a1 + 968) & 0xFFFFFFFELL) != 0 )
  {
    _warn_printk("Device already in use\n");
    __break(0x800u);
  }
  *(_QWORD *)(a1 + 968) = 1;
  ++*(_DWORD *)(a1 + 976);
  raw_spin_unlock_irqrestore(v4 + 104);
  v6 = 0;
  result = 0;
  if ( v14 )
    goto LABEL_30;
  return result;
}
