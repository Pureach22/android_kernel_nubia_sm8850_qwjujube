__int64 __fastcall trace_event_raw_event_mhi_update_channel_state(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5)
{
  __int64 v9; // x8
  const char *v10; // x23
  int v11; // w24
  __int64 result; // x0
  __int64 v13; // x22
  int v14; // w8
  size_t v15; // x24
  __int64 v16; // x25
  int v17; // w8
  __int64 v18; // x23
  _QWORD v19[7]; // [xsp+8h] [xbp-38h] BYREF

  v19[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v19, 0, 48);
  if ( (v9 & 0x2C0) == 0
    || (v9 & 0x100) != 0
    || (v18 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v18, (result & 1) == 0) )
  {
    if ( *(_QWORD *)(*(_QWORD *)(a2 + 16) + 8LL) )
      v10 = *(const char **)(*(_QWORD *)(a2 + 16) + 8LL);
    else
      v10 = "(null)";
    v11 = strlen(v10) + 1;
    result = trace_event_buffer_reserve(v19, a1, v11 + 32LL);
    if ( result )
    {
      v13 = result + 32;
      v14 = (v11 << 16) | 0x20;
      v15 = (unsigned __int16)v11 - 1LL;
      v16 = result;
      *(_DWORD *)(result + 8) = v14;
      memcpy((void *)(result + 32), v10, v15);
      *(_BYTE *)(v13 + v15) = 0;
      v17 = *(_DWORD *)(a3 + 200);
      *(_QWORD *)(v16 + 24) = a5;
      *(_DWORD *)(v16 + 12) = v17;
      *(_DWORD *)(v16 + 16) = a4;
      result = trace_event_buffer_commit(v19);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
