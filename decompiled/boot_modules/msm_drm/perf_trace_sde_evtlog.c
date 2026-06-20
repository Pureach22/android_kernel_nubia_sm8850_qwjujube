size_t __fastcall perf_trace_sde_evtlog(__int64 a1, const char *a2, int a3, unsigned int a4, const void *a5)
{
  __int64 v5; // x30
  __int64 v7; // x23
  const char *v11; // x24
  size_t result; // x0
  __int64 v13; // x26
  unsigned __int64 StatusReg; // x28
  int v15; // w25
  int v16; // w27
  __int64 v17; // x30
  _QWORD *v18; // x9
  size_t v19; // x23
  unsigned __int64 v20; // x8
  unsigned int v21; // w10
  size_t v22; // x25
  size_t v23; // x26
  unsigned int v24; // w24
  int v25; // w9
  __int64 v26; // x10
  __int64 v27; // x2
  int v28; // w8
  __int64 v29; // x5
  __int64 v30; // x8
  __int64 v31; // x9
  __int64 v32; // x10
  __int64 v33; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v34; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v35[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v7 = v5;
  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v11 = a2;
  else
    v11 = "(null)";
  v35[0] = 0;
  v34 = 0;
  result = strlen(v11);
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v15 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v13) )
  {
    v16 = result & 0xFFFFFFF8;
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 148, v35, &v34);
    if ( result )
    {
      v17 = v7;
      v18 = (_QWORD *)v35[0];
      v33 = v13;
      *(_QWORD *)(v35[0] + 232LL) = &vars0;
      v19 = result;
      v18[31] = &v33;
      v20 = _ReadStatusReg(SP_EL0);
      v18[32] = v17;
      v18[33] = 5;
      v21 = (v15 << 16) + 65676;
      v22 = result + 140;
      *(_DWORD *)(result + 12) = v21;
      v23 = HIWORD(v21) - 1LL;
      *(_DWORD *)(result + 8) = *(_DWORD *)(v20 + 1804);
      memcpy((void *)(result + 140), v11, v23);
      *(_DWORD *)(v19 + 16) = a3;
      if ( a4 >= 0xF )
        v24 = 15;
      else
        v24 = a4;
      *(_BYTE *)(v22 + v23) = 0;
      memcpy((void *)(v19 + 80), a5, 4LL * v24);
      memset((void *)(v19 + 80 + 4LL * v24), 0, (4 * v24) ^ 0x3C);
      v25 = *(_DWORD *)(v19 + 88);
      v26 = *(_QWORD *)(v19 + 92);
      v27 = v34;
      *(_QWORD *)(v19 + 20) = *(_QWORD *)(v19 + 80);
      v28 = *(_DWORD *)(v19 + 100);
      *(_DWORD *)(v19 + 28) = v25;
      v29 = v35[0];
      *(_DWORD *)(v19 + 40) = v28;
      v31 = *(_QWORD *)(v19 + 104);
      v30 = *(_QWORD *)(v19 + 112);
      *(_QWORD *)(v19 + 32) = v26;
      v32 = *(_QWORD *)(v19 + 128);
      *(_QWORD *)(v19 + 44) = v31;
      *(_QWORD *)(v19 + 52) = v30;
      LODWORD(v31) = *(_DWORD *)(v19 + 120);
      LODWORD(v30) = *(_DWORD *)(v19 + 124);
      *(_QWORD *)(v19 + 68) = v32;
      *(_DWORD *)(v19 + 60) = v31;
      *(_DWORD *)(v19 + 64) = v30;
      *(_DWORD *)(v19 + 76) = *(_DWORD *)(v19 + 136);
      result = perf_trace_run_bpf_submit(v19, (unsigned int)(v16 + 148), v27, a1, 1, v29, StatusReg + v33, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
