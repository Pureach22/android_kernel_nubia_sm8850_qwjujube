__int64 __fastcall trace_event_raw_event_gh_rm_mem_notify(__int64 a1, int a2, char a3, int a4, unsigned __int16 *a5)
{
  __int64 v8; // x8
  __int64 v10; // x9
  int v11; // w23
  __int64 result; // x0
  int v13; // w8
  unsigned __int64 v14; // x8
  __int16 *v15; // x10
  __int16 v16; // t1
  unsigned __int64 v17; // x12
  _QWORD v19[7]; // [xsp+8h] [xbp-38h] BYREF

  v8 = a1;
  v19[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v19, 0, 48);
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v8 = a1, (result & 1) == 0) )
  {
    v11 = a5 ? 2 * *a5 : 0;
    result = trace_event_buffer_reserve(v19, v8, (unsigned int)(v11 + 28));
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_BYTE *)(result + 12) = a3;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 24) = (v11 << 16) | 0x1C;
      if ( a5 )
      {
        v13 = *a5;
        *(_WORD *)(result + 20) = v13;
        if ( v13 )
        {
          v14 = 0;
          v15 = (__int16 *)(a5 + 2);
          do
          {
            v16 = *v15;
            v15 += 2;
            v17 = *(unsigned __int16 *)(result + 20);
            *(_WORD *)(result + 28 + 2 * v14++) = v16;
          }
          while ( v14 < v17 );
        }
      }
      else
      {
        *(_WORD *)(result + 20) = 0;
      }
      result = trace_event_buffer_commit(v19);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
