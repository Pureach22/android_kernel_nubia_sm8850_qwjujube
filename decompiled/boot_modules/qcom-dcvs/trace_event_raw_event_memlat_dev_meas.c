__int64 __fastcall trace_event_raw_event_memlat_dev_meas(
        __int64 a1,
        const char *a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  __int64 v17; // x8
  const char *v18; // x26
  int v19; // w27
  __int64 result; // x0
  __int64 v21; // x25
  __int64 v22; // x20
  size_t v23; // x27
  const char *v24; // x26
  _QWORD v25[7]; // [xsp+8h] [xbp-38h] BYREF

  v25[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a1 + 72);
  memset(v25, 0, 48);
  if ( (v17 & 0x2C0) == 0
    || (v17 & 0x100) != 0
    || (v24 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v24, (result & 1) == 0) )
  {
    if ( a2 )
      v18 = a2;
    else
      v18 = "(null)";
    v19 = strlen(v18) + 1;
    result = trace_event_buffer_reserve(v25, a1, v19 + 56LL);
    if ( result )
    {
      v21 = result + 56;
      v22 = result;
      *(_DWORD *)(result + 8) = (v19 << 16) | 0x38;
      v23 = (unsigned __int16)v19 - 1LL;
      memcpy((void *)(result + 56), v18, v23);
      *(_BYTE *)(v21 + v23) = 0;
      *(_DWORD *)(v22 + 12) = a3;
      *(_QWORD *)(v22 + 16) = a4;
      *(_QWORD *)(v22 + 24) = a5;
      *(_QWORD *)(v22 + 32) = a6;
      *(_DWORD *)(v22 + 40) = a7;
      *(_DWORD *)(v22 + 44) = a8;
      *(_DWORD *)(v22 + 48) = a9;
      *(_DWORD *)(v22 + 52) = a10;
      result = trace_event_buffer_commit(v25);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
