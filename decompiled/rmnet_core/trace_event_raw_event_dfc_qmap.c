__int64 __fastcall trace_event_raw_event_dfc_qmap(__int64 a1, const void *a2, size_t a3, char a4, char a5)
{
  __int64 v8; // x8
  __int64 v10; // x9
  __int64 result; // x0
  __int64 v12; // x22
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v8 = a1;
  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v8 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v14, v8, (int)a3 + 32LL);
    if ( result )
    {
      *(_QWORD *)(result + 16) = a3;
      *(_BYTE *)(result + 8) = a4 & 1;
      v12 = result;
      *(_DWORD *)(result + 24) = ((_DWORD)a3 << 16) | 0x1D;
      memcpy((void *)(result + 29), a2, a3);
      *(_BYTE *)(v12 + 28) = a5;
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
