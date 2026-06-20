__int64 __fastcall trace_event_raw_event_kgsl_mem_alloc(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x20
  _QWORD v7[7]; // [xsp+8h] [xbp-38h] BYREF

  v7[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v7, 0, 48);
  if ( (v3 & 0x2C0) == 0 || (v3 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v7);
    if ( result )
    {
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 32);
      *(_QWORD *)(result + 16) = *(_QWORD *)(a2 + 48);
      v5 = *(_QWORD *)(*(_QWORD *)(a2 + 256) + 8LL);
      if ( v5 )
        LODWORD(v5) = *(_DWORD *)(v5 + 112);
      *(_DWORD *)(result + 24) = v5;
      v6 = result;
      kgsl_get_memory_usage((char *)(result + 28), 0x10u, *(_QWORD *)(a2 + 80));
      *(_DWORD *)(v6 + 44) = *(_DWORD *)(a2 + 248);
      *(_QWORD *)(v6 + 48) = *(_QWORD *)(a2 + 80);
      result = trace_event_buffer_commit(v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
