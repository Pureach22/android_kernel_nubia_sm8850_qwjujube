__int64 __fastcall trace_event_raw_event_hwmon_attr_class(__int64 a1, int a2, const char *a3, __int64 a4)
{
  __int64 v7; // x8
  const char *v8; // x22
  int v9; // w23
  __int64 result; // x0
  int v11; // w8
  size_t v12; // x21
  __int64 v13; // x23
  __int64 v14; // x20
  const char *v15; // x22
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v7 & 0x2C0) == 0
    || (v7 & 0x100) != 0
    || (v15 = a3, result = _trace_trigger_soft_disabled(a1), a3 = v15, (result & 1) == 0) )
  {
    if ( a3 )
      v8 = a3;
    else
      v8 = "(null)";
    v9 = strlen(v8) + 1;
    result = trace_event_buffer_reserve(v16, a1, v9 + 24LL);
    if ( result )
    {
      v11 = (v9 << 16) | 0x18;
      v12 = (unsigned __int16)v9 - 1LL;
      v13 = result;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = v11;
      v14 = result + 24;
      memcpy((void *)(result + 24), v8, v12);
      *(_BYTE *)(v14 + v12) = 0;
      *(_QWORD *)(v13 + 16) = a4;
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
