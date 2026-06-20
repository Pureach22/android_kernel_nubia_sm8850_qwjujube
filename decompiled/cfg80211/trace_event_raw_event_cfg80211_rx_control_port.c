__int64 __fastcall trace_event_raw_event_cfg80211_rx_control_port(__int64 a1, __int64 a2, __int64 a3, char a4, int a5)
{
  __int64 v9; // x9
  __int64 result; // x0
  __int64 v11; // x8
  int v12; // w9
  unsigned int v13; // w9
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v14);
    if ( result )
    {
      v11 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v11;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      *(_DWORD *)(result + 28) = *(_DWORD *)(a3 + 112);
      if ( *(_QWORD *)(a3 + 216) + *(unsigned __int16 *)(a3 + 186) == -6 )
      {
        *(_WORD *)(result + 36) = 0;
        *(_DWORD *)(result + 32) = 0;
      }
      else
      {
        v12 = *(_DWORD *)(*(_QWORD *)(a3 + 216) + *(unsigned __int16 *)(a3 + 186) + 6LL);
        *(_WORD *)(result + 36) = *(_WORD *)(*(_QWORD *)(a3 + 216) + *(unsigned __int16 *)(a3 + 186) + 10LL);
        *(_DWORD *)(result + 32) = v12;
      }
      v13 = *(unsigned __int16 *)(a3 + 180);
      *(_BYTE *)(result + 40) = a4 & 1;
      *(_DWORD *)(result + 44) = a5;
      *(_WORD *)(result + 38) = bswap32(v13) >> 16;
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
