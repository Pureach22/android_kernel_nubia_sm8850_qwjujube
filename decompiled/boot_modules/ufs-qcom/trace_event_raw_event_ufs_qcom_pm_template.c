__int64 __fastcall trace_event_raw_event_ufs_qcom_pm_template(
        __int64 a1,
        const char *a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v15; // x8
  const char *v16; // x26
  int v17; // w27
  __int64 result; // x0
  __int64 v19; // x25
  int v20; // w8
  size_t v21; // x27
  _DWORD *v22; // x28
  const char *v23; // x26
  _QWORD v24[7]; // [xsp+8h] [xbp-38h] BYREF

  v24[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_QWORD *)(a1 + 72);
  memset(v24, 0, 48);
  if ( (v15 & 0x2C0) == 0
    || (v15 & 0x100) != 0
    || (v23 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v23, (result & 1) == 0) )
  {
    if ( a2 )
      v16 = a2;
    else
      v16 = "(null)";
    v17 = strlen(v16) + 1;
    result = trace_event_buffer_reserve(v24, a1, v17 + 36LL);
    if ( result )
    {
      v19 = result + 36;
      v20 = (v17 << 16) | 0x24;
      v21 = (unsigned __int16)v17 - 1LL;
      v22 = (_DWORD *)result;
      *(_DWORD *)(result + 8) = v20;
      memcpy((void *)(result + 36), v16, v21);
      *(_BYTE *)(v19 + v21) = 0;
      v22[3] = a3;
      v22[4] = a4;
      v22[5] = a5;
      v22[6] = a6;
      v22[7] = a7;
      v22[8] = a8;
      result = trace_event_buffer_commit(v24);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
