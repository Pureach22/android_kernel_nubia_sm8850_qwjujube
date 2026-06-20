__int64 __fastcall trace_event_raw_event_mhi_intvec_states(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 v8; // x8
  const char *v9; // x23
  int v10; // w24
  __int64 result; // x0
  __int64 v12; // x22
  int v13; // w8
  size_t v14; // x24
  _DWORD *v15; // x25
  int v16; // w8
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v8 & 0x2C0) == 0 || (v8 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    if ( *(_QWORD *)(*(_QWORD *)(a2 + 16) + 8LL) )
      v9 = *(const char **)(*(_QWORD *)(a2 + 16) + 8LL);
    else
      v9 = "(null)";
    v10 = strlen(v9) + 1;
    result = trace_event_buffer_reserve(v17, a1, v10 + 28LL);
    if ( result )
    {
      v12 = result + 28;
      v13 = (v10 << 16) | 0x1C;
      v14 = (unsigned __int16)v10 - 1LL;
      v15 = (_DWORD *)result;
      *(_DWORD *)(result + 8) = v13;
      memcpy((void *)(result + 28), v9, v14);
      *(_BYTE *)(v12 + v14) = 0;
      v15[3] = *(_DWORD *)(a2 + 344);
      v16 = *(_DWORD *)(a2 + 348);
      v15[6] = a4;
      v15[4] = v16;
      v15[5] = a3;
      result = trace_event_buffer_commit(v17);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
