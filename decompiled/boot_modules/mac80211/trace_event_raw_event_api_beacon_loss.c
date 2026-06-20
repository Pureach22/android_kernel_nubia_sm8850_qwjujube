__int64 __fastcall trace_event_raw_event_api_beacon_loss(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  int v4; // w21
  __int64 result; // x0
  __int64 v6; // x20
  int v7; // w8
  size_t v8; // x21
  int v9; // w8
  _QWORD v10[7]; // [xsp+8h] [xbp-38h] BYREF

  v10[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v10, 0, 48);
  if ( (v3 & 0x2C0) == 0 || (v3 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v4 = strlen((const char *)(a2 + 1640)) + 1;
    result = trace_event_buffer_reserve(v10);
    if ( result )
    {
      v6 = result + 32;
      v7 = (v4 << 16) | 0x20;
      v8 = (unsigned __int16)v4 - 1LL;
      *(_DWORD *)(result + 28) = v7;
      v9 = *(_DWORD *)(a2 + 4720);
      *(_QWORD *)(result + 16) = a2;
      *(_DWORD *)(result + 8) = v9;
      *(_BYTE *)(result + 24) = *(_BYTE *)(a2 + 5848);
      memcpy((void *)(result + 32), (const void *)(a2 + 1640), v8);
      *(_BYTE *)(v6 + v8) = 0;
      result = trace_event_buffer_commit(v10);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
