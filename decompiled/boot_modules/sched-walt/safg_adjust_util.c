__int64 __fastcall safg_adjust_util(__int64 result, __int64 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x2
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x8
  __int64 v6; // x3
  __int64 v7; // x4
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x10
  __int64 v10; // x9
  unsigned __int64 StatusReg; // x19
  __int64 v12; // x8

  if ( safg_enable )
  {
    if ( (unsigned int)result >= 0x20 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        result = _traceiter_safg_sau_adjust_util(0, (unsigned int)result);
        v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v12;
        if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
          return preempt_schedule_notrace(result);
      }
    }
    else
    {
      v2 = *((_QWORD *)&_per_cpu_offset + (unsigned int)result);
      v3 = *a2;
      v4 = *(_QWORD *)((char *)&sau_normal_util + v2);
      v5 = *(_QWORD *)((char *)&sau_stall_util + v2);
      if ( v4 >= 0x400 )
        v6 = 1024;
      else
        v6 = v4;
      if ( v5 >= 0x400 )
        v7 = 1024;
      else
        v7 = v5;
      v8 = v7 * safg_reduce_pct / 0x64uLL;
      v9 = v3 * safg_reduce_maxutil_pct / 0x64uLL;
      if ( v8 < v9 )
        v9 = v7 * safg_reduce_pct / 0x64uLL;
      if ( safg_policy > 3 )
      {
        if ( safg_policy == 4 )
        {
          v10 = (v3 - v9) & ~((__int64)(v3 - v9) >> 63);
        }
        else
        {
          if ( safg_policy != 5 )
            return result;
          v10 = (v6 - v8) & ~((__int64)(v6 - v8) >> 63);
        }
      }
      else if ( safg_policy == 1 )
      {
        if ( v6 <= v3 )
          v10 = *a2;
        else
          v10 = v6;
      }
      else
      {
        v10 = v6;
        if ( safg_policy != 3 )
          return result;
      }
      *a2 = v10;
    }
  }
  return result;
}
