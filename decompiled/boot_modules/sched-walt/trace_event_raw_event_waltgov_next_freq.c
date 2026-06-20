__int64 __fastcall trace_event_raw_event_waltgov_next_freq(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6,
        int a7,
        char a8,
        char a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  __int64 v16; // x8
  __int64 v21; // x9
  __int64 result; // x0
  int v23; // w8
  int v24; // w9
  __int64 v25; // x9
  __int64 v26; // x9
  __int64 v27; // x9
  __int64 v28; // x8
  int v29; // w8
  _QWORD v31[7]; // [xsp+8h] [xbp-38h] BYREF

  v16 = a1;
  v31[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = *(_QWORD *)(a1 + 72);
  memset(v31, 0, 48);
  if ( (v21 & 0x2C0) == 0
    || (v21 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v16 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v31, v16, 80);
    if ( result )
    {
      v23 = a2[7];
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_DWORD *)(result + 32) = a5;
      *(_DWORD *)(result + 36) = a6;
      *(_DWORD *)(result + 8) = v23;
      *(_DWORD *)(result + 40) = a2[13];
      v24 = a2[14];
      *(_BYTE *)(result + 52) = a8 & 1;
      *(_BYTE *)(result + 53) = a9 & 1;
      *(_DWORD *)(result + 44) = v24;
      *(_DWORD *)(result + 48) = a7;
      v25 = (unsigned int)a2[7];
      if ( (unsigned int)v25 >= 0x20
        || (v26 = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v25) + 3760),
            *(_DWORD *)(result + 64) = a11,
            *(_DWORD *)(result + 56) = v26,
            *(_DWORD *)(result + 60) = a10,
            v27 = (unsigned int)a2[7],
            (unsigned int)v27 >= 0x20)
        || (v28 = *(unsigned int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v27) + 8] + 32LL),
            (unsigned int)v28 > 3) )
      {
        __break(0x5512u);
      }
      v29 = *((_DWORD *)&freq_cap + v28 + 4);
      *(_DWORD *)(result + 76) = a13;
      *(_DWORD *)(result + 68) = v29;
      *(_DWORD *)(result + 72) = a12;
      result = trace_event_buffer_commit(v31);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
