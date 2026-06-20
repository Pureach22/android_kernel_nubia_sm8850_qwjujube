__int64 __fastcall trace_event_raw_event_dfc_flow_info(
        __int64 a1,
        const char *a2,
        char a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  __int64 v13; // x8
  const char *v14; // x25
  int v15; // w26
  __int64 result; // x0
  __int64 v17; // x24
  int v18; // w8
  size_t v19; // x26
  __int64 v20; // x27
  const char *v21; // x25
  _QWORD v22[7]; // [xsp+8h] [xbp-38h] BYREF

  v22[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 72);
  memset(v22, 0, 48);
  if ( (v13 & 0x2C0) == 0
    || (v13 & 0x100) != 0
    || (v21 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v21, (result & 1) == 0) )
  {
    if ( a2 )
      v14 = a2;
    else
      v14 = "(null)";
    v15 = strlen(v14) + 1;
    result = trace_event_buffer_reserve(v22, a1, v15 + 32LL);
    if ( result )
    {
      v17 = result + 32;
      v18 = (v15 << 16) | 0x20;
      v19 = (unsigned __int16)v15 - 1LL;
      v20 = result;
      *(_DWORD *)(result + 8) = v18;
      memcpy((void *)(result + 32), v14, v19);
      *(_BYTE *)(v17 + v19) = 0;
      *(_BYTE *)(v20 + 12) = a3;
      *(_DWORD *)(v20 + 16) = a4;
      *(_DWORD *)(v20 + 20) = a5;
      *(_DWORD *)(v20 + 24) = a6;
      *(_DWORD *)(v20 + 28) = a7;
      result = trace_event_buffer_commit(v22);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
