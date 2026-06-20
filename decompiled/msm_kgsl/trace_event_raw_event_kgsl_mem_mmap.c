__int64 __fastcall trace_event_raw_event_kgsl_mem_mmap(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x20
  _QWORD v8[7]; // [xsp+8h] [xbp-38h] BYREF

  v8[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v8, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v8);
    if ( result )
    {
      *(_QWORD *)(result + 8) = a3;
      v7 = result;
      *(_QWORD *)(result + 16) = *(_QWORD *)(a2 + 32);
      *(_QWORD *)(result + 24) = *(_QWORD *)(a2 + 48);
      kgsl_get_memory_usage((char *)(result + 32), 0x10u, *(_QWORD *)(a2 + 80));
      *(_DWORD *)(v7 + 48) = *(_DWORD *)(a2 + 248);
      *(_QWORD *)(v7 + 56) = *(_QWORD *)(a2 + 80);
      result = trace_event_buffer_commit(v8);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
