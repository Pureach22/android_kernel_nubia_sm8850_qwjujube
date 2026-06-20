void __fastcall ieee80211_dynamic_ps_enable_work(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x24
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // w9
  int v12; // w8

  v2 = *(_QWORD *)(a2 - 8);
  if ( v2 && (*(_BYTE *)(a2 - 5016) & 2) == 0 )
  {
    if ( *(int *)(a2 - 5008) >= 1 )
    {
      if ( (drv_tx_frames_pending(a2 - 5016) & 1) != 0 )
      {
LABEL_8:
        v6 = jiffies;
        v7 = _msecs_to_jiffies(*(unsigned int *)(a2 - 5008));
        mod_timer(a2 + 48, v7 + v6);
        return;
      }
      v4 = raw_spin_lock_irqsave(a2 - 3704);
      v5 = *(unsigned __int16 *)(a2 - 4888);
      if ( *(_WORD *)(a2 - 4888) )
      {
        if ( *(_QWORD *)(a2 - 4536) )
        {
LABEL_7:
          raw_spin_unlock_irqrestore(a2 - 3704, v4);
          goto LABEL_8;
        }
        if ( v5 != 1 )
        {
          if ( *(_QWORD *)(a2 - 4528) )
            goto LABEL_7;
          if ( v5 != 2 )
          {
            if ( *(_QWORD *)(a2 - 4520) )
              goto LABEL_7;
            if ( v5 != 3 )
            {
              if ( *(_QWORD *)(a2 - 4512) )
                goto LABEL_7;
              if ( v5 != 4 )
              {
                if ( *(_QWORD *)(a2 - 4504) )
                  goto LABEL_7;
                if ( v5 != 5 )
                {
                  if ( *(_QWORD *)(a2 - 4496) )
                    goto LABEL_7;
                  if ( v5 != 6 )
                  {
                    if ( *(_QWORD *)(a2 - 4488) )
                      goto LABEL_7;
                    if ( v5 != 7 )
                    {
                      if ( *(_QWORD *)(a2 - 4480) )
                        goto LABEL_7;
                      if ( v5 != 8 )
                      {
                        if ( *(_QWORD *)(a2 - 4472) )
                          goto LABEL_7;
                        if ( v5 != 9 )
                        {
                          if ( *(_QWORD *)(a2 - 4464) )
                            goto LABEL_7;
                          if ( v5 != 10 )
                          {
                            if ( *(_QWORD *)(a2 - 4456) )
                              goto LABEL_7;
                            if ( v5 != 11 )
                            {
                              if ( *(_QWORD *)(a2 - 4448) )
                                goto LABEL_7;
                              if ( v5 != 12 )
                              {
                                if ( *(_QWORD *)(a2 - 4440) )
                                  goto LABEL_7;
                                if ( v5 != 13 )
                                {
                                  if ( *(_QWORD *)(a2 - 4432) )
                                    goto LABEL_7;
                                  if ( v5 != 14 )
                                  {
                                    if ( *(_QWORD *)(a2 - 4424) )
                                      goto LABEL_7;
                                    if ( v5 != 15 )
                                    {
                                      if ( *(_QWORD *)(a2 - 4416) )
                                        goto LABEL_7;
                                      if ( v5 != 16 )
                                      {
                                        __break(0x5512u);
                                        drv_tx_frames_pending(v4);
                                        return;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      raw_spin_unlock_irqrestore(a2 - 3704, v4);
    }
    if ( (*(_QWORD *)(a2 - 4920) & 0x200) != 0 && (*(_BYTE *)(v2 + 2501) & 1) == 0 )
    {
      if ( (drv_tx_frames_pending(a2 - 5016) & 1) == 0 )
      {
        v10 = ((__int64 (__fastcall *)(__int64, __int64, __int64, bool))ieee80211_nullfunc_get)(
                a2 - 5016,
                v2 + 4720,
                0xFFFFFFFFLL,
                (*(_QWORD *)(a2 - 4920) & 0x10000000000LL) == 0);
        if ( v10 )
        {
          **(_WORD **)(v10 + 224) |= 0x1000u;
          v11 = *(_DWORD *)(v10 + 40);
          v12 = v11 | 0x12000;
          *(_DWORD *)(v10 + 40) = v11 | 0x12000;
          if ( (*(_QWORD *)(a2 - 4920) & 0x10000) != 0 )
          {
            v12 = v11 | 0x12001;
            *(_DWORD *)(v10 + 40) = v11 | 0x12001;
          }
          if ( (*(_BYTE *)(v2 + 2500) & 2) != 0 )
            *(_DWORD *)(v10 + 40) = v12 | 0x20000000;
          ieee80211_tx_skb_tid(v2, v10, 7, 0xFFFFFFFFLL);
        }
        ieee80211_flush_queues(a2 - 5016, v2, 0);
        if ( (*(_QWORD *)(a2 - 4920) & 0x10000) == 0 )
          goto LABEL_26;
LABEL_16:
        if ( (*(_QWORD *)(a2 - 4920) & 0x200) != 0 && (*(_BYTE *)(v2 + 2501) & 1) == 0 )
          return;
LABEL_26:
        *(_DWORD *)(v2 + 2500) &= ~0x100u;
        *(_DWORD *)(a2 - 5016) |= 2u;
        ieee80211_hw_config(a2 - 5016, 16);
        return;
      }
      v8 = jiffies;
      v9 = _msecs_to_jiffies(*(unsigned int *)(a2 - 5008));
      mod_timer(a2 + 48, v9 + v8);
    }
    if ( (*(_QWORD *)(a2 - 4920) & 0x10000) == 0 )
      goto LABEL_26;
    goto LABEL_16;
  }
}
