__int64 __fastcall trace_event_raw_event_sched_enq_deq_task(__int64 a1, __int64 *a2, char a3, int a4, char a5, int a6)
{
  __int64 v9; // x8
  __int64 v12; // x9
  __int64 result; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x10
  _DWORD *v17; // x8
  __int64 v18; // x9
  char v19; // w8
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v9 = a1;
  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v12 & 0x2C0) == 0
    || (v12 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v9 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v21, v9, 68);
    if ( result )
    {
      v14 = a2[291];
      *(_QWORD *)(result + 8) = a2[290];
      *(_QWORD *)(result + 16) = v14;
      *(_DWORD *)(result + 24) = *((_DWORD *)a2 + 450);
      *(_DWORD *)(result + 28) = *((_DWORD *)a2 + 37);
      LODWORD(v14) = *((_DWORD *)a2 + 10);
      *(_BYTE *)(result + 36) = a3 & 1;
      *(_DWORD *)(result + 32) = v14;
      v15 = *((unsigned int *)a2 + 10);
      if ( (unsigned int)v15 >= 0x20
        || (*(_DWORD *)(result + 40) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v15) + 4),
            v16 = *((unsigned int *)a2 + 10),
            (unsigned int)v16 > 0x1F) )
      {
        __break(0x5512u);
      }
      *(_DWORD *)(result + 44) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v16) + 2640);
      *(_DWORD *)(result + 48) = a4;
      if ( a2 == (__int64 *)&init_task )
        v17 = &vendor_data_pad;
      else
        v17 = a2 + 648;
      *(_DWORD *)(result + 52) = v17[7];
      *(_DWORD *)(result + 56) = *((unsigned __int16 *)v17 + 80);
      v18 = *a2;
      *(_BYTE *)(result + 61) = a5 & 1;
      *(_BYTE *)(result + 60) = (v18 & 0x400000) != 0;
      v19 = *((_BYTE *)v17 + 189);
      *(_DWORD *)(result + 64) = a6;
      *(_BYTE *)(result + 62) = v19;
      result = trace_event_buffer_commit(v21);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
