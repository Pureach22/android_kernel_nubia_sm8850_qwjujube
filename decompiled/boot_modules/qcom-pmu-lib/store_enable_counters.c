__int64 __fastcall store_enable_counters(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 value; // x0
  char v8; // w8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x21
  __int64 v11; // x22
  unsigned __int64 v12; // x25
  char v13; // w19
  unsigned int *v14; // x27
  unsigned int v16; // w23
  __int64 v17; // x28
  __int64 v18; // x8
  __int64 v19; // x0
  unsigned __int64 v20; // x8
  __int64 v21; // [xsp+8h] [xbp-38h]
  __int64 v22; // [xsp+10h] [xbp-30h]
  __int64 v23; // [xsp+18h] [xbp-28h] BYREF
  __int64 v24; // [xsp+20h] [xbp-20h]
  __int64 v25; // [xsp+28h] [xbp-18h]
  __int64 v26; // [xsp+30h] [xbp-10h]
  __int64 v27; // [xsp+38h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (sysfs_streq(a3, "BEEFDEAD") & 1) == 0 )
  {
    value = sysfs_streq(a3, "DEADBEEF");
    if ( (value & 1) == 0 || qcom_pmu_inited != 1 || (pmu_counters_enabled & 1) != 0 )
      goto LABEL_8;
    v8 = 0;
    v21 = a4;
LABEL_13:
    v9 = (unsigned int)(-1LL << v8) & _cpu_possible_mask;
    if ( !(_DWORD)v9 )
    {
LABEL_44:
      delete_events(value);
      printk(&unk_9162);
      a4 = v21;
      pmu_counters_enabled = 1;
      goto LABEL_8;
    }
    v10 = __clz(__rbit64(v9));
    v11 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[v10]);
    if ( !*(_DWORD *)(v11 + 328) )
      goto LABEL_12;
    v12 = 0;
    v13 = 0;
    v22 = pmu_base + 40LL * (unsigned int)v10;
    while ( 2 )
    {
      v14 = (unsigned int *)(v11 + 44 + 40 * v12++);
      while ( 1 )
      {
        if ( v12 == 10 )
          goto LABEL_45;
        if ( *(v14 - 9) )
        {
          v16 = *(v14 - 1);
          v17 = *v14;
          if ( *(_QWORD *)(v14 - 7) || v16 <= 3 )
            break;
        }
LABEL_17:
        v14 += 10;
        if ( v12++ >= *(unsigned int *)(v11 + 328) )
        {
          if ( (v13 & 1) != 0 )
LABEL_11:
            value = writel_relaxed(1, v22 + 36);
LABEL_12:
          v8 = v10 + 1;
          if ( v10 >= 0x1F )
            goto LABEL_44;
          goto LABEL_13;
        }
      }
      v25 = 0;
      v26 = 0;
      v23 = 0;
      v24 = 0;
      if ( *(v14 - 1) > 3 )
      {
        value = *(_QWORD *)(v14 - 7);
        if ( value )
        {
          value = perf_event_read_value(value);
          goto LABEL_27;
        }
      }
      else
      {
        LODWORD(v23) = *(v14 - 1);
        value = smp_call_function_single(*(v14 - 5), read_amu_reg, &v23, 1);
        if ( (value & 0x80000000) == 0 )
        {
          value = v24;
LABEL_27:
          *(_QWORD *)(v14 - 3) = value;
        }
      }
      if ( pmu_base )
      {
        v18 = *v14;
        if ( (unsigned int)v18 <= 8 && cpucp_map[16 * v18] == 1 )
        {
          v19 = *(_QWORD *)(v14 - 3);
          if ( v16 >= 4 )
          {
            if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v14 - 7) + 152LL) + 328LL) < 6u )
            {
              if ( *(v14 - 9) == 17 )
                v19 |= 0xFFFFFFFF80000000LL;
              else
                v19 |= 0x80000000uLL;
            }
            else
            {
              v20 = 0xFFFFFFFF80000000LL;
              if ( pmu_long_counter )
                v20 = 0x8000000000000000LL;
              v19 |= v20;
            }
          }
          if ( (unsigned int)v17 >= 0xA )
LABEL_45:
            __break(0x5512u);
          value = writel_relaxed(v19, v22 + 4 * v17);
          v13 = 1;
          if ( v12 >= *(unsigned int *)(v11 + 328) )
            goto LABEL_11;
          continue;
        }
      }
      goto LABEL_17;
    }
  }
  if ( pmu_counters_enabled == 1 )
  {
    if ( (setup_events() & 0x80000000) != 0 )
    {
      printk(&unk_90B5);
    }
    else
    {
      configure_cpucp_map(_cpu_possible_mask);
      pmu_counters_enabled = 0;
      printk(&unk_8E9D);
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
