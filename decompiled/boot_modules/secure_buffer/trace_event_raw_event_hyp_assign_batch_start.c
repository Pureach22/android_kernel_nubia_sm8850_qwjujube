__int64 __fastcall trace_event_raw_event_hyp_assign_batch_start(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 result; // x0
  int v8; // w8
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 *v11; // x10
  __int64 v12; // x11
  __int64 v13; // t1
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v5 = a1;
  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v5 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v15, v5, (int)(16 * a3) + 32LL);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a3;
      v8 = 8 * a3 + 32;
      *(_QWORD *)(result + 16) = 0;
      *(_DWORD *)(result + 24) = ((unsigned __int16)a3 << 19) | 0x20;
      *(_DWORD *)(result + 28) = v8 | (a3 << 19);
      if ( a3 )
      {
        v9 = (unsigned __int16)v8 & 0xFFF8;
        v10 = a3;
        v11 = (__int64 *)(a2 + 8);
        v12 = result;
        do
        {
          --v10;
          *(_QWORD *)(v12 + 32) = *(v11 - 1);
          v13 = *v11;
          v11 += 2;
          *(_QWORD *)(v12 + v9) = v13;
          v12 += 8;
          *(_QWORD *)(result + 16) += v13;
        }
        while ( v10 );
      }
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
