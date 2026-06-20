__int64 __fastcall trace_event_raw_event_api_gtk_rekey_notify(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v7; // x8
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x22
  int v11; // w8
  size_t v12; // x23
  const void *v13; // x1
  int v14; // w8
  __int64 v15; // x21
  __int16 v16; // w9
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v8 = strlen((const char *)(a2 + 1640)) + 1;
    result = trace_event_buffer_reserve(v17);
    if ( result )
    {
      v10 = result + 46;
      v11 = (v8 << 16) | 0x2E;
      v12 = (unsigned __int16)v8 - 1LL;
      v13 = (const void *)(a2 + 1640);
      *(_DWORD *)(result + 28) = v11;
      v14 = *(_DWORD *)(a2 + 4720);
      *(_QWORD *)(result + 16) = a2;
      *(_DWORD *)(result + 8) = v14;
      LOBYTE(v14) = *(_BYTE *)(a2 + 5848);
      v15 = result;
      *(_BYTE *)(result + 24) = v14;
      memcpy((void *)(result + 46), v13, v12);
      *(_BYTE *)(v10 + v12) = 0;
      v16 = *(_WORD *)(a3 + 4);
      *(_DWORD *)(v15 + 32) = *(_DWORD *)a3;
      *(_WORD *)(v15 + 36) = v16;
      *(_QWORD *)(v15 + 38) = *a4;
      result = trace_event_buffer_commit(v17);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
