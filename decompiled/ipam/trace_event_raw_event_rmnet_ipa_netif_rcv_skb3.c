__int64 __fastcall trace_event_raw_event_rmnet_ipa_netif_rcv_skb3(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  const char *v6; // x22
  int v7; // w23
  __int64 result; // x0
  __int64 v9; // x21
  int v10; // w8
  size_t v11; // x23
  __int64 v12; // x24
  int v13; // w8
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    if ( *(_QWORD *)(a2 + 16) == -296 )
      v6 = "(null)";
    else
      v6 = (const char *)(*(_QWORD *)(a2 + 16) + 296LL);
    v7 = strlen(v6) + 1;
    result = trace_event_buffer_reserve(v14);
    if ( result )
    {
      v9 = result + 48;
      v10 = (v7 << 16) | 0x30;
      v11 = (unsigned __int16)v7 - 1LL;
      v12 = result;
      *(_DWORD *)(result + 8) = v10;
      memcpy((void *)(result + 48), v6, v11);
      *(_BYTE *)(v9 + v11) = 0;
      *(_QWORD *)(v12 + 16) = a2;
      *(_WORD *)(v12 + 24) = bswap32(*(unsigned __int16 *)(a2 + 180)) >> 16;
      *(_DWORD *)(v12 + 28) = *(_DWORD *)(a2 + 112);
      v13 = *(_DWORD *)(a2 + 116);
      *(_QWORD *)(v12 + 40) = a3;
      *(_DWORD *)(v12 + 32) = v13;
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
