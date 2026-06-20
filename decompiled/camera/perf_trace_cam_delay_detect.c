__int64 __fastcall perf_trace_cam_delay_detect(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v8; // x30
  __int64 v10; // x26
  __int64 result; // x0
  __int64 v17; // x27
  unsigned __int64 StatusReg; // x28
  unsigned int v19; // w25
  __int64 v20; // x30
  _QWORD *v21; // x9
  int v22; // w11
  const char *v23; // x12
  int v24; // w8
  __int64 v25; // x26
  __int64 v26; // x28
  const char *v27; // x1
  size_t v28; // x27
  int v29; // w8
  void *v30; // x26
  const char *v31; // x1
  size_t v32; // x27
  __int64 v33; // x2
  _QWORD *v34; // x5
  __int64 v35; // x8
  unsigned __int64 v36; // x9
  __int64 v37; // [xsp+0h] [xbp-50h] BYREF
  unsigned __int64 v38; // [xsp+8h] [xbp-48h]
  __int64 v39; // [xsp+10h] [xbp-40h]
  unsigned int v40; // [xsp+1Ch] [xbp-34h] BYREF
  _QWORD *v41; // [xsp+20h] [xbp-30h] BYREF
  __int64 v42; // [xsp+28h] [xbp-28h] BYREF
  const char *v43; // [xsp+30h] [xbp-20h]
  __int64 v44; // [xsp+38h] [xbp-18h]
  const char *v45; // [xsp+40h] [xbp-10h]
  __int64 v46; // [xsp+48h] [xbp-8h]
  __int64 vars0; // [xsp+50h] [xbp+0h] BYREF

  v10 = v8;
  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v45 = nullptr;
  v42 = 0;
  v43 = nullptr;
  v41 = nullptr;
  v40 = 0;
  result = trace_event_get_offsets_cam_delay_detect(&v42);
  v17 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v17) )
  {
    v19 = ((result + 59) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v19, &v41, &v40);
    if ( result )
    {
      v20 = v10;
      v21 = v41;
      v22 = v42;
      v23 = v43;
      v41[31] = &v37;
      v24 = v44;
      v21[29] = &vars0;
      v25 = result + (unsigned __int16)v22;
      v38 = StatusReg;
      v39 = v17;
      v26 = result;
      HIDWORD(v37) = a8;
      v21[32] = v20;
      v21[33] = 5;
      if ( v23 )
        v27 = v23;
      else
        v27 = "(null)";
      *(_DWORD *)(result + 8) = v22;
      *(_DWORD *)(result + 12) = v24;
      v28 = HIWORD(v22) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v22), v27, v28);
      *(_BYTE *)(v25 + v28) = 0;
      v29 = *(_DWORD *)(v26 + 12);
      v30 = (void *)(v26 + (unsigned __int16)v29);
      if ( v45 )
        v31 = v45;
      else
        v31 = "(null)";
      v32 = HIWORD(v29) - 1LL;
      memcpy(v30, v31, v32);
      *((_BYTE *)v30 + v32) = 0;
      *(_QWORD *)(v26 + 16) = a4;
      *(_QWORD *)(v26 + 24) = a5;
      v33 = v40;
      v34 = v41;
      *(_DWORD *)(v26 + 40) = HIDWORD(v37);
      v36 = v38;
      v35 = v39;
      *(_DWORD *)(v26 + 32) = a6;
      *(_DWORD *)(v26 + 36) = a7;
      result = perf_trace_run_bpf_submit(v26, v19, v33, a1, 1, v34, v36 + v35, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
