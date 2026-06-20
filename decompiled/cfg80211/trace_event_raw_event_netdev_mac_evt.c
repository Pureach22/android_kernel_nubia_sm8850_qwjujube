__int64 __fastcall trace_event_raw_event_netdev_mac_evt(__int64 a1, __int64 a2, int *a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  int v8; // w9
  _QWORD v9[7]; // [xsp+8h] [xbp-38h] BYREF

  v9[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v9, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v9);
    if ( result )
    {
      v7 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v7;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      if ( a3 )
      {
        v8 = *a3;
        *(_WORD *)(result + 32) = *((_WORD *)a3 + 2);
        *(_DWORD *)(result + 28) = v8;
      }
      else
      {
        *(_WORD *)(result + 32) = 0;
        *(_DWORD *)(result + 28) = 0;
      }
      result = trace_event_buffer_commit(v9);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
