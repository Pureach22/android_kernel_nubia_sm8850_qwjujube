__int64 __fastcall crm_write_pwr_states(__int64 a1, int a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x20
  int v7; // w0
  int v8; // w21
  __int64 v9; // x22
  __int64 v10; // x26
  __int64 v11; // x28
  unsigned int v12; // w8
  unsigned int v13; // w24
  unsigned int v14; // w9
  unsigned int i; // w25
  __int64 v16; // x8
  _DWORD *v17; // x9
  int v18; // w21
  __int64 v19; // x0
  __int64 v20; // x1

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 152);
    v3 = *(unsigned int *)(v2 + 48);
    if ( (int)v3 >= 1 )
    {
      v4 = 0;
      while ( 1 )
      {
        v5 = *(_QWORD *)(v2 + 40) + 192 * v4;
        if ( *(_DWORD *)(v5 + 32) == a2 )
          break;
        if ( ++v4 == v3 )
          return 4294967274LL;
      }
      if ( v5 && *(_DWORD *)v5 != 1 )
      {
        raw_spin_lock(v5 + 172);
        if ( *(_DWORD *)(v5 + 36) )
        {
          v7 = readl_relaxed(
                 *(_QWORD *)(v5 + 24)
               + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v5 + 40) + 4LL)
                              + *(_DWORD *)(*(_QWORD *)(v5 + 40) + 12LL) * *(_DWORD *)(v5 + 32)));
          if ( !v7 )
          {
            v8 = 0;
LABEL_16:
            v9 = 0;
            v10 = v5 + 48;
            _ReadStatusReg(SP_EL0);
            do
            {
              if ( (((unsigned __int64)*(unsigned int *)(*(_QWORD *)(v2 + 288) + 4LL) >> v9) & 1) != 0 )
              {
                v11 = v10 + 40 * v9;
                v12 = *(_DWORD *)(v11 + 12);
                if ( v12 )
                {
                  v13 = 0;
                  v14 = *(_DWORD *)(v11 + 8);
                  do
                  {
                    if ( v14 )
                    {
                      for ( i = 0; i < v14; ++i )
                      {
                        if ( i >= 5 )
                        {
                          __break(0x800u);
                          v16 = 3;
                        }
                        else
                        {
                          v16 = i + 3;
                        }
                        v17 = *(_DWORD **)(v10 + 40 * v9 + 16);
                        writel_relaxed(
                          *(unsigned int *)(*(_QWORD *)(*(_QWORD *)v11 + 8LL * (int)v13) + 4LL * (int)i),
                          *(_QWORD *)(v5 + 24)
                        + *v17
                        + v17[1] * *(_DWORD *)(v5 + 32)
                        + v17[v16]
                        + v17[8] * v8
                        + v17[2] * v13);
                        ipc_log_string(
                          *(_QWORD *)(v5 + 184),
                          "Flush: type: %u resource_idx:%u pwr_state: %u data: %#x",
                          v9,
                          v13,
                          i,
                          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v11 + 8LL * (int)v13) + 4LL * (int)i));
                        v14 = *(_DWORD *)(v11 + 8);
                      }
                      v12 = *(_DWORD *)(v11 + 12);
                    }
                    ++v13;
                  }
                  while ( v13 < v12 );
                }
              }
              ++v9;
            }
            while ( v9 != 3 );
            writel_relaxed(
              (unsigned int)(1 << v8),
              *(_QWORD *)(v5 + 24)
            + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v5 + 40) + 4LL)
                           + *(_DWORD *)(*(_QWORD *)(v5 + 40) + 12LL) * *(_DWORD *)(v5 + 32)));
            if ( *(_BYTE *)(v5 + 181) == 1 )
            {
              raw_spin_unlock(v5 + 172);
              return 0;
            }
            v18 = crm_channel_switch_complete(v5, v8);
            raw_spin_unlock(v5 + 172);
            if ( !v18 )
              return 0;
LABEL_34:
            crm_dump_drv_regs(v5, v2);
            v19 = crm_dump_regs(v2);
            __break(0x800u);
            return crm_dump_drv_regs(v19, v20);
          }
          if ( (v7 & 3) != 0 )
          {
            v8 = v7 & 1;
            goto LABEL_16;
          }
        }
        raw_spin_unlock(v5 + 172);
        goto LABEL_34;
      }
    }
  }
  return 4294967274LL;
}
