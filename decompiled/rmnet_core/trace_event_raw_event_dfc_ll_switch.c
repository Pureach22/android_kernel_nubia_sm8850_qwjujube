__int64 __fastcall trace_event_raw_event_dfc_ll_switch(
        __int64 a1,
        const char *a2,
        char a3,
        unsigned __int8 a4,
        const void *a5)
{
  __int64 v9; // x8
  const char *v10; // x23
  int v11; // w24
  __int64 result; // x0
  int v13; // w8
  int v14; // w9
  __int64 v15; // x22
  size_t v16; // x24
  __int64 v17; // x25
  __int64 v18; // x8
  const char *v19; // x23
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v9 & 0x2C0) == 0
    || (v9 & 0x100) != 0
    || (v19 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v19, (result & 1) == 0) )
  {
    if ( a2 )
      v10 = a2;
    else
      v10 = "(null)";
    v11 = strlen(v10);
    result = trace_event_buffer_reserve(v20, a1, v11 + 1 + a4 + 20LL);
    if ( result )
    {
      v13 = ((v11 + 1) << 16) | 0x14;
      v14 = (v11 + 21) | (a4 << 16);
      v15 = result + 20;
      v16 = (unsigned __int16)(v11 + 1) - 1LL;
      v17 = result;
      *(_DWORD *)(result + 8) = v13;
      *(_DWORD *)(result + 16) = v14;
      memcpy((void *)(result + 20), v10, v16);
      v18 = *(unsigned __int16 *)(v17 + 16);
      *(_BYTE *)(v15 + v16) = 0;
      *(_BYTE *)(v17 + 12) = a3;
      *(_BYTE *)(v17 + 13) = a4;
      memcpy((void *)(v17 + v18), a5, a4);
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
