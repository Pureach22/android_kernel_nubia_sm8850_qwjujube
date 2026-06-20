_DWORD *__fastcall perf_trace_rproc_qcom_event(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x21
  _DWORD *result; // x0
  __int64 v5; // x24
  unsigned __int64 StatusReg; // x25
  unsigned int v7; // w20
  __int64 v8; // x30
  _QWORD *v9; // x9
  int v10; // w11
  int v11; // w8
  const char *v12; // x12
  char *v13; // x22
  _DWORD *v14; // x21
  const char *v15; // x1
  int v16; // w9
  size_t v17; // x23
  int v18; // w8
  char *v19; // x22
  const char *v20; // x1
  size_t v21; // x23
  int v22; // w8
  char *v23; // x22
  const char *v24; // x1
  size_t v25; // x23
  __int64 v26; // [xsp+0h] [xbp-50h] BYREF
  unsigned int v27; // [xsp+Ch] [xbp-44h] BYREF
  _QWORD *v28; // [xsp+10h] [xbp-40h] BYREF
  __int64 v29; // [xsp+18h] [xbp-38h] BYREF
  const char *v30; // [xsp+20h] [xbp-30h]
  __int64 v31; // [xsp+28h] [xbp-28h]
  const char *v32; // [xsp+30h] [xbp-20h]
  __int64 v33; // [xsp+38h] [xbp-18h]
  const char *v34; // [xsp+40h] [xbp-10h]
  __int64 v35; // [xsp+48h] [xbp-8h]
  __int64 vars0; // [xsp+50h] [xbp+0h] BYREF

  v3 = v1;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = nullptr;
  v31 = 0;
  v32 = nullptr;
  v29 = 0;
  v30 = nullptr;
  v28 = nullptr;
  v27 = 0;
  result = (_DWORD *)trace_event_get_offsets_rproc_qcom_event(&v29);
  v5 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v5) )
  {
    v7 = (((_DWORD)result + 31) & 0xFFFFFFF8) - 4;
    result = (_DWORD *)perf_trace_buf_alloc(v7, &v28, &v27);
    if ( result )
    {
      v8 = v3;
      v9 = v28;
      v10 = v29;
      v28[31] = &v26;
      v11 = v31;
      v12 = v30;
      v9[29] = &vars0;
      v13 = (char *)result + (unsigned __int16)v10;
      v14 = result;
      if ( v12 )
        v15 = v12;
      else
        v15 = "(null)";
      v9[32] = v8;
      v9[33] = 5;
      v16 = v33;
      result[2] = v10;
      result[3] = v11;
      result[4] = v16;
      v17 = HIWORD(v10) - 1LL;
      memcpy((char *)result + (unsigned __int16)v10, v15, v17);
      v13[v17] = 0;
      v18 = v14[3];
      v19 = (char *)v14 + (unsigned __int16)v18;
      if ( v32 )
        v20 = v32;
      else
        v20 = "(null)";
      v21 = HIWORD(v18) - 1LL;
      memcpy(v19, v20, v21);
      v19[v21] = 0;
      v22 = v14[4];
      v23 = (char *)v14 + (unsigned __int16)v22;
      if ( v34 )
        v24 = v34;
      else
        v24 = "(null)";
      v25 = HIWORD(v22) - 1LL;
      memcpy(v23, v24, v25);
      v23[v25] = 0;
      result = (_DWORD *)perf_trace_run_bpf_submit(v14, v7, v27, a1, 1, v28, StatusReg + v5, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
