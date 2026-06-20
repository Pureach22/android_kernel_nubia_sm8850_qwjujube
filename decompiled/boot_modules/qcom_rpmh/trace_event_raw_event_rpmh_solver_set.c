__int64 __fastcall trace_event_raw_event_rpmh_solver_set(__int64 a1, const char *a2, char a3)
{
  __int64 v5; // x8
  const char *v6; // x21
  int v7; // w22
  __int64 result; // x0
  char v9; // w23
  int v10; // w8
  __int64 v11; // x19
  size_t v12; // x20
  __int64 v13; // x22
  const char *v14; // x21
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v5 & 0x2C0) == 0
    || (v5 & 0x100) != 0
    || (v14 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v14, (result & 1) == 0) )
  {
    if ( a2 )
      v6 = a2;
    else
      v6 = "(null)";
    v7 = strlen(v6) + 1;
    result = trace_event_buffer_reserve(v15, a1, v7 + 16LL);
    if ( result )
    {
      v9 = a3 & 1;
      v10 = (v7 << 16) | 0xD;
      v11 = result + 13;
      v12 = (unsigned __int16)v7 - 1LL;
      v13 = result;
      *(_DWORD *)(result + 8) = v10;
      memcpy((void *)(result + 13), v6, v12);
      *(_BYTE *)(v11 + v12) = 0;
      *(_BYTE *)(v13 + 12) = v9;
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
