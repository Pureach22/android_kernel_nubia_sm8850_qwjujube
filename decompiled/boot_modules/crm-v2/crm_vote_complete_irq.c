__int64 __fastcall crm_vote_complete_irq(int a1, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x11
  __int64 v4; // x26
  __int64 v5; // x22
  __int64 v6; // x20
  __int64 v7; // x25
  __int64 v8; // x27
  __int64 v9; // x23
  __int64 v10; // x19
  unsigned int v11; // w0
  __int64 v12; // x24
  __int64 v13; // x8
  __int64 v16; // [xsp+20h] [xbp-10h]

  v2 = *(_DWORD *)(a2 + 72);
  if ( v2 >= 1 )
  {
    v3 = 0;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v4 = *(_QWORD *)(a2 + 64) + 192 * v3;
      if ( (*(_BYTE *)(v4 + 180) & 1) != 0 || *(_DWORD *)(v4 + 176) == a1 )
        break;
LABEL_4:
      if ( ++v3 >= v2 )
        return 1;
    }
    v16 = v3;
    raw_spin_lock(v4 + 168);
    v5 = 0;
    v6 = v4 + 48;
    while ( 1 )
    {
      if ( (((unsigned __int64)*(unsigned int *)(*(_QWORD *)(a2 + 288) + 4LL) >> v5) & 1) != 0 )
      {
        v7 = v6 + 40 * v5;
        if ( v5 == 2 )
        {
          v8 = 1;
LABEL_13:
          v9 = 0;
          v10 = v6 + 40 * v5;
          do
          {
            v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(v4 + 24)
                                               + (unsigned int)(**(_DWORD **)(v10 + 16)
                                                              + *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4LL)
                                                              * *(_DWORD *)(v4 + 32)
                                                              + *(_DWORD *)(*(_QWORD *)(v10 + 16) + 36LL)
                                                              + *(_DWORD *)(*(_QWORD *)(v10 + 16) + 8LL) * v9)));
            if ( v11 )
            {
              v12 = v11;
              writel_relaxed(
                1u,
                (unsigned int *)(*(_QWORD *)(v4 + 24)
                               + (unsigned int)(**(_DWORD **)(v10 + 16)
                                              + *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4LL) * *(_DWORD *)(v4 + 32)
                                              + *(_DWORD *)(*(_QWORD *)(v10 + 16) + 40LL)
                                              + *(_DWORD *)(*(_QWORD *)(v10 + 16) + 8LL) * v9)));
              ipc_log_string(*(_QWORD *)(v4 + 184), "IRQ: type: %u resource_idx:%u irq_status: %lu", v5, v9, v12);
              v13 = *(_QWORD *)(v7 + 32) + 80 * v9;
              if ( (*(_BYTE *)(v13 + 48) & 1) != 0 )
              {
                if ( *(_BYTE *)(v13 + 12) == 1 )
                {
                  *(_BYTE *)(v13 + 48) = 0;
                  complete(v13 + 16);
                }
              }
              else
              {
                __break(0x800u);
              }
            }
            ++v9;
          }
          while ( v9 != v8 );
          goto LABEL_8;
        }
        v8 = *(unsigned int *)(v7 + 12);
        if ( (int)v8 >= 1 )
          goto LABEL_13;
      }
LABEL_8:
      if ( ++v5 == 3 )
      {
        raw_spin_unlock(v4 + 168);
        v3 = v16;
        v2 = *(_DWORD *)(a2 + 72);
        goto LABEL_4;
      }
    }
  }
  return 1;
}
