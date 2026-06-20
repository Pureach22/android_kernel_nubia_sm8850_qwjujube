__int64 __fastcall perf_trace_cam_perf(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v9; // x25
  unsigned __int64 StatusReg; // x26
  unsigned int v11; // w21
  __int64 v12; // x30
  _QWORD *v13; // x9
  int v14; // w11
  const char *v15; // x12
  int v16; // w8
  __int64 v17; // x22
  __int64 v18; // x24
  const char *v19; // x1
  size_t v20; // x23
  int v21; // w8
  void *v22; // x22
  const char *v23; // x1
  size_t v24; // x23
  __int64 v25; // x2
  _QWORD *v26; // x5
  __int64 v27; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v28; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD *v29; // [xsp+10h] [xbp-30h] BYREF
  __int64 v30; // [xsp+18h] [xbp-28h] BYREF
  const char *v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  const char *v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]
  __int64 v35; // [xsp+40h] [xbp+0h] BYREF

  v6 = v4;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = nullptr;
  v30 = 0;
  v31 = nullptr;
  v29 = nullptr;
  v28 = 0;
  result = trace_event_get_offsets_cam_perf(&v30);
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v11 = ((result + 35) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v11, &v29, &v28);
    if ( result )
    {
      v12 = v6;
      v13 = v29;
      v14 = v30;
      v15 = v31;
      v29[31] = &v27;
      v16 = v32;
      v13[29] = &v35;
      v17 = result + (unsigned __int16)v14;
      v18 = result;
      if ( v15 )
        v19 = v15;
      else
        v19 = "(null)";
      v13[32] = v12;
      v13[33] = 5;
      *(_DWORD *)(result + 8) = v14;
      *(_DWORD *)(result + 12) = v16;
      v20 = HIWORD(v14) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v14), v19, v20);
      *(_BYTE *)(v17 + v20) = 0;
      v21 = *(_DWORD *)(v18 + 12);
      v22 = (void *)(v18 + (unsigned __int16)v21);
      if ( v33 )
        v23 = v33;
      else
        v23 = "(null)";
      v24 = HIWORD(v21) - 1LL;
      memcpy(v22, v23, v24);
      *((_BYTE *)v22 + v24) = 0;
      v25 = v28;
      v26 = v29;
      *(_QWORD *)(v18 + 16) = a4;
      result = perf_trace_run_bpf_submit(v18, v11, v25, a1, 1, v26, StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
