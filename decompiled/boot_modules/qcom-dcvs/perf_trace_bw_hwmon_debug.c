size_t __fastcall perf_trace_bw_hwmon_debug(
        __int64 a1,
        const char *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 v10; // x28
  const char *v14; // x27
  size_t result; // x0
  __int64 v18; // x26
  int v19; // w20
  __int64 v20; // x30
  _QWORD *v21; // x9
  unsigned int v22; // w10
  size_t v23; // x20
  __int64 v24; // x26
  _QWORD *v25; // x21
  size_t v26; // x28
  unsigned __int64 v27; // x8
  __int64 v28; // x9
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x5
  __int64 v32; // x9
  __int64 v33; // [xsp+0h] [xbp-40h] BYREF
  __int64 v34; // [xsp+8h] [xbp-38h]
  unsigned int v35; // [xsp+14h] [xbp-2Ch]
  __int64 v36; // [xsp+18h] [xbp-28h]
  unsigned __int64 StatusReg; // [xsp+20h] [xbp-20h]
  unsigned int v38; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v39[2]; // [xsp+30h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+40h] [xbp+0h] BYREF

  v36 = a3;
  v10 = v8;
  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v14 = a2;
  else
    v14 = "(null)";
  v39[0] = 0;
  v38 = 0;
  result = strlen(v14);
  v18 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v19 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v18) )
  {
    v35 = ((result + 76) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v35, v39, &v38);
    if ( result )
    {
      v20 = v10;
      v21 = (_QWORD *)v39[0];
      v22 = (v19 << 16) + 65600;
      *(_QWORD *)(v39[0] + 248LL) = &v33;
      v23 = result + 64;
      v21[29] = &vars0;
      v34 = v18;
      v24 = a8;
      v25 = (_QWORD *)result;
      v26 = HIWORD(v22) - 1LL;
      v21[32] = v20;
      v21[33] = 5;
      *(_DWORD *)(result + 8) = v22;
      memcpy((void *)(result + 64), v14, v26);
      v28 = v36;
      v27 = StatusReg;
      *(_BYTE *)(v23 + v26) = 0;
      v29 = v35;
      v30 = v38;
      v31 = v39[0];
      v25[2] = v28;
      v25[3] = a4;
      v32 = v34;
      v25[4] = a5;
      v25[5] = a6;
      v25[6] = a7;
      v25[7] = v24;
      result = perf_trace_run_bpf_submit(v25, v29, v30, a1, 1, v31, v27 + v32, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
