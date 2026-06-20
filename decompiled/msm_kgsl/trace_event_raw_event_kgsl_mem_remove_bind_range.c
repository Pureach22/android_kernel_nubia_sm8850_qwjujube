__int64 __fastcall trace_event_raw_event_kgsl_mem_remove_bind_range(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v9; // x9
  __int64 result; // x0
  __int64 v11; // x8
  int v12; // w8
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v13, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v13);
    if ( result )
    {
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 32) + a3;
      v11 = *(_QWORD *)(*(_QWORD *)(a2 + 256) + 8LL);
      if ( v11 )
        LODWORD(v11) = *(_DWORD *)(v11 + 112);
      *(_DWORD *)(result + 20) = v11;
      *(_DWORD *)(result + 16) = *(_DWORD *)(a2 + 248);
      v12 = *(_DWORD *)(a4 + 248);
      *(_QWORD *)(result + 32) = a5;
      *(_DWORD *)(result + 24) = v12;
      result = trace_event_buffer_commit(v13);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
