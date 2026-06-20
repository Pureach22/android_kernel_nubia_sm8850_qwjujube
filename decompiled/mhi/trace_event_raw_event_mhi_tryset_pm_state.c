__int64 __fastcall trace_event_raw_event_mhi_tryset_pm_state(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x8
  const char *v6; // x21
  int v7; // w22
  __int64 result; // x0
  __int64 v9; // x20
  int v10; // w8
  size_t v11; // x22
  __int64 v12; // x23
  int v13; // w8
  __int64 v14; // x21
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v5 & 0x2C0) == 0
    || (v5 & 0x100) != 0
    || (v14 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v14, (result & 1) == 0) )
  {
    v6 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 8LL) ? *(const char **)(*(_QWORD *)(a2 + 16) + 8LL) : "(null)";
    v7 = strlen(v6) + 1;
    result = trace_event_buffer_reserve(v15, a1, v7 + 16LL);
    if ( result )
    {
      v9 = result + 16;
      v10 = (v7 << 16) | 0x10;
      v11 = (unsigned __int16)v7 - 1LL;
      v12 = result;
      *(_DWORD *)(result + 8) = v10;
      memcpy((void *)(result + 16), v6, v11);
      *(_BYTE *)(v9 + v11) = 0;
      v13 = 63 - __clz(a3);
      if ( !a3 )
        v13 = 0;
      *(_DWORD *)(v12 + 12) = v13;
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
