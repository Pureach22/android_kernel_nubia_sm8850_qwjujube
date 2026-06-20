__int64 __fastcall trace_event_raw_event_kgsl_pwrlevel(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v12; // x8
  const char *v13; // x25
  int v14; // w26
  __int64 result; // x0
  __int64 v16; // x24
  int v17; // w8
  size_t v18; // x26
  __int64 v19; // x27
  __int64 v20; // x25
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v12 & 0x2C0) == 0
    || (v12 & 0x100) != 0
    || (v20 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v20, (result & 1) == 0) )
  {
    if ( *(_QWORD *)(a2 + 8) )
      v13 = *(const char **)(a2 + 8);
    else
      v13 = "(null)";
    v14 = strlen(v13) + 1;
    result = trace_event_buffer_reserve(v21);
    if ( result )
    {
      v16 = result + 40;
      v17 = (v14 << 16) | 0x28;
      v18 = (unsigned __int16)v14 - 1LL;
      v19 = result;
      *(_DWORD *)(result + 8) = v17;
      memcpy((void *)(result + 40), v13, v18);
      *(_BYTE *)(v16 + v18) = 0;
      *(_DWORD *)(v19 + 12) = a3;
      *(_DWORD *)(v19 + 16) = a4;
      *(_DWORD *)(v19 + 20) = a5;
      *(_DWORD *)(v19 + 24) = a6;
      *(_QWORD *)(v19 + 32) = a7;
      result = trace_event_buffer_commit(v21);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
