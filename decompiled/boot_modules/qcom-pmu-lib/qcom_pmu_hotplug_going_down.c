__int64 __fastcall qcom_pmu_hotplug_going_down(unsigned int a1)
{
  __int64 v2; // x22
  __int64 v3; // x21
  __int64 v4; // x0
  unsigned __int64 v5; // x23
  char v6; // w26
  __int64 v7; // x22
  unsigned int *v8; // x24
  __int64 v9; // x27
  unsigned int v10; // w28
  __int64 v11; // x0
  __int64 value; // x0
  __int64 v13; // x8
  unsigned int v14; // w8
  __int64 v16; // [xsp+8h] [xbp-28h] BYREF
  __int64 v17; // [xsp+10h] [xbp-20h]
  __int64 v18; // [xsp+18h] [xbp-18h]
  __int64 v19; // [xsp+20h] [xbp-10h]
  __int64 v20; // [xsp+28h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 0x20 )
LABEL_34:
    __break(0x5512u);
  if ( qcom_pmu_inited == 1 )
  {
    v2 = pmu_base;
    v3 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[a1]);
    v4 = raw_spin_lock_irqsave(v3 + 336);
    *(_BYTE *)(v3 + 1) = 1;
    raw_spin_unlock_irqrestore(v3 + 336, v4);
    if ( *(int *)(v3 + 332) >= 1 )
    {
      do
        _const_udelay(42950);
      while ( *(int *)(v3 + 332) > 0 );
    }
    if ( *(_DWORD *)(v3 + 328) )
    {
      v5 = 0;
      v6 = 0;
      v7 = v2 + 40LL * a1;
      v8 = (unsigned int *)(v3 + 24);
      while ( 1 )
      {
        if ( v5 == 9 )
          goto LABEL_34;
        if ( !*(v8 - 4) )
          goto LABEL_7;
        v10 = v8[4];
        v9 = v8[5];
        v11 = *((_QWORD *)v8 - 1);
        if ( !v11 && v10 > 3 )
          goto LABEL_7;
        v19 = 0;
        v17 = 0;
        v18 = 0;
        v16 = 0;
        if ( v10 > 3 )
        {
          if ( v11 )
          {
            value = perf_event_read_value(v11);
            goto LABEL_18;
          }
        }
        else
        {
          LODWORD(v16) = v10;
          if ( (smp_call_function_single(*v8, read_amu_reg, &v16, 1) & 0x80000000) == 0 )
          {
            value = v17;
            goto LABEL_18;
          }
        }
        value = *((_QWORD *)v8 + 1);
LABEL_18:
        *((_QWORD *)v8 + 1) = value;
        if ( pmu_base )
        {
          v13 = v8[5];
          if ( (unsigned int)v13 <= 8 && cpucp_map[16 * v13] == 1 )
          {
            if ( v10 >= 4 )
            {
              if ( *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v8 - 1) + 152LL) + 328LL) < 6u )
              {
                LODWORD(value) = value | 0x80000000;
              }
              else
              {
                v14 = 0x80000000;
                if ( pmu_long_counter )
                  v14 = 0;
                LODWORD(value) = v14 | value;
              }
            }
            if ( (unsigned int)v9 > 9 )
              goto LABEL_34;
            writel_relaxed(value, (unsigned int *)(v7 + 4 * v9));
            v6 = 1;
          }
        }
        if ( *((_QWORD *)v8 - 1) )
        {
          perf_event_release_kernel();
          *((_QWORD *)v8 - 1) = 0;
        }
LABEL_7:
        ++v5;
        v8 += 10;
        if ( v5 >= *(unsigned int *)(v3 + 328) )
        {
          if ( (v6 & 1) != 0 )
            writel_relaxed(1u, (unsigned int *)(v7 + 36));
          break;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
