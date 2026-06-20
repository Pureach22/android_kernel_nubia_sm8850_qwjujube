__int64 __fastcall trace_event_raw_event_kgsl_pwrstats(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _QWORD *a4,
        int a5,
        __int64 a6)
{
  __int64 v10; // x8
  const char *v11; // x24
  int v12; // w25
  __int64 result; // x0
  __int64 v14; // x23
  int v15; // w8
  size_t v16; // x25
  __int64 v17; // x26
  __int64 v18; // x8
  __int64 v19; // x24
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (v19 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v19, (result & 1) == 0) )
  {
    if ( *(_QWORD *)(a2 + 8) )
      v11 = *(const char **)(a2 + 8);
    else
      v11 = "(null)";
    v12 = strlen(v11) + 1;
    result = trace_event_buffer_reserve(v20);
    if ( result )
    {
      v14 = result + 64;
      v15 = (v12 << 16) | 0x40;
      v16 = (unsigned __int16)v12 - 1LL;
      v17 = result;
      *(_DWORD *)(result + 8) = v15;
      memcpy((void *)(result + 64), v11, v16);
      *(_BYTE *)(v14 + v16) = 0;
      *(_QWORD *)(v17 + 16) = a3;
      *(_QWORD *)(v17 + 24) = *a4;
      *(_QWORD *)(v17 + 32) = a4[1];
      v18 = a4[2];
      *(_DWORD *)(v17 + 48) = a5;
      *(_QWORD *)(v17 + 56) = a6;
      *(_QWORD *)(v17 + 40) = v18;
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
