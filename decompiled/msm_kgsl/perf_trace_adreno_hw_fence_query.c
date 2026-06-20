__int64 __fastcall perf_trace_adreno_hw_fence_query(__int64 a1, __int64 a2, __int64 a3, int a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x30
  __int64 v10; // x24
  __int64 result; // x0
  __int64 v13; // x25
  unsigned __int64 StatusReg; // x26
  unsigned int v15; // w20
  _QWORD *v16; // x9
  int v17; // w11
  const char *v18; // x8
  bool v19; // zf
  int v20; // w10
  __int64 v21; // x22
  const char *v22; // x1
  size_t v23; // x23
  __int64 v24; // x21
  int v25; // w8
  void *v26; // x22
  const char *v27; // x1
  size_t v28; // x23
  __int64 v29; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v30; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD *v31; // [xsp+10h] [xbp-30h] BYREF
  __int64 v32; // [xsp+18h] [xbp-28h] BYREF
  const char *v33; // [xsp+20h] [xbp-20h]
  __int64 v34; // [xsp+28h] [xbp-18h]
  const char *v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]
  __int64 vars0; // [xsp+40h] [xbp+0h] BYREF

  v10 = v6;
  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = nullptr;
  v32 = 0;
  v33 = nullptr;
  v31 = nullptr;
  v30 = 0;
  result = trace_event_get_offsets_adreno_hw_fence_query(&v32, a5, a6);
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v13) )
  {
    v15 = ((result + 51) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v15, &v31, &v30);
    if ( result )
    {
      v16 = v31;
      v17 = v32;
      v31[29] = &vars0;
      v16[31] = &v29;
      v18 = v33;
      v19 = v33 == nullptr;
      v16[32] = v10;
      v16[33] = 5;
      v20 = v34;
      *(_QWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      v21 = result + (unsigned __int16)v17;
      if ( v19 )
        v22 = "(null)";
      else
        v22 = v18;
      *(_DWORD *)(result + 28) = v17;
      *(_DWORD *)(result + 32) = v20;
      v23 = HIWORD(v17) - 1LL;
      *(_DWORD *)(result + 24) = a4;
      v24 = result;
      memcpy((void *)(result + (unsigned __int16)v17), v22, v23);
      *(_BYTE *)(v21 + v23) = 0;
      v25 = *(_DWORD *)(v24 + 32);
      v26 = (void *)(v24 + (unsigned __int16)v25);
      if ( v35 )
        v27 = v35;
      else
        v27 = "(null)";
      v28 = HIWORD(v25) - 1LL;
      memcpy(v26, v27, v28);
      *((_BYTE *)v26 + v28) = 0;
      result = perf_trace_run_bpf_submit(v24, v15, v30, a1, 1, v31, StatusReg + v13, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
