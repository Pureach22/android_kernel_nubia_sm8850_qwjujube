__int64 __fastcall trace_event_raw_event_adreno_drawctxt_switch(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  int v8; // w8
  _QWORD v9[7]; // [xsp+8h] [xbp-38h] BYREF

  v9[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v9, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v9);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 28);
      v7 = *(_QWORD *)(a2 + 176);
      if ( v7 )
        LODWORD(v7) = *(_DWORD *)(v7 + 4);
      *(_DWORD *)(result + 12) = v7;
      if ( a3 )
        v8 = *(_DWORD *)(a3 + 4);
      else
        v8 = 0;
      *(_DWORD *)(result + 16) = v8;
      result = trace_event_buffer_commit(v9);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
