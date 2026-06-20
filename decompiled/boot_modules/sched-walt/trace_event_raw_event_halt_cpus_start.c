__int64 __fastcall trace_event_raw_event_halt_cpus_start(__int64 a1, __int64 *a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 result; // x0
  __int64 v8; // x8
  int v9; // w9
  int v10; // w10
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v5 = a1;
  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v5 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12, v5, 24);
    if ( result )
    {
      v8 = *a2;
      v9 = _cpu_halt_mask[0];
      v10 = _cpu_partial_halt_mask[0];
      *(_BYTE *)(result + 20) = a3;
      *(_DWORD *)(result + 8) = v8;
      *(_DWORD *)(result + 12) = v9;
      *(_DWORD *)(result + 16) = v10;
      result = trace_event_buffer_commit(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
