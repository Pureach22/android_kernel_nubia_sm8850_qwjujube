__int64 __fastcall tmc_enable_etr_sink(__int64 a1, int a2, __int64 a3)
{
  __int64 v4; // x19
  unsigned int v5; // w22
  __int64 aux; // x0
  __int64 v7; // x23
  __int64 v8; // x25
  int v9; // w8
  int v10; // w24
  unsigned int v11; // w0
  __int64 v12; // x0

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  if ( a2 == 2 )
  {
    aux = perf_get_aux(a3);
    if ( aux )
      v7 = *(_QWORD *)(aux + 48);
    else
      v7 = 0;
    raw_spin_lock_irqsave(v4 + 104);
    if ( (unsigned int)*(_QWORD *)(a1 + 968) == 1 )
      goto LABEL_13;
    if ( v7 )
    {
      v8 = *(_QWORD *)(v7 + 8);
      if ( v8 )
      {
        v9 = *(_DWORD *)(v4 + 108);
        v10 = *(_DWORD *)(v7 + 16);
        if ( v9 != -1 && v9 != v10 )
        {
LABEL_13:
          v5 = -16;
          goto LABEL_24;
        }
        if ( v9 == v10 )
        {
          v5 = 0;
          goto LABEL_17;
        }
        if ( *(_DWORD *)(v8 + 4) != 1 || (*(_BYTE *)(v4 + 204) & 1) != 0 )
        {
          if ( *(_QWORD *)(v4 + 120) )
          {
            __break(0x800u);
            v5 = -16;
            goto LABEL_24;
          }
          v5 = coresight_claim_device(*(_QWORD *)(v4 + 16));
          if ( v5 )
          {
LABEL_24:
            raw_spin_unlock_irqrestore(v4 + 104);
            return v5;
          }
          *(_QWORD *)(v4 + 120) = v8;
          v11 = _tmc_etr_enable_hw(v4);
          if ( v11 )
          {
            v5 = v11;
            v12 = *(_QWORD *)(v4 + 16);
            *(_QWORD *)(v4 + 120) = 0;
            coresight_disclaim_device(v12);
            goto LABEL_24;
          }
          *(_DWORD *)(v4 + 108) = v10;
          if ( ((unsigned int)*(_QWORD *)(a1 + 968) | 2) != 2 )
          {
            _warn_printk("Device already in use\n");
            __break(0x800u);
          }
          v5 = 0;
          *(_QWORD *)(a1 + 968) = 2;
          *(_QWORD *)(v4 + 296) = *(_QWORD *)(v7 + 8);
LABEL_17:
          ++*(_DWORD *)(a1 + 976);
          goto LABEL_24;
        }
      }
    }
    __break(0x800u);
    v5 = -22;
    goto LABEL_24;
  }
  if ( a2 == 1 )
  {
    mutex_lock(v4 + 152);
    v5 = tmc_enable_etr_sink_sysfs(a1);
    mutex_unlock(v4 + 152);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v5;
}
