__int64 __fastcall trace_event_raw_event_syncpoint_fence_template(__int64 a1, __int64 a2, const char *a3)
{
  __int64 v4; // x8
  const char *v5; // x21
  int v6; // w22
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x19
  const char *v10; // x21
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  memset(v11, 0, 48);
  if ( (v4 & 0x2C0) == 0
    || (v4 & 0x100) != 0
    || (v10 = a3, result = _trace_trigger_soft_disabled(a1), a3 = v10, (result & 1) == 0) )
  {
    if ( a3 )
      v5 = a3;
    else
      v5 = "(null)";
    v6 = strlen(v5) + 1;
    result = trace_event_buffer_reserve(v11);
    if ( result )
    {
      *(_DWORD *)(result + 8) = (v6 << 16) | 0x10;
      v8 = *(_QWORD *)(a2 + 8);
      v9 = result + 16;
      *(_DWORD *)(result + 12) = *(_DWORD *)(v8 + 4);
      memcpy((void *)(result + 16), v5, (unsigned __int16)v6 - 1LL);
      *(_BYTE *)(v9 + (unsigned __int16)v6 - 1LL) = 0;
      result = trace_event_buffer_commit(v11);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
