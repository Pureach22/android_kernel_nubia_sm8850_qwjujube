__int64 __fastcall trace_event_raw_event_ipa_tx_dp(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v6; // x8
  const char *v7; // x22
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x21
  int v11; // w8
  size_t v12; // x23
  __int64 v13; // x24
  int v14; // w8
  const char *v15; // x22
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v6 & 0x2C0) == 0
    || (v6 & 0x100) != 0
    || (v15 = a3, result = _trace_trigger_soft_disabled(a1), a3 = v15, (result & 1) == 0) )
  {
    if ( a3 )
      v7 = a3;
    else
      v7 = "(null)";
    v8 = strlen(v7) + 1;
    result = trace_event_buffer_reserve(v16);
    if ( result )
    {
      v10 = result + 48;
      v11 = (v8 << 16) | 0x30;
      v12 = (unsigned __int16)v8 - 1LL;
      v13 = result;
      *(_DWORD *)(result + 8) = v11;
      memcpy((void *)(result + 48), v7, v12);
      *(_BYTE *)(v10 + v12) = 0;
      *(_QWORD *)(v13 + 16) = a2;
      *(_WORD *)(v13 + 24) = bswap32(*(unsigned __int16 *)(a2 + 180)) >> 16;
      *(_DWORD *)(v13 + 28) = *(_DWORD *)(a2 + 112);
      v14 = *(_DWORD *)(a2 + 116);
      *(_QWORD *)(v13 + 40) = a4;
      *(_DWORD *)(v13 + 32) = v14;
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
