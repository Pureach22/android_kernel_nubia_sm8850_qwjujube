__int64 __fastcall trace_event_raw_event_gh_rm_mem_accept_reply(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x1
  __int64 v4; // x8
  int v5; // w20
  unsigned int v6; // w21
  __int64 result; // x0
  unsigned int v8; // w8
  int v9; // w10
  unsigned __int64 v10; // x8
  __int64 *v11; // x11
  __int64 v12; // t1
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v3 = a1;
  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v4 & 0x2C0) == 0 || (v4 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v3 = a1, (result & 1) == 0) )
  {
    v5 = 25;
    if ( a2 )
    {
      v6 = *a2 <= 4 ? 8 * *a2 : 32;
      v5 = (((v6 >> 3) & 0xFFF) << 19) | 0x19;
    }
    else
    {
      v6 = 0;
    }
    result = trace_event_buffer_reserve(v14, v3, 2 * v6 + 28);
    if ( result )
    {
      *(_BYTE *)(result + 24) = (unsigned __int64)a2 > 0xFFFFFFFFFFFFF000LL;
      *(_DWORD *)(result + 12) = v5;
      *(_DWORD *)(result + 16) = (v6 + 25) | (v6 << 16);
      if ( a2 && (unsigned __int64)a2 <= 0xFFFFFFFFFFFFF000LL )
      {
        v8 = *a2;
        *(_DWORD *)(result + 8) = *a2;
        if ( v8 >= 4 )
          v9 = 4;
        else
          v9 = v8;
        *(_DWORD *)(result + 20) = v9;
        if ( v8 )
        {
          v10 = 0;
          v11 = (__int64 *)((char *)a2 + 14);
          do
          {
            *(_QWORD *)(result + 25 + 8 * v10) = *(v11 - 1);
            v12 = *v11;
            v11 += 2;
            *(_QWORD *)(result + (unsigned __int16)(v6 + 25) + 8 * v10++) = v12;
          }
          while ( v10 < *(unsigned int *)(result + 20) );
        }
      }
      else
      {
        *(_DWORD *)(result + 8) = 0;
        *(_DWORD *)(result + 20) = 0;
      }
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
