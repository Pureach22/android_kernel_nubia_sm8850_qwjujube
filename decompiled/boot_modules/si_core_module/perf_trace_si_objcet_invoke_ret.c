size_t __fastcall perf_trace_si_objcet_invoke_ret(__int64 a1, const char *a2, int a3, int a4, __int64 a5, int a6)
{
  __int64 v6; // x30
  __int64 v8; // x26
  const char *v13; // x25
  size_t result; // x0
  __int64 v15; // x21
  int v16; // w27
  unsigned int v17; // w24
  __int64 v18; // x30
  _QWORD *v19; // x9
  unsigned int v20; // w10
  size_t v21; // x26
  int v22; // w21
  size_t v23; // x28
  size_t v24; // x27
  unsigned __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x2
  __int64 v28; // x5
  __int64 v29; // [xsp+0h] [xbp-30h] BYREF
  __int64 v30; // [xsp+8h] [xbp-28h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-20h]
  unsigned int v32; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v33[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v8 = v6;
  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v13 = a2;
  else
    v13 = "(null)";
  v33[0] = 0;
  v32 = 0;
  result = strlen(v13);
  v15 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v16 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v15) )
  {
    v17 = ((result + 52) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v17, v33, &v32);
    if ( result )
    {
      v18 = v8;
      v19 = (_QWORD *)v33[0];
      v20 = (v16 << 16) + 65572;
      *(_QWORD *)(v33[0] + 248LL) = &v29;
      v21 = result + 36;
      v19[29] = &vars0;
      v30 = v15;
      v22 = a6;
      v23 = result;
      v24 = HIWORD(v20) - 1LL;
      v19[32] = v18;
      v19[33] = 5;
      *(_DWORD *)(result + 8) = v20;
      memcpy((void *)(result + 36), v13, v24);
      v26 = v30;
      v25 = StatusReg;
      *(_BYTE *)(v21 + v24) = 0;
      v27 = v32;
      v28 = v33[0];
      *(_DWORD *)(v23 + 12) = a3;
      *(_DWORD *)(v23 + 16) = a4;
      *(_QWORD *)(v23 + 24) = a5;
      *(_DWORD *)(v23 + 32) = v22;
      result = perf_trace_run_bpf_submit(v23, v17, v27, a1, 1, v28, v25 + v26, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
