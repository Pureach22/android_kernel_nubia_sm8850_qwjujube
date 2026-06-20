__int64 __fastcall trace_event_raw_event_api_chswitch_done(__int64 a1, __int64 a2, char a3, int a4)
{
  __int64 v7; // x8
  int v8; // w23
  __int64 result; // x0
  char v10; // w24
  __int64 v11; // x21
  const void *v12; // x1
  int v13; // w8
  __int64 v14; // x20
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v8 = strlen((const char *)(a2 + 1640)) + 1;
    result = trace_event_buffer_reserve(v15);
    if ( result )
    {
      v10 = a3 & 1;
      v11 = result + 40;
      v12 = (const void *)(a2 + 1640);
      *(_DWORD *)(result + 28) = (v8 << 16) | 0x28;
      v13 = *(_DWORD *)(a2 + 4720);
      *(_QWORD *)(result + 16) = a2;
      *(_DWORD *)(result + 8) = v13;
      LOBYTE(v13) = *(_BYTE *)(a2 + 5848);
      v14 = result;
      *(_BYTE *)(result + 24) = v13;
      memcpy((void *)(result + 40), v12, (unsigned __int16)v8 - 1LL);
      *(_BYTE *)(v11 + (unsigned __int16)v8 - 1LL) = 0;
      *(_BYTE *)(v14 + 32) = v10;
      *(_DWORD *)(v14 + 36) = a4;
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
