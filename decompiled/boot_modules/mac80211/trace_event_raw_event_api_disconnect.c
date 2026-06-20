__int64 __fastcall trace_event_raw_event_api_disconnect(__int64 a1, __int64 a2, char a3)
{
  __int64 v5; // x8
  int v6; // w22
  __int64 result; // x0
  __int64 v8; // x21
  int v9; // w8
  size_t v10; // x22
  const void *v11; // x1
  int v12; // w8
  __int64 v13; // x20
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v6 = strlen((const char *)(a2 + 1640)) + 1;
    result = trace_event_buffer_reserve(v14);
    if ( result )
    {
      v8 = result + 36;
      v9 = (v6 << 16) | 0x24;
      v10 = (unsigned __int16)v6 - 1LL;
      v11 = (const void *)(a2 + 1640);
      *(_DWORD *)(result + 28) = v9;
      v12 = *(_DWORD *)(a2 + 4720);
      *(_QWORD *)(result + 16) = a2;
      *(_DWORD *)(result + 8) = v12;
      LOBYTE(v12) = *(_BYTE *)(a2 + 5848);
      v13 = result;
      *(_BYTE *)(result + 24) = v12;
      memcpy((void *)(result + 36), v11, v10);
      *(_BYTE *)(v8 + v10) = 0;
      *(_DWORD *)(v13 + 32) = a3 & 1;
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
