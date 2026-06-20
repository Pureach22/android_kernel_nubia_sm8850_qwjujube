__int64 __fastcall perf_trace_print_skb_gso(
        __int64 a1,
        __int64 a2,
        __int16 a3,
        __int16 a4,
        __int16 a5,
        __int16 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 v12; // x26
  __int64 result; // x0
  __int64 v17; // x27
  unsigned __int64 StatusReg; // x28
  unsigned int v19; // w20
  _QWORD *v20; // x9
  const char *v21; // x11
  int v22; // w8
  int v23; // w9
  void *v24; // x22
  __int64 v25; // x8
  __int64 v26; // x21
  const char *v27; // x1
  __int64 v28; // x23
  int v29; // w8
  void *v30; // x21
  const char *v31; // x1
  size_t v32; // x22
  __int64 v33; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v34; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD *v35; // [xsp+10h] [xbp-30h] BYREF
  __int64 v36; // [xsp+18h] [xbp-28h] BYREF
  const char *v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  const char *v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]
  __int64 vars0; // [xsp+40h] [xbp+0h] BYREF

  v12 = v8;
  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = nullptr;
  v36 = 0;
  v37 = nullptr;
  v35 = nullptr;
  v34 = 0;
  result = trace_event_get_offsets_print_skb_gso(&v36, a7, a8);
  v17 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v17) )
  {
    v19 = ((result + 51) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v19, &v35, &v34);
    if ( result )
    {
      v20 = v35;
      v21 = v37;
      v35[31] = &v33;
      v22 = v36;
      v20[29] = &vars0;
      v20[32] = v12;
      v20[33] = 5;
      LODWORD(v20) = v38;
      *(_QWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 32) = v22;
      *(_DWORD *)(result + 36) = (_DWORD)v20;
      *(_DWORD *)(result + 16) = *(_DWORD *)(a2 + 112);
      v23 = *(_DWORD *)(a2 + 116);
      *(_WORD *)(result + 28) = a5;
      v24 = (void *)(result + (unsigned __int16)v22);
      v25 = HIWORD(v22);
      *(_WORD *)(result + 24) = a3;
      *(_WORD *)(result + 30) = a6;
      v26 = v25 - 1;
      *(_WORD *)(result + 26) = a4;
      if ( v21 )
        v27 = v21;
      else
        v27 = "(null)";
      v28 = result;
      *(_DWORD *)(result + 20) = v23;
      memcpy(v24, v27, v25 - 1);
      *((_BYTE *)v24 + v26) = 0;
      v29 = *(_DWORD *)(v28 + 36);
      v30 = (void *)(v28 + (unsigned __int16)v29);
      if ( v39 )
        v31 = v39;
      else
        v31 = "(null)";
      v32 = HIWORD(v29) - 1LL;
      memcpy(v30, v31, v32);
      *((_BYTE *)v30 + v32) = 0;
      result = perf_trace_run_bpf_submit(v28, v19, v34, a1, 1, v35, StatusReg + v17, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
