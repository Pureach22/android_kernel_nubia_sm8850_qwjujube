__int64 __fastcall trace_event_raw_event_cam_context_state(__int64 a1, const char *a2, __int64 a3)
{
  __int64 v5; // x8
  const char *v6; // x21
  int v7; // w22
  __int64 result; // x0
  int v9; // w8
  __int64 v10; // x19
  const char *v11; // x21
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v5 & 0x2C0) == 0
    || (v5 & 0x100) != 0
    || (v11 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v11, (result & 1) == 0) )
  {
    if ( a2 )
      v6 = a2;
    else
      v6 = "(null)";
    v7 = strlen(v6) + 1;
    result = trace_event_buffer_reserve(v12, a1, v7 + 24LL);
    if ( result )
    {
      *(_QWORD *)(result + 8) = a3;
      *(_DWORD *)(result + 20) = (v7 << 16) | 0x18;
      v9 = *(_DWORD *)(a3 + 240);
      v10 = result + 24;
      *(_DWORD *)(result + 16) = v9;
      memcpy((void *)(result + 24), v6, (unsigned __int16)v7 - 1LL);
      *(_BYTE *)(v10 + (unsigned __int16)v7 - 1LL) = 0;
      result = trace_event_buffer_commit(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
