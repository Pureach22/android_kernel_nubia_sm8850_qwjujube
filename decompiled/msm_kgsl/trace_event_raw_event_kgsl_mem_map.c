__int64 __fastcall trace_event_raw_event_kgsl_mem_map(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x20
  _QWORD v10[7]; // [xsp+8h] [xbp-38h] BYREF

  v10[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v10, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v10);
    if ( result )
    {
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 32);
      v7 = *(_QWORD *)(a2 + 48);
      *(_DWORD *)(result + 24) = a3;
      *(_QWORD *)(result + 16) = v7;
      *(_DWORD *)(result + 28) = (unsigned __int8)*(_DWORD *)(a2 + 80) >> 5;
      v8 = *(_QWORD *)(*(_QWORD *)(a2 + 256) + 8LL);
      if ( v8 )
        LODWORD(v8) = *(_DWORD *)(v8 + 112);
      *(_DWORD *)(result + 32) = v8;
      v9 = result;
      kgsl_get_memory_usage((char *)(result + 36), 0x10u, *(_QWORD *)(a2 + 80));
      *(_DWORD *)(v9 + 52) = *(_DWORD *)(a2 + 248);
      result = trace_event_buffer_commit(v10);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
