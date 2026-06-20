__int64 __fastcall trace_event_raw_event_kgsl_msg(__int64 a1, const char *a2)
{
  __int64 v2; // x8
  const char *v3; // x20
  int v4; // w21
  __int64 result; // x0
  __int64 v6; // x19
  int v7; // w8
  size_t v8; // x21
  const char *v9; // x20
  _QWORD v10[7]; // [xsp+8h] [xbp-38h] BYREF

  v10[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 72);
  memset(v10, 0, 48);
  if ( (v2 & 0x2C0) == 0
    || (v2 & 0x100) != 0
    || (v9 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v9, (result & 1) == 0) )
  {
    if ( a2 )
      v3 = a2;
    else
      v3 = "(null)";
    v4 = strlen(v3) + 1;
    result = trace_event_buffer_reserve(v10);
    if ( result )
    {
      v6 = result + 12;
      v7 = (v4 << 16) | 0xC;
      v8 = (unsigned __int16)v4 - 1LL;
      *(_DWORD *)(result + 8) = v7;
      memcpy((void *)(result + 12), v3, v8);
      *(_BYTE *)(v6 + v8) = 0;
      result = trace_event_buffer_commit(v10);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
