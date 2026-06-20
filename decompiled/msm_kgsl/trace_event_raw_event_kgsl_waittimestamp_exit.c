__int64 __fastcall trace_event_raw_event_kgsl_waittimestamp_exit(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 v6; // x8
  const char *v7; // x22
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x21
  int v11; // w8
  size_t v12; // x23
  __int64 v13; // x24
  __int64 v14; // x22
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v6 & 0x2C0) == 0
    || (v6 & 0x100) != 0
    || (v14 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v14, (result & 1) == 0) )
  {
    if ( *(_QWORD *)(a2 + 8) )
      v7 = *(const char **)(a2 + 8);
    else
      v7 = "(null)";
    v8 = strlen(v7) + 1;
    result = trace_event_buffer_reserve(v15);
    if ( result )
    {
      v10 = result + 20;
      v11 = (v8 << 16) | 0x14;
      v12 = (unsigned __int16)v8 - 1LL;
      v13 = result;
      *(_DWORD *)(result + 8) = v11;
      memcpy((void *)(result + 20), v7, v12);
      *(_BYTE *)(v10 + v12) = 0;
      *(_DWORD *)(v13 + 12) = a3;
      *(_DWORD *)(v13 + 16) = a4;
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
