__int64 __fastcall trace_event_raw_event_walt_lb_cpu_util(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 result; // x0
  _BYTE *v8; // x9
  unsigned __int64 v9; // x11
  unsigned __int64 v10; // x9
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v5 = a1;
  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v5 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12, v5, 36);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      if ( a2 >= 0x20 )
      {
        __break(0x5512u);
        JUMPOUT(0x3AA6C);
      }
      *(_DWORD *)(result + 12) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 4);
      *(_DWORD *)(result + 16) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + a2) + 532);
      *(_DWORD *)(result + 20) = *(_DWORD *)(a3 + 24);
      *(_DWORD *)(result + 24) = *(_DWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 56];
      v8 = &walt_rq[*((_QWORD *)&_per_cpu_offset + a2)];
      v9 = *((_QWORD *)v8 + 5);
      v10 = *((_QWORD *)v8 + 79);
      if ( v9 < v10 )
        LODWORD(v10) = v9;
      *(_DWORD *)(result + 28) = v10;
      *(_DWORD *)(result + 32) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 632];
      result = trace_event_buffer_commit(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
