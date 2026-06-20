__int64 __fastcall trace_event_raw_event_qcom_dcvs_update(
        __int64 a1,
        const char *a2,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v16; // x8
  const char *v17; // x26
  int v18; // w27
  __int64 result; // x0
  __int64 v20; // x25
  int v21; // w8
  __int64 v22; // x19
  size_t v23; // x27
  const char *v24; // x26
  _QWORD v25[7]; // [xsp+8h] [xbp-38h] BYREF

  v25[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 72);
  memset(v25, 0, 48);
  if ( (v16 & 0x2C0) == 0
    || (v16 & 0x100) != 0
    || (v24 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v24, (result & 1) == 0) )
  {
    if ( a2 )
      v17 = a2;
    else
      v17 = "(null)";
    v18 = strlen(v17) + 1;
    result = trace_event_buffer_reserve(v25, a1, v18 + 64LL);
    if ( result )
    {
      v20 = result + 64;
      v21 = (v18 << 16) | 0x40;
      v22 = result;
      v23 = (unsigned __int16)v18 - 1LL;
      *(_DWORD *)(result + 8) = v21;
      memcpy((void *)(result + 64), v17, v23);
      *(_BYTE *)(v20 + v23) = 0;
      *(_DWORD *)(v22 + 12) = a3;
      *(_DWORD *)(v22 + 16) = a4;
      *(_QWORD *)(v22 + 24) = a5;
      *(_QWORD *)(v22 + 32) = a6;
      *(_QWORD *)(v22 + 40) = a7;
      *(_QWORD *)(v22 + 48) = a8;
      *(_QWORD *)(v22 + 56) = a9;
      result = trace_event_buffer_commit(v25);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
