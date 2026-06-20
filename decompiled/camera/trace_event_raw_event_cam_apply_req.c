__int64 __fastcall trace_event_raw_event_cam_apply_req(__int64 a1, const char *a2, int a3, __int64 a4, int a5)
{
  __int64 v9; // x8
  const char *v10; // x23
  int v11; // w24
  __int64 result; // x0
  __int64 v13; // x22
  int v14; // w8
  size_t v15; // x24
  __int64 v16; // x25
  const char *v17; // x23
  _QWORD v18[7]; // [xsp+8h] [xbp-38h] BYREF

  v18[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v18, 0, 48);
  if ( (v9 & 0x2C0) == 0
    || (v9 & 0x100) != 0
    || (v17 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v17, (result & 1) == 0) )
  {
    if ( a2 )
      v10 = a2;
    else
      v10 = "(null)";
    v11 = strlen(v10) + 1;
    result = trace_event_buffer_reserve(v18, a1, v11 + 32LL);
    if ( result )
    {
      v13 = result + 28;
      v14 = (v11 << 16) | 0x1C;
      v15 = (unsigned __int16)v11 - 1LL;
      v16 = result;
      *(_DWORD *)(result + 8) = v14;
      memcpy((void *)(result + 28), v10, v15);
      *(_BYTE *)(v13 + v15) = 0;
      *(_DWORD *)(v16 + 12) = a3;
      *(_QWORD *)(v16 + 16) = a4;
      *(_DWORD *)(v16 + 24) = a5;
      result = trace_event_buffer_commit(v18);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
