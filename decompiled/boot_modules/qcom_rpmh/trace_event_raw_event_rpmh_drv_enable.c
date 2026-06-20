__int64 __fastcall trace_event_raw_event_rpmh_drv_enable(__int64 a1, const char *a2, char a3, int a4)
{
  __int64 v7; // x8
  const char *v8; // x22
  int v9; // w23
  __int64 result; // x0
  char v11; // w24
  int v12; // w8
  __int64 v13; // x20
  size_t v14; // x21
  __int64 v15; // x23
  const char *v16; // x22
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v7 & 0x2C0) == 0
    || (v7 & 0x100) != 0
    || (v16 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v16, (result & 1) == 0) )
  {
    if ( a2 )
      v8 = a2;
    else
      v8 = "(null)";
    v9 = strlen(v8) + 1;
    result = trace_event_buffer_reserve(v17, a1, v9 + 20LL);
    if ( result )
    {
      v11 = a3 & 1;
      v12 = (v9 << 16) | 0x14;
      v13 = result + 20;
      v14 = (unsigned __int16)v9 - 1LL;
      v15 = result;
      *(_DWORD *)(result + 8) = v12;
      memcpy((void *)(result + 20), v8, v14);
      *(_BYTE *)(v13 + v14) = 0;
      *(_BYTE *)(v15 + 12) = v11;
      *(_DWORD *)(v15 + 16) = a4;
      result = trace_event_buffer_commit(v17);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
