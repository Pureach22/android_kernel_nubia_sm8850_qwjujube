__int64 __fastcall perf_trace_waltgov_next_freq(
        __int64 result,
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
  __int64 v13; // x30
  __int64 v14; // x27
  __int64 v16; // x19
  __int64 v22; // x28
  unsigned __int64 StatusReg; // x21
  _QWORD *v24; // x9
  int v25; // w8
  int v26; // w11
  __int64 v27; // x9
  __int64 v28; // x9
  __int64 v29; // x9
  __int64 v30; // x8
  __int64 v31; // x2
  __int64 v32; // x5
  int v33; // w8
  __int64 v34; // [xsp+0h] [xbp-20h] BYREF
  int v35; // [xsp+8h] [xbp-18h]
  unsigned int v36; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v37[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v35 = a7;
  v14 = v13;
  v16 = result;
  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = 0;
  v22 = *(_QWORD *)(result + 104);
  v36 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v22) )
  {
    result = perf_trace_buf_alloc(84, v37, &v36);
    if ( result )
    {
      v24 = (_QWORD *)v37[0];
      *(_QWORD *)(v37[0] + 232LL) = &vars0;
      v24[31] = &v34;
      v24[32] = v14;
      v24[33] = 5;
      LODWORD(v24) = v35;
      v25 = a2[7];
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_DWORD *)(result + 32) = a5;
      *(_DWORD *)(result + 36) = a6;
      *(_DWORD *)(result + 8) = v25;
      *(_DWORD *)(result + 40) = a2[13];
      v26 = a2[14];
      *(_BYTE *)(result + 52) = a8 & 1;
      *(_BYTE *)(result + 53) = a9 & 1;
      *(_DWORD *)(result + 44) = v26;
      *(_DWORD *)(result + 48) = (_DWORD)v24;
      v27 = (unsigned int)a2[7];
      if ( (unsigned int)v27 >= 0x20
        || (v28 = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v27) + 3760),
            *(_DWORD *)(result + 64) = a11,
            *(_DWORD *)(result + 56) = v28,
            *(_DWORD *)(result + 60) = a10,
            v29 = (unsigned int)a2[7],
            (unsigned int)v29 >= 0x20)
        || (v30 = *(unsigned int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v29) + 8] + 32LL),
            (unsigned int)v30 > 3) )
      {
        __break(0x5512u);
      }
      v31 = v36;
      v32 = v37[0];
      v33 = *((_DWORD *)&freq_cap + v30 + 4);
      *(_DWORD *)(result + 76) = a13;
      *(_DWORD *)(result + 68) = v33;
      *(_DWORD *)(result + 72) = a12;
      result = perf_trace_run_bpf_submit(result, 84, v31, v16, 1, v32, StatusReg + v22, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
