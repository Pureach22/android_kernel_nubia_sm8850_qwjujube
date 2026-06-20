size_t __fastcall perf_trace_rpmh_drv_enable(__int64 a1, const char *a2, char a3, int a4)
{
  __int64 v4; // x30
  __int64 v6; // x23
  const char *v9; // x22
  size_t result; // x0
  __int64 v11; // x25
  unsigned __int64 StatusReg; // x26
  int v13; // w24
  int v14; // w27
  __int64 v15; // x30
  _QWORD *v16; // x9
  unsigned int v17; // w10
  char v18; // w28
  size_t v19; // x21
  size_t v20; // x24
  size_t v21; // x23
  __int64 v22; // x2
  __int64 v23; // x5
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v9 = a2;
  else
    v9 = "(null)";
  v26[0] = 0;
  v25 = 0;
  result = strlen(v9);
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v14 = result & 0xFFFFFFF8;
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 28, v26, &v25);
    if ( result )
    {
      v15 = v6;
      v16 = (_QWORD *)v26[0];
      v17 = (v13 << 16) + 65556;
      *(_QWORD *)(v26[0] + 248LL) = &v24;
      v18 = a3 & 1;
      v19 = result + 20;
      v16[29] = &vars0;
      v20 = result;
      v21 = HIWORD(v17) - 1LL;
      v16[32] = v15;
      v16[33] = 5;
      *(_DWORD *)(result + 8) = v17;
      memcpy((void *)(result + 20), v9, v21);
      *(_BYTE *)(v19 + v21) = 0;
      v22 = v25;
      v23 = v26[0];
      *(_BYTE *)(v20 + 12) = v18;
      *(_DWORD *)(v20 + 16) = a4;
      result = perf_trace_run_bpf_submit(v20, (unsigned int)(v14 + 28), v22, a1, 1, v23, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
