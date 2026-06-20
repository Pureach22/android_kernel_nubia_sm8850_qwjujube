__int64 __fastcall trace_event_raw_event_kgsl_clk(__int64 a1, __int64 a2, char a3, int a4)
{
  __int64 v6; // x8
  const char *v7; // x22
  int v8; // w23
  __int64 result; // x0
  char v10; // w24
  int v11; // w8
  __int64 v12; // x20
  size_t v13; // x21
  __int64 v14; // x23
  __int64 v15; // x22
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v6 & 0x2C0) == 0
    || (v6 & 0x100) != 0
    || (v15 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v15, (result & 1) == 0) )
  {
    if ( *(_QWORD *)(a2 + 8) )
      v7 = *(const char **)(a2 + 8);
    else
      v7 = "(null)";
    v8 = strlen(v7) + 1;
    result = trace_event_buffer_reserve(v16);
    if ( result )
    {
      v10 = a3 & 1;
      v11 = (v8 << 16) | 0x14;
      v12 = result + 20;
      v13 = (unsigned __int16)v8 - 1LL;
      v14 = result;
      *(_DWORD *)(result + 8) = v11;
      memcpy((void *)(result + 20), v7, v13);
      *(_BYTE *)(v12 + v13) = 0;
      *(_BYTE *)(v14 + 12) = v10;
      *(_DWORD *)(v14 + 16) = a4;
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
