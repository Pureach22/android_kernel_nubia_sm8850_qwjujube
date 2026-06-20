__int64 __fastcall trace_event_raw_event_hyp_assign_info(
        __int64 a1,
        const void *a2,
        int a3,
        const void *a4,
        const void *a5,
        int a6)
{
  __int64 v9; // x8
  __int64 v12; // x9
  int v13; // w24
  int v14; // w25
  __int64 result; // x0
  int v16; // w8
  size_t v17; // x2
  __int64 v18; // x23
  size_t v19; // x21
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v9 = a1;
  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v12 & 0x2C0) == 0
    || (v12 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v9 = a1, (result & 1) == 0) )
  {
    v13 = 4 * a3;
    v14 = 4 * a6 + 4 * a3;
    result = trace_event_buffer_reserve(v21, v9, v14 + 4 * a6 + 28LL);
    if ( result )
    {
      v16 = (a3 << 18) | 0x1C;
      v17 = 4LL * a3;
      *(_DWORD *)(result + 8) = a3;
      *(_DWORD *)(result + 12) = a6;
      v18 = result;
      *(_DWORD *)(result + 16) = v16;
      *(_DWORD *)(result + 20) = (a6 << 18) | (v13 + 28);
      *(_DWORD *)(result + 24) = (v14 + 28) | (a6 << 18);
      memcpy((void *)(result + 28), a2, v17);
      v19 = 4LL * a6;
      memcpy((void *)(v18 + *(unsigned __int16 *)(v18 + 20)), a4, v19);
      memcpy((void *)(v18 + *(unsigned __int16 *)(v18 + 24)), a5, v19);
      result = trace_event_buffer_commit(v21);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
