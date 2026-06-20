__int64 __fastcall trace_event_raw_event_tlbsync_timeout(__int64 a1, const char **a2)
{
  __int64 v4; // x8
  const char *v5; // x21
  const char *v6; // x8
  const char *v7; // x0
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x19
  const char *v11; // x1
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v4 & 0x2C0) == 0 || (v4 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v5 = a2[14];
    v6 = v5;
    if ( !v5 )
      v6 = *a2;
    if ( v6 )
      v7 = v6;
    else
      v7 = "(null)";
    v8 = strlen(v7) + 1;
    if ( !v5 )
      v5 = *a2;
    result = trace_event_buffer_reserve(v12, a1, v8 + 12LL);
    if ( result )
    {
      v10 = result + 12;
      if ( v5 )
        v11 = v5;
      else
        v11 = "(null)";
      *(_DWORD *)(result + 8) = (v8 << 16) | 0xC;
      memcpy((void *)(result + 12), v11, (unsigned __int16)v8 - 1LL);
      *(_BYTE *)(v10 + (unsigned __int16)v8 - 1LL) = 0;
      result = trace_event_buffer_commit(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
