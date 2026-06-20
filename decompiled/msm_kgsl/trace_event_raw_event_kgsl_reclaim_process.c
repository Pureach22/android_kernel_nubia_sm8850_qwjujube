__int64 __fastcall trace_event_raw_event_kgsl_reclaim_process(__int64 a1, __int64 a2, int a3, char a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x9
  int v10; // w9
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v11, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v11);
    if ( result )
    {
      v9 = *(_QWORD *)(a2 + 8);
      if ( v9 )
        LODWORD(v9) = *(_DWORD *)(v9 + 112);
      *(_DWORD *)(result + 8) = v9;
      *(_DWORD *)(result + 12) = a3;
      v10 = *(_DWORD *)(a2 + 400);
      *(_BYTE *)(result + 20) = a4 & 1;
      *(_DWORD *)(result + 16) = v10;
      result = trace_event_buffer_commit(v11);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
