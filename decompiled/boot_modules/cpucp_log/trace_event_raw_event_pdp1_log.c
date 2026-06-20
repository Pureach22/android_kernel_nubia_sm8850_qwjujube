__int64 __fastcall trace_event_raw_event_pdp1_log(__int64 a1, const char *a2)
{
  __int64 v3; // x8
  const char *v4; // x20
  int v5; // w21
  __int64 result; // x0
  __int64 v7; // x19
  int v8; // w8
  size_t v9; // x21
  const char *v10; // x20
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v11, 0, 48);
  if ( (v3 & 0x2C0) == 0
    || (v3 & 0x100) != 0
    || (v10 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v10, (result & 1) == 0) )
  {
    if ( a2 )
      v4 = a2;
    else
      v4 = "(null)";
    v5 = strlen(v4) + 1;
    result = trace_event_buffer_reserve(v11, a1, v5 + 12LL);
    if ( result )
    {
      v7 = result + 12;
      v8 = (v5 << 16) | 0xC;
      v9 = (unsigned __int16)v5 - 1LL;
      *(_DWORD *)(result + 8) = v8;
      memcpy((void *)(result + 12), v4, v9);
      *(_BYTE *)(v7 + v9) = 0;
      result = trace_event_buffer_commit(v11);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
