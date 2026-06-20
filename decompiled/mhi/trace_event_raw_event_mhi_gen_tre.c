__int64 __fastcall trace_event_raw_event_mhi_gen_tre(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  const char *v8; // x22
  int v9; // w23
  __int64 result; // x0
  __int64 v11; // x21
  int v12; // w8
  size_t v13; // x23
  __int64 v14; // x24
  int v15; // w8
  __int64 v16; // x22
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v7 & 0x2C0) == 0
    || (v7 & 0x100) != 0
    || (v16 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v16, (result & 1) == 0) )
  {
    if ( *(_QWORD *)(*(_QWORD *)(a2 + 16) + 8LL) )
      v8 = *(const char **)(*(_QWORD *)(a2 + 16) + 8LL);
    else
      v8 = "(null)";
    v9 = strlen(v8) + 1;
    result = trace_event_buffer_reserve(v17, a1, v9 + 40LL);
    if ( result )
    {
      v11 = result + 40;
      v12 = (v9 << 16) | 0x28;
      v13 = (unsigned __int16)v9 - 1LL;
      v14 = result;
      *(_DWORD *)(result + 8) = v12;
      memcpy((void *)(result + 40), v8, v13);
      *(_BYTE *)(v11 + v13) = 0;
      v15 = *(_DWORD *)(a3 + 200);
      *(_QWORD *)(v14 + 16) = a4;
      *(_DWORD *)(v14 + 12) = v15;
      *(_QWORD *)(v14 + 24) = *(_QWORD *)a4;
      *(_DWORD *)(v14 + 32) = *(_DWORD *)(a4 + 8);
      *(_DWORD *)(v14 + 36) = *(_DWORD *)(a4 + 12);
      result = trace_event_buffer_commit(v17);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
