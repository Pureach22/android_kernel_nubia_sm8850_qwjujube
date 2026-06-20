__int64 __fastcall trace_event_raw_event_handle_page_completion(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int16 a4,
        char a5,
        int a6)
{
  __int64 v11; // x9
  __int64 result; // x0
  __int64 v13; // x8
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v11 & 0x2C0) == 0 || (v11 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v14);
    if ( result )
    {
      *(_QWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      v13 = memstart_addr;
      *(_WORD *)(result + 24) = a4;
      *(_DWORD *)(result + 40) = a6;
      *(_BYTE *)(result + 26) = a5 & 1;
      *(_QWORD *)(result + 32) = (a2 - -64 * (v13 >> 12) + 0x140000000LL) >> 6;
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
