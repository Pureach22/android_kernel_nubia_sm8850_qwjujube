__int64 __fastcall trace_event_raw_event_bcm_voter_commit(__int64 a1, const char *a2, _DWORD *a3)
{
  __int64 v5; // x8
  const char *v6; // x21
  int v7; // w22
  __int64 result; // x0
  __int64 v9; // x20
  int v10; // w8
  size_t v11; // x22
  _DWORD *v12; // x23
  const char *v13; // x21
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v5 & 0x2C0) == 0
    || (v5 & 0x100) != 0
    || (v13 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v13, (result & 1) == 0) )
  {
    if ( a2 )
      v6 = a2;
    else
      v6 = "(null)";
    v7 = strlen(v6) + 1;
    result = trace_event_buffer_reserve(v14, a1, v7 + 24LL);
    if ( result )
    {
      v9 = result + 24;
      v10 = (v7 << 16) | 0x18;
      v11 = (unsigned __int16)v7 - 1LL;
      v12 = (_DWORD *)result;
      *(_DWORD *)(result + 8) = v10;
      memcpy((void *)(result + 24), v6, v11);
      *(_BYTE *)(v9 + v11) = 0;
      v12[3] = *a3;
      v12[4] = a3[1];
      v12[5] = a3[2];
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
