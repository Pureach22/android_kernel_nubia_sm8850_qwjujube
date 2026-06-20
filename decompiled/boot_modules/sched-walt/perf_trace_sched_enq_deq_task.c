__int64 __fastcall perf_trace_sched_enq_deq_task(__int64 result, __int64 *a2, char a3, int a4, char a5, int a6)
{
  __int64 v6; // x30
  __int64 v7; // x25
  __int64 v10; // x19
  __int64 v14; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v16; // x9
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x10
  _DWORD *v20; // x8
  __int64 v21; // x9
  __int64 v22; // x2
  __int64 v23; // x5
  char v24; // w8
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v28; // [xsp+20h] [xbp+0h] BYREF

  v7 = v6;
  v10 = result;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v14 = *(_QWORD *)(result + 104);
  v26 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v14) )
  {
    result = perf_trace_buf_alloc(68, v27, &v26);
    if ( result )
    {
      v16 = (_QWORD *)v27[0];
      *(_QWORD *)(v27[0] + 232LL) = &v28;
      v16[31] = &v25;
      v16[32] = v7;
      v16[33] = 5;
      v17 = a2[291];
      *(_QWORD *)(result + 8) = a2[290];
      *(_QWORD *)(result + 16) = v17;
      *(_DWORD *)(result + 24) = *((_DWORD *)a2 + 450);
      *(_DWORD *)(result + 28) = *((_DWORD *)a2 + 37);
      LODWORD(v17) = *((_DWORD *)a2 + 10);
      *(_BYTE *)(result + 36) = a3 & 1;
      *(_DWORD *)(result + 32) = v17;
      v18 = *((unsigned int *)a2 + 10);
      if ( (unsigned int)v18 >= 0x20
        || (*(_DWORD *)(result + 40) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v18) + 4),
            v19 = *((unsigned int *)a2 + 10),
            (unsigned int)v19 > 0x1F) )
      {
        __break(0x5512u);
      }
      *(_DWORD *)(result + 44) = *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v19) + 2640);
      *(_DWORD *)(result + 48) = a4;
      if ( a2 == (__int64 *)&init_task )
        v20 = &vendor_data_pad;
      else
        v20 = a2 + 648;
      *(_DWORD *)(result + 52) = v20[7];
      *(_DWORD *)(result + 56) = *((unsigned __int16 *)v20 + 80);
      v21 = *a2;
      *(_BYTE *)(result + 61) = a5 & 1;
      v22 = v26;
      v23 = v27[0];
      *(_BYTE *)(result + 60) = (v21 & 0x400000) != 0;
      v24 = *((_BYTE *)v20 + 189);
      *(_DWORD *)(result + 64) = a6;
      *(_BYTE *)(result + 62) = v24;
      result = perf_trace_run_bpf_submit(result, 68, v22, v10, 1, v23, StatusReg + v14, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
