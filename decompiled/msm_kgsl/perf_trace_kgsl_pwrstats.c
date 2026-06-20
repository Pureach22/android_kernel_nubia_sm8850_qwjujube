size_t __fastcall perf_trace_kgsl_pwrstats(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4, int a5, __int64 a6)
{
  __int64 v6; // x30
  __int64 v8; // x26
  const char *v13; // x8
  const char *v14; // x25
  size_t result; // x0
  __int64 v16; // x20
  int v17; // w27
  unsigned int v18; // w24
  __int64 v19; // x30
  _QWORD *v20; // x9
  unsigned int v21; // w10
  size_t v22; // x26
  __int64 v23; // x20
  size_t v24; // x28
  size_t v25; // x27
  __int64 v26; // x2
  __int64 v27; // x5
  __int64 v28; // x8
  __int64 v29; // [xsp+0h] [xbp-30h] BYREF
  __int64 v30; // [xsp+8h] [xbp-28h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-20h]
  unsigned int v32; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v33[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v8 = v6;
  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(const char **)(a2 + 8);
  v33[0] = 0;
  v32 = 0;
  if ( v13 )
    v14 = v13;
  else
    v14 = "(null)";
  result = strlen(v14);
  v16 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v17 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v16) )
  {
    v18 = ((result + 76) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v18, v33, &v32);
    if ( result )
    {
      v19 = v8;
      v20 = (_QWORD *)v33[0];
      v21 = (v17 << 16) + 65600;
      *(_QWORD *)(v33[0] + 248LL) = &v29;
      v22 = result + 64;
      v20[29] = &vars0;
      v30 = v16;
      v23 = a6;
      v24 = result;
      v25 = HIWORD(v21) - 1LL;
      v20[32] = v19;
      v20[33] = 5;
      *(_DWORD *)(result + 8) = v21;
      memcpy((void *)(result + 64), v14, v25);
      *(_BYTE *)(v22 + v25) = 0;
      *(_QWORD *)(v24 + 16) = a3;
      v26 = v32;
      v27 = v33[0];
      *(_QWORD *)(v24 + 24) = *a4;
      *(_QWORD *)(v24 + 32) = a4[1];
      v28 = a4[2];
      *(_DWORD *)(v24 + 48) = a5;
      *(_QWORD *)(v24 + 56) = v23;
      *(_QWORD *)(v24 + 40) = v28;
      result = perf_trace_run_bpf_submit(v24, v18, v26, a1, 1, v27, StatusReg + v30, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
