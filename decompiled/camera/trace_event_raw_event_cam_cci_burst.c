__int64 __fastcall trace_event_raw_event_cam_cci_burst(__int64 a1, int a2, int a3, int a4, const char *a5, int a6)
{
  __int64 v11; // x8
  const char *v12; // x24
  int v13; // w25
  __int64 result; // x0
  __int64 v15; // x22
  __int64 v16; // x20
  const char *v17; // x24
  _QWORD v18[7]; // [xsp+8h] [xbp-38h] BYREF

  v18[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 72);
  memset(v18, 0, 48);
  if ( (v11 & 0x2C0) == 0
    || (v11 & 0x100) != 0
    || (v17 = a5, result = _trace_trigger_soft_disabled(a1), a5 = v17, (result & 1) == 0) )
  {
    if ( a5 )
      v12 = a5;
    else
      v12 = "(null)";
    v13 = strlen(v12) + 1;
    result = trace_event_buffer_reserve(v18, a1, v13 + 28LL);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      v15 = result;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = (v13 << 16) | 0x1C;
      v16 = result + 28;
      memcpy((void *)(result + 28), v12, (unsigned __int16)v13 - 1LL);
      *(_BYTE *)(v16 + (unsigned __int16)v13 - 1LL) = 0;
      *(_DWORD *)(v15 + 24) = a6;
      result = trace_event_buffer_commit(v18);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
