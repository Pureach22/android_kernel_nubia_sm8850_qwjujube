__int64 __fastcall trace_event_raw_event_safg_update_sau_counter(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 result; // x0
  _QWORD v9[7]; // [xsp+8h] [xbp-38h] BYREF

  v5 = a1;
  v9[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v9, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v5 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v9, v5, 80);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      if ( a2 >= 0x20 )
      {
        __break(0x5512u);
        JUMPOUT(0x3F1CC);
      }
      *(_QWORD *)(result + 24) = *(_QWORD *)((char *)&sau_delta + *((_QWORD *)&_per_cpu_offset + a2));
      *(_QWORD *)(result + 32) = *(_QWORD *)((char *)&sau_delta + *((_QWORD *)&_per_cpu_offset + a2) + 8);
      *(_QWORD *)(result + 40) = *(_QWORD *)((char *)&sau_delta + *((_QWORD *)&_per_cpu_offset + a2) + 16);
      *(_QWORD *)(result + 48) = *(_QWORD *)((char *)&sau_delta + *((_QWORD *)&_per_cpu_offset + a2) + 24);
      *(_QWORD *)(result + 56) = *(_QWORD *)((char *)&sau_update_delta_time + *((_QWORD *)&_per_cpu_offset + a2));
      *(_QWORD *)(result + 64) = *(_QWORD *)((char *)&sau_normal_util + *((_QWORD *)&_per_cpu_offset + a2));
      *(_QWORD *)(result + 72) = *(_QWORD *)((char *)&sau_stall_util + *((_QWORD *)&_per_cpu_offset + a2));
      result = trace_event_buffer_commit(v9);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
