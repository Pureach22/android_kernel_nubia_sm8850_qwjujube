__int64 __fastcall perf_trace_tracing_eva_frame_from_sw(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        int a6,
        __int64 a7,
        int a8,
        __int64 a9)
{
  __int64 v9; // x30
  __int64 v12; // x26
  __int64 result; // x0
  __int64 v18; // x27
  unsigned __int64 StatusReg; // x28
  unsigned int v20; // w24
  __int64 v21; // x30
  _QWORD *v22; // x9
  int v23; // w11
  __int64 v24; // x26
  int v25; // w10
  const char *v26; // x9
  __int64 v27; // x27
  __int64 v28; // x25
  const char *v29; // x1
  int v30; // w8
  void *v31; // x26
  const char *v32; // x1
  size_t v33; // x27
  __int64 v34; // x8
  __int64 v35; // x10
  __int64 v36; // x2
  _QWORD *v37; // x5
  __int64 v38; // x6
  unsigned __int64 v39; // [xsp+0h] [xbp-50h] BYREF
  __int64 v40; // [xsp+8h] [xbp-48h]
  __int64 v41; // [xsp+10h] [xbp-40h]
  unsigned int v42; // [xsp+1Ch] [xbp-34h] BYREF
  _QWORD *v43; // [xsp+20h] [xbp-30h] BYREF
  __int64 v44; // [xsp+28h] [xbp-28h] BYREF
  const char *v45; // [xsp+30h] [xbp-20h]
  __int64 v46; // [xsp+38h] [xbp-18h]
  const char *v47; // [xsp+40h] [xbp-10h]
  __int64 v48; // [xsp+48h] [xbp-8h]
  __int64 vars0; // [xsp+50h] [xbp+0h] BYREF

  v12 = v9;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = nullptr;
  v44 = 0;
  v45 = nullptr;
  v43 = nullptr;
  v42 = 0;
  result = trace_event_get_offsets_tracing_eva_frame_from_sw(&v44, a3, a7);
  v18 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v18) )
  {
    v20 = ((result + 59) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v20, &v43, &v42);
    if ( result )
    {
      v21 = v12;
      v22 = v43;
      v23 = v44;
      v43[29] = &vars0;
      v22[31] = &v39;
      v24 = result + (unsigned __int16)v23;
      v39 = StatusReg;
      v22[32] = v21;
      v22[33] = 5;
      v25 = v46;
      *(_DWORD *)(result + 16) = v23;
      v40 = a9;
      v41 = v18;
      v26 = v45;
      v27 = HIWORD(v23) - 1LL;
      *(_DWORD *)(result + 32) = v25;
      *(_QWORD *)(result + 8) = a2;
      v28 = result;
      if ( v26 )
        v29 = v26;
      else
        v29 = "(null)";
      memcpy((void *)(result + (unsigned __int16)v23), v29, HIWORD(v23) - 1LL);
      *(_BYTE *)(v24 + v27) = 0;
      v30 = *(_DWORD *)(v28 + 32);
      v31 = (void *)(v28 + (unsigned __int16)v30);
      if ( v47 )
        v32 = v47;
      else
        v32 = "(null)";
      v33 = HIWORD(v30) - 1LL;
      memcpy(v31, v32, v33);
      v35 = v40;
      v34 = v41;
      *((_BYTE *)v31 + v33) = 0;
      v36 = v42;
      v37 = v43;
      v38 = v39 + v34;
      *(_DWORD *)(v28 + 20) = a4;
      *(_DWORD *)(v28 + 24) = a5;
      *(_DWORD *)(v28 + 28) = a6;
      *(_DWORD *)(v28 + 36) = a8;
      *(_QWORD *)(v28 + 40) = v35;
      result = perf_trace_run_bpf_submit(v28, v20, v36, a1, 1, v37, v38, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
