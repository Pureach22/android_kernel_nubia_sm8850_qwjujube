__int64 __fastcall perf_trace_msm_v4l2_vidc_inst(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x21
  __int64 result; // x0
  __int64 v5; // x24
  unsigned __int64 StatusReg; // x25
  unsigned int v7; // w20
  __int64 v8; // x30
  _QWORD *v9; // x9
  int v10; // w11
  const char *v11; // x12
  int v12; // w8
  __int64 v13; // x21
  __int64 v14; // x23
  const char *v15; // x1
  size_t v16; // x22
  int v17; // w8
  void *v18; // x21
  const char *v19; // x1
  size_t v20; // x22
  __int64 v21; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v22; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD *v23; // [xsp+10h] [xbp-30h] BYREF
  __int64 v24; // [xsp+18h] [xbp-28h] BYREF
  const char *v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  const char *v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]
  __int64 vars0; // [xsp+40h] [xbp+0h] BYREF

  v3 = v1;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = nullptr;
  v24 = 0;
  v25 = nullptr;
  v23 = nullptr;
  v22 = 0;
  result = trace_event_get_offsets_msm_v4l2_vidc_inst(&v24);
  v5 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v5) )
  {
    v7 = ((result + 27) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v7, &v23, &v22);
    if ( result )
    {
      v8 = v3;
      v9 = v23;
      v10 = v24;
      v11 = v25;
      v23[31] = &v21;
      v12 = v26;
      v9[29] = &vars0;
      v13 = result + (unsigned __int16)v10;
      v14 = result;
      if ( v11 )
        v15 = v11;
      else
        v15 = "(null)";
      v9[32] = v8;
      v9[33] = 5;
      *(_DWORD *)(result + 8) = v10;
      *(_DWORD *)(result + 12) = v12;
      v16 = HIWORD(v10) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v10), v15, v16);
      *(_BYTE *)(v13 + v16) = 0;
      v17 = *(_DWORD *)(v14 + 12);
      v18 = (void *)(v14 + (unsigned __int16)v17);
      if ( v27 )
        v19 = v27;
      else
        v19 = "(null)";
      v20 = HIWORD(v17) - 1LL;
      memcpy(v18, v19, v20);
      *((_BYTE *)v18 + v20) = 0;
      result = perf_trace_run_bpf_submit(v14, v7, v22, a1, 1, v23, StatusReg + v5, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
