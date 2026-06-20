__int64 __fastcall trace_event_raw_event_map_mem_s2(__int64 a1, int a2, unsigned int *a3)
{
  __int64 v5; // x1
  __int64 v6; // x8
  int v7; // w21
  __int64 result; // x0
  int v9; // w9
  unsigned __int64 v10; // x8
  __int64 *v11; // x11
  __int64 v12; // t1
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v5 = a1;
  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v5 = a1, (result & 1) == 0) )
  {
    v7 = *a3;
    result = trace_event_buffer_reserve(v14, v5, (int)(16 * *a3) + 24LL);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      v9 = 8 * v7 + 24;
      *(_DWORD *)(result + 16) = ((unsigned __int16)v7 << 19) | 0x18;
      *(_DWORD *)(result + 20) = v9 | (v7 << 19);
      *(_WORD *)(result + 12) = *a3;
      if ( *a3 )
      {
        v10 = 0;
        v11 = (__int64 *)((char *)a3 + 14);
        do
        {
          *(_QWORD *)(result + 24 + 8 * v10) = *(v11 - 1);
          v12 = *v11;
          v11 += 2;
          *(_QWORD *)(result + ((unsigned __int16)v9 & 0xFFF8) + 8 * v10++) = v12;
        }
        while ( v10 < *a3 );
      }
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
