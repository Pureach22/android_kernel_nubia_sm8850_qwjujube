__int64 __fastcall trace_event_raw_event_kgsl_mem_sync_cache(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x23
  __int64 v12; // x8
  int v13; // w8
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v14);
    if ( result )
    {
      v11 = result;
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 32);
      kgsl_get_memory_usage((char *)(result + 16), 0x10u, *(_QWORD *)(a2 + 80));
      v12 = *(_QWORD *)(*(_QWORD *)(a2 + 256) + 8LL);
      if ( v12 )
        LODWORD(v12) = *(_DWORD *)(v12 + 112);
      *(_DWORD *)(v11 + 32) = v12;
      v13 = *(_DWORD *)(a2 + 248);
      *(_QWORD *)(v11 + 48) = a3;
      *(_DWORD *)(v11 + 36) = v13;
      *(_DWORD *)(v11 + 40) = a5;
      if ( !a4 )
        a4 = *(_QWORD *)(a2 + 48);
      *(_QWORD *)(v11 + 56) = a4;
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
