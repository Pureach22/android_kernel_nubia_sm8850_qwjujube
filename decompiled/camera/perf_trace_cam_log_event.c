__int64 __fastcall perf_trace_cam_log_event(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x23
  __int64 result; // x0
  __int64 v11; // x26
  unsigned __int64 StatusReg; // x27
  unsigned int v13; // w22
  __int64 v14; // x30
  _QWORD *v15; // x9
  int v16; // w11
  const char *v17; // x12
  int v18; // w8
  __int64 v19; // x23
  __int64 v20; // x25
  const char *v21; // x1
  size_t v22; // x24
  int v23; // w8
  void *v24; // x23
  const char *v25; // x1
  size_t v26; // x24
  __int64 v27; // x2
  _QWORD *v28; // x5
  __int64 v29; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v30; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD *v31; // [xsp+10h] [xbp-30h] BYREF
  __int64 v32; // [xsp+18h] [xbp-28h] BYREF
  const char *v33; // [xsp+20h] [xbp-20h]
  __int64 v34; // [xsp+28h] [xbp-18h]
  const char *v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]
  __int64 vars0; // [xsp+40h] [xbp+0h] BYREF

  v7 = v5;
  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = nullptr;
  v32 = 0;
  v33 = nullptr;
  v31 = nullptr;
  v30 = 0;
  result = trace_event_get_offsets_cam_log_event(&v32);
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v13 = ((result + 43) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v13, &v31, &v30);
    if ( result )
    {
      v14 = v7;
      v15 = v31;
      v16 = v32;
      v17 = v33;
      v31[31] = &v29;
      v18 = v34;
      v15[29] = &vars0;
      v19 = result + (unsigned __int16)v16;
      v20 = result;
      if ( v17 )
        v21 = v17;
      else
        v21 = "(null)";
      v15[32] = v14;
      v15[33] = 5;
      *(_DWORD *)(result + 8) = v16;
      *(_DWORD *)(result + 12) = v18;
      v22 = HIWORD(v16) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v16), v21, v22);
      *(_BYTE *)(v19 + v22) = 0;
      v23 = *(_DWORD *)(v20 + 12);
      v24 = (void *)(v20 + (unsigned __int16)v23);
      if ( v35 )
        v25 = v35;
      else
        v25 = "(null)";
      v26 = HIWORD(v23) - 1LL;
      memcpy(v24, v25, v26);
      *((_BYTE *)v24 + v26) = 0;
      v27 = v30;
      v28 = v31;
      *(_QWORD *)(v20 + 16) = a4;
      *(_QWORD *)(v20 + 24) = a5;
      result = perf_trace_run_bpf_submit(v20, v13, v27, a1, 1, v28, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
