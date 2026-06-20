__int64 __fastcall trace_event_raw_event_rmnet_xmit_skb(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  const char *v5; // x21
  int v6; // w22
  __int64 result; // x0
  __int64 v8; // x20
  int v9; // w8
  size_t v10; // x22
  __int64 v11; // x23
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v4 & 0x2C0) == 0 || (v4 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    if ( *(_QWORD *)(a2 + 16) == -296 )
      v5 = "(null)";
    else
      v5 = (const char *)(*(_QWORD *)(a2 + 16) + 296LL);
    v6 = strlen(v5) + 1;
    result = trace_event_buffer_reserve(v12, a1, v6 + 16LL);
    if ( result )
    {
      v8 = result + 16;
      v9 = (v6 << 16) | 0x10;
      v10 = (unsigned __int16)v6 - 1LL;
      v11 = result;
      *(_DWORD *)(result + 8) = v9;
      memcpy((void *)(result + 16), v5, v10);
      *(_BYTE *)(v8 + v10) = 0;
      *(_DWORD *)(v11 + 12) = *(_DWORD *)(a2 + 112);
      result = trace_event_buffer_commit(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
