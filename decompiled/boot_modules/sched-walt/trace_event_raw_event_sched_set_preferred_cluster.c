__int64 __fastcall trace_event_raw_event_sched_set_preferred_cluster(
        __int64 a1,
        int *a2,
        __int64 a3,
        char a4,
        int a5,
        int a6)
{
  __int64 v9; // x8
  __int64 v12; // x9
  __int64 result; // x0
  int v14; // w8
  char v15; // w9
  int v16; // w9
  __int64 v17; // x8
  __int64 v18; // x8
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v9 = a1;
  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v12 & 0x2C0) == 0
    || (v12 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v9 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v20, v9, 72);
    if ( result )
    {
      v14 = *a2;
      *(_QWORD *)(result + 16) = a3;
      *(_DWORD *)(result + 8) = v14;
      v15 = *((_BYTE *)a2 + 40);
      *(_BYTE *)(result + 25) = a4 & 1;
      *(_BYTE *)(result + 24) = v15;
      v16 = sysctl_sched_hyst_min_coloc_ns;
      *(_QWORD *)(result + 32) = *((_QWORD *)a2 + 10);
      v17 = *((_QWORD *)a2 + 8);
      *(_DWORD *)(result + 48) = v16;
      *(_QWORD *)(result + 40) = v17;
      v18 = *((_QWORD *)a2 + 9);
      *(_DWORD *)(result + 64) = a5;
      *(_DWORD *)(result + 68) = a6;
      *(_QWORD *)(result + 56) = v18;
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
