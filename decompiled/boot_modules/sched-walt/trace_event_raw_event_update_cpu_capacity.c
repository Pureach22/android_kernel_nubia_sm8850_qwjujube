__int64 __fastcall trace_event_raw_event_update_cpu_capacity(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 result; // x0
  __int64 v10; // x9
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v7 = a1;
  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v8 & 0x2C0) == 0 || (v8 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v7 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12, v7, 64);
    if ( result )
    {
      if ( a2 >= 0x20 )
      {
        __break(0x5512u);
        JUMPOUT(0x3D508);
      }
      v10 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 8];
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = *(_QWORD *)((char *)&cpu_scale + *((_QWORD *)&_per_cpu_offset + a2));
      *(_QWORD *)(result + 40) = *(_QWORD *)((char *)&cpu_scale + *((_QWORD *)&_per_cpu_offset + a2))
                               - *(_QWORD *)((char *)&hw_pressure + *((_QWORD *)&_per_cpu_offset + a2));
      *(_QWORD *)(result + 56) = *(unsigned int *)(v10 + 44);
      *(_QWORD *)(result + 48) = *(unsigned int *)(v10 + 40);
      result = trace_event_buffer_commit(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
