__int64 __fastcall qcom_pmu_hotplug_coming_up(unsigned int a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x23
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v8; // x0
  unsigned __int64 v15; // x10
  unsigned __int64 v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = _kmalloc_cache_noprof(cpus_read_lock, 3520, 136);
  v3 = v2;
  if ( v2 )
  {
    v4 = *(_QWORD *)(v2 + 40);
    *(_DWORD *)(v2 + 4) = 136;
    *(_QWORD *)(v2 + 40) = v4 | 4;
  }
  if ( a1 >= 0x20 )
    goto LABEL_25;
  v5 = pmu_base;
  v6 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[a1]);
  v16[0] = 0;
  if ( v2 )
  {
    if ( qcom_pmu_inited != 1 )
    {
LABEL_32:
      kfree(v3);
      result = 0;
      goto LABEL_33;
    }
    if ( *(_DWORD *)(v6 + 328) )
    {
      if ( (set_event((unsigned int *)(v6 + 8), a1, v2) & 0x80000000) == 0 )
      {
        if ( *(_DWORD *)(v6 + 328) < 2u )
          goto LABEL_28;
        if ( (set_event((unsigned int *)(v6 + 48), a1, v3) & 0x80000000) == 0 )
        {
          if ( *(_DWORD *)(v6 + 328) < 3u )
            goto LABEL_28;
          if ( (set_event((unsigned int *)(v6 + 88), a1, v3) & 0x80000000) == 0 )
          {
            if ( *(_DWORD *)(v6 + 328) < 4u )
              goto LABEL_28;
            if ( (set_event((unsigned int *)(v6 + 128), a1, v3) & 0x80000000) == 0 )
            {
              if ( *(_DWORD *)(v6 + 328) < 5u )
                goto LABEL_28;
              if ( (set_event((unsigned int *)(v6 + 168), a1, v3) & 0x80000000) == 0 )
              {
                if ( *(_DWORD *)(v6 + 328) < 6u )
                  goto LABEL_28;
                if ( (set_event((unsigned int *)(v6 + 208), a1, v3) & 0x80000000) == 0 )
                {
                  if ( *(_DWORD *)(v6 + 328) < 7u )
                    goto LABEL_28;
                  if ( (set_event((unsigned int *)(v6 + 248), a1, v3) & 0x80000000) == 0 )
                  {
                    if ( *(_DWORD *)(v6 + 328) < 8u )
                      goto LABEL_28;
                    if ( (set_event((unsigned int *)(v6 + 288), a1, v3) & 0x80000000) == 0 )
                    {
                      if ( *(_DWORD *)(v6 + 328) < 9u )
                        goto LABEL_28;
                      if ( (set_event((unsigned int *)(v6 + 328), a1, v3) & 0x80000000) == 0 )
                      {
                        if ( *(_DWORD *)(v6 + 328) > 9u )
                        {
LABEL_25:
                          __break(0x5512u);
                          goto LABEL_26;
                        }
                        goto LABEL_28;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      printk(&unk_8E43);
    }
LABEL_28:
    v16[0] = 0;
    _X9 = v16;
    __asm { PRFM            #0x11, [X9,#0x10+var_10] }
    do
      v15 = __ldxr(v16);
    while ( __stxr(v15 | (1LL << a1), v16) );
    configure_cpucp_map(v16[0]);
    if ( pmu_base )
      writel_relaxed(0, (unsigned int *)(v5 + 40LL * a1 + 36));
    v8 = raw_spin_lock_irqsave(v6 + 336);
    *(_BYTE *)(v6 + 1) = 0;
    raw_spin_unlock_irqrestore(v6 + 336, v8);
    goto LABEL_32;
  }
LABEL_26:
  result = 4294967284LL;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
