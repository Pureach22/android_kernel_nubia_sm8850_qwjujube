_DWORD *__fastcall perf_trace_msm_vidc_driver(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x21
  _DWORD *result; // x0
  __int64 v5; // x24
  unsigned __int64 StatusReg; // x25
  unsigned int v7; // w20
  __int64 v8; // x30
  _QWORD *v9; // x9
  int v10; // w12
  int v11; // w8
  _DWORD *v12; // x21
  unsigned __int16 v13; // w10
  unsigned int v14; // w11
  const char *v15; // x8
  char *v16; // x22
  __int64 v17; // x23
  const char *v18; // x1
  int v19; // w8
  char *v20; // x22
  const char *v21; // x1
  size_t v22; // x23
  int v23; // w8
  char *v24; // x22
  const char *v25; // x1
  size_t v26; // x23
  int v27; // w8
  char *v28; // x22
  const char *v29; // x1
  size_t v30; // x23
  __int64 v31; // [xsp+0h] [xbp-60h] BYREF
  unsigned int v32; // [xsp+Ch] [xbp-54h] BYREF
  _QWORD *v33; // [xsp+10h] [xbp-50h] BYREF
  __int64 v34; // [xsp+18h] [xbp-48h] BYREF
  const char *v35; // [xsp+20h] [xbp-40h]
  __int64 v36; // [xsp+28h] [xbp-38h]
  const char *v37; // [xsp+30h] [xbp-30h]
  __int64 v38; // [xsp+38h] [xbp-28h]
  const char *v39; // [xsp+40h] [xbp-20h]
  __int64 v40; // [xsp+48h] [xbp-18h]
  const char *v41; // [xsp+50h] [xbp-10h]
  __int64 v42; // [xsp+58h] [xbp-8h]
  __int64 vars0; // [xsp+60h] [xbp+0h] BYREF

  v3 = v1;
  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  v41 = nullptr;
  v38 = 0;
  v39 = nullptr;
  v36 = 0;
  v37 = nullptr;
  v34 = 0;
  v35 = nullptr;
  v33 = nullptr;
  v32 = 0;
  result = (_DWORD *)trace_event_get_offsets_msm_vidc_driver(&v34);
  v5 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v5) )
  {
    v7 = (((_DWORD)result + 35) & 0xFFFFFFF8) - 4;
    result = (_DWORD *)perf_trace_buf_alloc(v7, &v33, &v32);
    if ( result )
    {
      v8 = v3;
      v9 = v33;
      v10 = v40;
      v33[31] = &v31;
      v11 = v36;
      v9[29] = &vars0;
      v12 = result;
      v9[32] = v8;
      v9[33] = 5;
      v13 = v34;
      LODWORD(v9) = v38;
      v14 = WORD1(v34);
      result[2] = v34;
      result[3] = v11;
      v15 = v35;
      v16 = (char *)result + v13;
      result[4] = (_DWORD)v9;
      result[5] = v10;
      v17 = v14 - 1LL;
      if ( v15 )
        v18 = v15;
      else
        v18 = "(null)";
      memcpy(v16, v18, v14 - 1LL);
      v16[v17] = 0;
      v19 = v12[3];
      v20 = (char *)v12 + (unsigned __int16)v19;
      if ( v37 )
        v21 = v37;
      else
        v21 = "(null)";
      v22 = HIWORD(v19) - 1LL;
      memcpy(v20, v21, v22);
      v20[v22] = 0;
      v23 = v12[4];
      v24 = (char *)v12 + (unsigned __int16)v23;
      if ( v39 )
        v25 = v39;
      else
        v25 = "(null)";
      v26 = HIWORD(v23) - 1LL;
      memcpy(v24, v25, v26);
      v24[v26] = 0;
      v27 = v12[5];
      v28 = (char *)v12 + (unsigned __int16)v27;
      if ( v41 )
        v29 = v41;
      else
        v29 = "(null)";
      v30 = HIWORD(v27) - 1LL;
      memcpy(v28, v29, v30);
      v28[v30] = 0;
      result = (_DWORD *)perf_trace_run_bpf_submit(v12, v7, v32, a1, 1, v33, StatusReg + v5, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
