__int64 __fastcall trace_event_raw_event_adreno_input_hw_fence(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        const char *a6)
{
  __int64 v10; // x8
  const char *v11; // x24
  int v12; // w25
  __int64 result; // x0
  __int64 v14; // x20
  const char *v15; // x24
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (v15 = a6, result = _trace_trigger_soft_disabled(a1), a6 = v15, (result & 1) == 0) )
  {
    if ( a6 )
      v11 = a6;
    else
      v11 = "(null)";
    v12 = strlen(v11) + 1;
    result = trace_event_buffer_reserve(v16);
    if ( result )
    {
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      v14 = result + 44;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 40) = (v12 << 16) | 0x2C;
      *(_QWORD *)(result + 32) = a5;
      memcpy((void *)(result + 44), v11, (unsigned __int16)v12 - 1LL);
      *(_BYTE *)(v14 + (unsigned __int16)v12 - 1LL) = 0;
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
