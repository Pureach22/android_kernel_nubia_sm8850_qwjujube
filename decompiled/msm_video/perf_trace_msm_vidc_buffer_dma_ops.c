__int64 __fastcall perf_trace_msm_vidc_buffer_dma_ops(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        __int64 a5,
        __int64 a6,
        char a7,
        int a8)
{
  __int64 v8; // x30
  __int64 v11; // x26
  __int64 result; // x0
  __int64 v17; // x21
  unsigned __int64 StatusReg; // x22
  unsigned int v19; // w24
  _QWORD *v20; // x9
  int v21; // w8
  __int64 v22; // x22
  char v23; // w21
  __int64 v24; // x28
  int v25; // w10
  const char *v26; // x9
  void *v27; // x26
  __int64 v28; // x10
  const char *v29; // x1
  __int64 v30; // x27
  const char *v31; // x10
  int v32; // w8
  __int64 v33; // x23
  size_t v34; // x22
  const char *v35; // x1
  unsigned __int64 v36; // x8
  __int64 v37; // x9
  __int64 v38; // x2
  _QWORD *v39; // x5
  __int64 v40; // [xsp+0h] [xbp-50h] BYREF
  __int64 v41; // [xsp+8h] [xbp-48h]
  unsigned __int64 v42; // [xsp+10h] [xbp-40h]
  unsigned int v43; // [xsp+1Ch] [xbp-34h] BYREF
  _QWORD *v44; // [xsp+20h] [xbp-30h] BYREF
  __int64 v45; // [xsp+28h] [xbp-28h] BYREF
  const char *v46; // [xsp+30h] [xbp-20h]
  __int64 v47; // [xsp+38h] [xbp-18h]
  const char *v48; // [xsp+40h] [xbp-10h]
  __int64 v49; // [xsp+48h] [xbp-8h]
  __int64 vars0; // [xsp+50h] [xbp+0h] BYREF

  v11 = v8;
  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = nullptr;
  v45 = 0;
  v46 = nullptr;
  v44 = nullptr;
  v43 = 0;
  result = trace_event_get_offsets_msm_vidc_buffer_dma_ops(&v45);
  v17 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v17) )
  {
    v19 = ((result + 67) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v19, &v44, &v43);
    if ( result )
    {
      v20 = v44;
      v41 = v17;
      v42 = StatusReg;
      v44[31] = &v40;
      v21 = v47;
      v22 = a5;
      v20[29] = &vars0;
      v23 = a4;
      v24 = result;
      v20[32] = v11;
      v20[33] = 5;
      v25 = v45;
      v26 = v46;
      *(_DWORD *)(result + 40) = v21;
      *(_DWORD *)(result + 8) = v25;
      v27 = (void *)(result + (unsigned __int16)v25);
      v28 = HIWORD(v25);
      if ( v26 )
        v29 = v26;
      else
        v29 = "(null)";
      v30 = v28 - 1;
      memcpy(v27, v29, v28 - 1);
      *((_BYTE *)v27 + v30) = 0;
      v31 = v48;
      v32 = *(_DWORD *)(v24 + 40);
      *(_QWORD *)(v24 + 16) = a3;
      *(_QWORD *)(v24 + 32) = v22;
      v33 = v24 + (unsigned __int16)v32;
      *(_BYTE *)(v24 + 24) = v23;
      v34 = HIWORD(v32) - 1LL;
      if ( v31 )
        v35 = v31;
      else
        v35 = "(null)";
      memcpy((void *)(v24 + (unsigned __int16)v32), v35, v34);
      v37 = v41;
      v36 = v42;
      *(_BYTE *)(v33 + v34) = 0;
      v38 = v43;
      v39 = v44;
      *(_BYTE *)(v24 + 44) = a7;
      *(_DWORD *)(v24 + 48) = a8;
      result = perf_trace_run_bpf_submit(v24, v19, v38, a1, 1, v39, v36 + v37, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
