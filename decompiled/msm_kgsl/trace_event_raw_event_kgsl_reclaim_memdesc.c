__int64 __fastcall trace_event_raw_event_kgsl_reclaim_memdesc(__int64 a1, __int64 a2, char a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x9
  __int64 v8; // x9
  _QWORD v9[7]; // [xsp+8h] [xbp-38h] BYREF

  v9[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v9, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v9);
    if ( result )
    {
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 32);
      *(_QWORD *)(result + 16) = *(_QWORD *)(a2 + 48);
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 112);
      v7 = *(_QWORD *)(*(_QWORD *)(a2 + 256) + 8LL);
      if ( v7 )
        LODWORD(v7) = *(_DWORD *)(v7 + 112);
      *(_DWORD *)(result + 28) = v7;
      *(_DWORD *)(result + 32) = *(_DWORD *)(a2 + 248);
      v8 = *(_QWORD *)(a2 + 80);
      *(_BYTE *)(result + 48) = a3 & 1;
      *(_QWORD *)(result + 40) = v8;
      result = trace_event_buffer_commit(v9);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
