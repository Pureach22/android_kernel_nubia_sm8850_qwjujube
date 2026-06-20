__int64 __fastcall trace_event_raw_event_dfc_tx_link_status_ind(__int64 a1, int a2, int a3, char a4, char a5, char a6)
{
  __int64 v9; // x8
  __int64 v12; // x9
  __int64 result; // x0
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v9 = a1;
  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v12 & 0x2C0) == 0
    || (v12 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v9 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v15, v9, 20);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_BYTE *)(result + 16) = a4;
      *(_BYTE *)(result + 17) = a5;
      *(_BYTE *)(result + 18) = a6;
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
