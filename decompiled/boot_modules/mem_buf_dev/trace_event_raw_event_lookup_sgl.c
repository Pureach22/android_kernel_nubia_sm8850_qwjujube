__int64 __fastcall trace_event_raw_event_lookup_sgl(__int64 a1, unsigned int *a2, int a3, int a4)
{
  __int64 v7; // x1
  __int64 v8; // x8
  int v9; // w22
  __int64 result; // x0
  int v11; // w9
  unsigned __int64 v12; // x8
  __int64 *v13; // x11
  __int64 v14; // t1
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v7 = a1;
  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v8 & 0x2C0) == 0 || (v8 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v7 = a1, (result & 1) == 0) )
  {
    v9 = *a2;
    result = trace_event_buffer_reserve(v16, v7, (int)(16 * *a2) + 28LL);
    if ( result )
    {
      v11 = 8 * v9 + 28;
      *(_DWORD *)(result + 12) = ((unsigned __int16)v9 << 19) | 0x1C;
      *(_DWORD *)(result + 16) = v11 | (v9 << 19);
      *(_WORD *)(result + 8) = *a2;
      if ( *a2 )
      {
        v12 = 0;
        v13 = (__int64 *)((char *)a2 + 14);
        do
        {
          *(_QWORD *)(result + 28 + 8 * v12) = *(v13 - 1);
          v14 = *v13;
          v13 += 2;
          *(_QWORD *)(result + ((unsigned __int16)v11 & 0xFFFC) + 8 * v12++) = v14;
        }
        while ( v12 < *a2 );
      }
      *(_DWORD *)(result + 20) = a3;
      *(_DWORD *)(result + 24) = a4;
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
