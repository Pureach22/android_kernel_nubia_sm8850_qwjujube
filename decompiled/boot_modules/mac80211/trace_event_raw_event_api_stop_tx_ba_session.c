__int64 __fastcall trace_event_raw_event_api_stop_tx_ba_session(__int64 a1, int *a2, __int16 a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  int v7; // w9
  _QWORD v8[7]; // [xsp+8h] [xbp-38h] BYREF

  v8[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v8, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v8);
    if ( result )
    {
      if ( a2 )
      {
        v7 = *a2;
        *(_WORD *)(result + 12) = *((_WORD *)a2 + 2);
        *(_DWORD *)(result + 8) = v7;
      }
      else
      {
        *(_WORD *)(result + 12) = 0;
        *(_DWORD *)(result + 8) = 0;
      }
      *(_WORD *)(result + 14) = a3;
      result = trace_event_buffer_commit(v8);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
