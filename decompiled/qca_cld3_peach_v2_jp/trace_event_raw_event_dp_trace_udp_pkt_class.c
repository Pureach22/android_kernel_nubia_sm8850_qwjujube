__int64 __fastcall trace_event_raw_event_dp_trace_udp_pkt_class(
        __int64 a1,
        __int64 a2,
        __int16 a3,
        __int16 a4,
        __int16 a5,
        __int64 a6,
        char a7)
{
  __int64 v10; // x8
  __int64 v14; // x9
  __int64 result; // x0
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v10 = a1;
  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v14 & 0x2C0) == 0
    || (v14 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v10 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v17, v10, 40);
    if ( result )
    {
      *(_QWORD *)(result + 8) = a2;
      *(_WORD *)(result + 16) = a3;
      *(_WORD *)(result + 18) = a4;
      *(_WORD *)(result + 20) = a5;
      *(_QWORD *)(result + 24) = a6;
      *(_BYTE *)(result + 32) = a7;
      result = trace_event_buffer_commit(v17);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
