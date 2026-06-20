__int64 __fastcall trace_event_raw_event_cma_alloc_start(__int64 a1, const char *a2, __int64 a3, int a4)
{
  __int64 v7; // x8
  const char *v8; // x22
  int v9; // w23
  __int64 result; // x0
  __int64 v11; // x21
  int v12; // w8
  size_t v13; // x23
  __int64 v14; // x24
  const char *v15; // x22
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v7 & 0x2C0) == 0
    || (v7 & 0x100) != 0
    || (v15 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v15, (result & 1) == 0) )
  {
    if ( a2 )
      v8 = a2;
    else
      v8 = "(null)";
    v9 = strlen(v8) + 1;
    result = trace_event_buffer_reserve(v16, a1, v9 + 32LL);
    if ( result )
    {
      v11 = result + 28;
      v12 = (v9 << 16) | 0x1C;
      v13 = (unsigned __int16)v9 - 1LL;
      v14 = result;
      *(_DWORD *)(result + 8) = v12;
      memcpy((void *)(result + 28), v8, v13);
      *(_BYTE *)(v11 + v13) = 0;
      *(_QWORD *)(v14 + 16) = a3;
      *(_DWORD *)(v14 + 24) = a4;
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
