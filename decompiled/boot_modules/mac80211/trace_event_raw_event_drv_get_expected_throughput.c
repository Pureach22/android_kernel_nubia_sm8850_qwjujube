__int64 __fastcall trace_event_raw_event_drv_get_expected_throughput(__int64 a1, int *a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  int v5; // w9
  _QWORD v6[7]; // [xsp+8h] [xbp-38h] BYREF

  v6[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v6, 0, 48);
  if ( (v3 & 0x2C0) == 0 || (v3 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v6);
    if ( result )
    {
      if ( a2 )
      {
        v5 = *a2;
        *(_WORD *)(result + 12) = *((_WORD *)a2 + 2);
        *(_DWORD *)(result + 8) = v5;
      }
      else
      {
        *(_WORD *)(result + 12) = 0;
        *(_DWORD *)(result + 8) = 0;
      }
      result = trace_event_buffer_commit(v6);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
