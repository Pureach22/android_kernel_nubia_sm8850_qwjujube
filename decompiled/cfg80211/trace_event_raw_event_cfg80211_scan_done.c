__int64 __fastcall trace_event_raw_event_cfg80211_scan_done(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  int v6; // w22
  __int64 result; // x0
  __int64 v8; // x21
  int v9; // w9
  __int64 v10; // x8
  __int64 v11; // x8
  __int16 v12; // w9
  int v13; // w8
  int v14; // w9
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v6 = a2 ? *(_DWORD *)(a2 + 24) : 0;
    result = trace_event_buffer_reserve(v15);
    if ( result )
    {
      v8 = result;
      *(_DWORD *)(result + 12) = (v6 << 16) | 0x46;
      if ( a2 )
      {
        memcpy((void *)(result + *(unsigned __int16 *)(result + 12)), *(const void **)(a2 + 16), *(_QWORD *)(a2 + 24));
        v9 = *(_DWORD *)(a2 + 40);
        *(_WORD *)(v8 + 20) = *(_WORD *)(a2 + 44);
        *(_DWORD *)(v8 + 16) = v9;
        v10 = *(_QWORD *)(a2 + 64);
        if ( v10 )
          LODWORD(v10) = *(_DWORD *)(v10 + 40);
        *(_DWORD *)(v8 + 40) = v10;
        v11 = *(_QWORD *)(a2 + 96);
        if ( v11 )
        {
          v12 = *(_WORD *)(v11 + 52);
          v13 = *(_DWORD *)(v11 + 48);
          *(_WORD *)(v8 + 48) = v12;
          *(_DWORD *)(v8 + 44) = v13;
        }
        *(_BYTE *)(v8 + 50) = *(_BYTE *)(a2 + 129);
      }
      if ( a3 )
      {
        *(_BYTE *)(v8 + 51) = *(_BYTE *)(a3 + 14);
        *(_QWORD *)(v8 + 56) = *(_QWORD *)a3;
        v14 = *(_DWORD *)(a3 + 8);
        *(_WORD *)(v8 + 68) = *(_WORD *)(a3 + 12);
        *(_DWORD *)(v8 + 64) = v14;
      }
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
