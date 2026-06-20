__int64 __fastcall get_cpu_total_instruction(__int64 a1, __int64 a2, __int64 a3)
{
  char v3; // w8
  __int64 v4; // x20
  __int64 v5; // x19
  unsigned __int64 v6; // x22
  unsigned __int64 v7; // x21
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x25
  __int64 v10; // x28
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x28
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x9
  __int64 result; // x0

  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  _ReadStatusReg(SP_EL0);
  do
  {
    v8 = (unsigned int)(-1LL << v3) & _cpu_possible_mask;
    if ( !(_DWORD)v8 )
      break;
    v9 = __clz(__rbit64(v8));
    v10 = *(_QWORD *)pmu_events + 32 * v9;
    mutex_lock(&perfevent_lock);
    if ( !*(_DWORD *)v10 )
      goto LABEL_11;
    if ( (cpu_is_hp[_per_cpu_offset[v9]] & 1) != 0 )
    {
      v11 = *(_QWORD *)(v10 + 24);
    }
    else
    {
      if ( (unsigned int)qcom_pmu_read((unsigned int)v9) )
        goto LABEL_11;
      v11 = 0;
    }
    v12 = v11 - *(_QWORD *)(v10 + 8);
    *(_QWORD *)(v10 + 8) = v11;
    *(_QWORD *)(v10 + 16) = v12;
LABEL_11:
    mutex_unlock(&perfevent_lock);
    v13 = *(_QWORD *)(pmu_events + 8) + 32 * v9;
    mutex_lock(&perfevent_lock);
    if ( *(_DWORD *)v13 )
    {
      if ( (cpu_is_hp[_per_cpu_offset[v9]] & 1) != 0 )
      {
        v14 = *(_QWORD *)(v13 + 24);
LABEL_16:
        v15 = v14 - *(_QWORD *)(v13 + 8);
        *(_QWORD *)(v13 + 8) = v14;
        *(_QWORD *)(v13 + 16) = v15;
        goto LABEL_17;
      }
      if ( !(unsigned int)qcom_pmu_read((unsigned int)v9) )
      {
        v14 = 0;
        goto LABEL_16;
      }
    }
LABEL_17:
    mutex_unlock(&perfevent_lock);
    v16 = *(_QWORD *)(*(_QWORD *)pmu_events + 32 * v9 + 16);
    v17 = *(_QWORD *)(*(_QWORD *)(pmu_events + 8) + 32 * v9 + 16);
    if ( *(_QWORD *)((char *)&cpu_scale + _per_cpu_offset[v9]) <= (unsigned __int64)min_cpu_capacity )
    {
      if ( v17 )
      {
        v19 = 100 * v16 / v17;
        if ( v7 <= v19 )
          v7 = v19;
      }
      v5 += v16;
    }
    else
    {
      if ( v17 >= 0x9EB10 )
      {
        v18 = 100 * v16 / v17;
        if ( v6 <= v18 )
          v6 = v18;
      }
      v4 += v16;
    }
    v3 = v9 + 1;
  }
  while ( v9 < 0x1F );
  LODWORD(result) = scnprintf(a3, 4096, "%llu:%llu:%llu:%llu\n", v4, v6, v5, v7);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
