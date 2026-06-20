__int64 safg_sau_update_tick_handler()
{
  __int64 result; // x0
  _QWORD *v1; // x9
  char *v2; // x10
  char *v3; // x12
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x1
  __int64 v6; // x11
  unsigned __int64 v7; // x12
  char *v8; // x10
  __int64 v9; // x14
  __int64 v10; // x10
  unsigned __int64 v11; // x2
  unsigned __int64 v12; // x3
  __int64 v13; // x5
  unsigned __int64 v14; // x12
  unsigned __int64 v15; // x4
  __int64 v16; // x11
  __int64 v17; // [xsp+0h] [xbp-10h]
  unsigned __int64 v18; // [xsp+8h] [xbp-8h]

  result = ktime_get();
  if ( safg_enable )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v5 = *(unsigned int *)(StatusReg + 40);
    if ( (unsigned int)v5 >= 0x20 )
    {
      __break(0x5512u);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v17 = v5;
        v18 = StatusReg;
        result = _traceiter_safg_update_sau_counter(0);
        v5 = v17;
        v3 = (char *)&sau_update_delta_time;
        v2 = (char *)&sau_delta;
        v1 = &_per_cpu_offset;
        v16 = *(_QWORD *)(v18 + 16) - 1LL;
        *(_DWORD *)(v18 + 16) = v16;
        if ( !v16 || !*(_QWORD *)(v18 + 16) )
        {
          result = preempt_schedule_notrace(result);
          v5 = v17;
          v3 = (char *)&sau_update_delta_time;
          v2 = (char *)&sau_delta;
          v1 = &_per_cpu_offset;
        }
      }
    }
    else
    {
      v1 = &_per_cpu_offset;
      if ( (unsigned __int64)(result - *(_QWORD *)((char *)&sau_last_update_time + *((_QWORD *)&_per_cpu_offset + v5))) < 0x7A1201 )
        return result;
      *(_QWORD *)((char *)&sau_cntr + *((_QWORD *)&_per_cpu_offset + v5)) = _ReadStatusReg(AMEVCNTR01_EL0);
      v2 = (char *)&sau_delta;
      *(_QWORD *)((char *)&sau_delta + *((_QWORD *)&_per_cpu_offset + v5)) = *(_QWORD *)((char *)&sau_cntr
                                                                                       + *((_QWORD *)&_per_cpu_offset
                                                                                         + v5))
                                                                           - *(_QWORD *)((char *)&sau_prev_cntr
                                                                                       + *((_QWORD *)&_per_cpu_offset
                                                                                         + v5));
      *(_QWORD *)((char *)&sau_prev_cntr + *((_QWORD *)&_per_cpu_offset + v5)) = *(_QWORD *)((char *)&sau_cntr
                                                                                           + *((_QWORD *)&_per_cpu_offset
                                                                                             + v5));
      *(_QWORD *)((char *)&sau_cntr + *((_QWORD *)&_per_cpu_offset + v5) + 8) = _ReadStatusReg(AMEVCNTR00_EL0);
      *(_QWORD *)((char *)&sau_delta + *((_QWORD *)&_per_cpu_offset + v5) + 8) = *(_QWORD *)((char *)&sau_cntr
                                                                                           + *((_QWORD *)&_per_cpu_offset
                                                                                             + v5)
                                                                                           + 8)
                                                                               - *(_QWORD *)((char *)&sau_prev_cntr
                                                                                           + *((_QWORD *)&_per_cpu_offset
                                                                                             + v5)
                                                                                           + 8);
      *(_QWORD *)((char *)&sau_prev_cntr + *((_QWORD *)&_per_cpu_offset + v5) + 8) = *(_QWORD *)((char *)&sau_cntr
                                                                                               + *((_QWORD *)&_per_cpu_offset
                                                                                                 + v5)
                                                                                               + 8);
      *(_QWORD *)((char *)&sau_cntr + *((_QWORD *)&_per_cpu_offset + v5) + 16) = _ReadStatusReg(AMEVCNTR02_EL0);
      *(_QWORD *)((char *)&sau_delta + *((_QWORD *)&_per_cpu_offset + v5) + 16) = *(_QWORD *)((char *)&sau_cntr
                                                                                            + *((_QWORD *)&_per_cpu_offset
                                                                                              + v5)
                                                                                            + 16)
                                                                                - *(_QWORD *)((char *)&sau_prev_cntr
                                                                                            + *((_QWORD *)&_per_cpu_offset
                                                                                              + v5)
                                                                                            + 16);
      *(_QWORD *)((char *)&sau_prev_cntr + *((_QWORD *)&_per_cpu_offset + v5) + 16) = *(_QWORD *)((char *)&sau_cntr
                                                                                                + *((_QWORD *)&_per_cpu_offset
                                                                                                  + v5)
                                                                                                + 16);
      *(_QWORD *)((char *)&sau_cntr + *((_QWORD *)&_per_cpu_offset + v5) + 24) = _ReadStatusReg(AMEVCNTR03_EL0);
      *(_QWORD *)((char *)&sau_delta + *((_QWORD *)&_per_cpu_offset + v5) + 24) = *(_QWORD *)((char *)&sau_cntr
                                                                                            + *((_QWORD *)&_per_cpu_offset
                                                                                              + v5)
                                                                                            + 24)
                                                                                - *(_QWORD *)((char *)&sau_prev_cntr
                                                                                            + *((_QWORD *)&_per_cpu_offset
                                                                                              + v5)
                                                                                            + 24);
      *(_QWORD *)((char *)&sau_prev_cntr + *((_QWORD *)&_per_cpu_offset + v5) + 24) = *(_QWORD *)((char *)&sau_cntr
                                                                                                + *((_QWORD *)&_per_cpu_offset
                                                                                                  + v5)
                                                                                                + 24);
      v3 = (char *)&sau_update_delta_time;
      *(_QWORD *)((char *)&sau_update_delta_time + *((_QWORD *)&_per_cpu_offset + v5)) = result
                                                                                       - *(_QWORD *)((char *)&sau_last_update_time + *((_QWORD *)&_per_cpu_offset + v5));
      *(_QWORD *)((char *)&sau_last_update_time + *((_QWORD *)&_per_cpu_offset + v5)) = result;
    }
    v6 = v1[v5];
    v7 = *(_QWORD *)&v3[v6];
    if ( !v7 )
    {
      *(_QWORD *)((char *)&sau_normal_util + v6) = 0;
      *(_QWORD *)((char *)&sau_stall_util + v1[v5]) = 0;
      return result;
    }
    v8 = &v2[v6];
    v9 = *((_QWORD *)v8 + 1);
    v10 = *((_QWORD *)v8 + 3);
    if ( v9 )
    {
      v11 = 1000000 * v9 / v7;
      if ( v10 )
      {
LABEL_8:
        v12 = 1000000 * v10 / v7;
LABEL_12:
        v13 = *(_QWORD *)((char *)&walt_rq + v6 + 632);
        v14 = *(unsigned int *)(*(_QWORD *)((char *)&walt_rq + v6 + 8) + 40LL);
        v15 = (unsigned int)(v14 % *(_QWORD *)((char *)&cpu_scale + v6) * v13 / *(_QWORD *)((char *)&cpu_scale + v6))
            + (unsigned int)(v14 / *(_QWORD *)((char *)&cpu_scale + v6)) * (_DWORD)v13;
        *(_QWORD *)((char *)&sau_normal_util + v6) = v13 * v11 / v15;
        *(_QWORD *)((char *)&sau_stall_util + v1[v5]) = v13 * v12 / v15;
        return result;
      }
    }
    else
    {
      v11 = 2000;
      if ( v10 )
        goto LABEL_8;
    }
    v12 = 0;
    goto LABEL_12;
  }
  return result;
}
