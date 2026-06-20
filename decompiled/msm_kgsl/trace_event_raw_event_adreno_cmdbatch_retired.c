__int64 __fastcall trace_event_raw_event_adreno_cmdbatch_retired(
        __int64 a1,
        __int64 a2,
        int *a3,
        int a4,
        int a5,
        int a6)
{
  __int64 v11; // x9
  __int64 result; // x0
  int v13; // w8
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v11 & 0x2C0) == 0 || (v11 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v14);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 4);
      *(_DWORD *)(result + 12) = a3[5];
      v13 = *a3;
      *(_DWORD *)(result + 20) = a6;
      *(_DWORD *)(result + 24) = a4;
      *(_DWORD *)(result + 16) = v13;
      *(_QWORD *)(result + 32) = *((_QWORD *)a3 + 4);
      *(_QWORD *)(result + 40) = *((_QWORD *)a3 + 5);
      *(_DWORD *)(result + 48) = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(result + 52) = a3[1];
      *(_DWORD *)(result + 56) = a3[2];
      *(_DWORD *)(result + 60) = a3[3];
      *(_DWORD *)(result + 64) = a5;
      *(_DWORD *)(result + 80) = a3[4];
      *(_QWORD *)(result + 88) = *((_QWORD *)a3 + 3);
      *(_QWORD *)(result + 96) = *((_QWORD *)a3 + 6);
      *(_QWORD *)(result + 104) = *((_QWORD *)a3 + 7);
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
