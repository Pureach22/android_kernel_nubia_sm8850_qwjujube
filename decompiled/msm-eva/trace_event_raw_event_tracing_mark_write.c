__int64 __fastcall trace_event_raw_event_tracing_mark_write(__int64 a1, char a2, __int64 a3, const char *a4, int a5)
{
  __int64 v9; // x8
  const char *v10; // x23
  int v11; // w24
  __int64 result; // x0
  int v13; // w8
  __int64 v14; // x20
  __int64 v15; // x22
  const char *v16; // x23
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v9 & 0x2C0) == 0
    || (v9 & 0x100) != 0
    || (v16 = a4, result = _trace_trigger_soft_disabled(a1), a4 = v16, (result & 1) == 0) )
  {
    v10 = a4 ? a4 : "(null)";
    v11 = strlen(v10) + 1;
    result = trace_event_buffer_reserve(v17, a1, v11 + 24LL);
    if ( result )
    {
      *(_BYTE *)(result + 8) = a2;
      *(_DWORD *)(result + 16) = (v11 << 16) | 0x18;
      if ( a3 )
        v13 = *(_DWORD *)(a3 + 1804);
      else
        v13 = 0;
      v14 = result + 24;
      *(_DWORD *)(result + 12) = v13;
      v15 = result;
      memcpy((void *)(result + 24), v10, (unsigned __int16)v11 - 1LL);
      *(_BYTE *)(v14 + (unsigned __int16)v11 - 1LL) = 0;
      *(_DWORD *)(v15 + 20) = a5;
      result = trace_event_buffer_commit(v17);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
