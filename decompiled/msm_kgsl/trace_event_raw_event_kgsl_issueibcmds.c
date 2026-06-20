__int64 __fastcall trace_event_raw_event_kgsl_issueibcmds(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v14; // x8
  const char *v15; // x26
  int v16; // w27
  __int64 result; // x0
  __int64 v18; // x25
  int v19; // w8
  size_t v20; // x27
  _DWORD *v21; // x28
  __int64 v22; // x26
  _QWORD v23[7]; // [xsp+8h] [xbp-38h] BYREF

  v23[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 72);
  memset(v23, 0, 48);
  if ( (v14 & 0x2C0) == 0
    || (v14 & 0x100) != 0
    || (v22 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v22, (result & 1) == 0) )
  {
    if ( *(_QWORD *)(a2 + 8) )
      v15 = *(const char **)(a2 + 8);
    else
      v15 = "(null)";
    v16 = strlen(v15) + 1;
    result = trace_event_buffer_reserve(v23);
    if ( result )
    {
      v18 = result + 36;
      v19 = (v16 << 16) | 0x24;
      v20 = (unsigned __int16)v16 - 1LL;
      v21 = (_DWORD *)result;
      *(_DWORD *)(result + 8) = v19;
      memcpy((void *)(result + 36), v15, v20);
      *(_BYTE *)(v18 + v20) = 0;
      v21[3] = a3;
      v21[4] = a4;
      v21[5] = a5;
      v21[6] = a6;
      v21[7] = a7;
      v21[8] = a8;
      result = trace_event_buffer_commit(v23);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
