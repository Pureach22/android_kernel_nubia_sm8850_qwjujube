__int64 __fastcall trace_event_raw_event_clk_reset(__int64 a1, int **a2, __int64 a3, char a4)
{
  __int64 v8; // x8
  const char **v9; // x26
  const char *v10; // x23
  const char *v11; // x8
  const char *v12; // x0
  int v13; // w25
  __int64 result; // x0
  char v15; // w26
  __int64 v16; // x21
  const char *v17; // x1
  __int64 v18; // x23
  int v19; // w8
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v8 & 0x2C0) == 0 || (v8 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v9 = (const char **)a2[14];
    v10 = v9[14];
    v11 = v10;
    if ( !v10 )
      v11 = *v9;
    if ( v11 )
      v12 = v11;
    else
      v12 = "(null)";
    v13 = strlen(v12) + 1;
    if ( !v10 )
      v10 = *v9;
    result = trace_event_buffer_reserve(v20, a1, v13 + 32LL);
    if ( result )
    {
      v15 = a4 & 1;
      v16 = result + 25;
      if ( v10 )
        v17 = v10;
      else
        v17 = "(null)";
      v18 = result;
      *(_DWORD *)(result + 8) = (v13 << 16) | 0x19;
      memcpy((void *)(result + 25), v17, (unsigned __int16)v13 - 1LL);
      *(_BYTE *)(v16 + (unsigned __int16)v13 - 1LL) = 0;
      v19 = **a2;
      *(_QWORD *)(v18 + 16) = a3;
      *(_BYTE *)(v18 + 24) = v15;
      *(_DWORD *)(v18 + 12) = v19;
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
