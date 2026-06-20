size_t __fastcall perf_trace_memlat_dev_meas(
        __int64 a1,
        const char *a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  __int64 v10; // x30
  __int64 v12; // x28
  const char *v16; // x27
  size_t result; // x0
  __int64 v20; // x25
  int v21; // w20
  _QWORD *v22; // x9
  unsigned int v23; // w10
  size_t v24; // x20
  int v25; // w25
  size_t v26; // x21
  size_t v27; // x28
  __int64 v28; // x1
  int v29; // w8
  __int64 v30; // x2
  __int64 v31; // x5
  int v32; // w8
  int v33; // w9
  unsigned __int64 v34; // x8
  __int64 v35; // x9
  __int64 v36; // [xsp+0h] [xbp-40h] BYREF
  int v37; // [xsp+8h] [xbp-38h]
  int v38; // [xsp+Ch] [xbp-34h]
  __int64 v39; // [xsp+10h] [xbp-30h]
  unsigned int v40; // [xsp+18h] [xbp-28h]
  int v41; // [xsp+1Ch] [xbp-24h]
  unsigned __int64 StatusReg; // [xsp+20h] [xbp-20h]
  unsigned int v43; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v44[2]; // [xsp+30h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+40h] [xbp+0h] BYREF

  v41 = a3;
  v12 = v10;
  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v16 = a2;
  else
    v16 = "(null)";
  v44[0] = 0;
  v43 = 0;
  result = strlen(v16);
  v20 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v21 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v20) )
  {
    v40 = ((result + 68) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v40, v44, &v43);
    if ( result )
    {
      v22 = (_QWORD *)v44[0];
      v23 = (v21 << 16) + 65592;
      *(_QWORD *)(v44[0] + 248LL) = &v36;
      v24 = result + 56;
      v39 = v20;
      v22[29] = &vars0;
      v25 = a8;
      v26 = result;
      v38 = a10;
      v22[32] = v12;
      v22[33] = 5;
      *(_DWORD *)(result + 8) = v23;
      v27 = HIWORD(v23) - 1LL;
      v37 = a9;
      memcpy((void *)(result + 56), v16, v27);
      v28 = v40;
      v29 = v41;
      *(_BYTE *)(v24 + v27) = 0;
      v30 = v43;
      v31 = v44[0];
      *(_DWORD *)(v26 + 12) = v29;
      v33 = v37;
      v32 = v38;
      *(_QWORD *)(v26 + 16) = a4;
      *(_QWORD *)(v26 + 24) = a5;
      *(_QWORD *)(v26 + 32) = a6;
      *(_DWORD *)(v26 + 48) = v33;
      *(_DWORD *)(v26 + 52) = v32;
      v34 = StatusReg;
      v35 = v39;
      *(_DWORD *)(v26 + 40) = a7;
      *(_DWORD *)(v26 + 44) = v25;
      result = perf_trace_run_bpf_submit(v26, v28, v30, a1, 1, v31, v34 + v35, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
