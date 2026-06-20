_DWORD *__fastcall perf_trace_kgsl_mmu_pagefault(__int64 a1, __int64 a2, __int64 a3, int a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x30
  __int64 v10; // x23
  _DWORD *result; // x0
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  unsigned int v14; // w20
  __int64 v15; // x30
  _QWORD *v16; // x9
  int v17; // w11
  const char *v18; // x12
  int v19; // w8
  char *v20; // x24
  _DWORD *v21; // x23
  const char *v22; // x1
  int v23; // w9
  size_t v24; // x25
  const char *v25; // x10
  int v26; // w8
  char *v27; // x22
  const char *v28; // x1
  size_t v29; // x21
  int v30; // w8
  char *v31; // x21
  const char *v32; // x1
  size_t v33; // x22
  __int64 v34; // [xsp+0h] [xbp-50h] BYREF
  unsigned int v35; // [xsp+Ch] [xbp-44h] BYREF
  _QWORD *v36; // [xsp+10h] [xbp-40h] BYREF
  __int64 v37; // [xsp+18h] [xbp-38h] BYREF
  const char *v38; // [xsp+20h] [xbp-30h]
  __int64 v39; // [xsp+28h] [xbp-28h]
  const char *v40; // [xsp+30h] [xbp-20h]
  __int64 v41; // [xsp+38h] [xbp-18h]
  const char *v42; // [xsp+40h] [xbp-10h]
  __int64 v43; // [xsp+48h] [xbp-8h]
  __int64 vars0; // [xsp+50h] [xbp+0h] BYREF

  v10 = v6;
  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v42 = nullptr;
  v39 = 0;
  v40 = nullptr;
  v37 = 0;
  v38 = nullptr;
  v36 = nullptr;
  v35 = 0;
  result = (_DWORD *)trace_event_get_offsets_kgsl_mmu_pagefault(&v37, a2, a5, a6);
  v12 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    v14 = (((_DWORD)result + 51) & 0xFFFFFFF8) - 4;
    result = (_DWORD *)perf_trace_buf_alloc(v14, &v36, &v35);
    if ( result )
    {
      v15 = v10;
      v16 = v36;
      v17 = v37;
      v18 = v38;
      v36[29] = &vars0;
      v16[31] = &v34;
      v19 = v39;
      v20 = (char *)result + (unsigned __int16)v17;
      v21 = result;
      if ( v18 )
        v22 = v18;
      else
        v22 = "(null)";
      v16[32] = v15;
      v16[33] = 5;
      v23 = v41;
      result[2] = v17;
      result[7] = v19;
      result[8] = v23;
      v24 = HIWORD(v17) - 1LL;
      memcpy((char *)result + (unsigned __int16)v17, v22, v24);
      v20[v24] = 0;
      v25 = v40;
      v26 = v21[7];
      *((_QWORD *)v21 + 2) = a3;
      v21[6] = a4;
      v27 = (char *)v21 + (unsigned __int16)v26;
      if ( v25 )
        v28 = v25;
      else
        v28 = "(null)";
      v29 = HIWORD(v26) - 1LL;
      memcpy(v27, v28, v29);
      v27[v29] = 0;
      v30 = v21[8];
      v31 = (char *)v21 + (unsigned __int16)v30;
      if ( v42 )
        v32 = v42;
      else
        v32 = "(null)";
      v33 = HIWORD(v30) - 1LL;
      memcpy(v31, v32, v33);
      v31[v33] = 0;
      result = (_DWORD *)perf_trace_run_bpf_submit(v21, v14, v35, a1, 1, v36, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
