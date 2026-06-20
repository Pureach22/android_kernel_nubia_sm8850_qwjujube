__int64 __fastcall trace_event_raw_event_kgsl_pwr_template(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x8
  const char *v5; // x21
  int v6; // w22
  __int64 result; // x0
  char v8; // w23
  int v9; // w8
  __int64 v10; // x19
  size_t v11; // x20
  __int64 v12; // x22
  __int64 v13; // x21
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v4 & 0x2C0) == 0
    || (v4 & 0x100) != 0
    || (v13 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v13, (result & 1) == 0) )
  {
    if ( *(_QWORD *)(a2 + 8) )
      v5 = *(const char **)(a2 + 8);
    else
      v5 = "(null)";
    v6 = strlen(v5) + 1;
    result = trace_event_buffer_reserve(v14);
    if ( result )
    {
      v8 = a3 & 1;
      v9 = (v6 << 16) | 0xD;
      v10 = result + 13;
      v11 = (unsigned __int16)v6 - 1LL;
      v12 = result;
      *(_DWORD *)(result + 8) = v9;
      memcpy((void *)(result + 13), v5, v11);
      *(_BYTE *)(v10 + v11) = 0;
      *(_BYTE *)(v12 + 12) = v8;
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
