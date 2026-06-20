size_t __fastcall perf_trace_kgsl_issueibcmds(__int64 a1, __int64 a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  __int64 v8; // x30
  __int64 v10; // x27
  const char *v16; // x8
  const char *v18; // x26
  size_t result; // x0
  int v20; // w28
  __int64 v21; // x30
  _QWORD *v22; // x9
  unsigned int v23; // w10
  size_t v24; // x27
  _DWORD *v25; // x20
  size_t v26; // x28
  int v27; // w8
  int v28; // w9
  __int64 v29; // x2
  __int64 v30; // x5
  __int64 v31; // x1
  __int64 v32; // x8
  unsigned __int64 v33; // x9
  int v34; // [xsp+0h] [xbp-30h] BYREF
  int v35; // [xsp+4h] [xbp-2Ch]
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-28h]
  __int64 v37; // [xsp+10h] [xbp-20h]
  unsigned int v38; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v39[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v10 = v8;
  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(const char **)(a2 + 8);
  v39[0] = 0;
  v38 = 0;
  if ( v16 )
    v18 = v16;
  else
    v18 = "(null)";
  result = strlen(v18);
  v20 = result;
  v37 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v37) )
  {
    v35 = result & 0xFFFFFFF8;
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 44, v39, &v38);
    if ( result )
    {
      v21 = v10;
      v22 = (_QWORD *)v39[0];
      v23 = (v20 << 16) + 65572;
      *(_QWORD *)(v39[0] + 248LL) = &v34;
      v24 = result + 36;
      v22[29] = &vars0;
      v34 = a8;
      v25 = (_DWORD *)result;
      v26 = HIWORD(v23) - 1LL;
      v22[32] = v21;
      v22[33] = 5;
      *(_DWORD *)(result + 8) = v23;
      memcpy((void *)(result + 36), v18, v26);
      v28 = v34;
      v27 = v35;
      *(_BYTE *)(v24 + v26) = 0;
      v29 = v38;
      v30 = v39[0];
      v25[7] = a7;
      v25[8] = v28;
      v31 = (unsigned int)(v27 + 44);
      v33 = StatusReg;
      v32 = v37;
      v25[3] = a3;
      v25[4] = a4;
      v25[5] = a5;
      v25[6] = a6;
      result = perf_trace_run_bpf_submit(v25, v31, v29, a1, 1, v30, v33 + v32, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
