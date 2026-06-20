__int64 __fastcall perf_trace_print_icmp(
        __int64 a1,
        __int64 a2,
        __int16 a3,
        char a4,
        __int16 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x30
  __int64 v11; // x25
  __int64 result; // x0
  __int64 v15; // x26
  unsigned __int64 StatusReg; // x27
  unsigned int v17; // w20
  _QWORD *v18; // x9
  const char *v19; // x11
  int v20; // w8
  int v21; // w10
  void *v22; // x22
  __int64 v23; // x8
  __int64 v24; // x21
  const char *v25; // x1
  __int64 v26; // x23
  int v27; // w8
  void *v28; // x21
  const char *v29; // x1
  size_t v30; // x22
  __int64 v31; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v32; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD *v33; // [xsp+10h] [xbp-30h] BYREF
  __int64 v34; // [xsp+18h] [xbp-28h] BYREF
  const char *v35; // [xsp+20h] [xbp-20h]
  __int64 v36; // [xsp+28h] [xbp-18h]
  const char *v37; // [xsp+30h] [xbp-10h]
  __int64 v38; // [xsp+38h] [xbp-8h]
  __int64 v39; // [xsp+40h] [xbp+0h] BYREF

  v11 = v7;
  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = nullptr;
  v34 = 0;
  v35 = nullptr;
  v33 = nullptr;
  v32 = 0;
  result = trace_event_get_offsets_print_icmp(&v34, a6, a7);
  v15 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v15) )
  {
    v17 = ((result + 51) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v17, &v33, &v32);
    if ( result )
    {
      v18 = v33;
      v19 = v35;
      v33[31] = &v31;
      v20 = v34;
      v18[29] = &v39;
      v18[32] = v11;
      v18[33] = 5;
      LODWORD(v18) = v36;
      *(_QWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 28) = v20;
      *(_DWORD *)(result + 32) = (_DWORD)v18;
      v21 = *(_DWORD *)(a2 + 112);
      *(_BYTE *)(result + 22) = a4;
      v22 = (void *)(result + (unsigned __int16)v20);
      v23 = HIWORD(v20);
      *(_WORD *)(result + 24) = a5;
      v24 = v23 - 1;
      *(_WORD *)(result + 20) = a3;
      *(_DWORD *)(result + 16) = v21;
      if ( v19 )
        v25 = v19;
      else
        v25 = "(null)";
      v26 = result;
      memcpy(v22, v25, v23 - 1);
      *((_BYTE *)v22 + v24) = 0;
      v27 = *(_DWORD *)(v26 + 32);
      v28 = (void *)(v26 + (unsigned __int16)v27);
      if ( v37 )
        v29 = v37;
      else
        v29 = "(null)";
      v30 = HIWORD(v27) - 1LL;
      memcpy(v28, v29, v30);
      *((_BYTE *)v28 + v30) = 0;
      result = perf_trace_run_bpf_submit(v26, v17, v32, a1, 1, v33, StatusReg + v15, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
