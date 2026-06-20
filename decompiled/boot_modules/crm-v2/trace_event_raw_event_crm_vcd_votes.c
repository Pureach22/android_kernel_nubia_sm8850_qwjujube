__int64 __fastcall trace_event_raw_event_crm_vcd_votes(__int64 a1, const char *a2, int a3, int a4, int a5, int a6)
{
  __int64 v11; // x8
  const char *v12; // x24
  int v13; // w25
  __int64 result; // x0
  __int64 v15; // x23
  int v16; // w8
  size_t v17; // x25
  _DWORD *v18; // x26
  const char *v19; // x24
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v11 & 0x2C0) == 0
    || (v11 & 0x100) != 0
    || (v19 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v19, (result & 1) == 0) )
  {
    if ( a2 )
      v12 = a2;
    else
      v12 = "(null)";
    v13 = strlen(v12) + 1;
    result = trace_event_buffer_reserve(v20, a1, v13 + 28LL);
    if ( result )
    {
      v15 = result + 28;
      v16 = (v13 << 16) | 0x1C;
      v17 = (unsigned __int16)v13 - 1LL;
      v18 = (_DWORD *)result;
      *(_DWORD *)(result + 8) = v16;
      memcpy((void *)(result + 28), v12, v17);
      *(_BYTE *)(v15 + v17) = 0;
      v18[3] = a3;
      v18[4] = a4;
      v18[5] = a5;
      v18[6] = a6;
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
